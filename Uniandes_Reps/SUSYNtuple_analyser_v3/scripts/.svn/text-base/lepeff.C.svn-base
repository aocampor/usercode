#include <string>
#include <stdlib>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
void LepEff(string rootfile,string rootfile1){
  TFile *f1 = TFile::Open(rootfile.c_str());
  TFile *f2 = TFile::Open(rootfile1.c_str());
  TH1F* h1 = (TH1F*)f1->Get("lepeff/CaloTightInvMass");
  TH1F* h2 = (TH1F*)f2->Get("susytree/CaloTightInvMass");
  double factor = (h1->Integral(60,80)+h1->Integral(100,120))/h1->Integral(80,100);
  double factor1 = (h2->Integral(60,80)+h2->Integral(100,120))/h2->Integral(80,100);
  TH1F* hcmapt = (TH1F*) f1->Get("lepeff/PFCaloMuonAccepted_pt");
  TH1F* hcmept = (TH1F*) f1->Get("lepeff/PFCaloMuonEfficient_pt");
  TH1F* hcmapt1b = (TH1F*) f1->Get("lepeff/PFCaloMuonAccepted_1band_pt");
  TH1F* hcmept1b = (TH1F*) f1->Get("lepeff/PFCaloMuonEfficient_1band_pt");
  TH1F* hcmapt2b = (TH1F*) f1->Get("lepeff/PFCaloMuonAccepted_2band_pt");
  TH1F* hcmept2b = (TH1F*) f1->Get("lepeff/PFCaloMuonEfficient_2band_pt");

  TH1F* h2cmapt = (TH1F*) f2->Get("susytree/PFCaloMuonAccepted_pt");
  TH1F* h2cmept = (TH1F*) f2->Get("susytree/PFCaloMuonEfficient_pt");
  TH1F* h2cmapt1b = (TH1F*) f2->Get("susytree/PFCaloMuonAccepted_1band_pt");
  TH1F* h2cmept1b = (TH1F*) f2->Get("susytree/PFCaloMuonEfficient_1band_pt");
  TH1F* h2cmapt2b = (TH1F*) f2->Get("susytree/PFCaloMuonAccepted_2band_pt");
  TH1F* h2cmept2b = (TH1F*) f2->Get("susytree/PFCaloMuonEfficient_2band_pt");

  TH1F* hmgena = (TH1F*)f1->Get("lepeff/PFgenMuonAccepted_pt");
  TH1F* hmgene = (TH1F*)f1->Get("lepeff/PFgenMuonEfficient_pt");
  hmgena->Sumw2();
  hmgene->Sumw2();
  TCanvas *c1 = new TCanvas();
  c1->SetFillColor(0);
  TH1F* eff= new TH1F("eff","eff",40,0,200);
  TH1F* eff2= new TH1F("eff2","eff2",40,0,200);
  cout << "Muons " << endl;
  for(unsigned int i=0;i < hcmapt->GetXaxis()->GetNbins(); i++){
    float bincont = hcmapt->GetBinContent(i+1) - (hcmapt2b->GetBinContent(i+1)+hcmapt1b->GetBinContent(i+1))*factor;
    float bincont1 = hcmept->GetBinContent(i+1) - (hcmept2b->GetBinContent(i+1)+hcmept1b->GetBinContent(i+1))*factor;
    cout << "bin " << i+1 << " efficient " << hcmept->GetBinContent(i+1) << " background " << (hcmept2b->GetBinContent(i+1)+hcmept1b->GetBinContent(i+1))*factor << " total " << bincont1 << endl;  
    cout << "bin " << i+1 << " accepted " << hcmapt->GetBinContent(i+1) << " background " << (hcmapt2b->GetBinContent(i+1)+hcmapt1b->GetBinContent(i+1))*factor << " total " << bincont << endl;  
    if(bincont < 0)
      bincont = 0;
    if(bincont1 < 0)
      bincont1 = 0;
    if(bincont1 > bincont)
      bincont1 = bincont;
    if(bincont != 0){
      float p = bincont1/bincont;
      float n = bincont;
      eff->SetBinContent(i+1,p);
      eff->SetBinError(i+1,sqrt(p*(1-p)/n));
    }
  }

  for(unsigned int i=0;i < h2cmapt->GetXaxis()->GetNbins(); i++){
    float bincont = h2cmapt->GetBinContent(i+1) - (h2cmapt2b->GetBinContent(i+1)+h2cmapt1b->GetBinContent(i+1))*factor1;
    float bincont1 = h2cmept->GetBinContent(i+1) - (h2cmept2b->GetBinContent(i+1)+h2cmept1b->GetBinContent(i+1))*factor1;
    cout << "bin " << i+1 << " efficient " << h2cmept->GetBinContent(i+1) << " background " << (h2cmept2b->GetBinContent(i+1)+h2cmept1b->GetBinContent(i+1))*factor1 << " total " << bincont1 << endl;  
    cout << "bin " << i+1 << " accepted " << h2cmapt->GetBinContent(i+1) << " background " << (h2cmapt2b->GetBinContent(i+1)+h2cmapt1b->GetBinContent(i+1))*factor1 << " total " << bincont << endl;  
    if(bincont < 0)
      bincont = 0;
    if(bincont1 < 0)
      bincont1 = 0;
    if(bincont1 > bincont)
      bincont1 = bincont;
    if(bincont != 0){
      float p = bincont1/bincont;
      float n = bincont;
      eff2->SetBinContent(i+1,p);
      eff2->SetBinError(i+1,sqrt(p*(1-p)/n));
    }
  }

  hmgene->Divide(hmgena);
  hmgene->SetLineColor(2);
  hmgene->GetYaxis()->SetRangeUser(0,1);
  hmgene->GetXaxis()->SetRangeUser(0,150);

  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  hmgene->SetLineWidth(2);
  hmgene->SetMarkerColor(1);
  hmgene->SetMarkerStyle(21);
  hmgene->GetXaxis()->SetTitleFont(42);
  hmgene->GetXaxis()->SetLabelFont(42);
  hmgene->GetYaxis()->SetTitleFont(42);
  hmgene->GetYaxis()->SetLabelFont(42);
  hmgene->GetXaxis()->SetTitle("#mu P_{T} (GeV)");
  hmgene->GetYaxis()->SetTitle("#mu Rec #epsilon (P_{T})");
  c1->SetTicky(1);
  c1->SetTickx(1);
  gPad->SetGrid();
  //TF1 *fun1 = new TF1("fit1","[0]+[1]*TMath::Erf((x-[2])/[3]-1)",0,100);
  TF1 *fun1 = new TF1("fit1","[0]+[1]*exp(-x*[2])",0,100);
  //  TF1 *g1 = new TF1("m1","fit1",0,50);
  //  TF1 *g2 = new TF1("m2","fit1",50,200);
  //  TF1 *total = new TF1("mstotal","fit1(0)+m2(4)",0,200);
  hmgene->Draw();
  fun1->SetParameters(0.75,0.32,5,18);
  //  hmgene->Fit(g1,"R");
  //  hmgene->Fit(g2,"R+");
  //  Double_t par[8];
  //  g1->GetParameters(&par[0]);
  //  g1->GetParameters(&par[4]);
  //  total->SetParameters(par);
  //  hmgene->Fit(fit1,"R+");
  eff2->SetLineColor(4);

  eff->Draw("SAME");
  eff2->Draw("SAME");
  c1->SaveAs("efficiency_calomuons_pt.png");
  hmgene->Draw();
  c1->SaveAs("efficiency_genmuons_pt.png");

  TH1F* hcmaeta = (TH1F*) f1->Get("lepeff/PFCaloMuonAccepted_eta");
  TH1F* hcmeeta = (TH1F*) f1->Get("lepeff/PFCaloMuonEfficient_eta");
  TH1F* hcmaeta1b = (TH1F*) f1->Get("lepeff/PFCaloMuonAccepted_1band_eta");
  TH1F* hcmeeta1b = (TH1F*) f1->Get("lepeff/PFCaloMuonEfficient_1band_eta");
  TH1F* hcmaeta2b = (TH1F*) f1->Get("lepeff/PFCaloMuonAccepted_2band_eta");
  TH1F* hcmeeta2b = (TH1F*) f1->Get("lepeff/PFCaloMuonEfficient_2band_eta");

  TH1F* h2cmaeta = (TH1F*) f2->Get("susytree/PFCaloMuonAccepted_eta");
  TH1F* h2cmeeta = (TH1F*) f2->Get("susytree/PFCaloMuonEfficient_eta");
  TH1F* h2cmaeta1b = (TH1F*) f2->Get("susytree/PFCaloMuonAccepted_1band_eta");
  TH1F* h2cmeeta1b = (TH1F*) f2->Get("susytree/PFCaloMuonEfficient_1band_eta");
  TH1F* h2cmaeta2b = (TH1F*) f2->Get("susytree/PFCaloMuonAccepted_2band_eta");
  TH1F* h2cmeeta2b = (TH1F*) f2->Get("susytree/PFCaloMuonEfficient_2band_eta");

  TH1F* hmgenaeta = (TH1F*)f1->Get("lepeff/PFgenMuonAccepted_eta");
  TH1F* hmgeneeta = (TH1F*)f1->Get("lepeff/PFgenMuonEfficient_eta");
  hmgenaeta->Sumw2();
  hmgeneeta->Sumw2();
  TH1F* effeta= new TH1F("effeta","effeta",25,-2.5,2.5);
  TH1F* effeta2= new TH1F("effeta2","effeta2",25,-2.5,2.5);
  for(unsigned int i=0;i < hcmaeta->GetXaxis()->GetNbins(); i++){
    float bincont = hcmaeta->GetBinContent(i+1) - (hcmaeta2b->GetBinContent(i+1)+hcmaeta1b->GetBinContent(i+1))*factor;
    float bincont1 = hcmeeta->GetBinContent(i+1) - (hcmeeta2b->GetBinContent(i+1)+hcmeeta1b->GetBinContent(i+1))*factor;
    cout << "bin " << i+1 << " efficient " << hcmeeta->GetBinContent(i+1) << " background " << (hcmeeta2b->GetBinContent(i+1)+hcmeeta1b->GetBinContent(i+1))*factor << " total " << bincont1 << endl;  
    cout << "bin " << i+1 << " accepted " << hcmaeta->GetBinContent(i+1) << " background " << (hcmaeta2b->GetBinContent(i+1)+hcmaeta1b->GetBinContent(i+1))*factor << " total " << bincont << endl;  
    if(bincont < 0)
      bincont = 0;
    if(bincont1 < 0)
      bincont1 = 0;
    if(bincont1 > bincont)
      bincont1 = bincont;
    if(bincont != 0){
      float p = bincont1/bincont;
      float n = bincont;
      effeta->SetBinContent(i+1,p);
      effeta->SetBinError(i+1,sqrt(p*(1-p)/n));
    }
  }
  for(unsigned int i=0;i < h2cmaeta->GetXaxis()->GetNbins(); i++){
    float bincont = h2cmaeta->GetBinContent(i+1) - (h2cmaeta2b->GetBinContent(i+1)+h2cmaeta1b->GetBinContent(i+1))*factor1;
    float bincont1 = h2cmeeta->GetBinContent(i+1) - (h2cmeeta2b->GetBinContent(i+1)+h2cmeeta1b->GetBinContent(i+1))*factor1;
    cout << "bin " << i+1 << " efficient " << h2cmeeta->GetBinContent(i+1) << " background " << (h2cmeeta2b->GetBinContent(i+1)+h2cmeeta1b->GetBinContent(i+1))*factor << " total " << bincont1 << endl;  
    cout << "bin " << i+1 << " accepted " << h2cmaeta->GetBinContent(i+1) << " background " << (h2cmaeta2b->GetBinContent(i+1)+h2cmaeta1b->GetBinContent(i+1))*factor << " total " << bincont << endl;  
    if(bincont < 0)
      bincont = 0;
    if(bincont1 < 0)
      bincont1 = 0;
    if(bincont1 > bincont)
      bincont1 = bincont;
    if(bincont != 0){
      float p = bincont1/bincont;
      float n = bincont;
      effeta2->SetBinContent(i+1,p);
      effeta2->SetBinError(i+1,sqrt(p*(1-p)/n));
    }
  }

  hmgeneeta->Divide(hmgenaeta);
  hmgeneeta->SetLineColor(2);
  hmgeneeta->GetYaxis()->SetRangeUser(0,1);
  //  hmgeneeta->GetXaxis()->SetRangeUser(-2.5,2.5);
  hmgeneeta->SetLineWidth(2);
  hmgeneeta->SetMarkerColor(1);
  hmgeneeta->SetMarkerStyle(21);
  hmgeneeta->GetXaxis()->SetTitleFont(42);
  hmgeneeta->GetXaxis()->SetLabelFont(42);
  hmgeneeta->GetYaxis()->SetTitleFont(42);
  hmgeneeta->GetYaxis()->SetLabelFont(42);
  hmgeneeta->GetXaxis()->SetTitle("#mu #eta (GeV)");
  hmgeneeta->GetYaxis()->SetTitle("#mu Rec #epsilon (#eta)");
  hmgeneeta->Draw();
  effeta2->SetLineColor(3);
  effeta->Draw("SAME");
  effeta2->Draw("SAME");
  c1->SaveAs("efficiency_calomuons_eta.jpg");

  hmgeneeta->Draw();
  c1->SaveAs("efficiency_genmuons_eta.png");
  //////////electrons
  TH1F* he1 = (TH1F*)f1->Get("lepeff/ClusTightInvMass");
  cout << he1->Integral(60,80) << endl;
  cout << he1->Integral(80,100) << endl; 
  cout << he1->Integral(100,120) << endl;
  cout << sqrt(he1->Integral(60,80)*he1->Integral(100,120)) << endl;
  //  double factore = sqrt(he1->Integral(50,72)*he1->Integral(110,132))/he1->Integral(110,132);
  double factore = (he1->Integral(60,80)+he1->Integral(100,120))/he1->Integral(80,100);
  TH1F* hceapt = (TH1F*) f1->Get("lepeff/PFClusElectronAccepted_pt");
  TH1F* hceept = (TH1F*) f1->Get("lepeff/PFClusElectronEfficient_pt");
  TH1F* hceapt2b = (TH1F*) f1->Get("lepeff/PFClusElectronAccepted_2band_pt");
  TH1F* hceept2b = (TH1F*) f1->Get("lepeff/PFClusElectronEfficient_2band_pt");
  TH1F* hceapt1b = (TH1F*) f1->Get("lepeff/PFClusElectronAccepted_1band_pt");
  TH1F* hceept1b = (TH1F*) f1->Get("lepeff/PFClusElectronEfficient_1band_pt");
  TH1F* hegena = (TH1F*)f1->Get("lepeff/PFgenElectronAccepted_pt");
  TH1F* hegene = (TH1F*)f1->Get("lepeff/PFgenElectronEfficient_pt");
  hegena->Sumw2();
  hegene->Sumw2();
  TH1F* effe= new TH1F("effe","effe",40,0,200);
  cout << "Electrons " << endl;
  for(unsigned int i=0;i < hceapt->GetXaxis()->GetNbins(); i++){
    float bincont = hceapt->GetBinContent(i+1);// - (hceapt2b->GetBinContent(i+1)+hceapt1b->GetBinContent(i+1))*factore;
    float bincont1 = hceept->GetBinContent(i+1);// - (hceept2b->GetBinContent(i+1)+hceept1b->GetBinContent(i+1))*factore;
    cout << "bin " << i+1 << " efficient " << hceept->GetBinContent(i+1) << " background " << (hceept2b->GetBinContent(i+1)+hceept1b->GetBinContent(i+1))*factore << " total " << bincont1 << endl;  
    cout << "bin " << i+1 << " accepted " << hceapt->GetBinContent(i+1) << " background " << (hceapt2b->GetBinContent(i+1)+hceapt1b->GetBinContent(i+1))*factore << " total " << bincont << endl;  
    if(bincont < 0)
      bincont = 0;
    if(bincont1 < 0)
      bincont1 = 0;
    if(bincont1 > bincont)
      bincont1 = bincont;
    if(bincont != 0){
      float p = bincont1/bincont;
      float n = bincont;
      effe->SetBinContent(i+1,p);
      effe->SetBinError(i+1,sqrt(p*(1-p)/n));
    }
  }
  hegene->Divide(hegena);
  hegene->SetLineColor(2);
  //  cout << hcmapt->GetXaxis()->GetNbins() << endl;
  //  hcmapt->Add(hcmapt2b,-1*factor);
  //  hcmapt->Draw();
  //  c1->SaveAs("accep_calomuons_pt.jpg");
  //  hcmept->Add(hcmept2b,-1*factor);
  //  hcmept->Draw();
  //  c1->SaveAs("efficient_calomuons_pt.jpg");
  //  hcmept->Divide(hcmapt);
  //  TCanvas *c1 = new TCanvas();
  hegene->GetYaxis()->SetRangeUser(0,1);
  hegene->GetXaxis()->SetRangeUser(0,150);
  hegene->SetLineWidth(2);
  hegene->SetMarkerColor(1);
  hegene->SetMarkerStyle(21);
  hegene->GetXaxis()->SetTitleFont(42);
  hegene->GetXaxis()->SetLabelFont(42);
  hegene->GetYaxis()->SetTitleFont(42);
  hegene->GetYaxis()->SetLabelFont(42);
  hegene->GetXaxis()->SetTitle("e P_{T} (GeV)");
  hegene->GetYaxis()->SetTitle("e Rec #epsilon (P_{T})");
  hegene->Draw();
  effe->Draw("SAME");
  c1->SaveAs("efficiency_cluselec_pt.jpg");

  hegene->Draw();
  c1->SaveAs("efficiency_genelec_pt.png");

  TH1F* hceaeta = (TH1F*) f1->Get("lepeff/PFClusElectronAccepted_eta");
  TH1F* hceeeta = (TH1F*) f1->Get("lepeff/PFClusElectronEfficient_eta");
  TH1F* hceaeta1b = (TH1F*) f1->Get("lepeff/PFClusElectronAccepted_1band_eta");
  TH1F* hceeeta1b = (TH1F*) f1->Get("lepeff/PFClusElectronEfficient_1band_eta");
  TH1F* hceaeta2b = (TH1F*) f1->Get("lepeff/PFClusElectronAccepted_2band_eta");
  TH1F* hceeeta2b = (TH1F*) f1->Get("lepeff/PFClusElectronEfficient_2band_eta");
  TH1F* hegenaeta = (TH1F*)f1->Get("lepeff/PFgenElectronAccepted_eta");
  TH1F* hegeneeta = (TH1F*)f1->Get("lepeff/PFgenElectronEfficient_eta");
  hegenaeta->Sumw2();
  hegeneeta->Sumw2();
  TH1F* effeeta= new TH1F("effeeta","effeeta",25,-2.5,2.5);
  cout << "Electrons eta" << endl;
  for(unsigned int i=0;i < hceaeta->GetXaxis()->GetNbins(); i++){
    float bincont = hceaeta->GetBinContent(i+1) - (hceaeta2b->GetBinContent(i+1)+hceaeta1b->GetBinContent(i+1))*factore;
    float bincont1 = hceeeta->GetBinContent(i+1) - (hceeeta2b->GetBinContent(i+1)+hceeeta1b->GetBinContent(i+1))*factore;
    cout << "bin " << i+1 << " efficient " << hceeeta->GetBinContent(i+1) << " background " << (hceeeta2b->GetBinContent(i+1)+hceeeta1b->GetBinContent(i+1))*factore << " total " << bincont1 << endl;  
    cout << "bin " << i+1 << " accepted " << hceaeta->GetBinContent(i+1) << " background " << (hceaeta2b->GetBinContent(i+1)+hceaeta1b->GetBinContent(i+1))*factore << " total " << bincont << endl;  
    if(bincont < 0)
      bincont = 0;
    if(bincont1 < 0)
      bincont1 = 0;
    if(bincont1 > bincont)
      bincont1 = bincont;
    if(bincont != 0){
      float p = bincont1/bincont;
      float n = bincont;
      effeeta->SetBinContent(i+1,p);
      effeeta->SetBinError(i+1,sqrt(p*(1-p)/n));
    }
  }
  hegeneeta->Divide(hegenaeta);
  hegeneeta->SetLineColor(2);
  hegeneeta->GetYaxis()->SetRangeUser(0,1);
  //  hmgeneeta->GetXaxis()->SetRangeUser(-2.5,2.5);
  hegeneeta->SetLineWidth(2);
  hegeneeta->SetMarkerColor(1);
  hegeneeta->SetMarkerStyle(21);
  hegeneeta->GetXaxis()->SetTitleFont(42);
  hegeneeta->GetXaxis()->SetLabelFont(42);
  hegeneeta->GetYaxis()->SetTitleFont(42);
  hegeneeta->GetYaxis()->SetLabelFont(42);
  hegeneeta->GetXaxis()->SetTitle("e #eta (GeV)");
  hegeneeta->GetYaxis()->SetTitle("e Rec #epsilon (#eta)");
  hegeneeta->Draw();
  effeeta->Draw("SAME");
  c1->SaveAs("efficiency_cluselectrons_eta.jpg");

  hegeneeta->Draw();
  c1->SaveAs("efficiency_genelectrons_eta.png");

}
