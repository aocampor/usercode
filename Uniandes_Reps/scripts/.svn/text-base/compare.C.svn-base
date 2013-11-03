#include <iostream>
#include <string>
#include <stdlib>
#include <sstream>
#include <algorithm>
#include <iterator>
void compare(){
  TFile *f1 = TFile::Open("test_LM0.root");
  TFile *f2 = TFile::Open("test_ttbarTauola_1.root");
  TFile *f3 = TFile::Open("test_MC.root");
  TFile *f4 = TFile::Open("test_QCD_AllPtBins_7TeV_Pythia_1.root");
  TFile *f5 = TFile::Open("test_wjets_madgraph_vols_1.root");
  TFile *f6 = TFile::Open("test_zjets_madgraph_vols_1.root");
  //  TFile *f7 = TFile::Open("tot_jetmet.root");
  TFile *f7 = TFile::Open("new_data.root");
  //TFile *f7 = TFile::Open("tot_jet.root");
  TF1 *fa1 = new TF1("fa1","1",0,1000000);
  std::vector<string> names;
  names.clear();
  std::vector<string> namesh;
  std::vector<string> namesc;
  TH1D* h1;
  TH1D* h2;
  TH1D* h3;
  TH1D* h4;
  TH1D* h5;
  TH1D* h6;
  TH1D* h7;
  f7->cd();
  TDirectory *dir = gDirectory;
  TIter next(dir->GetListOfKeys());
  TKey *key;
  gStyle->SetFrameFillColor(0);
  gStyle->SetStatColor(0);
  gStyle->SetStatBorderSize(0);
  gStyle->SetStatFont(42);
  gStyle->SetStatStyle(0);
  //  gStyle->SetOptStat(1110);
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  TCanvas *c1 = new TCanvas();
  c1->SetFillColor(0);
  c1->SetLogy(1);
  while ((key = (TKey*)next())) {
    if (key->IsFolder()) {
      names.push_back(key->GetName());
    }
  }
  for (unsigned int i=0; i<names.size();i++){
    std::cout << i+1 << " " << names[i] << endl; 
    f7->cd(names[i].c_str());
    TDirectory *dir1 = gDirectory;
    TIter next1(dir1->GetListOfKeys());
    namesh.clear();
    namesc.clear();
    while ((key = (TKey*)next1())) {
      namesh.push_back(key->GetName());
      namesc.push_back(key->GetClassName());
    }
    for(unsigned int j=0; j<namesh.size();j++){
      std::cout << "\t" << j+1 << " " << namesh[j] << " class " << namesc[j] << endl; 
      if(namesc[j] == "TH1D"){
	string temp,exit;
	temp = names[i]+"/"+namesh[j];
	exit =  "plots/" + names[i]+"_"+namesh[j]+".png";
	h1 =(TH1D*)f1->Get(temp.c_str());
	h2 =(TH1D*)f2->Get(temp.c_str());
	h3 =(TH1D*)f3->Get(temp.c_str());
	h4 =(TH1D*)f4->Get(temp.c_str());
	h5 =(TH1D*)f5->Get(temp.c_str());
	h6 =(TH1D*)f6->Get(temp.c_str());
	h7 =(TH1D*)f7->Get(temp.c_str());
	h7->Sumw2();
	//h7->Multiply(fa1,1);
	double mc_weight;
	//	double mc_ev = h3->GetIntegral();
	double gev_lm0 = 207533;
	double gev_qcd = 24905592;
	double gev_wjets = 10034822;
	double gev_zjets = 1084921;
	double gev_tt = 1282199;
	double gev_mc = gev_lm0 +  gev_qcd + gev_wjets + gev_zjets + gev_tt;
	double rev_mc = h3->GetEntries();
	double rev_tt = h2->GetEntries();
	double rev_lm0 = h1->GetEntries();
	double rev_qcd =h4->GetEntries();
	double rev_wjets = h5->GetEntries();
	double rev_zjets =h6->GetEntries();
	double w_lm0 = rev_lm0/gev_lm0;
	double w_qcd = rev_qcd/gev_qcd;
	double w_tt = rev_tt/gev_tt;
	double w_wjets = rev_wjets/gev_wjets;
	double w_zjets = rev_zjets/gev_zjets;
	double w_mc = rev_mc/gev_mc;
	//	if(mc_ev != 0)
	//	  mc_weight = (double)1/mc_ev;
	//	else
	//	  continue;
	double data_weight = 27.5/57.;
	//	double data_ev = h7->GetIntegral();
	//	if(data_ev != 0)
	//	  data_weight = (double)1/data_ev;
	//	else
	//	  data_weight = 1;
	h3->SetFillColor(2);
	h3->GetXaxis()->SetLabelFont(42);
	h3->GetXaxis()->SetTitleFont(42);
	h3->GetXaxis()->SetTitle(namesh[j].c_str());
	h3->GetYaxis()->SetTitle("N.Events");
	h3->GetYaxis()->SetTitleFont(42);
	h3->GetYaxis()->SetLabelFont(42);
	h3->SetLineColor(2);
	h3->SetLineStyle(1);
	h3->SetLineWidth(2);
	TLegend *legend = new TLegend(0.65,0.7,0.85,0.9,"");
	legend->AddEntry(h3,"All MC data", "f");
	legend->AddEntry(h2,"TTBar", "f");
	legend->AddEntry(h1,"LM0", "f");
	legend->AddEntry(h4,"QCD Phytia", "f");
	legend->AddEntry(h5,"WJets Madgraph", "f");
	legend->AddEntry(h6,"ZJets Madgraph", "f");
	legend->AddEntry(h7,"All Data", "f");
	legend->SetFillColor(0);
	legend->SetTextFont(42);
	h1->SetFillColor(7);
	h1->SetLineColor(7);
	h1->SetLineStyle(2);
	h1->SetLineWidth(2);
	h2->SetFillColor(3);
	h2->SetLineColor(3);
	h2->SetLineStyle(3);
	h2->SetLineWidth(2);
	h4->SetFillColor(4);
	h4->SetLineColor(4);
	h4->SetLineStyle(4);
	h4->SetLineWidth(2);
	h5->SetFillColor(5);
	h5->SetLineColor(5);
	h5->SetLineStyle(5);
	h5->SetLineWidth(2);
	h6->SetFillColor(6);
	h6->SetLineColor(6);
	h6->SetLineStyle(6);
	h6->SetLineWidth(2);
	h7->SetFillColor(0);
	h7->SetLineColor(1);
	h7->SetLineStyle(7);
	h7->SetLineWidth(2);
	h3->Scale(data_weight);
	h1->Scale(data_weight);
	h6->Scale(data_weight);
	h5->Scale(data_weight);
	h4->Scale(data_weight);
	h2->Scale(data_weight);
	h3->GetYaxis()->SetRangeUser(0.0001,1e6);
	h3->Draw("");
	h4->Draw("SAME");
	h5->Draw("SAME");
	h6->Draw("SAME");
	h2->Draw("SAME");
	h1->Draw("SAME");
	h7->Draw("SAME");
	legend->Draw("SAME");
	c1->SaveAs(exit.c_str());
      }
    }
  }
}
