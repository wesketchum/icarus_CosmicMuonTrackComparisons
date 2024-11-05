#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "sbnobj/Common/Calibration/TrackCaloSkimmerObj.h"



void Sept_angle_E_MAY2023(bool verbose=false) {


  gStyle->SetOptStat(0);
  ofstream outfile("t.txt");
  ofstream outfile_col_mc("mcMAY2023_NUMI_tpc0_sel12_East_file_xyz_col.txt");
  ofstream outfile_in2_mc("mcMAY2023_NUMI_tpc0_sel12_East_file_xyz_in2.txt");
  ofstream outfile_in1_mc("mcMAY2023_NUMI_tpc0_sel12_East_file_xyz_in1.txt");

  ofstream outfile_col_data("dataMAY2023_NUMI_tpc0_sel12_East_file_xyz_col.txt");
  ofstream outfile_in2_data("dataMAY2023_NUMI_tpc0_sel12_East_file_xyz_in2.txt");
  ofstream outfile_in1_data("dataMAY2023_NUMI_tpc0_sel12_East_file_xyz_in1.txt");


  ofstream outfileqc("MAY2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_Qdx_col.txt");
  ofstream outfileq1("MAY2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_Qdx_in1.txt");
  ofstream outfileq2("MAY2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_Qdx_in2.txt");

  ofstream outfilehc("MAY2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_HC_col.txt");
  ofstream outfileh1("MAY2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_HC_in1.txt");
  ofstream outfileh2("MAY2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_HC_in2.txt");


  ofstream outfile1("hnoCOSangle_by_MAY2023__col_E_tpc0.txt");
  ofstream outfile2("hnoCOSangle_by_MAY2023__in1_E_tpc0.txt");
  ofstream outfile3("hnoCOSangle_by_MAY2023__in2_E_tpc0.txt");
  ofstream outfile4("hnoCOSangle_by_MAY2023__col_W_tpc0.txt");
  ofstream outfile5("hnoCOSangle_by_MAY2023__in1_W_tpc0.txt");
  ofstream outfile6("hnoCOSangle_by_MAY2023__in2_W_tpc0.txt");


  int n = 5000;

  double X_SEL12_East_MC_col[n];
  double X_SEL12_East_MC_in1[n];
  double X_SEL12_East_MC_in2[n];

  double Y_SEL12_East_MC_col[n];
  double Y_SEL12_East_MC_in1[n];
  double Y_SEL12_East_MC_in2[n];

  double Z_SEL12_East_MC_col[n];
  double Z_SEL12_East_MC_in1[n];
  double Z_SEL12_East_MC_in2[n];


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

  TH1F *h1p = new TH1F("h1p","TPC0 East Cryostat MC (COL) ", 100., 0.0, 2.0); //0., 7.0);                             
  h1p->GetXaxis()->SetTitle("angle in radians");

  TH1F *h4p = new TH1F("h4p","TPC0 West Cryostat MC (COL) ", 100., 0.0, 2.0); //0., 7.0);                             
  h4p->GetXaxis()->SetTitle("angle in radians");

  TH1F *h5p = new TH1F("h5p","TPC0 West Cryostat MC (IN1) ", 100., 0.0, 2.0); //0., 7.0);                             
  h5p->GetXaxis()->SetTitle("angle in radians");

  TH1F *h6p = new TH1F("h6p","TPC0 West Cryostat MC (IN2) ", 100., 0.0, 2.0); //0., 7.0);                             
  h6p->GetXaxis()->SetTitle("angle in radians");

  TH1F *h2p = new TH1F("h2p","TPC0 East Cryostat MC (IN1) ", 100., 0.0, 2.0); //0., 7.0);                            \
                                                                                                                      
  h2p->GetXaxis()->SetTitle("angle in radians");

  TH1F *h3p = new TH1F("h3p","TPC0 East Cryostat MC (IN2) ", 100., 0.0, 2.0); //0., 7.0);                            \
                                                                                                                      
  h3p->GetXaxis()->SetTitle("angle in radians");





   //Get the files from ICARUS gpvm
  TFileCollection *my_files = new TFileCollection("my_files","My File List");

  my_files->AddFromFile("mc_april22versiontest2.txt");//mc_aprilversion.txt");
  //  my_files->Add("/pnfs/icarus/persistent/calibration/calib_ntuples/mc/2022A/NUMI_in-time_Cosmics/ff/f6/hist_prodcorsika_proton_intime_icarus_numi_sce_on_gen_g4_detsim_reco1_55129168_4162_reco2-6776dd5e-af02-4946-b111-3e02546ada0d.root");//icarus/app/users/obitter/icarus_CosmicMuonTrackComparisons/mc_april22version.txt");//   /pnfs/icarus/persistent/calibration/calib_ntuples/mc/2022A/NUMI_in-time_Cosmics/*/*/*.root");
  ///pnfs/icarus/persistent/calibration/calib_ntuples/mc/ICARUS_NuMI_Nu_Cosmics/hist_prodcorsika_genie_protononly_icarus_numi*.root");///pnfs/icarus/persistent/calibration/calib_ntuples/mc/ICARUS_BNB_Nu_Cosmics/hist_prodcorsika_bnb*.root");//_genie_protononly_overburden_icarus_gen_filter_g4_detsim_48288510_9_reco1_20210916T052145_reco2.root");//hist_prodcorsika_genie_protononly_icarus_numi_volDetEnclosure_tpc_gen_filter_g4_detsim_48288511_98_reco1_20210912T202552_reco2.root");//*.root");//

  //*.root");

//ICARUS_NuMI_Nu_Cosmics/hist_prodcorsika_genie_protononly_icarus_numi_*.root");///icarus/data/users/obitter/CalibrationWS21/hist_prodcorsika_genie_protononly_icarus_numi*.root");//  /pnfs/icarus/persistent/calibration/calib_ntuples/mc/ICARUS_NuMI_Nu_Cosmics/hist_prodcorsika_genie_protononly_icarus_numi_*.root);//volDetEnclosure_tpc_gen_filter_g4_detsim_48288511_90_reco1_20210912T095950_reco2.root");///icarus/data/users/obitter/CalibrationWS21/hist_prodcorsika_genie_protononly_icarus_numi_volDetEnclosure_tpc_gen_filter_g4_detsim_48288511_9_reco1_20210912T103409_reco2.root");//*.root");

///pnfs/icarus/persistent/calibration/calib_ntuples/mc/ICARUS_NuMI_Nu_Cosmics/hist_prodcorsika_genie_protononly_icarus_numi_volDetEnclosure_tpc_gen_filter_g4_detsim_48288511*.root");//24037195*.root");   ///icarus/data/users/obitter/CalibrationWS21/hist_prodcorsika_genie_protononly_icarus_numi*.root");//_volDetEnclosure_tpc_gen_filter_g4_detsim_48288511_9_reco1_20210912T103409_reco2.root");//hist_prodcorsika_genie_protononly_icarus_numi*.root");//    
  ///pnfs/icarus/persistent/calibration/calib_ntuples/mc/ICARUS_NuMI_Nu_Cosmics/hist*.root"); 
  //  /icarus/data/users/obitter/CalibrationWS21/hist_prodcorsika_genie_protononly_icarus_numi*.root");//
///pnfs/icarus/persistent/calibration/calib_ntuples/mc/ICARUS_NuMI_Nu_Cosmics/
//hist_prodcorsika_genie_protononly_icarus_numi*.root");//hist_prodcorsika_genie_protononly_icarus_numi_volDetEnclosure_tpc_gen_filter_g4_detsim_48288511_9_reco1_20210912T103409_reco2.root");//hist*.root");
 outfile<< "Number of files in our MC list is " << my_files->GetNFiles() <<endl;
  TChain myfile("caloskimE/TrackCaloSkim");
  myfile.AddFileInfoList(my_files->GetList());

  TFileCollection *my_files2 = new TFileCollection("my_files2","My File List2");
  my_files2->AddFromFile("data_april22versiontest2.txt");

  //  my_files2->Add("/pnfs/icarus/persistent/calibration/calib_ntuples/production/v09_37_02_01/numi/ff/c2/hist_data_dl1_fstrmNUMI_run7897_43_20220314T040651_20220404T053037_pot_20220404T071845_stage0_20220409T040314_stage1.root");///pnfs/icarus/persistent/calibration/calib_ntuples/production/v09_37_02_01/numi/*/*/*.root");
  ///pnfs/icarus/persistent/calibration/calib_ntuples/data/hist_data_dl4_fstrmNUMI*.root");///icarus/data/users/obitter/CalibrationWS21/hist_data_dl4_fstrmBNB_run6106_9_20210626T121435_20210813T230443_stage0_20210814T130318_stage1-bf52c0be-5863-4a74-a49b-7273aca42be3.root");///icarus/data/users/obitter/CalibrationWS21/*BNB*.root"); ///pnfs/icarus/persistent/calibration/calib_ntuples/data/*BNB*run606*.root");///icarus/data/users/obitter/CalibrationWS21/*BNB*.root");

///pnfs/icarus/persistent/calibration/calib_ntuples/data/*BNB*run5*.root");//*BNB*run6100*.root");//*BNB*.root");///icarus/data/users/obitter/CalibrationWS21/hist_data_dl4_fstrm*.root");///pnfs/icarus/persistent/calibration/calib_ntuples/data/hist_data_dl4_fstrmNUMI_*.root);//run6100_8_20210624T222802_20210810T173022_stage0_20210811T172950_stage1-aaf73d30-50ca-4661-a655-5e11616b005d.root");///pnfs/icarus/persistent/calibration/calib_ntuples/data/hist_data_dl4_fstrmNUMI_run6106_3_20210626T110945_20210812T034226_stage0_20210812T113610_stage1-2f1b69b2-5063-44e9-a1d2-129b4cb99fed.root");///pnfs/icarus/persistent/calibration/calib_ntuples/data/hist_data_dl4_fstrmNUMI_run6106_7_20210626T122720_20210812T011952_stage0_20210812T120934_stage1-8dc3d211-6be0-4580-b340-9b68768e98f5.root");

///icarus/data/users/obitter/CalibrationWS21/hist_data_dl4_fstrmNUMI_run6106_50_20210627T040512_20210812T023813_stage0_20210812T121941_stage1-008e44f5-2b5f-49f3-9bf3-927a0c4bd7c1.root");   //*.root");
// /icarus/data/users/obitter/CalibrationWS21/hist_data_dl4_fstrmNUMI*.root");/icarus/data/users/obitter/CalibrationWS21/hist_data_dl4_fstrmNUMI*.root");

///pnfs/icarus/persistent/calibration/calib_ntuples/data/hist_data_dl4_fstrmNUMI*.root");//hist*.root"); ///icarus/data/users/obitter/CalibrationWS21/hist_data*NUMI*.root");//_dl4_fstrmNUMI_run6106_50_20210627T040512_20210812T023813_stage0_20210812T121941_stage1-008e44f5-2b5f-49f3-9bf3-927a0c4bd7c1.root");

//his*NUMI*.root");//
//pnfs/icarus/persistent/calibration/calib_ntuples/data/hist_data_dl4_fstrmNUMI*.root"); 
  ///icarus/data/users/obitter/CalibrationWS21/hist_data_dl4_fstrmNUMI*.root");///pnfs/icarus/persistent/calibration/calib_ntuples/data/hist_data_dl4_fstrmNUMI_run6106_50_20210627T040512_20210812T023813_stage0_20210812T121941_stage1-008e44f5-2b5f-49f3-9bf3-927a0c4bd7c1.root");//hist_data_dl4_fstrmNUMI*.root");
  outfile<< "Number of files in our data list is " << my_files2->GetNFiles()<<endl;
  TChain myfile2("caloskimE/TrackCaloSkim");
  myfile2.AddFileInfoList(my_files2->GetList());

  cout<<"files read"<<endl;

  //delcare variables
  TTreeReader myReader(&myfile);
  TTreeReader myReader2(&myfile2);
  
  TTreeReaderValue<int> selected(myReader, "trk.selected");
  TTreeReaderValue<int> selected2(myReader2, "trk.selected");
  
  TTreeReaderValue<float> startX(myReader, "trk.start.x");
  TTreeReaderValue<float> startX2(myReader2, "trk.start.x");
  
  TTreeReaderValue<float> startY(myReader, "trk.start.y");
  TTreeReaderValue<float> startY2(myReader2, "trk.start.y");

  TTreeReaderValue<float> startZ(myReader, "trk.start.z");
  TTreeReaderValue<float> startZ2(myReader2, "trk.start.z");


  TTreeReaderValue<float> endX(myReader, "trk.end.x");
  TTreeReaderValue<float> endX2(myReader2, "trk.end.x");

  TTreeReaderValue<float> endY(myReader, "trk.end.y");
  TTreeReaderValue<float> endY2(myReader2, "trk.end.y");

  TTreeReaderValue<float> endZ(myReader, "trk.end.z");
  TTreeReaderValue<float> endZ2(myReader2, "trk.end.z");

  TTreeReaderValue<int> run(myReader, "trk.meta.run");
  TTreeReaderValue<int> run2(myReader2, "trk.meta.run");



  TTreeReaderValue<int> event(myReader, "trk.meta.evt");
  TTreeReaderValue<int> event2(myReader2, "trk.meta.evt");


  
  TTreeReaderArray<float> dqdx_i1(myReader, "trk.hits0.dqdx");
  TTreeReaderArray<float> dqdx2_i1(myReader2, "trk.hits0.dqdx");
  
  TTreeReaderArray<float> dqdx_c(myReader, "trk.hits2.dqdx");                                                                       
  TTreeReaderArray<float> dqdx2_c(myReader2, "trk.hits2.dqdx");                                                                                                                                                                             

  TTreeReaderArray<float> dqdx_i2(myReader, "trk.hits1.dqdx");
  TTreeReaderArray<float> dqdx2_i2(myReader2, "trk.hits1.dqdx");


  TTreeReaderArray<float> rr_c(myReader, "trk.hits2.rr");
  TTreeReaderArray<float> rr2_c(myReader2, "trk.hits2.rr");

  TTreeReaderArray<float> rr_i2(myReader, "trk.hits1.rr");
  TTreeReaderArray<float> rr2_i2(myReader2, "trk.hits1.rr");

  TTreeReaderArray<float> rr_i1(myReader, "trk.hits0.rr");
  TTreeReaderArray<float> rr2_i1(myReader2, "trk.hits0.rr");

  
  TTreeReaderArray<float> z_i1(myReader, "trk.hits0.dir.z");
  TTreeReaderArray<float> z2_i1(myReader2, "trk.hits0.dir.z");
  
  TTreeReaderArray<float> y_i1(myReader, "trk.hits0.dir.y");
  TTreeReaderArray<float> y2_i1(myReader2, "trk.hits0.dir.y");
  
  TTreeReaderArray<float> x_i1(myReader, "trk.hits0.dir.x");
  TTreeReaderArray<float> x2_i1(myReader2, "trk.hits0.dir.x");
  
  TTreeReaderArray<float> z_i2(myReader, "trk.hits1.dir.z");
  TTreeReaderArray<float> z2_i2(myReader2, "trk.hits1.dir.z");
  
  TTreeReaderArray<float> y_i2(myReader, "trk.hits1.dir.y");
  TTreeReaderArray<float> y2_i2(myReader2, "trk.hits1.dir.y");
  
  TTreeReaderArray<float> x_i2(myReader, "trk.hits1.dir.x");
  TTreeReaderArray<float> x2_i2(myReader2, "trk.hits1.dir.x");
  
  TTreeReaderArray<float> z_c(myReader, "trk.hits2.dir.z");
  TTreeReaderArray<float> z2_c(myReader2, "trk.hits2.dir.z");
  
  TTreeReaderArray<float> y_c(myReader, "trk.hits2.dir.y");
  TTreeReaderArray<float> y2_c(myReader2, "trk.hits2.dir.y");
 
  TTreeReaderArray<float> x_c(myReader, "trk.hits2.dir.x");
  TTreeReaderArray<float> x2_c(myReader2, "trk.hits2.dir.x");
 
  TTreeReaderArray<bool> ontraj_c(myReader, "trk.hits2.ontraj");
  TTreeReaderArray<bool> ontraj2_c(myReader2, "trk.hits2.ontraj");

  TTreeReaderArray<bool> ontraj_i2(myReader, "trk.hits1.ontraj");
  TTreeReaderArray<bool> ontraj2_i2(myReader2, "trk.hits1.ontraj");

  TTreeReaderArray<bool> ontraj_i1(myReader, "trk.hits0.ontraj");
  TTreeReaderArray<bool> ontraj2_i1(myReader2, "trk.hits0.ontraj");

  TTreeReaderValue<float> length(myReader, "trk.length");
  TTreeReaderValue<float> length2(myReader2, "trk.length");

  TTreeReaderValue<float> t0(myReader, "trk.t0");
  TTreeReaderValue<float> t02(myReader2, "trk.t0");

  TTreeReaderArray<float> integral_c(myReader, "trk.hits2.h.integral");
  TTreeReaderArray<float> integral2_c(myReader2, "trk.hits2.h.integral");

  TTreeReaderArray<float> integral_i2(myReader, "trk.hits1.h.integral");
  TTreeReaderArray<float> integral2_i2(myReader2, "trk.hits1.h.integral");

  TTreeReaderArray<float> integral_i1(myReader, "trk.hits0.h.integral");
  TTreeReaderArray<float> integral2_i1(myReader2, "trk.hits0.h.integral");

  TTreeReaderArray<float> width_c(myReader, "trk.hits2.h.width");
  TTreeReaderArray<float> width2_c(myReader2, "trk.hits2.h.width");

  TTreeReaderArray<float> width_i2(myReader, "trk.hits1.h.width");
  TTreeReaderArray<float> width2_i2(myReader2, "trk.hits1.h.width");

  TTreeReaderArray<float> width_i1(myReader, "trk.hits0.h.width");
  TTreeReaderArray<float> width2_i1(myReader2, "trk.hits0.h.width");

  TTreeReaderArray<uint16_t> tpc_c(myReader, "trk.hits2.h.tpc");
  TTreeReaderArray<uint16_t> tpc2_c(myReader2, "trk.hits2.h.tpc");

  TTreeReaderArray<uint16_t> tpc_i2(myReader, "trk.hits1.h.tpc");
  TTreeReaderArray<uint16_t> tpc2_i2(myReader2, "trk.hits1.h.tpc");

  TTreeReaderArray<uint16_t> tpc_i1(myReader, "trk.hits0.h.tpc");
  TTreeReaderArray<uint16_t> tpc2_i1(myReader2, "trk.hits0.h.tpc");

  TTreeReaderArray<uint16_t> wire_c(myReader, "trk.hits2.h.wire");
  TTreeReaderArray<uint16_t> wire2_c(myReader2, "trk.hits2.h.wire");

  TTreeReaderArray<uint16_t> wire_i2(myReader, "trk.hits1.h.wire");
  TTreeReaderArray<uint16_t> wire2_i2(myReader2, "trk.hits1.h.wire");

  TTreeReaderArray<uint16_t> wire_i1(myReader, "trk.hits0.h.wire");
  TTreeReaderArray<uint16_t> wire2_i1(myReader2, "trk.hits0.h.wire");

  TTreeReaderArray<float> time_c(myReader, "trk.hits2.h.time");
  TTreeReaderArray<float> time2_c(myReader2, "trk.hits2.h.time");

  TTreeReaderArray<float> time_i2(myReader, "trk.hits1.h.time");
  TTreeReaderArray<float> time2_i2(myReader2, "trk.hits1.h.time");

  TTreeReaderArray<float> time_i1(myReader, "trk.hits0.h.time");
  TTreeReaderArray<float> time2_i1(myReader2, "trk.hits0.h.time");

  TTreeReaderArray<float> pitch_c(myReader, "trk.hits2.pitch");
  TTreeReaderArray<float> pitch2_c(myReader2, "trk.hits2.pitch");

  TTreeReaderArray<float> pitch_i2(myReader, "trk.hits1.pitch");
  TTreeReaderArray<float> pitch2_i2(myReader2, "trk.hits1.pitch");

  TTreeReaderArray<float> pitch_i1(myReader, "trk.hits0.pitch");
  TTreeReaderArray<float> pitch2_i1(myReader2, "trk.hits0.pitch");






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
   double tpc_num = 0;


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

     outfile_col_mc<<x_c[last_h_mc_c]<<" "<<y_c[last_h_mc_c]<<" "<<z_c[last_h_mc_c]<<endl;
    

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


     outfileqc<<av_dqdx_mc_c<<endl;
     outfilehc<<av_integral_mc_c<<endl;

     cout<<"collection done"<<endl;

     if(tpc_i2[last_h_mc_i2]!=tpc_num)continue;//==0) continue;


     outfile_in2_mc<<x_i2[last_h_mc_i2]<<" "<<y_i2[last_h_mc_i2]<<" "<<z_i2[last_h_mc_i2]<<endl;


     X_SEL12_East_MC_in2[last_h_mc_i2] = x_i2[last_h_mc_i2];
     Y_SEL12_East_MC_in2[last_h_mc_i2] = y_i2[last_h_mc_i2];
     Z_SEL12_East_MC_in2[last_h_mc_i2] = z_i2[last_h_mc_i2];



     double sum_integral_mc_i2 =0.0;
     double sum_dqdx_mc_i2 =0.0;
     for(int j = 0; j <last_h_mc_i2; j++){
       sum_integral_mc_i2 += integral_i2[j];
       sum_dqdx_mc_i2 += dqdx_i2[j];
     }
     double av_integral_mc_i2 = sum_integral_mc_i2/last_h_mc_i2;
     double av_dqdx_mc_i2 = sum_dqdx_mc_i2/last_h_mc_i2;


     outfileq2<<av_dqdx_mc_i2<<endl;
     outfileh2<<av_integral_mc_i2<<endl;




     cout<<"induction 2 done"<<endl;



     if(tpc_i1[last_h_mc_i1]!=tpc_num)continue;//==0) continue;

     outfile_in1_mc<<x_i1[last_h_mc_i1]<<" "<<y_i1[last_h_mc_i1]<<" "<<z_i1[last_h_mc_i1]<<endl;     //60 degrees plus:                         

     X_SEL12_East_MC_in1[last_h_mc_i1] = x_i1[last_h_mc_i1];
     Y_SEL12_East_MC_in1[last_h_mc_i1] = y_i1[last_h_mc_i1];
     Z_SEL12_East_MC_in1[last_h_mc_i1] = z_i1[last_h_mc_i1];



     double sum_integral_mc_i1 =0.0;
     double sum_dqdx_mc_i1 =0.0;
     for(int k = 0; k <last_h_mc_i1; k++){
       sum_integral_mc_i1 += integral_i1[k];
       sum_dqdx_mc_i1 += dqdx_i1[k];
     }
     double av_integral_mc_i1 = sum_integral_mc_i1/last_h_mc_i1;
     double av_dqdx_mc_i1 = sum_dqdx_mc_i1/last_h_mc_i1;
                            
     outfileq1<<av_dqdx_mc_i1<<endl;
     outfileh1<<av_integral_mc_i1<<endl;



                                     
     cout<<"induction 1 done"<<endl;     


   }//end while myReader

   cout<<"MC done"<<endl;
   // outfile<<"MC done"<<endl;//track "<<a<<endl;
   //Data Azimuthal Angle
   while (myReader2.Next()) {
     if(*selected2 == 0) continue; //if not stopping, move one.

     //if(*tpc3 != 0) continue;

     b++;
     //get the last traj point on the collection plane


     if(y2_c.GetSize() == 0) continue;
     if(y2_i2.GetSize() == 0) continue;
     if(y2_i1.GetSize() == 0) continue;
     int last_h_data_c = y2_c.GetSize()-1;
     int last_h_data_i2 = y2_i2.GetSize()-1;
     int last_h_data_i1 = y2_i1.GetSize()-1;


     cout<<"DATA"<<endl;
     cout<<*run2<<" RUN"<<endl;
     cout<<*event2<<" EVENT"<<endl;
     cout<<" x c "<<x2_c.GetSize()-1<<" x i2 " <<x2_i2.GetSize()-1<<" x i1 "<<x2_i1.GetSize()-1<<endl;
     cout<<" y c "<<y2_c.GetSize()-1<<" y i2 " <<y2_i2.GetSize()-1<<" y i1 "<<y2_i1.GetSize()-1<<endl;
     cout<<" z c "<<z2_c.GetSize()-1<<" z i2 " <<z2_i2.GetSize()-1<<" z i1 "<<z2_i1.GetSize()-1<<endl;
     cout<<" tpc c "<<tpc2_c[last_h_data_c]<<endl;
     cout<<" tpc i2 "<<tpc2_i2[last_h_data_i2]<<endl;
     cout<<" tpc i1 "<<tpc2_i1[last_h_data_i1]<<endl;
     //cout<<*run2<<endl;
     //cout<<*event2<<endl;

     //if not on thr trajectory, continue
     if(ontraj2_c[last_h_data_c]!=1) continue;
     if(ontraj2_i2[last_h_data_i2]!=1) continue;
     if(ontraj2_i1[last_h_data_i1]!=1) continue;





     if(tpc2_c[last_h_data_c]!=tpc_num)continue;//==0) continue;

     outfile_col_data<<x2_c[last_h_data_c]<<" "<<y2_c[last_h_data_c]<<" "<<z2_c[last_h_data_c]<<endl;
     //60 degrees plus:                                                      
     cout<<"collection done"<<endl;
     //if(verbose) 
     //cout << "MC angle " << TMath::ATan(x_c[last_h_mc_c]/z_c[last_h_mc_c]) << endl;

     //and fill all the other histograms related to traj points too
     

     //if(ontraj2_i2[last_h_data_i2]!=1) continue;
     if(tpc2_i2[last_h_data_i2]!=tpc_num)continue;//==0) continue;

     outfile_in2_data<<x2_i2[last_h_data_i2]<<" "<<y2_i2[last_h_data_i2]<<" "<<z2_i2[last_h_data_i2]<<endl;

     //60 degree
     cout<<"induction 2 done"<<endl;


     //if(ontraj2_i1[last_h_data_i1]!=1) continue;
     if(tpc2_i1[last_h_data_i1]!=tpc_num)continue;//==0) continue;
     outfile_in1_data<<x2_i1[last_h_data_i1]<<" "<<y2_i1[last_h_data_i1]<<" "<<z2_i1[last_h_data_i1]<<endl;



     cout<<"induction 1 done"<<endl;

   }//end while myReader2
   
   

   cout<<"data done"<<endl;
   outfile<<"data done"<<endl;
   
   double z_p = 1.0;

   double Pi = 3.1415926535897932384;

   for(int alpha = 0; alpha<n; alpha++){

     angle_by_col_E[alpha] = TMath::ACos( (  (Z_SEL12_East_MC_col[alpha]*z_p) ) / ( sqrt(X_SEL12_East_MC_col[alpha]*X_SEL12_East_MC_col[alpha]+ Y_SEL12_East_MC_col[alpha]*Y_SEL12_East_MC_col[alpha]+Z_SEL12_East_MC_col[alpha]*Z_SEL12_East_MC_col[alpha]) * sqrt( (z_p*z_p) ) ) );


     cout<<angle_by_col_E[alpha]<<endl;
     cout<<((Pi)/2.0)<<endl;

     if( (angle_by_col_E[alpha] > ((Pi)/2.0)) && (angle_by_col_E[alpha] < (Pi) ) ){
       outfile1<<(Pi) - angle_by_col_E[alpha]<<endl;
       h1p->Fill((Pi) - angle_by_col_E[alpha]);
       cout<<"here"<<endl;
     }

     else if( (angle_by_col_E[alpha] > (Pi)) && (angle_by_col_E[alpha] < ((3.0*Pi)/2.0)) ){
       outfile1<<angle_by_col_E[alpha] - (Pi)<<endl;
       h1p->Fill(angle_by_col_E[alpha] - (Pi));
       cout<<"2here"<<endl;
     }

     else if( angle_by_col_E[alpha] < ((Pi)/2.0) ){
       outfile1<<angle_by_col_E[alpha]<<endl;
       h1p->Fill(angle_by_col_E[alpha]);
       cout<<" not"<<endl;
     }



   }

   for(int beta = 0; beta<n; beta++){
     angle_by_in1_E[beta] = TMath::ACos( (  (Z_SEL12_East_MC_in1[beta]*z_p) ) / ( sqrt(X_SEL12_East_MC_in1[beta]*X_SEL12_East_MC_in1[beta]+Y_SEL12_East_MC_in1[beta]*Y_SEL12_East_MC_in1[beta]+Z_SEL12_East_MC_in1[beta]*Z_SEL12_East_MC_in1[beta]) * sqrt( (z_p*z_p) ) ) );
     if(  (angle_by_in1_E[beta] > ((Pi)/2.0) ) && (angle_by_in1_E[beta] < (Pi) )){
       outfile2<<(Pi) - angle_by_in1_E[beta]<<endl;
       h2p->Fill((Pi) - angle_by_in1_E[beta]);
     }

     else if(  (angle_by_in1_E[beta] > (Pi) ) && (angle_by_in1_E[beta] < ((3.0*Pi)/2.0) )){
       outfile2<<angle_by_in1_E[beta] -(Pi)<<endl;
       h2p->Fill(angle_by_in1_E[beta] -(Pi));
     }

     else if(angle_by_in1_E[beta] < ((Pi)/2.0) ){
       outfile2<<angle_by_in1_E[beta]<<endl;
       h2p->Fill(angle_by_in1_E[beta]);
     }
   }



   for(int gamma = 0; gamma<n; gamma++){
     angle_by_in2_E[gamma] = TMath::ACos( ( (Z_SEL12_East_MC_in2[gamma]*z_p) ) / ( sqrt(X_SEL12_East_MC_in2[gamma]*X_SEL12_East_MC_in2[gamma]+Y_SEL12_East_MC_in2[gamma]*Y_SEL12_East_MC_in2[gamma]+Z_SEL12_East_MC_in2[gamma]*Z_SEL12_East_MC_in2[gamma]) * sqrt( (z_p*z_p) ) ) );
     if( (angle_by_in2_E[gamma] > (Pi)) && (angle_by_in2_E[gamma] < ((3.0*Pi)/2.0))){

       outfile3<<angle_by_in2_E[gamma]-(Pi)<<endl;
       h3p->Fill( angle_by_in2_E[gamma]-(Pi));

     }

     else if( (angle_by_in2_E[gamma] > ((Pi)/2.0)) && (angle_by_in2_E[gamma] < (Pi))){

       outfile3<<(Pi) - angle_by_in2_E[gamma]<<endl;
       h3p->Fill((Pi) - angle_by_in2_E[gamma]);

     }
     else if(angle_by_in2_E[gamma] < ((Pi)/2.0) ){

       outfile3<<angle_by_in2_E[gamma]<<endl;
       h3p->Fill(angle_by_in2_E[gamma]);                                                                                                         }
   }



   TCanvas* cnvs1p= new TCanvas("cnvs1p", "TPC0 East Cryostat MC COL",1,1,600,500);
   h1p->Draw("HIST");
   TCanvas* cnvs2p= new TCanvas("cnvs2p", "TPC0 East Cryostat MC IN1",1,1,600,500);
   h2p->Draw("HIST");
   TCanvas* cnvs3p= new TCanvas("cnvs3p", "TPC0 East Cryostat MC IN2",1,1,600,500);
   h3p->Draw("HIST");
   TCanvas* cnvs4p= new TCanvas("cnvs4p", "TPC0 West Cryostat MC COL",1,1,600,500);
   h4p->Draw("HIST");
   TCanvas* cnvs5p= new TCanvas("cnvs5p", "TPC0 West Cryostat MC IN1",1,1,600,500);
   h5p->Draw("HIST");
   TCanvas* cnvs6p= new TCanvas("cnvs6p", "TPC0 West Cryostat MC IN2",1,1,600,500);
   h6p->Draw("HIST");

   cnvs1p->SaveAs("MC_tpc0_sel12_East_file_xyz_col_angle_NEW_h_AUG2023.pdf");
   cnvs2p->SaveAs("MC_tpc0_sel12_East_file_xyz_in1_angle_NEW_h_AUG2023.pdf");
   cnvs3p->SaveAs("MC_tpc0_sel12_East_file_xyz_in2_angle_NEW_h_AUG2023.pdf");
   cnvs4p->SaveAs("MC_tpc0_sel12_West_file_xyz_col_angle_NEW_h_AUG2023.pdf");
   cnvs5p->SaveAs("MC_tpc0_sel12_West_file_xyz_in1_angle_NEW_h_AUG2023.pdf");
   cnvs6p->SaveAs("MC_tpc0_sel12_West_file_xyz_in2_angle_NEW_h_AUG2023.pdf");


   std::cout << "Number of files in our MC list is " << my_files->GetNFiles() << std::endl;
   std::cout << "Number of files in our data list is " << my_files2->GetNFiles() << std::endl;

   cout<<"end of macro"<<endl;


}
