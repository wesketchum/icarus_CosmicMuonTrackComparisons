#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

void Nov2D(bool verbose=false) {


  gStyle->SetOptStat(0);

  ifstream infile1("hnoCOSangle_by_in1_E_tpc0.txt");
  ifstream infile2a("p60noCOSangle_by_col_E_tpc0.txt");
  ifstream infile2b("p60noCOSangle_by_in2_E_tpc0.txt");
  ifstream infile3a("m60noCOSangle_by_col_E_tpc0.txt");
  ifstream infile3b("m60noCOSangle_by_in2_E_tpc0.txt");
  ifstream infile4("OUTFILE_my_testTESToutputNUMI_tpc0_sel0_East_file_Qdx_in1.txt");
  ifstream infile5("OUTFILE_my_testTESToutputNUMI_tpc0_sel0_East_file_Qdx_col.txt");
  ifstream infile6("OUTFILE_my_testTESToutputNUMI_tpc0_sel0_East_file_Qdx_in2.txt");
  cout<<"HERE"<<endl;
  int E0 = 0;
  int W0 = 0;
  int E1 = 0;
  int W1 = 0;
  int E2 = 0;
  int W2 = 0;
  int E3 = 0;
  int W3 = 0;
  double Et0 = 0.0;
  double Wt0 = 0.0;
  double Et1 = 0.0;
  double Wt1 = 0.0;
  double Et2 = 0.0;
  double Wt2 = 0.0;
  double Et3 = 0.0;
  double Wt3 = 0.0;
  double h1[5000];
  double pc[5000];
  double p2[5000];
  double mc[5000];
  double m2[5000];
  double dqdx_c[5000];
  double dqdx_1[5000];
  double dqdx_2[5000];
  //  TCanvas* cnvs_az2 = new TCanvas("cnvs_az2", "c1", 1,1,800,700);   

  /*
  THStack *hs_z02D = new THStack("hs_z02D","");
  THStack *hs_z12D = new THStack("hs_z12D","");
  THStack *hs_z22D = new THStack("hs_z22D","");





  cout<<"TStack"<<endl;

  // Create a histograms for the values we read.


  TH2F *hz_ci02D_mc   = new TH2F("hz_ci02D_mc","Zenith Angle vs  Charge Integral in ADC: West Cryostat", 50., 0., 1.6, 50., 0., 2000.);
  TH2F *hz_ci02D_data = new TH2F("hz_ci02D_data","Zenith Angle vs Charge Integral in ADC: West Cryostat", 50., 0., 1.6, 50., 0., 2000.);
  hz_ci02D_mc->GetYaxis()->SetTitle("Charge Integral in ADC ");
  hz_ci02D_mc->GetXaxis()->SetTitle("Zenith angle in radians");


  */

  cout<<"histos"<<endl;


  while(infile1>>Et0){
    h1[E0] = Et0;
    E0++;
  }

  while(infile2a>>Wt0){
    pc[W0] = Wt0;
    W0++;
  }
  while(infile2b>>Et1){
    p2[E1] = Et1;
    E1++;
  }

  while(infile3a>>Wt1){
    mc[W1] = Wt1;
    W1++;
  }
  while(infile3b>>Et2){
    m2[E2] = Et2;
    E2++;
  }

  while(infile4>>Wt2){
    dqdx_c[W2] = Wt2;
    W2++;
  }

  while(infile5>>Et3){
    dqdx_1[E3] = Et3;
    E3++;
  }
  while(infile6>>Wt3){
    dqdx_2[W3] = Wt3;
    W3++;
  }

  cout<<E0<<" "<<W0<<" "<<E1<<" "<<W1<<" "<<E2<<" "<<W2<<" "<<E3<<" "<<W3<<" "<<endl;



  /*     h_l2Dc_mc->Fill(TMath::ATan(x_c[last_h_mc_c]/z_c[last_h_mc_c]) , *length);

   //normalizing MC distribution


   TH2*h1l2Dc = (TH2*)(h_l2Dc_mc->Clone("h1l2Dc"));
   h1l2Dc->Scale(1./h1l2Dc->Integral());

   cout<<"norm"<<endl;

   TCanvas* cnvs_az1 = new TCanvas("cnvs_az1", "c1", 1,1,800,700);
   h1a->SetLineColor(kRed);
   h2a->SetLineColor(kBlue);
   hs_az1->Add(h1a);
   hs_az1->Add(h2a);
   hs_az1->Draw("nostackHIST");
   cout<<"HERE2"<<endl;
   hs_az1->GetXaxis()->SetTitle(" Azimuthal Angle in radians ");
   hs_az1->GetYaxis()->SetTitle("Relative Frequency");
   TText Ta; Ta.SetTextFont(42); Ta.SetTextAlign(21);
   Ta.DrawTextNDC(.5,.95,"Relative Frequency vs Azimuthal Angle (in1): West Cryostat");
   auto legenda = new TLegend(0.1,0.8,0.2,0.9);
   legenda->AddEntry(h1a,"MC");
   legenda->AddEntry(h2a,"Data");
   legenda->Draw();
   cnvs_az1->Update();

   cnvs_az1->SaveAs("/icarus/data/users/obitter/CalibrationWS21/histos_for_analysis/my_TESToutputNUMI_tpc3_sel2_West_file_AzimuthalAngle_in1TEST.pdf");
   cout<<"plots done"<<endl;
  */
   cout<<"end of macro"<<endl;


}

   
