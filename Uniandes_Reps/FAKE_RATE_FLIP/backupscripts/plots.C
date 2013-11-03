{
#include <stdlib>
#include <TString.h>
  TFile *f1 = TFile::Open("../root_files/MC_PG_v2.root");
  TFile *f2 = TFile::Open("../root_files/iso.root"); 
  TFile *f3 = TFile::Open("../root_files/iso_data.root");
  TFile *f4 = TFile::Open("../root_files/MC_truth_zjets.root");
  /////////histograms in first file particle gun
  TH1F* ptgood = (TH1F*)f1->FindObjectAny("Pt_correct_charge");
  TH1F* ptwrong = (TH1F*)f1->FindObjectAny("Pt_wrong_charge");
  TH1F* etagood = (TH1F*)f1->FindObjectAny("Eta_correct_charge");
  TH1F* etawrong = (TH1F*)f1->FindObjectAny("Eta_wrong_charge");
  TH1F* ptgood_b[3];
  TH1F* ptwrong_b[3];
  TH1F* divpt_b[3];
  TH1F* etagood_b[5];
  TH1F* etawrong_b[5];
  TH1F* diveta_b[5];

  TString stuf[5] = {"1","2","3","4","5"};
  TString tit ="";

  TCanvas *c1 = new TCanvas();
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  c1->SetFillColor(0);
  c1->Range(-0.125,-0.125,1.125,1.125);
  c1->SetBorderSize(0);
  c1->SetTickx(1);
  c1->SetTicky(1);
  c1->SetFrameFillColor(0);
  c1->SetFrameBorderMode(0);
  c1->SetLeftMargin(0.2);  

  for(int i=0;i < 3;i++){
    tit = "Good_Pt_Bins_in_eta_bin_"+stuf[i];
    ptgood_b[i] = (TH1F*)f1->FindObjectAny(tit);
    tit = "Wrong_Pt_Bins_in_eta_bin_"+stuf[i];
    ptwrong_b[i] = (TH1F*)f1->FindObjectAny(tit);
    tit = "Fake_Q_PG_Rate_in_pt_for_eta_bin_"+stuf[i];
    divpt_b[i] = new TH1F(tit,tit,5,0,5);
  }
  for(int i=0;i < 5;i++){
    tit = "Good_Eta_Bins_in_pt_bin_"+stuf[i];
    etagood_b[i] = (TH1F*)f1->FindObjectAny(tit);
    tit = "Wrong_Eta_Bins_in_pt_bin_"+stuf[i];
    etawrong_b[i] = (TH1F*)f1->FindObjectAny(tit);
    tit = "Fake_Q_PG_Rate_in_eta_for_pt_bin_"+stuf[i];
    diveta_b[i] = new TH1F(tit,tit,3,0,3);
  }
  TH2F* etaptgood = (TH2F*)f1->FindObjectAny("PTEta_correct_charge");
  TH2F* etaptwrong = (TH2F*)f1->FindObjectAny("PTEta_wrong_charge");
  TH2F* etaptrate = new TH2F("EtaPtRate","Fake rate in pt and Eta",5,0,5,3,0,3);
  TH1F* divpt = new TH1F("divpt","Fake percentage pt",5,0,5); 
  TH1F* diveta = new TH1F("diveta","Fake percentage eta",3,0,3); 
  divpt->GetXaxis()->SetBinLabel(1,"5-10 GeV");
  divpt->GetXaxis()->SetBinLabel(2,"10-20 GeV");
  divpt->GetXaxis()->SetBinLabel(3,"20-40 GeV");
  divpt->GetXaxis()->SetBinLabel(4,"40-70 GeV");
  divpt->GetXaxis()->SetBinLabel(5," > 70 GeV");
  divpt->GetXaxis()->SetTitle("PF El Pt (GeV)");
  divpt->GetYaxis()->SetTitle("Charge miss-identification rate");
  divpt->GetXaxis()->SetTitleOffset(1);
  divpt->GetYaxis()->SetTitleOffset(2);
  divpt->GetXaxis()->SetLabelFont(42);
  divpt->GetXaxis()->SetTitleFont(42);
  divpt->GetYaxis()->SetLabelFont(42);
  divpt->GetYaxis()->SetTitleFont(42);
  divpt->SetMarkerStyle(12);
  divpt->SetMarkerSize(0.8);
  divpt->SetMarkerColor(1);
  for(int i=0; i<3; i++){
    divpt_b[i]->GetXaxis()->SetBinLabel(1,"5-10 GeV");
    divpt_b[i]->GetXaxis()->SetBinLabel(2,"10-20 GeV");
    divpt_b[i]->GetXaxis()->SetBinLabel(3,"20-40 GeV");
    divpt_b[i]->GetXaxis()->SetBinLabel(4,"40-70 GeV");
    divpt_b[i]->GetXaxis()->SetBinLabel(5," > 70 GeV");
    divpt_b[i]->GetXaxis()->SetTitle("PF El Pt (GeV)");
    divpt_b[i]->GetYaxis()->SetTitle("Charge miss-identification rate in eta bin "+stuf[i]);
    divpt_b[i]->GetXaxis()->SetTitleOffset(1);
    divpt_b[i]->GetYaxis()->SetTitleOffset(2);
    divpt_b[i]->GetXaxis()->SetLabelFont(42);
    divpt_b[i]->GetXaxis()->SetTitleFont(42);
    divpt_b[i]->GetYaxis()->SetLabelFont(42);
    divpt_b[i]->GetYaxis()->SetTitleFont(42);
    divpt_b[i]->SetMarkerStyle(12);
    divpt_b[i]->SetMarkerSize(0.8);
    divpt_b[i]->SetMarkerColor(1);
  }
  for(int i =1;i<=5; i++){
    int goodpt = ptgood->GetBinContent(i);
    int wrongpt = ptwrong->GetBinContent(i);
    int entries = goodpt + wrongpt;//ptgood->GetEntries();
    divpt->SetBinContent(i,(float)wrongpt/(float)goodpt);
    divpt->SetBinError(i,(float)wrongpt/(float)(goodpt*sqrt(entries))); 
  }
  for(int j=0; j<3;j++){
    for(int i =1;i<=5; i++){
      int goodpt = ptgood_b[j]->GetBinContent(i);
      int wrongpt = ptwrong_b[j]->GetBinContent(i);
      int entries = goodpt + wrongpt;//ptgood->GetEntries();
      divpt_b[j]->SetBinContent(i,(float)wrongpt/(float)goodpt);
      divpt_b[j]->SetBinError(i,(float)wrongpt/(float)(goodpt*sqrt(entries))); 
    }
  }
  c1->cd();
  divpt->GetYaxis()->SetRangeUser(0,0.009);
  divpt->Draw();
  c1->SaveAs("../plots/Pt_PG_bins.gif");
  for(int i=0;i < 3; i++){
    tit = "../plots/Pt_PG_bins_in_eta_bin_"+stuf[i]+".gif";
    c1->cd();
    divpt_b[i]->GetYaxis()->SetRangeUser(0,0.009);
    divpt_b[i]->Draw();
    c1->SaveAs(tit);
  }

  diveta->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
  diveta->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
  diveta->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
  for(int i=0; i<5;i++){
    diveta_b[i]->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
    diveta_b[i]->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
    diveta_b[i]->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
  }
  for(int i =1;i<=3; i++){
    int goodpt = etagood->GetBinContent(i);
    int wrongpt = etawrong->GetBinContent(i);
    int entries = goodpt+wrongpt;//etagood->GetEntries();
    diveta->SetBinContent(i,(float)wrongpt/(float)goodpt); 
    diveta->SetBinError(i,(float)wrongpt/(float)(goodpt*sqrt(entries))); 
  }
  for(int j=0;j<5;j++){
    for(int i =1;i<=3; i++){
      int goodpt = etagood_b[j]->GetBinContent(i);
      int wrongpt = etawrong_b[j]->GetBinContent(i);
      int entries = goodpt+wrongpt;//etagood->GetEntries();
      diveta_b[j]->SetBinContent(i,(float)wrongpt/(float)goodpt); 
      diveta_b[j]->SetBinError(i,(float)wrongpt/(float)(goodpt*sqrt(entries))); 
    }
  }
  diveta->GetXaxis()->SetTitle("PF El #eta");
  diveta->GetYaxis()->SetTitle("Charge miss-identification rate");
  diveta->GetXaxis()->SetTitleOffset(1);
  diveta->GetYaxis()->SetTitleOffset(2);
  diveta->GetXaxis()->SetLabelFont(42);
  diveta->GetXaxis()->SetTitleFont(42);
  diveta->GetYaxis()->SetLabelFont(42);
  diveta->GetYaxis()->SetTitleFont(42);
  diveta->SetMarkerStyle(12);
  diveta->SetMarkerSize(0.8);
  diveta->SetMarkerColor(1);
  diveta->GetYaxis()->SetRangeUser(0,0.009);
  diveta->Draw();
  c1->SaveAs("../plots/Eta_PG_bins.gif");
  for(int j=0;j<5;j++){
    diveta_b[j]->GetXaxis()->SetTitle("PF El #eta");
    diveta_b[j]->GetYaxis()->SetTitle("Charge miss-identification rate");
    diveta_b[j]->GetXaxis()->SetTitleOffset(1);
    diveta_b[j]->GetYaxis()->SetTitleOffset(2);
    diveta_b[j]->GetXaxis()->SetLabelFont(42);
    diveta_b[j]->GetXaxis()->SetTitleFont(42);
    diveta_b[j]->GetYaxis()->SetLabelFont(42);
    diveta_b[j]->GetYaxis()->SetTitleFont(42);
    diveta_b[j]->SetMarkerStyle(12);
    diveta_b[j]->SetMarkerSize(0.8);
    diveta_b[j]->SetMarkerColor(1);
    tit = "../plots/Eta_PG_bins_in_pt_bin_"+stuf[j]+".gif";
    diveta_b[j]->GetYaxis()->SetRangeUser(0,0.009);
    diveta_b[j]->Draw();
    c1->SaveAs(tit);
  }

  for(int i =1;i<=5; i++){
    for(int j =1;j<=3; j++){
      int goodpt = etaptgood->GetBinContent(i,j);
      int wrongpt = etaptwrong->GetBinContent(i,j);
      int entries = goodpt+wrongpt;//etaptgood->GetEntries();
      etaptrate->SetBinContent(i,j,(float)wrongpt/(float)goodpt);
      etaptrate->SetBinError(i,j,(float)wrongpt/(float)(goodpt*sqrt(entries)));
    }
  }

  /////////histograms in first file particle gun
  TH1F* ptgood_mctz = (TH1F*)f4->FindObjectAny("Pt_correct_charge");
  TH1F* ptwrong_mctz = (TH1F*)f4->FindObjectAny("Pt_wrong_charge");
  TH1F* etagood_mctz = (TH1F*)f4->FindObjectAny("Eta_correct_charge");
  TH1F* etawrong_mctz = (TH1F*)f4->FindObjectAny("Eta_wrong_charge");
  TH1F* ptgood_mctz_b[3];
  TH1F* ptwrong_mctz_b[3];
  TH1F* divpt_mctz_b[3];
  TH1F* etagood_mctz_b[5];
  TH1F* etawrong_mctz_b[5];
  TH1F* diveta_mctz_b[5];

  for(int i=0;i < 3;i++){
    tit = "Good_Pt_Bins_in_eta_bin_"+stuf[i];
    ptgood_mctz_b[i] = (TH1F*)f4->FindObjectAny(tit);
    tit = "Wrong_Pt_Bins_in_eta_bin_"+stuf[i];
    ptwrong_mctz_b[i] = (TH1F*)f4->FindObjectAny(tit);
    tit = "Fake_Q_Rate_MCTZ_in_pt_for_eta_bin_"+stuf[i];
    divpt_mctz_b[i] = new TH1F(tit,tit,5,0,5);
  }
  for(int i=0;i < 5;i++){
    tit = "Good_Eta_Bins_in_pt_bin_"+stuf[i];
    etagood_mctz_b[i] = (TH1F*)f4->FindObjectAny(tit);
    tit = "Wrong_Eta_Bins_in_pt_bin_"+stuf[i];
    etawrong_mctz_b[i] = (TH1F*)f4->FindObjectAny(tit);
    tit = "Fake_Q_Rate_MCTZ_in_eta_for_pt_bin_"+stuf[i];
    diveta_mctz_b[i] = new TH1F(tit,tit,3,0,3);
  }
  TH2F* etaptgood_mctz = (TH2F*)f4->FindObjectAny("PTEta_correct_charge");
  TH2F* etaptwrong_mctz = (TH2F*)f4->FindObjectAny("PTEta_wrong_charge");
  TH2F* etaptrate_mctz = new TH2F("EtaPtRateMCTZ","Fake rate in pt and Eta",5,0,5,3,0,3);
  TH1F* divpt_mctz = new TH1F("divptMCTZ","Fake percentage pt",5,0,5); 
  TH1F* diveta_mctz = new TH1F("divetaMCTZ","Fake percentage eta",3,0,3); 
  divpt_mctz->GetXaxis()->SetBinLabel(1,"5-10 GeV");
  divpt_mctz->GetXaxis()->SetBinLabel(2,"10-20 GeV");
  divpt_mctz->GetXaxis()->SetBinLabel(3,"20-40 GeV");
  divpt_mctz->GetXaxis()->SetBinLabel(4,"40-70 GeV");
  divpt_mctz->GetXaxis()->SetBinLabel(5," > 70 GeV");
  divpt_mctz->GetXaxis()->SetTitle("PF El Pt (GeV)");
  divpt_mctz->GetYaxis()->SetTitle("Charge miss-identification rate");
  divpt_mctz->GetXaxis()->SetTitleOffset(1);
  divpt_mctz->GetYaxis()->SetTitleOffset(2);
  divpt_mctz->GetXaxis()->SetLabelFont(42);
  divpt_mctz->GetXaxis()->SetTitleFont(42);
  divpt_mctz->GetYaxis()->SetLabelFont(42);
  divpt_mctz->GetYaxis()->SetTitleFont(42);
  divpt_mctz->SetMarkerStyle(13);
  divpt_mctz->SetMarkerSize(0.8);
  divpt_mctz->SetMarkerColor(3);
  for(int i=0; i<3; i++){
    divpt_mctz_b[i]->GetXaxis()->SetBinLabel(1,"5-10 GeV");
    divpt_mctz_b[i]->GetXaxis()->SetBinLabel(2,"10-20 GeV");
    divpt_mctz_b[i]->GetXaxis()->SetBinLabel(3,"20-40 GeV");
    divpt_mctz_b[i]->GetXaxis()->SetBinLabel(4,"40-70 GeV");
    divpt_mctz_b[i]->GetXaxis()->SetBinLabel(5," > 70 GeV");
    divpt_mctz_b[i]->GetXaxis()->SetTitle("PF El Pt (GeV)");
    divpt_mctz_b[i]->GetYaxis()->SetTitle("Charge miss-identification rate in eta bin "+stuf[i]);
    divpt_mctz_b[i]->GetXaxis()->SetTitleOffset(1);
    divpt_mctz_b[i]->GetYaxis()->SetTitleOffset(2);
    divpt_mctz_b[i]->GetXaxis()->SetLabelFont(42);
    divpt_mctz_b[i]->GetXaxis()->SetTitleFont(42);
    divpt_mctz_b[i]->GetYaxis()->SetLabelFont(42);
    divpt_mctz_b[i]->GetYaxis()->SetTitleFont(42);
    divpt_mctz_b[i]->SetMarkerStyle(13);
    divpt_mctz_b[i]->SetMarkerSize(0.8);
    divpt_mctz_b[i]->SetMarkerColor(3);
  }
  for(int i =1;i<=5; i++){
    int goodpt = ptgood_mctz->GetBinContent(i);
    int wrongpt = ptwrong_mctz->GetBinContent(i);
    int entries = goodpt + wrongpt;//ptgood->GetEntries();
    divpt_mctz->SetBinContent(i,(float)wrongpt/(float)goodpt);
    divpt_mctz->SetBinError(i,(float)wrongpt/(float)(goodpt*sqrt(entries))); 
  }
  for(int j=0; j<3;j++){
    for(int i =1;i<=5; i++){
      int goodpt = ptgood_b[j]->GetBinContent(i);
      int wrongpt = ptwrong_b[j]->GetBinContent(i);
      int entries = goodpt + wrongpt;//ptgood->GetEntries();
      divpt_mctz_b[j]->SetBinContent(i,(float)wrongpt/(float)goodpt);
      divpt_mctz_b[j]->SetBinError(i,(float)wrongpt/(float)(goodpt*sqrt(entries))); 
    }
  }
  c1->cd();
  divpt_mctz->GetYaxis()->SetRangeUser(0,0.009);
  divpt_mctz->Draw();
  c1->SaveAs("../plots/Pt_MCTZ_bins.gif");
  for(int i=0;i < 3; i++){
    tit = "../plots/Pt_MCTZ_bins_in_eta_bin_"+stuf[i]+".gif";
    c1->cd();
    divpt_mctz_b[i]->GetYaxis()->SetRangeUser(0,0.009);
    divpt_mctz_b[i]->Draw();
    c1->SaveAs(tit);
  }

  diveta_mctz->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
  diveta_mctz->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
  diveta_mctz->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
  for(int i=0; i<5;i++){
    diveta_mctz_b[i]->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
    diveta_mctz_b[i]->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
    diveta_mctz_b[i]->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
  }
  for(int i =1;i<=3; i++){
    int goodpt = etagood_mctz->GetBinContent(i);
    int wrongpt = etawrong_mctz->GetBinContent(i);
    int entries = goodpt+wrongpt;//etagood->GetEntries();
    diveta_mctz->SetBinContent(i,(float)wrongpt/(float)goodpt); 
    diveta_mctz->SetBinError(i,(float)wrongpt/(float)(goodpt*sqrt(entries))); 
  }
  for(int j=0;j<5;j++){
    for(int i =1;i<=3; i++){
      int goodpt = etagood_mctz_b[j]->GetBinContent(i);
      int wrongpt = etawrong_mctz_b[j]->GetBinContent(i);
      int entries = goodpt+wrongpt;//etagood->GetEntries();
      diveta_mctz_b[j]->SetBinContent(i,(float)wrongpt/(float)goodpt); 
      diveta_mctz_b[j]->SetBinError(i,(float)wrongpt/(float)(goodpt*sqrt(entries))); 
    }
  }
  diveta_mctz->GetXaxis()->SetTitle("PF El #eta");
  diveta_mctz->GetYaxis()->SetTitle("Charge miss-identification rate");
  diveta_mctz->GetXaxis()->SetTitleOffset(1);
  diveta_mctz->GetYaxis()->SetTitleOffset(2);
  diveta_mctz->GetXaxis()->SetLabelFont(42);
  diveta_mctz->GetXaxis()->SetTitleFont(42);
  diveta_mctz->GetYaxis()->SetLabelFont(42);
  diveta_mctz->GetYaxis()->SetTitleFont(42);
  diveta_mctz->SetMarkerStyle(13);
  diveta_mctz->SetMarkerSize(0.8);
  diveta_mctz->SetMarkerColor(3);
  diveta_mctz->GetYaxis()->SetRangeUser(0,0.009);
  diveta_mctz->Draw();
  c1->SaveAs("../plots/Eta_MCTZ_bins.gif");
  for(int j=0;j<5;j++){
    diveta_mctz_b[j]->GetXaxis()->SetTitle("PF El #eta");
    diveta_mctz_b[j]->GetYaxis()->SetTitle("Charge miss-identification rate");
    diveta_mctz_b[j]->GetXaxis()->SetTitleOffset(1);
    diveta_mctz_b[j]->GetYaxis()->SetTitleOffset(2);
    diveta_mctz_b[j]->GetXaxis()->SetLabelFont(42);
    diveta_mctz_b[j]->GetXaxis()->SetTitleFont(42);
    diveta_mctz_b[j]->GetYaxis()->SetLabelFont(42);
    diveta_mctz_b[j]->GetYaxis()->SetTitleFont(42);
    diveta_mctz_b[j]->SetMarkerStyle(13);
    diveta_mctz_b[j]->SetMarkerSize(0.8);
    diveta_mctz_b[j]->SetMarkerColor(3);
    tit = "../plots/Eta_MCTZ_bins_in_pt_bin_"+stuf[j]+".gif";
    diveta_mctz_b[j]->GetYaxis()->SetRangeUser(0,0.009);
    diveta_mctz_b[j]->Draw();
    c1->SaveAs(tit);
  }

  for(int i =1;i<=5; i++){
    for(int j =1;j<=3; j++){
      int goodpt = etaptgood_mctz->GetBinContent(i,j);
      int wrongpt = etaptwrong_mctz->GetBinContent(i,j);
      int entries = goodpt+wrongpt;//etaptgood_mctz->GetEntries();
      etaptrate_mctz->SetBinContent(i,j,(float)wrongpt/(float)goodpt);
      etaptrate_mctz->SetBinError(i,j,(float)wrongpt/(float)(goodpt*sqrt(entries)));
    }
  }

  /////////////////histograms in MC ZJets Madgrph
  TH1F* ptgood_mc = (TH1F*)f2->FindObjectAny("GoodElPt");
  TH1F* ptwrong_mc = (TH1F*)f2->FindObjectAny("WrongElPt");
  TH1F* etagood_mc = (TH1F*)f2->FindObjectAny("GoodElEta");
  TH1F* etawrong_mc = (TH1F*)f2->FindObjectAny("WrongElEta");
  TH2F* etaptgood_mc = (TH2F*)f2->FindObjectAny("GoodEl2D");
  TH2F* etaptwrong_mc = (TH2F*)f2->FindObjectAny("WrongEl2D");
  TH2F* etaptrate_mc = new TH2F("EtaPtRate_TPMCZ","Fake rate in pt and Eta MC Z",5,0,5,3,0,3);
  TH1F* divpt_mc = new TH1F("divpt_mc","Fake percentage MC pt",5,0,5); 
  TH1F* diveta_mc = new TH1F("diveta_mc","Fake percentage MC eta",3,0,3); 
  TH1F* ptgood_mc_b[3];
  TH1F* ptwrong_mc_b[3];
  TH1F* etagood_mc_b[5];
  TH1F* etawrong_mc_b[5];
  TH1F* divpt_mc_b[3];
  TH1F* diveta_mc_b[5];
 
  for(int i=0;i<3;i++){
    tit = "Good_El_Pt_in_eta_bin_"+stuf[i];
    ptgood_mc_b[i] = (TH1F*)f2->FindObjectAny(tit);
    tit = "Wrong_El_Pt_in_eta_bin_"+stuf[i];
    ptwrong_mc_b[i] = (TH1F*)f2->FindObjectAny(tit);
    tit = "Fake_Q_Rate_TPMCZ_in_pt_for_eta_bin_"+stuf[i];
    divpt_mc_b[i]  = new TH1F(tit,tit,5,0,5);
  }
  for(int i=0;i<5;i++){
    tit = "Good_El_Eta_in_pt_bin_"+stuf[i];
    etagood_mc_b[i] = (TH1F*)f2->FindObjectAny(tit);
    tit = "Wrong_El_Eta_in_pt_bin_"+stuf[i];
    etawrong_mc_b[i] = (TH1F*)f2->FindObjectAny(tit);
    tit = "Fake_Q_Rate_TPMCZ_in_eta_for_pt_bin_"+stuf[i];
    diveta_mc_b[i]  = new TH1F(tit,tit,3,0,3);
  }

  divpt_mc->GetXaxis()->SetBinLabel(1,"5-10 GeV");
  divpt_mc->GetXaxis()->SetBinLabel(2,"10-20 GeV");
  divpt_mc->GetXaxis()->SetBinLabel(3,"20-40 GeV");
  divpt_mc->GetXaxis()->SetBinLabel(4,"40-70 GeV");
  divpt_mc->GetXaxis()->SetBinLabel(5," > 70 GeV");
  divpt_mc->GetXaxis()->SetTitle("PF El Pt (GeV)");
  divpt_mc->GetYaxis()->SetTitle("Charge miss-identification rate");
  divpt_mc->GetXaxis()->SetTitleOffset(1);
  divpt_mc->GetYaxis()->SetTitleOffset(2);
  divpt_mc->GetXaxis()->SetLabelFont(42);
  divpt_mc->GetXaxis()->SetTitleFont(42);
  divpt_mc->GetYaxis()->SetLabelFont(42);
  divpt_mc->GetYaxis()->SetTitleFont(42);
  divpt_mc->SetMarkerStyle(23);
  divpt_mc->SetMarkerSize(0.9);
  divpt_mc->SetMarkerColor(2);
  for(int i=0;i<3;i++){
    divpt_mc_b[i]->GetXaxis()->SetBinLabel(1,"5-10 GeV");
    divpt_mc_b[i]->GetXaxis()->SetBinLabel(2,"10-20 GeV");
    divpt_mc_b[i]->GetXaxis()->SetBinLabel(3,"20-40 GeV");
    divpt_mc_b[i]->GetXaxis()->SetBinLabel(4,"40-70 GeV");
    divpt_mc_b[i]->GetXaxis()->SetBinLabel(5," > 70 GeV");
    divpt_mc_b[i]->GetXaxis()->SetTitle("PF El Pt (GeV)");
    divpt_mc_b[i]->GetYaxis()->SetTitle("Charge miss-identification rate");
    divpt_mc_b[i]->GetXaxis()->SetTitleOffset(1);
    divpt_mc_b[i]->GetYaxis()->SetTitleOffset(2);
    divpt_mc_b[i]->GetXaxis()->SetLabelFont(42);
    divpt_mc_b[i]->GetXaxis()->SetTitleFont(42);
    divpt_mc_b[i]->GetYaxis()->SetLabelFont(42);
    divpt_mc_b[i]->GetYaxis()->SetTitleFont(42);
    divpt_mc_b[i]->SetMarkerStyle(23);
    divpt_mc_b[i]->SetMarkerSize(0.9);
    divpt_mc_b[i]->SetMarkerColor(2);
  }

  for(int i =1;i<=5; i++){
    int goodpt = ptgood_mc->GetBinContent(i);
    int wrongpt = ptwrong_mc->GetBinContent(i);
    int entries = goodpt + wrongpt; 
    if(goodpt != 0){
      divpt_mc->SetBinContent(i,(float)wrongpt/(float)goodpt);
      divpt_mc->SetBinError(i,(float)wrongpt/(float)(goodpt*sqrt(entries))); 
    }
  }

  for(int j=0; j<3;j++){
    for(int i =1;i<=5; i++){
      int goodpt = ptgood_mc_b[j]->GetBinContent(i);
      int wrongpt = ptwrong_mc_b[j]->GetBinContent(i);
      int entries = goodpt + wrongpt;
      if(goodpt != 0){
	divpt_mc_b[j]->SetBinContent(i,(float)wrongpt/(float)goodpt);
	divpt_mc_b[j]->SetBinError(i,(float)wrongpt/(float)(goodpt*sqrt(entries))); 
      }
    }
  }
  divpt_mc->GetYaxis()->SetRangeUser(0,0.009);
  divpt_mc->Draw();
  c1->SaveAs("../plots/Pt_TPMCZ_bins.gif");
  for(int i=0;i<3;i++){
    tit = "../plots/Pt_TPMCZ_bins_in_eta_bin_"+stuf[i]+".gif";
    divpt_mc_b[i]->GetYaxis()->SetRangeUser(0,0.009);
    divpt_mc_b[i]->Draw();
    c1->SaveAs(tit);
  }

  diveta_mc->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
  diveta_mc->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
  diveta_mc->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
  diveta_mc->GetXaxis()->SetTitle("PF El #eta");
  diveta_mc->GetYaxis()->SetTitle("Charge miss-identification rate");
  diveta_mc->GetXaxis()->SetTitleOffset(1);
  diveta_mc->GetYaxis()->SetTitleOffset(2);
  diveta_mc->GetXaxis()->SetLabelFont(42);
  diveta_mc->GetXaxis()->SetTitleFont(42);
  diveta_mc->GetYaxis()->SetLabelFont(42);
  diveta_mc->GetYaxis()->SetTitleFont(42);
  diveta_mc->SetMarkerStyle(23);
  diveta_mc->SetMarkerSize(0.9);
  diveta_mc->SetMarkerColor(2);

  for(int i=0;i<5;i++){
    diveta_mc_b[i]->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
    diveta_mc_b[i]->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
    diveta_mc_b[i]->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
    diveta_mc_b[i]->GetXaxis()->SetTitle("PF El #eta");
    diveta_mc_b[i]->GetYaxis()->SetTitle("Charge miss-identification rate");
    diveta_mc_b[i]->GetXaxis()->SetTitleOffset(1);
    diveta_mc_b[i]->GetYaxis()->SetTitleOffset(2);
    diveta_mc_b[i]->GetXaxis()->SetLabelFont(42);
    diveta_mc_b[i]->GetXaxis()->SetTitleFont(42);
    diveta_mc_b[i]->GetYaxis()->SetLabelFont(42);
    diveta_mc_b[i]->GetYaxis()->SetTitleFont(42);
    diveta_mc_b[i]->SetMarkerStyle(23);
    diveta_mc_b[i]->SetMarkerSize(0.9);
    diveta_mc_b[i]->SetMarkerColor(2);
  }

  for(int i =1;i<=3; i++){
    int goodpt = etagood_mc->GetBinContent(i);
    int wrongpt = etawrong_mc->GetBinContent(i);
    int entries = goodpt + wrongpt;//ptgood_mc->GetEntries() + ptwrong_mc->GetEntries();
    if(goodpt != 0 ){
      diveta_mc->SetBinContent(i,(float)wrongpt/(float)goodpt); 
      diveta_mc->SetBinError(i,(float)wrongpt/(float)(goodpt*sqrt(entries))); 
    }
  }
  for(int j=0;j<5;j++){
    for(int i =1;i<=3; i++){
      int goodpt = etagood_mc_b[j]->GetBinContent(i);
      int wrongpt = etawrong_mc_b[j]->GetBinContent(i);
      int entries = goodpt+wrongpt;//ptgood_mc->GetEntries() + ptwrong_mc->GetEntries();
      if(goodpt != 0 ){
	diveta_mc_b[j]->SetBinContent(i,(float)wrongpt/(float)goodpt); 
	diveta_mc_b[j]->SetBinError(i,(float)wrongpt/(float)(goodpt*sqrt(entries))); 
      }
    }
  }
  diveta_mc->GetYaxis()->SetRangeUser(0,0.009);
  diveta_mc->Draw();
  c1->SaveAs("../plots/Eta_TPMCZ_bins.gif");

  for(int i=0;i<5;i++){
    tit = "../plots/Eta_TPMCZ_bins_in_pt_bin_"+stuf[i]+".gif";
    diveta_mc_b[i]->GetYaxis()->SetRangeUser(0,0.009);
    diveta_mc_b[i]->Draw();
    c1->SaveAs(tit);
  }

  for(int i =1;i<=5; i++){
    for(int j =1;j<=3; j++){
      int goodpt = etaptgood_mc->GetBinContent(i,j);
      int wrongpt = etaptwrong_mc->GetBinContent(i,j);
      int entries = etaptgood_mc->GetEntries();
      if(goodpt != 0){
	etaptrate_mc->SetBinContent(i,j,(float)wrongpt/(float)goodpt);
	etaptrate_mc->SetBinError(i,j,(float)wrongpt/(float)(goodpt*sqrt(entries))); 
      }
    }
  }

  //////////////histograms z data

  TH1F* ptgood_data = (TH1F*)f3->FindObjectAny("GoodElPt");
  TH1F* ptwrong_data = (TH1F*)f3->FindObjectAny("WrongElPt");
  TH1F* etagood_data = (TH1F*)f3->FindObjectAny("GoodElEta");
  TH1F* etawrong_data = (TH1F*)f3->FindObjectAny("WrongElEta");
  TH2F* etaptgood_data = (TH2F*)f3->FindObjectAny("GoodEl2D");
  TH2F* etaptwrong_data = (TH2F*)f3->FindObjectAny("WrongEl2D");
  TH2F* etaptrate_data = new TH2F("EtaPtRate_DATA","Fake rate in pt and Eta DATA Z",5,0,5,3,0,3);
  TH1F* divpt_data = new TH1F("divpt_data","Fake percentage DATA pt",5,0,5); 
  TH1F* diveta_data = new TH1F("diveta_data","Fake percentage DATA eta",3,0,3); 
  TH1F* ptgood_data_b[3];
  TH1F* ptwrong_data_b[3];
  TH1F* etagood_data_b[5];
  TH1F* etawrong_data_b[5];
  TH1F* divpt_data_b[3];
  TH1F* diveta_data_b[5];
 
  for(int i=0;i<3;i++){
    tit = "Good_El_Pt_in_eta_bin_"+stuf[i];
    ptgood_data_b[i] = (TH1F*)f3->FindObjectAny(tit);
    tit = "Wrong_El_Pt_in_eta_bin_"+stuf[i];
    ptwrong_data_b[i] = (TH1F*)f3->FindObjectAny(tit);
    tit = "Fake_Q_Rate_TPDATA_in_pt_for_eta_bin_"+stuf[i];
    divpt_data_b[i]  = new TH1F(tit,tit,5,0,5);
  }
  for(int i=0;i<5;i++){
    tit = "Good_El_Eta_in_pt_bin_"+stuf[i];
    etagood_data_b[i] = (TH1F*)f3->FindObjectAny(tit);
    tit = "Wrong_El_Eta_in_pt_bin_"+stuf[i];
    etawrong_data_b[i] = (TH1F*)f3->FindObjectAny(tit);
    tit = "Fake_Q_Rate_TPDATA_in_eta_for_pt_bin_"+stuf[i];
    diveta_data_b[i]  = new TH1F(tit,tit,3,0,3);
  }
  divpt_data->GetXaxis()->SetBinLabel(1,"5-10 GeV");
  divpt_data->GetXaxis()->SetBinLabel(2,"10-20 GeV");
  divpt_data->GetXaxis()->SetBinLabel(3,"20-40 GeV");
  divpt_data->GetXaxis()->SetBinLabel(4,"40-70 GeV");
  divpt_data->GetXaxis()->SetBinLabel(5," > 70 GeV");
  divpt_data->GetXaxis()->SetTitle("PF El Pt (GeV)");
  divpt_data->GetYaxis()->SetTitle("Charge miss-identification rate");
  divpt_data->GetXaxis()->SetTitleOffset(1);
  divpt_data->GetYaxis()->SetTitleOffset(2);
  divpt_data->GetXaxis()->SetLabelFont(42);
  divpt_data->GetXaxis()->SetTitleFont(42);
  divpt_data->GetYaxis()->SetLabelFont(42);
  divpt_data->GetYaxis()->SetTitleFont(42);
  divpt_data->SetMarkerStyle(24);
  divpt_data->SetMarkerSize(0.9);
  divpt_data->SetMarkerColor(4);
  for(int i=0;i<3;i++){
    divpt_data_b[i]->GetXaxis()->SetBinLabel(1,"5-10 GeV");
    divpt_data_b[i]->GetXaxis()->SetBinLabel(2,"10-20 GeV");
    divpt_data_b[i]->GetXaxis()->SetBinLabel(3,"20-40 GeV");
    divpt_data_b[i]->GetXaxis()->SetBinLabel(4,"40-70 GeV");
    divpt_data_b[i]->GetXaxis()->SetBinLabel(5," > 70 GeV");
    divpt_data_b[i]->GetXaxis()->SetTitle("PF El Pt (GeV)");
    divpt_data_b[i]->GetYaxis()->SetTitle("Charge miss-identification rate");
    divpt_data_b[i]->GetXaxis()->SetTitleOffset(1);
    divpt_data_b[i]->GetYaxis()->SetTitleOffset(2);
    divpt_data_b[i]->GetXaxis()->SetLabelFont(42);
    divpt_data_b[i]->GetXaxis()->SetTitleFont(42);
    divpt_data_b[i]->GetYaxis()->SetLabelFont(42);
    divpt_data_b[i]->GetYaxis()->SetTitleFont(42);
    divpt_data_b[i]->SetMarkerStyle(24);
    divpt_data_b[i]->SetMarkerSize(0.9);
    divpt_data_b[i]->SetMarkerColor(4);
  }

  for(int i =1;i<=5; i++){
    int goodpt = ptgood_data->GetBinContent(i);
    int wrongpt = ptwrong_data->GetBinContent(i);
    int entries = goodpt + wrongpt; 
    if(goodpt != 0){
      divpt_data->SetBinContent(i,(float)wrongpt/(float)goodpt);
      divpt_data->SetBinError(i,(float)wrongpt/(float)(goodpt*sqrt(entries))); 
    }
  }

  for(int j=0; j<3;j++){
    for(int i =1;i<=5; i++){
      int goodpt = ptgood_data_b[j]->GetBinContent(i);
      int wrongpt = ptwrong_data_b[j]->GetBinContent(i);
      int entries = goodpt + wrongpt;
      if(goodpt != 0){
	divpt_data_b[j]->SetBinContent(i,(float)wrongpt/(float)goodpt);
	divpt_data_b[j]->SetBinError(i,(float)wrongpt/(float)(goodpt*sqrt(entries))); 
      }
    }
  }
  divpt_data->GetYaxis()->SetRangeUser(0,0.009);
  divpt_data->Draw();
  c1->SaveAs("../plots/Pt_TPDATA_bins.gif");
  for(int i=0;i<3;i++){
    tit = "../plots/Pt_TPDATA_bins_in_eta_bin_"+stuf[i]+".gif";
    divpt_data_b[i]->GetYaxis()->SetRangeUser(0,0.009);
    divpt_data_b[i]->Draw();
    c1->SaveAs(tit);
  }

  diveta_data->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
  diveta_data->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
  diveta_data->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
  diveta_data->GetXaxis()->SetTitle("PF El #eta");
  diveta_data->GetYaxis()->SetTitle("Charge miss-identification rate");
  diveta_data->GetXaxis()->SetTitleOffset(1);
  diveta_data->GetYaxis()->SetTitleOffset(2);
  diveta_data->GetXaxis()->SetLabelFont(42);
  diveta_data->GetXaxis()->SetTitleFont(42);
  diveta_data->GetYaxis()->SetLabelFont(42);
  diveta_data->GetYaxis()->SetTitleFont(42);
  diveta_data->SetMarkerStyle(24);
  diveta_data->SetMarkerSize(0.9);
  diveta_data->SetMarkerColor(4);

  for(int i=0;i<5;i++){
    diveta_data_b[i]->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
    diveta_data_b[i]->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
    diveta_data_b[i]->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
    diveta_data_b[i]->GetXaxis()->SetTitle("PF El #eta");
    diveta_data_b[i]->GetYaxis()->SetTitle("Charge miss-identification rate");
    diveta_data_b[i]->GetXaxis()->SetTitleOffset(1);
    diveta_data_b[i]->GetYaxis()->SetTitleOffset(2);
    diveta_data_b[i]->GetXaxis()->SetLabelFont(42);
    diveta_data_b[i]->GetXaxis()->SetTitleFont(42);
    diveta_data_b[i]->GetYaxis()->SetLabelFont(42);
    diveta_data_b[i]->GetYaxis()->SetTitleFont(42);
    diveta_data_b[i]->SetMarkerStyle(24);
    diveta_data_b[i]->SetMarkerSize(0.9);
    diveta_data_b[i]->SetMarkerColor(4);
  }

  for(int i =1;i<=3; i++){
    int goodpt = etagood_data->GetBinContent(i);
    int wrongpt = etawrong_data->GetBinContent(i);
    int entries = goodpt + wrongpt;//ptgood_data->GetEntries() + ptwrong_data->GetEntries();
    if(goodpt != 0 ){
      diveta_data->SetBinContent(i,(float)wrongpt/(float)goodpt); 
      diveta_data->SetBinError(i,(float)wrongpt/(float)(goodpt*sqrt(entries))); 
    }
  }
  for(int j=0;j<5;j++){
    for(int i =1;i<=3; i++){
      int goodpt = etagood_data_b[j]->GetBinContent(i);
      int wrongpt = etawrong_data_b[j]->GetBinContent(i);
      int entries = goodpt+wrongpt;//ptgood_data->GetEntries() + ptwrong_data->GetEntries();
      if(goodpt != 0 ){
	diveta_data_b[j]->SetBinContent(i,(float)wrongpt/(float)goodpt); 
	diveta_data_b[j]->SetBinError(i,(float)wrongpt/(float)(goodpt*sqrt(entries))); 
      }
    }
  }
  diveta_data->GetYaxis()->SetRangeUser(0,0.009);
  diveta_data->Draw();
  c1->SaveAs("../plots/Eta_TPDATA_bins.gif");

  for(int i=0;i<5;i++){
    tit = "../plots/Eta_TPDATA_bins_in_pt_bin_"+stuf[i]+".gif";
    diveta_data_b[i]->GetYaxis()->SetRangeUser(0,0.009);
    diveta_data_b[i]->Draw();
    c1->SaveAs(tit);
  }

  for(int i =1;i<=5; i++){
    for(int j =1;j<=3; j++){
      int goodpt = etaptgood_data->GetBinContent(i,j);
      int wrongpt = etaptwrong_data->GetBinContent(i,j);
      int entries = etaptgood_data->GetEntries();
      if(goodpt != 0){
	etaptrate_data->SetBinContent(i,j,(float)wrongpt/(float)goodpt);
	etaptrate_data->SetBinError(i,j,(float)wrongpt/(float)(goodpt*sqrt(entries))); 
      }
    }
  }
  ///////////////////////comparisons
  divpt->Draw();
  divpt_mc->Draw("SAME");
  divpt_mctz->Draw("SAME");
  divpt_data->Draw("SAME");
  c1->SaveAs("../plots/Pt_TPMCZ_PG_TPDATA_MCTZ_comp.gif");

  diveta->Draw();
  diveta_mc->Draw("SAME");
  diveta_mctz->Draw("SAME");
  diveta_data->Draw("SAME");
  c1->SaveAs("../plots/Eta_TPMCZ_PG_MCTZ_comp.gif");

  for(int i=0;i<3;i++){
    tit = "../plots/Pt_TPMCZ_PG_TPDATA_MCTZ_comp_in_eta_bin_"+stuf[i]+".gif";		
    divpt->Draw();
    divpt_mc_b[i]->Draw("SAME");
    divpt_mctz_b[i]->Draw("SAME");
    divpt_data_b[i]->Draw("SAME");
    c1->SaveAs(tit);
  }
  for(int i=0;i<5;i++){
    tit = "../plots/Eta_TPMCZ_PG_TPDATA_MCTZ_comp_in_pt_bin_"+stuf[i]+".gif";
    diveta_b[i]->GetYaxis()->SetRangeUser(0,0.009);
    diveta_data_b[i]->Draw();
    diveta_mc_b[i]->Draw("SAME");
    diveta_mctz_b[i]->Draw("SAME");
    diveta_b[i]->Draw("SAME");
    c1->SaveAs(tit);
  }

  /////////////////////3 D histograms
  c1->Range(-1.308267,-1.129947,1.296441,1.129947);
  TView *view = TView::CreateView(1);
  view->SetRange(0,0,0,5,3,0.008334489);
  gStyle->SetPalette(1);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(0);
  c1->SetTickx(1);
  c1->SetTicky(1);
  c1->SetTheta(31.5);
  c1->SetPhi(29.79569);
  c1->SetLeftMargin(0.199773);
  c1->SetRightMargin(0.1952327);
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);
  etaptrate->GetXaxis()->SetTitle("Pt (GeV)");
  etaptrate->GetXaxis()->SetLabelFont(42);
  etaptrate->GetXaxis()->SetTitleOffset(2);
  etaptrate->GetXaxis()->SetTitleFont(42);
  etaptrate->GetXaxis()->SetBinLabel(1,"5 < pt < 10");
  etaptrate->GetXaxis()->SetBinLabel(2,"10 < pt < 20");
  etaptrate->GetXaxis()->SetBinLabel(3,"20 < pt < 40");
  etaptrate->GetXaxis()->SetBinLabel(4,"40 < pt < 70");
  etaptrate->GetXaxis()->SetBinLabel(5,"pt > 70");
  etaptrate->GetYaxis()->SetTitle("#eta");
  etaptrate->GetYaxis()->SetLabelFont(42);
  etaptrate->GetXaxis()->SetLabelOffset(0.06);
  etaptrate->GetYaxis()->SetTitleOffset(2);
  etaptrate->GetYaxis()->SetTitleFont(42);
  etaptrate->GetYaxis()->SetBinLabel(1,"| #eta |  < 0.8");
  etaptrate->GetYaxis()->SetBinLabel(2,"0.8 < | #eta |  < 1.6");
  etaptrate->GetYaxis()->SetBinLabel(3,"1.6 < | #eta | < 2.4");
  etaptrate->GetZaxis()->SetTitle("Flip Rate Particle Gun");
  etaptrate->GetZaxis()->SetLabelFont(42);
  etaptrate->GetZaxis()->SetTitleOffset(2);
  etaptrate->GetZaxis()->SetTitleFont(42);
  etaptrate->Draw("LEGO1 ");
  c1->SaveAs("../plots/PtandEta_PG_3D.gif");
  etaptrate_mc->GetXaxis()->SetTitle("Pt (GeV)");
  etaptrate_mc->GetXaxis()->SetLabelFont(42);
  etaptrate_mc->GetXaxis()->SetTitleOffset(2);
  etaptrate_mc->GetXaxis()->SetTitleFont(42);
  etaptrate_mc->GetXaxis()->SetBinLabel(1,"5 < pt < 10");
  etaptrate_mc->GetXaxis()->SetBinLabel(2,"10 < pt < 20");
  etaptrate_mc->GetXaxis()->SetBinLabel(3,"20 < pt < 40");
  etaptrate_mc->GetXaxis()->SetBinLabel(4,"40 < pt < 70");
  etaptrate_mc->GetXaxis()->SetBinLabel(5,"pt > 70");
  etaptrate_mc->GetXaxis()->SetLabelOffset(0.06);
  etaptrate_mc->GetYaxis()->SetTitle("#eta");
  etaptrate_mc->GetYaxis()->SetLabelFont(42);
  etaptrate_mc->GetYaxis()->SetTitleOffset(2);
  etaptrate_mc->GetYaxis()->SetTitleFont(42);
  etaptrate_mc->GetYaxis()->SetBinLabel(1,"| #eta |  < 0.8");
  etaptrate_mc->GetYaxis()->SetBinLabel(2,"0.8 < | #eta |  < 1.6");
  etaptrate_mc->GetYaxis()->SetBinLabel(3,"1.6 < | #eta | < 2.4");
  etaptrate_mc->GetZaxis()->SetTitle("Flip Rate Tag and Probe ZJets Madgraph");
  etaptrate_mc->GetZaxis()->SetLabelFont(42);
  etaptrate_mc->GetZaxis()->SetTitleOffset(2);
  etaptrate_mc->GetZaxis()->SetTitleFont(42);
  etaptrate_mc->Draw("LEGO1 ");
  c1->SaveAs("../plots/PtandEta_TPMCZ_3D.gif");

  etaptrate_mctz->GetXaxis()->SetTitle("Pt (GeV)");
  etaptrate_mctz->GetXaxis()->SetLabelFont(42);
  etaptrate_mctz->GetXaxis()->SetTitleOffset(2);
  etaptrate_mctz->GetXaxis()->SetTitleFont(42);
  etaptrate_mctz->GetXaxis()->SetBinLabel(1,"5 < pt < 10");
  etaptrate_mctz->GetXaxis()->SetBinLabel(2,"10 < pt < 20");
  etaptrate_mctz->GetXaxis()->SetBinLabel(3,"20 < pt < 40");
  etaptrate_mctz->GetXaxis()->SetBinLabel(4,"40 < pt < 70");
  etaptrate_mctz->GetXaxis()->SetBinLabel(5,"pt > 70");
  etaptrate_mctz->GetXaxis()->SetLabelOffset(0.06);
  etaptrate_mctz->GetYaxis()->SetTitle("#eta");
  etaptrate_mctz->GetYaxis()->SetLabelFont(42);
  etaptrate_mctz->GetYaxis()->SetTitleOffset(2);
  etaptrate_mctz->GetYaxis()->SetTitleFont(42);
  etaptrate_mctz->GetYaxis()->SetBinLabel(1,"| #eta |  < 0.8");
  etaptrate_mctz->GetYaxis()->SetBinLabel(2,"0.8 < | #eta |  < 1.6");
  etaptrate_mctz->GetYaxis()->SetBinLabel(3,"1.6 < | #eta | < 2.4");
  etaptrate_mctz->GetZaxis()->SetTitle("Flip Rate MCTruth ZJets Madgraph");
  etaptrate_mctz->GetZaxis()->SetLabelFont(42);
  etaptrate_mctz->GetZaxis()->SetTitleOffset(2);
  etaptrate_mctz->GetZaxis()->SetTitleFont(42);
  etaptrate_mctz->Draw("LEGO1 ");
  c1->SaveAs("../plots/PtandEta_MCTZ_3D.gif");

  etaptrate_data->GetXaxis()->SetTitle("Pt (GeV)");
  etaptrate_data->GetXaxis()->SetLabelFont(42);
  etaptrate_data->GetXaxis()->SetTitleOffset(2);
  etaptrate_data->GetXaxis()->SetTitleFont(42);
  etaptrate_data->GetXaxis()->SetBinLabel(1,"5 < pt < 10");
  etaptrate_data->GetXaxis()->SetBinLabel(2,"10 < pt < 20");
  etaptrate_data->GetXaxis()->SetBinLabel(3,"20 < pt < 40");
  etaptrate_data->GetXaxis()->SetBinLabel(4,"40 < pt < 70");
  etaptrate_data->GetXaxis()->SetBinLabel(5,"pt > 70");
  etaptrate_data->GetXaxis()->SetLabelOffset(0.06);
  etaptrate_data->GetYaxis()->SetTitle("#eta");
  etaptrate_data->GetYaxis()->SetLabelFont(42);
  etaptrate_data->GetYaxis()->SetTitleOffset(2);
  etaptrate_data->GetYaxis()->SetTitleFont(42);
  etaptrate_data->GetYaxis()->SetBinLabel(1,"| #eta |  < 0.8");
  etaptrate_data->GetYaxis()->SetBinLabel(2,"0.8 < | #eta |  < 1.6");
  etaptrate_data->GetYaxis()->SetBinLabel(3,"1.6 < | #eta | < 2.4");
  etaptrate_data->GetZaxis()->SetTitle("Flip Rate Tag and Probe Data");
  etaptrate_data->GetZaxis()->SetLabelFont(42);
  etaptrate_data->GetZaxis()->SetTitleOffset(2);
  etaptrate_data->GetZaxis()->SetTitleFont(42);
  etaptrate_data->Draw("LEGO1 ");
  c1->SaveAs("../plots/PtandEta_TPDATA_3D.gif");
}
