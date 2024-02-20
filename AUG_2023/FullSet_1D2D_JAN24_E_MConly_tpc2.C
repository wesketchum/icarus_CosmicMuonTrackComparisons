#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "sbnobj/Common/Calibration/TrackCaloSkimmerObj.h"



void FullSet_1D2D_JAN24_E_MConly_tpc2(bool verbose=false) {


  gStyle->SetOptStat(0);
  ofstream outfile("t.txt");
  ofstream outfile_col_mc_xyz("mcOCT2023_NUMI_tpc2_sel12_East_file_xyz_col.txt");
  ofstream outfile_in2_mc_xyz("mcOCT2023_NUMI_tpc2_sel12_East_file_xyz_in2.txt");
  ofstream outfile_in1_mc_xyz("mcOCT2023_NUMI_tpc2_sel12_East_file_xyz_in1.txt");

  ofstream outfile_dqdxc("mcOCT2023_OUTFILE_my_testTESToutputNUMI_tpc2_sel12_East_file_Qdx_col.txt");
  ofstream outfile_dqdx1("mcOCT2023_OUTFILE_my_testTESToutputNUMI_tpc2_sel12_East_file_Qdx_in1.txt");
  ofstream outfile_dqdx2("mcOCT2023_OUTFILE_my_testTESToutputNUMI_tpc2_sel12_East_file_Qdx_in2.txt");

  ofstream outfile_intc("mcOCT2023_OUTFILE_my_testTESToutputNUMI_tpc2_sel12_East_file_HC_col.txt");
  ofstream outfile_int1("mcOCT2023_OUTFILE_my_testTESToutputNUMI_tpc2_sel12_East_file_HC_in1.txt");
  ofstream outfile_int2("mcOCT2023_OUTFILE_my_testTESToutputNUMI_tpc2_sel12_East_file_HC_in2.txt");


  ofstream outfile1("mchnoCOSangle_by_OCT2023__col_East_file_tpc2.txt");
  ofstream outfile2("mchnoCOSangle_by_OCT2023__in1_East_file_tpc2.txt");
  ofstream outfile3("mchnoCOSangle_by_OCT2023__in2_East_file_tpc2.txt");

  ofstream outfile1_c_PLUS("mchnoCOSangle_by_OCT2023__col_East_file_tpc2_PLUS.txt");
  ofstream outfile2_1_PLUS("mchnoCOSangle_by_OCT2023__in1_East_file_tpc2_PLUS.txt");
  ofstream outfile3_2_PLUS("mchnoCOSangle_by_OCT2023__in2_East_file_tpc2_PLUS.txt");

  ofstream outfile1_c_MINUS("mchnoCOSangle_by_OCT2023__col_East_file_tpc2_MINUS.txt");
  ofstream outfile2_1_MINUS("mchnoCOSangle_by_OCT2023__in1_East_file_tpc2_MINUS.txt");
  ofstream outfile3_2_MINUS("mchnoCOSangle_by_OCT2023__in2_East_file_tpc2_MINUS.txt");

  
  ofstream outT("OCT2023.txt");
  double z_p = 1.0;

  double Plus_x = 1.0/sqrt(3);
  double Plus_z = 1.0;
  double Minus_x = -1.0/sqrt(3);
  double Minus_z = 1.0;
  double Pi = 3.1415926535897932384;
  int n = 8000;

  double X_SEL12_East_MC_col[n];
  double X_SEL12_East_MC_in1[n];
  double X_SEL12_East_MC_in2[n];

  double Y_SEL12_East_MC_col[n];
  double Y_SEL12_East_MC_in1[n];
  double Y_SEL12_East_MC_in2[n];

  double Z_SEL12_East_MC_col[n];
  double Z_SEL12_East_MC_in1[n];
  double Z_SEL12_East_MC_in2[n];



  double ref_angle_col[n];// = 0.0                                                                                                         
  double ref_angle_in1[n];//                                                                                          
  double ref_angle_in2[n];// = 0.0                                                                     

  double ref_angle_col_p[n]; 
  double ref_angle_in1_p[n];
  double ref_angle_in2_p[n];
  double ref_angle_col_m[n];
  double ref_angle_in1_m[n];
  double ref_angle_in2_m[n];
  double nc=0.0;
  double ni1=0.0;
  double ni2=0.0;

  double angle_by_in1_p[n];
  double angle_by_in1_m[n];
  double angle_by_in2_p[n];
  double angle_by_in2_m[n];
  double angle_by_col_p[n];
  double angle_by_col_m[n];
  double angle_by_col_E[n];
  double angle_by_in2_E[n];
  double angle_by_col_W[n];
  double angle_by_in2_W[n];
  double angle_by_in1_E[n];
  double angle_by_in1_W[n];

  double angle_by_col_Eo[n];
  double angle_by_in2_Eo[n];
  double angle_by_col_Wo[n];
  double angle_by_in2_Wo[n];
  double angle_by_in1_Eo[n];
  double angle_by_in1_Wo[n];
  TH1F *h1p = new TH1F("h1p","TPC2 East Cryostat MC (COL) ", 100., 0.0, 2.0); //0., 7.0);                             
  h1p->GetXaxis()->SetTitle("angle in radians");


  TH1F *h2p = new TH1F("h2p","TPC2 East Cryostat MC (IN1) ", 100., 0.0, 2.0); //0., 7.0);                                                                                                                                                  
  h2p->GetXaxis()->SetTitle("angle in radians");

  TH1F *h3p = new TH1F("h3p","TPC2 East Cryostat MC (IN2) ", 100., 0.0, 2.0); //0., 7.0);                                                                                                                                                
  h3p->GetXaxis()->SetTitle("angle in radians");


  TH1F *h1pDQ = new TH1F("h1pDQ","TPC2 East Cryostat MC (COL) ", 100., 100.0, 1000.0); //0., 7.0);                    
  h1pDQ->GetXaxis()->SetTitle("dQ/dX");


  TH1F *h2pDQ = new TH1F("h2pDQ","TPC2 East Cryostat MC (IN1) ", 100., 100.0, 1000.0); //0., 7.0);                                                                                                                                      
  h2pDQ->GetXaxis()->SetTitle("dQ/dX");

  TH1F *h3pDQ = new TH1F("h3pDQ","TPC2 East Cryostat MC (IN2) ", 100., 100.0, 1000.0); //0., 7.0);                    
  h3pDQ->GetXaxis()->SetTitle("dQ/dX");

  TH1F *h1pI = new TH1F("h1pI","TPC2 East Cryostat MC (COL) ", 100., 100.0, 1000.0); //0., 7.0);                   \
                                                                                                                      
  h1pI->GetXaxis()->SetTitle("integral");


  TH1F *h2pI = new TH1F("h2pI","TPC2 East Cryostat MC (IN1) ", 100., 100.0, 1000.0); //0., 7.0);                   \
                                                                                                                      
  h2pI->GetXaxis()->SetTitle("integral");

  TH1F *h3pI = new TH1F("h3pI","TPC2 East Cryostat MC (IN2) ", 100., 100.0, 1000.0); //0., 7.0);                   \
                                                                                                                      
  h3pI->GetXaxis()->SetTitle("integral");







  TH1F *h1P = new TH1F("h1P","TPC2 East Cryostat MC COL (P) ", 100., 0.0, 2.0);
  h1P->GetXaxis()->SetTitle("angle (radians)");
  TH1F *h1m = new TH1F("h1m","TPC2 East Cryostat MC COL (M) ", 100., 0.0, 2.0);
  h1m->GetXaxis()->SetTitle("angle (radians)");

  TH1F *h2P = new TH1F("h2P","TPC2 East Cryostat MC IN2 (P) ", 100., 0.0, 2.0);
  h1P->GetXaxis()->SetTitle("angle (radians)");
  TH1F *h2m = new TH1F("h2m","TPC2 East Cryostat MC IN2 (M) ", 100., 0.0, 2.0);
  h1m->GetXaxis()->SetTitle("angle (radians)");

  TH1F *h3P = new TH1F("h3P","TPC2 East Cryostat MC IN1 (P) ", 100., 0.0, 2.0);
  h3P->GetXaxis()->SetTitle("angle (radians)");
  TH1F *h3m = new TH1F("h3m","TPC2 East Cryostat MC IN1 (M) ", 100., 0.0, 2.0);
  h3m->GetXaxis()->SetTitle("angle (radians)");



  TH2F *hz_hor_dQdx_East_tpc2_COL=new TH2F("hz_hor_dQdx_East_tpc2_COL","Horizontal Angle vs  dQdx COL", 50., 0., 2.0, 50., 0., 1000.);
  hz_hor_dQdx_East_tpc2_COL->GetYaxis()->SetTitle("dQdx ");
  hz_hor_dQdx_East_tpc2_COL->GetXaxis()->SetTitle("Horizontal angle in radians");
  TH2F *hz_hor_dQdx_East_tpc2_IN2=new TH2F("hz_hor_dQdx_East_tpc2_IN2","Horizontal Angle vs  dQdx IN2", 50., 0., 2.0, 50., 0., 1000.);
  hz_hor_dQdx_East_tpc2_IN2->GetYaxis()->SetTitle("dQdx ");
  hz_hor_dQdx_East_tpc2_IN2->GetXaxis()->SetTitle("Horizontal angle in radians");
  TH2F *hz_hor_dQdx_East_tpc2_IN1=new TH2F("hz_hor_dQdx_East_tpc2_IN1","Horizontal Angle vs  dQdx IN1", 50., 0., 2.0, 50., 0., 1000.);
  hz_hor_dQdx_East_tpc2_IN1->GetYaxis()->SetTitle("dQdx ");
  hz_hor_dQdx_East_tpc2_IN1->GetXaxis()->SetTitle("Horizontal angle in radians");

  TH2F *hz_hor_INT_East_tpc2_COL=new TH2F("hz_hor_INT_East_tpc2_COL","Horizontal Angle vs  INT COL", 50., 0., 2.0, 50., 0., 1000.);
  hz_hor_INT_East_tpc2_COL->GetYaxis()->SetTitle("INT ");
  hz_hor_INT_East_tpc2_COL->GetXaxis()->SetTitle("Horizontal angle in radians");
  TH2F *hz_hor_INT_East_tpc2_IN2=new TH2F("hz_hor_INT_East_tpc2_IN2","Horizontal Angle vs  INT IN2", 50., 0., 2.0, 50., 0., 1000.);
  hz_hor_INT_East_tpc2_IN2->GetYaxis()->SetTitle("INT ");
  hz_hor_INT_East_tpc2_IN2->GetXaxis()->SetTitle("Horizontal angle in radians");
  TH2F *hz_hor_INT_East_tpc2_IN1=new TH2F("hz_hor_INT_East_tpc2_IN1","Horizontal Angle vs  INT IN1", 50., 0., 2.0, 50., 0., 1000.);
  hz_hor_INT_East_tpc2_IN1->GetYaxis()->SetTitle("INT ");
  hz_hor_INT_East_tpc2_IN1->GetXaxis()->SetTitle("Horizontal angle in radians");


  TH2F *hz_plus_dQdx_East_tpc2_COL=new TH2F("hz_plus_dQdx_East_tpc2_COL","Horizontal plus Angle vs dQdx COL", 50., 0., 2.0, 50., 0., 1000.);
  hz_plus_dQdx_East_tpc2_COL->GetYaxis()->SetTitle("dQdx ");
  hz_plus_dQdx_East_tpc2_COL->GetXaxis()->SetTitle("Horizontal plus angle in radians");
  TH2F *hz_plus_dQdx_East_tpc2_IN2=new TH2F("hz_plus_dQdx_East_tpc2_IN2","Horizontal plus Angle vs dQdx IN2", 50., 0., 2.0, 50., 0., 1000.);
  hz_plus_dQdx_East_tpc2_IN2->GetYaxis()->SetTitle("dQdx ");
  hz_plus_dQdx_East_tpc2_IN2->GetXaxis()->SetTitle("Horizontal plus angle in radians");
  TH2F *hz_plus_dQdx_East_tpc2_IN1=new TH2F("hz_plus_dQdx_East_tpc2_IN1","Horizontal plus Angle vs dQdx IN1", 50., 0., 2.0, 50., 0., 1000.);
  hz_plus_dQdx_East_tpc2_IN1->GetYaxis()->SetTitle("dQdx ");
  hz_plus_dQdx_East_tpc2_IN1->GetXaxis()->SetTitle("Horizontal plus angle in radians");

  TH2F *hz_plus_INT_East_tpc2_COL=new TH2F("hz_plus_INT_East_tpc2_COL","Horizontal plus Angle vs  INT COL", 50., 0., 2.0, 50., 0., 1000.);
  hz_plus_INT_East_tpc2_COL->GetYaxis()->SetTitle("INT ");
  hz_plus_INT_East_tpc2_COL->GetXaxis()->SetTitle("Horizontal plus angle in radians");
  TH2F *hz_plus_INT_East_tpc2_IN2=new TH2F("hz_plus_INT_East_tpc2_IN2","Horizontal plus Angle vs  INT IN2", 50., 0., 2.0, 50., 0., 1000.);
  hz_plus_INT_East_tpc2_IN2->GetYaxis()->SetTitle("INT ");
  hz_plus_INT_East_tpc2_IN2->GetXaxis()->SetTitle("Horizontal plus angle in radians");
  TH2F *hz_plus_INT_East_tpc2_IN1=new TH2F("hz_plus_INT_East_tpc2_IN1","Horizontal plus Angle vs  INT IN1", 50., 0., 2.0, 50., 0., 1000.);
  hz_plus_INT_East_tpc2_IN1->GetYaxis()->SetTitle("INT ");
  hz_plus_INT_East_tpc2_IN1->GetXaxis()->SetTitle("Horizontal plus angle in radians");


  TH2F *hz_minus_dQdx_East_tpc2_COL=new TH2F("hz_minus_dQdx_East_tpc2_COL","Horizontal minus Angle vs dQdx COL", 50., 0., 2.0, 50., 0., 1000.);
  hz_minus_dQdx_East_tpc2_COL->GetYaxis()->SetTitle("dQdx ");
  hz_minus_dQdx_East_tpc2_COL->GetXaxis()->SetTitle("Horizontal minus angle in radians");
  TH2F *hz_minus_dQdx_East_tpc2_IN2=new TH2F("hz_minus_dQdx_East_tpc2_IN2","Horizontal minus Angle vs dQdx IN2", 50., 0., 2.0, 50., 0., 1000.);
  hz_minus_dQdx_East_tpc2_IN2->GetYaxis()->SetTitle("dQdx ");
  hz_minus_dQdx_East_tpc2_IN2->GetXaxis()->SetTitle("Horizontal minus angle in radians");
  TH2F *hz_minus_dQdx_East_tpc2_IN1=new TH2F("hz_minus_dQdx_East_tpc2_IN1","Horizontal minus Angle vs dQdx IN1", 50., 0., 2.0, 50., 0., 1000.);
  hz_minus_dQdx_East_tpc2_IN1->GetYaxis()->SetTitle("dQdx ");
  hz_minus_dQdx_East_tpc2_IN1->GetXaxis()->SetTitle("Horizontal minus angle in radians");

  TH2F *hz_minus_INT_East_tpc2_COL=new TH2F("hz_minus_INT_East_tpc2_COL","Horizontal minus Angle vs  INT COL", 50., 0., 2.0, 50., 0., 1000.);
  hz_minus_INT_East_tpc2_COL->GetYaxis()->SetTitle("INT ");
  hz_minus_INT_East_tpc2_COL->GetXaxis()->SetTitle("Horizontal minus angle in radians");
  TH2F *hz_minus_INT_East_tpc2_IN2=new TH2F("hz_minus_INT_East_tpc2_IN2","Horizontal minus Angle vs  INT IN2", 50., 0., 2.0, 50., 0., 1000.);
  hz_minus_INT_East_tpc2_IN2->GetYaxis()->SetTitle("INT ");
  hz_minus_INT_East_tpc2_IN2->GetXaxis()->SetTitle("Horizontal minus angle in radians");
  TH2F *hz_minus_INT_East_tpc2_IN1=new TH2F("hz_minus_INT_East_tpc2_IN1","Horizontal minus Angle vs  INT IN1", 50., 0., 2.0, 50., 0., 1000.);
  hz_minus_INT_East_tpc2_IN1->GetYaxis()->SetTitle("INT ");
  hz_minus_INT_East_tpc2_IN1->GetXaxis()->SetTitle("Horizontal minus angle in radians");





   //Get the files from ICARUS gpvm
  TFileCollection *my_files = new TFileCollection("my_files","My File List");

  my_files->AddFromFile("list_MC24.txt");//MC24.txt");///pnfs/sbn/data/sbn_fd/poms_production/2023A/ICARUS_BNB_intime_cosmics/mc/reconstructed/icaruscode_v09_72_00_03p01/calibtuples/00/**/**.root");///pnfs/sbn/data/sbn_fd/poms_production/data/Run2/reconstructed/icaruscode_v09_72_00_03p01/bnbmajority/calibtuples/00/00/**/**/");//mc_april22versiontest2.txt");//mc_aprilversion.txt");
 outfile<< "Number of files in our MC list is " << my_files->GetNFiles() <<endl;
  TChain myfile("caloskimE/TrackCaloSkim");
  myfile.AddFileInfoList(my_files->GetList());


  cout<<"files read"<<endl;

  //delcare variables
  TTreeReader myReader(&myfile);
  
  TTreeReaderValue<int> selected(myReader, "trk.selected");
  TTreeReaderValue<float> startX(myReader, "trk.start.x");
  
  TTreeReaderValue<float> startY(myReader, "trk.start.y");

  TTreeReaderValue<float> startZ(myReader, "trk.start.z");

  TTreeReaderValue<float> endX(myReader, "trk.end.x");
  TTreeReaderValue<float> endY(myReader, "trk.end.y");
  TTreeReaderValue<float> endZ(myReader, "trk.end.z");
  TTreeReaderValue<int> run(myReader, "trk.meta.run");
  TTreeReaderValue<int> event(myReader, "trk.meta.evt");  
  TTreeReaderArray<float> dqdx_i1(myReader, "trk.hits0.dqdx");
  TTreeReaderArray<float> dqdx_c(myReader, "trk.hits2.dqdx");                                                        
  TTreeReaderArray<float> dqdx_i2(myReader, "trk.hits1.dqdx");
  TTreeReaderArray<float> rr_c(myReader, "trk.hits2.rr");
  TTreeReaderArray<float> rr_i2(myReader, "trk.hits1.rr");
  TTreeReaderArray<float> rr_i1(myReader, "trk.hits0.rr");
  TTreeReaderArray<float> z_i1(myReader, "trk.hits0.dir.z");
  TTreeReaderArray<float> y_i1(myReader, "trk.hits0.dir.y");
  TTreeReaderArray<float> x_i1(myReader, "trk.hits0.dir.x");
  TTreeReaderArray<float> z_i2(myReader, "trk.hits1.dir.z");
  TTreeReaderArray<float> y_i2(myReader, "trk.hits1.dir.y");
  TTreeReaderArray<float> x_i2(myReader, "trk.hits1.dir.x");
  TTreeReaderArray<float> z_c(myReader, "trk.hits2.dir.z");
  TTreeReaderArray<float> y_c(myReader, "trk.hits2.dir.y");
  TTreeReaderArray<float> x_c(myReader, "trk.hits2.dir.x");
  TTreeReaderArray<bool> ontraj_c(myReader, "trk.hits2.ontraj");
  TTreeReaderArray<bool> ontraj_i2(myReader, "trk.hits1.ontraj");
  TTreeReaderArray<bool> ontraj_i1(myReader, "trk.hits0.ontraj");
  TTreeReaderValue<float> length(myReader, "trk.length");
  TTreeReaderValue<float> t0(myReader, "trk.t0");
  TTreeReaderArray<float> integral_c(myReader, "trk.hits2.h.integral");
  TTreeReaderArray<float> integral_i2(myReader, "trk.hits1.h.integral");
  TTreeReaderArray<float> integral_i1(myReader, "trk.hits0.h.integral");
  TTreeReaderArray<float> width_c(myReader, "trk.hits2.h.width");
  TTreeReaderArray<float> width_i2(myReader, "trk.hits1.h.width");
  TTreeReaderArray<float> width_i1(myReader, "trk.hits0.h.width");
  TTreeReaderArray<uint16_t> tpc_c(myReader, "trk.hits2.h.tpc");
  TTreeReaderArray<uint16_t> tpc_i2(myReader, "trk.hits1.h.tpc");
  TTreeReaderArray<uint16_t> tpc_i1(myReader, "trk.hits0.h.tpc");
  TTreeReaderArray<uint16_t> wire_c(myReader, "trk.hits2.h.wire");
  TTreeReaderArray<uint16_t> wire_i2(myReader, "trk.hits1.h.wire");
  TTreeReaderArray<uint16_t> wire_i1(myReader, "trk.hits0.h.wire");
  TTreeReaderArray<float> time_c(myReader, "trk.hits2.h.time");
  TTreeReaderArray<float> time_i2(myReader, "trk.hits1.h.time");
  TTreeReaderArray<float> time_i1(myReader, "trk.hits0.h.time");
  TTreeReaderArray<float> pitch_c(myReader, "trk.hits2.pitch");
  TTreeReaderArray<float> pitch_i2(myReader, "trk.hits1.pitch");
  TTreeReaderArray<float> pitch_i1(myReader, "trk.hits0.pitch");
  
   double num = 0.0;
   double num2 = 0.0;
   int a = 0;
   int b = 0;
   int j = 0;
   int k = 0;
   double angle[52000];
   double angle2[52000];
   double zangle[52000];
   double zangle2[52000];
   cout<<"vars declared"<<endl;
   double tpc_num = 2;


   //MC Azimuthal Angle
   while (myReader.Next()) {
     a++;
     cout<<"track "<<a<<endl;
     //     outfile<<"track "<<a<<endl;
     if(*selected == 0) continue; //if not stopping, move one.
     //if(*tpc3 != 0) continue;
     //only here if stopping 
 
     //can add other track-level variables here

     if(y_c.GetSize() == 0) continue;
     if(y_i2.GetSize() == 0) continue;
     if(y_i1.GetSize() == 0) continue;

     int last_h_mc_c = y_c.GetSize()-1;
     int last_h_mc_i2 = y_i2.GetSize()-1;
     int last_h_mc_i1 = y_i1.GetSize()-1;


     
     cout<<"MC"<<endl;
     cout<<" x c "<<x_c.GetSize()-1<<" x i2 " <<x_i2.GetSize()-1<<" x i1 "<<x_i1.GetSize()-1<<endl;
     cout<<" y c "<<y_c.GetSize()-1<<" y i2 " <<y_i2.GetSize()-1<<" y i1 "<<y_i1.GetSize()-1<<endl;
     cout<<" z c "<<z_c.GetSize()-1<<" z i2 " <<z_i2.GetSize()-1<<" z i1 "<<z_i1.GetSize()-1<<endl;
     cout<<" tpc c "<<tpc_c[last_h_mc_c]<<endl;
     cout<<" tpc i2 "<<tpc_i2[last_h_mc_i2]<<endl;
     cout<<" tpc i1 "<<tpc_i1[last_h_mc_i1]<<endl;


     //if not on thr trajectory, continue
     if(ontraj_c[last_h_mc_c]!=1) continue;
     if(ontraj_i2[last_h_mc_i2]!=1) continue;
     if(ontraj_i1[last_h_mc_i1]!=1) continue;

     if(tpc_c[last_h_mc_c]!=tpc_num) continue;

     outfile_col_mc_xyz<<x_c[last_h_mc_c]<<" "<<y_c[last_h_mc_c]<<" "<<z_c[last_h_mc_c]<<endl;
    

     X_SEL12_East_MC_col[last_h_mc_c] = x_c[last_h_mc_c];
     Y_SEL12_East_MC_col[last_h_mc_c] = y_c[last_h_mc_c];
     Z_SEL12_East_MC_col[last_h_mc_c] = z_c[last_h_mc_c];

     
     double sum_integral_mc_c = 0.0;
     double sum_dqdx_mc_c =0.0;
     for(int i = 0; i < last_h_mc_c; i++){
       sum_integral_mc_c += integral_c[i];
       sum_dqdx_mc_c += dqdx_c[i];
     }

     double av_integral_mc_c = sum_integral_mc_c/last_h_mc_c;
     double av_dqdx_mc_c = sum_dqdx_mc_c/last_h_mc_c;
     double AVG_int_col[last_h_mc_c];
     double AVG_dqdx_col[last_h_mc_c];
     outfile_dqdxc<<av_dqdx_mc_c<<endl;
     outfile_intc<<av_integral_mc_c<<endl;

     h1pDQ->Fill(av_dqdx_mc_c);
     h1pI->Fill(av_integral_mc_c);

     AVG_int_col[last_h_mc_c] = av_dqdx_mc_c;
     //outfile_dqdxc<<AVG_int_col[last_h_mc_c]<<endl;

     int alpha = last_h_mc_c;
     //     for(int alpha = 0; alpha<nc; alpha++){
                                                                                       
       ref_angle_col[alpha] = 0.0;
       ref_angle_col_p[alpha] = 0.0;
       ref_angle_col_m[alpha] = 0.0;
       angle_by_col_E[alpha] = TMath::ACos( (  (Z_SEL12_East_MC_col[alpha]*z_p) ) / ( sqrt(X_SEL12_East_MC_col[alpha]*X_SEL12_East_MC_col[alpha]+ Y_SEL12_East_MC_col[alpha]*Y_SEL12_East_MC_col[alpha]+Z_SEL12_East_MC_col[alpha]*Z_SEL12_East_MC_col[alpha]) * sqrt( (z_p*z_p) ) ) );


       angle_by_col_p[alpha] = TMath::ACos( (  (X_SEL12_East_MC_col[alpha]*Plus_x)+(Z_SEL12_East_MC_col[alpha]*Plus_z) ) / ( sqrt(X_SEL12_East_MC_col[alpha]*X_SEL12_East_MC_col[alpha]+ Y_SEL12_East_MC_col[alpha]*Y_SEL12_East_MC_col[alpha]+Z_SEL12_East_MC_col[alpha]*Z_SEL12_East_MC_col[alpha]) * sqrt( (Plus_x*Plus_x + Plus_z*Plus_z) ) ) );
       angle_by_col_m[alpha] = TMath::ACos( (  (X_SEL12_East_MC_col[alpha]*Minus_x)+(Z_SEL12_East_MC_col[alpha]*Minus_z) ) / ( sqrt(X_SEL12_East_MC_col[alpha]*X_SEL12_East_MC_col[alpha]+ Y_SEL12_East_MC_col[alpha]*Y_SEL12_East_MC_col[alpha]+Z_SEL12_East_MC_col[alpha]*Z_SEL12_East_MC_col[alpha]) * sqrt( (Minus_x*Minus_x + Minus_z*Minus_z) ) ) );


       //ref_angle_col[alpha] = 0.0;
       cout<<angle_by_col_E[alpha]<<endl;
       cout<<((Pi)/2.0)<<endl;


       if( (angle_by_col_E[alpha] > ((Pi)/2.0)) && (angle_by_col_E[alpha] < (Pi) ) ){
	 ref_angle_col[alpha] = (Pi) - angle_by_col_E[alpha];
	 outfile1<<ref_angle_col[alpha]<<endl;                                     
	 h1p->Fill((Pi) - angle_by_col_E[alpha]);
       }
       else if( (angle_by_col_E[alpha] > (Pi)) && (angle_by_col_E[alpha] < ((3.0*Pi)/2.0)) ){
	 ref_angle_col[alpha]= angle_by_col_E[alpha] - (Pi);
	 outfile1<<ref_angle_col[alpha]<<endl;
	 h1p->Fill(angle_by_col_E[alpha] - (Pi));
       }
       else if( angle_by_col_E[alpha] < ((Pi)/2.0) ){
	 ref_angle_col[alpha]= angle_by_col_E[alpha];
	 outfile1<<ref_angle_col[alpha]<<endl;
	 h1p->Fill(angle_by_col_E[alpha]);
       }



       if( (angle_by_col_p[alpha] > ((Pi)/2.0)) && (angle_by_col_p[alpha] < (Pi) ) ){
         ref_angle_col_p[alpha] = (Pi) - angle_by_col_p[alpha];
         outfile1_c_PLUS<<ref_angle_col_p[alpha]<<endl;
         h1P->Fill((Pi) - angle_by_col_p[alpha]);
       }
       else if( (angle_by_col_p[alpha] > (Pi)) && (angle_by_col_p[alpha] < ((3.0*Pi)/2.0)) ){
         ref_angle_col_p[alpha]= angle_by_col_p[alpha] - (Pi);
         outfile1_c_PLUS<<ref_angle_col_p[alpha]<<endl;
         h1P->Fill(angle_by_col_p[alpha] - (Pi));
       }
       else if( angle_by_col_p[alpha] < ((Pi)/2.0) ){
         ref_angle_col_p[alpha]= angle_by_col_p[alpha];
         outfile1_c_PLUS<<ref_angle_col_p[alpha]<<endl;
         h1P->Fill(angle_by_col_p[alpha]);
       }



       if( (angle_by_col_m[alpha] > ((Pi)/2.0)) && (angle_by_col_m[alpha] < (Pi) ) ){
         ref_angle_col_m[alpha] = (Pi) - angle_by_col_m[alpha];
         outfile1_c_MINUS<<ref_angle_col_m[alpha]<<endl;
         h1m->Fill((Pi) - angle_by_col_m[alpha]);
       }
       else if( (angle_by_col_m[alpha] > (Pi)) && (angle_by_col_m[alpha] < ((3.0*Pi)/2.0)) ){
         ref_angle_col_m[alpha]= angle_by_col_m[alpha] - (Pi);
         outfile1_c_MINUS<<ref_angle_col_m[alpha]<<endl;
         h1m->Fill(angle_by_col_m[alpha] - (Pi));
       }
       else if( angle_by_col_m[alpha] < ((Pi)/2.0) ){
         ref_angle_col_m[alpha]= angle_by_col_m[alpha];
         outfile1_c_MINUS<<ref_angle_col_m[alpha]<<endl;
         h1m->Fill(angle_by_col_m[alpha]);
       }


       hz_hor_dQdx_East_tpc2_COL->Fill(ref_angle_col[alpha],av_dqdx_mc_c);
       hz_hor_INT_East_tpc2_COL->Fill(ref_angle_col[alpha],av_integral_mc_c);


       hz_plus_dQdx_East_tpc2_COL->Fill(ref_angle_col_p[alpha],av_dqdx_mc_c);
       hz_plus_INT_East_tpc2_COL->Fill(ref_angle_col_p[alpha],av_integral_mc_c);

       hz_minus_dQdx_East_tpc2_COL->Fill(ref_angle_col_m[alpha],av_dqdx_mc_c);
       hz_minus_INT_East_tpc2_COL->Fill(ref_angle_col_m[alpha],av_integral_mc_c);



     cout<<"collection done"<<endl;

     if(tpc_i2[last_h_mc_i2]!=tpc_num)continue;//==0) continue;


     outfile_in2_mc_xyz<<x_i2[last_h_mc_i2]<<" "<<y_i2[last_h_mc_i2]<<" "<<z_i2[last_h_mc_i2]<<endl;


     X_SEL12_East_MC_in2[last_h_mc_i2] = x_i2[last_h_mc_i2];
     Y_SEL12_East_MC_in2[last_h_mc_i2] = y_i2[last_h_mc_i2];
     Z_SEL12_East_MC_in2[last_h_mc_i2] = z_i2[last_h_mc_i2];



     double sum_integral_mc_i2 =0.0;
     double sum_dqdx_mc_i2 =0.0;
     double AVG_int_in2[last_h_mc_i2];
     double AVG_dqdx_in2[last_h_mc_i2];
     for(int j = 0; j <last_h_mc_i2; j++){
       sum_integral_mc_i2 += integral_i2[j];
       sum_dqdx_mc_i2 += dqdx_i2[j];
     }
     double av_integral_mc_i2 = sum_integral_mc_i2/last_h_mc_i2;
     double av_dqdx_mc_i2 = sum_dqdx_mc_i2/last_h_mc_i2;


     outfile_dqdx2<<av_dqdx_mc_i2<<endl;
     outfile_int2<<av_integral_mc_i2<<endl;


     h3pDQ->Fill(av_dqdx_mc_i2);
     h3pI->Fill(av_integral_mc_i2);

     int gamma = last_h_mc_i2;

     //   for(int gamma = 0; gamma<ni2; gamma++){

       ref_angle_in2[gamma] = 0.0;
       ref_angle_in2_p[gamma] = 0.0;
       ref_angle_in2_m[gamma] = 0.0;
       angle_by_in2_E[gamma] = TMath::ACos( ( (Z_SEL12_East_MC_in2[gamma]*z_p) ) / ( sqrt(X_SEL12_East_MC_in2[gamma]*X_SEL12_East_MC_in2[gamma]+Y_SEL12_East_MC_in2[gamma]*Y_SEL12_East_MC_in2[gamma]+Z_SEL12_East_MC_in2[gamma]*Z_SEL12_East_MC_in2[gamma]) * sqrt( (z_p*z_p) ) ) );

       angle_by_in2_p[gamma] = TMath::ACos( ( (X_SEL12_East_MC_in2[gamma]*Plus_x)+(Z_SEL12_East_MC_in2[gamma]*Plus_z) ) / ( sqrt(X_SEL12_East_MC_in2[gamma]*X_SEL12_East_MC_in2[gamma]+Y_SEL12_East_MC_in2[gamma]*Y_SEL12_East_MC_in2[gamma]+Z_SEL12_East_MC_in2[gamma]*Z_SEL12_East_MC_in2[gamma]) * sqrt( (Plus_x*Plus_x + Plus_z*Plus_z) ) ) );

       angle_by_in2_m[gamma] = TMath::ACos( ( (X_SEL12_East_MC_in2[gamma]*Minus_x)+(Z_SEL12_East_MC_in2[gamma]*Minus_z) ) / ( sqrt(X_SEL12_East_MC_in2[gamma]*X_SEL12_East_MC_in2[gamma]+Y_SEL12_East_MC_in2[gamma]*Y_SEL12_East_MC_in2[gamma]+Z_SEL12_East_MC_in2[gamma]*Z_SEL12_East_MC_in2[gamma]) * sqrt( (Minus_x*Minus_x + Minus_z*Minus_z) ) ) );

       if( (angle_by_in2_E[gamma] > (Pi)) && (angle_by_in2_E[gamma] < ((3.0*Pi)/2.0))){
	 ref_angle_in2[gamma] = angle_by_in2_E[gamma]-(Pi);
	 outfile3<<ref_angle_in2[gamma]<<endl;
	 h3p->Fill( angle_by_in2_E[gamma]-(Pi));
       }

       else if( (angle_by_in2_E[gamma] > ((Pi)/2.0)) && (angle_by_in2_E[gamma] < (Pi))){
	 ref_angle_in2[gamma] = (Pi) - angle_by_in2_E[gamma];
	 outfile3<<ref_angle_in2[gamma]<<endl;
	 h3p->Fill((Pi) - angle_by_in2_E[gamma]);
       }
       else if(angle_by_in2_E[gamma] < ((Pi)/2.0) ){
	 ref_angle_in2[gamma] = angle_by_in2_E[gamma];
	 outfile3<<ref_angle_in2[gamma]<<endl;
	 h3p->Fill(angle_by_in2_E[gamma]);                                                                             \
       }
     


       if( (angle_by_in2_p[gamma] > (Pi)) && (angle_by_in2_p[gamma] < ((3.0*Pi)/2.0))){
         ref_angle_in2_p[gamma] = angle_by_in2_p[gamma]-(Pi);
         outfile3_2_PLUS<<ref_angle_in2_p[gamma]<<endl;
         h2P->Fill( angle_by_in2_p[gamma]-(Pi));
       }

       else if( (angle_by_in2_p[gamma] > ((Pi)/2.0)) && (angle_by_in2_p[gamma] < (Pi))){
         ref_angle_in2_p[gamma] = (Pi) - angle_by_in2_p[gamma];
         outfile3_2_PLUS<<ref_angle_in2_p[gamma]<<endl;
         h2P->Fill((Pi) - angle_by_in2_p[gamma]);
       }
       else if(angle_by_in2_p[gamma] < ((Pi)/2.0) ){
         ref_angle_in2_p[gamma] = angle_by_in2_p[gamma];
         outfile3_2_PLUS<<ref_angle_in2_p[gamma]<<endl;
         h2P->Fill(angle_by_in2_p[gamma]);                                                                             \
       }


       if( (angle_by_in2_m[gamma] > (Pi)) && (angle_by_in2_m[gamma] < ((3.0*Pi)/2.0))){
         ref_angle_in2_m[gamma] = angle_by_in2_m[gamma]-(Pi);
         outfile3_2_MINUS<<ref_angle_in2_m[gamma]<<endl;
         h2m->Fill( angle_by_in2_m[gamma]-(Pi));
       }

       else if( (angle_by_in2_m[gamma] > ((Pi)/2.0)) && (angle_by_in2_m[gamma] < (Pi))){
         ref_angle_in2_m[gamma] = (Pi) - angle_by_in2_m[gamma];
         outfile3_2_MINUS<<ref_angle_in2_m[gamma]<<endl;
         h2m->Fill((Pi) - angle_by_in2_m[gamma]);
       }
       else if(angle_by_in2_m[gamma] < ((Pi)/2.0) ){
         ref_angle_in2_m[gamma] = angle_by_in2_m[gamma];
         outfile3_2_MINUS<<ref_angle_in2_m[gamma]<<endl;
         h2m->Fill(angle_by_in2_m[gamma]);                                                                             \
       }


         hz_hor_dQdx_East_tpc2_IN2->Fill(ref_angle_in2[gamma],av_dqdx_mc_i2);
         hz_hor_INT_East_tpc2_IN2->Fill(ref_angle_in2[gamma],av_integral_mc_i2);

	 hz_plus_dQdx_East_tpc2_IN2->Fill(ref_angle_in2_p[gamma],av_dqdx_mc_i2);
         hz_plus_INT_East_tpc2_IN2->Fill(ref_angle_in2_p[gamma],av_integral_mc_i2);

	 hz_minus_dQdx_East_tpc2_IN2->Fill(ref_angle_in2_m[gamma],av_dqdx_mc_i2);
         hz_minus_INT_East_tpc2_IN2->Fill(ref_angle_in2_m[gamma],av_integral_mc_i2);



     cout<<"induction 2 done"<<endl;

     if(tpc_i1[last_h_mc_i1]!=tpc_num)continue;//==0) continue;

     outfile_in1_mc_xyz<<x_i1[last_h_mc_i1]<<" "<<y_i1[last_h_mc_i1]<<" "<<z_i1[last_h_mc_i1]<<endl;     //60 degrees plus:                         

     X_SEL12_East_MC_in1[last_h_mc_i1] = x_i1[last_h_mc_i1];
     Y_SEL12_East_MC_in1[last_h_mc_i1] = y_i1[last_h_mc_i1];
     Z_SEL12_East_MC_in1[last_h_mc_i1] = z_i1[last_h_mc_i1];


     double sum_integral_mc_i1 =0.0;
     double sum_dqdx_mc_i1 =0.0;
     double AVG_int_in1[last_h_mc_i1];
     double AVG_dqdx_in1[last_h_mc_i1];
     for(int k = 0; k <last_h_mc_i1; k++){
       sum_integral_mc_i1 += integral_i1[k];
       sum_dqdx_mc_i1 += dqdx_i1[k];
     }
     double av_integral_mc_i1 = sum_integral_mc_i1/last_h_mc_i1;
     double av_dqdx_mc_i1 = sum_dqdx_mc_i1/last_h_mc_i1;

                            
     outfile_dqdx1<<av_dqdx_mc_i1<<endl;
     outfile_int1<<av_integral_mc_i1<<endl;
                             
     h2pDQ->Fill(av_dqdx_mc_i1);
     h2pI->Fill(av_integral_mc_i1);
     int beta = last_h_mc_i1;

     ref_angle_in1[beta] = 0.0;
     ref_angle_in1_p[beta] = 0.0;
     ref_angle_in1_m[beta] = 0.0;
     angle_by_in1_E[beta] = TMath::ACos( (  (Z_SEL12_East_MC_in1[beta]*z_p) ) / ( sqrt(X_SEL12_East_MC_in1[beta]*X_SEL12_East_MC_in1[beta]+Y_SEL12_East_MC_in1[beta]*Y_SEL12_East_MC_in1[beta]+Z_SEL12_East_MC_in1[beta]*Z_SEL12_East_MC_in1[beta]) * sqrt( (z_p*z_p) ) ) );

     //Plus
     angle_by_in1_p[beta] = TMath::ACos( (  (X_SEL12_East_MC_in1[beta]*Plus_x)+ (Z_SEL12_East_MC_in1[beta]*Plus_z) ) / ( sqrt(X_SEL12_East_MC_in1[beta]*X_SEL12_East_MC_in1[beta]+Y_SEL12_East_MC_in1[beta]*Y_SEL12_East_MC_in1[beta]+Z_SEL12_East_MC_in1[beta]*Z_SEL12_East_MC_in1[beta]) * sqrt( (Plus_x*Plus_x)*(Plus_z*Plus_z) ) ) );
     //Minus
     angle_by_in1_m[beta] = TMath::ACos( (  (X_SEL12_East_MC_in1[beta]*Minus_x)+(Z_SEL12_East_MC_in1[beta]*Minus_z) ) / ( sqrt(X_SEL12_East_MC_in1[beta]*X_SEL12_East_MC_in1[beta]+Y_SEL12_East_MC_in1[beta]*Y_SEL12_East_MC_in1[beta]+Z_SEL12_East_MC_in1[beta]*Z_SEL12_East_MC_in1[beta]) * sqrt( (Minus_x*Minus_x)*(Minus_z*Minus_z) ) ) );

    
     if(  (angle_by_in1_E[beta] > ((Pi)/2.0) ) && (angle_by_in1_E[beta] < (Pi) )){

       ref_angle_in1[beta] = (Pi) - angle_by_in1_E[beta];
       outfile2<<ref_angle_in1[beta]<<endl;
       h2p->Fill((Pi) - angle_by_in1_E[beta]);
     }

     else if(  (angle_by_in1_E[beta] > (Pi) ) && (angle_by_in1_E[beta] < ((3.0*Pi)/2.0) )){
       ref_angle_in1[beta] = angle_by_in1_E[beta] -(Pi);
       outfile2<<ref_angle_in1[beta]<<endl;
       h2p->Fill(angle_by_in1_E[beta] -(Pi));
     }

     else if(angle_by_in1_E[beta] < ((Pi)/2.0) ){
       ref_angle_in1[beta] = angle_by_in1_E[beta];
       outfile2<<ref_angle_in1[beta]<<endl;
       h2p->Fill(angle_by_in1_E[beta]);
     }


     if(  (angle_by_in1_p[beta] > ((Pi)/2.0) ) && (angle_by_in1_p[beta] < (Pi) )){

       ref_angle_in1_p[beta] = (Pi) - angle_by_in1_p[beta];
       outfile2_1_PLUS<<ref_angle_in1_p[beta]<<endl;
       h3P->Fill((Pi) - angle_by_in1_p[beta]);
     }

     else if(  (angle_by_in1_p[beta] > (Pi) ) && (angle_by_in1_p[beta] < ((3.0*Pi)/2.0) )){
       ref_angle_in1_p[beta] = angle_by_in1_p[beta] -(Pi);
       outfile2_1_PLUS<<ref_angle_in1_p[beta]<<endl;
       h3P->Fill(angle_by_in1_p[beta] -(Pi));
     }

     else if(angle_by_in1_p[beta] < ((Pi)/2.0) ){
       ref_angle_in1_p[beta] = angle_by_in1_p[beta];
       outfile2_1_PLUS<<ref_angle_in1_p[beta]<<endl;
       h3P->Fill(angle_by_in1_p[beta]);
     }

     if(  (angle_by_in1_m[beta] > ((Pi)/2.0) ) && (angle_by_in1_m[beta] < (Pi) )){

       ref_angle_in1_m[beta] = (Pi) - angle_by_in1_m[beta];
       outfile2_1_MINUS<<ref_angle_in1_m[beta]<<endl;
       h3m->Fill((Pi) - angle_by_in1_m[beta]);
     }

     else if(  (angle_by_in1_m[beta] > (Pi) ) && (angle_by_in1_m[beta] < ((3.0*Pi)/2.0) )){
       ref_angle_in1_m[beta] = angle_by_in1_m[beta] -(Pi);
       outfile2_1_MINUS<<ref_angle_in1_m[beta]<<endl;
       h3m->Fill(angle_by_in1_m[beta] -(Pi));
     }

     else if(angle_by_in1_m[beta] < ((Pi)/2.0) ){
       ref_angle_in1_m[beta] = angle_by_in1_m[beta];
       outfile2_1_PLUS<<ref_angle_in1_m[beta]<<endl;
       h3m->Fill(angle_by_in1_m[beta]);
     }



     hz_hor_dQdx_East_tpc2_IN1->Fill(ref_angle_in1[beta],av_dqdx_mc_i1);
     hz_hor_INT_East_tpc2_IN1->Fill(ref_angle_in1[beta],av_integral_mc_i1);

        
     hz_plus_dQdx_East_tpc2_IN1->Fill(ref_angle_in1_p[beta],av_dqdx_mc_i1);
     hz_plus_INT_East_tpc2_IN1->Fill(ref_angle_in1_p[beta],av_integral_mc_i1);


     hz_minus_dQdx_East_tpc2_IN1->Fill(ref_angle_in1_m[beta],av_dqdx_mc_i1);
     hz_minus_INT_East_tpc2_IN1->Fill(ref_angle_in1_m[beta],av_integral_mc_i1);



     cout<<"induction 1 done"<<endl;     


     nc=last_h_mc_c;
     ni1=last_h_mc_i1;
     ni2=last_h_mc_i2;

   }//end while myReader
   cout<<"MC done"<<endl;
   
   TCanvas* cnvs1p= new TCanvas("cnvs1p", "TPC2 East Cryostat MC COL",1,1,600,500);
   h1p->Draw("HIST");
   TCanvas* cnvs2p= new TCanvas("cnvs2p", "TPC2 East Cryostat MC IN1",1,1,600,500);
   h2p->Draw("HIST");
   TCanvas* cnvs3p= new TCanvas("cnvs3p", "TPC2 East Cryostat MC IN2",1,1,600,500);
   h3p->Draw("HIST");

   cnvs1p->SaveAs("JAN24/MC_tpc2_sel12_East_file_xyz_col_angle_NEW_h_JAN2024.pdf");
   cnvs2p->SaveAs("JAN24/MC_tpc2_sel12_East_file_xyz_in1_angle_NEW_h_JAN2024.pdf");
   cnvs3p->SaveAs("JAN24/MC_tpc2_sel12_East_file_xyz_in2_angle_NEW_h_JAN2024.pdf");

   TCanvas* cnvs1pDQ= new TCanvas("cnvs1pDQ", "TPC2 East Cryostat MC COL",1,1,600,500);
   h1pDQ->Draw("HIST");
   TCanvas* cnvs2pDQ= new TCanvas("cnvs2pDQ", "TPC2 East Cryostat MC IN1",1,1,600,500);
   h2pDQ->Draw("HIST");
   TCanvas* cnvs3pDQ= new TCanvas("cnvs3pDQ", "TPC2 East Cryostat MC IN2",1,1,600,500);
   h3pDQ->Draw("HIST");

   cnvs1pDQ->SaveAs("JAN24/MC_tpc2_sel12_East_file_xyz_col_DQDX_NEW_h_JAN2024.pdf");
   cnvs2pDQ->SaveAs("JAN24/MC_tpc2_sel12_East_file_xyz_in1_DQDX_NEW_h_JAN2024.pdf");
   cnvs3pDQ->SaveAs("JAN24/MC_tpc2_sel12_East_file_xyz_in2_DQDX_NEW_h_JAN2024.pdf");


   TCanvas* cnvs1pI= new TCanvas("cnvs1pI", "TPC2 East Cryostat MC COL",1,1,600,500);
   h1pI->Draw("HIST");
   TCanvas* cnvs2pI= new TCanvas("cnvs2pI", "TPC2 East Cryostat MC IN1",1,1,600,500);
   h2pI->Draw("HIST");
   TCanvas* cnvs3pI= new TCanvas("cnvs3pI", "TPC2 East Cryostat MC IN2",1,1,600,500);
   h3pI->Draw("HIST");

   cnvs1pI->SaveAs("JAN24/MC_tpc2_sel12_East_file_xyz_col_INT_NEW_h_JAN2024.pdf");
   cnvs2pI->SaveAs("JAN24/MC_tpc2_sel12_East_file_xyz_in1_INT_NEW_h_JAN2024.pdf");
   cnvs3pI->SaveAs("JAN24/MC_tpc2_sel12_East_file_xyz_in2_INT_NEW_h_JAN2024.pdf");



   TCanvas* cnvs1P= new TCanvas("cnvs1P", "TPC2 East Cryostat MC COL Plus",1,1,600,500);
   h1P->Draw("HIST");
   TCanvas* cnvs1m= new TCanvas("cnvs1m", "TPC2 East Cryostat MC COL Minus",1,1,600,500);
   h1m->Draw("HIST");
   cnvs1P->SaveAs("JAN24/COL_MC_tpc2_sel12_East_file_angle_PLUS_JAN2024.pdf");
   cnvs1m->SaveAs("JAN24/COL_MC_tpc2_sel12_East_file_angle_MINUS_JAN2024.pdf");

   TCanvas* cnvs2P= new TCanvas("cnvs2P", "TPC2 East Cryostat MC IN2 Plus",1,1,600,500);
   h2P->Draw("HIST");
   TCanvas* cnvs2m= new TCanvas("cnvs2m", "TPC2 East Cryostat MC IN2 Minus",1,1,600,500);
   h2m->Draw("HIST");
   cnvs2P->SaveAs("JAN24/IN2_MC_tpc2_sel12_East_file_angle_PLUS_JAN2024.pdf");
   cnvs2m->SaveAs("JAN24/IN2_MC_tpc2_sel12_East_file_angle_MINUS_JAN2024.pdf");

   TCanvas* cnvs3P= new TCanvas("cnvs3p", "TPC2 East Cryostat MC IN1 Plus",1,1,600,500);
   h3P->Draw("HIST");
   TCanvas* cnvs3m= new TCanvas("cnvs3m", "TPC2 East Cryostat MC IN1 Minus",1,1,600,500);
   h3m->Draw("HIST");
   cnvs3P->SaveAs("JAN24/IN1_MC_tpc2_sel12_East_file_angle_PLUS_JAN2024.pdf");
   cnvs3m->SaveAs("JAN24/IN1_MC_tpc2_sel12_East_file_angle_MINUS_JAN2024.pdf");

   TCanvas *c1 = new TCanvas("c1", "COL Profile: dqdx vs horizontal angle ",200,10,700,500);
   hz_hor_dQdx_East_tpc2_COL->Draw();
   TCanvas *c2 = new TCanvas("c2", "COL Profile: integral vs horizontal angle ",200,10,700,500);
   hz_hor_INT_East_tpc2_COL->Draw();
   c1->SaveAs("JAN24/COL_Profile_MC_tpc2_sel12_East_file_dqdx_VS_horizontalAngle_JAN2024.pdf");
   c2->SaveAs("JAN24/COL_Profile_MC_tpc2_sel12_East_file_integral_VS_horizontalAngle_JAN2024.pdf");

   TCanvas *c3 = new TCanvas("c3", "IN2 Profile: dqdx vs horizontal angle ",200,10,700,500);
   hz_hor_dQdx_East_tpc2_IN2->Draw();
   TCanvas *c4 = new TCanvas("c4", "IN2 Profile: integral vs horizontal angle ",200,10,700,500);
   hz_hor_INT_East_tpc2_IN2->Draw();
   c3->SaveAs("JAN24/IN2_Profile_MC_tpc2_sel12_East_file_dqdx_VS_horizontalAngle_JAN2024.pdf");
   c4->SaveAs("JAN24/IN2_Profile_MC_tpc2_sel12_East_file_integral_VS_horizontalAngle_JAN2024.pdf");

   TCanvas *c5 = new TCanvas("c5", "IN1 Profile: dqdx vs horizontal angle ",200,10,700,500);
   hz_hor_dQdx_East_tpc2_IN1->Draw();
   TCanvas *c6 = new TCanvas("c6", "IN1 Profile: integral vs horizontal angle ",200,10,700,500);
   hz_hor_INT_East_tpc2_IN1->Draw();
   c5->SaveAs("JAN24/IN1_Profile_MC_tpc2_sel12_East_file_dqdx_VS_horizontalAngle_JAN2024.pdf");
   c6->SaveAs("JAN24/IN1_Profile_MC_tpc2_sel12_East_file_integral_VS_horizontalAngle_JAN2024.pdf");





   TCanvas *c11 = new TCanvas("c11", "COL Profile: dqdx vs plus angle ",200,10,700,500);
   hz_plus_dQdx_East_tpc2_COL->Draw();
   TCanvas *c21 = new TCanvas("c21", "COL Profile: integral vs plus angle ",200,10,700,500);
   hz_plus_INT_East_tpc2_COL->Draw();
   c11->SaveAs("JAN24/COL_Profile_MC_tpc2_sel12_East_file_dqdx_VS_plusAngle_JAN2024.pdf");
   c21->SaveAs("JAN24/COL_Profile_MC_tpc2_sel12_East_file_integral_VS_plusAngle_JAN2024.pdf");

   TCanvas *c31 = new TCanvas("c31", "IN2 Profile: dqdx vs plus angle ",200,10,700,500);
   hz_plus_dQdx_East_tpc2_IN2->Draw();
   TCanvas *c41 = new TCanvas("c41", "IN2 Profile: integral vs plus angle ",200,10,700,500);
   hz_plus_INT_East_tpc2_IN2->Draw();
   c31->SaveAs("JAN24/IN2_Profile_MC_tpc2_sel12_East_file_dqdx_VS_plusAngle_JAN2024.pdf");
   c41->SaveAs("JAN24/IN2_Profile_MC_tpc2_sel12_East_file_integral_VS_plusAngle_JAN2024.pdf");

   TCanvas *c51 = new TCanvas("c51", "IN1 Profile: dqdx vs plus angle ",200,10,700,500);
   hz_plus_dQdx_East_tpc2_IN1->Draw();
   TCanvas *c61 = new TCanvas("c61", "IN1 Profile: integral vs plus angle ",200,10,700,500);
   hz_plus_INT_East_tpc2_IN1->Draw();
   c51->SaveAs("JAN24/IN1_Profile_MC_tpc2_sel12_East_file_dqdx_VS_plusAngle_JAN2024.pdf");
   c61->SaveAs("JAN24/IN1_Profile_MC_tpc2_sel12_East_file_integral_VS_plusAngle_JAN2024.pdf");


   TCanvas *c12 = new TCanvas("c12", "COL Profile: dqdx vs minus angle ",200,10,700,500);
   hz_minus_dQdx_East_tpc2_COL->Draw();
   TCanvas *c22 = new TCanvas("c22", "COL Profile: integral vs minus angle ",200,10,700,500);
   hz_minus_INT_East_tpc2_COL->Draw();
   c12->SaveAs("JAN24/COL_Profile_MC_tpc2_sel12_East_file_dqdx_VS_minusAngle_JAN2024.pdf");
   c22->SaveAs("JAN24/COL_Profile_MC_tpc2_sel12_East_file_integral_VS_minusAngle_JAN2024.pdf");

   TCanvas *c32 = new TCanvas("c32", "IN2 Profile: dqdx vs minus angle ",200,10,700,500);
   hz_minus_dQdx_East_tpc2_IN2->Draw();
   TCanvas *c42 = new TCanvas("c42", "IN2 Profile: integral vs minus angle ",200,10,700,500);
   hz_minus_INT_East_tpc2_IN2->Draw();
   c32->SaveAs("JAN24/IN2_Profile_MC_tpc2_sel12_East_file_dqdx_VS_minusAngle_JAN2024.pdf");
   c42->SaveAs("JAN24/IN2_Profile_MC_tpc2_sel12_East_file_integral_VS_minusAngle_JAN2024.pdf");

   TCanvas *c52 = new TCanvas("c52", "IN1 Profile: dqdx vs minus angle ",200,10,700,500);
   hz_minus_dQdx_East_tpc2_IN1->Draw();
   TCanvas *c62 = new TCanvas("c62", "IN1 Profile: integral vs minus angle ",200,10,700,500);
   hz_minus_INT_East_tpc2_IN1->Draw();
   c52->SaveAs("JAN24/IN1_Profile_MC_tpc2_sel12_East_file_dqdx_VS_minusAngle_JAN2024.pdf");
   c62->SaveAs("JAN24/IN1_Profile_MC_tpc2_sel12_East_file_integral_VS_minusAngle_JAN2024.pdf");




   std::cout << "Number of files in our MC list is " << my_files->GetNFiles() << std::endl;
   cout<<"end of macro"<<endl;


}
