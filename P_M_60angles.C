void P_M_60angles(){

  gStyle->SetOptStat(0);

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
   double E0i[5000];
   double E1i[5000];
   double E2i[5000];
   double E3i[5000];
   double W0i[5000];
   double W1i[5000];
   double W2i[5000];
   double W3i[5000];

   double E0p[5000];
   double W0p[5000];
   double E0m[5000];
   double W0m[5000];
   double E1p[5000];
   double W1p[5000];
   double E1m[5000];
   double W1m[5000];
   double E2p[5000];
   double W2p[5000];
   double E2m[5000];
   double W2m[5000];
   double E3p[5000];
   double W3p[5000];
   double E3m[5000];
   double W3m[5000];

   ifstream infile1("noCOSangle_by_in1_E_tpc0.txt");
   ifstream infile2("noCOSangle_by_in1_W_tpc0.txt");
   ifstream infile3("noCOSangle_by_in1_E_tpc1.txt");
   ifstream infile4("noCOSangle_by_in1_W_tpc1.txt");
   ifstream infile5("noCOSangle_by_in1_E_tpc2.txt");
   ifstream infile6("noCOSangle_by_in1_W_tpc2.txt");
   ifstream infile7("noCOSangle_by_in1_E_tpc3.txt");
   ifstream infile8("noCOSangle_by_in1_W_tpc3.txt");

   ofstream o1("E_tpc0_plus.txt");
   ofstream o2("E_tpc0_minus.txt");


   TH1F *h1p = new TH1F("h1p","TPC0 East Cryostat MC (P) ", 100., 0.0, 5.0);
   h1p->GetXaxis()->SetTitle("angle (radians)");

   TH1F *h2p = new TH1F("h2p","TPC0 West Cryostat MC (P) ", 100., 0.0, 5.0);
   h2p->GetXaxis()->SetTitle("angle (radians)");

   TH1F *h1m = new TH1F("h1m","TPC0 East Cryostat MC (M) ", 100., -2.0, 3.0); 
   h1m->GetXaxis()->SetTitle("angle (radians)");

   TH1F *h2m = new TH1F("h2m","TPC0 West Cryostat MC (M) ", 100., -2.0, 3.0);
   h2m->GetXaxis()->SetTitle("angle (radians)");

   TH1F *h3p = new TH1F("h3p","TPC1 East Cryostat MC (P) ", 100., 0.0, 5.0);
   h3p->GetXaxis()->SetTitle("angle (radians)");

   TH1F *h4p = new TH1F("h4p","TPC1 West Cryostat MC (P) ", 100., 0.0, 5.0);
   h4p->GetXaxis()->SetTitle("angle (radians)");

   TH1F *h3m = new TH1F("h3m","TPC1 East Cryostat MC (M) ", 100., -2.0, 3.0);
   h3m->GetXaxis()->SetTitle("angle (radians)");

   TH1F *h4m = new TH1F("h4m","TPC1 West Cryostat MC (M) ", 100., -2.0, 3.0);
   h4m->GetXaxis()->SetTitle("angle (radians)");

   TH1F *h5p = new TH1F("h5p","TPC2 East Cryostat MC (P) ", 100., 0.0, 5.0);
   h5p->GetXaxis()->SetTitle("angle (radians)");

   TH1F *h6p = new TH1F("h6p","TPC2 West Cryostat MC (P) ", 100., 0.0, 5.0);
   h6p->GetXaxis()->SetTitle("angle (radians)");

   TH1F *h5m = new TH1F("h5m","TPC2 East Cryostat MC (M) ", 100., -2.0, 3.0);
   h5m->GetXaxis()->SetTitle("angle (radians)");

   TH1F *h6m = new TH1F("h6m","TPC2 West Cryostat MC (M) ", 100., -2.0, 3.0);
   h6m->GetXaxis()->SetTitle("angle (radians)");

   TH1F *h7p = new TH1F("h7p","TPC3 East Cryostat MC (P) ", 100., 0.0, 5.0);
   h7p->GetXaxis()->SetTitle("angle (radians)");

   TH1F *h8p = new TH1F("h8p","TPC3 West Cryostat MC (P) ", 100., 0.0, 5.0);
   h8p->GetXaxis()->SetTitle("angle (radians)");

   TH1F *h7m = new TH1F("h7m","TPC3 East Cryostat MC (M) ", 100., -2.0, 3.0);
   h7m->GetXaxis()->SetTitle("angle (radians)");

   TH1F *h8m = new TH1F("h8m","TPC3 West Cryostat MC (M) ", 100., -2.0, 3.0);
   h8m->GetXaxis()->SetTitle("angle (radians)");

   cout<<"HERE"<<endl;

   while(infile1>>Et0)
     {
       E0i[E0] = Et0;
       //       cout<<E0<<endl;
       E0++;
       //cout<<E0<<endl;
     }

   while(infile2>>Wt0)
     {
       W0i[W0] = Wt0;
       W0++;
     }

   while(infile3>>Et1)
     {
       E1i[E1] = Et1;
       E1++;
     }

   while(infile4>>Wt1)
     {
       W1i[W1] = Wt1;
       W1++;
     }


   while(infile5>>Et2)
     {
       E2i[E2] = Et2;
       E2++;
     }

   while(infile6>>Wt2)
     {
       W2i[W2] = Wt2;
       W2++;
     }


   while(infile7>>Et3)
     {
       E3i[E3] = Et3;
       E3++;
     }

   while(infile8>>Wt3)
     {
       W3i[W3] = Wt3;
       W3++;
     }





   for(int n0 = 0; n0<E0; n0++){

     E0p[n0] = E0i[n0] + TMath::Pi()/(3.0);
     E0m[n0] = E0i[n0] - TMath::Pi()/(3.0);
     cout<<  E0p[n0]<<" "<<  E0m[n0]<<endl;

     h1p->Fill(E0p[n0]);
     h1m->Fill(E0m[n0]);
   }

   for(int m0 = 0; m0<W0; m0++){

     W0p[m0] = W0i[m0] + TMath::Pi()/(3.0);
     W0m[m0] = W0i[m0] - TMath::Pi()/(3.0);
     h2p->Fill(W0p[m0]);
     h2m->Fill(W0m[m0]);
   }




   for(int n1 = 0; n1<E1; n1++){

     E1p[n1] = E1i[n1] + TMath::Pi()/(3.0);
     E1m[n1] = E1i[n1] - TMath::Pi()/(3.0);

     o1<<E1p[n1]<<endl;
     o2<<E1m[n1]<<endl;
     h3p->Fill(E1p[n1]);
     h3m->Fill(E1m[n1]);
   }

   for(int m1 = 0; m1<W1; m1++){

     W1p[m1] = W1i[m1] + TMath::Pi()/(3.0);
     W1m[m1] = W1i[m1] - TMath::Pi()/(3.0);
     h4p->Fill(W1p[m1]);
     h4m->Fill(W1m[m1]);
   }



   for(int n2 = 0; n2<E2; n2++){

     E2p[n2] = E2i[n2] + TMath::Pi()/(3.0);
     E2m[n2] = E2i[n2] - TMath::Pi()/(3.0);
     h5p->Fill(E2p[n2]);
     h5m->Fill(E2m[n2]);
   }

   for(int m2 = 0; m2<W2; m2++){

     W2p[m2] = W2i[m2] + TMath::Pi()/(3.0);
     W2m[m2] = W2i[m2] - TMath::Pi()/(3.0);
     h6p->Fill(W2p[m2]);
     h6m->Fill(W2m[m2]);
   }

   for(int n3 = 0; n3<E3; n3++){

     E3p[n3] = E3i[n3] + TMath::Pi()/(3.0);
     E3m[n3] = E3i[n3] - TMath::Pi()/(3.0);
     h7p->Fill(E3p[n3]);
     h7m->Fill(E3m[n3]);
   }

   for(int m3 = 0; m3<W3; m3++){

     W3p[m3] = W3i[m3] + TMath::Pi()/(3.0);
     W3m[m3] = W3i[m3] - TMath::Pi()/(3.0);
     h8p->Fill(W3p[m3]);
     h8m->Fill(W3m[m3]);
   }







   TCanvas* cnvs1p= new TCanvas("cnvs1p", "TPC0 East Cryostat MC Plus",1,1,600,500);
   h1p->Draw("HIST");
   TCanvas* cnvs2p= new TCanvas("cnvs2p", "TPC0 West Cryostat MC Plus",1,1,600,500);
   h2p->Draw("HIST");
   TCanvas* cnvs3p= new TCanvas("cnvs3p", "TPC1 East Cryostat MC Plus",1,1,600,500);
   h3p->Draw("HIST");
   TCanvas* cnvs4p= new TCanvas("cnvs4p", "TPC1 West Cryostat MC Plus",1,1,600,500);
   h4p->Draw("HIST");
   TCanvas* cnvs5p= new TCanvas("cnvs5p", "TPC2 East Cryostat MC Plus",1,1,600,500);
   h5p->Draw("HIST");
   TCanvas* cnvs6p= new TCanvas("cnvs6p", "TPC2 West Cryostat MC Plus",1,1,600,500);
   h6p->Draw("HIST");
   TCanvas* cnvs7p= new TCanvas("cnvs7p", "TPC3 East Cryostat MC Plus",1,1,600,500);
   h7p->Draw("HIST");
   TCanvas* cnvs8p= new TCanvas("cnvs8p", "TPC3 West Cryostat MC Plus",1,1,600,500);
   h8p->Draw("HIST");
   TCanvas* cnvs1m= new TCanvas("cnvs1m", "TPC0 East Cryostat MC Minus",1,1,600,500);
   h1m->Draw("HIST");
   TCanvas* cnvs2m= new TCanvas("cnvs2m", "TPC0 West Cryostat MC Minus",1,1,600,500);
   h2m->Draw("HIST");
   TCanvas* cnvs3m= new TCanvas("cnvs3m", "TPC1 East Cryostat MC Minus",1,1,600,500);
   h3m->Draw("HIST");
   TCanvas* cnvs4m= new TCanvas("cnvs4m", "TPC1 West Cryostat MC Minus",1,1,600,500);
   h4m->Draw("HIST");
   TCanvas* cnvs5m= new TCanvas("cnvs5m", "TPC2 East Cryostat MC Minus",1,1,600,500);
   h5m->Draw("HIST");
   TCanvas* cnvs6m= new TCanvas("cnvs6m", "TPC2 West Cryostat MC Minus",1,1,600,500);
   h6m->Draw("HIST");
   TCanvas* cnvs7m= new TCanvas("cnvs7m", "TPC3 East Cryostat MC Minus",1,1,600,500);
   h7m->Draw("HIST");
   TCanvas* cnvs8m= new TCanvas("cnvs8m", "TPC3 West Cryostat MC Minus",1,1,600,500);
   h8m->Draw("HIST");

   cnvs1p->SaveAs("b_MC_tpc0_sel12_East_file_angle_PLUS.pdf");
   cnvs2p->SaveAs("b_MC_tpc0_sel12_West_file_angle_PLUS.pdf");
   cnvs3p->SaveAs("b_MC_tpc1_sel12_East_file_angle_PLUS.pdf");
   cnvs4p->SaveAs("b_MC_tpc1_sel12_West_file_angle_PLUS.pdf");
   cnvs5p->SaveAs("b_MC_tpc2_sel12_East_file_angle_PLUS.pdf");
   cnvs6p->SaveAs("b_MC_tpc2_sel12_West_file_angle_PLUS.pdf");
   cnvs7p->SaveAs("b_MC_tpc3_sel12_East_file_angle_PLUS.pdf");
   cnvs8p->SaveAs("b_MC_tpc3_sel12_West_file_angle_PLUS.pdf");


   cnvs1m->SaveAs("b_MC_tpc0_sel12_East_file_angle_MINUS.pdf");
   cnvs2m->SaveAs("b_MC_tpc0_sel12_West_file_angle_MINUS.pdf");
   cnvs3m->SaveAs("b_MC_tpc1_sel12_East_file_angle_MINUS.pdf");
   cnvs4m->SaveAs("b_MC_tpc1_sel12_West_file_angle_MINUS.pdf");
   cnvs5m->SaveAs("b_MC_tpc2_sel12_East_file_angle_MINUS.pdf");
   cnvs6m->SaveAs("b_MC_tpc2_sel12_West_file_angle_MINUS.pdf");
   cnvs7m->SaveAs("b_MC_tpc3_sel12_East_file_angle_MINUS.pdf");
   cnvs8m->SaveAs("b_MC_tpc3_sel12_West_file_angle_MINUS.pdf");

}
