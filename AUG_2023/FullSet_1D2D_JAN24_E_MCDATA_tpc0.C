#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "sbnobj/Common/Calibration/TrackCaloSkimmerObj.h"
#include "iostream"


void FullSet_1D2D_JAN24_E_MCDATA_tpc0(bool verbose=false) {


  gStyle->SetOptStat(0);

  ofstream outfile_dqdxc("FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_Qdx_col_MCvsDATA.txt");
  ofstream outfile_dqdx1("FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_Qdx_in1_MCvsDATA.txt");
  ofstream outfile_dqdx2("FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_Qdx_in2_MCvsDATA.txt");

  ofstream outfile_intc("FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_HC_col_MCvsDATA.txt");
  ofstream outfile_int1("FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_HC_in1_MCvsDATA.txt");
  ofstream outfile_int2("FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_HC_in2_MCvsDATA.txt");



  ofstream outfile1("hnoCOSangle_FEB24_col_East_file_tpc0_MCvsDATA.txt");
  ofstream outfile2("hnoCOSangle_FEB24_in1_East_file_tpc0_MCvsDATA.txt");
  ofstream outfile3("hnoCOSangle_FEB24_in2_East_file_tpc0_MCvsDATA.txt");

  ofstream outfile1_c_PLUS("hnoCOSangle_FEB24_col_East_file_tpc0_PLUS_MCvsDATA.txt");
  ofstream outfile2_1_PLUS("hnoCOSangle_FEB24_in1_East_file_tpc0_PLUS_MCvsDATA.txt");
  ofstream outfile3_2_PLUS("hnoCOSangle_FEB24_in2_East_file_tpc0_PLUS_MCvsDATA.txt");

  ofstream outfile1_c_MINUS("hnoCOSangle_FEB24_col_East_file_tpc0_MINUS_MCvsDATA.txt");
  ofstream outfile2_1_MINUS("hnoCOSangle_FEB24_in1_East_file_tpc0_MINUS_MCvsDATA.txt");
  ofstream outfile3_2_MINUS("hnoCOSangle_FEB24_in2_East_file_tpc0_MINUS_MCvsDATA.txt");

  ifstream infiledqdxc_DATA("dataOCT2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_Qdx_col.txt");
  ifstream infiledqdx2_DATA("dataOCT2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_Qdx_in2.txt");
  ifstream infiledqdx1_DATA("dataOCT2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_Qdx_in1.txt");
  ifstream infileintc_DATA("dataOCT2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_HC_col.txt");
  ifstream infileint2_DATA("dataOCT2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_HC_in2.txt");
  ifstream infileint1_DATA("dataOCT2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_HC_in1.txt");

  ifstream infileAc_DATA("datahnoCOSangle_by_OCT2023__col_East_file_tpc0.txt");
  ifstream infileA2_DATA("datahnoCOSangle_by_OCT2023__in2_East_file_tpc0.txt");
  ifstream infileA1_DATA("datahnoCOSangle_by_OCT2023__in1_East_file_tpc0.txt");
  ifstream infileAcp_DATA("datahnoCOSangle_by_OCT2023__col_East_file_tpc0_PLUS.txt");
  ifstream infileA2p_DATA("datahnoCOSangle_by_OCT2023__in2_East_file_tpc0_PLUS.txt");
  ifstream infileA1p_DATA("datahnoCOSangle_by_OCT2023__in1_East_file_tpc0_PLUS.txt");
  ifstream infileAcm_DATA("datahnoCOSangle_by_OCT2023__col_East_file_tpc0_MINUS.txt");
  ifstream infileA2m_DATA("datahnoCOSangle_by_OCT2023__in2_East_file_tpc0_MINUS.txt");
  ifstream infileA1m_DATA("datahnoCOSangle_by_OCT2023__in1_East_file_tpc0_MINUS.txt");


  ifstream infiledqdxc_MC("mcOCT2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_Qdx_col.txt");
  ifstream infiledqdx2_MC("mcOCT2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_Qdx_in2.txt");
  ifstream infiledqdx1_MC("mcOCT2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_Qdx_in1.txt");
  ifstream infileintc_MC("mcOCT2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_HC_col.txt");
  ifstream infileint2_MC("mcOCT2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_HC_in2.txt");
  ifstream infileint1_MC("mcOCT2023_OUTFILE_my_testTESToutputNUMI_tpc0_sel12_East_file_HC_in1.txt");

  ifstream infileAc_MC("mchnoCOSangle_by_OCT2023__col_East_file_tpc0.txt");
  ifstream infileA2_MC("mchnoCOSangle_by_OCT2023__in2_East_file_tpc0.txt");
  ifstream infileA1_MC("mchnoCOSangle_by_OCT2023__in1_East_file_tpc0.txt");
  ifstream infileAcp_MC("mchnoCOSangle_by_OCT2023__col_East_file_tpc0_PLUS.txt");
  ifstream infileA2p_MC("mchnoCOSangle_by_OCT2023__in2_East_file_tpc0_PLUS.txt");
  ifstream infileA1p_MC("mchnoCOSangle_by_OCT2023__in1_East_file_tpc0_PLUS.txt");
  ifstream infileAcm_MC("mchnoCOSangle_by_OCT2023__col_East_file_tpc0_MINUS.txt");
  ifstream infileA2m_MC("mchnoCOSangle_by_OCT2023__in2_East_file_tpc0_MINUS.txt");
  ifstream infileA1m_MC("mchnoCOSangle_by_OCT2023__in1_East_file_tpc0_MINUS.txt");


  int n = 15000;

  double ref_angle_col_DATA[n];                                                                                  
  double ref_angle_in1_DATA[n];                                                                                       
  double ref_angle_in2_DATA[n];          

  double ref_angle_col_p_DATA[n];
  double ref_angle_in1_p_DATA[n];
  double ref_angle_in2_p_DATA[n];

  double ref_angle_col_m_DATA[n];
  double ref_angle_in1_m_DATA[n];
  double ref_angle_in2_m_DATA[n];

  double DQDX_col_DATA[n];
  double DQDX_in2_DATA[n];
  double DQDX_in1_DATA[n];

  double INT_col_DATA[n];
  double INT_in2_DATA[n];
  double INT_in1_DATA[n];

  double ref_angle_col_MC[n];
  double ref_angle_in1_MC[n];
  double ref_angle_in2_MC[n];

  double ref_angle_col_p_MC[n];
  double ref_angle_in1_p_MC[n];
  double ref_angle_in2_p_MC[n];

  double ref_angle_col_m_MC[n];
  double ref_angle_in1_m_MC[n];
  double ref_angle_in2_m_MC[n];

  double DQDX_col_MC[n];
  double DQDX_in2_MC[n];
  double DQDX_in1_MC[n];

  double INT_col_MC[n];
  double INT_in2_MC[n];
  double INT_in1_MC[n];

  double val_dqdxc_DATA=0.0;
  double val_dqdx2_DATA=0.0;
  double val_dqdx1_DATA=0.0;
  double val_intc_DATA=0.0;
  double val_int2_DATA=0.0;
  double val_int1_DATA=0.0;

  double val_Ac_DATA=0.0;
  double val_A2_DATA=0.0;
  double val_A1_DATA=0.0;
  double val_Acp_DATA=0.0;
  double val_A2p_DATA=0.0;
  double val_A1p_DATA=0.0;
  double val_Acm_DATA=0.0;
  double val_A2m_DATA=0.0;
  double val_A1m_DATA=0.0;

  double val_dqdxc_MC=0.0;
  double val_dqdx2_MC=0.0;
  double val_dqdx1_MC=0.0;
  double val_intc_MC=0.0;
  double val_int2_MC=0.0;
  double val_int1_MC=0.0;

  double val_Ac_MC=0.0;
  double val_A2_MC=0.0;
  double val_A1_MC=0.0;
  double val_Acp_MC=0.0;
  double val_A2p_MC=0.0;
  double val_A1p_MC=0.0;
  double val_Acm_MC=0.0;
  double val_A2m_MC=0.0;
  double val_A1m_MC=0.0;


  TH1F *h_Ac_mc   = new TH1F("h_Ac_mc","Relative Frequency vs  Horizontal Angle: East Cryostat", 100., 0., 2.);
  TH1F *h_Ac_data = new TH1F("h_Ac_data","Relative Frequency vs Horizontal Angle: East Cryostat", 100., 0., 2.);
  h_Ac_mc->GetXaxis()->SetTitle(" Horizontal Angle (radians) ");
  h_Ac_mc->GetYaxis()->SetTitle("Relative Frequency");
  THStack *hs_Ac = new THStack("hs_Ac","");
  TH1F *h_A1_mc   = new TH1F("h_A1_mc","Relative Frequency vs  Horizontal Angle: East Cryostat", 100., 0., 2.);
  TH1F *h_A1_data = new TH1F("h_A1_data","Relative Frequency vs Horizontal Angle: East Cryostat", 100., 0., 2.);
  h_A1_mc->GetXaxis()->SetTitle(" Horizontal Angle (radians) ");
  h_A1_mc->GetYaxis()->SetTitle("Relative Frequency");
  THStack *hs_A1 = new THStack("hs_A1","");
  TH1F *h_A2_mc   = new TH1F("h_A2_mc","Relative Frequency vs  Horizontal Angle: East Cryostat", 100., 0., 2.);
  TH1F *h_A2_data = new TH1F("h_A2_data","Relative Frequency vs Horizontal Angle: East Cryostat", 100., 0., 2.);
  h_A2_mc->GetXaxis()->SetTitle(" Horizontal Angle (radians) ");
  h_A2_mc->GetYaxis()->SetTitle("Relative Frequency");
  THStack *hs_A2 = new THStack("hs_A2","");


  TH1F *h_Acp_mc   = new TH1F("h_Acp_mc","Relative Frequency vs  Horizontal Angle PLUS: East Cryostat", 100., 0., 2.);
  TH1F *h_Acp_data = new TH1F("h_Acp_data","Relative Frequency vs Horizontal Angle PLUS: East Cryostat", 100., 0., 2.);
  h_Acp_mc->GetXaxis()->SetTitle(" Horizontal Angle PLUS (radians) ");
  h_Acp_mc->GetYaxis()->SetTitle("Relative Frequency");
  THStack *hs_Acp = new THStack("hs_Acp","");
  TH1F *h_A1p_mc   = new TH1F("h_A1p_mc","Relative Frequency vs  Horizontal Angle PLUS: East Cryostat", 100., 0., 2.);
  TH1F *h_A1p_data = new TH1F("h_A1p_data","Relative Frequency vs Horizontal Angle PLUS: East Cryostat", 100., 0., 2.);
  h_A1p_mc->GetXaxis()->SetTitle(" Horizontal Angle PLUS (radians) ");
  h_A1p_mc->GetYaxis()->SetTitle("Relative Frequency");
  THStack *hs_A1p = new THStack("hs_A1p","");
  TH1F *h_A2p_mc   = new TH1F("h_A2p_mc","Relative Frequency vs  Horizontal Angle PLUS: East Cryostat", 100., 0., 2.);
  TH1F *h_A2p_data = new TH1F("h_A2p_data","Relative Frequency vs Horizontal Angle PLUS: East Cryostat", 100., 0., 2.);
  h_A2p_mc->GetXaxis()->SetTitle(" Horizontal Angle PLUS (radians) ");
  h_A2p_mc->GetYaxis()->SetTitle("Relative Frequency");
  THStack *hs_A2p = new THStack("hs_A2p","");

  TH1F *h_Acm_mc   = new TH1F("h_Acm_mc","Relative Frequency vs  Horizontal Angle MINUS: East Cryostat", 100., 0., 2.);
  TH1F *h_Acm_data = new TH1F("h_Acm_data","Relative Frequency vs Horizontal Angle MINUS: East Cryostat", 100., 0., 2.);
  h_Acm_mc->GetXaxis()->SetTitle(" Horizontal Angle MINUS (radians) ");
  h_Acm_mc->GetYaxis()->SetTitle("Relative Frequency");
  THStack *hs_Acm = new THStack("hs_Acm","");
  TH1F *h_A1m_mc   = new TH1F("h_A1m_mc","Relative Frequency vs  Horizontal Angle MINUS: East Cryostat", 100., 0., 2.);
  TH1F *h_A1m_data = new TH1F("h_A1m_data","Relative Frequency vs Horizontal Angle MINUS: East Cryostat", 100., 0., 2.);
  h_A1m_mc->GetXaxis()->SetTitle(" Horizontal Angle MINUS (radians) ");
  h_A1m_mc->GetYaxis()->SetTitle("Relative Frequency");
  THStack *hs_A1m = new THStack("hs_A1m","");
  TH1F *h_A2m_mc   = new TH1F("h_A2m_mc","Relative Frequency vs  Horizontal Angle MINUS: East Cryostat", 100., 0., 2.);
  TH1F *h_A2m_data = new TH1F("h_A2m_data","Relative Frequency vs Horizontal Angle MINUS: East Cryostat", 100., 0., 2.);
  h_A2m_mc->GetXaxis()->SetTitle(" Horizontal Angle MINUS (radians) ");
  h_A2m_mc->GetYaxis()->SetTitle("Relative Frequency");
  THStack *hs_A2m = new THStack("hs_A2m","");

  TH1F *h_dqdxc_mc   = new TH1F("h_dqdxc_mc","Relative Frequency vs  DQDX: East Cryostat", 100., 0., 2000.);
  TH1F *h_dqdxc_data = new TH1F("h_dqdxc_data","Relative Frequency vs  DQDX: East Cryostat", 100., 0., 2000.);
  h_dqdxc_mc->GetXaxis()->SetTitle(" DQDX ");
  h_dqdxc_mc->GetYaxis()->SetTitle("Relative Frequency");
  THStack *hs_dqdxc = new THStack("hs_dqdxc","");
  TH1F *h_dqdx1_mc   = new TH1F("h_dqdx1_mc","Relative Frequency vs   DQDX: East Cryostat", 100., 0., 2000.);
  TH1F *h_dqdx1_data = new TH1F("h_dqdx1_data","Relative Frequency vs  DQDX: East Cryostat", 100., 0., 2000.);
  h_dqdx1_mc->GetXaxis()->SetTitle(" DQDX ");
  h_dqdx1_mc->GetYaxis()->SetTitle("Relative Frequency");
  THStack *hs_dqdx1 = new THStack("hs_dqdx1","");
  TH1F *h_dqdx2_mc   = new TH1F("h_dqdx2_mc","Relative Frequency vs   DQDX: East Cryostat", 100., 0., 2000.);
  TH1F *h_dqdx2_data = new TH1F("h_dqdx2_data","Relative Frequency vs  DQDX: East Cryostat", 100., 0., 2000.);
  h_dqdx2_mc->GetXaxis()->SetTitle(" DQDX ");
  h_dqdx2_mc->GetYaxis()->SetTitle("Relative Frequency");
  THStack *hs_dqdx2 = new THStack("hs_dqdx2","");

  TH1F *h_intc_mc   = new TH1F("h_intc_mc","Relative Frequency vs  INT: East Cryostat", 100., 0., 2000.);
  TH1F *h_intc_data = new TH1F("h_intc_data","Relative Frequency vs  INT: East Cryostat", 100., 0., 2000.);
  h_intc_mc->GetXaxis()->SetTitle(" INT ");
  h_intc_mc->GetYaxis()->SetTitle("Relative Frequency");
  THStack *hs_intc = new THStack("hs_intc","");
  TH1F *h_int1_mc   = new TH1F("h_int1_mc","Relative Frequency vs   INT: East Cryostat", 100., 0., 2000.);
  TH1F *h_int1_data = new TH1F("h_int1_data","Relative Frequency vs  INT: East Cryostat", 100., 0., 2000.);
  h_int1_mc->GetXaxis()->SetTitle(" INT ");
  h_int1_mc->GetYaxis()->SetTitle("Relative Frequency");
  THStack *hs_int1 = new THStack("hs_int1","");
  TH1F *h_int2_mc   = new TH1F("h_int2_mc","Relative Frequency vs   INT: East Cryostat", 100., 0., 2000.);
  TH1F *h_int2_data = new TH1F("h_int2_data","Relative Frequency vs  INT: East Cryostat", 100., 0., 2000.);
  h_int2_mc->GetXaxis()->SetTitle(" INT ");
  h_int2_mc->GetYaxis()->SetTitle("Relative Frequency");
  THStack *hs_int2 = new THStack("hs_int2","");




  cout<<"Declare done"<<endl;
  //read in

  int MC_Ac = 0;
  while(infileAc_MC>>val_Ac_MC)
    {
      ref_angle_col_MC[MC_Ac] = val_Ac_MC;
      MC_Ac++;
    }
  int MC_A1 = 0;
  while(infileA1_MC>>val_A1_MC)
    {
      ref_angle_in1_MC[MC_A1] = val_A1_MC;
      MC_A1++;
    }
  int MC_A2 = 0;
  while(infileA2_MC>>val_A2_MC)
    {
      ref_angle_in2_MC[MC_A2] = val_A2_MC;
      MC_A2++;
    }

  cout<<"MC angle"<<endl;

  int MC_Acp = 0;
  while(infileAcp_MC>>val_Acp_MC)
    {
      ref_angle_col_p_MC[MC_Acp] = val_Acp_MC;
      MC_Acp++;
    }
  int MC_A1p = 0;
  while(infileA1p_MC>>val_A1p_MC)
    {
      ref_angle_in1_p_MC[MC_A1p] = val_A1p_MC;
      MC_A1p++;
    }
  int MC_A2p = 0;
  while(infileA2p_MC>>val_A2p_MC)
    {
      ref_angle_in2_p_MC[MC_A2p] = val_A2p_MC;
      MC_A2p++;
    }


  cout<<"MC p angle"<<endl;
  int MC_Acm = 0;
  while(infileAcm_MC>>val_Acm_MC)
    {
      ref_angle_col_m_MC[MC_Acm] = val_Acm_MC;
      MC_Acm++;
    }
  int MC_A1m = 0;
  while(infileA1m_MC>>val_A1m_MC)
    {
      ref_angle_in1_m_MC[MC_A1m] = val_A1m_MC;
      MC_A1m++;
    }
  int MC_A2m = 0;
  while(infileA2m_MC>>val_A2m_MC)
    {
      ref_angle_in2_m_MC[MC_A2m] = val_A2m_MC;
      MC_A2m++;
    }

  cout<<"MC m angle"<<endl;
   int MC_DQDXc = 0;
    while(infiledqdxc_MC>>val_dqdxc_MC)
     {
       DQDX_col_MC[MC_DQDXc] = val_dqdxc_MC;
       MC_DQDXc++;
     }
   int MC_DQDX1 = 0;
   while(infiledqdx1_MC>>val_dqdx1_MC)
     {
       DQDX_in1_MC[MC_DQDX1] = val_dqdx1_MC;
       MC_DQDX1++;
     }
   int MC_DQDX2 = 0;
   while(infiledqdx2_MC>>val_dqdx2_MC)
     {
       DQDX_in2_MC[MC_DQDX2] = val_dqdx2_MC;
       MC_DQDX2++;
     }


   cout<<"MC dqdx"<<endl;
   int MC_INTc = 0;
   while(infileintc_MC>>val_intc_MC)
     {
       INT_col_MC[MC_INTc] = val_intc_MC;
       MC_INTc++;
     }
   int MC_INT1 = 0;
   while(infileint1_MC>>val_int1_MC)
     {
       INT_in1_MC[MC_INT1] = val_int1_MC;
       MC_INT1++;
     }
   int MC_INT2 = 0;
   while(infileint2_MC>>val_int2_MC)
     {
       INT_in2_MC[MC_INT2] = val_int2_MC;
       MC_INT2++;
     }
   cout<<"MC int"<<endl;


   int DATA_Ac = 0;
   //cout<<"here1"<<endl;
   while(infileAc_DATA>>val_Ac_DATA)
     {
       //cout<<"here2 "<<DATA_Ac<<endl;
       ref_angle_col_DATA[DATA_Ac] = val_Ac_DATA;
       //cout<<"here3 "<<DATA_Ac<<endl;
       DATA_Ac++;
       //cout<<"here4"<<endl;
     }
   //   cout<<"here"<<endl;
   int DATA_A1 = 0;
   while(infileA1_DATA>>val_A1_DATA)
     {
       ref_angle_in1_DATA[DATA_A1] = val_A1_DATA;
       DATA_A1++;
     }
   int DATA_A2 = 0;
   while(infileA2_DATA>>val_A2_DATA)
     {
       ref_angle_in2_DATA[DATA_A2] = val_A2_DATA;
       DATA_A2++;
     }


   cout<<"DATA angle"<<endl;
   int DATA_Acp = 0;
   while(infileAcp_DATA>>val_Acp_DATA)
     {
       ref_angle_col_p_DATA[DATA_Acp] = val_Acp_DATA;
       DATA_Acp++;
     }
   int DATA_A1p = 0;
   while(infileA1p_DATA>>val_A1p_DATA)
     {
       ref_angle_in1_p_DATA[DATA_A1p] = val_A1p_DATA;
       DATA_A1p++;
     }
   int DATA_A2p = 0;
   while(infileA2p_DATA>>val_A2p_DATA)
     {
       ref_angle_in2_p_DATA[DATA_A2p] = val_A2p_DATA;
       DATA_A2p++;
     }

   cout<<"DATA angle p"<<endl;
   int DATA_Acm = 0;
   while(infileAcm_DATA>>val_Acm_DATA)
     {
       ref_angle_col_m_DATA[DATA_Acm] = val_Acm_DATA;
       DATA_Acm++;
     }
   int DATA_A1m = 0;
   while(infileA1m_DATA>>val_A1m_DATA)
     {
       ref_angle_in1_m_DATA[DATA_A1m] = val_A1m_DATA;
       DATA_A1m++;
     }
   int DATA_A2m = 0;
   while(infileA2m_DATA>>val_A2m_DATA)
     {
       ref_angle_in2_m_DATA[DATA_A2m] = val_A2m_DATA;
       DATA_A2m++;
     }

   cout<<"DATA angle m"<<endl;

   int DATA_DQDXc = 0;
   while(infiledqdxc_DATA>>val_dqdxc_DATA)
     {
       DQDX_col_DATA[DATA_DQDXc] = val_dqdxc_DATA;
       DATA_DQDXc++;
     }
   int DATA_DQDX1 = 0;
   while(infiledqdx1_DATA>>val_dqdx1_DATA)
     {
       DQDX_in1_DATA[DATA_DQDX1] = val_dqdx1_DATA;
       DATA_DQDX1++;
     }
   int DATA_DQDX2 = 0;
   while(infiledqdx2_DATA>>val_dqdx2_DATA)
     {
       DQDX_in2_DATA[DATA_DQDX2] = val_dqdx2_DATA;
       DATA_DQDX2++;
     }

   cout<<"DATA dqdx"<<endl;
   int DATA_INTc = 0;
   while(infileintc_DATA>>val_intc_DATA)
     {
       INT_col_DATA[DATA_INTc] = val_intc_DATA;
       DATA_INTc++;
     }
   int DATA_INT1 = 0;
   while(infileint1_DATA>>val_int1_DATA)
     {
       INT_in1_DATA[DATA_INT1] = val_int1_DATA;
       DATA_INT1++;
     }
   int DATA_INT2 = 0;
   while(infileint2_DATA>>val_int2_DATA)
     {
       INT_in2_DATA[DATA_INT2] = val_int2_DATA;
       DATA_INT2++;
     }
   cout<<"DATA int"<<endl;
   cout<<"Read in done"<<endl;
  // fill
   int aa=0;
   int aa1=0;
   int aa2=0;
   //  cout<<MC_Ac<<endl;
   //cout<<MC_A2p<<endl;
   //   cout<<MC_A2m<<endl;
   // cout<<DATA_A2<<endl;
   // cout<<DATA_A2p<<endl;
   ///cout<<DATA_A2m<<endl;
   //cout<<"here"<<endl;
   for (aa=0;aa<MC_Ac;aa++){
     h_Ac_mc->Fill(ref_angle_col_MC[aa]);
     //cout<<aa<<endl;
   }
   for (aa1=0;aa1<MC_A1;aa1++){
     h_A1_mc->Fill(ref_angle_in1_MC[aa1]);
     // cout<<"herec"<<endl;
   }
   for (aa2=0;aa2<MC_A2;aa2++){
     h_A2_mc->Fill(ref_angle_in2_MC[aa2]);
     //cout<<"hered"<<endl;
   }
   cout<<"here1"<<endl;
   int bb=0;
   int bb1=0;
   int bb2=0;
   for (bb=0;bb<DATA_Ac;bb++){
     h_Ac_data->Fill(ref_angle_col_DATA[bb]);
   }
   for (bb1=0;bb1<DATA_A1;bb1++){
     h_A1_data->Fill(ref_angle_in1_DATA[bb1]);
   }
   for (bb2=0;bb2<DATA_A2;bb2++){
     h_A2_data->Fill(ref_angle_in2_DATA[bb2]);
   }
   cout<<"here2"<<endl;
   int cc=0;
   int cc1=0;
   int cc2=0;
   for (cc=0;cc<MC_Acp;cc++){
     h_Acp_mc->Fill(ref_angle_col_p_MC[cc]);
   }
   for (cc1=0;cc1<MC_A1p;cc1++){
     h_A1p_mc->Fill(ref_angle_in1_p_MC[cc1]);
   }
   for (cc2=0;cc2<MC_A2p;cc2++){
     h_A2p_mc->Fill(ref_angle_in2_p_MC[cc2]);
   }
   cout<<"here3"<<endl;
   int dd=0;
   int dd1=0;
   int dd2=0;
   for (dd=0;dd<DATA_Acp;dd++){
     h_Acp_data->Fill(ref_angle_col_p_DATA[dd]);
   }
   for (dd1=0;dd1<DATA_A1p;dd1++){
     h_A1p_data->Fill(ref_angle_in1_p_DATA[dd1]);
   }
   for (dd2=0;dd2<DATA_A2p;dd2++){
     h_A2p_data->Fill(ref_angle_in2_p_DATA[dd2]);
   }

   int ee=0;
   int ee1=0;
   int ee2=0;
   for (ee=0;ee<MC_Acm;ee++){
     h_Acm_mc->Fill(ref_angle_col_m_MC[ee]);
   }
   for (ee1=0;ee1<MC_A1m;ee1++){
     h_A1m_mc->Fill(ref_angle_in1_m_MC[ee1]);
   }
   for (ee2=0;ee2<MC_A2m;ee2++){
     h_A2m_mc->Fill(ref_angle_in2_m_MC[ee2]);
   }
   int ff=0;
   int ff1=0;
   int ff2=0;
   for (ff=0;ff<DATA_Acm;ff++){
     h_Acm_data->Fill(ref_angle_col_m_DATA[ff]);
   }
   for (ff1=0;ff1<DATA_A1m;ff1++){
     h_A1m_data->Fill(ref_angle_in1_m_DATA[ff1]);
   }
   for (ff2=0;ff2<DATA_A2m;ff2++){
     h_A2m_data->Fill(ref_angle_in2_m_DATA[ff2]);
   }



   int gg=0;
   int gg1=0;
   int gg2=0;
   for (gg=0;gg<MC_DQDXc;gg++){
     h_dqdxc_mc->Fill(DQDX_col_MC[gg]);
   }
   for (gg1=0;gg1<MC_DQDX1;gg1++){
     h_dqdx1_mc->Fill(DQDX_in1_MC[gg1]);
   }
   for (gg2=0;gg2<MC_DQDX2;gg2++){
     h_dqdx2_mc->Fill(DQDX_in2_MC[gg2]);
   }


   int hh=0;
   int hh1=0;
   int hh2=0;
   for (hh=0;hh<DATA_DQDXc;hh++){
     h_dqdxc_data->Fill(DQDX_col_DATA[hh]);
   }
   for (hh1=0;hh1<DATA_DQDX1;hh1++){
     h_dqdx1_data->Fill(DQDX_in1_DATA[hh1]);
   }
   for (hh2=0;hh2<DATA_DQDX2;hh2++){
     h_dqdx2_data->Fill(DQDX_in2_DATA[hh2]);
   }


   int ii=0;
   int ii1=0;
   int ii2=0;
   for (ii=0;ii<MC_INTc;ii++){
     h_intc_mc->Fill(INT_col_MC[ii]);
   }
   for (ii1=0;ii1<MC_INT1;ii1++){
     h_int1_mc->Fill(INT_in1_MC[ii1]);
   }
   for (ii2=0;ii2<MC_INT2;ii2++){
     h_int2_mc->Fill(INT_in2_MC[ii2]);
   }

   int jj=0;
   int jj1=0;
   int jj2=0;
   for (jj=0;jj<DATA_INTc;jj++){
     h_intc_data->Fill(INT_col_DATA[jj]);
   }
   for (jj1=0;jj1<DATA_INT1;jj1++){
     h_int1_data->Fill(INT_in1_DATA[jj1]);
   }
   for (jj2=0;jj2<DATA_INT2;jj2++){
     h_int2_data->Fill(INT_in2_DATA[jj2]);
   }

   cout<<"Fill done"<<endl;
  //normalize?

   TH1*h1Ac = (TH1*)(h_Ac_mc->Clone("h1Ac"));
   h1Ac->Scale(1./h1Ac->Integral());
   TH1*h2Ac = (TH1*)(h_Ac_data->Clone("h2Ac"));
   h2Ac->Scale(1./h2Ac->Integral());

   TH1*h1A1 = (TH1*)(h_A1_mc->Clone("h1A1"));
   h1A1->Scale(1./h1A1->Integral());
   TH1*h2A1 = (TH1*)(h_A1_data->Clone("h2A1"));
   h2A1->Scale(1./h2A1->Integral());

   TH1*h1A2 = (TH1*)(h_A2_mc->Clone("h1A2"));
   h1A2->Scale(1./h1A2->Integral());
   TH1*h2A2 = (TH1*)(h_A2_data->Clone("h2A2"));
   h2A2->Scale(1./h2A2->Integral());



   TH1*h1Acp = (TH1*)(h_Acp_mc->Clone("h1Acp"));
   h1Acp->Scale(1./h1Acp->Integral());
   TH1*h2Acp = (TH1*)(h_Acp_data->Clone("h2Acp"));
   h2Acp->Scale(1./h2Acp->Integral());

   TH1*h1A1p = (TH1*)(h_A1p_mc->Clone("h1A1p"));
   h1A1p->Scale(1./h1A1p->Integral());
   TH1*h2A1p = (TH1*)(h_A1p_data->Clone("h2A1p"));
   h2A1p->Scale(1./h2A1p->Integral());

   TH1*h1A2p = (TH1*)(h_A2p_mc->Clone("h1A2p"));
   h1A2p->Scale(1./h1A2p->Integral());
   TH1*h2A2p = (TH1*)(h_A2p_data->Clone("h2A2p"));
   h2A2p->Scale(1./h2A2p->Integral());

   TH1*h1Acm = (TH1*)(h_Acm_mc->Clone("h1Acm"));
   h1Acm->Scale(1./h1Acm->Integral());
   TH1*h2Acm = (TH1*)(h_Acm_data->Clone("h2Acm"));
   h2Acm->Scale(1./h2Acm->Integral());

   TH1*h1A1m = (TH1*)(h_A1m_mc->Clone("h1A1m"));
   h1A1m->Scale(1./h1A1m->Integral());
   TH1*h2A1m = (TH1*)(h_A1m_data->Clone("h2A1m"));
   h2A1m->Scale(1./h2A1m->Integral());

   TH1*h1A2m = (TH1*)(h_A2m_mc->Clone("h1A2m"));
   h1A2m->Scale(1./h1A2m->Integral());
   TH1*h2A2m = (TH1*)(h_A2m_data->Clone("h2A2m"));
   h2A2m->Scale(1./h2A2m->Integral());


   TH1*h1DQDXc = (TH1*)(h_dqdxc_mc->Clone("h1DQDXc"));
   h1DQDXc->Scale(1./h1DQDXc->Integral());
   TH1*h2DQDXc = (TH1*)(h_dqdxc_data->Clone("h2DQDXc"));
   h2DQDXc->Scale(1./h2DQDXc->Integral());

   TH1*h1DQDX1 = (TH1*)(h_dqdx1_mc->Clone("h1DQDX1"));
   h1DQDX1->Scale(1./h1DQDX1->Integral());
   TH1*h2DQDX1 = (TH1*)(h_dqdx1_data->Clone("h2DQDX1"));
   h2DQDX1->Scale(1./h2DQDX1->Integral());

   TH1*h1DQDX2 = (TH1*)(h_dqdx2_mc->Clone("h1DQDX2"));
   h1DQDX2->Scale(1./h1DQDX2->Integral());
   TH1*h2DQDX2 = (TH1*)(h_dqdx2_data->Clone("h2DQDX2"));
   h2DQDX2->Scale(1./h2DQDX2->Integral());



   TH1*h1INTc = (TH1*)(h_intc_mc->Clone("h1INTc"));
   h1INTc->Scale(1./h1INTc->Integral());
   TH1*h2INTc = (TH1*)(h_intc_data->Clone("h2INTc"));
   h2INTc->Scale(1./h2INTc->Integral());

   TH1*h1INT1 = (TH1*)(h_int1_mc->Clone("h1INT1"));
   h1INT1->Scale(1./h1INT1->Integral());
   TH1*h2INT1 = (TH1*)(h_int1_data->Clone("h2INT1"));
   h2INT1->Scale(1./h2INT1->Integral());

   TH1*h1INT2 = (TH1*)(h_int2_mc->Clone("h1INT2"));
   h1INT2->Scale(1./h1INT2->Integral());
   TH1*h2INT2 = (TH1*)(h_int2_data->Clone("h2INT2"));
   h2INT2->Scale(1./h2INT2->Integral());


   cout<<"Norm done"<<endl;


  //display


   TCanvas* cnvs_Ac = new TCanvas("cnvs_Ac", "c7", 1,1,800,700);
   h1Ac->SetLineColor(kRed);
   h2Ac->SetLineColor(kBlue);
   hs_Ac->Add(h1Ac);
   hs_Ac->Add(h2Ac);
   hs_Ac->Draw("nostackHIST");

   hs_Ac->GetXaxis()->SetTitle(" Horizontal Angle (radians)  ");
   hs_Ac->GetYaxis()->SetTitle("Relative Frequency");
   TText TAc; TAc.SetTextFont(42); TAc.SetTextAlign(21);
   TAc.DrawTextNDC(.5,.95,"Relative Frequency vs Horizontal Angle (col): East Cryostat");
   auto legendAc = new TLegend(0.1,0.8,0.2,0.9);
   legendAc->AddEntry(h1Ac,"MC");
   legendAc->AddEntry(h2Ac,"Data");
   legendAc->Draw();
   cnvs_Ac->Update();
   cnvs_Ac->SaveAs("JAN24/FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_angle_col_MCvsDATA.pdf");


   TCanvas* cnvs_A1 = new TCanvas("cnvs_A1", "c7", 1,1,800,700);
   h1A1->SetLineColor(kRed);
   h2A1->SetLineColor(kBlue);
   hs_A1->Add(h1A1);
   hs_A1->Add(h2A1);
   hs_A1->Draw("nostackHIST");

   hs_A1->GetXaxis()->SetTitle(" Horizontal Angle (radians)  ");
   hs_A1->GetYaxis()->SetTitle("Relative Frequency");
   TText TA1; TA1.SetTextFont(42); TA1.SetTextAlign(21);
   TA1.DrawTextNDC(.5,.95,"Relative Frequency vs Horizontal Angle (in1): East Cryostat");
   auto legendA1 = new TLegend(0.1,0.8,0.2,0.9);
   legendA1->AddEntry(h1A1,"MC");
   legendA1->AddEntry(h2A1,"Data");
   legendA1->Draw();
   cnvs_A1->Update();
   cnvs_A1->SaveAs("JAN24/FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_angle_in1_MCvsDATA.pdf");

   TCanvas* cnvs_A2 = new TCanvas("cnvs_A2", "c7", 1,1,800,700);
   h1A2->SetLineColor(kRed);
   h2A2->SetLineColor(kBlue);
   hs_A2->Add(h1A2);
   hs_A2->Add(h2A2);
   hs_A2->Draw("nostackHIST");

   hs_A2->GetXaxis()->SetTitle(" Horizontal Angle (radians)  ");
   hs_A2->GetYaxis()->SetTitle("Relative Frequency");
   TText TA2; TA2.SetTextFont(42); TA2.SetTextAlign(21);
   TA2.DrawTextNDC(.5,.95,"Relative Frequency vs Horizontal Angle (in2): East Cryostat");
   auto legendA2 = new TLegend(0.1,0.8,0.2,0.9);
   legendA2->AddEntry(h1A2,"MC");
   legendA2->AddEntry(h2A2,"Data");
   legendA2->Draw();
   cnvs_A2->Update();
   cnvs_A2->SaveAs("JAN24/FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_angle_in2_MCvsDATA.pdf");


   TCanvas* cnvs_Acp = new TCanvas("cnvs_Acp", "c7", 1,1,800,700);
   h1Acp->SetLineColor(kRed);
   h2Acp->SetLineColor(kBlue);
   hs_Acp->Add(h1Acp);
   hs_Acp->Add(h2Acp);
   hs_Acp->Draw("nostackHIST");

   hs_Acp->GetXaxis()->SetTitle(" Horizontal Angle PLUS (radians)  ");
   hs_Acp->GetYaxis()->SetTitle("Relative Frequency");
   TText TAcp; TAcp.SetTextFont(42); TAcp.SetTextAlign(21);
   TAcp.DrawTextNDC(.5,.95,"Relative Frequency vs Horizontal Angle PLUS (col): East Cryostat");
   auto legendAcp = new TLegend(0.1,0.8,0.2,0.9);
   legendAcp->AddEntry(h1Acp,"MC");
   legendAcp->AddEntry(h2Acp,"Data");
   legendAcp->Draw();
   cnvs_Acp->Update();
   cnvs_Acp->SaveAs("JAN24/FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_angle_col_plus_MCvsDATA.pdf");


   TCanvas* cnvs_A1p = new TCanvas("cnvs_A1p", "c7", 1,1,800,700);
   h1A1p->SetLineColor(kRed);
   h2A1p->SetLineColor(kBlue);
   hs_A1p->Add(h1A1p);
   hs_A1p->Add(h2A1p);
   hs_A1p->Draw("nostackHIST");

   hs_A1p->GetXaxis()->SetTitle(" Horizontal Angle PLUS (radians)  ");
   hs_A1p->GetYaxis()->SetTitle("Relative Frequency");
   TText TA1p; TA1p.SetTextFont(42); TA1p.SetTextAlign(21);
   TA1p.DrawTextNDC(.5,.95,"Relative Frequency vs Horizontal Angle PLUS (in1): East Cryostat");
   auto legendA1p = new TLegend(0.1,0.8,0.2,0.9);
   legendA1p->AddEntry(h1A1p,"MC");
   legendA1p->AddEntry(h2A1p,"Data");
   legendA1p->Draw();
   cnvs_A1p->Update();
   cnvs_A1p->SaveAs("JAN24/FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_angle_in1_plus_MCvsDATA.pdf");


   TCanvas* cnvs_A2p = new TCanvas("cnvs_A2p", "c7", 1,1,800,700);
   h1A2p->SetLineColor(kRed);
   h2A2p->SetLineColor(kBlue);
   hs_A2p->Add(h1A2p);
   hs_A2p->Add(h2A2p);
   hs_A2p->Draw("nostackHIST");

   hs_A2p->GetXaxis()->SetTitle(" Horizontal Angle PLUS (radians)  ");
   hs_A2p->GetYaxis()->SetTitle("Relative Frequency");
   TText TA2p; TA2p.SetTextFont(42); TA2p.SetTextAlign(21);
   TA2p.DrawTextNDC(.5,.95,"Relative Frequency vs Horizontal Angle PLUS (in2): East Cryostat");
   auto legendA2p = new TLegend(0.1,0.8,0.2,0.9);
   legendA2p->AddEntry(h1A2p,"MC");
   legendA2p->AddEntry(h2A2p,"Data");
   legendA2p->Draw();
   cnvs_A2p->Update();
   cnvs_A2p->SaveAs("JAN24/FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_angle_in2_plus_MCvsDATA.pdf");

   TCanvas* cnvs_Acm = new TCanvas("cnvs_Acm", "c7", 1,1,800,700);
   h1Acm->SetLineColor(kRed);
   h2Acm->SetLineColor(kBlue);
   hs_Acm->Add(h1Acm);
   hs_Acm->Add(h2Acm);
   hs_Acm->Draw("nostackHIST");

   hs_Acm->GetXaxis()->SetTitle(" Horizontal Angle MINUS (radians)  ");
   hs_Acm->GetYaxis()->SetTitle("Relative Frequency");
   TText TAcm; TAcm.SetTextFont(42); TAcm.SetTextAlign(21);
   TAcm.DrawTextNDC(.5,.95,"Relative Frequency vs Horizontal Angle MINUS (col): East Cryostat");
   auto legendAcm = new TLegend(0.1,0.8,0.2,0.9);
   legendAcm->AddEntry(h1Acm,"MC");
   legendAcm->AddEntry(h2Acm,"Data");
   legendAcm->Draw();
   cnvs_Acm->Update();
   cnvs_Acm->SaveAs("JAN24/FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_angle_col_minus_MCvsDATA.pdf");

   TCanvas* cnvs_A1m = new TCanvas("cnvs_A1m", "c7", 1,1,800,700);
   h1A1m->SetLineColor(kRed);
   h2A1m->SetLineColor(kBlue);
   hs_A1m->Add(h1A1m);
   hs_A1m->Add(h2A1m);
   hs_A1m->Draw("nostackHIST");

   hs_A1m->GetXaxis()->SetTitle(" Horizontal Angle MINUS (radians)  ");
   hs_A1m->GetYaxis()->SetTitle("Relative Frequency");
   TText TA1m; TA1m.SetTextFont(42); TA1m.SetTextAlign(21);
   TA1m.DrawTextNDC(.5,.95,"Relative Frequency vs Horizontal Angle MINUS (in1): East Cryostat");
   auto legendA1m = new TLegend(0.1,0.8,0.2,0.9);
   legendA1m->AddEntry(h1A1m,"MC");
   legendA1m->AddEntry(h2A1m,"Data");
   legendA1m->Draw();
   cnvs_A1m->Update();
   cnvs_A1m->SaveAs("JAN24/FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_angle_in1_minus_MCvsDATA.pdf");


   TCanvas* cnvs_A2m = new TCanvas("cnvs_A2m", "c7", 1,1,800,700);
   h1A2m->SetLineColor(kRed);
   h2A2m->SetLineColor(kBlue);
   hs_A2m->Add(h1A2m);
   hs_A2m->Add(h2A2m);
   hs_A2m->Draw("nostackHIST");

   hs_A2m->GetXaxis()->SetTitle(" Horizontal Angle MINUS (radians)  ");
   hs_A2m->GetYaxis()->SetTitle("Relative Frequency");
   TText TA2m; TA2m.SetTextFont(42); TA2m.SetTextAlign(21);
   TA2m.DrawTextNDC(.5,.95,"Relative Frequency vs Horizontal Angle MINUS (in2): East Cryostat");
   auto legendA2m = new TLegend(0.1,0.8,0.2,0.9);
   legendA2m->AddEntry(h1A2m,"MC");
   legendA2m->AddEntry(h2A2m,"Data");
   legendA2m->Draw();
   cnvs_A2m->Update();
   cnvs_A2m->SaveAs("JAN24/FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_angle_in2_minus_MCvsDATA.pdf");




   TCanvas* cnvs_DQDXc = new TCanvas("cnvs_DQDXc", "c7", 1,1,800,700);
   h1DQDXc->SetLineColor(kRed);
   h2DQDXc->SetLineColor(kBlue);
   hs_dqdxc->Add(h1DQDXc);
   hs_dqdxc->Add(h2DQDXc);
   hs_dqdxc->Draw("nostackHIST");

   hs_dqdxc->GetXaxis()->SetTitle(" DQDX  ");
   hs_dqdxc->GetYaxis()->SetTitle("Relative Frequency");
   TText TDQDXc; TDQDXc.SetTextFont(42); TDQDXc.SetTextAlign(21);
   TDQDXc.DrawTextNDC(.5,.95,"Relative Frequency vs DQDX (col): East Cryostat");
   auto legendDQDXc = new TLegend(0.1,0.8,0.2,0.9);
   legendDQDXc->AddEntry(h1DQDXc,"MC");
   legendDQDXc->AddEntry(h2DQDXc,"Data");
   legendDQDXc->Draw();
   cnvs_DQDXc->Update();
   cnvs_DQDXc->SaveAs("JAN24/FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_DQDX_col_MCvsDATA.pdf");



   TCanvas* cnvs_DQDX1 = new TCanvas("cnvs_DQDX1", "c7", 1,1,800,700);
   h1DQDX1->SetLineColor(kRed);
   h2DQDX1->SetLineColor(kBlue);
   hs_dqdx1->Add(h1DQDX1);
   hs_dqdx1->Add(h2DQDX1);
   hs_dqdx1->Draw("nostackHIST");

   hs_dqdx1->GetXaxis()->SetTitle(" DQDX  ");
   hs_dqdx1->GetYaxis()->SetTitle("Relative Frequency");
   TText TDQDX1; TDQDX1.SetTextFont(42); TDQDX1.SetTextAlign(21);
   TDQDX1.DrawTextNDC(.5,.95,"Relative Frequency vs DQDX (in1): East Cryostat");
   auto legendDQDX1 = new TLegend(0.1,0.8,0.2,0.9);
   legendDQDX1->AddEntry(h1DQDX1,"MC");
   legendDQDX1->AddEntry(h2DQDX1,"Data");
   legendDQDX1->Draw();
   cnvs_DQDX1->Update();
   cnvs_DQDX1->SaveAs("JAN24/FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_DQDX_in1_MCvsDATA.pdf");



   TCanvas* cnvs_DQDX2 = new TCanvas("cnvs_DQDX2", "c7", 1,1,800,700);
   h1DQDX2->SetLineColor(kRed);
   h2DQDX2->SetLineColor(kBlue);
   hs_dqdx2->Add(h1DQDX2);
   hs_dqdx2->Add(h2DQDX2);
   hs_dqdx2->Draw("nostackHIST");

   hs_dqdx2->GetXaxis()->SetTitle(" DQDX  ");
   hs_dqdx2->GetYaxis()->SetTitle("Relative Frequency");
   TText TDQDX2; TDQDX2.SetTextFont(42); TDQDX2.SetTextAlign(21);
   TDQDX2.DrawTextNDC(.5,.95,"Relative Frequency vs DQDX (in2): East Cryostat");
   auto legendDQDX2 = new TLegend(0.1,0.8,0.2,0.9);
   legendDQDX2->AddEntry(h1DQDX2,"MC");
   legendDQDX2->AddEntry(h2DQDX2,"Data");
   legendDQDX2->Draw();
   cnvs_DQDX2->Update();
   cnvs_DQDX2->SaveAs("JAN24/FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_DQDX_in2_MCvsDATA.pdf");


   TCanvas* cnvs_INTc = new TCanvas("cnvs_INTc", "c7", 1,1,800,700);
   h1INTc->SetLineColor(kRed);
   h2INTc->SetLineColor(kBlue);
   hs_intc->Add(h1INTc);
   hs_intc->Add(h2INTc);
   hs_intc->Draw("nostackHIST");

   hs_intc->GetXaxis()->SetTitle(" INT  ");
   hs_intc->GetYaxis()->SetTitle("Relative Frequency");
   TText TINTc; TINTc.SetTextFont(42); TINTc.SetTextAlign(21);
   TINTc.DrawTextNDC(.5,.95,"Relative Frequency vs INT (col): East Cryostat");
   auto legendINTc = new TLegend(0.1,0.8,0.2,0.9);
   legendINTc->AddEntry(h1INTc,"MC");
   legendINTc->AddEntry(h2INTc,"Data");
   legendINTc->Draw();
   cnvs_INTc->Update();
   cnvs_INTc->SaveAs("JAN24/FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_INT_col_MCvsDATA.pdf");

   TCanvas* cnvs_INT1 = new TCanvas("cnvs_INT1", "c7", 1,1,800,700);
   h1INT1->SetLineColor(kRed);
   h2INT1->SetLineColor(kBlue);
   hs_int1->Add(h1INT1);
   hs_int1->Add(h2INT1);
   hs_int1->Draw("nostackHIST");

   hs_int1->GetXaxis()->SetTitle(" INT  ");
   hs_int1->GetYaxis()->SetTitle("Relative Frequency");
   TText TINT1; TINT1.SetTextFont(42); TINT1.SetTextAlign(21);
   TINT1.DrawTextNDC(.5,.95,"Relative Frequency vs INT (in1): East Cryostat");
   auto legendINT1 = new TLegend(0.1,0.8,0.2,0.9);
   legendINT1->AddEntry(h1INT1,"MC");
   legendINT1->AddEntry(h2INT1,"Data");
   legendINT1->Draw();
   cnvs_INT1->Update();
   cnvs_INT1->SaveAs("JAN24/FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_INT_in1_MCvsDATA.pdf");


   TCanvas* cnvs_INT2 = new TCanvas("cnvs_INT2", "c7", 1,1,800,700);
   h1INT2->SetLineColor(kRed);
   h2INT2->SetLineColor(kBlue);
   hs_int2->Add(h1INT2);
   hs_int2->Add(h2INT2);
   hs_int2->Draw("nostackHIST");

   hs_int2->GetXaxis()->SetTitle(" INT  ");
   hs_int2->GetYaxis()->SetTitle("Relative Frequency");
   TText TINT2; TINT2.SetTextFont(42); TINT2.SetTextAlign(21);
   TINT2.DrawTextNDC(.5,.95,"Relative Frequency vs INT (in2): East Cryostat");
   auto legendINT2 = new TLegend(0.1,0.8,0.2,0.9);
   legendINT2->AddEntry(h1INT2,"MC");
   legendINT2->AddEntry(h2INT2,"Data");
   legendINT2->Draw();
   cnvs_INT2->Update();
   cnvs_INT2->SaveAs("JAN24/FEB24_OUTFILE_NUMI_tpc0_sel12_East_file_INT_in2_MCvsDATA.pdf");


   cout<<"Display done"<<endl;
}
