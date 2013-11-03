/**********************************************
 *                                            *
 *           Giuseppe Roselli                 *
 *         INFN, Sezione di Bari              *
 *      Via Amendola 173, 70126 Bari          *
 *         Phone: +390805443218               *
 *                                            *
 *                                            *
 *                                            *
 **********************************************/

#include <iostream>
#include <fstream>
#include <TROOT.h>
#include <TDirectory.h>
#include <TH1.h>
#include <TF1.h>
#include <TH2.h>
#include <TFile.h>
#include "TAxis.h"
#include "TMath.h"
#include "TTree.h"
#include "TLeaf.h"
#include <TCanvas.h>
#include <TGraph.h>
#include <TDirectory.h>
#include <TVectorD.h>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <map>

using namespace std;

int main(){
  std::string buff;
  std::string f1 = "PENE";
  ifstream* input = new ifstream(f1.c_str(),ios::in);

  int first = f1.find("_");
  int second = f1.find(".");
  f1=f1.substr(first+1,second-1);
  std::cout<<f1<<std::endl;
  std::vector<std::string> line;
  line.clear();
  while(getline(*input,buff,'\n')){
    line.push_back(buff);
  }

  ofstream* output;
  unsigned int b=0;
  for(unsigned int i=0;i<line.size();i++){
    if(i==b*5){
      b++;
      char copy[256];
      sprintf(copy,"file_%i_%s",b,f1.c_str());
      std::cout<<copy<<std::endl;
      output= new ofstream(copy);
    }
    *output<<line[i]<<std::endl;
  }

  return 0;
}

