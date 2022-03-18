void compare_histograms(TString file1_name,
                        TString file2_name)
{

  std::vector<std::string> hists_to_compare=
  {"hist_start_x","hist_start_y","hist_start_z"};

  TFile file1(file1_name,"READ");
  TFile file2(file2_name,"READ");

  std::cout << "Compare histograms from file " << file1_name
            << " and " << file2_name << std::endl;

  for(auto const& hname : hists_to_compare)
  {
    TH1D* h1 = (TH1D*)file1.Get(hname.c_str());
    TH1D* h2 = (TH1D*)file2.Get(hname.c_str());

    std::cout << "Comparing " << hname << std::endl;
    std::cout << "\tChi2Test: " << h1->Chi2Test(h2,"UU NORM") << std::endl;
    std::cout << "\tKSTest: " << h1->KolmogorovTest(h2,"UO") << std::endl;
  }

}
