#include<stdio.h>

void JUNE_plots_noCOS(){

  gStyle->SetOptStat(0);

  int n = 10000;
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



  double SEL12_East_MC_col[n];
  double SEL12_East_MC_in1[n];
  double SEL12_East_MC_in2[n];


  double SEL12_East_DATA_col[n];
  double SEL12_East_DATA_in1[n];
  double SEL12_East_DATA_in2[n];



  double SEL12_West_MC_col[n];
  double SEL12_West_MC_in1[n];
  double SEL12_West_MC_in2[n];


  double SEL12_West_DATA_col[n];
  double SEL12_West_DATA_in1[n];
  double SEL12_West_DATA_in2[n];


  double z_SEL12_East_MC_col[n];// = 0.0;
  double z_SEL12_East_MC_in1[n];// = 0.0;
  double z_SEL12_East_MC_in2[n];// = 0.0;

  double z_SEL12_East_DATA_col[n];// = 0.0;
  double z_SEL12_East_DATA_in1[n];// = 0.0;
  double z_SEL12_East_DATA_in2[n];// = 0.0;

  double z_SEL12_West_MC_col[n];// = 0.0;
  double z_SEL12_West_MC_in1[n];// = 0.0;
  double z_SEL12_West_MC_in2[n];// = 0.0;

  double z_SEL12_West_DATA_col[n];// = 0.0;
  double z_SEL12_West_DATA_in1[n];// = 0.0;
  double z_SEL12_West_DATA_in2[n];// = 0.0;

  double z60p_SEL12_East_MC_col[n];// = 0.0;
  double z60p_SEL12_East_MC_in1[n];// = 0.0;
  double z60p_SEL12_East_MC_in2[n];// = 0.0;

  double z60p_SEL12_East_DATA_col[n];// = 0.0;
  double z60p_SEL12_East_DATA_in1[n];// = 0.0;
  double z60p_SEL12_East_DATA_in2[n];// = 0.0;

  double z60p_SEL12_West_MC_col[n];// = 0.0;
  double z60p_SEL12_West_MC_in1[n];// = 0.0;
  double z60p_SEL12_West_MC_in2[n];// = 0.0;

  double z60p_SEL12_West_DATA_col[n];// = 0.0;
  double z60p_SEL12_West_DATA_in1[n];// = 0.0;
  double z60p_SEL12_West_DATA_in2[n];// = 0.0;

  double z60m_SEL12_East_MC_col[n];// = 0.0;
  double z60m_SEL12_East_MC_in1[n];// = 0.0;
  double z60m_SEL12_East_MC_in2[n];// = 0.0;

  double z60m_SEL12_East_DATA_col[n];// = 0.0;
  double z60m_SEL12_East_DATA_in1[n];// = 0.0;
  double z60m_SEL12_East_DATA_in2[n];// = 0.0;

  double z60m_SEL12_West_MC_col[n];// = 0.0;
  double z60m_SEL12_West_MC_in1[n];// = 0.0;
  double z60m_SEL12_West_MC_in2[n];// = 0.0;

  double z60m_SEL12_West_DATA_col[n];// = 0.0;
  double z60m_SEL12_West_DATA_in1[n];// = 0.0;
  double z60m_SEL12_West_DATA_in2[n];// = 0.0;

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

  ifstream infile1("mcJUNE_NUMI_tpc3_sel12_East_file_ZenithAngle_col.txt");
  ifstream infile2("mcJUNE_NUMI_tpc3_sel12_East_file_ZenithAngle_in1.txt");
  ifstream infile3("mcJUNE_NUMI_tpc3_sel12_East_file_ZenithAngle_in2.txt");
  ifstream infile4("mcJUNE_NUMI_tpc3_sel12_West_file_ZenithAngle_col.txt");
  ifstream infile5("mcJUNE_NUMI_tpc3_sel12_West_file_ZenithAngle_in1.txt");
  ifstream infile6("mcJUNE_NUMI_tpc3_sel12_West_file_ZenithAngle_in2.txt");

  ofstream a("test2.txt");
  //  TCanvas* cnvs1= new TCanvas("cnvs1", "TPC3 East Cryostat MC",1,1,600,500);
  TH1F *h1 = new TH1F("h1","TPC3 East Cryostat MC (COL)", 100., -1.0, 1.0);
  h1->GetXaxis()->SetTitle("  Zenith in radians ");

  //  TCanvas* cnvs2= new TCanvas("cnvs2", "TPC3 East Cryostat MC",1,1,600,500);
  TH1F *h2 = new TH1F("h2","TPC3 East Cryostat MC (IN1)", 50.,-1.0, 1.0); //-1.0, 1.0);0., 7.0);
  h2->GetXaxis()->SetTitle("   Zenith in radians ");

  //TCanvas* cnvs3= new TCanvas("cnvs3", "TPC3 East Cryostat MC",1,1,600,500);
  TH1F *h3 = new TH1F("h3","TPC3 East Cryostat MC (IN2)", 100., -1.0, 1.0); //0., 7.0);
  h3->GetXaxis()->SetTitle("  Zenith in radians ");

  //TCanvas* cnvs7= new TCanvas("cnvs7", "TPC3 West Cryostat MC",1,1,600,500);
  TH1F *h4 = new TH1F("h4","TPC3 West Cryostat MC (COL)", 100., -1.0, 1.0); //0., 7.0);
  h4->GetXaxis()->SetTitle("  Zenith in radians ");

  //TCanvas* cnvs8= new TCanvas("cnvs8", "TPC3 West Cryostat MC",1,1,600,500);
  TH1F *h5 = new TH1F("h5","TPC3 West Cryostat MC (IN1)", 100., -1.0, 1.0); //0., 7.0);
  h5->GetXaxis()->SetTitle("  Zenith in radians ");

  //TCanvas* cnvs9= new TCanvas("cnvs9", "TPC3 West Cryostat MC",1,1,600,500);
  TH1F *h6 = new TH1F("h6","TPC3 West Cryostat MC (IN2)", 100., -1.0, 1.0); //0., 7.0);
  h6->GetXaxis()->SetTitle("  Zenith in radians ");







  while(infile1>>A)
    {
      SEL12_East_MC_col[aa] = A;
      aa++;
    }

  while(infile2>>B)
    {
      SEL12_East_MC_in1[bb] = B;
      bb++;
    }

  while(infile3>>C)
    {
      SEL12_East_MC_in2[cc] = C;
      cc++;
    }



  while(infile4>>D)
    {
      SEL12_West_MC_col[dd] = D;
      dd++;
    }

  while(infile5>>E)
    {
      SEL12_West_MC_in1[ee] = E;
      ee++;
    }

  while(infile6>>F)
    {
      SEL12_West_MC_in2[ff] = F;
      ff++;
    }




  cout<<"TEST"<<endl;
  for(int aa2 = 0; aa2<aa; aa2++){

    //z_SEL12_East_MC_col[aa2] =  abs( (TMath::Pi()/2.0) - SEL12_East_MC_col[aa2] );
    cout<<TMath::Cos(SEL12_East_MC_col[aa2])<<endl;
    h1->Fill(SEL12_East_MC_col[aa2]);
    cout<<TMath::Cos(SEL12_East_MC_col[aa2])<<" "<<SEL12_East_MC_col[aa2]<<endl;
    //" "<<TMath::Cos(z60m_SEL12_East_MC_col[aa2])<<endl;
  }



  for(int bb2 = 0; bb2<bb; bb2++){

    //z_SEL12_East_MC_in1[bb2] =  abs( (TMath::Pi()/2.0) - SEL12_East_MC_in1[bb2] );
    h2->Fill(SEL12_East_MC_in1[bb2]);
    }


  for(int cc2 = 0; cc2<cc; cc2++){

    h3->Fill(SEL12_East_MC_in2[cc2]);
    }




  for(int dd2 = 0; dd2<dd; dd2++){

    //z_SEL12_East_DATA_col[dd2] =  abs( (TMath::Pi()/2.0) - SEL12_East_DATA_col[dd2] );
    h4->Fill(SEL12_West_MC_col[dd2]);
    a<<SEL12_West_MC_col[dd2]<<endl;
     }

  a<<"NEXT"<<endl;

  for(int ee2 = 0; ee2<ee; ee2++){

    //    z_SEL12_East_DATA_in1[ee2] =  abs( (TMath::Pi()/2.0) - SEL12_East_DATA_in1[ee2] );
    h5->Fill(SEL12_West_MC_in1[ee2]);
    a<<SEL12_West_MC_in1[ee2]<<endl;

     }


  for(int ff2 = 0; ff2<ff; ff2++){
    h6->Fill(SEL12_West_MC_in2[ff2]);
  }


















  TCanvas* cnvs1= new TCanvas("cnvs1", "TPC3 East Cryostat MC",1,1,600,500);
  h1->Draw("HIST");


  TCanvas* cnvs2= new TCanvas("cnvs2", "TPC3 East Cryostat MC",1,1,600,500);
  h2->Draw("HIST");

  TCanvas* cnvs3= new TCanvas("cnvs3", "TPC3 East Cryostat MC",1,1,600,500);
  h3->Draw("HIST");



  TCanvas* cnvs4= new TCanvas("cnvs4", "TPC3 West Cryostat MC",1,1,600,500);
  h4->Draw("HIST");

  TCanvas* cnvs5= new TCanvas("cnvs5", "TPC3 West Cryostat MC",1,1,600,500);
  h5->Draw("HIST");


  TCanvas* cnvs6= new TCanvas("cnvs6", "TPC3 West Cryostat MC",1,1,600,500);
  h6->Draw("HIST");


   cnvs1->SaveAs("MC_tpc3_sel12_East_file_ZenithAngle_col_noCOS.pdf");

  cnvs2->SaveAs("MC_tpc3_sel12_East_file_ZenithAngle_in1_noCOS.pdf");

  cnvs3->SaveAs("MC_tpc3_sel12_East_file_ZenithAngle_in2_noCOS.pdf");


  cnvs4->SaveAs("MC_tpc3_sel12_West_file_ZenithAngle_col_noCOS.pdf");

  cnvs5->SaveAs("MC_tpc3_sel12_West_file_ZenithAngle_in1_noCOS.pdf");

  cnvs6->SaveAs("MC_tpc3_sel12_West_file_ZenithAngle_in2_noCOS.pdf");

 

  }
