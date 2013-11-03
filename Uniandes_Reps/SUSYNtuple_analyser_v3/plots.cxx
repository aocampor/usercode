#include <string>
#include <stdlib>
#include <sstream>
#include <algorithm>
#include <iterator>
void plots(string input,string out_pre){
  //  std::cout << "argv " << argv.c_str() << std::endl;
  //  TFile *f1 = TFile::Open("/Volumes/Untitled/data/SUSYTree/OUT/Salida_LM0_temp.root");
  TFile *f1 = TFile::Open(input.c_str());
  TH1F *h1,*h2,*h3,*h4;
  std::string out="";
  /////////////Two Jets comparison PF vs Calo
  TFolder *fol1;
  fol1 = (TFolder*)f1->Get("Alphat");
  h1=(TH1F*)fol1->FindObject("AlphaT_2Jets_case");
  h2=(TH1F*)fol1->FindObject("AlphaT_2PFJets_case");
  TCanvas *c1 =new  TCanvas();
  gStyle->SetOptStat(1110);
  gStyle->SetOptTitle(0);
  gStyle->SetFillColor(0);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  c1->SetFillColor(0);
  TPad *pad1 = new TPad("pad1","",0,0,1,1);
  TPad *pad2 = new TPad("pad2","",0,0,1,1);
  TLegend *legend = new TLegend(0.65,0.6,0.85,0.8,"");
  legend->AddEntry(h1,"#alpha_{T} 2 Calo Jets case", "f");
  legend->AddEntry(h2,"#alpha_{T} 2 PF Jets case", "f");
  legend->SetTextFont(42);
  pad2->SetFillStyle(4000); //will be transparent
  Double_t ymin = 4e-3;
  Double_t ymax = 100;
  Double_t dy = (ymax-ymin)/0.8; //10 per cent margins top and bottom
  Double_t xmin = 5e-3;
  Double_t xmax = 20;
  Double_t dx = (xmax-xmin)/0.8; //10 per cent margins left and right
  pad1->Range(xmin-0.1*dx,ymin-0.1*dy,xmax+0.1*dx,ymax+0.1*dy);
  pad1->SetFillColor(0);
  pad2->SetFillColor(0);
  pad1->Draw();
  pad1->cd();
  pad1->SetLogy(1);
  pad1->SetLogx(0);
  pad2->Range(xmin-0.1*dx,ymin-0.1*dy,xmax+0.1*dx,ymax+0.1*dy);
  pad2->Draw();
  pad2->cd();
  h2->SetLineColor(2);
  h1->GetXaxis()->SetLabelFont(42);
  h1->GetXaxis()->SetTitleFont(42);
  h1->GetXaxis()->SetTitle("#alpha_{T}");
  h1->GetYaxis()->SetLabelFont(42);
  h1->GetYaxis()->SetTitleFont(42);
  h1->GetYaxis()->SetTitle("N. Entries/34 pb^{-1}");
  c1->SetFillColor(0);
  gStyle->SetOptStat(1110);
  gStyle->SetOptTitle(0);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  h1->Draw("");
  pad1->Update();
  TPaveStats *ps1 = (TPaveStats*)h1->GetListOfFunctions()->FindObject("stats");
  ps1->SetX1NDC(0.15); 
  ps1->SetX2NDC(0.35);
  ps1->SetY1NDC(0.6); 
  ps1->SetY2NDC(0.8);
  ps1->SetBorderSize(0);
  ps1->SetTextFont(42);
  ps1->SetFillColor(0);
  pad1->Modified();
  pad2->Draw();
  pad2->cd();
  pad2->SetLogy(1);
  pad2->SetLogx(0);
  h2->Draw("SAMES");
  pad2->Update();
  TPaveStats *ps2 = (TPaveStats*)h2->GetListOfFunctions()->FindObject("stats");
  ps2->SetX1NDC(0.15); ps2->SetX2NDC(0.35);
  ps2->SetY1NDC(0.4); ps2->SetY2NDC(0.6);
  ps2->SetTextColor(kRed);
  ps2->SetBorderSize(0);
  ps2->SetTextFont(42);
  ps2->SetFillColor(0);
  legend->Draw("SAMES");
  out = "plots/"+out_pre+"_PF_vs_Calo_twoJets_alphat.png";
  c1->SaveAs(out.c_str());

  //////////////////////N jets comparison minimum DeltaHT PF vs calo

  h3=(TH1F*)fol1->FindObject("Alphat_njets_case_minimum_deltaht");
  h4=(TH1F*)fol1->FindObject("Alphat_nPFjets_case_minimum_deltaht");
  TPad *pad1 = new TPad("pad1","",0,0,1,1);
  TPad *pad2 = new TPad("pad2","",0,0,1,1);
  TLegend *legend = new TLegend(0.65,0.6,0.85,0.8,"");
  legend->AddEntry(h3,"#alpha_{T} Calo Jets > 2 jets", "f");
  legend->AddEntry(h4,"#alpha_{T} PF Jets > 2 jets", "f");
  legend->SetTextFont(42);
  pad2->SetFillStyle(4000); //will be transparent
  Double_t ymin = 4e-3;
  Double_t ymax = 100;
  Double_t dy = (ymax-ymin)/0.8; //10 per cent margins top and bottom
  Double_t xmin = 5e-3;
  Double_t xmax = 20;
  Double_t dx = (xmax-xmin)/0.8; //10 per cent margins left and right
  pad1->Range(xmin-0.1*dx,ymin-0.1*dy,xmax+0.1*dx,ymax+0.1*dy);
  pad1->SetFillColor(0);
  pad2->SetFillColor(0);
  pad1->Draw();
  pad1->cd();
  pad1->SetLogy(1);
  pad1->SetLogx(0);
  pad2->Range(xmin-0.1*dx,ymin-0.1*dy,xmax+0.1*dx,ymax+0.1*dy);
  pad2->Draw();
  pad2->cd();
  h4->SetLineColor(2);
  h3->GetXaxis()->SetLabelFont(42);
  h3->GetXaxis()->SetTitleFont(42);
  h3->GetXaxis()->SetTitle("#alpha_{T} min #Delta HT");
  h3->GetYaxis()->SetLabelFont(42);
  h3->GetYaxis()->SetTitleFont(42);
  h3->GetYaxis()->SetTitle("N. Entries/34 pb^{-1}");
  c1->SetFillColor(0);
  gStyle->SetOptStat(1110);
  gStyle->SetOptTitle(0);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  h3->Draw("");
  pad1->Update();
  TPaveStats *ps1 = (TPaveStats*)h3->GetListOfFunctions()->FindObject("stats");
  ps1->SetX1NDC(0.15); 
  ps1->SetX2NDC(0.35);
  ps1->SetY1NDC(0.6); 
  ps1->SetY2NDC(0.8);
  ps1->SetBorderSize(0);
  ps1->SetTextFont(42);
  ps1->SetFillColor(0);
  pad1->Modified();
  pad2->Draw();
  pad2->cd();
  pad2->SetLogy(1);
  pad2->SetLogx(0);
  h4->Draw("SAMES");
  pad2->Update();
  TPaveStats *ps2 = (TPaveStats*)h4->GetListOfFunctions()->FindObject("stats");
  ps2->SetX1NDC(0.15); ps2->SetX2NDC(0.35);
  ps2->SetY1NDC(0.4); ps2->SetY2NDC(0.6);
  ps2->SetTextColor(kRed);
  ps2->SetBorderSize(0);
  ps2->SetTextFont(42);
  ps2->SetFillColor(0);
  legend->Draw("SAMES");
  out = "plots/"+out_pre+"_PF_vs_Calo_nJets_alphat_minHT.png";
  c1->SaveAs(out.c_str());

  ///////////////////Njets calo jets min deltaht vs reclustered

  h3=(TH1F*)fol1->FindObject("Alphat_njets_case_minimum_deltaht");
  h4=(TH1F*)fol1->FindObject("Alphat_njets_case_as_reclustered");
  TPad *pad1 = new TPad("pad1","",0,0,1,1);
  TPad *pad2 = new TPad("pad2","",0,0,1,1);
  TLegend *legend = new TLegend(0.65,0.6,0.85,0.8,"");
  legend->AddEntry(h3,"#alpha_{T} > 2 jets min #Delta HT", "f");
  legend->AddEntry(h4,"#alpha_{T} > 2 jets reclustered", "f");
  legend->SetTextFont(42);
  pad2->SetFillStyle(4000); //will be transparent
  Double_t ymin = 4e-3;
  Double_t ymax = 100;
  Double_t dy = (ymax-ymin)/0.8; //10 per cent margins top and bottom
  Double_t xmin = 5e-3;
  Double_t xmax = 20;
  Double_t dx = (xmax-xmin)/0.8; //10 per cent margins left and right
  pad1->Range(xmin-0.1*dx,ymin-0.1*dy,xmax+0.1*dx,ymax+0.1*dy);
  pad1->SetFillColor(0);
  pad2->SetFillColor(0);
  pad1->Draw();
  pad1->cd();
  pad1->SetLogy(1);
  pad1->SetLogx(0);
  pad2->Range(xmin-0.1*dx,ymin-0.1*dy,xmax+0.1*dx,ymax+0.1*dy);
  pad2->Draw();
  pad2->cd();
  h4->SetLineColor(2);
  h3->GetXaxis()->SetLabelFont(42);
  h3->GetXaxis()->SetTitleFont(42);
  h3->GetXaxis()->SetTitle("#alpha_{T} Calo Jets");
  h3->GetYaxis()->SetLabelFont(42);
  h3->GetYaxis()->SetTitleFont(42);
  h3->GetYaxis()->SetTitle("N. Entries/34 pb^{-1}");
  c1->SetFillColor(0);
  gStyle->SetOptStat(1110);
  gStyle->SetOptTitle(0);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  h3->Draw("");
  pad1->Update();
  TPaveStats *ps1 = (TPaveStats*)h3->GetListOfFunctions()->FindObject("stats");
  ps1->SetX1NDC(0.15); 
  ps1->SetX2NDC(0.35);
  ps1->SetY1NDC(0.6); 
  ps1->SetY2NDC(0.8);
  ps1->SetBorderSize(0);
  ps1->SetTextFont(42);
  ps1->SetFillColor(0);
  pad1->Modified();
  pad2->Draw();
  pad2->cd();
  pad2->SetLogy(1);
  pad2->SetLogx(0);
  h4->Draw("SAMES");
  pad2->Update();
  TPaveStats *ps2 = (TPaveStats*)h4->GetListOfFunctions()->FindObject("stats");
  ps2->SetX1NDC(0.15); ps2->SetX2NDC(0.35);
  ps2->SetY1NDC(0.4); ps2->SetY2NDC(0.6);
  ps2->SetTextColor(kRed);
  ps2->SetBorderSize(0);
  ps2->SetTextFont(42);
  ps2->SetFillColor(0);
  legend->Draw("SAMES");
  out = "plots/"+out_pre+"_Calo_nJets_alphat_minHT_vs_reclustered.png";
  c1->SaveAs(out.c_str());

  ///////////////////Njets PF jets min deltaht vs reclustered

  h3=(TH1F*)fol1->FindObject("Alphat_nPFjets_case_minimum_deltaht");
  h4=(TH1F*)fol1->FindObject("Alphat_nPFjets_case_as_reclustered");
  TPad *pad1 = new TPad("pad1","",0,0,1,1);
  TPad *pad2 = new TPad("pad2","",0,0,1,1);
  TLegend *legend = new TLegend(0.65,0.6,0.85,0.8,"");
  legend->AddEntry(h3,"#alpha_{T} > 2 jets min #Delta HT", "f");
  legend->AddEntry(h4,"#alpha_{T} > 2 jets reclustered", "f");
  legend->SetTextFont(42);
  pad2->SetFillStyle(4000); //will be transparent
  Double_t ymin = 4e-3;
  Double_t ymax = 100;
  Double_t dy = (ymax-ymin)/0.8; //10 per cent margins top and bottom
  Double_t xmin = 5e-3;
  Double_t xmax = 20;
  Double_t dx = (xmax-xmin)/0.8; //10 per cent margins left and right
  pad1->Range(xmin-0.1*dx,ymin-0.1*dy,xmax+0.1*dx,ymax+0.1*dy);
  pad1->SetFillColor(0);
  pad2->SetFillColor(0);
  pad1->Draw();
  pad1->cd();
  pad1->SetLogy(1);
  pad1->SetLogx(0);
  pad2->Range(xmin-0.1*dx,ymin-0.1*dy,xmax+0.1*dx,ymax+0.1*dy);
  pad2->Draw();
  pad2->cd();
  h4->SetLineColor(2);
  h3->SetLineColor(1);
  h3->GetXaxis()->SetLabelFont(42);
  h3->GetXaxis()->SetTitleFont(42);
  h3->GetXaxis()->SetTitle("#alpha_{T} PF Jets");
  h3->GetYaxis()->SetLabelFont(42);
  h3->GetYaxis()->SetTitleFont(42);
  h3->GetYaxis()->SetTitle("N. Entries/34 pb^{-1}");
  c1->SetFillColor(0);
  gStyle->SetOptStat(1110);
  gStyle->SetOptTitle(0);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  h3->Draw("");
  pad1->Update();
  TPaveStats *ps1 = (TPaveStats*)h3->GetListOfFunctions()->FindObject("stats");
  ps1->SetX1NDC(0.15); 
  ps1->SetX2NDC(0.35);
  ps1->SetY1NDC(0.6); 
  ps1->SetY2NDC(0.8);
  ps1->SetBorderSize(0);
  ps1->SetTextFont(42);
  ps1->SetTextColor(1);
  ps1->SetFillColor(0);
  pad1->Modified();
  pad2->Draw();
  pad2->cd();
  pad2->SetLogy(1);
  pad2->SetLogx(0);
  h4->Draw("SAMES");
  pad2->Update();
  TPaveStats *ps2 = (TPaveStats*)h4->GetListOfFunctions()->FindObject("stats");
  ps2->SetX1NDC(0.15); ps2->SetX2NDC(0.35);
  ps2->SetY1NDC(0.4); ps2->SetY2NDC(0.6);
  ps2->SetTextColor(kRed);
  ps2->SetBorderSize(0);
  ps2->SetTextFont(42);
  ps2->SetFillColor(0);
  legend->Draw("SAMES");
  out = "plots/"+out_pre+"_PF_nJets_alphat_minHT_vs_reclustered.png";
  c1->SaveAs(out.c_str());

  ///////////////////Njets PF vs Calo jets alphat reclustered

  h3=(TH1F*)fol1->FindObject("Alphat_njets_case_as_reclustered");
  h4=(TH1F*)fol1->FindObject("Alphat_nPFjets_case_as_reclustered");
  TPad *pad1 = new TPad("pad1","",0,0,1,1);
  TPad *pad2 = new TPad("pad2","",0,0,1,1);
  TLegend *legend = new TLegend(0.65,0.6,0.85,0.8,"");
  legend->AddEntry(h3,"#alpha_{T} > 2 Calo jets", "f");
  legend->AddEntry(h4,"#alpha_{T} > 2 PF jets", "f");
  legend->SetTextFont(42);
  pad2->SetFillStyle(4000); //will be transparent
  Double_t ymin = 4e-3;
  Double_t ymax = 100;
  Double_t dy = (ymax-ymin)/0.8; //10 per cent margins top and bottom
  Double_t xmin = 5e-3;
  Double_t xmax = 20;
  Double_t dx = (xmax-xmin)/0.8; //10 per cent margins left and right
  pad1->Range(xmin-0.1*dx,ymin-0.1*dy,xmax+0.1*dx,ymax+0.1*dy);
  pad1->SetFillColor(0);
  pad2->SetFillColor(0);
  pad1->SetFillColor(0);
  pad2->SetFillColor(0);
  pad1->Draw();
  pad1->cd();
  pad1->SetLogy(1);
  pad1->SetLogx(0);
  pad2->Range(xmin-0.1*dx,ymin-0.1*dy,xmax+0.1*dx,ymax+0.1*dy);
  pad2->Draw();
  pad2->cd();
  h4->SetLineColor(2);
  h3->SetLineColor(1);
  h3->GetXaxis()->SetLabelFont(42);
  h3->GetXaxis()->SetTitleFont(42);
  h3->GetXaxis()->SetTitle("#alpha_{T} reclustered");
  h3->GetYaxis()->SetLabelFont(42);
  h3->GetYaxis()->SetTitleFont(42);
  h3->GetYaxis()->SetTitle("N. Entries/34 pb^{-1}");
  c1->SetFillColor(0);
  gStyle->SetOptStat(1110);
  gStyle->SetOptTitle(0);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  h3->Draw("");
  pad1->Update();
  TPaveStats *ps1 = (TPaveStats*)h3->GetListOfFunctions()->FindObject("stats");
  ps1->SetX1NDC(0.15); 
  ps1->SetX2NDC(0.35);
  ps1->SetY1NDC(0.6); 
  ps1->SetY2NDC(0.8);
  ps1->SetBorderSize(0);
  ps1->SetTextFont(42);
  ps1->SetTextColor(1);
  ps1->SetFillColor(0);
  pad1->Modified();
  pad2->Draw();
  pad2->cd();
  pad2->SetLogy(1);
  pad2->SetLogx(0);
  h4->Draw("SAMES");
  pad2->Update();
  TPaveStats *ps2 = (TPaveStats*)h4->GetListOfFunctions()->FindObject("stats");
  ps2->SetX1NDC(0.15); ps2->SetX2NDC(0.35);
  ps2->SetY1NDC(0.4); ps2->SetY2NDC(0.6);
  ps2->SetTextColor(kRed);
  ps2->SetBorderSize(0);
  ps2->SetTextFont(42);
  ps2->SetFillColor(0);
  legend->Draw("SAMES");
  out = "plots/"+out_pre+"_PF_vs_Calo_nJets_alphat_reclustered.png";
  c1->SaveAs(out.c_str());

}
