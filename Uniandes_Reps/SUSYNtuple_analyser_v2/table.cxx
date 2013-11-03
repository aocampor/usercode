#include "string.h"
#include <iostream>
#include <fstream>
#include <stdlib>
#include <iomanip>
void table(string inp_file,string folder,string histo,string out){
  string ou = "";
  ou = "sigtable_"+out+".txt";
  ofstream outfile (ou.c_str());
  outfile.precision(4);
  string line;
  ifstream infile ("input_files.txt");
  std::vector<string> vecstr;
  if (infile.is_open())
    {
      while ( infile.good() )
	{
	  getline (infile,line);
	  vecstr.push_back(line);	
	}
      infile.close();
    }
  else cout << "Unable to open file";
  int nfiles = vecstr.size();
  if (outfile.is_open())
    {
      outfile << "Significance table for";
      //      cout << histo << endl;
      /*
      char ver[50]="";  
      strcpy(ver,histo.c_str());
      char *pch;
      std::vector<char*> strvec;
      pch = strtok(ver,"_");
      strvec.push_back(pch);
      while (pch != NULL){
	pch = strtok(NULL, "_");
	strvec.push_back(pch);
      }
      cout << "size " << strvec.size() << std::endl;
      int size = strvec.size();
      if(size > 5)
	cout << strvec[size-5] << " " << strvec[size-4] << " " << strvec[size-3] << " " << strvec[size-2] << " " << strvec[size-1] << endl;
      outfile << " " <<strvec[size-5] << " " << strvec[size-4] << " " << strvec[size-3] << " " << strvec[size-2] << " " << strvec[size-1]  << ".\n";
      */
      outfile << " " << histo << endl;
      int i = 0;
      std::vector<double> val; 
      std::vector<double> err;
      val.clear();
      err.clear();
      while(i < nfiles-1){
	TFile *f1 = TFile::Open(vecstr[i].c_str());
	TFolder *fol1;
	fol1 =(TFolder*)f1->Get(folder.c_str());
	TH1F *h1;
	h1=(TH1F*)fol1->FindObject(histo.c_str());
	val.push_back(h1->GetBinContent(2));
	err.push_back(h1->GetBinError(2));
	outfile << vecstr[i].c_str() << setw(15) << val[i] << " +- " << err[i] << "\n";
	//outfile << val[i] << setw(30) << err[i] << "\n";
	i++;
      }
      double back=0;
      double qcd = 0;
      for(i=0;i<nfiles-2;i++){
	back += val[i];
      }
      for(i=0;i<8;i++){
	qcd += val[i];
      }
      if (back == 0)
	outfile << "Significancy " << setw(35) << 0 << "\n";	
      else
	outfile << "Significancy " << setw(35) << val[nfiles-2]/sqrt(back) << "\n";
      if(qcd==0)
	outfile << "QCD Significancy " << setw(32)  << 0 << "\n";
      else
	outfile << "QCD Significancy " << setw(32)  << val[nfiles-2]/sqrt(qcd) << "\n";
      //outfile << val[nfiles-2]/sqrt(back) << "\n";
      //  outfile << val[nfiles-2]/sqrt(qcd) << "\n";
      outfile.close();
    }
  else cout << "Unable to open file"; 
}
