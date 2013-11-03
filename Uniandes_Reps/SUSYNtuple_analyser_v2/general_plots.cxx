#include <string>
#include <stdlib>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
void genplots(string line,float xmin,float xmax,float ymin,float ymax, int blogx, int blogy){
  char *cstr,*p;
  string name;
  vector< TFile *> rfil;
  vector< TH1D*> hist;
  vector<char*> names;
  cstr = new char [line.size()+1];
  strcpy (cstr, line.c_str());
  p=strtok(cstr," ");
  unsigned int i =0;
  while (p!=NULL){
    names.push_back(p);
    p=strtok(NULL," ");
  }
  THStack *hs = new THStack("hs",names[names.size()-2]);
  for(i = 0; i<names.size()-2; i++){
    TFile *f1 = TFile::Open(names[i]);
    rfil.push_back( &f1 );
    TFolder *fol = f1->Get(names[names.size()-2]);
    TH1D* h1 = (TH1D*)fol->FindObject(names[names.size()-1]);
    hist.push_back(&h1);
    int k=0;
    k= 100-5*i;
    hist[i]->SetFillColor(k);
    hist[i]->SetLineColor(1);
    hist[i]->SetMarkerColor(k);
    hist[i]->SetMarkerStyle(20);
    //hist[i]->Rebin(1);
    if(i != names.size()-3)
      hs->Add(hist[i]);
    else{
      hist[i]->SetFillColor(1);
      hist[i]->SetLineColor(2);
      hist[i]->SetMarkerColor(1);
      hist[i]->SetMarkerStyle(23);
    }
    f1->Close();
  }
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
  if(blogy ==1)
    c1->SetLogy(1);
  if(blogx ==1)
    c1->SetLogx(1);
  c1->SetTickx(1);
  c1->SetTicky(1);
  c1->SetRightMargin(0.37);
  hist[names.size()-3]->GetXaxis()->SetLabelFont(42);
  hist[names.size()-3]->GetXaxis()->SetTitleFont(42);
  hist[names.size()-3]->GetXaxis()->SetTitle(names[names.size()-1]);
  hist[names.size()-3]->GetYaxis()->SetTitle("N.Events");
  hist[names.size()-3]->GetYaxis()->SetTitleFont(42);
  hist[names.size()-3]->GetYaxis()->SetLabelFont(42);
  hist[names.size()-3]->GetYaxis()->SetRangeUser(ymin,ymax);
  hist[names.size()-3]->GetXaxis()->SetRangeUser(xmin,xmax);
  //hist[names.size()-3]->SetFillColor(2);
  hist[names.size()-3]->SetLineColor(2);
  hist[names.size()-3]->SetMarkerColor(1);
  hist[names.size()-3]->SetMarkerStyle(23);
  //  hist[0]->SetLineStyle(1);
  //  hist[names.size()-3]->SetLineWidth(2);
  TLegend *legend = new TLegend(0.65,0.3,1,0.8,"");
  for(i=0;i<names.size()-2;i++){
    cstr = new char [100];
    strcpy (cstr, names[i]);
    p=strtok(cstr,"/");
    char *tem;
    while (p!=NULL){
      tem=p;
      p=strtok(NULL,"/");
    }
    //legend->AddEntry(hist[i],names[i], "f");
    legend->AddEntry(hist[i],tem, "f");
  }
  legend->SetFillColor(0);
  legend->SetTextFont(42);
  hist[names.size()-3]->Draw();
  hs->Draw("stack,SAME");
  legend->Draw("SAME");
  hist[names.size()-3]->Draw("SAME");
  c1->SaveAs("stack.gif");
  delete[] cstr;    
}
