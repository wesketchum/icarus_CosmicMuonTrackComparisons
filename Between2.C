#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "sbnobj/Common/Calibration/TrackCaloSkimmerObj.h"


#include<stdio.h>
void Between2(){



  gStyle->SetOptStat(0);
  int n = 5000;

  double A  = 0.0;
  double B  = 0.0;
  double C  = 0.0;

  double D  = 0.0;
  double E  = 0.0;
  double F  = 0.0;

  double G  = 0.0;
  double H  = 0.0;
  double I  = 0.0;

  double J  = 0.0;
  double K  = 0.0;
  double L  = 0.0;


  double M  = 0.0;
  double N  = 0.0;
  double O  = 0.0;


  double P  = 0.0;
  double Q  = 0.0;
  double R  = 0.0;


  double X_SEL12_East_MC_col[n];
  double X_SEL12_East_MC_in1[n];
  double X_SEL12_East_MC_in2[n];

  double Y_SEL12_East_MC_col[n];
  double Y_SEL12_East_MC_in1[n];
  double Y_SEL12_East_MC_in2[n];

  double Z_SEL12_East_MC_col[n];
  double Z_SEL12_East_MC_in1[n];
  double Z_SEL12_East_MC_in2[n];



  double X_SEL12_West_MC_col[n];
  double X_SEL12_West_MC_in1[n];
  double X_SEL12_West_MC_in2[n];

  double Y_SEL12_West_MC_col[n];
  double Y_SEL12_West_MC_in1[n];
  double Y_SEL12_West_MC_in2[n];

  double Z_SEL12_West_MC_col[n];
  double Z_SEL12_West_MC_in1[n];
  double Z_SEL12_West_MC_in2[n];

  int aa = 0;
  int bb = 0;
  int cc = 0;

  int dd = 0;
  int ee = 0;
  int ff = 0;

  int gg = 0;
  int hh = 0;
  int ii = 0;

  int jj = 0;
  int kk = 0;
  int ll = 0;

  int mm = 0;
  int nn = 0;
  int oo = 0;

  int pp = 0;
  int qq = 0;
  int rr = 0;


  double angle_by_col_E[n];
  double angle_by_in2_E[n];
  double angle_by_col_W[n];
  double angle_by_in2_W[n];
  double angle_by_in1_E[n];
  double angle_by_in1_W[n];

  ifstream infile1("mcJUNE_NUMI_tpc3_sel12_East_file_xyz_col.txt");
  ifstream infile2("mcJUNE_NUMI_tpc3_sel12_East_file_xyz_in1.txt");
  ifstream infile3("mcJUNE_NUMI_tpc3_sel12_East_file_xyz_in2.txt");

  ifstream infile4("mcJUNE_NUMI_tpc3_sel12_West_file_xyz_col.txt");
  ifstream infile5("mcJUNE_NUMI_tpc3_sel12_West_file_xyz_in1.txt");
  ifstream infile6("mcJUNE_NUMI_tpc3_sel12_West_file_xyz_in2.txt");

  ofstream outfile1("noCOSangle_by_col_E_tpc3.txt");
  ofstream outfile2("noCOSangle_by_in1_E_tpc3.txt");
  ofstream outfile3("noCOSangle_by_in2_E_tpc3.txt");
  ofstream outfile4("noCOSangle_by_col_W_tpc3.txt");
  ofstream outfile5("noCOSangle_by_in1_W_tpc3.txt");
  ofstream outfile6("noCOSangle_by_in2_W_tpc3.txt");



  TH1F *h1p = new TH1F("h1p","TPC3 East Cryostat MC (COL) ", 100., 0.0, 2.0); //0., 7.0);                           
  h1p->GetXaxis()->SetTitle("angle wrt horizontal in radians");

  TH1F *h4p = new TH1F("h4p","TPC3 West Cryostat MC (COL) ", 100., 0.0, 2.0); //0., 7.0);                           
  h4p->GetXaxis()->SetTitle("angle wrt horizontal in radians");

  TH1F *h5p = new TH1F("h5p","TPC3 West Cryostat MC (IN1) ", 100., 0.0, 2.0); //0., 7.0);                           
  h5p->GetXaxis()->SetTitle("angle wrt horizontal in radians");

  TH1F *h6p = new TH1F("h6p","TPC3 West Cryostat MC (IN2) ", 100., 0.0, 2.0); //0., 7.0);                           
  h6p->GetXaxis()->SetTitle("angle wrt horizontal in radians");

  TH1F *h2p = new TH1F("h2p","TPC3 East Cryostat MC (IN1) ", 100., 0.0, 2.0); //0., 7.0);                                                                                         
  h2p->GetXaxis()->SetTitle("angle wrt horizontal in radians");

  TH1F *h3p = new TH1F("h3p","TPC3 East Cryostat MC (IN2) ", 100., 0.0, 2.0); //0., 7.0);                                                                                         
  h3p->GetXaxis()->SetTitle("angle wrt horizontal in radians");



  while(infile1>>A>>D>>G)
    {
      X_SEL12_East_MC_col[aa] =  A;
      Y_SEL12_East_MC_col[aa] =  D;
      Z_SEL12_East_MC_col[aa] =  G;
      cout<<X_SEL12_East_MC_col[aa]<<" "<<Y_SEL12_East_MC_col[aa]<<" "<<Z_SEL12_East_MC_col[aa]<<endl;
      aa++;
    }

  while(infile2>>B>>E>>H)
    {
      X_SEL12_East_MC_in1[bb] =  B;
      Y_SEL12_East_MC_in1[bb] =  E;
      Z_SEL12_East_MC_in1[bb] =  H;
      bb++;
    }

  while(infile3>>C>>F>>I)
    {
      X_SEL12_East_MC_in2[cc] =  C;
      Y_SEL12_East_MC_in2[cc] =  F;
      Z_SEL12_East_MC_in2[cc] =  I;
      cc++;
    }

  while(infile4>>J>>M>>P)
    {
      X_SEL12_West_MC_col[dd] =  J;
      Y_SEL12_West_MC_col[dd] =  M;
      Z_SEL12_West_MC_col[dd] =  P;
      dd++;
    }

  while(infile5>>K>>N>>Q)
    {
      X_SEL12_West_MC_in1[ee] =  K;
      Y_SEL12_West_MC_in1[ee] =  N;
      Z_SEL12_West_MC_in1[ee] =  Q;
      ee++;
    }

  while(infile6>>L>>O>>R)
    {
      X_SEL12_West_MC_in2[ff] =  L;
      Y_SEL12_West_MC_in2[ff] =  O;
      Z_SEL12_West_MC_in2[ff] =  R;
      ff++;
    }

  for(int alpha = 0; alpha<aa; alpha++){

    angle_by_col_E[alpha] = TMath::ACos( (Z_SEL12_East_MC_col[alpha]*1.0) / ( sqrt(X_SEL12_East_MC_col[alpha]*X_SEL12_East_MC_col[alpha]+ Y_SEL12_East_MC_col[alpha]*Y_SEL12_East_MC_col[alpha]+Z_SEL12_East_MC_col[alpha]*Z_SEL12_East_MC_col[alpha]) * sqrt( 1.0*1.0 ) ) );
    outfile1<<angle_by_col_E[alpha]<<endl;
    h1p->Fill(angle_by_col_E[alpha]);
  }

  for(int beta = 0; beta<bb; beta++){
    angle_by_in1_E[beta] = TMath::ACos( (Z_SEL12_East_MC_in1[beta]*1.0) / ( sqrt(X_SEL12_East_MC_in1[beta]*X_SEL12_East_MC_in1[beta]+Y_SEL12_East_MC_in1[beta]*Y_SEL12_East_MC_in1[beta]+Z_SEL12_East_MC_in1[beta]*Z_SEL12_East_MC_in1[beta]) * sqrt( 1.0*1.0 ) ) );
    outfile2<<angle_by_in1_E[beta]<<endl;
    h2p->Fill(angle_by_in1_E[beta]);
  }

    for(int gamma = 0; gamma<cc; gamma++){
    angle_by_in2_E[gamma] = TMath::ACos( (Z_SEL12_East_MC_in2[gamma]*1.0) / ( sqrt(X_SEL12_East_MC_in2[gamma]*X_SEL12_East_MC_in2[gamma]+Y_SEL12_East_MC_in2[gamma]*Y_SEL12_East_MC_in2[gamma]+Z_SEL12_East_MC_in2[gamma]*Z_SEL12_East_MC_in2[gamma]) * sqrt( 1.0*1.0 ) ) );
    outfile3<<angle_by_in2_E[gamma]<<endl;			       						
    h3p->Fill(angle_by_in2_E[gamma]);													 				    
  }




  //  cout<<"HERE"<<endl; 
 
  for(int delta = 0; delta<dd; delta++){
    // cout<<"HERE"<<endl;

    angle_by_col_W[delta] = TMath::ACos( (Z_SEL12_West_MC_col[delta]*1.0) / ( sqrt(X_SEL12_West_MC_col[delta]*X_SEL12_West_MC_col[delta]+Y_SEL12_West_MC_col[delta]*Y_SEL12_West_MC_col[delta]+Z_SEL12_West_MC_col[delta]*Z_SEL12_West_MC_col[delta]) * sqrt( 1.0*1.0 ) ) );

    outfile4<<angle_by_col_W[delta]<<endl;
    h4p->Fill(angle_by_col_W[delta]);
  }

  for(int zeta = 0; zeta<ee; zeta++){
    angle_by_in1_W[zeta] = TMath::ACos( (Z_SEL12_West_MC_in1[zeta]*1.0) / ( sqrt(X_SEL12_West_MC_in1[zeta]*X_SEL12_West_MC_in1[zeta]+Y_SEL12_West_MC_in1[zeta]*Y_SEL12_West_MC_in1[zeta]+Z_SEL12_West_MC_in1[zeta]*Z_SEL12_West_MC_in1[zeta]) * sqrt( 1.0*1.0 ) ) );
    outfile5<<angle_by_in1_W[zeta]<<endl;
    h5p->Fill(angle_by_in1_W[zeta]);
  }


  for(int eta = 0; eta<ff; eta++){
  angle_by_in2_W[eta] = TMath::ACos( (Z_SEL12_West_MC_in2[eta]*1.0) / ( sqrt(X_SEL12_West_MC_in2[eta]*X_SEL12_West_MC_in2[eta]+Y_SEL12_West_MC_in2[eta]*Y_SEL12_West_MC_in2[eta]+Z_SEL12_West_MC_in2[eta]*Z_SEL12_West_MC_in2[eta]) * sqrt( 1.0*1.0 ) ) );
    outfile6<<angle_by_in2_W[eta]<<endl;
    h6p->Fill(angle_by_in2_W[eta]);

  }


  TCanvas* cnvs1p= new TCanvas("cnvs1p", "TPC3 East Cryostat MC COL",1,1,600,500);
  h1p->Draw("HIST");
  TCanvas* cnvs2p= new TCanvas("cnvs2p", "TPC3 East Cryostat MC IN1",1,1,600,500);
  h2p->Draw("HIST");
  TCanvas* cnvs3p= new TCanvas("cnvs3p", "TPC3 East Cryostat MC IN2",1,1,600,500);
  h3p->Draw("HIST");
  TCanvas* cnvs4p= new TCanvas("cnvs4p", "TPC3 West Cryostat MC COL",1,1,600,500);
  h4p->Draw("HIST");
  TCanvas* cnvs5p= new TCanvas("cnvs5p", "TPC3 West Cryostat MC IN1",1,1,600,500);
  h5p->Draw("HIST");
  TCanvas* cnvs6p= new TCanvas("cnvs6p", "TPC3 West Cryostat MC IN2",1,1,600,500);
  h6p->Draw("HIST");

  cnvs1p->SaveAs("MC_tpc3_sel12_East_file_xyz_col_angle_NEW.pdf");
  cnvs2p->SaveAs("MC_tpc3_sel12_East_file_xyz_in1_angle_NEW.pdf");
  cnvs3p->SaveAs("MC_tpc3_sel12_East_file_xyz_in2_angle_NEW.pdf");
  cnvs4p->SaveAs("MC_tpc3_sel12_West_file_xyz_col_angle_NEW.pdf");
  cnvs5p->SaveAs("MC_tpc3_sel12_West_file_xyz_in1_angle_NEW.pdf");
  cnvs6p->SaveAs("MC_tpc3_sel12_West_file_xyz_in2_angle_NEW.pdf");


}
