#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

void Az_angle() {


   TCanvas* cnvs = new TCanvas("cnvs", "c1", 1,1,800,700);
 
  THStack *hs = new THStack("hs","");
 
  // Create a histograms for the values we read.
   TH1F *myHist = new TH1F("myHist","Relative Frequency vs  Azimuthal Angle: East Cryostat", 100., 0., 1.6);
   myHist->GetXaxis()->SetTitle(" Azimuthal Angle in radians ");
   myHist->GetYaxis()->SetTitle("Relative Frequency");
 
  TH1F *myHist2 = new TH1F("myHist2","Relative Frequency vs Azimuthal Angle: East Cryostat", 100., 0., 1.6);
 
   gStyle->SetOptStat(0);

   //Get the files from ICARUS gpvm
TFileCollection *my_files = new TFileCollection("my_files","My File List");
 my_files->Add("/pnfs/icarus/persistent/calibration/calib_ntuples/mc/ICARUS_NuMI_Nu_Cosmics/hist*.root");

std::cout << "Number of files in our MC list is " << my_files->GetNFiles() << std::endl;
TFileCollection *my_files2 = new TFileCollection("my_files2","My File List2");
 my_files2->Add("/pnfs/icarus/persistent/calibration/calib_ntuples/data/hist_data_dl4_fstrmNUMI*.root");
std::cout << "Number of files in our data list is " << my_files2->GetNFiles() << std::endl;


TChain myfile("caloskimE/TrackCaloSkim");

TChain myfile2("caloskimE/TrackCaloSkim");

 myfile.AddFileInfoList(my_files->GetList());

 myfile2.AddFileInfoList(my_files2->GetList());

 //delcare variables
 TTreeReader myReader(&myfile);
 TTreeReader myReader2(&myfile2);
   
   TTreeReaderValue<int> selected(myReader, "trk.selected");
   TTreeReaderValue<int> selected2(myReader2, "trk.selected");
 
   TTreeReaderValue<float> startX(myReader, "trk.start.x");
   TTreeReaderValue<float> startX2(myReader2, "trk.start.x");

   TTreeReaderValue<float> endX(myReader, "trk.end.x");
   TTreeReaderValue<float> endX2(myReader2, "trk.end.x");

   TTreeReaderArray<float> dqdx(myReader, "trk.hits0.dqdx");
   TTreeReaderArray<float> dqdx2(myReader2, "trk.hits0.dqdx");
 
   TTreeReaderArray<float> rr(myReader, "trk.hits0.rr");
   TTreeReaderArray<float> rr2(myReader2, "trk.hits0.rr");
 
  TTreeReaderArray<float> z_i1(myReader, "trk.hits0.dir.z");
  TTreeReaderArray<float> z2_i1(myReader2, "trk.hits0.dir.z");
  
  TTreeReaderArray<float> y_i1(myReader, "trk.hits0.dir.y");
  TTreeReaderArray<float> y2_i1(myReader2, "trk.hits0.dir.y");
 
  TTreeReaderArray<float> x_i1(myReader, "trk.hits0.dir.x");
  TTreeReaderArray<float> x2_i1(myReader2, "trk.hits0.dir.x");
 
  TTreeReaderArray<float> z_i2(myReader, "trk.hits1.dir.z");
  TTreeReaderArray<float> z2_i2(myReader2, "trk.hits1.dir.z");
  
  TTreeReaderArray<float> y_i2(myReader, "trk.hits1.dir.y");
  TTreeReaderArray<float> y2_2(myReader2, "trk.hits1.dir.y");
  
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

   double num = 0.0;
   double num2 = 0.0;
   int aa = 0;
   int j = 0;
   int k = 0;
   double angle[52000];
   double angle2[52000];


   //MC Azimuthal Angle
   while (myReader.Next()) {
     if (*selected == 0) { // Tracks selected as stopping
	int a = y_c.GetSize();
          for (unsigned i = 0; i < y_c.GetSize(); i++) {
            num = x_c[i]/z_c[i];//collection plane

	    angle[i] = TMath::ATan(num);
	    if(i == (a-1)){

	      if(ontraj_c[i]==1){
	      
		    myHist->Fill(angle[i]);
		    cout<<"MC angle "<<angle[i]<<endl;

	  
	      }
	   
	    }
	  }
	 
     }
          
   }

   //normalizing MC distribution
   TH1*h1 = (TH1*)(myHist->Clone("h1"));
   h1->Scale(1./h1->Integral());


   //Data Azimuthal Angle
 while (myReader2.Next()) {
   if (*selected2 == 0){// Tracks selected as stopping
     int b = y2_c.GetSize();
		for (unsigned j = 0; j < y2_c.GetSize(); j++) {
		  num2 = x2_c[j]/z2_c[j];//collection plane
		  angle2[j] = TMath::ATan(num2);
		  if(j == (b-1)){

		    if(ontraj2_c[j]==1){	
		      myHist2->Fill(angle2[j]);
		      cout<<"data angle "<<angle2[j]<<endl;

	  

		    }	   
		  }

		}
	 
   }
          
 }
 
   //normalizing data distribution
   TH1*h2 = (TH2*)(myHist2->Clone("h2"));
   h2->Scale(1./h2->Integral());

   //drawing distribtions
   h1->SetLineColor(kRed);
   h2->SetLineColor(kBlue);
   hs->Add(h2);
   hs->Add(h1);

   hs->Draw("nostackHIST");
   cnvs->Update();
   hs->GetXaxis()->SetTitle(" Azimuthal Angle in radians ");
   hs->GetYaxis()->SetTitle("Relative Frequency");
   TText T; T.SetTextFont(42); T.SetTextAlign(21);
   T.DrawTextNDC(.5,.95,"Relative Frequency vs Azimuthal Angle: East Cryostat");

   auto legend = new TLegend(0.1,0.8,0.2,0.9);
   legend->AddEntry(h1,"MC");
   legend->AddEntry(h2,"Data");
   legend->Draw();


}
