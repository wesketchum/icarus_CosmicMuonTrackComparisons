#include<stdio.h>

void JUNE_plots(){

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

  ifstream infile1("mcJUNE_NUMI_tpc0_sel12_East_file_ZenithAngle_col.txt");
  ifstream infile2("mcJUNE_NUMI_tpc0_sel12_East_file_ZenithAngle_in1.txt");
  ifstream infile3("mcJUNE_NUMI_tpc0_sel12_East_file_ZenithAngle_in2.txt");

  ifstream infile4("dataJUNE_NUMI_tpc0_sel12_East_file_ZenithAngle_col.txt");
  ifstream infile5("dataJUNE_NUMI_tpc0_sel12_East_file_ZenithAngle_in1.txt");
  ifstream infile6("dataJUNE_NUMI_tpcc_sel12_East_file_ZenithAngle_in2.txt");

  ifstream infile7("mcJUNE_NUMI_tpc0_sel12_West_file_ZenithAngle_col.txt");
  ifstream infile8("mcJUNE_NUMI_tpc0_sel12_West_file_ZenithAngle_in1.txt");
  ifstream infile9("mcJUNE_NUMI_tpc0_sel12_West_file_ZenithAngle_in2.txt");

  ifstream infile10("dataJUNE_NUMI_tpc0_sel12_West_file_ZenithAngle_col.txt");
  ifstream infile11("dataJUNE_NUMI_tpc0_sel12_West_file_ZenithAngle_in1.txt");
  ifstream infile12("dataJUNE_NUMI_tpc0_sel12_West_file_ZenithAngle_in2.txt");


  //  TCanvas* cnvs1= new TCanvas("cnvs1", "TPC0 East Cryostat MC",1,1,600,500);
  TH1F *h1 = new TH1F("h1","TPC0 East Cryostat MC (COL)", 100., -1.0, 1.0);
  h1->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //  TCanvas* cnvs2= new TCanvas("cnvs2", "TPC0 East Cryostat MC",1,1,600,500);
  TH1F *h2 = new TH1F("h2","TPC0 East Cryostat MC (IN1)", 50.,-1.0, 1.0); //-1.0, 1.0);0., 7.0);
  h2->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs3= new TCanvas("cnvs3", "TPC0 East Cryostat MC",1,1,600,500);
  TH1F *h3 = new TH1F("h3","TPC0 East Cryostat MC (IN2)", 100., -1.0, 1.0); //0., 7.0);
  h3->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs4= new TCanvas("cnvs4", "TPC0 East Cryostat DATA",1,1,600,500);
  TH1F *h4 = new TH1F("h4","TPC0 East Cryostat DATA (COL)", 100., -1.0, 1.0); //0., 7.0);
  h4->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs5= new TCanvas("cnvs5", "TPC0 East Cryostat DATA",1,1,600,500);
  TH1F *h5 = new TH1F("h5","TPC0 East Cryostat DATA (IN1)", 100., -1.0, 1.0); //0., 7.0);
  h5->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs6= new TCanvas("cnvs6", "TPC0 East Cryostat DATA",1,1,600,500);
  TH1F *h6 = new TH1F("h6","TPC0 East Cryostat DATA (IN2)", 100., -1.0, 1.0); //0., 7.0);
  h6->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs7= new TCanvas("cnvs7", "TPC0 West Cryostat MC",1,1,600,500);
  TH1F *h7 = new TH1F("h7","TPC0 West Cryostat MC (COL)", 100., -1.0, 1.0); //0., 7.0);
  h7->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs8= new TCanvas("cnvs8", "TPC0 West Cryostat MC",1,1,600,500);
  TH1F *h8 = new TH1F("h8","TPC0 West Cryostat MC (IN1)", 100., -1.0, 1.0); //0., 7.0);
  h8->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs9= new TCanvas("cnvs9", "TPC0 West Cryostat MC",1,1,600,500);
  TH1F *h9 = new TH1F("h9","TPC0 West Cryostat MC (IN2)", 100., -1.0, 1.0); //0., 7.0);
  h9->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs10= new TCanvas("cnvs10", "TPC0 West Cryostat DATA",1,1,600,500);
  TH1F *h10 = new TH1F("h10","TPC0 West Cryostat DATA (COL)", 100., -1.0, 1.0); //0., 7.0);
  h10->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs11= new TCanvas("cnvs11", "TPC0 West Cryostat DATA",1,1,600,500);
  TH1F *h11 = new TH1F("h11","TPC0 West Cryostat DATA (IN1)", 100., -1.0, 1.0); //0., 7.0);
  h11->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs12= new TCanvas("cnvs12", "TPC0 West Cryostat DATA",1,1,600,500);
  TH1F *h12 = new TH1F("h12","TPC0 West Cryostat DATA (IN2)", 100., -1.0, 1.0); //0., 7.0);
  h12->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //  TCanvas* cnvs1p= new TCanvas("cnvs1p", "TPC0 East Cryostat MC +60",1,1,600,500);
  TH1F *h1p = new TH1F("h1p","TPC0 East Cryostat MC (COL) +60", 100., -1.0, 1.0); //0., 7.0);
  h1p->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs2p= new TCanvas("cnvs2p", "TPC0 East Cryostat MC +60",1,1,600,500);
  TH1F *h2p = new TH1F("h2p","TPC0 East Cryostat MC (IN1) +60", 100., -1.0, 1.0); //., 7.0);
  h2p->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs3p= new TCanvas("cnvs3p", "TPC0 East Cryostat MC +60",1,1,600,500);
  TH1F *h3p = new TH1F("h3p","TPC0 East Cryostat MC (IN2) +60", 100., -1.0, 1.0); //0., 7.0);
  h3p->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs4p= new TCanvas("cnvs4p", "TPC0 East Cryostat DATA +60",1,1,600,500);
  TH1F *h4p = new TH1F("h4p","TPC0 East Cryostat DATA (COL) +60", 100., -1.0, 1.0); //0., 7.0);
  h4p->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs5p= new TCanvas("cnvs5p", "TPC0 East Cryostat DATA +60",1,1,600,500);
  TH1F *h5p = new TH1F("h5p","TPC0 East Cryostat DATA (IN1) +60", 100., -1.0, 1.0); //0., 7.0);
  h5p->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs6p= new TCanvas("cnvs6p", "TPC0 East Cryostat DATA +60",1,1,600,500);
  TH1F *h6p = new TH1F("h6p","TPC0 East Cryostat DATA (IN2) +60", 100., -1.0, 1.0); //0., 7.0);
  h6p->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs7p= new TCanvas("cnvs7p", "TPC0 West Cryostat MC +60",1,1,600,500);
  TH1F *h7p = new TH1F("h7p","TPC0 West Cryostat MC (COL) +60", 100., -1.0, 1.0); //0., 7.0);
  h7p->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs8p= new TCanvas("cnvs8p", "TPC0 West Cryostat MC +60",1,1,600,500);
  TH1F *h8p = new TH1F("h8p","TPC0 West Cryostat MC (IN1) +60", 100., -1.0, 1.0); //0., 7.0);
  h8p->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs9p= new TCanvas("cnvs9p", "TPC0 West Cryostat MC +60",1,1,600,500);
  TH1F *h9p = new TH1F("h9p","TPC0 West Cryostat MC (IN2) +60", 100., -1.0, 1.0); //0., 7.0);
  h9p->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs10p= new TCanvas("cnvs10p", "TPC0 West Cryostat DATA +60",1,1,600,500);
  TH1F *h10p = new TH1F("h10p","TPC0 West Cryostat DATA (COL) +60", 100., -1.0, 1.0); //0., 7.0);
  h10p->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  // TCanvas* cnvs11p= new TCanvas("cnvs11p", "TPC0 West Cryostat DATA +60",1,1,600,500);
  TH1F *h11p = new TH1F("h11p","TPC0 West Cryostat DATA (IN1) +60", 100., -1.0, 1.0); //0., 7.0);
  h11p->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  // TCanvas* cnvs12p= new TCanvas("cnvs12p", "TPC0 West Cryostat DATA +60",1,1,600,500);
  TH1F *h12p = new TH1F("h12p","TPC0 West Cryostat DATA (IN2) +60", 100., -1.0, 1.0); //0., 7.0);
  h12p->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  // TCanvas* cnvs1m= new TCanvas("cnvs1m", "TPC0 East Cryostat MC -60",1,1,600,500);
  TH1F *h1m = new TH1F("h1m","TPC0 East Cryostat MC (COL) -60", 100., -1.0, 1.0); //0., 7.0);
  h1m->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs2m= new TCanvas("cnvs2m", "TPC0 East Cryostat MC -60",1,1,600,500);
  TH1F *h2m = new TH1F("h2m","TPC0 East Cryostat MC (IN1) -60", 100.,-1.0, 1.0); // 0., 7.0);
  h2m->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs3m= new TCanvas("cnvs3m", "TPC0 East Cryostat MC -60",1,1,600,500);
  TH1F *h3m = new TH1F("h3m","TPC0 East Cryostat MC (IN2) -60", 100., -1.0, 1.0); //0., 7.0);
  h3m->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs4m= new TCanvas("cnvs4m", "TPC0 East Cryostat DATA -60",1,1,600,500);
  TH1F *h4m = new TH1F("h4m","TPC0 East Cryostat DATA (COL) -60", 100., -1.0, 1.0); //0., 7.0);
  h4m->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //  TCanvas* cnvs5m= new TCanvas("cnvs5m", "TPC0 East Cryostat DATA -60",1,1,600,500);
  TH1F *h5m = new TH1F("h5m","TPC0 East Cryostat DATA (IN1) -60", 100., -1.0, 1.0); //0., 7.0);
  h5m->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs6m= new TCanvas("cnvs6m", "TPC0 East Cryostat DATA -60",1,1,600,500);
  TH1F *h6m = new TH1F("h6m","TPC0 East Cryostat DATA (IN2) -60", 100.,-1.0, 1.0); // 0., 7.0);
  h6m->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs7m= new TCanvas("cnvs7m", "TPC0 West Cryostat MC -60",1,1,600,500);
  TH1F *h7m = new TH1F("h7m","TPC0 West Cryostat MC (COL) -60", 100., -1.0, 1.0); //0., 7.0);
  h7m->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs8m= new TCanvas("cnvs8m", "TPC0 West Cryostat MC -60",1,1,600,500);
  TH1F *h8m = new TH1F("h8m","TPC0 West Cryostat MC (IN1) -60", 100., -1.0, 1.0); //0., 7.0);
  h8m->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs9m= new TCanvas("cnvs9m", "TPC0 West Cryostat MC -60",1,1,600,500);
  TH1F *h9m = new TH1F("h9m","TPC0 West Cryostat MC (IN2) -60", 100., -1.0, 1.0); //0., 7.0);
  h9m->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs10m= new TCanvas("cnvs10m", "TPC0 West Cryostat DATA -60",1,1,600,500);
  TH1F *h10m = new TH1F("h10m","TPC0 West Cryostat DATA (COL) -60", 100., -1.0, 1.0); //0., 7.0);
  h10m->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs11m= new TCanvas("cnvs11m", "TPC0 West Cryostat DATA -60",1,1,600,500);
  TH1F *h11m = new TH1F("h11m","TPC0 West Cryostat DATA (IN1) -60", 100., -1.0, 1.0); //0., 7.0);
  h11m->GetXaxis()->SetTitle("Cosine of Zenith in radians");

  //TCanvas* cnvs12m= new TCanvas("cnvs12m", "TPC0 West Cryostat DATA -60",1,1,600,500);
  TH1F *h12m = new TH1F("h12m","TPC0 West Cryostat DATA (IN2) -60", 100., -1.0, 1.0); //0., 7.0);
  h12m->GetXaxis()->SetTitle("Cosine of Zenith in radians");















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
      SEL12_East_DATA_col[dd] = D;
      dd++;
    }

  while(infile5>>E)
    {
      SEL12_East_DATA_in1[ee] = E;
      ee++;
    }

  while(infile6>>F)
    {
      SEL12_East_DATA_in2[ff] = F;
      ff++;
    }



  while(infile7>>G)
    {
      SEL12_West_MC_col[gg] = G;
      gg++;

      cout<<SEL12_West_MC_col[gg]<<endl;

    }

  while(infile8>>H)
    {
      SEL12_West_MC_in1[hh] = H;
      hh++;
    }

  while(infile9>>I)
    {
      SEL12_West_MC_in2[ii] = I;
      ii++;
    }




  while(infile10>>J)
    {
      SEL12_West_DATA_col[jj] = J;
      jj++;
    }

  while(infile11>>K)
    {
      SEL12_West_DATA_in1[kk] = K;
      kk++;
    }

  while(infile12>>L)
    {
      SEL12_West_DATA_in2[ll] = L;
      ll++;
    }




  cout<<"TEST"<<endl;
  for(int aa2 = 0; aa2<aa; aa2++){

    z_SEL12_East_MC_col[aa2] =  abs( (TMath::Pi()/2.0) - SEL12_East_MC_col[aa2] );
    cout<<TMath::Cos(z_SEL12_East_MC_col[aa2])<<endl;
    h1->Fill(TMath::Cos(z_SEL12_East_MC_col[aa2]));
    cout<<TMath::Cos(z_SEL12_East_MC_col[aa2])<<endl;

    z60p_SEL12_East_MC_col[aa2] = (abs( (TMath::Pi()/2.0) - SEL12_East_MC_col[aa2]))+ (TMath::Pi()/3.0);
    cout<<TMath::Cos(z60p_SEL12_East_MC_col[aa2])<<endl;
    h1p->Fill(TMath::Cos(z60p_SEL12_East_MC_col[aa2]));
    cout<<TMath::Cos(z60p_SEL12_East_MC_col[aa2])<<endl;

    z60m_SEL12_East_MC_col[aa2] = (abs( (TMath::Pi()/2.0) - SEL12_East_MC_col[aa2])) - (TMath::Pi()/3.0);
    cout<<TMath::Cos(z60m_SEL12_East_MC_col[aa2])<<endl;
    h1m->Fill(TMath::Cos(z60m_SEL12_East_MC_col[aa2]));
    cout<<TMath::Cos(z60m_SEL12_East_MC_col[aa2])<<endl;

    cout<<TMath::Cos(z_SEL12_East_MC_col[aa2])<<" "<<TMath::Cos(z60p_SEL12_East_MC_col[aa2])<<" "<<TMath::Cos(z60m_SEL12_East_MC_col[aa2])<<endl;
  }



  for(int bb2 = 0; bb2<bb; bb2++){

    z_SEL12_East_MC_in1[bb2] =  abs( (TMath::Pi()/2.0) - SEL12_East_MC_in1[bb2] );
    h2->Fill(z_SEL12_East_MC_in1[bb2]);
    z60p_SEL12_East_MC_in1[bb2] =  (abs( (TMath::Pi()/2.0) - SEL12_East_MC_in1[bb2] )) + (TMath::Pi()/3.0) ;
    h2p->Fill(z60p_SEL12_East_MC_in1[bb2]);
    z60m_SEL12_East_MC_in1[bb2] =  (abs( (TMath::Pi()/2.0) - SEL12_East_MC_in1[bb2] )) - (TMath::Pi()/3.0) ;
    h2m->Fill(z60m_SEL12_East_MC_in1[bb2]);
  }


  for(int cc2 = 0; cc2<cc; cc2++){

    z_SEL12_East_MC_in2[cc2] =  abs( (TMath::Pi()/2.0) - SEL12_East_MC_in2[cc2] );
    h3->Fill(z_SEL12_East_MC_in2[cc2]);
    z60p_SEL12_East_MC_in2[cc2] =  (abs( (TMath::Pi()/2.0) - SEL12_East_MC_in2[cc2] )) + (TMath::Pi()/3.0) ;
    h3p->Fill(z60p_SEL12_East_MC_in2[cc2]);
    z60m_SEL12_East_MC_in2[cc2] =  (abs( (TMath::Pi()/2.0) - SEL12_East_MC_in2[cc2] )) - (TMath::Pi()/3.0) ;
    h3m->Fill(z60m_SEL12_East_MC_in2[cc2]);
  }




  for(int dd2 = 0; dd2<dd; dd2++){

    z_SEL12_East_DATA_col[dd2] =  abs( (TMath::Pi()/2.0) - SEL12_East_DATA_col[dd2] );
    h4->Fill(z_SEL12_East_DATA_col[dd2]);
    z60p_SEL12_East_DATA_col[dd2] = (abs(  (TMath::Pi()/2.0) - SEL12_East_DATA_col[dd2] )) + (TMath::Pi()/3.0) ;
    h4p->Fill(z60p_SEL12_East_DATA_col[dd2]);
    z60m_SEL12_East_DATA_col[dd2] = (abs(  (TMath::Pi()/2.0) - SEL12_East_DATA_col[dd2] )) - (TMath::Pi()/3.0) ;
    h4m->Fill(z60m_SEL12_East_DATA_col[dd2]);
  }



  for(int ee2 = 0; ee2<ee; ee2++){

    z_SEL12_East_DATA_in1[ee2] =  abs( (TMath::Pi()/2.0) - SEL12_East_DATA_in1[ee2] );
    h5->Fill(z_SEL12_East_DATA_in1[ee2]);
    z60p_SEL12_East_DATA_in1[ee2] =  (abs( (TMath::Pi()/2.0) - SEL12_East_DATA_in1[ee2] )) + (TMath::Pi()/3.0) ;
    h5p->Fill(z60p_SEL12_East_DATA_in1[ee2]);
    z60m_SEL12_East_DATA_in1[ee2] =  (abs( (TMath::Pi()/2.0) - SEL12_East_DATA_in1[ee2] )) - (TMath::Pi()/3.0) ;
    h5m->Fill(z60m_SEL12_East_DATA_in1[ee2]);
  }


  for(int ff2 = 0; ff2<ff; ff2++){

    z_SEL12_East_DATA_in2[ff2] =  abs( (TMath::Pi()/2.0) - SEL12_East_DATA_in2[ff2] );
    h6->Fill(z_SEL12_East_DATA_in2[ff2]);
    z60p_SEL12_East_DATA_in2[ff2] =  (abs( (TMath::Pi()/2.0) - SEL12_East_DATA_in2[ff2] )) + (TMath::Pi()/3.0) ;
    h6p->Fill(z60p_SEL12_East_DATA_in2[ff2]);
    z60m_SEL12_East_DATA_in2[ff2] =  (abs( (TMath::Pi()/2.0) - SEL12_East_DATA_in2[ff2] )) - (TMath::Pi()/3.0) ;
    h6m->Fill(z60m_SEL12_East_DATA_in2[ff2]);
  }



  for(int gg2 = 0; gg2<gg; gg2++){

    z_SEL12_West_MC_col[gg2] =  abs( (TMath::Pi()/2.0) - SEL12_West_MC_col[gg2] );
    h7->Fill(z_SEL12_West_MC_col[gg2]);
    z60p_SEL12_West_MC_col[gg2] =  (abs( (TMath::Pi()/2.0) - SEL12_West_MC_col[gg2] )) + (TMath::Pi()/3.0) ;
    h7p->Fill(z60p_SEL12_West_MC_col[gg2]);
    z60m_SEL12_West_MC_col[gg2] =  (abs( (TMath::Pi()/2.0) - SEL12_West_MC_col[gg2] )) - (TMath::Pi()/3.0) ;
    h7m->Fill(z60m_SEL12_West_MC_col[gg2]);
  }



  for(int hh2 = 0; hh2<hh; hh2++){

    z_SEL12_West_MC_in1[hh2] =  abs( (TMath::Pi()/2.0) - SEL12_West_MC_in1[hh2] );
    h8->Fill(z_SEL12_West_MC_in1[hh2]);
    z60p_SEL12_West_MC_in1[hh2] =  (abs( (TMath::Pi()/2.0) - SEL12_West_MC_in1[hh2] )) + (TMath::Pi()/3.0) ;
    h8p->Fill(z60p_SEL12_West_MC_in1[hh2]);
    z60m_SEL12_West_MC_in1[hh2] =  (abs( (TMath::Pi()/2.0) - SEL12_West_MC_in1[hh2] )) - (TMath::Pi()/3.0) ;
    h8m->Fill(z60m_SEL12_West_MC_in1[hh2]);
  }


  for(int ii2 = 0; ii2<ii; ii2++){

    z_SEL12_West_MC_in2[ii2] =  abs( (TMath::Pi()/2.0) - SEL12_West_MC_in2[ii2] );
    h9->Fill(z_SEL12_West_MC_in2[ii2]);
    z60p_SEL12_West_MC_in2[ii2] =  (abs( (TMath::Pi()/2.0) - SEL12_West_MC_in2[ii2] )) + (TMath::Pi()/3.0) ;
    h9p->Fill(z60p_SEL12_West_MC_in2[ii2]);
    z60m_SEL12_West_MC_in2[ii2] =  (abs( (TMath::Pi()/2.0) - SEL12_West_MC_in2[ii2] )) - (TMath::Pi()/3.0) ;
    h9m->Fill(z60m_SEL12_West_MC_in2[ii2]);
  }




  for(int jj2 = 0; jj2<jj; jj2++){

    z_SEL12_West_DATA_col[jj2] =  abs( (TMath::Pi()/2.0) - SEL12_West_DATA_col[jj2] );
    h10->Fill(z_SEL12_West_DATA_col[jj2]);
    z60p_SEL12_West_DATA_col[jj2] =  (abs( (TMath::Pi()/2.0) - SEL12_West_DATA_col[jj2] )) + (TMath::Pi()/3.0) ;
    h10p->Fill(z60p_SEL12_West_DATA_col[jj2]);
    z60m_SEL12_West_DATA_col[jj2] =  (abs( (TMath::Pi()/2.0) - SEL12_West_DATA_col[jj2] )) - (TMath::Pi()/3.0) ;
    h10m->Fill(z60m_SEL12_West_DATA_col[jj2]);
  }



  for(int kk2 = 0; kk2<kk; kk2++){

    z_SEL12_West_DATA_in1[kk2] =  abs( (TMath::Pi()/2.0) - SEL12_West_DATA_in1[kk2] );

    h11->Fill(z_SEL12_West_DATA_in1[kk2]);
    z60p_SEL12_West_DATA_in1[kk2] =  (abs( (TMath::Pi()/2.0) - SEL12_West_DATA_in1[kk2] ))+ (TMath::Pi()/3.0) ;
    h11p->Fill(z60p_SEL12_West_DATA_in1[kk2]);
    z60m_SEL12_West_DATA_in1[kk2] =  (abs( (TMath::Pi()/2.0) - SEL12_West_DATA_in1[kk2] )) - (TMath::Pi()/3.0) ;
    h11m->Fill(z60m_SEL12_West_DATA_in1[kk2]);
  }


  for(int ll2 = 0; ll2<ll; ll2++){

    z_SEL12_West_DATA_in2[ll2] =  abs( (TMath::Pi()/2.0) - SEL12_West_DATA_in2[ll2] );
    h12->Fill(z_SEL12_West_DATA_in2[ll2]);
    z60p_SEL12_West_DATA_in2[ll2] =  (abs( (TMath::Pi()/2.0) - SEL12_West_DATA_in2[ll2] )) + (TMath::Pi()/3.0) ;
    h12p->Fill(z60p_SEL12_West_DATA_in2[ll2]);
    z60m_SEL12_West_DATA_in2[ll2] =  (abs( (TMath::Pi()/2.0) - SEL12_West_DATA_in2[ll2] )) - (TMath::Pi()/3.0) ;
    h12m->Fill(z60m_SEL12_West_DATA_in2[ll2]);
  }
















  TCanvas* cnvs1= new TCanvas("cnvs1", "TPC0 East Cryostat MC",1,1,600,500);
  h1->Draw("HIST");
  TCanvas* cnvs1p= new TCanvas("cnvs1p", "TPC0 East Cryostat MC +60",1,1,600,500); 
  h1p->Draw("HIST");
  TCanvas* cnvs1m= new TCanvas("cnvs1m", "TPC0 East Cryostat MC -60",1,1,600,500); 
  h1m->Draw("HIST");


  TCanvas* cnvs2= new TCanvas("cnvs2", "TPC0 East Cryostat MC",1,1,600,500);
  h2->Draw("HIST");
  TCanvas* cnvs2p= new TCanvas("cnvs2p", "TPC0 East Cryostat MC +60",1,1,600,500);
  h2p->Draw("HIST");
  TCanvas* cnvs2m= new TCanvas("cnvs2m", "TPC0 East Cryostat MC -60",1,1,600,500);
  h2m->Draw("HIST");


  TCanvas* cnvs3= new TCanvas("cnvs3", "TPC0 East Cryostat MC",1,1,600,500);
  h3->Draw("HIST");
  TCanvas* cnvs3p= new TCanvas("cnvs3p", "TPC0 East Cryostat MC +60",1,1,600,500);
  h3p->Draw("HIST");
  TCanvas* cnvs3m= new TCanvas("cnvs3m", "TPC0 East Cryostat MC -60",1,1,600,500);
  h3m->Draw("HIST");


  TCanvas* cnvs4= new TCanvas("cnvs4", "TPC0 East Cryostat DATA",1,1,600,500);
  h4->Draw("HIST");
  TCanvas* cnvs4p= new TCanvas("cnvs4p", "TPC0 East Cryostat DATA +60",1,1,600,500);
  h4p->Draw("HIST");
  TCanvas* cnvs4m= new TCanvas("cnvs4m", "TPC0 East Cryostat DATA -60",1,1,600,500);
  h4m->Draw("HIST");


  TCanvas* cnvs5= new TCanvas("cnvs5", "TPC0 East Cryostat DATA",1,1,600,500);
  h5->Draw("HIST");
  TCanvas* cnvs5p= new TCanvas("cnvs5p", "TPC0 East Cryostat DATA +60",1,1,600,500);
  h5p->Draw("HIST");
  TCanvas* cnvs5m= new TCanvas("cnvs5m", "TPC0 East Cryostat DATA -60",1,1,600,500);
  h5m->Draw("HIST");


  TCanvas* cnvs6= new TCanvas("cnvs6", "TPC0 East Cryostat DATA",1,1,600,500);
  h6->Draw("HIST");
  TCanvas* cnvs6p= new TCanvas("cnvs6p", "TPC0 East Cryostat DATA +60",1,1,600,500);
  h6p->Draw("HIST");
  TCanvas* cnvs6m= new TCanvas("cnvs6m", "TPC0 East Cryostat DATA -60",1,1,600,500);
  h6m->Draw("HIST");

  TCanvas* cnvs7= new TCanvas("cnvs7", "TPC0 West Cryostat MC",1,1,600,500);
  h7->Draw("HIST");
  TCanvas* cnvs7p= new TCanvas("cnvs7p", "TPC0 West Cryostat MC +60",1,1,600,500);
  h7p->Draw("HIST");
  TCanvas* cnvs7m= new TCanvas("cnvs7m", "TPC0 West Cryostat MC -60",1,1,600,500);
  h7m->Draw("HIST");


  TCanvas* cnvs8= new TCanvas("cnvs8", "TPC0 West Cryostat MC",1,1,600,500);
  h8->Draw("HIST");
  TCanvas* cnvs8p= new TCanvas("cnvs8p", "TPC0 West Cryostat MC +60",1,1,600,500);
  h8p->Draw("HIST");
  TCanvas* cnvs8m= new TCanvas("cnvs8m", "TPC0 West Cryostat MC -60",1,1,600,500);
  h8m->Draw("HIST");


  TCanvas* cnvs9= new TCanvas("cnvs9", "TPC0 West Cryostat MC",1,1,600,500);
  h9->Draw("HIST");
  TCanvas* cnvs9p= new TCanvas("cnvs9p", "TPC0 West Cryostat MC +60",1,1,600,500);
  h9p->Draw("HIST");
  TCanvas* cnvs9m= new TCanvas("cnvs9m", "TPC0 West Cryostat MC -60",1,1,600,500);
  h9m->Draw("HIST");


  TCanvas* cnvs10= new TCanvas("cnvs10", "TPC0 West Cryostat DATA",1,1,600,500);
  h10->Draw("HIST");
  TCanvas* cnvs10p= new TCanvas("cnvs10p", "TPC0 West Cryostat DATA +60",1,1,600,500);
  h10p->Draw("HIST");
  TCanvas* cnvs10m= new TCanvas("cnvs10m", "TPC0 West Cryostat DATA -60",1,1,600,500);
  h10m->Draw("HIST");


  TCanvas* cnvs11= new TCanvas("cnvs11", "TPC0 West Cryostat DATA",1,1,600,500);
  h11->Draw("HIST");
  TCanvas* cnvs11p= new TCanvas("cnvs11p", "TPC0 West Cryostat DATA +60",1,1,600,500);
  h11p->Draw("HIST");
  TCanvas* cnvs11m= new TCanvas("cnvs11m", "TPC0 West Cryostat DATA -60",1,1,600,500);
  h11m->Draw("HIST");


  TCanvas* cnvs12= new TCanvas("cnvs12", "TPC0 West Cryostat DATA",1,1,600,500);
  h12->Draw("HIST");
  TCanvas* cnvs12p= new TCanvas("cnvs12p", "TPC0 West Cryostat DATA +60",1,1,600,500);
  h12p->Draw("HIST");
  TCanvas* cnvs12m= new TCanvas("cnvs12m", "TPC0 West Cryostat DATA -60",1,1,600,500);
  h12m->Draw("HIST");



   cnvs1->SaveAs("MC_tpc0_sel12_East_file_ZenithAngle_col_NEW.pdf");
  cnvs1p->SaveAs("MC_tpc0_sel12_East_file_ZenithAngle_col_60p_NEW.pdf");
  cnvs1m->SaveAs("MC_tpc0_sel12_East_file_ZenithAngle_col_60m_NEW.pdf");

  cnvs2->SaveAs("MC_tpc0_sel12_East_file_ZenithAngle_in1_NEW.pdf");
  cnvs2p->SaveAs("MC_tpc0_sel12_East_file_ZenithAngle_in1_60p_NEW.pdf");
  cnvs2m->SaveAs("MC_tpc0_sel12_East_file_ZenithAngle_in1_60m_NEW.pdf");

  cnvs3->SaveAs("MC_tpc0_sel12_East_file_ZenithAngle_in2_NEW.pdf");
  cnvs3p->SaveAs("MC_tpc0_sel12_East_file_ZenithAngle_in2_60p_NEW.pdf");
  cnvs3m->SaveAs("MC_tpc0_sel12_East_file_ZenithAngle_in2_60m_NEW.pdf");

  cnvs4->SaveAs("DATA_tpc0_sel12_East_file_ZenithAngle_col_NEW.pdf");
  cnvs4p->SaveAs("DATA_tpc0_sel12_East_file_ZenithAngle_col_60p_NEW.pdf");
  cnvs4m->SaveAs("DATA_tpc0_sel12_East_file_ZenithAngle_col_60m_NEW.pdf");

  cnvs5->SaveAs("DATA_tpc0_sel12_East_file_ZenithAngle_in1_NEW.pdf");
  cnvs5p->SaveAs("DATA_tpc0_sel12_East_file_ZenithAngle_in1_60p_NEW.pdf");
  cnvs5m->SaveAs("DATA_tpc0_sel12_East_file_ZenithAngle_in1_60m_NEW.pdf");

  cnvs6->SaveAs("DATA_tpc0_sel12_East_file_ZenithAngle_in2_NEW.pdf");
  cnvs6p->SaveAs("DATA_tpc0_sel12_East_file_ZenithAngle_in2_60p_NEW.pdf");
  cnvs6m->SaveAs("DATA_tpc0_sel12_East_file_ZenithAngle_in2_60m_NEW.pdf");

  cnvs7->SaveAs("MC_tpc0_sel12_West_file_ZenithAngle_col_NEW.pdf");
  cnvs7p->SaveAs("MC_tpc0_sel12_West_file_ZenithAngle_col_60p_NEW.pdf");
  cnvs7m->SaveAs("MC_tpc0_sel12_West_file_ZenithAngle_col_60m_NEW.pdf");

  cnvs8->SaveAs("MC_tpc0_sel12_West_file_ZenithAngle_in1_NEW.pdf");
  cnvs8p->SaveAs("MC_tpc0_sel12_West_file_ZenithAngle_in1_60p_NEW.pdf");
  cnvs8m->SaveAs("MC_tpc0_sel12_West_file_ZenithAngle_in1_60m_NEW.pdf");

  cnvs9->SaveAs("MC_tpc0_sel12_West_file_ZenithAngle_in2_NEW.pdf");
  cnvs9p->SaveAs("MC_tpc0_sel12_West_file_ZenithAngle_in2_60p_NEW.pdf");
  cnvs9m->SaveAs("MC_tpc0_sel12_West_file_ZenithAngle_in2_60m_NEW.pdf");

  cnvs10->SaveAs("DATA_tpc0_sel12_West_file_ZenithAngle_col_NEW.pdf");
  cnvs10p->SaveAs("DATA_tpc0_sel12_West_file_ZenithAngle_col_60p_NEW.pdf");
  cnvs10m->SaveAs("DATA_tpc0_sel12_West_file_ZenithAngle_col_60m_NEW.pdf");

  cnvs11->SaveAs("DATA_tpc0_sel12_West_file_ZenithAngle_in1_NEW.pdf");
  cnvs11p->SaveAs("DATA_tpc0_sel12_West_file_ZenithAngle_in1_60p_NEW.pdf");
  cnvs11m->SaveAs("DATA_tpc0_sel12_West_file_ZenithAngle_in1_60m_NEW.pdf");

  cnvs12->SaveAs("DATA_tpc0_sel12_West_file_ZenithAngle_in2_NEW.pdf");
  cnvs12p->SaveAs("DATA_tpc0_sel12_West_file_ZenithAngle_in2_60p_NEW.pdf");
  cnvs12m->SaveAs("DATA_tpc0_sel12_West_file_ZenithAngle_in2_60m_NEW.pdf");

 

  }
