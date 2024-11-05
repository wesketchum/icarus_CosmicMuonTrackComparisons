#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "sbnobj/Common/Calibration/TrackCaloSkimmerObj.h"


#include<stdio.h>
void Between2_hor(){



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

  double angle_by_col_Eo[n];
  double angle_by_in2_Eo[n];
  double angle_by_col_Wo[n];
  double angle_by_in2_Wo[n];
  double angle_by_in1_Eo[n];
  double angle_by_in1_Wo[n];

  ifstream infile1("mcJUNE_NUMI_tpc0_sel12_East_file_xyz_col.txt");
  ifstream infile2("mcJUNE_NUMI_tpc0_sel12_East_file_xyz_in1.txt");
  ifstream infile3("mcJUNE_NUMI_tpc0_sel12_East_file_xyz_in2.txt");

  ifstream infile4("mcJUNE_NUMI_tpc0_sel12_West_file_xyz_col.txt");
  ifstream infile5("mcJUNE_NUMI_tpc0_sel12_West_file_xyz_in1.txt");
  ifstream infile6("mcJUNE_NUMI_tpc0_sel12_West_file_xyz_in2.txt");

  ofstream outfile1("hnoCOSangle_by_col_E_tpc0.txt");
  ofstream outfile2("hnoCOSangle_by_in1_E_tpc0.txt");
  ofstream outfile3("hnoCOSangle_by_in2_E_tpc0.txt");
  ofstream outfile4("hnoCOSangle_by_col_W_tpc0.txt");
  ofstream outfile5("hnoCOSangle_by_in1_W_tpc0.txt");
  ofstream outfile6("hnoCOSangle_by_in2_W_tpc0.txt");

  double Pi = 3.1415926535897932384;

  TH1F *h1p = new TH1F("h1p","TPC0 East Cryostat MC (COL) ", 100., 0.0, 2.0); //0., 7.0);                           
  h1p->GetXaxis()->SetTitle("angle in radians");

  TH1F *h4p = new TH1F("h4p","TPC0 West Cryostat MC (COL) ", 100., 0.0, 2.0); //0., 7.0);                           
  h4p->GetXaxis()->SetTitle("angle in radians");

  TH1F *h5p = new TH1F("h5p","TPC0 West Cryostat MC (IN1) ", 100., 0.0, 2.0); //0., 7.0);                           
  h5p->GetXaxis()->SetTitle("angle in radians");

  TH1F *h6p = new TH1F("h6p","TPC0 West Cryostat MC (IN2) ", 100., 0.0, 2.0); //0., 7.0);                           
  h6p->GetXaxis()->SetTitle("angle in radians");

  TH1F *h2p = new TH1F("h2p","TPC0 East Cryostat MC (IN1) ", 100., 0.0, 2.0); //0., 7.0);                                                                                         
  h2p->GetXaxis()->SetTitle("angle in radians");

  TH1F *h3p = new TH1F("h3p","TPC0 East Cryostat MC (IN2) ", 100., 0.0, 2.0); //0., 7.0);                                                                                         
  h3p->GetXaxis()->SetTitle("angle in radians");



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

  /*
  for(int sym_a =0; sym_a<aa; sym_a++){
    X_SEL12_East_MC_col[sym_a] = X_SEL12_East_MC_colo[sym_a]*TMath::Cos(TMath::Pi/3.0) - Y_SEL12_East_MC_colo[sym_a]*TMath::Sin(TMath::Pi/3.0);
    Y_SEL12_East_MC_col[sym_a] = X_SEL12_East_MC_colo[sym_a]*TMath::Sin(TMath::Pi/3.0) + Y_SEL12_East_MC_colo[sym_a]*TMath::Cos(TMath::Pi/3.0);
    Z_SEL12_East_MC_col[sym_a] = Z_SEL12_East_MC_colo[sym_a];
  }

  for(int sym_b =0; sym_b<bb; sym_b++){
    X_SEL12_East_MC_in1[sym_b] = X_SEL12_East_MC_in1o[sym_b]*TMath::Cos(TMath::Pi/3.0) - Y_SEL12_East_MC_in1o[sym_b]*TMath::Sin(TMath::Pi/3.0);
    Y_SEL12_East_MC_in1[sym_b] = X_SEL12_East_MC_in1o[sym_b]*TMath::Sin(TMath::Pi/3.0) + Y_SEL12_East_MC_in1o[sym_b]*TMath::Cos(TMath::Pi/3.0);
    Z_SEL12_East_MC_in1[sym_b] = Z_SEL12_East_MC_in1o[sym_b];
  }

  for(int sym_c =0; sym_c<cc; sym_c++){
    X_SEL12_East_MC_in2[sym_c] = X_SEL12_East_MC_in2o[sym_c]*TMath::Cos(TMath::Pi/3.0) - Y_SEL12_East_MC_in2o[sym_c]*TMath::Sin(TMath::Pi/3.0);
    Y_SEL12_East_MC_in2[sym_c] = X_SEL12_East_MC_in2o[sym_c]*TMath::Sin(TMath::Pi/3.0) + Y_SEL12_East_MC_in2o[sym_c]*TMath::Cos(TMath::Pi/3.0);
    Z_SEL12_East_MC_in2[sym_c] = Z_SEL12_East_MC_in2o[sym_c];
  }

  for(int sym_d =0; sym_d<dd; sym_d++){
    X_SEL12_West_MC_col[sym_d] = X_SEL12_West_MC_colo[sym_d]*TMath::Cos(TMath::Pi/3.0) - Y_SEL12_West_MC_colo[sym_d]*TMath::Sin(TMath::Pi/3.0);
    Y_SEL12_West_MC_col[sym_d] = X_SEL12_West_MC_colo[sym_d]*TMath::Sin(TMath::Pi/3.0) + Y_SEL12_West_MC_colo[sym_d]*TMath::Cos(TMath::Pi/3.0);
    Z_SEL12_West_MC_col[sym_d] = Z_SEL12_West_MC_colo[sym_d];
  }

  for(int sym_e =0; sym_e<ee; sym_e++){
    X_SEL12_West_MC_in1[sym_e] = X_SEL12_West_MC_in1o[sym_e]*TMath::Cos(TMath::Pi/3.0) - Y_SEL12_West_MC_in1o[sym_e]*TMath::Sin(TMath::Pi/3.0);
    Y_SEL12_West_MC_in1[sym_e] = X_SEL12_West_MC_in1o[sym_e]*TMath::Sin(TMath::Pi/3.0) + Y_SEL12_West_MC_in1o[sym_e]*TMath::Cos(TMath::Pi/3.0);
    Z_SEL12_West_MC_in1[sym_e] = Z_SEL12_West_MC_in1o[sym_e];
  }

  for(int sym_f =0; sym_f<ff; sym_f++){
    X_SEL12_West_MC_in2[sym_f] = X_SEL12_West_MC_in2o[sym_f]*TMath::Cos(TMath::Pi/3.0) - Y_SEL12_West_MC_in2o[sym_f]*TMath::Sin(TMath::Pi/3.0);
    Y_SEL12_West_MC_in2[sym_f] = X_SEL12_West_MC_in2o[sym_f]*TMath::Sin(TMath::Pi/3.0) + Y_SEL12_West_MC_in2o[sym_f]*TMath::Cos(TMath::Pi/3.0);
    Z_SEL12_West_MC_in2[sym_f] = Z_SEL12_West_MC_in2o[sym_f];
  }

  */
  double z_p = 1.0;
  


  for(int alpha = 0; alpha<aa; alpha++){

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

  for(int beta = 0; beta<bb; beta++){
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
    for(int gamma = 0; gamma<cc; gamma++){
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
	h3p->Fill(angle_by_in2_E[gamma]);													  }	    
  }




  //  cout<<"HERE"<<endl; 
 
  for(int delta = 0; delta<dd; delta++){
    // cout<<"HERE"<<endl;

    angle_by_col_W[delta] = TMath::ACos( ( (Z_SEL12_West_MC_col[delta]*z_p) ) / ( sqrt(X_SEL12_West_MC_col[delta]*X_SEL12_West_MC_col[delta]+Y_SEL12_West_MC_col[delta]*Y_SEL12_West_MC_col[delta]+Z_SEL12_West_MC_col[delta]*Z_SEL12_West_MC_col[delta]) * sqrt( (z_p*z_p) ) ) );

    if( (angle_by_col_W[delta] > (Pi)) && (angle_by_col_W[delta] < ((3.0*Pi)/2.0))){
      outfile4<<angle_by_col_W[delta]-(Pi)<<endl;
      h4p->Fill(angle_by_col_W[delta]-(Pi));

    }

    else if( (angle_by_col_W[delta] > ((Pi)/2.0)) && (angle_by_col_W[delta] < (Pi))){
      outfile4<<(Pi) - angle_by_col_W[delta]<<endl;
      h4p->Fill((Pi) - angle_by_col_W[delta]);

    }
    else if(angle_by_col_W[delta] < ((Pi)/2.0) ){
    outfile4<<angle_by_col_W[delta]<<endl;
    h4p->Fill(angle_by_col_W[delta]);
    }
  }

  for(int zeta = 0; zeta<ee; zeta++){
    angle_by_in1_W[zeta] = TMath::ACos( (  (Z_SEL12_West_MC_in1[zeta]*z_p) ) / ( sqrt(X_SEL12_West_MC_in1[zeta]*X_SEL12_West_MC_in1[zeta]+Y_SEL12_West_MC_in1[zeta]*Y_SEL12_West_MC_in1[zeta]+Z_SEL12_West_MC_in1[zeta]*Z_SEL12_West_MC_in1[zeta]) * sqrt( (z_p*z_p) ) ) );

    if( (angle_by_in1_W[zeta] > (Pi)) && (angle_by_in1_W[zeta] < ((3.0*Pi)/2.0))){
      outfile5<<angle_by_in1_W[zeta]-(Pi)<<endl;
      h5p->Fill(angle_by_in1_W[zeta]-(Pi));
    }

    else if( (angle_by_in1_W[zeta] > ((Pi)/2.0)) && (angle_by_in1_W[zeta] < (Pi))){
      outfile5<<(Pi) - angle_by_in1_W[zeta]<<endl;
      h5p->Fill((Pi) - angle_by_in1_W[zeta]);

    }
    else if(angle_by_in1_W[zeta] < ((Pi)/2.0) ){
    outfile5<<angle_by_in1_W[zeta]<<endl;
    h5p->Fill(angle_by_in1_W[zeta]);
    }
  }


  for(int eta = 0; eta<ff; eta++){
    angle_by_in2_W[eta] = TMath::ACos( (  (Z_SEL12_West_MC_in2[eta]*z_p) ) / ( sqrt(X_SEL12_West_MC_in2[eta]*X_SEL12_West_MC_in2[eta]+Y_SEL12_West_MC_in2[eta]*Y_SEL12_West_MC_in2[eta]+Z_SEL12_West_MC_in2[eta]*Z_SEL12_West_MC_in2[eta]) * sqrt( (z_p*z_p) ) ) );

    if( (angle_by_in2_W[eta] > (Pi) ) && (angle_by_in2_W[eta] < ((3.0*Pi)/2.0) )){
      outfile6<<angle_by_in2_W[eta] -(Pi)<<endl;
      h6p->Fill(angle_by_in2_W[eta] -(Pi));
    }
    else if( (angle_by_in2_W[eta] > ((Pi)/2.0) ) && (angle_by_in2_W[eta] < (Pi) )){
      outfile6<<(Pi) - angle_by_in2_W[eta]<<endl;
      h6p->Fill((Pi) - angle_by_in2_W[eta]);
    }
    else if(angle_by_in2_W[eta] < ((Pi)/2.0) ){
    outfile6<<angle_by_in2_W[eta]<<endl;
    h6p->Fill(angle_by_in2_W[eta]);
    }
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

  cnvs1p->SaveAs("MC_tpc0_sel12_East_file_xyz_col_angle_NEW_h.pdf");
  cnvs2p->SaveAs("MC_tpc0_sel12_East_file_xyz_in1_angle_NEW_h.pdf");
  cnvs3p->SaveAs("MC_tpc0_sel12_East_file_xyz_in2_angle_NEW_h.pdf");
  cnvs4p->SaveAs("MC_tpc0_sel12_West_file_xyz_col_angle_NEW_h.pdf");
  cnvs5p->SaveAs("MC_tpc0_sel12_West_file_xyz_in1_angle_NEW_h.pdf");
  cnvs6p->SaveAs("MC_tpc0_sel12_West_file_xyz_in2_angle_NEW_h.pdf");


}
