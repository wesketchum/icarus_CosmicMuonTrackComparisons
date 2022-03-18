#include "TFile.h"
#include "TH1D.h"
#include "ROOT/RDataFrame.hxx"

void make_histosRDFrames(TString input_file_names,
                         const char* selection,
                         TString output_file_name="my_output_file.root",
                         unsigned int n_entries=0,
                         bool verbose=false) {

   //Get the files from ICARUS gpvm
  TFileCollection *my_files = new TFileCollection("my_files","My File List");
  my_files->Add(input_file_names);

  std::cout<< "Number of files in our file list is " << my_files->GetNFiles() <<std::endl;

  TChain chain_files("caloskimE/TrackCaloSkim");
  chain_files.AddFileInfoList(my_files->GetList());

  std::cout<<"files added to chain"<<std::endl;

  //declare our dataframe object
  ROOT::RDataFrame df_all(chain_files);

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
  auto hist_start_x = df_sel.Histo1D("start.x");
  auto hist_start_y = df_sel.Histo1D("start.y");
  auto hist_start_z = df_sel.Histo1D("start.z");
  auto hist_end_x = df_sel.Histo1D("end.x");
  auto hist_end_y = df_sel.Histo1D("end.y");
  auto hist_end_z = df_sel.Histo1D("end.z");

  auto hist_length = df_sel.Histo1D("length");
  auto hist_t0 = df_sel.Histo1D("t0");
  auto hist_angle_azimuth = df_sel.Histo1D("angle_azimuth");
  auto hist_angle_zenith = df_sel.Histo1D("angle_zenith");

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

    //df_plane = df_plane.Define("hits_dqdx_mean","ROOT::VecOps::Mean("+str_hits+".dqdx)");
    //df_plane = df_plane.Define("hits_integral_mean","ROOT::VecOps::Mean("+str_hits+".h.integral)");
    //df_plane = df_plane.Define("hits_width_mean","ROOT::VecOps::Mean("+str_hits+".h.width)");

    auto hist_hits_dqdx_mean = df_plane.Histo1D("hits_dqdx_mean");
    auto hist_hits_integral_mean = df_plane.Histo1D("hits_integral_mean");
    auto hist_hits_width_mean = df_plane.Histo1D("hits_width_mean");

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
