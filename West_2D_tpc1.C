#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

void West_2D_tpc1(bool verbose=false) {


  gStyle->SetOptStat(0);



  ifstream ifile1("OUTFILE_mc_my_outputNUMI_tpc1_sel12_West_file_Length_Az_col.txt");
  ifstream ifile2("OUTFILE_mc_my_outputNUMI_tpc1_sel12_West_file_Cint_Az_col.txt");
  ifstream ifile3("OUTFILE_data_my_outputNUMI_tpc1_sel12_West_file_Length_Az_col.txt");
  ifstream ifile4("OUTFILE_data_my_outputNUMI_tpc1_sel12_West_file_Cint_Az_col.txt");

  int n = 40000;
          
  int MC_L0 = 0;
  int MC_C0 = 0;
  int DATA_L0 = 0;
  int DATA_C0 = 0;

  double MCL0 = 0.0;
  double MCC0 = 0.0;
  double MCA0 = 0.0;
  double MCAz0 = 0.0;
  double DATAL0 = 0.0;
  double DATAC0 = 0.0;
  double DATAA0 = 0.0;
  double DATAAz0 = 0.0;

  int MC_L1 = 0;
  int MC_C1 = 0;
  int DATA_L1 = 0;
  int DATA_C1 = 0;

  double MCL1 = 0.0;
  double MCC1 = 0.0;
  double MCA1 = 0.0;
  double MCAz1 = 0.0;
  double DATAL1 = 0.0;
  double DATAC1 = 0.0;
  double DATAA1 = 0.0;
  double DATAAz1 = 0.0;



  double Length_MC0[n];
  double Length_DATA0[n];
  double Cint_MC0[n];
  double Cint_DATA0[n];

  double Length_MC1[n]; 
  double Length_DATA1[n];
  double Cint_MC1[n];
  double Cint_DATA1[n];

  double Az_MC0[n];
  double Az_DATA0[n];
  double Az_MC1[n];
  double Az_DATA1[n];





  ofstream outfile("test.txt");





  while(ifile1>>MCA0>>MCL0)
    {
        Az_MC0[MC_L0] = MCA0;
      Length_MC0[MC_L0] = MCL0;

      //      cout<<Az_MC0[MC_L0]<<" "<<Length_MC0[MC_L0]<<endl;

      MC_L0++;
    }

  while(ifile2>>MCAz0>>MCC0)
    {
     Cint_MC0[MC_C0] = MCC0;
     //     cout<<Cint_MC0[MC_C0]<<endl;

      MC_C0++;
    }

  while(ifile3>>DATAA0>>DATAL0)
    {
      Az_DATA0[DATA_L0] = DATAA0;
       Length_DATA0[DATA_L0] = DATAL0;
       //cout<<Az_DATA0[DATA_L0]<<" "<<Length_DATA0[DATA_L0]<<endl;

      DATA_L0++;
    }

  while(ifile4>>DATAAz0>>DATAC0)
    {
      Cint_DATA0[DATA_C0] = DATAC0;
      //cout<<Cint_DATA0[DATA_C0]<<endl;

      DATA_C0++;
    }




  //  TCanvas* cnvs_az2 = new TCanvas("cnvs_az2", "c1", 1,1,800,700);   
  THStack *hs_az2 = new THStack("hs_az2","");
  //TCanvas* cnvs_z2 = new TCanvas("cnvs_z2", "c1", 1,1,800,700);
  THStack *hs_zz2 = new THStack("hs_zz2","");
  //TCanvas* cnvs_az1 = new TCanvas("cnvs_az1", "c1", 1,1,800,700);
  THStack *hs_az1 = new THStack("hs_az1","");
  //TCanvas* cnvs_z1 = new TCanvas("cnvs_z1", "c1", 1,1,800,700);
  THStack *hs_zz1 = new THStack("hs_zz1","");
  //TCanvas* cnvs_az0 = new TCanvas("cnvs_az0", "c1", 1,1,800,700);
  THStack *hs_az0 = new THStack("hs_az0","");
  //TCanvas* cnvs_z0 = new TCanvas("cnvs_z0", "c1", 1,1,800,700);
  THStack *hs_zz0 = new THStack("hs_zz0","");
  //TCanvas* cnvs_l = new TCanvas("cnvs_l", "c1", 1,1,800,700);
  THStack *hs_l = new THStack("hs_l","");

  THStack *hs_l2Dc = new THStack("hs_l2Dc","");
  THStack *hs_l2D1 = new THStack("hs_l2D1","");
  THStack *hs_l2D2 = new THStack("hs_l2D2","");

  //TCanvas* cnvs_t0 = new TCanvas("cnvs_t0", "c1", 1,1,800,700);
  THStack *hs_t0 = new THStack("hs_t0","");
  //TCanvas* cnvs_sx = new TCanvas("cnvs_sx", "c1", 1,1,800,700);
  THStack *hs_sx = new THStack("hs_sx","");
  THStack *hs_sx2Dc = new THStack("hs_sx2Dc","");
  THStack *hs_sx2D1 = new THStack("hs_sx2D1","");
  THStack *hs_sx2D2 = new THStack("hs_sx2D2","");


  //TCanvas* cnvs_ex = new TCanvas("cnvs_ex", "c1", 1,1,800,700);
  THStack *hs_ex = new THStack("hs_ex","");
  THStack *hs_ex2Dc = new THStack("hs_ex2Dc","");
  THStack *hs_ex2D1 = new THStack("hs_ex2D1","");
  THStack *hs_ex2D2 = new THStack("hs_ex2D2","");
 
  //TCanvas* cnvs_sy = new TCanvas("cnvs_sy", "c1", 1,1,800,700);
  THStack *hs_sy = new THStack("hs_sy","");
  THStack *hs_sy2Dc = new THStack("hs_sy2Dc","");
  THStack *hs_sy2D1 = new THStack("hs_sy2D1","");
  THStack *hs_sy2D2 = new THStack("hs_sy2D2","");

  //TCanvas* cnvs_ey = new TCanvas("cnvs_ey", "c1", 1,1,800,700);
  THStack *hs_ey = new THStack("hs_ey","");
  THStack *hs_ey2Dc = new THStack("hs_ey2Dc","");
  THStack *hs_ey2D1 = new THStack("hs_ey2D1","");
  THStack *hs_ey2D2 = new THStack("hs_ey2D2","");


  //TCanvas* cnvs_sz = new TCanvas("cnvs_sz", "c1", 1,1,800,700);
  THStack *hs_sz = new THStack("hs_sz","");
  THStack *hs_sz2Dc = new THStack("hs_sz2Dc","");
  THStack *hs_sz2D1 = new THStack("hs_sz2D1","");
  THStack *hs_sz2D2 = new THStack("hs_sz2D2","");


  //TCanvas* cnvs_ez = new TCanvas("cnvs_ez", "c1", 1,1,800,700);
  THStack *hs_ez = new THStack("hs_ez","");
  THStack *hs_ez2Dc = new THStack("hs_ez2Dc","");
  THStack *hs_ez2D1 = new THStack("hs_ez2D1","");
  THStack *hs_ez2D2 = new THStack("hs_ez2D2","");



  //TCanvas* cnvs_r0 = new TCanvas("cnvs_r0", "c1", 1,1,800,700);
  THStack *hs_r0 = new THStack("hs_r0","");
  //TCanvas* cnvs_r1 = new TCanvas("cnvs_r1", "c1", 1,1,800,700);
  THStack *hs_r1 = new THStack("hs_r1","");
  //TCanvas* cnvs_r2 = new TCanvas("cnvs_r2", "c1", 1,1,800,700);
  THStack *hs_r2 = new THStack("hs_r2","");
  //TCanvas* cnvs_q0 = new TCanvas("cnvs_q0", "c1", 1,1,800,700);
  THStack *hs_q0 = new THStack("hs_q0","");
  //TCanvas* cnvs_q1 = new TCanvas("cnvs_q1", "c1", 1,1,800,700);
  THStack *hs_q1 = new THStack("hs_q1","");
  //TCanvas* cnvs_q2 = new TCanvas("cnvs_q2", "c1", 1,1,800,700);
  THStack *hs_q2 = new THStack("hs_q2","");

  THStack *hs_ci0 = new THStack("hs_ci0","");
  THStack *hs_ci1 = new THStack("hs_ci1","");
  THStack *hs_ci2 = new THStack("hs_ci2","");
  THStack *hs_ci02D = new THStack("hs_ci02D","");
  THStack *hs_ci12D = new THStack("hs_ci12D","");
  THStack *hs_ci22D = new THStack("hs_ci22D","");



  THStack *hs_wi0 = new THStack("hs_wi0","");
  THStack *hs_wi1 = new THStack("hs_wi1","");
  THStack *hs_wi2 = new THStack("hs_wi2","");

  THStack *hs_w0 = new THStack("hs_w0","");
  THStack *hs_w1 = new THStack("hs_w1","");
  THStack *hs_w2 = new THStack("hs_w2","");

  THStack *hs_ti0 = new THStack("hs_ti0","");
  THStack *hs_ti1 = new THStack("hs_ti1","");
  THStack *hs_ti2 = new THStack("hs_ti2","");

  THStack *hs_x0 = new THStack("hs_x0","");
  THStack *hs_x1 = new THStack("hs_x1","");
  THStack *hs_x2 = new THStack("hs_x2","");
  THStack *hs_x02D = new THStack("hs_x02D","");
  THStack *hs_x12D = new THStack("hs_x12D","");
  THStack *hs_x22D = new THStack("hs_x22D","");





  THStack *hs_y0 = new THStack("hs_y0","");
  THStack *hs_y1 = new THStack("hs_y1","");
  THStack *hs_y2 = new THStack("hs_y2","");
  THStack *hs_y02D = new THStack("hs_y02D","");
  THStack *hs_y12D = new THStack("hs_y12D","");
  THStack *hs_y22D = new THStack("hs_y22D","");

  THStack *hs_z0 = new THStack("hs_z0","");
  THStack *hs_z1 = new THStack("hs_z1","");
  THStack *hs_z2 = new THStack("hs_z2","");
  THStack *hs_z02D = new THStack("hs_z02D","");
  THStack *hs_z12D = new THStack("hs_z12D","");
  THStack *hs_z22D = new THStack("hs_z22D","");





  THStack *hs_p0 = new THStack("hs_p0","");
  THStack *hs_p1 = new THStack("hs_p1","");
  THStack *hs_p2 = new THStack("hs_p2","");


  cout<<"TStack"<<endl;

  // Create a histograms for the values we read.
  TH1F *h_azangle2_mc   = new TH1F("h_azangle2_mc","Relative Frequency vs  Azimuthal Angle: West Cryostat", 100., 0., 1.6);
  TH1F *h_azangle2_data = new TH1F("h_azangle2_data","Relative Frequency vs Azimuthal Angle: West Cryostat", 100., 0., 1.6);
  h_azangle2_mc->GetXaxis()->SetTitle(" Azimuthal Angle in radians ");
  h_azangle2_mc->GetYaxis()->SetTitle("Relative Frequency");
 
  TH1F *h_zangle2_mc   = new TH1F("h_zangle2_mc","Relative Frequency vs  Zenith Angle: West Cryostat", 100., 0., 1.6);
  TH1F *h_zangle2_data = new TH1F("h_zangle2_data","Relative Frequency vs Zenith Angle: West Cryostat", 100., 0., 1.6);
  h_zangle2_mc->GetXaxis()->SetTitle(" Zenith Angle in radians ");
  h_zangle2_mc->GetYaxis()->SetTitle("Relative Frequency");
 

  TH1F *h_azangle1_mc   = new TH1F("h_azangle1_mc","Relative Frequency vs  Azimuthal Angle: West Cryostat", 100., 0., 1.6);
  TH1F *h_azangle1_data = new TH1F("h_azangle1_data","Relative Frequency vs Azimuthal Angle: West Cryostat", 100., 0., 1.6);
  h_azangle1_mc->GetXaxis()->SetTitle(" Azimuthal Angle in radians ");
  h_azangle1_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_zangle1_mc   = new TH1F("h_zangle1_mc","Relative Frequency vs  Zenith Angle: West Cryostat", 100., 0., 1.6);
  TH1F *h_zangle1_data = new TH1F("h_zangle1_data","Relative Frequency vs Zenith Angle: West Cryostat", 100., 0., 1.6);
  h_zangle1_mc->GetXaxis()->SetTitle(" Zenith Angle in radians ");
  h_zangle1_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_azangle0_mc   = new TH1F("h_azangle0_mc","Relative Frequency vs  Azimuthal Angle: West Cryostat", 100., 0., 1.6);
  TH1F *h_azangle0_data = new TH1F("h_azangle0_data","Relative Frequency vs Azimuthal Angle: West Cryostat", 100., 0., 1.6);
  h_azangle0_mc->GetXaxis()->SetTitle(" Azimuthal Angle in radians ");
  h_azangle0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_zangle0_mc   = new TH1F("h_zangle0_mc","Relative Frequency vs  Zenith Angle: West Cryostat", 100., 0., 1.6);
  TH1F *h_zangle0_data = new TH1F("h_zangle0_data","Relative Frequency vs Zenith Angle: West Cryostat", 100., 0., 1.6);
  h_zangle0_mc->GetXaxis()->SetTitle(" Zenith Angle in radians ");
  h_zangle0_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_l_mc   = new TH1F("h_l_mc","Relative Frequency vs  Length: West Cryostat", 100., 0., 1500.);
  TH1F *h_l_data = new TH1F("h_l_data","Relative Frequency vs Length: West Cryostat", 100., 0., 1500.);
  h_l_mc->GetXaxis()->SetTitle("Muon Length in cm ");
  h_l_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH2F *h_l2Dc_mc   = new TH2F("h_l2Dc_mc","Azimuthal Angle vs  Length: West Cryostat", 50., 0., 1.6, 50., 0., 1500.);
  TH2F *h_l2Dc_data = new TH2F("h_l2Dc_data","Azimuthal Angle vs Length: West Cryostat", 50., 0., 1.6, 50., 0., 1500.);
  h_l2Dc_mc->GetYaxis()->SetTitle("Muon Length in cm ");
  h_l2Dc_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");

  TH2F *h_l2D1_mc   = new TH2F("h_l2D1_mc","Azimuthal Angle vs  Length: West Cryostat", 50., 0., 1.6, 50., 0., 1500.);
  TH2F *h_l2D1_data = new TH2F("h_l2D1_data","Azimuthal Angle vs Length: West Cryostat", 50., 0., 1.6, 50., 0., 1500.);
  h_l2D1_mc->GetYaxis()->SetTitle("Muon Length in cm ");
  h_l2D1_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");


  TH2F *h_l2D2_mc   = new TH2F("h_l2D2_mc","Azimuthal Angle vs  Length: West Cryostat", 50., 0., 1.6, 50., 0., 1500.);
  TH2F *h_l2D2_data = new TH2F("h_l2D2_data","Azimuthal Angle vs Length: West Cryostat", 50., 0., 1.6, 50., 0., 1500.);
  h_l2D2_mc->GetYaxis()->SetTitle("Muon Length in cm ");
  h_l2D2_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");


  TH1F *h_t0_mc   = new TH1F("h_t0_mc","Relative Frequency vs  T0: West Cryostat", 100., -100000., 100000.);
  TH1F *h_t0_data = new TH1F("h_t0_data","Relative Frequency vs T0: West Cryostat", 100., -100000., 100000.);
  h_t0_mc->GetXaxis()->SetTitle(" T0 in us ");
  h_t0_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_sx_mc   = new TH1F("h_sx_mc","Relative Frequency vs  Start (X): West Cryostat", 100., -100., -20.);//-100000., 100000.);
  TH1F *h_sx_data = new TH1F("h_sx_data","Relative Frequency vs Start (X): West Cryostat", 100., -100., -20.);//100., -100000., 100000.);
  h_sx_mc->GetXaxis()->SetTitle("Start (X) in cm ");
  h_sx_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH2F *h_sx2Dc_mc   = new TH2F("h_sx2Dc_mc","Azimuthal Angle vs  Start (X): West Cryostat", 100., 0., 1.6, 100., -100., -20.);
  TH2F *h_sx2Dc_data = new TH2F("h_sx2Dc_data","Azimuthal Angle vs Start (X): West Cryostat", 100., 0., 1.6, 100., -100., -20.);
  h_sx2Dc_mc->GetYaxis()->SetTitle("Start (X) in cm ");
  h_sx2Dc_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");


  TH2F *h_sx2D1_mc   = new TH2F("h_sx2D1_mc","Azimuthal Angle vs  Start (X): West Cryostat", 100., 0., 1.6, 100., -100., -20.);
  TH2F *h_sx2D1_data = new TH2F("h_sx2D1_data","Azimuthal Angle vs Start (X): West Cryostat", 100., 0., 1.6, 100., -100., -20.);
  h_sx2D1_mc->GetYaxis()->SetTitle("Start (X) in cm ");
  h_sx2D1_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");

  TH2F *h_sx2D2_mc   = new TH2F("h_sx2D2_mc","Azimuthal Angle vs  Start (X): West Cryostat", 50., 0., 1.6, 100., -100., -20.);
  TH2F *h_sx2D2_data = new TH2F("h_sx2D2_data","Azimuthal Angle vs Start (X): West Cryostat", 50., 0., 1.6, 100., -100., -20.);
  h_sx2D2_mc->GetYaxis()->SetTitle("Start (X) in cm ");
  h_sx2D2_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");




  TH1F *h_ex_mc   = new TH1F("h_ex_mc","Relative Frequency vs  End (X): West Cryostat", 100.,  -100., 100.);//-100000., 100000.);
  TH1F *h_ex_data = new TH1F("h_ex_data","Relative Frequency vs End (X): West Cryostat",  100., -100., 100.);//-100000., 100000.);
  h_ex_mc->GetXaxis()->SetTitle(" End (X) in cm ");
  h_ex_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH2F *h_ex2Dc_mc   = new TH2F("h_ex2Dc_mc","Azimuthal Angle vs  End (X): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  TH2F *h_ex2Dc_data = new TH2F("h_ex2Dc_data","Azimuthal Angle vs End (X): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  h_ex2Dc_mc->GetYaxis()->SetTitle("End (X) in cm ");
  h_ex2Dc_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");


  TH2F *h_ex2D1_mc   = new TH2F("h_ex2D1_mc","Azimuthal Angle vs  End (X): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  TH2F *h_ex2D1_data = new TH2F("h_ex2D1_data","Azimuthal Angle vs End (X): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  h_ex2D1_mc->GetYaxis()->SetTitle("End (X) in cm ");
  h_ex2D1_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");

  TH2F *h_ex2D2_mc   = new TH2F("h_ex2D2_mc","Azimuthal Angle vs  End (X): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  TH2F *h_ex2D2_data = new TH2F("h_ex2D2_data","Azimuthal Angle vs End (X): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  h_ex2D2_mc->GetYaxis()->SetTitle("End (X) in cm ");
  h_ex2D2_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");








  TH1F *h_sy_mc   = new TH1F("h_sy_mc","Relative Frequency vs  Start (Y): West Cryostat", 100.,  -100., 100.);//-100000., 100000.);
  TH1F *h_sy_data = new TH1F("h_sy_data","Relative Frequency vs Start (Y): West Cryostat",  100., -100., 100.);//-100000., 100000.);
  h_sy_mc->GetXaxis()->SetTitle("Start (Y) in cm ");
  h_sy_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH2F *h_sy2Dc_mc   = new TH2F("h_sy2Dc_mc","Azimuthal Angle vs  Start (Y): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  TH2F *h_sy2Dc_data = new TH2F("h_sy2Dc_data","Azimuthal Angle vs Start (Y): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  h_sy2Dc_mc->GetYaxis()->SetTitle("Start (Y) in cm ");
  h_sy2Dc_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");

  TH2F *h_sy2D1_mc   = new TH2F("h_sy2D1_mc","Azimuthal Angle vs  Start (Y): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  TH2F *h_sy2D1_data = new TH2F("h_sy2D1_data","Azimuthal Angle vs Start (Y): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  h_sy2D1_mc->GetYaxis()->SetTitle("Start (Y) in cm ");
  h_sy2D1_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");


  TH2F *h_sy2D2_mc   = new TH2F("h_sy2D2_mc","Azimuthal Angle vs  Start (Y): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  TH2F *h_sy2D2_data = new TH2F("h_sy2D2_data","Azimuthal Angle vs Start (Y): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  h_sy2D2_mc->GetYaxis()->SetTitle("Start (Y) in cm ");
  h_sy2D2_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");









  TH1F *h_ey_mc   = new TH1F("h_ey_mc","Relative Frequency vs  End (Y): West Cryostat", 100.,  -100., 100.);//-100000., 100000.);
  TH1F *h_ey_data = new TH1F("h_ey_data","Relative Frequency vs End (Y): West Cryostat",  100., -100., 100.);//-100000., 100000.);
  h_ey_mc->GetXaxis()->SetTitle(" End (Y) in cm ");
  h_ey_mc->GetYaxis()->SetTitle("Relative Frequency");



  TH2F *h_ey2Dc_mc   = new TH2F("h_ey2Dc_mc","Azimuthal Angle vs  End (Y): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  TH2F *h_ey2Dc_data = new TH2F("h_ey2Dc_data","Azimuthal Angle vs End (Y): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  h_ey2Dc_mc->GetYaxis()->SetTitle("End (Y) in cm ");
  h_ey2Dc_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");


  TH2F *h_ey2D1_mc   = new TH2F("h_ey2D1_mc","Azimuthal Angle vs  End (Y): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  TH2F *h_ey2D1_data = new TH2F("h_ey2D1_data","Azimuthal Angle vs End (Y): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  h_ey2D1_mc->GetYaxis()->SetTitle("End (Y) in cm ");
  h_ey2D1_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");


  TH2F *h_ey2D2_mc   = new TH2F("h_ey2D2_mc","Azimuthal Angle vs  End (Y): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  TH2F *h_ey2D2_data = new TH2F("h_ey2D2_data","Azimuthal Angle vs End (Y): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  h_ey2D2_mc->GetYaxis()->SetTitle("End (Y) in cm ");
  h_ey2D2_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");











  TH1F *h_sz_mc   = new TH1F("h_sz_mc","Relative Frequency vs  Start (Z): West Cryostat", 100., -100., 100.);//-100000., 100000.);
  TH1F *h_sz_data = new TH1F("h_sz_data","Relative Frequency vs Start (Z): West Cryostat",  100., -100., 100.);//-100000., 100000.);
  h_sz_mc->GetXaxis()->SetTitle("Start (Z) in cm ");
  h_sz_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH2F *h_sz2Dc_mc   = new TH2F("h_sz2Dc_mc","Azimuthal Angle vs  Start (Z): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  TH2F *h_sz2Dc_data = new TH2F("h_sz2Dc_data","Azimuthal Angle vs Start (Z): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  h_sz2Dc_mc->GetYaxis()->SetTitle("Start (Z) in cm ");
  h_sz2Dc_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");



  TH2F *h_sz2D1_mc   = new TH2F("h_sz2D1_mc","Azimuthal Angle vs  Start (Z): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  TH2F *h_sz2D1_data = new TH2F("h_sz2D1_data","Azimuthal Angle vs Start (Z): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  h_sz2D1_mc->GetYaxis()->SetTitle("Start (Z) in cm ");
  h_sz2D1_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");


  TH2F *h_sz2D2_mc   = new TH2F("h_sz2D2_mc","Azimuthal Angle vs  Start (Z): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  TH2F *h_sz2D2_data = new TH2F("h_sz2D2_data","Azimuthal Angle vs Start (Z): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  h_sz2D2_mc->GetYaxis()->SetTitle("Start (Z) in cm ");
  h_sz2D2_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");














  TH1F *h_ez_mc   = new TH1F("h_ez_mc","Relative Frequency vs  End (Z): West Cryostat", 100.,  -100., 100.);//-100000., 100000.);
  TH1F *h_ez_data = new TH1F("h_ez_data","Relative Frequency vs End (Z): West Cryostat",  100., -100., 100.);//-100000., 100000.);
  h_ez_mc->GetXaxis()->SetTitle(" End (Z) in cm ");
  h_ez_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH2F *h_ez2Dc_mc   = new TH2F("h_ez2Dc_mc","Azimuthal Angle vs  End (Z): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  TH2F *h_ez2Dc_data = new TH2F("h_ez2Dc_data","Azimuthal Angle vs End (Z): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  h_ez2Dc_mc->GetYaxis()->SetTitle("End (Z) in cm ");
  h_ez2Dc_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");

  TH2F *h_ez2D1_mc   = new TH2F("h_ez2D1_mc","Azimuthal Angle vs  End (Z): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  TH2F *h_ez2D1_data = new TH2F("h_ez2D1_data","Azimuthal Angle vs End (Z): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  h_ez2D1_mc->GetYaxis()->SetTitle("End (Z) in cm ");
  h_ez2D1_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");

  TH2F *h_ez2D2_mc   = new TH2F("h_ez2D2_mc","Azimuthal Angle vs  End (Z): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  TH2F *h_ez2D2_data = new TH2F("h_ez2D2_data","Azimuthal Angle vs End (Z): West Cryostat", 100., 0., 1.6, 100., -100., 100.);
  h_ez2D2_mc->GetYaxis()->SetTitle("End (Z) in cm ");
  h_ez2D2_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");












  TH1F *h_q0_mc   = new TH1F("h_q0_mc","Relative Frequency vs  dQ/dx: West Cryostat", 100., 0., 2000.);
  TH1F *h_q0_data = new TH1F("h_q0_data","Relative Frequency vs dQ/dx: West Cryostat", 100., 0., 2000.);
  h_q0_mc->GetXaxis()->SetTitle(" dQ/dx ");
  h_q0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_q1_mc   = new TH1F("h_q1_mc","Relative Frequency vs  dQ/dx: West Cryostat", 100., 0., 2000.);//-100000., 100000.);
  TH1F *h_q1_data = new TH1F("h_q1_data","Relative Frequency vs dQ/dx: West Cryostat", 100., 0., 2000.);//-100000., 100000.);
  h_q1_mc->GetXaxis()->SetTitle(" dQ/dx ");
  h_q1_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_q2_mc   = new TH1F("h_q2_mc","Relative Frequency vs  dQ/dx: West Cryostat", 100., 0., 2000.);//-100000., 100000.);
  TH1F *h_q2_data = new TH1F("h_q2_data","Relative Frequency vs dQ/dx: West Cryostat", 100., 0., 2000.);//-100000., 100000.);
  h_q2_mc->GetXaxis()->SetTitle(" dQ/dx ");
  h_q2_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_r0_mc   = new TH1F("h_r0_mc","Relative Frequency vs  Residual Range: West Cryostat", 100., 0., 150.);//-100000., 100000.);
  TH1F *h_r0_data = new TH1F("h_r0_data","Relative Frequency vs Residual Range: West Cryostat", 100., 0., 150.);// -100000., 100000.);
  h_r0_mc->GetXaxis()->SetTitle(" Residual Range in cm ");
  h_r0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_r1_mc   = new TH1F("h_r1_mc","Relative Frequency vs  Residual Range: West Cryostat", 100., 0., 150.);//100-100000., 100000.);
  TH1F *h_r1_data = new TH1F("h_r1_data","Relative Frequency vs Residual Range: West Cryostat", 100., 0., 150.);//-100000., 100000.);
  h_r1_mc->GetXaxis()->SetTitle(" Residual Range in cm ");
  h_r1_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_r2_mc   = new TH1F("h_r2_mc","Relative Frequency vs  Residual Range: West Cryostat", 100., 0., 150.);//-100000., 100000.);
  TH1F *h_r2_data = new TH1F("h_r2_data","Relative Frequency vs Residual Range: West Cryostat", 100., 0., 150.);//-100000., 100000.);
  h_r2_mc->GetXaxis()->SetTitle(" Residual Range in cm ");
  h_r2_mc->GetYaxis()->SetTitle("Relative Frequency");




  TH1F *h_ci0_mc   = new TH1F("h_ci0_mc","Relative Frequency vs  Charge Integral: West Cryostat", 100., 0., 2000.);//-100000., 100000.);
  TH1F *h_ci0_data = new TH1F("h_ci0_data","Relative Frequency vs Charge Integral: West Cryostat", 100., 0., 2000.);//-100000., 100000.);
  h_ci0_mc->GetXaxis()->SetTitle(" Charge Integral in ADC ");
  h_ci0_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH2F *h_ci02D_mc   = new TH2F("h_ci02D_mc","Azimuthal Angle vs  Charge Integral in ADC: West Cryostat", 50., 0., 1.6, 50., 0., 2000.);
  TH2F *h_ci02D_data = new TH2F("h_ci02D_data","Azimuthal Angle vs Charge Integral in ADC: West Cryostat", 50., 0., 1.6, 50., 0., 2000.);
  h_ci02D_mc->GetYaxis()->SetTitle("Charge Integral in ADC ");
  h_ci02D_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");



  TH1F *h_ci1_mc   = new TH1F("h_ci1_mc","Relative Frequency vs  Charge Integral: West Cryostat", 100., 0., 2000.);//-100000., 100000.);
  TH1F *h_ci1_data = new TH1F("h_ci1_data","Relative Frequency vs Charge Integral: West Cryostat", 100., 0., 2000.);//-100000., 100000.);
  h_ci1_mc->GetXaxis()->SetTitle(" Charge Integral in ADC ");
  h_ci1_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH2F *h_ci12D_mc   = new TH2F("h_ci12D_mc","Azimuthal Angle vs  Charge Integral in ADC: West Cryostat", 50., 0., 1.6, 50., 0., 2000.);
  TH2F *h_ci12D_data = new TH2F("h_ci12D_data","Azimuthal Angle vs Charge Integral in ADC: West Cryostat", 50., 0., 1.6, 50., 0., 2000.);
  h_ci12D_mc->GetYaxis()->SetTitle("Charge Integral in ADC ");
  h_ci12D_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");


  TH1F *h_ci2_mc   = new TH1F("h_ci2_mc","Relative Frequency vs  Charge Integral: West Cryostat", 100., 0., 2000.);//-100000., 100000.);
  TH1F *h_ci2_data = new TH1F("h_ci2_data","Relative Frequency vs Charge Integral: West Cryostat", 100., 0., 2000.);//-100000., 100000.);
  h_ci2_mc->GetXaxis()->SetTitle(" Charge Integral in ADC ");
  h_ci2_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH2F *h_ci22D_mc   = new TH2F("h_ci22D_mc","Azimuthal Angle vs  Charge Integral in ADC: West Cryostat", 50., 0., 1.6, 50., 0., 2000.);
  TH2F *h_ci22D_data = new TH2F("h_ci22D_data","Azimuthal Angle vs Charge Integral in ADC: West Cryostat", 50., 0., 1.6, 50., 0., 2000.);
  h_ci22D_mc->GetYaxis()->SetTitle("Charge Integral in ADC ");
  h_ci22D_mc->GetXaxis()->SetTitle("Azimuthal angle in radians");




  TH1F *h_wi0_mc   = new TH1F("h_wi0_mc","Relative Frequency vs  Width: West Cryostat", 100., 0., 20.);//-100000., 100000.);
  TH1F *h_wi0_data = new TH1F("h_wi0_data","Relative Frequency vs Width: West Cryostat", 100., 0., 20.);//-100000., 100000.);
  h_wi0_mc->GetXaxis()->SetTitle(" Width in ticks");
  h_wi0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_wi1_mc   = new TH1F("h_wi1_mc","Relative Frequency vs  Width: West Cryostat", 100., 0., 20.);//-100000., 100000.);
  TH1F *h_wi1_data = new TH1F("h_wi1_data","Relative Frequency vs Width: West Cryostat", 100., 0., 20.);//-100000., 100000.);
  h_wi1_mc->GetXaxis()->SetTitle(" Width in ticks");
  h_wi1_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_wi2_mc   = new TH1F("h_wi2_mc","Relative Frequency vs  Width: West Cryostat", 100., 0., 20.);// -100000., 100000.);
  TH1F *h_wi2_data = new TH1F("h_wi2_data","Relative Frequency vs Width: West Cryostat", 100., 0., 20.);// -100000., 100000.);
  h_wi2_mc->GetXaxis()->SetTitle(" Width in ticks");
  h_wi2_mc->GetYaxis()->SetTitle("Relative Frequency");




  TH1F *h_w0_mc   = new TH1F("h_w0_mc","Relative Frequency vs  Wire: West Cryostat", 100., 0., 100.);//-100., 100.);
  TH1F *h_w0_data = new TH1F("h_w0_data","Relative Frequency vs Wire: West Cryostat", 100., 0., 100.);//-100., 100.);
  h_w0_mc->GetXaxis()->SetTitle(" Wire Number");
  h_w0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_w1_mc   = new TH1F("h_w1_mc","Relative Frequency vs  Wire: West Cryostat", 100.,0., 100.);// -100000., 100000.);
  TH1F *h_w1_data = new TH1F("h_w1_data","Relative Frequency vs Wire: West Cryostat", 100.,0., 100.);// -100000., 100000.);
  h_w1_mc->GetXaxis()->SetTitle(" Wire Number");
  h_w1_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_w2_mc   = new TH1F("h_w2_mc","Relative Frequency vs  Wire: West Cryostat", 100., 0., 100.);//-100000., 100000.);
  TH1F *h_w2_data = new TH1F("h_w2_data","Relative Frequency vs Wire: West Cryostat", 100., 0., 100.);//-100000., 100000.);
  h_w2_mc->GetXaxis()->SetTitle(" Wire Number");
  h_w2_mc->GetYaxis()->SetTitle("Relative Frequency");



  TH1F *h_ti0_mc   = new TH1F("h_ti0_mc","Relative Frequency vs  Time: West Cryostat", 100., 0., 20.); //-1000., 100.);
  TH1F *h_ti0_data = new TH1F("h_ti0_data","Relative Frequency vs Time: West Cryostat", 100., 0., 20.); //-100000., 100000.); //0., 100.);// -100000., 100000.);
  h_ti0_mc->GetXaxis()->SetTitle(" Time in ticks");
  h_ti0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_ti1_mc   = new TH1F("h_ti1_mc","Relative Frequency vs  Time: West Cryostat", 100., 0., 20.); //-100000., 100000.); //0., 100.);//-100000., 100000.);
  TH1F *h_ti1_data = new TH1F("h_ti1_data","Relative Frequency vs Time: West Cryostat", 100.,0., 20.); //-100000., 100000.); // 0., 100.);//-100000., 100000.);
  h_ti1_mc->GetXaxis()->SetTitle(" Time in ticks");
  h_ti1_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_ti2_mc   = new TH1F("h_ti2_mc","Relative Frequency vs  Time: West Cryostat", 100., 0., 20.); //-100000., 100000.); //0., 100.);//-100000., 100000.);
  TH1F *h_ti2_data = new TH1F("h_ti2_data","Relative Frequency vs Time: West Cryostat", 100., 0., 20.); //-100000., 100000.); //0., 100.);//-100000., 100000.);
  h_ti2_mc->GetXaxis()->SetTitle(" Time in ticks");
  h_ti2_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_x0_mc   = new TH1F("h_x0_mc","Relative Frequency vs  Direction (X): West Cryostat", 100., -5., 5.);// -100000., 100000.);
  TH1F *h_x0_data = new TH1F("h_x0_data","Relative Frequency vs Direction (X): West Cryostat", 100., -5., 5.);//-10., 10.);//-100000., 100000.);
  h_x0_mc->GetXaxis()->SetTitle(" Direction (X) in cm");
  h_x0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_x1_mc   = new TH1F("h_x1_mc","Relative Frequency vs  Direction (X): West Cryostat", 100., -5., 5.);//-10., 10.);//-100000., 100000.);
  TH1F *h_x1_data = new TH1F("h_x1_data","Relative Frequency vs Direction (X): West Cryostat", 100., -5., 5.);//-10., 10.);//-100000., 100000.);
  h_x1_mc->GetXaxis()->SetTitle(" Direction (X) in cm");
  h_x1_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_x2_mc   = new TH1F("h_x2_mc","Relative Frequency vs  Direction (X): West Cryostat", 100., -5., 5.);//-10., 10.);//-100000., 100000.);
  TH1F *h_x2_data = new TH1F("h_x2_data","Relative Frequency vs Direction (X): West Cryostat", 100., -5., 5.);//-10., 10.);//-100000., 100000.);
  h_x2_mc->GetXaxis()->SetTitle(" Direction (X) in cm");
  h_x2_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_y0_mc   = new TH1F("h_y0_mc","Relative Frequency vs  Direction (Y): West Cryostat", 100., -5., 5.);//-10., 10.);//-100000., 100000.);
  TH1F *h_y0_data = new TH1F("h_y0_data","Relative Frequency vs Direction (Y): West Cryostat", 100., -5., 5.);//-10., 10.);//-100000., 100000.);
  h_y0_mc->GetXaxis()->SetTitle(" Direction (Y) in cm");
  h_y0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_y1_mc   = new TH1F("h_y1_mc","Relative Frequency vs  Direction (Y): West Cryostat", 100., -5., 5.);//-10., 10.);//-100000., 100000.);
  TH1F *h_y1_data = new TH1F("h_y1_data","Relative Frequency vs Direction (Y): West Cryostat", 100., -5., 5.);//-10., 10.);//-100000., 100000.);
  h_y1_mc->GetXaxis()->SetTitle(" Direction (Y) in cm");
  h_y1_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_y2_mc   = new TH1F("h_y2_mc","Relative Frequency vs  Direction (Y): West Cryostat", 100., -5., 5.);//-10., 10.);//-100000., 100000.);
  TH1F *h_y2_data = new TH1F("h_y2_data","Relative Frequency vs Direction (Y): West Cryostat", 100., -5., 5.);//-10., 10.);//-100000., 100000.);
  h_y2_mc->GetXaxis()->SetTitle(" Direction (Y) in cm");
  h_y2_mc->GetYaxis()->SetTitle("Relative Frequency");



  TH1F *h_z0_mc   = new TH1F("h_z0_mc","Relative Frequency vs  Direction (Z): West Cryostat", 100., -5., 5.);//-10., 10.);//-100000., 100000.);
  TH1F *h_z0_data = new TH1F("h_z0_data","Relative Frequency vs Direction (Z): West Cryostat", 100., -5., 5.);//-10., 10.);//-100000., 100000.);
  h_z0_mc->GetXaxis()->SetTitle(" Direction (Z) in cm");
  h_z0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_z1_mc   = new TH1F("h_z1_mc","Relative Frequency vs  Direction (Z): West Cryostat", 100., -5., 5.);//-10., 10.);//-100000., 100000.);
  TH1F *h_z1_data = new TH1F("h_z1_data","Relative Frequency vs Direction (Z): West Cryostat", 100., -5., 5.);//-10., 10.);//-100000., 100000.);
  h_z1_mc->GetXaxis()->SetTitle(" Direction (Z) in cm");
  h_z1_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_z2_mc   = new TH1F("h_z2_mc","Relative Frequency vs  Direction (Z): West Cryostat", 100., -5., 5.);//-10., 10.);//-100000., 100000.);
  TH1F *h_z2_data = new TH1F("h_z2_data","Relative Frequency vs Direction (Z): West Cryostat", 100., -5., 5.);//-10., 10.);//-100000., 100000.);
  h_z2_mc->GetXaxis()->SetTitle(" Direction (Z) in cm");
  h_z2_mc->GetYaxis()->SetTitle("Relative Frequency");



  TH1F *h_p0_mc   = new TH1F("h_p0_mc","Relative Frequency vs  Pitch: West Cryostat", 100., 0., 25.);
  TH1F *h_p0_data = new TH1F("h_p0_data","Relative Frequency vs Pitch: West Cryostat", 100., 0., 25.);
  h_p0_mc->GetXaxis()->SetTitle(" Pitch in cm");
  h_p0_mc->GetYaxis()->SetTitle("Relative Frequency");

  TH1F *h_p1_mc   = new TH1F("h_p1_mc","Relative Frequency vs  Pitch: West Cryostat", 100., 0., 25.);
  TH1F *h_p1_data = new TH1F("h_p1_data","Relative Frequency vs Pitch: West Cryostat", 100., 0., 25.);
  h_p1_mc->GetXaxis()->SetTitle(" Pitch in cm");
  h_p1_mc->GetYaxis()->SetTitle("Relative Frequency");


  TH1F *h_p2_mc   = new TH1F("h_p2_mc","Relative Frequency vs Pitch: West Cryostat", 100., 0., 25.);
  TH1F *h_p2_data = new TH1F("h_p2_data","Relative Frequency vs Pitch: West Cryostat", 100., 0., 25.);
  h_p2_mc->GetXaxis()->SetTitle(" Pitch in cm");
  h_p2_mc->GetYaxis()->SetTitle("Relative Frequency");





  cout<<"histos"<<endl;
  //create other histograms here!

  //delcare variables
   cout<<"vars declared"<<endl;


for(int n1 = 0; n1 < MC_L0; n1++){

     h_l2Dc_mc->Fill(Az_MC0[n1] , Length_MC0[n1]);
     h_ci22D_mc->Fill(Az_MC0[n1] , Cint_MC0[n1]);



 }




for(int n2 = 0; n2 < DATA_L0; n2++){
     h_l2Dc_data->Fill(Az_DATA0[n2]  , Length_DATA0[n2]);
     h_ci22D_data->Fill(Az_DATA0[n2] , Cint_DATA0[n2]);


 }









   cout<<"data done"<<endl;
   

   //normalizing MC distribution


   TH2*h1l2Dc = (TH2*)(h_l2Dc_mc->Clone("h1l2Dc"));
   h1l2Dc->Scale(1./h1l2Dc->Integral());


   TH2*h1AA2D = (TH2*)(h_ci22D_mc->Clone("h1AA2D"));
   h1AA2D->Scale(1./h1AA2D->Integral());


   TH2*h2l2Dc = (TH2*)(h_l2Dc_data->Clone("h2l2Dc"));
   h2l2Dc->Scale(1./h2l2Dc->Integral());

   TH2*h2AA2D = (TH2*)(h_ci22D_data->Clone("h2AA2D"));
   h2AA2D->Scale(1./h2AA2D->Integral());





   cout<<"norm"<<endl;



   //   TFile* my_new_file = new TFile("my_output_file_AzimuthalAngle_col.root","RECREATE"); // open new file in write mode
   //hs_az2->Write();





   //drawing distribtions




   TCanvas* cnvs_l2Dc = new TCanvas("cnvs_l2Dc", "c122Dc", 1,1,800,700);
   auto h1l2Dc_prof = h1l2Dc->ProfileX();
   auto h2l2Dc_prof = h2l2Dc->ProfileX();


   h1l2Dc_prof->SetLineColor(kRed);
   h2l2Dc_prof->SetLineColor(kBlue);

   // h1l2D1_prof->SetLineColor(kViolet);
   //h2l2D1_prof->SetLineColor(kYellow);


   h1l2Dc_prof->SetMaximum(700);


   h1l2Dc_prof->Draw();
   h2l2Dc_prof->Draw("same");

   //h1l2D1_prof->Draw("same");
   //h2l2D1_prof->Draw("same");
   

   auto legendl2Dc = new TLegend(0.1,0.1,0.2,0.2);
   legendl2Dc->AddEntry(h1l2Dc_prof,"MC tpc 1");
   legendl2Dc->AddEntry(h2l2Dc_prof,"Data tpc 1");
   //legendl2Dc->AddEntry(h1l2D1_prof,"MC tpc 1");
   //legendl2Dc->AddEntry(h2l2D1_prof,"Data tpc 1");

   legendl2Dc->Draw();
   cnvs_l2Dc->Update();

   TFile output_file1("my_output_file_2D_my_outputNUMI_SEL12_West_tpc1_fileLength_Az_col.root","RECREATE");
   h1l2Dc_prof->Write();
   h2l2Dc_prof->Write();
   cnvs_l2Dc->Write();

   cnvs_l2Dc->SaveAs("2D_my_outputNUMI_SEL12_West_tpc1_fileLength_Az_col.pdf");





   TCanvas* cnvs_ci22D = new TCanvas("cnvs_ci22D", "c212D", 1,1,800,700);
   auto h1ci22D_prof = h1AA2D->ProfileX();
   auto h2ci22D_prof = h2AA2D->ProfileX();

   h1ci22D_prof->SetLineColor(kRed);
   h2ci22D_prof->SetLineColor(kBlue);
   //   h1ci12D_prof->SetLineColor(kViolet);
   //h2ci12D_prof->SetLineColor(kYellow); 


   h1ci22D_prof->SetMaximum(700);


   h1ci22D_prof->Draw();
   h2ci22D_prof->Draw("same");

   // h1ci12D_prof->Draw("same");
   //h2ci12D_prof->Draw("same");


   //   hs_ci22D->GetYaxis()->SetTitle(" Charge Integral in ADC  ");
   //hs_ci22D->GetXaxis()->SetTitle("Azimuthal Angle in radians");
   //TText TAA2D; TAA2D.SetTextFont(42); TAA2D.SetTextAlign(21);
   //TAA2D.DrawTextNDC(.5,.95,"Charge Integral vs Azimuthal Angle (col): West Cryostat");
   auto legendAA2D = new TLegend(0.1,0.1,0.2,0.2);
   legendAA2D->AddEntry(h1AA2D,"MC tpc 1");
   legendAA2D->AddEntry(h2AA2D,"Data tpc 1");
   //legendAA2D->AddEntry(h1BB2D,"MC tpc 1");
   //legendAA2D->AddEntry(h2BB2D,"Data tpc 1");

   legendAA2D->Draw();
   cnvs_ci22D->Update();


   TFile output_file22("my_output_file_2D_my_outputNUMI_SEL12_West_tpc1_fileCint_Az_col.root","RECREATE");
   h1ci22D_prof->Write();
   h2ci22D_prof->Write();
   cnvs_ci22D->Write();


   cnvs_ci22D->SaveAs("2D_my_outputNUMI_SEL12_West_tpc1_fileInt_az_col.pdf");



   cout<<"plots done"<<endl;

   cout<<"end of macro"<<endl;


}

