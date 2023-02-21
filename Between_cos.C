#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "sbnobj/Common/Calibration/TrackCaloSkimmerObj.h"


#include<stdio.h>
void Between_cos(){



  gStyle->SetOptStat(0);
  int n = 4500;

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


  double angle_wrt_col_E[n];
  double angle_wrt_in2_E[n];
  double angle_wrt_col_W[n];
  double angle_wrt_in2_W[n];


  ifstream infile1("mcJUNE_NUMI_tpc0_sel12_East_file_xyz_col.txt");
  ifstream infile2("mcJUNE_NUMI_tpc0_sel12_East_file_xyz_in1.txt");
  ifstream infile3("mcJUNE_NUMI_tpc0_sel12_East_file_xyz_in2.txt");

  ifstream infile4("mcJUNE_NUMI_tpc0_sel12_West_file_xyz_col.txt");
  ifstream infile5("mcJUNE_NUMI_tpc0_sel12_West_file_xyz_in1.txt");
  ifstream infile6("mcJUNE_NUMI_tpc0_sel12_West_file_xyz_in2.txt");

  ofstream outfile1("angle_wrt_col_E.txt");
  ofstream outfile2("angle_wrt_in2_E.txt");
  ofstream outfile3("angle_wrt_col_W.txt");
  ofstream outfile4("angle_wrt_in2_W.txt");

  TH1F *h1p = new TH1F("h1p","TPC0 East Cryostat MC (COL) ", 100., -1.0, 1.0); //0., 7.0);                           
  h1p->GetXaxis()->SetTitle("cosine of angle wrt horizontal in radians");

  TH1F *h2p = new TH1F("h2p","TPC0 West Cryostat MC (COL) ", 100., -1.0, 1.0); //0., 7.0);                           
  h2p->GetXaxis()->SetTitle("cosine of angle wrt horizontal in radians");

  TH1F *h3p = new TH1F("h3p","TPC0 East Cryostat MC (IN2) ", 100., -1.0, 1.0); //0., 7.0);                           
  h3p->GetXaxis()->SetTitle("cosine of angle wrt horizontal in radians");

  TH1F *h4p = new TH1F("h4p","TPC0 West Cryostat MC (IN2) ", 100., 01.0, 1.0); //0., 7.0);                           
  h4p->GetXaxis()->SetTitle("cosine of angle wrt horizontal in radians");





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

  for(int alpha = 0; alpha<bb; alpha++){

    angle_wrt_col_E[alpha] =  (X_SEL12_East_MC_col[alpha]*X_SEL12_East_MC_in1[alpha] + Y_SEL12_East_MC_col[alpha]*Y_SEL12_East_MC_in1[alpha] + Z_SEL12_East_MC_col[alpha]*Z_SEL12_East_MC_in1[alpha]) / ( sqrt(X_SEL12_East_MC_col[alpha]*X_SEL12_East_MC_col[alpha] + Y_SEL12_East_MC_col[alpha]*Y_SEL12_East_MC_col[alpha] + Z_SEL12_East_MC_col[alpha]*Z_SEL12_East_MC_col[alpha]) * sqrt(X_SEL12_East_MC_in1[alpha]*X_SEL12_East_MC_in1[alpha] + Y_SEL12_East_MC_in1[alpha]*Y_SEL12_East_MC_in1[alpha] + Z_SEL12_East_MC_in1[alpha]*Z_SEL12_East_MC_in1[alpha]));
    outfile1<<angle_wrt_col_E[alpha]<<endl;
    h1p->Fill(angle_wrt_col_E[alpha]);

    angle_wrt_in2_E[alpha] =   (X_SEL12_East_MC_in2[alpha]*X_SEL12_East_MC_in1[alpha] + Y_SEL12_East_MC_in2[alpha]*Y_SEL12_East_MC_in1[alpha] + Z_SEL12_East_MC_in2[alpha]*Z_SEL12_East_MC_in1[alpha]) / ( sqrt(X_SEL12_East_MC_in2[alpha]*X_SEL12_East_MC_in2[alpha] + Y_SEL12_East_MC_in2[alpha]*Y_SEL12_East_MC_in2[alpha] + Z_SEL12_East_MC_in2[alpha]*Z_SEL12_East_MC_in2[alpha]) * sqrt(X_SEL12_East_MC_in1[alpha]*X_SEL12_East_MC_in1[alpha] + Y_SEL12_East_MC_in1[alpha]*Y_SEL12_East_MC_in1[alpha] + Z_SEL12_East_MC_in1[alpha]*Z_SEL12_East_MC_in1[alpha]));															
     outfile2<<angle_wrt_in2_E[alpha]<<endl;			       						
    h3p->Fill(angle_wrt_in2_E[alpha]);																								    
  }
  //  cout<<"HERE"<<endl; 
 
  for(int beta = 0; beta<ee; beta++){
    // cout<<"HERE"<<endl;
    angle_wrt_col_W[beta] =  (X_SEL12_West_MC_col[beta]*X_SEL12_West_MC_in1[beta] + Y_SEL12_West_MC_col[beta]*Y_SEL12_West_MC_in1[beta] + Z_SEL12_West_MC_col[beta]*Z_SEL12_West_MC_in1[beta]) / ( sqrt(X_SEL12_West_MC_col[beta]*X_SEL12_West_MC_col[beta] + Y_SEL12_West_MC_col[beta]*Y_SEL12_West_MC_col[beta] + Z_SEL12_West_MC_col[beta]*Z_SEL12_West_MC_col[beta]) * sqrt(X_SEL12_West_MC_in1[beta]*X_SEL12_West_MC_in1[beta] + Y_SEL12_West_MC_in1[beta]*Y_SEL12_West_MC_in1[beta] + Z_SEL12_West_MC_in1[beta]*Z_SEL12_West_MC_in1[beta]));
    outfile3<<angle_wrt_col_W[beta]<<endl;
    h2p->Fill(angle_wrt_col_W[beta]);

    angle_wrt_in2_W[beta] =  (X_SEL12_West_MC_in2[beta]*X_SEL12_West_MC_in1[beta] + Y_SEL12_West_MC_in2[beta]*Y_SEL12_West_MC_in1[beta] + Z_SEL12_West_MC_in2[beta]*Z_SEL12_West_MC_in1[beta]) / ( sqrt(X_SEL12_West_MC_in2[beta]*X_SEL12_West_MC_in2[beta] + Y_SEL12_West_MC_in2[beta]*Y_SEL12_West_MC_in2[beta] + Z_SEL12_West_MC_in2[beta]*Z_SEL12_West_MC_in2[beta]) * sqrt(X_SEL12_West_MC_in1[beta]*X_SEL12_West_MC_in1[beta] + Y_SEL12_West_MC_in1[beta]*Y_SEL12_West_MC_in1[beta] + Z_SEL12_West_MC_in1[beta]*Z_SEL12_West_MC_in1[beta]));
    outfile4<<angle_wrt_in2_W[beta]<<endl;
    h4p->Fill(angle_wrt_in2_W[beta]);

  }


  TCanvas* cnvs1p= new TCanvas("cnvs1p", "TPC0 East Cryostat MC COL",1,1,600,500);
  h1p->Draw("HIST");
  TCanvas* cnvs2p= new TCanvas("cnvs2p", "TPC0 West Cryostat MC COL",1,1,600,500);
  h2p->Draw("HIST");
  TCanvas* cnvs3p= new TCanvas("cnvs3p", "TPC0 East Cryostat MC IN2",1,1,600,500);
  h3p->Draw("HIST");
  TCanvas* cnvs4p= new TCanvas("cnvs4p", "TPC0 West Cryostat MC IN2",1,1,600,500);
  h4p->Draw("HIST");


  cnvs1p->SaveAs("MC_tpc0_sel12_East_file_xyz_col_COSangle_NEW.pdf");
  cnvs2p->SaveAs("MC_tpc0_sel12_West_file_xyz_col_COSangle_NEW.pdf");
  cnvs3p->SaveAs("MC_tpc0_sel12_East_file_xyz_in2_COSangle_NEW.pdf");
  cnvs4p->SaveAs("MC_tpc0_sel12_West_file_xyz_in2_COSangle_NEW.pdf");



}
