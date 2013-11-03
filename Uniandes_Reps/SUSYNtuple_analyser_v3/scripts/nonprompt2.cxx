#include <string>
#include <stdlib>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
void nonprompt2(string rootfile1,string rootfile2,string rootfile3,string rootfile4,string rootfile5,string rootfile6,string rootfile7,string rootfile8){
 
  float lum =35;
  float w1 =0.01122*lum/1116957;
  float w2 =8.76e8*lum/6098303;
  float w3 =25470*lum/3063982;
  float w4 =923800*lum/3071012;
  float w5 =2.186*lum/2172418;
  float w6 =6.04e7*lum/5168756;
  float w7 =1256*lum/3261713;
  float w8 =87.98*lum/2099775;

  TFile *f1 = TFile::Open(rootfile1.c_str());
  TFile *f2 = TFile::Open(rootfile2.c_str());
  TFile *f3 = TFile::Open(rootfile3.c_str());
  TFile *f4 = TFile::Open(rootfile4.c_str());
  TFile *f5 = TFile::Open(rootfile5.c_str());
  TFile *f6 = TFile::Open(rootfile6.c_str());
  TFile *f7 = TFile::Open(rootfile7.c_str());
  TFile *f8 = TFile::Open(rootfile8.c_str());

  TFolder *fol11 = f1->Get("Electron");
  TFolder *fol21 = f2->Get("Electron");
  TFolder *fol31 = f3->Get("Electron");
  TFolder *fol41 = f4->Get("Electron");
  TFolder *fol51 = f5->Get("Electron");
  TFolder *fol61 = f6->Get("Electron");
  TFolder *fol71 = f7->Get("Electron");
  TFolder *fol81 = f8->Get("Electron");

  TFolder *fol12 = f1->Get("Muon");
  TFolder *fol22 = f2->Get("Muon");
  TFolder *fol32 = f3->Get("Muon");
  TFolder *fol42 = f4->Get("Muon");
  TFolder *fol52 = f5->Get("Muon");
  TFolder *fol62 = f6->Get("Muon");
  TFolder *fol72 = f7->Get("Muon");
  TFolder *fol82 = f8->Get("Muon");

  TFolder *fol13 = f1->Get("Tau");
  TFolder *fol23 = f2->Get("Tau");
  TFolder *fol33 = f3->Get("Tau");
  TFolder *fol43 = f4->Get("Tau");
  TFolder *fol53 = f5->Get("Tau");
  TFolder *fol63 = f6->Get("Tau");
  TFolder *fol73 = f7->Get("Tau");
  TFolder *fol83 = f8->Get("Tau");

  TH2D* h11 = fol11->FindObject("Loose_PFElectrons_pt_eta");
  TH2D* h12 = fol11->FindObject("Tight_PFElectrons_pt_eta");
  TH2D* h13 = fol12->FindObject("Loose_PFMuons_pt_eta");
  TH2D* h14 = fol12->FindObject("Tight_PFMuons_pt_eta");
  TH2D* h15 = fol13->FindObject("Loose_PFTau_pt_eta");
  TH2D* h16 = fol13->FindObject("Tight_PFTau_pt_eta");

  TH2D* h21 = fol21->FindObject("Loose_PFElectrons_pt_eta");
  TH2D* h22 = fol21->FindObject("Tight_PFElectrons_pt_eta");
  TH2D* h23 = fol22->FindObject("Loose_PFMuons_pt_eta");
  TH2D* h24 = fol22->FindObject("Tight_PFMuons_pt_eta");
  TH2D* h25 = fol23->FindObject("Loose_PFTau_pt_eta");
  TH2D* h26 = fol23->FindObject("Tight_PFTau_pt_eta");

  TH2D* h31 = fol31->FindObject("Loose_PFElectrons_pt_eta");
  TH2D* h32 = fol31->FindObject("Tight_PFElectrons_pt_eta");
  TH2D* h33 = fol32->FindObject("Loose_PFMuons_pt_eta");
  TH2D* h34 = fol32->FindObject("Tight_PFMuons_pt_eta");
  TH2D* h35 = fol33->FindObject("Loose_PFTau_pt_eta");
  TH2D* h36 = fol33->FindObject("Tight_PFTau_pt_eta");

  TH2D* h41 = fol41->FindObject("Loose_PFElectrons_pt_eta");
  TH2D* h42 = fol41->FindObject("Tight_PFElectrons_pt_eta");
  TH2D* h43 = fol42->FindObject("Loose_PFMuons_pt_eta");
  TH2D* h44 = fol42->FindObject("Tight_PFMuons_pt_eta");
  TH2D* h45 = fol43->FindObject("Loose_PFTau_pt_eta");
  TH2D* h46 = fol43->FindObject("Tight_PFTau_pt_eta");

  TH2D* h51 = fol51->FindObject("Loose_PFElectrons_pt_eta");
  TH2D* h52 = fol51->FindObject("Tight_PFElectrons_pt_eta");
  TH2D* h53 = fol52->FindObject("Loose_PFMuons_pt_eta");
  TH2D* h54 = fol52->FindObject("Tight_PFMuons_pt_eta");
  TH2D* h55 = fol53->FindObject("Loose_PFTau_pt_eta");
  TH2D* h56 = fol53->FindObject("Tight_PFTau_pt_eta");

  TH2D* h61 = fol61->FindObject("Loose_PFElectrons_pt_eta");
  TH2D* h62 = fol61->FindObject("Tight_PFElectrons_pt_eta");
  TH2D* h63 = fol62->FindObject("Loose_PFMuons_pt_eta");
  TH2D* h64 = fol62->FindObject("Tight_PFMuons_pt_eta");
  TH2D* h65 = fol63->FindObject("Loose_PFTau_pt_eta");
  TH2D* h66 = fol63->FindObject("Tight_PFTau_pt_eta");

  TH2D* h71 = fol71->FindObject("Loose_PFElectrons_pt_eta");
  TH2D* h72 = fol71->FindObject("Tight_PFElectrons_pt_eta");
  TH2D* h73 = fol72->FindObject("Loose_PFMuons_pt_eta");
  TH2D* h74 = fol72->FindObject("Tight_PFMuons_pt_eta");
  TH2D* h75 = fol73->FindObject("Loose_PFTau_pt_eta");
  TH2D* h76 = fol73->FindObject("Tight_PFTau_pt_eta");

  TH2D* h81 = fol81->FindObject("Loose_PFElectrons_pt_eta");
  TH2D* h82 = fol81->FindObject("Tight_PFElectrons_pt_eta");
  TH2D* h83 = fol82->FindObject("Loose_PFMuons_pt_eta");
  TH2D* h84 = fol82->FindObject("Tight_PFMuons_pt_eta");
  TH2D* h85 = fol83->FindObject("Loose_PFTau_pt_eta");
  TH2D* h86 = fol83->FindObject("Tight_PFTau_pt_eta");

  //  cout << h11->GetXaxis()->GetNbins() << " " << h11->GetYaxis()->GetNbins() << endl;
  TH2D* hel = new TH2D("Electron_TL","Electron_TL",100,0,500,24,-3,3);
  TH2D* hmu = new TH2D("Muon_TL","Muon_TL",100,0,500,24,-3,3);
  TH2D* hta = new TH2D("Tau_TL","Tau_TL",100,0,500,24,-3,3);

  for(unsigned int i =0;i<100;i++){
    for(unsigned int j=0;j<24;j++){
      float nume = 0, dene = 0;
      float numm = 0, denm = 0;
      float numt = 0, dent = 0;

      dene = w1*h11->GetBinContent(i,j) + w2*h21->GetBinContent(i,j) + w3*h31->GetBinContent(i,j) + w4*h41->GetBinContent(i,j) + w5*h51->GetBinContent(i,j) + w6*h61->GetBinContent(i,j) + w7*h71->GetBinContent(i,j) + w8*h81->GetBinContent(i,j);
      nume = w1*h12->GetBinContent(i,j) + w2*h22->GetBinContent(i,j) + w3*h32->GetBinContent(i,j) + w4*h42->GetBinContent(i,j) + w5*h52->GetBinContent(i,j) + w6*h62->GetBinContent(i,j) + w7*h72->GetBinContent(i,j) + w8*h82->GetBinContent(i,j);

      denm = w1*h13->GetBinContent(i,j) + w2*h23->GetBinContent(i,j) + w3*h33->GetBinContent(i,j) + w4*h43->GetBinContent(i,j) + w5*h53->GetBinContent(i,j) + w6*h63->GetBinContent(i,j) + w7*h73->GetBinContent(i,j) + w8*h83->GetBinContent(i,j);
      numm = w1*h14->GetBinContent(i,j) + w2*h24->GetBinContent(i,j) + w3*h34->GetBinContent(i,j) + w4*h44->GetBinContent(i,j) + w5*h54->GetBinContent(i,j) + w6*h64->GetBinContent(i,j) + w7*h74->GetBinContent(i,j) + w8*h84->GetBinContent(i,j);

      dent = w1*h15->GetBinContent(i,j) + w2*h25->GetBinContent(i,j) + w3*h35->GetBinContent(i,j) + w4*h45->GetBinContent(i,j) + w5*h55->GetBinContent(i,j) + w6*h65->GetBinContent(i,j) + w7*h75->GetBinContent(i,j) + w8*h85->GetBinContent(i,j);
      numt = w1*h16->GetBinContent(i,j) + w2*h26->GetBinContent(i,j) + w3*h36->GetBinContent(i,j) + w4*h46->GetBinContent(i,j) + w5*h56->GetBinContent(i,j) + w6*h66->GetBinContent(i,j) + w7*h76->GetBinContent(i,j) + w8*h86->GetBinContent(i,j);

      if(dene != 0 )
	hel->SetBinContent(i,j,nume/dene);
      if(denm != 0 )
	hmu->SetBinContent(i,j,numm/denm);
      if(dent != 0 )
	hta->SetBinContent(i,j,numt/dent);

    }
  }

  TCanvas *c1 = new TCanvas(); 
  //  c1->SetFillColor(0);
  gStyle->SetPalette(1);
  hel->Draw("COL");
  c1->SaveAs("ElectroTL.root");
  hmu->Draw("COL");
  c1->SaveAs("MuonTL.root");
  hta->Draw("COL");
  c1->SaveAs("TauTL.root");

  TH1D *helpt = new TH1D("ElectronTLPt","ElectronTLPt",100,0,500);
  TH1D *hmupt = new TH1D("MuonTLPt","MuonTLPt",100,0,500);
  TH1D *htapt = new TH1D("TauTLPt","TauTLPt",100,0,500);
  
  for(unsigned int i =0;i<100;i++){
    float nume = 0, dene = 0;
    float numm = 0, denm = 0;
    float numt = 0, dent = 0;
    for(unsigned int j=0;j<24;j++){
      dene = dene + w1*h11->GetBinContent(i,j) + w2*h21->GetBinContent(i,j) + w3*h31->GetBinContent(i,j) + w4*h41->GetBinContent(i,j) + w5*h51->GetBinContent(i,j) + w6*h61->GetBinContent(i,j) + w7*h71->GetBinContent(i,j) + w8*h81->GetBinContent(i,j);
      nume = nume + w1*h12->GetBinContent(i,j) + w2*h22->GetBinContent(i,j) + w3*h32->GetBinContent(i,j) + w4*h42->GetBinContent(i,j) + w5*h52->GetBinContent(i,j) + w6*h62->GetBinContent(i,j) + w7*h72->GetBinContent(i,j) + w8*h82->GetBinContent(i,j);
      
      denm = denm + w1*h13->GetBinContent(i,j) + w2*h23->GetBinContent(i,j) + w3*h33->GetBinContent(i,j) + w4*h43->GetBinContent(i,j) + w5*h53->GetBinContent(i,j) + w6*h63->GetBinContent(i,j) + w7*h73->GetBinContent(i,j) + w8*h83->GetBinContent(i,j);
      numm = numm + w1*h14->GetBinContent(i,j) + w2*h24->GetBinContent(i,j) + w3*h34->GetBinContent(i,j) + w4*h44->GetBinContent(i,j) + w5*h54->GetBinContent(i,j) + w6*h64->GetBinContent(i,j) + w7*h74->GetBinContent(i,j) + w8*h84->GetBinContent(i,j);
      
      dent = dent + w1*h15->GetBinContent(i,j) + w2*h25->GetBinContent(i,j) + w3*h35->GetBinContent(i,j) + w4*h45->GetBinContent(i,j) + w5*h55->GetBinContent(i,j) + w6*h65->GetBinContent(i,j) + w7*h75->GetBinContent(i,j) + w8*h85->GetBinContent(i,j);
      numt = numt + w1*h16->GetBinContent(i,j) + w2*h26->GetBinContent(i,j) + w3*h36->GetBinContent(i,j) + w4*h46->GetBinContent(i,j) + w5*h56->GetBinContent(i,j) + w6*h66->GetBinContent(i,j) + w7*h76->GetBinContent(i,j) + w8*h86->GetBinContent(i,j);
    }
    if(dene != 0 ){
      helpt->SetBinContent(i,nume/dene);
      helpt->SetBinError(i,sqrt((nume/dene)*(1-nume/dene)/dene));
    }
    if(denm != 0 ){
      hmupt->SetBinContent(i,numm/denm);
      hmupt->SetBinError(i,sqrt((numm/denm)*(1-numm/denm)/denm));
    }
    if(dent != 0 ){
      htapt->SetBinContent(i,numt/dent);
      htapt->SetBinError(i,sqrt((numt/dent)*(1-numt/dent)/dent));
    }
  }
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  helpt->GetXaxis()->SetLabelFont(42);
  helpt->GetXaxis()->SetTitleFont(42);
  helpt->GetYaxis()->SetLabelFont(42);
  helpt->GetYaxis()->SetTitleFont(42);
  helpt->GetYaxis()->SetTitle("e #epsilon (Tight/Loose)");
  helpt->GetXaxis()->SetTitle("e P_{T} (GeV)");
  helpt->GetYaxis()->SetRangeUser(0,1);
  helpt->GetXaxis()->SetRangeUser(0,100);
  //  gPad->SetLogy(1);
  gPad->SetTicky(1);
  gPad->SetTickx(1);

  helpt->SetMarkerColor(1);
  helpt->SetMarkerStyle(21);
  helpt->SetLineColor(2);
  helpt->SetLineWidth(2);
  helpt->Draw();
  c1->SaveAs("pt_ToverL_pfelectrons.png");
  hmupt->GetXaxis()->SetLabelFont(42);
  hmupt->GetXaxis()->SetTitleFont(42);
  hmupt->GetYaxis()->SetLabelFont(42);
  hmupt->GetYaxis()->SetTitleFont(42);
  hmupt->GetYaxis()->SetTitle("#mu #epsilon (Tight/Loose)");
  hmupt->GetXaxis()->SetTitle("#mu P_{T} (GeV)");
  hmupt->GetYaxis()->SetRangeUser(0,1);
  hmupt->GetXaxis()->SetRangeUser(0,100);
  hmupt->SetMarkerColor(1);
  hmupt->SetMarkerStyle(21);
  hmupt->SetLineColor(2);
  hmupt->SetLineWidth(2);
  hmupt->Draw();
  c1->SaveAs("pt_ToverL_pfmuons.png");
  htapt->GetXaxis()->SetLabelFont(42);
  htapt->GetXaxis()->SetTitleFont(42);
  htapt->GetYaxis()->SetLabelFont(42);
  htapt->GetYaxis()->SetTitleFont(42);
  htapt->GetYaxis()->SetTitle("#tau #epsilon (Tight/Loose)");
  htapt->GetXaxis()->SetTitle("#tau P_{T} (GeV)");
  htapt->GetYaxis()->SetRangeUser(0,1.1);
  htapt->GetXaxis()->SetRangeUser(0,100);
  htapt->SetMarkerColor(1);
  htapt->SetMarkerStyle(21);
  htapt->SetLineColor(2);
  htapt->SetLineWidth(2);
  htapt->Draw();
  c1->SaveAs("pt_ToverL_pftaus.png");


  TH1D *heleta = new TH1D("ElectronTLeta","ElectronTLeta",24,-3,3);
  TH1D *hmueta = new TH1D("MuonTLeta","MuonTLeta",24,-3,3);
  TH1D *htaeta = new TH1D("TauTLeta","TauTLeta",24,-3,3);
  
  for(unsigned int j =0;j<24;j++){
    float nume = 0, dene = 0;
    float numm = 0, denm = 0;
    float numt = 0, dent = 0;
    for(unsigned int i=0;i<100;i++){
      dene = dene + w1*h11->GetBinContent(i,j) + w2*h21->GetBinContent(i,j) + w3*h31->GetBinContent(i,j) + w4*h41->GetBinContent(i,j) + w5*h51->GetBinContent(i,j) + w6*h61->GetBinContent(i,j) + w7*h71->GetBinContent(i,j) + w8*h81->GetBinContent(i,j);
      nume = nume + w1*h12->GetBinContent(i,j) + w2*h22->GetBinContent(i,j) + w3*h32->GetBinContent(i,j) + w4*h42->GetBinContent(i,j) + w5*h52->GetBinContent(i,j) + w6*h62->GetBinContent(i,j) + w7*h72->GetBinContent(i,j) + w8*h82->GetBinContent(i,j);
      
      denm = denm + w1*h13->GetBinContent(i,j) + w2*h23->GetBinContent(i,j) + w3*h33->GetBinContent(i,j) + w4*h43->GetBinContent(i,j) + w5*h53->GetBinContent(i,j) + w6*h63->GetBinContent(i,j) + w7*h73->GetBinContent(i,j) + w8*h83->GetBinContent(i,j);
      numm = numm + w1*h14->GetBinContent(i,j) + w2*h24->GetBinContent(i,j) + w3*h34->GetBinContent(i,j) + w4*h44->GetBinContent(i,j) + w5*h54->GetBinContent(i,j) + w6*h64->GetBinContent(i,j) + w7*h74->GetBinContent(i,j) + w8*h84->GetBinContent(i,j);
      
      dent = dent + w1*h15->GetBinContent(i,j) + w2*h25->GetBinContent(i,j) + w3*h35->GetBinContent(i,j) + w4*h45->GetBinContent(i,j) + w5*h55->GetBinContent(i,j) + w6*h65->GetBinContent(i,j) + w7*h75->GetBinContent(i,j) + w8*h85->GetBinContent(i,j);
      numt = numt + w1*h16->GetBinContent(i,j) + w2*h26->GetBinContent(i,j) + w3*h36->GetBinContent(i,j) + w4*h46->GetBinContent(i,j) + w5*h56->GetBinContent(i,j) + w6*h66->GetBinContent(i,j) + w7*h76->GetBinContent(i,j) + w8*h86->GetBinContent(i,j);
    }
    if(dene != 0 ){
      heleta->SetBinContent(j,nume/dene);
      heleta->SetBinError(j,sqrt((nume/dene)*(1-nume/dene)/dene));
    }
    if(denm != 0 ){
      hmueta->SetBinContent(j,numm/denm);
      hmueta->SetBinError(j,sqrt((numm/denm)*(1-numm/denm)/denm));
    }
    if(dent != 0 ){
      htaeta->SetBinContent(j,numt/dent);
      htaeta->SetBinError(j,sqrt((numt/dent)*(1-numt/dent)/dent));
    }
  }
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  heleta->GetXaxis()->SetLabelFont(42);
  heleta->GetXaxis()->SetTitleFont(42);
  heleta->GetYaxis()->SetLabelFont(42);
  heleta->GetYaxis()->SetTitleFont(42);
  heleta->GetYaxis()->SetTitle("e #epsilon (Tight/Loose)");
  heleta->GetXaxis()->SetTitle("e #eta");
  heleta->GetYaxis()->SetRangeUser(0,1);
  heleta->GetXaxis()->SetRangeUser(-2.5,2.5);
  //  gPad->SetLogy(1);
  gPad->SetTicky(1);
  gPad->SetTickx(1);

  heleta->SetMarkerColor(1);
  heleta->SetMarkerStyle(21);
  heleta->SetLineColor(2);
  heleta->SetLineWidth(2);
  heleta->Draw();
  c1->SaveAs("eta_ToverL_pfelectrons.png");
  hmueta->GetXaxis()->SetLabelFont(42);
  hmueta->GetXaxis()->SetTitleFont(42);
  hmueta->GetYaxis()->SetLabelFont(42);
  hmueta->GetYaxis()->SetTitleFont(42);
  hmueta->GetYaxis()->SetTitle("#mu #epsilon (Tight/Loose)");
  hmueta->GetXaxis()->SetTitle("#mu #eta");
  hmueta->GetYaxis()->SetRangeUser(0,1);
  hmueta->GetXaxis()->SetRangeUser(-2.5,2.5);
  hmueta->SetMarkerColor(1);
  hmueta->SetMarkerStyle(21);
  hmueta->SetLineColor(2);
  hmueta->SetLineWidth(2);
  hmueta->Draw();
  c1->SaveAs("eta_ToverL_pfmuons.png");
  htaeta->GetXaxis()->SetLabelFont(42);
  htaeta->GetXaxis()->SetTitleFont(42);
  htaeta->GetYaxis()->SetLabelFont(42);
  htaeta->GetYaxis()->SetTitleFont(42);
  htaeta->GetYaxis()->SetTitle("#tau #epsilon (Tight/Loose)");
  htaeta->GetXaxis()->SetTitle("#tau #eta");
  htaeta->GetYaxis()->SetRangeUser(0,1);
  htaeta->GetXaxis()->SetRangeUser(-2.5,2.5);
  htaeta->SetMarkerColor(1);
  htaeta->SetMarkerStyle(21);
  htaeta->SetLineColor(2);
  htaeta->SetLineWidth(2);
  htaeta->Draw();
  c1->SaveAs("eta_ToverL_pftaus.png");


  f1->Close();
  f2->Close();
  f3->Close();
  f4->Close();
  f5->Close();
  f6->Close();
  f7->Close();
  f8->Close();

  /*

  TFolder *fol2 = gROOT->GetRootFolder()->AddFolder("Output","Output");
  TFile *f1 = TFile::Open(rootfile.c_str());
  TFolder *fol = f1->Get("Electron");
  TFile *f2 = new TFile("nonprompt.root","Recreate");

  TH2D* h1 = fol->FindObject("Loose_Electrons_pt_eta");
  TH2D* h2 = fol->FindObject("Tight_Electrons_pt_eta");

  TH1D* h1x = h1->ProjectionX("Pt",0,-1,"ed"); 
  TH1D* h2x = h2->ProjectionX("Pt2",0,-1,"ed"); 
  TH1D* hdivx = new TH1D("Division","Division",100,0,500);
  TH2D* h3 = new TH2D("BigDiv","BigDiv",6,0,6,5,0,5); 

  TH1D* h1xe = h1->ProjectionY("Eta",0,-1,"ed"); 
  TH1D* h2xe = h2->ProjectionY("Eta2",0,-1,"ed"); 
  TH1D* hdivxe = new TH1D("EtaDivision","EtaDivision",24,-3,3);

  TH2D* h1pf = fol->FindObject("Loose_PFElectrons_pt_eta");
  TH2D* h2pf = fol->FindObject("Tight_PFElectrons_pt_eta");

  TH1D* h1xpf = h1pf->ProjectionX("pfPt",0,-1,"ed"); 
  TH1D* h2xpf = h2pf->ProjectionX("pfPt2",0,-1,"ed"); 
  TH1D* hdivxpf = new TH1D("PFDivision","PFDivision",100,0,500);
  TH2D* h3pf = new TH2D("pfBigDiv","pfBigDiv",6,0,6,5,0,5); 

  TH1D* h1xepf = h1pf->ProjectionY("pfEta",0,-1,"ed"); 
  TH1D* h2xepf = h2pf->ProjectionY("pfEta2",0,-1,"ed"); 
  TH1D* hdivxepf = new TH1D("pfEtaDivision","pfEtaDivision",24,-3,3);

  f2->cd();
  fol2->Add(h1);
  fol2->Add(h2);
  fol2->Add(h1x);
  fol2->Add(h2x);
  fol2->Add(hdivx);
  fol2->Add(h1xe);
  fol2->Add(h2xe);
  fol2->Add(hdivxe);
  fol2->Add(h3);
  fol2->Add(h1pf);
  fol2->Add(h2pf);
  fol2->Add(h1xpf);
  fol2->Add(h2xpf);
  fol2->Add(hdivxpf);
  fol2->Add(h1xepf);
  fol2->Add(h2xepf);
  fol2->Add(hdivxepf);
  fol2->Add(h3pf);

  float pn[6][5];
  float pd[6][5];
  for(int i =0; i < 6; i++){
    for(int l = 0; l < 5; l++){
      pn[i][l] = 0;
      pd[i][l] = 0;
    }
  }
  for(int i =1; i <= 100; i++){
    for(int l = 1; l <=24; l++){
      if(i==1){
	if(l <= 5 ){
	  pd[0][0]+=h1->GetBinContent(i,l);
	  pn[0][0]+=h2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[0][1]+=h1->GetBinContent(i,l);
	  pn[0][1]+=h2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[0][2]+=h1->GetBinContent(i,l);
	  pn[0][2]+=h2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[0][3]+=h1->GetBinContent(i,l);
	  pn[0][3]+=h2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[0][4]+=h1->GetBinContent(i,l);
	  pn[0][4]+=h2->GetBinContent(i,l);
	}
      }
      else if(i==2){
	if(l <= 5 ){
	  pd[1][0]+=h1->GetBinContent(i,l);
	  pn[1][0]+=h2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[1][1]+=h1->GetBinContent(i,l);
	  pn[1][1]+=h2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[1][2]+=h1->GetBinContent(i,l);
	  pn[1][2]+=h2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[1][3]+=h1->GetBinContent(i,l);
	  pn[1][3]+=h2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[1][4]+=h1->GetBinContent(i,l);
	  pn[1][4]+=h2->GetBinContent(i,l);
	}
      }
      else if(i==3 || i == 4){
	if(l <= 5 ){
	  pd[2][0]+=h1->GetBinContent(i,l);
	  pn[2][0]+=h2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[2][1]+=h1->GetBinContent(i,l);
	  pn[2][1]+=h2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[2][2]+=h1->GetBinContent(i,l);
	  pn[2][2]+=h2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[2][3]+=h1->GetBinContent(i,l);
	  pn[2][3]+=h2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[2][4]+=h1->GetBinContent(i,l);
	  pn[2][4]+=h2->GetBinContent(i,l);
	}
      }
      else if(i >= 5 && i <= 10 ){
	if(l <= 5 ){
	  pd[3][0]+=h1->GetBinContent(i,l);
	  pn[3][0]+=h2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[3][1]+=h1->GetBinContent(i,l);
	  pn[3][1]+=h2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[3][2]+=h1->GetBinContent(i,l);
	  pn[3][2]+=h2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[3][3]+=h1->GetBinContent(i,l);
	  pn[3][3]+=h2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[3][4]+=h1->GetBinContent(i,l);
	  pn[3][4]+=h2->GetBinContent(i,l);
	}
      }
      else if(i >= 11 && i <= 20 ){
	if(l <= 5 ){
	  pd[4][0]+=h1->GetBinContent(i,l);
	  pn[4][0]+=h2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[4][1]+=h1->GetBinContent(i,l);
	  pn[4][1]+=h2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[4][2]+=h1->GetBinContent(i,l);
	  pn[4][2]+=h2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[4][3]+=h1->GetBinContent(i,l);
	  pn[4][3]+=h2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[4][4]+=h1->GetBinContent(i,l);
	  pn[4][4]+=h2->GetBinContent(i,l);
	}
      }
      else if(i >= 21 && i <= 100 ){
	if(l <= 5 ){
	  pd[5][0]+=h1->GetBinContent(i,l);
	  pn[5][0]+=h2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[5][1]+=h1->GetBinContent(i,l);
	  pn[5][1]+=h2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[5][2]+=h1->GetBinContent(i,l);
	  pn[5][2]+=h2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[5][3]+=h1->GetBinContent(i,l);
	  pn[5][3]+=h2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[5][4]+=h1->GetBinContent(i,l);
	  pn[5][4]+=h2->GetBinContent(i,l);
	}
      }
    }
  }

  cout << "electron" << endl;
  for(int i=0; i < 6; i++ ){
    for(int l=0; l < 5; l++){
      if(pd[i][l] != 0 ){
	float p = (float)pn[i][l]/pd[i][l];
	float n = pn[i][l]+pd[i][l];
	cout << "bin " << i << ", " << l << ": " << p << " +- " << sqrt(p*(1-p)/n)  << endl;
	h3->SetBinContent(i+1,l+1,p);
	h3->SetBinError(i+1,l+1,sqrt(p*(1-p)/n));
      }
    }
  }

  for(int i =0; i < 6; i++){
    for(int l = 0; l < 5; l++){
      pn[i][l] = 0;
      pd[i][l] = 0;
    }
  }

  for(int i =1; i <= 100; i++){
    for(int l = 1; l <=24; l++){
      if(i==1){
	if(l <= 5 ){
	  pd[0][0]+=h1pf->GetBinContent(i,l);
	  pn[0][0]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[0][1]+=h1pf->GetBinContent(i,l);
	  pn[0][1]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[0][2]+=h1pf->GetBinContent(i,l);
	  pn[0][2]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[0][3]+=h1pf->GetBinContent(i,l);
	  pn[0][3]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[0][4]+=h1pf->GetBinContent(i,l);
	  pn[0][4]+=h2pf->GetBinContent(i,l);
	}
      }
      else if(i==2){
	if(l <= 5 ){
	  pd[1][0]+=h1pf->GetBinContent(i,l);
	  pn[1][0]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[1][1]+=h1pf->GetBinContent(i,l);
	  pn[1][1]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[1][2]+=h1pf->GetBinContent(i,l);
	  pn[1][2]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[1][3]+=h1pf->GetBinContent(i,l);
	  pn[1][3]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[1][4]+=h1pf->GetBinContent(i,l);
	  pn[1][4]+=h2pf->GetBinContent(i,l);
	}
      }
      else if(i==3 || i == 4){
	if(l <= 5 ){
	  pd[2][0]+=h1pf->GetBinContent(i,l);
	  pn[2][0]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[2][1]+=h1pf->GetBinContent(i,l);
	  pn[2][1]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[2][2]+=h1pf->GetBinContent(i,l);
	  pn[2][2]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[2][3]+=h1pf->GetBinContent(i,l);
	  pn[2][3]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[2][4]+=h1pf->GetBinContent(i,l);
	  pn[2][4]+=h2pf->GetBinContent(i,l);
	}
      }
      else if(i >= 5 && i <= 10 ){
	if(l <= 5 ){
	  pd[3][0]+=h1pf->GetBinContent(i,l);
	  pn[3][0]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[3][1]+=h1pf->GetBinContent(i,l);
	  pn[3][1]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[3][2]+=h1pf->GetBinContent(i,l);
	  pn[3][2]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[3][3]+=h1pf->GetBinContent(i,l);
	  pn[3][3]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[3][4]+=h1pf->GetBinContent(i,l);
	  pn[3][4]+=h2pf->GetBinContent(i,l);
	}
      }
      else if(i >= 11 && i <= 20 ){
	if(l <= 5 ){
	  pd[4][0]+=h1pf->GetBinContent(i,l);
	  pn[4][0]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[4][1]+=h1pf->GetBinContent(i,l);
	  pn[4][1]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[4][2]+=h1pf->GetBinContent(i,l);
	  pn[4][2]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[4][3]+=h1pf->GetBinContent(i,l);
	  pn[4][3]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[4][4]+=h1pf->GetBinContent(i,l);
	  pn[4][4]+=h2pf->GetBinContent(i,l);
	}
      }
      else if(i >= 21 && i <= 100 ){
	if(l <= 5 ){
	  pd[5][0]+=h1pf->GetBinContent(i,l);
	  pn[5][0]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[5][1]+=h1pf->GetBinContent(i,l);
	  pn[5][1]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[5][2]+=h1pf->GetBinContent(i,l);
	  pn[5][2]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[5][3]+=h1pf->GetBinContent(i,l);
	  pn[5][3]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[5][4]+=h1pf->GetBinContent(i,l);
	  pn[5][4]+=h2pf->GetBinContent(i,l);
	}
      }
    }
  }

  cout << "pf electron" << endl;
  for(int i=0; i < 6; i++ ){
    for(int l=0; l < 5; l++){
      if(pd[i][l] != 0 ){
	float p = (float)pn[i][l]/pd[i][l];
	float n = pn[i][l]+pd[i][l];
	cout << "bin " << i << ", " << l << ": " << p << " +- " << sqrt(p*(1-p)/n)  << endl;
	h3pf->SetBinContent(i+1,l+1,p);
	h3pf->SetBinError(i+1,l+1,sqrt(p*(1-p)/n));
      }
    }
  }

  hdivx->Divide(h2x,h1x,1,1,"B");
  hdivxpf->Divide(h2xpf,h1xpf,1,1,"B");
  hdivxe->Divide(h2xe,h1xe,1,1,"B");
  hdivxepf->Divide(h2xepf,h1xepf,1,1,"B");

  TCanvas *c1 = new TCanvas();

  hdivx->GetXaxis()->SetRangeUser(2,220);
  hdivx->Draw();
  c1->SaveAs("Ept_ToverL_electrons.jpg");

  hdivxpf->GetXaxis()->SetRangeUser(2,220);
  hdivxpf->Draw();
  c1->SaveAs("Ept_ToverL_pfelectrons.jpg");

  hdivxe->Draw();
  c1->SaveAs("Eeta_ToverL_electrons.jpg");

  hdivxepf->Draw();
  c1->SaveAs("Eeta_ToverL_pfelectrons.jpg");

  /////////////muons

  TFolder *fol1 = f1->Get("Muon");

  TH2D* j1 = fol1->FindObject("Loose_Muons_pt_eta");
  TH2D* j2 = fol1->FindObject("Tight_Muons_pt_eta");

  TH1D* j1x = j1->ProjectionX("mPt",0,-1,"ed"); 
  TH1D* j2x = j2->ProjectionX("mPt2",0,-1,"ed"); 
  TH1D* jdivx = new TH1D("mDivision","mDivision",100,0,500);
  TH2D* j3 = new TH2D("mBigDiv","mBigDiv",6,0,6,5,0,5); 

  TH1D* j1xe = j1->ProjectionY("mEta",0,-1,"ed"); 
  TH1D* j2xe = j2->ProjectionY("mEta2",0,-1,"ed"); 
  TH1D* jdivxe = new TH1D("mEtaDivision","mEtaDivision",24,-3,3);

  TH2D* j1pf = fol1->FindObject("Loose_PFMuons_pt_eta");
  TH2D* j2pf = fol1->FindObject("Tight_PFMuons_pt_eta");

  TH1D* j1xpf = j1pf->ProjectionX("mpfPt",0,-1,"ed"); 
  TH1D* j2xpf = j2pf->ProjectionX("mpfPt2",0,-1,"ed"); 
  TH1D* jdivxpf = new TH1D("mPFDivision","mPFDivision",100,0,500);
  TH2D* j3pf = new TH2D("pfmBigDiv","pfmBigDiv",6,0,6,5,0,5); 

  TH1D* j1xepf = j1pf->ProjectionY("mpfEta",0,-1,"ed"); 
  TH1D* j2xepf = j2pf->ProjectionY("mpfEta2",0,-1,"ed"); 
  TH1D* jdivxepf = new TH1D("mpfEtaDivision","mpfEtaDivision",24,-3,3);

  f2->cd();
  fol2->Add(j1);
  fol2->Add(j2);
  fol2->Add(j1x);
  fol2->Add(j2x);
  fol2->Add(jdivx);
  fol2->Add(j1xe);
  fol2->Add(j2xe);
  fol2->Add(jdivxe);
  fol2->Add(j3);
  fol2->Add(j1pf);
  fol2->Add(j2pf);
  fol2->Add(j1xpf);
  fol2->Add(j2xpf);
  fol2->Add(jdivxpf);
  fol2->Add(j1xepf);
  fol2->Add(j2xepf);
  fol2->Add(jdivxepf);
  fol2->Add(j3pf);


  float pn[6][5];
  float pd[6][5];
  for(int i =0; i < 6; i++){
    for(int l = 0; l < 5; l++){
      pn[i][l] = 0;
      pd[i][l] = 0;
    }
  }
  for(int i =1; i <= 100; i++){
    for(int l = 1; l <=24; l++){
      if(i==1){
	if(l <= 5 ){
	  pd[0][0]+=j1->GetBinContent(i,l);
	  pn[0][0]+=j2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[0][1]+=j1->GetBinContent(i,l);
	  pn[0][1]+=j2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[0][2]+=j1->GetBinContent(i,l);
	  pn[0][2]+=j2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[0][3]+=j1->GetBinContent(i,l);
	  pn[0][3]+=j2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[0][4]+=j1->GetBinContent(i,l);
	  pn[0][4]+=j2->GetBinContent(i,l);
	}
      }
      else if(i==2){
	if(l <= 5 ){
	  pd[1][0]+=j1->GetBinContent(i,l);
	  pn[1][0]+=j2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[1][1]+=j1->GetBinContent(i,l);
	  pn[1][1]+=j2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[1][2]+=j1->GetBinContent(i,l);
	  pn[1][2]+=j2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[1][3]+=j1->GetBinContent(i,l);
	  pn[1][3]+=j2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[1][4]+=j1->GetBinContent(i,l);
	  pn[1][4]+=j2->GetBinContent(i,l);
	}
      }
      else if(i==3 || i == 4){
	if(l <= 5 ){
	  pd[2][0]+=j1->GetBinContent(i,l);
	  pn[2][0]+=j2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[2][1]+=j1->GetBinContent(i,l);
	  pn[2][1]+=j2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[2][2]+=j1->GetBinContent(i,l);
	  pn[2][2]+=j2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[2][3]+=j1->GetBinContent(i,l);
	  pn[2][3]+=j2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[2][4]+=j1->GetBinContent(i,l);
	  pn[2][4]+=j2->GetBinContent(i,l);
	}
      }
      else if(i >= 5 && i <= 10 ){
	if(l <= 5 ){
	  pd[3][0]+=j1->GetBinContent(i,l);
	  pn[3][0]+=j2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[3][1]+=j1->GetBinContent(i,l);
	  pn[3][1]+=j2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[3][2]+=j1->GetBinContent(i,l);
	  pn[3][2]+=j2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[3][3]+=j1->GetBinContent(i,l);
	  pn[3][3]+=j2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[3][4]+=j1->GetBinContent(i,l);
	  pn[3][4]+=j2->GetBinContent(i,l);
	}
      }
      else if(i >= 11 && i <= 20 ){
	if(l <= 5 ){
	  pd[4][0]+=j1->GetBinContent(i,l);
	  pn[4][0]+=j2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[4][1]+=j1->GetBinContent(i,l);
	  pn[4][1]+=j2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[4][2]+=j1->GetBinContent(i,l);
	  pn[4][2]+=j2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[4][3]+=j1->GetBinContent(i,l);
	  pn[4][3]+=j2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[4][4]+=j1->GetBinContent(i,l);
	  pn[4][4]+=j2->GetBinContent(i,l);
	}
      }
      else if(i >= 21 && i <= 100 ){
	if(l <= 5 ){
	  pd[5][0]+=j1->GetBinContent(i,l);
	  pn[5][0]+=j2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[5][1]+=j1->GetBinContent(i,l);
	  pn[5][1]+=j2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[5][2]+=j1->GetBinContent(i,l);
	  pn[5][2]+=j2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[5][3]+=j1->GetBinContent(i,l);
	  pn[5][3]+=j2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[5][4]+=j1->GetBinContent(i,l);
	  pn[5][4]+=j2->GetBinContent(i,l);
	}
      }
    }
  }

  cout << "muon" << endl;
  for(int i=0; i < 6; i++ ){
    for(int l=0; l < 5; l++){
      if(pd[i][l] != 0 ){
	float p = (float)pn[i][l]/pd[i][l];
	float n = pn[i][l]+pd[i][l];
	cout << "bin " << i << ", " << l << ": " << p << " +- " << sqrt(p*(1-p)/n)  << endl;
	j3->SetBinContent(i+1,l+1,p);
	j3->SetBinError(i+1,l+1,sqrt(p*(1-p)/n));
      }
    }
  }

  for(int i =0; i < 6; i++){
    for(int l = 0; l < 5; l++){
      pn[i][l] = 0;
      pd[i][l] = 0;
    }
  }

  for(int i =1; i <= 100; i++){
    for(int l = 1; l <=24; l++){
      if(i==1){
	if(l <= 5 ){
	  pd[0][0]+=j1pf->GetBinContent(i,l);
	  pn[0][0]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[0][1]+=j1pf->GetBinContent(i,l);
	  pn[0][1]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[0][2]+=j1pf->GetBinContent(i,l);
	  pn[0][2]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[0][3]+=j1pf->GetBinContent(i,l);
	  pn[0][3]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[0][4]+=j1pf->GetBinContent(i,l);
	  pn[0][4]+=j2pf->GetBinContent(i,l);
	}
      }
      else if(i==2){
	if(l <= 5 ){
	  pd[1][0]+=j1pf->GetBinContent(i,l);
	  pn[1][0]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[1][1]+=j1pf->GetBinContent(i,l);
	  pn[1][1]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[1][2]+=j1pf->GetBinContent(i,l);
	  pn[1][2]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[1][3]+=j1pf->GetBinContent(i,l);
	  pn[1][3]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[1][4]+=j1pf->GetBinContent(i,l);
	  pn[1][4]+=j2pf->GetBinContent(i,l);
	}
      }
      else if(i==3 || i == 4){
	if(l <= 5 ){
	  pd[2][0]+=j1pf->GetBinContent(i,l);
	  pn[2][0]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[2][1]+=j1pf->GetBinContent(i,l);
	  pn[2][1]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[2][2]+=j1pf->GetBinContent(i,l);
	  pn[2][2]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[2][3]+=j1pf->GetBinContent(i,l);
	  pn[2][3]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[2][4]+=j1pf->GetBinContent(i,l);
	  pn[2][4]+=j2pf->GetBinContent(i,l);
	}
      }
      else if(i >= 5 && i <= 10 ){
	if(l <= 5 ){
	  pd[3][0]+=j1pf->GetBinContent(i,l);
	  pn[3][0]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[3][1]+=j1pf->GetBinContent(i,l);
	  pn[3][1]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[3][2]+=j1pf->GetBinContent(i,l);
	  pn[3][2]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[3][3]+=j1pf->GetBinContent(i,l);
	  pn[3][3]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[3][4]+=j1pf->GetBinContent(i,l);
	  pn[3][4]+=j2pf->GetBinContent(i,l);
	}
      }
      else if(i >= 11 && i <= 20 ){
	if(l <= 5 ){
	  pd[4][0]+=j1pf->GetBinContent(i,l);
	  pn[4][0]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[4][1]+=j1pf->GetBinContent(i,l);
	  pn[4][1]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[4][2]+=j1pf->GetBinContent(i,l);
	  pn[4][2]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[4][3]+=j1pf->GetBinContent(i,l);
	  pn[4][3]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[4][4]+=j1pf->GetBinContent(i,l);
	  pn[4][4]+=j2pf->GetBinContent(i,l);
	}
      }
      else if(i >= 21 && i <= 100 ){
	if(l <= 5 ){
	  pd[5][0]+=j1pf->GetBinContent(i,l);
	  pn[5][0]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[5][1]+=j1pf->GetBinContent(i,l);
	  pn[5][1]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[5][2]+=j1pf->GetBinContent(i,l);
	  pn[5][2]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[5][3]+=j1pf->GetBinContent(i,l);
	  pn[5][3]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[5][4]+=j1pf->GetBinContent(i,l);
	  pn[5][4]+=j2pf->GetBinContent(i,l);
	}
      }
    }
  }

  cout << "pf muon" << endl;
  for(int i=0; i < 6; i++ ){
    for(int l=0; l < 5; l++){
      if(pd[i][l] != 0 ){
	float p = (float)pn[i][l]/pd[i][l];
	float n = pn[i][l]+pd[i][l];
	cout << "bin " << i << ", " << l << ": " << p << " +- " << sqrt(p*(1-p)/n)  << endl;
	j3pf->SetBinContent(i+1,l+1,p);
	j3pf->SetBinError(i+1,l+1,sqrt(p*(1-p)/n));
      }
    }
  }

  jdivx->Divide(j2x,j1x,1,1,"B");
  jdivxpf->Divide(j2xpf,j1xpf,1,1,"B");
  jdivxe->Divide(j2xe,j1xe,1,1,"B");
  jdivxepf->Divide(j2xepf,j1xepf,1,1,"B");

  jdivx->GetXaxis()->SetRangeUser(2,220);
  jdivx->Draw();
  c1->SaveAs("Ept_ToverL_muons.jpg");

  jdivxpf->GetXaxis()->SetRangeUser(2,220);
  jdivxpf->Draw();
  c1->SaveAs("Ept_ToverL_pfmuons.jpg");

  jdivxe->Draw();
  c1->SaveAs("Eeta_ToverL_muons.jpg");

  jdivxepf->Draw();
  c1->SaveAs("Eeta_ToverL_pfmuons.jpg");

  /////////////taus

  TFolder *fol3 = f1->Get("Tau");

  TH2D* k1 = fol3->FindObject("Loose_Tau_pt_eta");
  TH2D* k2 = fol3->FindObject("Tight_Tau_pt_eta");

  TH1D* k1x = k1->ProjectionX("tPt",0,-1,"ed"); 
  TH1D* k2x = k2->ProjectionX("tPt2",0,-1,"ed"); 
  TH1D* kdivx = new TH1D("tDivision","tDivision",100,0,500);
  TH2D* k3 = new TH2D("tBigDiv","tBigDiv",6,0,6,5,0,5); 

  TH1D* k1xe = k1->ProjectionY("tEta",0,-1,"ed"); 
  TH1D* k2xe = k2->ProjectionY("tEta2",0,-1,"ed"); 
  TH1D* kdivxe = new TH1D("tEtaDivision","tEtaDivision",24,-3,3);

  TH2D* k1pf = fol3->FindObject("Loose_PFTau_pt_eta");
  TH2D* k2pf = fol3->FindObject("Tight_PFTau_pt_eta");

  TH1D* k1xpf = k1pf->ProjectionX("tpfPt",0,-1,"ed"); 
  TH1D* k2xpf = k2pf->ProjectionX("tpfPt2",0,-1,"ed"); 
  TH1D* kdivxpf = new TH1D("tPFDivision","tPFDivision",100,0,500);
  TH2D* k3pf = new TH2D("tpfBigDiv","tpfBigDiv",6,0,6,5,0,5); 

  TH1D* k1xepf = k1pf->ProjectionY("tpfEta",0,-1,"ed"); 
  TH1D* k2xepf = k2pf->ProjectionY("tpfEta2",0,-1,"ed"); 
  TH1D* kdivxepf = new TH1D("tpfEtaDivision","tpfEtaDivision",24,-3,3);

  f2->cd();
  fol2->Add(k1);
  fol2->Add(k2);
  fol2->Add(k1x);
  fol2->Add(k2x);
  fol2->Add(kdivx);
  fol2->Add(k1xe);
  fol2->Add(k2xe);
  fol2->Add(kdivxe);
  fol2->Add(k3);
  fol2->Add(k1pf);
  fol2->Add(k2pf);
  fol2->Add(k1xpf);
  fol2->Add(k2xpf);
  fol2->Add(kdivxpf);
  fol2->Add(k1xepf);
  fol2->Add(k2xepf);
  fol2->Add(kdivxepf);
  fol2->Add(k3pf);

  for(int i =0; i < 6; i++){
    for(int l = 0; l < 5; l++){
      pn[i][l] = 0;
      pd[i][l] = 0;
    }
  }

  for(int i =1; i <= 100; i++){
    for(int l = 1; l <=24; l++){
      if(i==1){
	if(l <= 5 ){
	  pd[0][0]+=k1->GetBinContent(i,l);
	  pn[0][0]+=k2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[0][1]+=k1->GetBinContent(i,l);
	  pn[0][1]+=k2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[0][2]+=k1->GetBinContent(i,l);
	  pn[0][2]+=k2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[0][3]+=k1->GetBinContent(i,l);
	  pn[0][3]+=k2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[0][4]+=k1->GetBinContent(i,l);
	  pn[0][4]+=k2->GetBinContent(i,l);
	}
      }
      else if(i==2){
	if(l <= 5 ){
	  pd[1][0]+=k1->GetBinContent(i,l);
	  pn[1][0]+=k2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[1][1]+=k1->GetBinContent(i,l);
	  pn[1][1]+=k2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[1][2]+=k1->GetBinContent(i,l);
	  pn[1][2]+=k2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[1][3]+=k1->GetBinContent(i,l);
	  pn[1][3]+=k2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[1][4]+=k1->GetBinContent(i,l);
	  pn[1][4]+=k2->GetBinContent(i,l);
	}
      }
      else if(i==3 || i == 4){
	if(l <= 5 ){
	  pd[2][0]+=k1->GetBinContent(i,l);
	  pn[2][0]+=k2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[2][1]+=k1->GetBinContent(i,l);
	  pn[2][1]+=k2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[2][2]+=k1->GetBinContent(i,l);
	  pn[2][2]+=k2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[2][3]+=k1->GetBinContent(i,l);
	  pn[2][3]+=k2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[2][4]+=k1->GetBinContent(i,l);
	  pn[2][4]+=k2->GetBinContent(i,l);
	}
      }
      else if(i >= 5 && i <= 10 ){
	if(l <= 5 ){
	  pd[3][0]+=k1->GetBinContent(i,l);
	  pn[3][0]+=k2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[3][1]+=k1->GetBinContent(i,l);
	  pn[3][1]+=k2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[3][2]+=k1->GetBinContent(i,l);
	  pn[3][2]+=k2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[3][3]+=k1->GetBinContent(i,l);
	  pn[3][3]+=k2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[3][4]+=k1->GetBinContent(i,l);
	  pn[3][4]+=k2->GetBinContent(i,l);
	}
      }
      else if(i >= 11 && i <= 20 ){
	if(l <= 5 ){
	  pd[4][0]+=k1->GetBinContent(i,l);
	  pn[4][0]+=k2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[4][1]+=k1->GetBinContent(i,l);
	  pn[4][1]+=k2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[4][2]+=k1->GetBinContent(i,l);
	  pn[4][2]+=k2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[4][3]+=k1->GetBinContent(i,l);
	  pn[4][3]+=k2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[4][4]+=k1->GetBinContent(i,l);
	  pn[4][4]+=k2->GetBinContent(i,l);
	}
      }
      else if(i >= 21 && i <= 100 ){
	if(l <= 5 ){
	  pd[5][0]+=k1->GetBinContent(i,l);
	  pn[5][0]+=k2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[5][1]+=k1->GetBinContent(i,l);
	  pn[5][1]+=k2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[5][2]+=k1->GetBinContent(i,l);
	  pn[5][2]+=k2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[5][3]+=k1->GetBinContent(i,l);
	  pn[5][3]+=k2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[5][4]+=k1->GetBinContent(i,l);
	  pn[5][4]+=k2->GetBinContent(i,l);
	}
      }
    }
  }
  cout << "tau" << endl;
  for(int i=0; i < 6; i++ ){
    for(int l=0; l < 5; l++){
      if(pd[i][l] != 0 ){
	float p = (float)pn[i][l]/pd[i][l];
	float n = pn[i][l]+pd[i][l];
	cout << "bin " << i << ", " << l << ": " << p << " +- " << sqrt(p*(1-p)/n)  << endl;
	k3->SetBinContent(i+1,l+1,p);
	k3->SetBinError(i+1,l+1,sqrt(p*(1-p)/n));
      }
    }
  }

  for(int i =0; i < 6; i++){
    for(int l = 0; l < 5; l++){
      pn[i][l] = 0;
      pd[i][l] = 0;
    }
  }

  for(int i =1; i <= 100; i++){
    for(int l = 1; l <=24; l++){
      if(i==1){
	if(l <= 5 ){
	  pd[0][0]+=k1pf->GetBinContent(i,l);
	  pn[0][0]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[0][1]+=k1pf->GetBinContent(i,l);
	  pn[0][1]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[0][2]+=k1pf->GetBinContent(i,l);
	  pn[0][2]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[0][3]+=k1pf->GetBinContent(i,l);
	  pn[0][3]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[0][4]+=k1pf->GetBinContent(i,l);
	  pn[0][4]+=k2pf->GetBinContent(i,l);
	}
      }
      else if(i==2){
	if(l <= 5 ){
	  pd[1][0]+=k1pf->GetBinContent(i,l);
	  pn[1][0]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[1][1]+=k1pf->GetBinContent(i,l);
	  pn[1][1]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[1][2]+=k1pf->GetBinContent(i,l);
	  pn[1][2]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[1][3]+=k1pf->GetBinContent(i,l);
	  pn[1][3]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[1][4]+=k1pf->GetBinContent(i,l);
	  pn[1][4]+=k2pf->GetBinContent(i,l);
	}
      }
      else if(i==3 || i == 4){
	if(l <= 5 ){
	  pd[2][0]+=k1pf->GetBinContent(i,l);
	  pn[2][0]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[2][1]+=k1pf->GetBinContent(i,l);
	  pn[2][1]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[2][2]+=k1pf->GetBinContent(i,l);
	  pn[2][2]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[2][3]+=k1pf->GetBinContent(i,l);
	  pn[2][3]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[2][4]+=k1pf->GetBinContent(i,l);
	  pn[2][4]+=k2pf->GetBinContent(i,l);
	}
      }
      else if(i >= 5 && i <= 10 ){
	if(l <= 5 ){
	  pd[3][0]+=k1pf->GetBinContent(i,l);
	  pn[3][0]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[3][1]+=k1pf->GetBinContent(i,l);
	  pn[3][1]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[3][2]+=k1pf->GetBinContent(i,l);
	  pn[3][2]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[3][3]+=k1pf->GetBinContent(i,l);
	  pn[3][3]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[3][4]+=k1pf->GetBinContent(i,l);
	  pn[3][4]+=k2pf->GetBinContent(i,l);
	}
      }
      else if(i >= 11 && i <= 20 ){
	if(l <= 5 ){
	  pd[4][0]+=k1pf->GetBinContent(i,l);
	  pn[4][0]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[4][1]+=k1pf->GetBinContent(i,l);
	  pn[4][1]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[4][2]+=k1pf->GetBinContent(i,l);
	  pn[4][2]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[4][3]+=k1pf->GetBinContent(i,l);
	  pn[4][3]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[4][4]+=k1pf->GetBinContent(i,l);
	  pn[4][4]+=k2pf->GetBinContent(i,l);
	}
      }
      else if(i >= 21 && i <= 100 ){
	if(l <= 5 ){
	  pd[5][0]+=k1pf->GetBinContent(i,l);
	  pn[5][0]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[5][1]+=k1pf->GetBinContent(i,l);
	  pn[5][1]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[5][2]+=k1pf->GetBinContent(i,l);
	  pn[5][2]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[5][3]+=k1pf->GetBinContent(i,l);
	  pn[5][3]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[5][4]+=k1pf->GetBinContent(i,l);
	  pn[5][4]+=k2pf->GetBinContent(i,l);
	}
      }
    }
  }

  cout << "pf tau" << endl;
  for(int i=0; i < 6; i++ ){
    for(int l=0; l < 5; l++){
      if(pd[i][l] != 0 ){
	float p = (float)pn[i][l]/pd[i][l];
	float n = pn[i][l]+pd[i][l];
	cout << "bin " << i << ", " << l << ": " << p << " +- " << sqrt(p*(1-p)/n)  << endl;
	k3pf->SetBinContent(i+1,l+1,p);
	k3pf->SetBinError(i+1,l+1,sqrt(p*(1-p)/n));
      }
    }
  }

  kdivx->Divide(k2x,k1x,1,1,"B");
  kdivxpf->Divide(k2xpf,k1xpf,1,1,"B");
  kdivxe->Divide(k2xe,k1xe,1,1,"B");
  kdivxepf->Divide(k2xepf,k1xepf,1,1,"B");

  kdivx->GetXaxis()->SetRangeUser(2,220);
  kdivx->Draw();
  c1->SaveAs("Ept_ToverL_tau.jpg");

  kdivxpf->GetXaxis()->SetRangeUser(2,220);
  kdivxpf->Draw();
  c1->SaveAs("Ept_ToverL_pftau.jpg");

  kdivxe->Draw();
  c1->SaveAs("Eeta_ToverL_tau.jpg");

  kdivxepf->Draw();
  c1->SaveAs("Eeta_ToverL_pftau.jpg");

  h3->Draw("COLZ");
  f1->Close();

  f2->cd();
  fol2->Write();
  f2->Close();
  */
}
