#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "sbnobj/Common/Calibration/TrackCaloSkimmerObj.h"



void Sept_angle_E_MAY2023_MConly(bool verbose=false) {


  gStyle->SetOptStat(0);
  ofstream outfile("t.txt");
  ofstream outfile_col_mc_xyz("mcAUG2023_NUMI_tpc0_sel12_East_file_xyz_col.txt");
  ofstream outfile_in2_mc_xyz("mcAUG2023_NUMI_tpc0_sel12_East_file_xyz_in2.txt");
  ofstream outfile_in1_mc_xyz("mcAUG2023_NUMI_tpc0_sel12_East_file_xyz_in1.txt");

  ofstream outfile_dqdxc("AUG2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_Qdx_col.txt");
  ofstream outfile_dqdx1("AUG2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_Qdx_in1.txt");
  ofstream outfile_dqdx2("AUG2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_Qdx_in2.txt");

  ofstream outfile_intc("AUG2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_HC_col.txt");
  ofstream outfile_int1("AUG2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_HC_in1.txt");
  ofstream outfile_int2("AUG2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_HC_in2.txt");


  ofstream outfile1("hnoCOSangle_by_AUG2023__col_E_tpc0.txt");
  ofstream outfile2("hnoCOSangle_by_AUG2023__in1_E_tpc0.txt");
  ofstream outfile3("hnoCOSangle_by_AUG2023__in2_E_tpc0.txt");
  
  ofstream outT("AUG2023.txt");
  double z_p = 1.0;
  double Pi = 3.1415926535897932384;
  int n = 8000;

  double X_SEL12_East_MC_col[n];
  double X_SEL12_East_MC_in1[n];
  double X_SEL12_East_MC_in2[n];

  double Y_SEL12_East_MC_col[n];
  double Y_SEL12_East_MC_in1[n];
  double Y_SEL12_East_MC_in2[n];

  double Z_SEL12_East_MC_col[n];
  double Z_SEL12_East_MC_in1[n];
  double Z_SEL12_East_MC_in2[n];



  double ref_angle_col[n];// = 0.0                                                                      \
                                                                                                                      
  double ref_angle_in1[n];// = .0                                                                      \
                                                                                                                      
  double ref_angle_in2[n];// = 0.0                                                                      


  double nc=0.0;
  double ni1=0.0;
  double ni2=0.0;








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


  TH1F *h2p = new TH1F("h2p","TPC0 East Cryostat MC (IN1) ", 100., 0.0, 2.0); //0., 7.0);                                                                                                                                                  
  h2p->GetXaxis()->SetTitle("angle in radians");

  TH1F *h3p = new TH1F("h3p","TPC0 East Cryostat MC (IN2) ", 100., 0.0, 2.0); //0., 7.0);                                                                                                                                                
  h3p->GetXaxis()->SetTitle("angle in radians");


  TH1F *h1pDQ = new TH1F("h1pDQ","TPC0 East Cryostat MC (COL) ", 100., 100.0, 1000.0); //0., 7.0);                            
                                                                                                                      
  h1p->GetXaxis()->SetTitle("dQ/dX");


  TH1F *h2pDQ = new TH1F("h2pDQ","TPC0 East Cryostat MC (IN1) ", 100., 100.0, 1000.0); //0., 7.0);                            
                                                                                                                     
                                                                                                                      
  h2p->GetXaxis()->SetTitle("dQ/dX");

  TH1F *h3pDQ = new TH1F("h3pDQ","TPC0 East Cryostat MC (IN2) ", 100., 100.0, 1000.0); //0., 7.0);                           
                                                                                                                      
  h3p->GetXaxis()->SetTitle("dQ/dX");


   //Get the files from ICARUS gpvm
  TFileCollection *my_files = new TFileCollection("my_files","My File List");

  my_files->AddFromFile("mc_april22versiontest2.txt");//mc_aprilversion.txt");
 outfile<< "Number of files in our MC list is " << my_files->GetNFiles() <<endl;
  TChain myfile("caloskimE/TrackCaloSkim");
  myfile.AddFileInfoList(my_files->GetList());


  cout<<"files read"<<endl;

  //delcare variables
  TTreeReader myReader(&myfile);
  
  TTreeReaderValue<int> selected(myReader, "trk.selected");
  TTreeReaderValue<float> startX(myReader, "trk.start.x");
  
  TTreeReaderValue<float> startY(myReader, "trk.start.y");

  TTreeReaderValue<float> startZ(myReader, "trk.start.z");

  TTreeReaderValue<float> endX(myReader, "trk.end.x");
  TTreeReaderValue<float> endY(myReader, "trk.end.y");
  TTreeReaderValue<float> endZ(myReader, "trk.end.z");
  TTreeReaderValue<int> run(myReader, "trk.meta.run");
  TTreeReaderValue<int> event(myReader, "trk.meta.evt");  
  TTreeReaderArray<float> dqdx_i1(myReader, "trk.hits0.dqdx");
  TTreeReaderArray<float> dqdx_c(myReader, "trk.hits2.dqdx");                                                        
  TTreeReaderArray<float> dqdx_i2(myReader, "trk.hits1.dqdx");
  TTreeReaderArray<float> rr_c(myReader, "trk.hits2.rr");
  TTreeReaderArray<float> rr_i2(myReader, "trk.hits1.rr");
  TTreeReaderArray<float> rr_i1(myReader, "trk.hits0.rr");
  TTreeReaderArray<float> z_i1(myReader, "trk.hits0.dir.z");
  TTreeReaderArray<float> y_i1(myReader, "trk.hits0.dir.y");
  TTreeReaderArray<float> x_i1(myReader, "trk.hits0.dir.x");
  TTreeReaderArray<float> z_i2(myReader, "trk.hits1.dir.z");
  TTreeReaderArray<float> y_i2(myReader, "trk.hits1.dir.y");
  TTreeReaderArray<float> x_i2(myReader, "trk.hits1.dir.x");
  TTreeReaderArray<float> z_c(myReader, "trk.hits2.dir.z");
  TTreeReaderArray<float> y_c(myReader, "trk.hits2.dir.y");
  TTreeReaderArray<float> x_c(myReader, "trk.hits2.dir.x");
  TTreeReaderArray<bool> ontraj_c(myReader, "trk.hits2.ontraj");
  TTreeReaderArray<bool> ontraj_i2(myReader, "trk.hits1.ontraj");
  TTreeReaderArray<bool> ontraj_i1(myReader, "trk.hits0.ontraj");
  TTreeReaderValue<float> length(myReader, "trk.length");
  TTreeReaderValue<float> t0(myReader, "trk.t0");
  TTreeReaderArray<float> integral_c(myReader, "trk.hits2.h.integral");
  TTreeReaderArray<float> integral_i2(myReader, "trk.hits1.h.integral");
  TTreeReaderArray<float> integral_i1(myReader, "trk.hits0.h.integral");
  TTreeReaderArray<float> width_c(myReader, "trk.hits2.h.width");
  TTreeReaderArray<float> width_i2(myReader, "trk.hits1.h.width");
  TTreeReaderArray<float> width_i1(myReader, "trk.hits0.h.width");
  TTreeReaderArray<uint16_t> tpc_c(myReader, "trk.hits2.h.tpc");
  TTreeReaderArray<uint16_t> tpc_i2(myReader, "trk.hits1.h.tpc");
  TTreeReaderArray<uint16_t> tpc_i1(myReader, "trk.hits0.h.tpc");
  TTreeReaderArray<uint16_t> wire_c(myReader, "trk.hits2.h.wire");
  TTreeReaderArray<uint16_t> wire_i2(myReader, "trk.hits1.h.wire");
  TTreeReaderArray<uint16_t> wire_i1(myReader, "trk.hits0.h.wire");
  TTreeReaderArray<float> time_c(myReader, "trk.hits2.h.time");
  TTreeReaderArray<float> time_i2(myReader, "trk.hits1.h.time");
  TTreeReaderArray<float> time_i1(myReader, "trk.hits0.h.time");
  TTreeReaderArray<float> pitch_c(myReader, "trk.hits2.pitch");
  TTreeReaderArray<float> pitch_i2(myReader, "trk.hits1.pitch");
  TTreeReaderArray<float> pitch_i1(myReader, "trk.hits0.pitch");
  
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

     outfile_col_mc_xyz<<x_c[last_h_mc_c]<<" "<<y_c[last_h_mc_c]<<" "<<z_c[last_h_mc_c]<<endl;
    

     X_SEL12_East_MC_col[last_h_mc_c] = x_c[last_h_mc_c];
     Y_SEL12_East_MC_col[last_h_mc_c] = y_c[last_h_mc_c];
     Z_SEL12_East_MC_col[last_h_mc_c] = z_c[last_h_mc_c];

     //????
     double sum_integral_mc_c = 0.0;
     double sum_dqdx_mc_c =0.0;
     for(int i = 0; i < last_h_mc_c; i++){
       sum_integral_mc_c += integral_c[i];
       sum_dqdx_mc_c += dqdx_c[i];
     }

     double av_integral_mc_c = sum_integral_mc_c/last_h_mc_c;
     double av_dqdx_mc_c = sum_dqdx_mc_c/last_h_mc_c;
     double AVG_int_col[last_h_mc_c];
     double AVG_dqdx_col[last_h_mc_c];
     outfile_dqdxc<<av_dqdx_mc_c<<endl;
     outfile_intc<<av_integral_mc_c<<endl;

     AVG_int_col[last_h_mc_c] = av_dqdx_mc_c;
     //outfile_dqdxc<<AVG_int_col[last_h_mc_c]<<endl;

     int alpha = last_h_mc_c;
     //     for(int alpha = 0; alpha<nc; alpha++){
 
      //     outT<<n<<endl;  

                                                                                          
       ref_angle_col[alpha] = 0.0;
       
       angle_by_col_E[alpha] = TMath::ACos( (  (Z_SEL12_East_MC_col[alpha]*z_p) ) / ( sqrt(X_SEL12_East_MC_col[alpha]*X_SEL12_East_MC_col[alpha]+ Y_SEL12_East_MC_col[alpha]*Y_SEL12_East_MC_col[alpha]+Z_SEL12_East_MC_col[alpha]*Z_SEL12_East_MC_col[alpha]) * sqrt( (z_p*z_p) ) ) );
       //ref_angle_col[alpha] = 0.0;
       cout<<angle_by_col_E[alpha]<<endl;
       cout<<((Pi)/2.0)<<endl;
       if( (angle_by_col_E[alpha] > ((Pi)/2.0)) && (angle_by_col_E[alpha] < (Pi) ) ){
	 ref_angle_col[alpha] = (Pi) - angle_by_col_E[alpha];
	 outfile1<<ref_angle_col[alpha]<<endl;//(Pi) - angle_by_col_E[alpha]<<endl;                                     
	 h1p->Fill((Pi) - angle_by_col_E[alpha]);
	 cout<<"here"<<endl;
       }
       else if( (angle_by_col_E[alpha] > (Pi)) && (angle_by_col_E[alpha] < ((3.0*Pi)/2.0)) ){
	 ref_angle_col[alpha]= angle_by_col_E[alpha] - (Pi);
	 outfile1<<ref_angle_col[alpha]<<endl;
	 h1p->Fill(angle_by_col_E[alpha] - (Pi));
	 cout<<"2here"<<endl;
       }
       else if( angle_by_col_E[alpha] < ((Pi)/2.0) ){
	 ref_angle_col[alpha]= angle_by_col_E[alpha];
	 outfile1<<ref_angle_col[alpha]<<endl;
	 h1p->Fill(angle_by_col_E[alpha]);
	 cout<<" not"<<endl;
       }
       outT<<alpha<<endl;
     












     cout<<"collection done"<<endl;

     if(tpc_i2[last_h_mc_i2]!=tpc_num)continue;//==0) continue;


     outfile_in2_mc_xyz<<x_i2[last_h_mc_i2]<<" "<<y_i2[last_h_mc_i2]<<" "<<z_i2[last_h_mc_i2]<<endl;


     X_SEL12_East_MC_in2[last_h_mc_i2] = x_i2[last_h_mc_i2];
     Y_SEL12_East_MC_in2[last_h_mc_i2] = y_i2[last_h_mc_i2];
     Z_SEL12_East_MC_in2[last_h_mc_i2] = z_i2[last_h_mc_i2];



     double sum_integral_mc_i2 =0.0;
     double sum_dqdx_mc_i2 =0.0;
     double AVG_int_in2[last_h_mc_i2];
     double AVG_dqdx_in2[last_h_mc_i2];
     for(int j = 0; j <last_h_mc_i2; j++){
       sum_integral_mc_i2 += integral_i2[j];
       sum_dqdx_mc_i2 += dqdx_i2[j];
     }
     double av_integral_mc_i2 = sum_integral_mc_i2/last_h_mc_i2;
     double av_dqdx_mc_i2 = sum_dqdx_mc_i2/last_h_mc_i2;


     outfile_dqdx2<<av_dqdx_mc_i2<<endl;
     outfile_int2<<av_integral_mc_i2<<endl;

     int gamma = last_h_mc_i2;

     //   for(int gamma = 0; gamma<ni2; gamma++){

       ref_angle_in2[gamma] = 0.0;

       angle_by_in2_E[gamma] = TMath::ACos( ( (Z_SEL12_East_MC_in2[gamma]*z_p) ) / ( sqrt(X_SEL12_East_MC_in2[gamma]*X_SEL12_East_MC_in2[gamma]+Y_SEL12_East_MC_in2[gamma]*Y_SEL12_East_MC_in2[gamma]+Z_SEL12_East_MC_in2[gamma]*Z_SEL12_East_MC_in2[gamma]) * sqrt( (z_p*z_p) ) ) );
       if( (angle_by_in2_E[gamma] > (Pi)) && (angle_by_in2_E[gamma] < ((3.0*Pi)/2.0))){
	 ref_angle_in2[gamma] = angle_by_in2_E[gamma]-(Pi);
	 outfile3<<ref_angle_in2[gamma]<<endl;
	 h3p->Fill( angle_by_in2_E[gamma]-(Pi));

       }

       else if( (angle_by_in2_E[gamma] > ((Pi)/2.0)) && (angle_by_in2_E[gamma] < (Pi))){
	 ref_angle_in2[gamma] = (Pi) - angle_by_in2_E[gamma];
	 outfile3<<ref_angle_in2[gamma]<<endl;
	 h3p->Fill((Pi) - angle_by_in2_E[gamma]);

       }
       else if(angle_by_in2_E[gamma] < ((Pi)/2.0) ){
	 ref_angle_in2[gamma] = angle_by_in2_E[gamma];
	 outfile3<<ref_angle_in2[gamma]<<endl;
	 h3p->Fill(angle_by_in2_E[gamma]);                                                                             \
       }
     






     cout<<"induction 2 done"<<endl;

     if(tpc_i1[last_h_mc_i1]!=tpc_num)continue;//==0) continue;

     outfile_in1_mc_xyz<<x_i1[last_h_mc_i1]<<" "<<y_i1[last_h_mc_i1]<<" "<<z_i1[last_h_mc_i1]<<endl;     //60 degrees plus:                         

     X_SEL12_East_MC_in1[last_h_mc_i1] = x_i1[last_h_mc_i1];
     Y_SEL12_East_MC_in1[last_h_mc_i1] = y_i1[last_h_mc_i1];
     Z_SEL12_East_MC_in1[last_h_mc_i1] = z_i1[last_h_mc_i1];



     double sum_integral_mc_i1 =0.0;
     double sum_dqdx_mc_i1 =0.0;
     double AVG_int_in1[last_h_mc_i1];
     double AVG_dqdx_in1[last_h_mc_i1];
     for(int k = 0; k <last_h_mc_i1; k++){
       sum_integral_mc_i1 += integral_i1[k];
       sum_dqdx_mc_i1 += dqdx_i1[k];
     }
     double av_integral_mc_i1 = sum_integral_mc_i1/last_h_mc_i1;
     double av_dqdx_mc_i1 = sum_dqdx_mc_i1/last_h_mc_i1;

                            
     outfile_dqdx1<<av_dqdx_mc_i1<<endl;
     outfile_int1<<av_integral_mc_i1<<endl;
                             

     int beta = last_h_mc_i1;

     ref_angle_in1[beta] = 0.0;

     angle_by_in1_E[beta] = TMath::ACos( (  (Z_SEL12_East_MC_in1[beta]*z_p) ) / ( sqrt(X_SEL12_East_MC_in1[beta]*X_SEL12_East_MC_in1[beta]+Y_SEL12_East_MC_in1[beta]*Y_SEL12_East_MC_in1[beta]+Z_SEL12_East_MC_in1[beta]*Z_SEL12_East_MC_in1[beta]) * sqrt( (z_p*z_p) ) ) );

     if(  (angle_by_in1_E[beta] > ((Pi)/2.0) ) && (angle_by_in1_E[beta] < (Pi) )){

       ref_angle_in1[beta] = (Pi) - angle_by_in1_E[beta];
       outfile2<<ref_angle_in1[beta]<<endl;
       h2p->Fill((Pi) - angle_by_in1_E[beta]);
     }

     else if(  (angle_by_in1_E[beta] > (Pi) ) && (angle_by_in1_E[beta] < ((3.0*Pi)/2.0) )){
       ref_angle_in1[beta] = angle_by_in1_E[beta] -(Pi);
       outfile2<<ref_angle_in1[beta]<<endl;
       h2p->Fill(angle_by_in1_E[beta] -(Pi));
     }

     else if(angle_by_in1_E[beta] < ((Pi)/2.0) ){
       ref_angle_in1[beta] = angle_by_in1_E[beta];
       outfile2<<ref_angle_in1[beta]<<endl;
       h2p->Fill(angle_by_in1_E[beta]);
     }








        
     cout<<"induction 1 done"<<endl;     


     nc=last_h_mc_c;
     ni1=last_h_mc_i1;
     ni2=last_h_mc_i2;

   }//end while myReader
   cout<<"MC done"<<endl;
   /*
     double z_p = 1.0;
   double Pi = 3.1415926535897932384;
   //double ref_angle_col[last_h_mc_c];// = 0.0
   //double ref_angle_in1[last_h_mc_i1];// = .0
   //double ref_angle_in2[last_h_mc_i2];// = 0.0
   ref_angle_col[alpha] = 0.0;
   for(int alpha = 0; alpha<nc; alpha++){
     //     outT<<n<<endl;
     angle_by_col_E[alpha] = TMath::ACos( (  (Z_SEL12_East_MC_col[alpha]*z_p) ) / ( sqrt(X_SEL12_East_MC_col[alpha]*X_SEL12_East_MC_col[alpha]+ Y_SEL12_East_MC_col[alpha]*Y_SEL12_East_MC_col[alpha]+Z_SEL12_East_MC_col[alpha]*Z_SEL12_East_MC_col[alpha]) * sqrt( (z_p*z_p) ) ) );
     //ref_angle_col[alpha] = 0.0;
     cout<<angle_by_col_E[alpha]<<endl;
     cout<<((Pi)/2.0)<<endl;
     if( (angle_by_col_E[alpha] > ((Pi)/2.0)) && (angle_by_col_E[alpha] < (Pi) ) ){
       ref_angle_col[alpha] = (Pi) - angle_by_col_E[alpha];
       outfile1<<ref_angle_col[alpha]<<endl;//(Pi) - angle_by_col_E[alpha]<<endl;
       h1p->Fill((Pi) - angle_by_col_E[alpha]);
       cout<<"here"<<endl;
     }
     else if( (angle_by_col_E[alpha] > (Pi)) && (angle_by_col_E[alpha] < ((3.0*Pi)/2.0)) ){
       ref_angle_col[alpha]= angle_by_col_E[alpha] - (Pi);
       outfile1<<ref_angle_col[alpha]<<endl;
       h1p->Fill(angle_by_col_E[alpha] - (Pi));
       cout<<"2here"<<endl;
     }
     else if( angle_by_col_E[alpha] < ((Pi)/2.0) ){
       ref_angle_col[alpha]= angle_by_col_E[alpha];
       outfile1<<ref_angle_col[alpha]<<endl;
       h1p->Fill(angle_by_col_E[alpha]);
       cout<<" not"<<endl;
     }
   outT<<alpha<<endl;
   }

   for(int beta = 0; beta<ni1; beta++){

     ref_angle_in1[beta] = 0.0;

     angle_by_in1_E[beta] = TMath::ACos( (  (Z_SEL12_East_MC_in1[beta]*z_p) ) / ( sqrt(X_SEL12_East_MC_in1[beta]*X_SEL12_East_MC_in1[beta]+Y_SEL12_East_MC_in1[beta]*Y_SEL12_East_MC_in1[beta]+Z_SEL12_East_MC_in1[beta]*Z_SEL12_East_MC_in1[beta]) * sqrt( (z_p*z_p) ) ) );
     if(  (angle_by_in1_E[beta] > ((Pi)/2.0) ) && (angle_by_in1_E[beta] < (Pi) )){

       ref_angle_in1[beta] = (Pi) - angle_by_in1_E[beta];
       outfile2<<ref_angle_in1[beta]<<endl;
       h2p->Fill((Pi) - angle_by_in1_E[beta]);
     }

     else if(  (angle_by_in1_E[beta] > (Pi) ) && (angle_by_in1_E[beta] < ((3.0*Pi)/2.0) )){
       ref_angle_in1[beta] = angle_by_in1_E[beta] -(Pi);
       outfile2<<ref_angle_in1[beta]<<endl;
       h2p->Fill(angle_by_in1_E[beta] -(Pi));
     }

     else if(angle_by_in1_E[beta] < ((Pi)/2.0) ){
       ref_angle_in1[beta] = angle_by_in1_E[beta];
       outfile2<<ref_angle_in1[beta]<<endl;
       h2p->Fill(angle_by_in1_E[beta]);
     }
   }

   for(int gamma = 0; gamma<ni2; gamma++){

     ref_angle_in2[gamma] = 0.0;

     angle_by_in2_E[gamma] = TMath::ACos( ( (Z_SEL12_East_MC_in2[gamma]*z_p) ) / ( sqrt(X_SEL12_East_MC_in2[gamma]*X_SEL12_East_MC_in2[gamma]+Y_SEL12_East_MC_in2[gamma]*Y_SEL12_East_MC_in2[gamma]+Z_SEL12_East_MC_in2[gamma]*Z_SEL12_East_MC_in2[gamma]) * sqrt( (z_p*z_p) ) ) );
     if( (angle_by_in2_E[gamma] > (Pi)) && (angle_by_in2_E[gamma] < ((3.0*Pi)/2.0))){
       ref_angle_in2[gamma] = angle_by_in2_E[gamma]-(Pi);
       outfile3<<ref_angle_in2[gamma]<<endl;
       h3p->Fill( angle_by_in2_E[gamma]-(Pi));

     }

     else if( (angle_by_in2_E[gamma] > ((Pi)/2.0)) && (angle_by_in2_E[gamma] < (Pi))){
       ref_angle_in2[gamma] = (Pi) - angle_by_in2_E[gamma];
       outfile3<<ref_angle_in2[gamma]<<endl;
       h3p->Fill((Pi) - angle_by_in2_E[gamma]);

     }
     else if(angle_by_in2_E[gamma] < ((Pi)/2.0) ){
       ref_angle_in2[gamma] = angle_by_in2_E[gamma];
       outfile3<<ref_angle_in2[gamma]<<endl;
       h3p->Fill(angle_by_in2_E[gamma]);                                                                                   }
   }


   */
   TCanvas* cnvs1p= new TCanvas("cnvs1p", "TPC0 East Cryostat MC COL",1,1,600,500);
   h1p->Draw("HIST");
   TCanvas* cnvs2p= new TCanvas("cnvs2p", "TPC0 East Cryostat MC IN1",1,1,600,500);
   h2p->Draw("HIST");
   TCanvas* cnvs3p= new TCanvas("cnvs3p", "TPC0 East Cryostat MC IN2",1,1,600,500);
   h3p->Draw("HIST");

   cnvs1p->SaveAs("MC_tpc0_sel12_East_file_xyz_col_angle_NEW_h_AUG2023.pdf");
   cnvs2p->SaveAs("MC_tpc0_sel12_East_file_xyz_in1_angle_NEW_h_AUG2023.pdf");
   cnvs3p->SaveAs("MC_tpc0_sel12_East_file_xyz_in2_angle_NEW_h_AUG2023.pdf");


   std::cout << "Number of files in our MC list is " << my_files->GetNFiles() << std::endl;
   cout<<"end of macro"<<endl;


}
