#include "TFile.h"
#include "TH1D.h"
#include "sbnobj/Common/Calibration/TrackCaloSkimmerObj.h"
#include "ROOT/RDataFrame.hxx"

#pragma link C++ class sbn::Vector3D+;
#pragma link C++ class sbn::HitInfo+;
#pragma link C++ class vector<sbn::HitInfo>+;

typedef std::map<std::string,ROOT::RDF::TH1DModel> TH1D_registry_t;


template <typename RDF>
auto create_Histo1D(RDF df,std::string var,TH1D_registry_t hreg)
{
  auto hmod = hreg.find(var);
  if(hmod==hreg.end())
    return df.Histo1D(var);

  return df.Histo1D(hmod->second,var);
}

TH1D_registry_t register_histograms()
{
  TH1D_registry_t hist_registry;

  hist_registry["start.x"] = ROOT::RDF::TH1DModel("","Relative Frequency vs  Start (X); Start X (cm)", 100, -400., 400.);
  hist_registry["start.y"] = ROOT::RDF::TH1DModel("","Relative Frequency vs  Start (Y); Start Y (cm)", 100, -150., 150.);
  hist_registry["start.z"] = ROOT::RDF::TH1DModel("","Relative Frequency vs  Start (Z); Start Z (cm)", 100, -1000., 1000.);

  hist_registry["end.x"] = ROOT::RDF::TH1DModel("","Relative Frequency vs  End (X);End X (cm)", 100, -400., 400.);
  hist_registry["end.y"] = ROOT::RDF::TH1DModel("","Relative Frequency vs  End (Y);End Y (cm)", 100, -150., 150.);
  hist_registry["end.z"] = ROOT::RDF::TH1DModel("","Relative Frequency vs  End (Z);End Z (cm);", 100, -1000., 1000.);

  hist_registry["length"] = ROOT::RDF::TH1DModel("","Relative Frequency vs  Length;Muon Length (cm);",100,0,1500);
  hist_registry["t0"] = ROOT::RDF::TH1DModel("","Relative Frequency vs  T_0;T_0 (#mus);",100,-1.5e6,1.5e6);
  hist_registry["angle_azimuth"] = ROOT::RDF::TH1DModel("","Relative Frequency vs Azimuthal Angle;azimuth (rad);Tracks",100,-0.5*TMath::Pi(),0.5*TMath::Pi());
  hist_registry["angle_zenith"] = ROOT::RDF::TH1DModel("","Relative Frequency vs Zenith Angle;zenith (rad);Tracks",100,-0.5*TMath::Pi(),0.5*TMath::Pi());

  hist_registry["hits_dqdx_mean"] = ROOT::RDF::TH1DModel("","Relative Frequency vs dQ/dx",100,0,1500);
  hist_registry["hits_integral_mean"] = ROOT::RDF::TH1DModel("","Relative Frequency vs Charge Integral",100,0,150.);
  hist_registry["hits_width_mean"] = ROOT::RDF::TH1DModel("","Relative Frequency vs Width",100,0,20);

  return hist_registry;
}

void make_histosRDFrames(TString input_file_names,
                         const char* selection,
                         TString output_file_name="my_output_file.root",
                         unsigned int n_entries=0,
                         bool verbose=false) {

  //make histogram registry
  auto hist_registry = register_histograms();

   //Get the files from ICARUS gpvm
  TFileCollection *my_files = new TFileCollection("my_files","My File List");
  my_files->Add(input_file_names);

  std::cout<< "Number of files in our file list is " << my_files->GetNFiles() <<std::endl;

  TChain chain_files("caloskimE/TrackCaloSkim");
  chain_files.AddFileInfoList(my_files->GetList());



  std::cout<<"files added to chain"<<std::endl;

  //declare our dataframe object
  ROOT::RDataFrame df_all(chain_files,
    {"trk.start","trk.end","trk.dir","trk.length","trk.t0",
    "trk.hits0.dir","trk.hits1.dir","trk.hits2.dir",
    "trk.hits0.dqdx","trk.hits1.dqdx","trk.hits2.dqdx",
    "trk.hits0.h.integral","trk.hits1.h.integral","trk.hits2.h.integral",
    "trk.hits0.h.width","trk.hits1.h.width","trk.hits2.h.width"});

  //limit Range
  auto df = df_all.Range(n_entries);

  //apply selection
  auto df_sel = df.Filter(selection);

  //define angles...
  df_sel = df_sel.Define("angle_azimuth","atan(dir.x/dir.z)");
  df_sel = df_sel.Define("angle_zenith","atan(sqrt(dir.x*dir.x+dir.y*dir.y)/dir.z)");

  std::cout<<"base selection path defined."<<std::endl;

  //create output file
  TFile output_file(output_file_name,"RECREATE");

  std::cout<<"Created " << output_file_name << std::endl;


  //make histograms and save them
  auto hist_start_x = create_Histo1D(df_sel,"start.x",hist_registry);//df_sel.Histo1D("start.x");
  auto hist_start_y = create_Histo1D(df_sel,"start.y",hist_registry);//df_sel.Histo1D("start.y");
  auto hist_start_z = create_Histo1D(df_sel,"start.z",hist_registry);//df_sel.Histo1D("start.z");
  auto hist_end_x = create_Histo1D(df_sel,"end.x",hist_registry);//df_sel.Histo1D("end.x");
  auto hist_end_y = create_Histo1D(df_sel,"end.y",hist_registry);//df_sel.Histo1D("end.y");
  auto hist_end_z = create_Histo1D(df_sel,"end.z",hist_registry);//df_sel.Histo1D("end.z");

  auto hist_length = create_Histo1D(df_sel,"length",hist_registry);//df_sel.Histo1D("length");
  auto hist_t0 = create_Histo1D(df_sel,"t0",hist_registry);//df_sel.Histo1D("t0");
  auto hist_angle_azimuth = create_Histo1D(df_sel,"angle_azimuth",hist_registry);//df_sel.Histo1D("angle_azimuth");
  auto hist_angle_zenith = create_Histo1D(df_sel,"angle_zenith",hist_registry);//df_sel.Histo1D("angle_zenith");

  hist_start_x->Write("hist_start_x");
  hist_start_y->Write("hist_start_y");
  hist_start_z->Write("hist_start_z");
  hist_end_x->Write("hist_end_x");
  hist_end_y->Write("hist_end_y");
  hist_end_z->Write("hist_end_z");

  hist_length->Write("hist_length");
  hist_t0->Write("hist_t0");
  hist_angle_zenith->Write("hist_angle_zenith");
  hist_angle_azimuth->Write("hist_angle_azimuth");

  std::cout<<"Wrote track histograms." << std::endl;

  //get things by plane
  char str_hits_size[100],str_hits_dqdx[100],str_hits_integral[100],str_hits_width[100];
  char hname[100];
  for(int p=0; p<3; ++p){
    std::cout<<"Processing plane " << p << std::endl;

    sprintf(str_hits_size,"hits%d.dir.x.size()",p);
    sprintf(str_hits_dqdx,"ROOT::VecOps::Mean(hits%d.dqdx)",p);
    sprintf(str_hits_integral,"ROOT::VecOps::Mean(hits%d.h.integral)",p);
    sprintf(str_hits_width,"ROOT::VecOps::Mean(hits%d.h.width)",p);

    auto df_plane = df_sel.Define("hits_n",str_hits_size)
                          .Filter("hits_n>0")
                          .Define("hits_dqdx_mean",str_hits_dqdx)
                          .Define("hits_integral_mean",str_hits_integral)
                          .Define("hits_width_mean",str_hits_width);

    auto hist_hits_dqdx_mean = create_Histo1D(df_plane,"hits_dqdx_mean",hist_registry);//df_plane.Histo1D("hits_dqdx_mean");
    auto hist_hits_integral_mean = create_Histo1D(df_plane,"hits_integral_mean",hist_registry);//df_plane.Histo1D("hits_integral_mean");
    auto hist_hits_width_mean = create_Histo1D(df_plane,"hits_width_mean",hist_registry);//df_plane.Histo1D("hits_width_mean");

    sprintf(hname,"hist_hits%d_dqdx_mean",p);
    hist_hits_dqdx_mean->Write(hname);
    sprintf(hname,"hist_hits%d_integral_mean",p);
    hist_hits_integral_mean->Write(hname);
    sprintf(hname,"hist_hits%d_width_mean",p);
    hist_hits_width_mean->Write(hname);

    std::cout<<"Write plane " << p << " histograms." << std::endl;

  }

  output_file.Close();
}
