#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdlib>

void Deadstrip(){
  int i, j;
  int n = 0;
  int Entry_0 = 0;
  int NumOfBins_0 = 0;
  
  string line, namesave, plotname_1, plotname_2, plotname_3, plotname_4;
  string parameter;
  ifstream filein;
  ofstream hvscaninfo;
  
  TFile * _file0 = TFile::Open("RPCDQM_97030_Merged.root");
  
  string name;
  string rollsname;
  rollsname = "rolls.txt";
  
  ifstream filein;
  filein.open(rollsname.c_str());

  string output = "output" + rollsname;
  hvscaninfo.open(output.c_str());

  _file0->cd();

  while (!filein.eof()){
    
    float deadstrip_0 = 0; 
    int deadstripnumber = 0;
    float EFF_0 = 0;

    getline(filein,line);
    string Roll = line;
    string name = "Occupancy_" + Roll;
    std::cout << name << std::endl;  
    TH1F * HV8900 = (TH1F*)_file0->Get(name.c_str());
    //    TH1F *HV8900 = (TH1F*)gDirectory->FindObjectAny(name.c_str());

    if(HV8900){
      std::cout << "Esta cogiendo la mierda." << std::endl;
      NumOfBins_0 = HV8900->TH1F::GetNbinsX();
      Entry_0 = HV8900->TH1F::GetEntries();

      std::vector<int> deadstrips;
      deadstrips.clear();

      for(i = 1; i <= NumOfBins_0; ++i){
	EFF_0 = HV8900->GetBinContent(i);
        if(Entry_0 !=0 && EFF_0 == 0) {
	  deadstrip_0++; 
	  deadstripnumber = i;
	  deadstrips.push_back(deadstripnumber);
        }
      }
      hvscaninfo << "------------------------------------------------- " << endl;  
      hvscaninfo << Roll << "each strip: " << endl;
      for(std::vector<int>::iterator it=deadstrips.begin();it!=deadstrips.end();it++) {
        hvscaninfo << (*it) << "   ";    
      }
      hvscaninfo << endl;
      hvscaninfo << " total number: " << deadstrip_0 << endl;
      
      deadstrips.clear();
    }
  }
  hvscaninfo.close();
}
