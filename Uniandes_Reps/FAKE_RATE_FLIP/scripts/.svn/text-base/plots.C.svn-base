{
#include <stdlib>
#include <TString.h>
  TFile *f1 = TFile::Open("../root_files/MC_PG.root");
  TFile *f2 = TFile::Open("../root_files/iso.root"); 
  //  TFile *f3 = TFile::Open("../root_files/Z_TandP_data.root");
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
  c1->SetLogy(1);
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
  divpt->SetLineColor(1);
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
    divpt_b[i]->SetLineColor(1);
  }
  divpt->Sumw2();
  divpt->Divide(ptwrong,ptgood,1,1,"");
  for(int j=0; j<3;j++){
    divpt_b[j]->Sumw2();
    divpt_b[j]->Divide(ptwrong_b[j],ptgood_b[j],1,1,"");
  }
  c1->cd();
  divpt->GetYaxis()->SetRangeUser(0.00001,1);
  divpt->Draw("E1");
  c1->SaveAs("../plots/Pt_PG_bins.gif");
  for(int i=0;i < 3; i++){
    tit = "../plots/Pt_PG_bins_in_eta_bin_"+stuf[i]+".gif";
    c1->cd();
    divpt_b[i]->GetYaxis()->SetRangeUser(0.00001,1);
    divpt_b[i]->Draw("E1");
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
  etagood->Sumw2();
  etawrong->Sumw2();
  diveta->Sumw2();
  diveta->Divide(etawrong,etagood,1,1,"");
  for(int j=0;j<5;j++){
    etagood_b[j]->Sumw2();
    etawrong_b[j]->Sumw2();
    diveta_b[j]->Sumw2();
    diveta_b[j]->Divide(etawrong_b[j],etagood_b[j],1,1,"");
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
  diveta->SetLineColor(1);
  diveta->GetYaxis()->SetRangeUser(0.00001,1);
  diveta->Draw("E1");
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
    diveta_b[j]->SetLineColor(1);
    tit = "../plots/Eta_PG_bins_in_pt_bin_"+stuf[j]+".gif";
    diveta_b[j]->GetYaxis()->SetRangeUser(0.00001,1);
    diveta_b[j]->Draw("E1");
    c1->SaveAs(tit);
  }
  etaptgood->Sumw2();
  etaptwrong->Sumw2();
  etaptrate->Sumw2();
  etaptrate->Divide(etaptwrong,etaptgood,1,1,"");
  for(int i =1;i<=5; i++){
    for(int j =1;j<=3; j++){
      std::cout << "bin i,j: " << i << " , " << j << " : " << etaptrate->GetBinContent(i,j) << " +/- " << etaptrate->GetBinError(i,j) << endl;
    }
  }

  /////////histograms in MC Truth Zjets
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
  divpt_mctz->SetMarkerStyle(12);
  divpt_mctz->SetMarkerSize(0.8);
  divpt_mctz->SetMarkerColor(3);
  divpt_mctz->SetLineColor(3);
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
    divpt_mctz_b[i]->SetMarkerStyle(12);
    divpt_mctz_b[i]->SetMarkerSize(0.8);
    divpt_mctz_b[i]->SetMarkerColor(3);
    divpt_mctz_b[i]->SetLineColor(3);
  }
  ptgood_mctz->Sumw2();
  ptwrong_mctz->Sumw2();
  divpt_mctz->Sumw2();
  divpt_mctz->Divide(ptwrong_mctz,ptgood_mctz,1,1,"");

  for(int j=0; j<3;j++){
    ptgood_mctz_b[j]->Sumw2();
    ptwrong_mctz_b[j]->Sumw2();
    divpt_mctz_b[j]->Sumw2();
    divpt_mctz_b[j]->Divide(ptwrong_mctz_b[j],ptgood_mctz_b[j],1,1,"");
  }
  c1->cd();
  divpt_mctz->GetYaxis()->SetRangeUser(0.00001,1);
  divpt_mctz->Draw("E1");
  c1->SaveAs("../plots/Pt_MCTZ_bins.gif");
  for(int i=0;i < 3; i++){
    tit = "../plots/Pt_MCTZ_bins_in_eta_bin_"+stuf[i]+".gif";
    c1->cd();
    divpt_mctz_b[i]->GetYaxis()->SetRangeUser(0.00001,1);
    divpt_mctz_b[i]->Draw("E1");
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
  etagood_mctz->Sumw2();
  etawrong_mctz->Sumw2();
  diveta_mctz->Sumw2();
  diveta_mctz->Divide(etawrong_mctz,etagood_mctz,1,1,"");

  for(int j=0;j<5;j++){
    etagood_mctz_b[j]->Sumw2();
    etawrong_mctz_b[j]->Sumw2();
    diveta_mctz_b[j]->Sumw2();
    diveta_mctz_b[j]->Divide(etawrong_mctz_b[j],etagood_mctz_b[j],1,1,"");
  }
  diveta_mctz->GetXaxis()->SetTitle("PF El #eta");
  diveta_mctz->GetYaxis()->SetTitle("Charge miss-identification rate");
  diveta_mctz->GetXaxis()->SetTitleOffset(1);
  diveta_mctz->GetYaxis()->SetTitleOffset(2);
  diveta_mctz->GetXaxis()->SetLabelFont(42);
  diveta_mctz->GetXaxis()->SetTitleFont(42);
  diveta_mctz->GetYaxis()->SetLabelFont(42);
  diveta_mctz->GetYaxis()->SetTitleFont(42);
  diveta_mctz->SetMarkerStyle(12);
  diveta_mctz->SetMarkerSize(0.8);
  diveta_mctz->SetMarkerColor(3);
  diveta_mctz->SetLineColor(3);
  diveta_mctz->GetYaxis()->SetRangeUser(0.00001,1);
  diveta_mctz->Draw("E1");
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
    diveta_mctz_b[j]->SetMarkerStyle(12);
    diveta_mctz_b[j]->SetMarkerSize(0.8);
    diveta_mctz_b[j]->SetMarkerColor(3);
    diveta_mctz_b[j]->SetLineColor(3);
    tit = "../plots/Eta_MCTZ_bins_in_pt_bin_"+stuf[j]+".gif";
    diveta_mctz_b[j]->GetYaxis()->SetRangeUser(0.00001,1);
    diveta_mctz_b[j]->Draw("E1");
    c1->SaveAs(tit);
  }
  etaptgood_mctz->Sumw2();
  etaptwrong_mctz->Sumw2();
  etaptrate_mctz->Sumw2();
  etaptrate_mctz->Divide(etaptwrong_mctz,etaptgood_mctz,1,1,"");
  for(int i =1;i<=5; i++){
    for(int j =1;j<=3; j++){
      std::cout << "MCT bin i,j: " << i << " , " << j << " : " << etaptrate_mctz->GetBinContent(i,j) << " +/- " << etaptrate_mctz->GetBinError(i,j) << endl;
    }
  }
  /////////////////histograms in Tag and Probe method MC ZJets Madgrph
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
  divpt_mc->SetMarkerStyle(12);
  divpt_mc->SetMarkerSize(0.9);
  divpt_mc->SetMarkerColor(2);
  divpt_mc->SetLineColor(2);
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
    divpt_mc_b[i]->SetMarkerStyle(12);
    divpt_mc_b[i]->SetMarkerSize(0.9);
    divpt_mc_b[i]->SetMarkerColor(2);
    divpt_mc_b[i]->SetLineColor(2);
  }
  ptgood_mc->Sumw2();
  ptwrong_mc->Sumw2();
  divpt_mc->Sumw2();
  divpt_mc->Divide(ptwrong_mc,ptgood_mc,1,1,"");

  for(int j=0; j<3;j++){
    ptgood_mc_b[j]->Sumw2();
    ptwrong_mc_b[j]->Sumw2();
    divpt_mc_b[j]->Sumw2();
    divpt_mc_b[j]->Divide(ptwrong_mc_b[j],ptgood_mc_b[j],1,1,"");
  }
  divpt_mc->GetYaxis()->SetRangeUser(0.00001,1);
  divpt_mc->Draw("E1");
  c1->SaveAs("../plots/Pt_TPMCZ_bins.gif");
  for(int i=0;i<3;i++){
    tit = "../plots/Pt_TPMCZ_bins_in_eta_bin_"+stuf[i]+".gif";
    divpt_mc_b[i]->GetYaxis()->SetRangeUser(0.00001,1);
    divpt_mc_b[i]->Draw("E1");
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
  diveta_mc->SetMarkerStyle(12);
  diveta_mc->SetMarkerSize(0.9);
  diveta_mc->SetMarkerColor(2);
  diveta_mc->SetLineColor(2);

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
    diveta_mc_b[i]->SetMarkerStyle(12);
    diveta_mc_b[i]->SetMarkerSize(0.9);
    diveta_mc_b[i]->SetMarkerColor(2);
    diveta_mc_b[i]->SetLineColor(2);
  }
  etagood_mc->Sumw2();
  etawrong_mc->Sumw2();
  diveta_mc->Sumw2();
  diveta_mc->Divide(etawrong_mc,etagood_mc,1,1,"");

  for(int j=0;j<5;j++){
    etagood_mc_b[j]->Sumw2();
    etawrong_mc_b[j]->Sumw2();
    diveta_mc_b[j]->Sumw2();
    diveta_mc_b[j]->Divide(etawrong_mc_b[j],etagood_mc_b[j],1,1,"");
  }
  diveta_mc->GetYaxis()->SetRangeUser(0.00001,1);
  diveta_mc->Draw("E1");
  c1->SaveAs("../plots/Eta_TPMCZ_bins.gif");

  for(int i=0;i<5;i++){
    tit = "../plots/Eta_TPMCZ_bins_in_pt_bin_"+stuf[i]+".gif";
    diveta_mc_b[i]->GetYaxis()->SetRangeUser(0.00001,1);
    diveta_mc_b[i]->Draw("E1");
    c1->SaveAs(tit);
  }
  etaptgood_mc->Sumw2();
  etaptwrong_mc->Sumw2();
  etaptrate_mc->Sumw2();
  etaptrate_mc->Divide(etaptwrong_mc,etaptgood_mc,1,1,"");

  /*
  /////////////////////////////// histograms no electron selection mc z
  
  TH1F* ptgood_mc_ses = (TH1F*)f2->FindObjectAny("GoodElPt_ses");
  TH1F* ptwrong_mc_ses = (TH1F*)f2->FindObjectAny("WrongElPt_ses");
  TH1F* etagood_mc_ses = (TH1F*)f2->FindObjectAny("GoodElEta_ses");
  TH1F* etawrong_mc_ses = (TH1F*)f2->FindObjectAny("WrongElEta_ses");
  TH2F* etaptgood_mc_ses = (TH2F*)f2->FindObjectAny("GoodEl2D_ses");
  TH2F* etaptwrong_mc_ses = (TH2F*)f2->FindObjectAny("WrongEl2D_ses");
  
  TH2F* etaptrate_mc_ses = new TH2F("EtaPtRate_TPMCZ_ses","Fake rate in pt and Eta MC Z",5,0,5,3,0,3);
  
  //TH2F* etaptrate_mc_pses = new TH2F("EtaPtRate_TPMCZ_pses","Fake rate in pt and Eta MC Z",5,0,5,3,0,3);
  
  TH1F* divpt_mc_ses = new TH1F("divpt_mc_ses","Fake percentage MC pt",5,0,5); 
  TH1F* diveta_mc_ses = new TH1F("diveta_mc_ses","Fake percentage MC eta",3,0,3); 
    
  TH1F* divpt_mc_pses = new TH1F("divpt_mc_pses","Fake percentage MC pt",5,0,5); 
  TH1F* diveta_mc_pses = new TH1F("diveta_mc_pses","Fake percentage MC eta",3,0,3); 
  TH1F* ptgood_mc_ses_b[3];
  TH1F* ptwrong_mc_ses_b[3];
  TH1F* etagood_mc_ses_b[5];
  TH1F* etawrong_mc_ses_b[5];
  
  TH1F* divpt_mc_ses_b[3];
  TH1F* diveta_mc_ses_b[5];
  
  TH1F* divpt_mc_pses_b[3];
  TH1F* diveta_mc_pses_b[5];
  

  for(int i=0;i<3;i++){
    
    tit = "Good_El_Pt_ses_in_eta_bin_"+stuf[i];
    ptgood_mc_ses_b[i] = (TH1F*)f2->FindObjectAny(tit);
    tit = "Wrong_El_Pt_ses_in_eta_bin_"+stuf[i];
    ptwrong_mc_ses_b[i] = (TH1F*)f2->FindObjectAny(tit);
    
    tit = "Fake_Q_Rate_TPMCZ_ses_in_pt_for_eta_bin_"+stuf[i];
    divpt_mc_ses_b[i]  = new TH1F(tit,tit,5,0,5);
  
    //    tit = "Fake_Q_Rate_TPMCZ_pses_in_pt_for_eta_bin_"+stuf[i];
    //    divpt_mc_pses_b[i]  = new TH1F(tit,tit,5,0,5);
  
  }
  for(int i=0;i<5;i++){
    
    tit = "Good_El_ses_Eta_in_pt_bin_"+stuf[i];
    etagood_mc_ses_b[i] = (TH1F*)f2->FindObjectAny(tit);
    tit = "Wrong_El_ses_Eta_in_pt_bin_"+stuf[i];
    etawrong_mc_ses_b[i] = (TH1F*)f2->FindObjectAny(tit);
    
    tit = "Fake_Q_Rate_TPMCZ_ses_in_eta_for_pt_bin_"+stuf[i];
    diveta_mc_ses_b[i]  = new TH1F(tit,tit,3,0,3);
  
    //    tit = "Fake_Q_Rate_TPMCZ_pses_in_eta_for_pt_bin_"+stuf[i];
    //    diveta_mc_pses_b[i]  = new TH1F(tit,tit,3,0,3);
  }

  divpt_mc_ses->GetXaxis()->SetBinLabel(1,"5-10 GeV");
  divpt_mc_ses->GetXaxis()->SetBinLabel(2,"10-20 GeV");
  divpt_mc_ses->GetXaxis()->SetBinLabel(3,"20-40 GeV");
  divpt_mc_ses->GetXaxis()->SetBinLabel(4,"40-70 GeV");
  divpt_mc_ses->GetXaxis()->SetBinLabel(5," > 70 GeV");
  divpt_mc_ses->GetXaxis()->SetTitle("PF El Pt (GeV)");
  divpt_mc_ses->GetYaxis()->SetTitle("Charge miss-identification rate");
  divpt_mc_ses->GetXaxis()->SetTitleOffset(1);
  divpt_mc_ses->GetYaxis()->SetTitleOffset(2);
  divpt_mc_ses->GetXaxis()->SetLabelFont(42);
  divpt_mc_ses->GetXaxis()->SetTitleFont(42);
  divpt_mc_ses->GetYaxis()->SetLabelFont(42);
  divpt_mc_ses->GetYaxis()->SetTitleFont(42);
  divpt_mc_ses->SetMarkerStyle(12);
  divpt_mc_ses->SetMarkerSize(0.9);
  divpt_mc_ses->SetMarkerColor(5);
  divpt_mc_ses->SetLineColor(5);
  
  divpt_mc_pses->GetXaxis()->SetBinLabel(1,"5-10 GeV");
  divpt_mc_pses->GetXaxis()->SetBinLabel(2,"10-20 GeV");
  divpt_mc_pses->GetXaxis()->SetBinLabel(3,"20-40 GeV");
  divpt_mc_pses->GetXaxis()->SetBinLabel(4,"40-70 GeV");
  divpt_mc_pses->GetXaxis()->SetBinLabel(5," > 70 GeV");
  divpt_mc_pses->GetXaxis()->SetTitle("PF El Pt (GeV)");
  divpt_mc_pses->GetYaxis()->SetTitle("Charge miss-identification rate");
  divpt_mc_pses->GetXaxis()->SetTitleOffset(1);
  divpt_mc_pses->GetYaxis()->SetTitleOffset(2);
  divpt_mc_pses->GetXaxis()->SetLabelFont(42);
  divpt_mc_pses->GetXaxis()->SetTitleFont(42);
  divpt_mc_pses->GetYaxis()->SetLabelFont(42);
  divpt_mc_pses->GetYaxis()->SetTitleFont(42);
  divpt_mc_pses->SetMarkerStyle(12);
  divpt_mc_pses->SetMarkerSize(0.9);
  divpt_mc_pses->SetMarkerColor(7);
  divpt_mc_pses->SetLineColor(7);
  
  for(int i=0;i<3;i++){
    divpt_mc_ses_b[i]->GetXaxis()->SetBinLabel(1,"5-10 GeV");
    divpt_mc_ses_b[i]->GetXaxis()->SetBinLabel(2,"10-20 GeV");
    divpt_mc_ses_b[i]->GetXaxis()->SetBinLabel(3,"20-40 GeV");
    divpt_mc_ses_b[i]->GetXaxis()->SetBinLabel(4,"40-70 GeV");
    divpt_mc_ses_b[i]->GetXaxis()->SetBinLabel(5," > 70 GeV");
    divpt_mc_ses_b[i]->GetXaxis()->SetTitle("PF El Pt (GeV)");
    divpt_mc_ses_b[i]->GetYaxis()->SetTitle("Charge miss-identification rate");
    divpt_mc_ses_b[i]->GetXaxis()->SetTitleOffset(1);
    divpt_mc_ses_b[i]->GetYaxis()->SetTitleOffset(2);
    divpt_mc_ses_b[i]->GetXaxis()->SetLabelFont(42);
    divpt_mc_ses_b[i]->GetXaxis()->SetTitleFont(42);
    divpt_mc_ses_b[i]->GetYaxis()->SetLabelFont(42);
    divpt_mc_ses_b[i]->GetYaxis()->SetTitleFont(42);
    divpt_mc_ses_b[i]->SetMarkerStyle(12);
    divpt_mc_ses_b[i]->SetMarkerSize(0.9);
    divpt_mc_ses_b[i]->SetMarkerColor(5);
    divpt_mc_ses_b[i]->SetLineColor(5);
    
    /////////////
    divpt_mc_pses_b[i]->GetXaxis()->SetBinLabel(1,"5-10 GeV");
    divpt_mc_pses_b[i]->GetXaxis()->SetBinLabel(2,"10-20 GeV");
    divpt_mc_pses_b[i]->GetXaxis()->SetBinLabel(3,"20-40 GeV");
    divpt_mc_pses_b[i]->GetXaxis()->SetBinLabel(4,"40-70 GeV");
    divpt_mc_pses_b[i]->GetXaxis()->SetBinLabel(5," > 70 GeV");
    divpt_mc_pses_b[i]->GetXaxis()->SetTitle("PF El Pt (GeV)");
    divpt_mc_pses_b[i]->GetYaxis()->SetTitle("Charge miss-identification rate");
    divpt_mc_pses_b[i]->GetXaxis()->SetTitleOffset(1);
    divpt_mc_pses_b[i]->GetYaxis()->SetTitleOffset(2);
    divpt_mc_pses_b[i]->GetXaxis()->SetLabelFont(42);
    divpt_mc_pses_b[i]->GetXaxis()->SetTitleFont(42);
    divpt_mc_pses_b[i]->GetYaxis()->SetLabelFont(42);
    divpt_mc_pses_b[i]->GetYaxis()->SetTitleFont(42);
    divpt_mc_pses_b[i]->SetMarkerStyle(12);
    divpt_mc_pses_b[i]->SetMarkerSize(0.9);
    divpt_mc_pses_b[i]->SetMarkerColor(7);
    divpt_mc_pses_b[i]->SetLineColor(7);
    
  }
  divpt_mc_ses->Sumw2();
  double k = 0;
  if((ptgood_mc->GetIntegral()-ptwrong_mc->GetIntegral())!=0)     
    k= (double)(ptwrong_mc->GetIntegral())/(ptgood_mc->GetIntegral()-ptwrong_mc->GetIntegral());
  //  double k = (double)(ptwrong_mc->GetIntegral()/(ptgood_mc->GetIntegral()-ptwrong_mc->GetIntegral()));
  cout <<"aca" << endl;
  for(int i =1;i<=5; i++){
    int goodpt = ptgood_mc->GetBinContent(i);
    int wrongpt = ptwrong_mc->GetBinContent(i);
    int entries = goodpt; 
    int os = goodpt - wrongpt;
    if(goodpt != 0){
      divpt_mc_ses->SetBinContent(i,float((wrongpt-k*os)/(goodpt)));
      //      divpt_mc_pses->SetBinContent(i,(float)wrongpt/(float)goodpt);
      //      divpt_mc_pses->SetBinError(i,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
    }
  }
  cout <<"aca" << endl;
  for(int j=0; j<3;j++){
    for(int i =1;i<=5; i++){
      int goodpt = ptgood_mc_b[j]->GetBinContent(i);
      int wrongpt = ptwrong_mc_b[j]->GetBinContent(i);
      int entries = goodpt;
      int os = goodpt - wrongpt;
      if(goodpt != 0){
	divpt_mc_ses_b[j]->SetBinContent(i,float(wrongpt-k*os)/goodpt);
	//      divpt_mc_ses_b[j]->SetBinError(i,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
	//   
      }
      
      if(goodpt != 0){
	divpt_mc_pses_b[j]->SetBinContent(i,(float)wrongpt/(float)goodpt);
	divpt_mc_pses_b[j]->SetBinError(i,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
      }
      
    }
  }
  divpt_mc_ses->GetYaxis()->SetRangeUser(0.00001,1);
  divpt_mc_ses->Draw("E1");
  c1->SaveAs("../plots/Pt_TPMCZ_ses_bins.gif");
  
  divpt_mc_pses->GetYaxis()->SetRangeUser(0.00001,1);
  divpt_mc_pses->Draw("E1");
  c1->SaveAs("../plots/Pt_TPMCZ_pses_bins.gif");
  
  for(int i=0;i<3;i++){
    tit = "../plots/Pt_TPMCZ_ses_bins_in_eta_bin_"+stuf[i]+".gif";
    divpt_mc_ses_b[i]->GetYaxis()->SetRangeUser(0.00001,1);
    divpt_mc_ses_b[i]->Draw("E1");
    c1->SaveAs(tit);
    
    tit = "../plots/Pt_TPMCZ_pses_bins_in_eta_bin_"+stuf[i]+".gif";
    divpt_mc_pses_b[i]->GetYaxis()->SetRangeUser(0.00001,1);
    divpt_mc_pses_b[i]->Draw("E1");
    c1->SaveAs(tit);
    
  }
  diveta_mc_ses->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
  diveta_mc_ses->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
  diveta_mc_ses->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
  diveta_mc_ses->GetXaxis()->SetTitle("PF El #eta");
  diveta_mc_ses->GetYaxis()->SetTitle("Charge miss-identification rate");
  diveta_mc_ses->GetXaxis()->SetTitleOffset(1);
  diveta_mc_ses->GetYaxis()->SetTitleOffset(2);
  diveta_mc_ses->GetXaxis()->SetLabelFont(42);
  diveta_mc_ses->GetXaxis()->SetTitleFont(42);
  diveta_mc_ses->GetYaxis()->SetLabelFont(42);
  diveta_mc_ses->GetYaxis()->SetTitleFont(42);
  diveta_mc_ses->SetMarkerStyle(12);
  diveta_mc_ses->SetMarkerSize(0.9);
  diveta_mc_ses->SetMarkerColor(5);
  diveta_mc_ses->SetLineColor(5);
    
  diveta_mc_pses->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
  diveta_mc_pses->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
  diveta_mc_pses->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
  diveta_mc_pses->GetXaxis()->SetTitle("PF El #eta");
  diveta_mc_pses->GetYaxis()->SetTitle("Charge miss-identification rate");
  diveta_mc_pses->GetXaxis()->SetTitleOffset(1);
  diveta_mc_pses->GetYaxis()->SetTitleOffset(2);
  diveta_mc_pses->GetXaxis()->SetLabelFont(42);
  diveta_mc_pses->GetXaxis()->SetTitleFont(42);
  diveta_mc_pses->GetYaxis()->SetLabelFont(42);
  diveta_mc_pses->GetYaxis()->SetTitleFont(42);
  diveta_mc_pses->SetMarkerStyle(12);
  diveta_mc_pses->SetMarkerSize(0.9);
  diveta_mc_pses->SetMarkerColor(7);
  diveta_mc_pses->SetLineColor(7);
  
  for(int i=0;i<5;i++){
    diveta_mc_ses_b[i]->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
    diveta_mc_ses_b[i]->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
    diveta_mc_ses_b[i]->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
    diveta_mc_ses_b[i]->GetXaxis()->SetTitle("PF El #eta");
    diveta_mc_ses_b[i]->GetYaxis()->SetTitle("Charge miss-identification rate");
    diveta_mc_ses_b[i]->GetXaxis()->SetTitleOffset(1);
    diveta_mc_ses_b[i]->GetYaxis()->SetTitleOffset(2);
    diveta_mc_ses_b[i]->GetXaxis()->SetLabelFont(42);
    diveta_mc_ses_b[i]->GetXaxis()->SetTitleFont(42);
    diveta_mc_ses_b[i]->GetYaxis()->SetLabelFont(42);
    diveta_mc_ses_b[i]->GetYaxis()->SetTitleFont(42);
    diveta_mc_ses_b[i]->SetMarkerStyle(12);
    diveta_mc_ses_b[i]->SetMarkerSize(0.9);
    diveta_mc_ses_b[i]->SetMarkerColor(5);
    diveta_mc_ses_b[i]->SetLineColor(5);
    ////////
    
    diveta_mc_pses_b[i]->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
    diveta_mc_pses_b[i]->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
    diveta_mc_pses_b[i]->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
    diveta_mc_pses_b[i]->GetXaxis()->SetTitle("PF El #eta");
    diveta_mc_pses_b[i]->GetYaxis()->SetTitle("Charge miss-identification rate");
    diveta_mc_pses_b[i]->GetXaxis()->SetTitleOffset(1);
    diveta_mc_pses_b[i]->GetYaxis()->SetTitleOffset(2);
    diveta_mc_pses_b[i]->GetXaxis()->SetLabelFont(42);
    diveta_mc_pses_b[i]->GetXaxis()->SetTitleFont(42);
    diveta_mc_pses_b[i]->GetYaxis()->SetLabelFont(42);
    diveta_mc_pses_b[i]->GetYaxis()->SetTitleFont(42);
    diveta_mc_pses_b[i]->SetMarkerStyle(12);
    diveta_mc_pses_b[i]->SetMarkerSize(0.9);
    diveta_mc_pses_b[i]->SetMarkerColor(7);
    diveta_mc_pses_b[i]->SetLineColor(7);
    
  }
  diveta_mc_ses->Sumw2();
  for(int i =1;i<=3; i++){
    int goodpt = etagood_mc->GetBinContent(i);
    int wrongpt = etawrong_mc->GetBinContent(i);
    int entries = goodpt; 
    int os = goodpt - wrongpt;
    if(goodpt != 0){
      diveta_mc_ses->SetBinContent(i,float(wrongpt-k*os)/goodpt);
    }
    
    if(goodpt != 0 ){
      diveta_mc_pses->SetBinContent(i,(float)wrongpt/(float)goodpt); 
      diveta_mc_pses->SetBinError(i,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
    }
    
  }
  for(int j=0;j<5;j++){
    diveta_mc_ses_b[j]->Sumw2();
    for(int i =1;i<=3; i++){
      int goodpt = etagood_mc_b[j]->GetBinContent(i);
      int wrongpt = etawrong_mc_b[j]->GetBinContent(i);
      int entries = goodpt;
      int os = goodpt - wrongpt;
      if(goodpt != 0){
	diveta_mc_ses_b[j]->SetBinContent(i,float(wrongpt-k*os)/goodpt);   
      }
      
      if(goodpt != 0 ){
	diveta_mc_pses_b[j]->SetBinContent(i,(float)wrongpt/(float)goodpt); 
	diveta_mc_pses_b[j]->SetBinError(i,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
      }
      
    }
  }
  diveta_mc_ses->GetYaxis()->SetRangeUser(0.00001,1);
  diveta_mc_ses->Draw("E1");
  c1->SaveAs("../plots/Eta_TPMCZ_ses_bins.gif");
  
  diveta_mc_pses->GetYaxis()->SetRangeUser(0.00001,1);
  diveta_mc_pses->Draw("E1");
  c1->SaveAs("../plots/Eta_TPMCZ_pses_bins.gif");
  
  for(int i=0;i<5;i++){
    tit = "../plots/Eta_TPMCZ_ses_bins_in_pt_bin_"+stuf[i]+".gif";
    diveta_mc_ses_b[i]->GetYaxis()->SetRangeUser(0.00001,1);
    diveta_mc_ses_b[i]->Draw("E1");
    c1->SaveAs(tit);
    
    tit = "../plots/Eta_TPMCZ_pses_bins_in_pt_bin_"+stuf[i]+".gif";
    diveta_mc_pses_b[i]->GetYaxis()->SetRangeUser(0.00001,1);
    diveta_mc_pses_b[i]->Draw("E1");
    c1->SaveAs(tit);
    
  }
  
  for(int i =1;i<=5; i++){
    for(int j =1;j<=3; j++){
      int goodpt = etaptgood_mc_ses->GetBinContent(i,j);
      int wrongpt = etaptwrong_mc_ses->GetBinContent(i,j);
      int entries = etaptgood_mc_ses->GetEntries();
      if(goodpt != 0){
	etaptrate_mc_ses->SetBinContent(i,j,(float)wrongpt/(float)goodpt);
	etaptrate_mc_ses->SetBinError(i,j,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
      }
      wrongpt = etaptwrong_mc->GetBinContent(i,j);
      int entries = goodpt + wrongpt;//etaptgood_mc_ses->GetEntries();
      if(goodpt != 0){
	etaptrate_mc_pses->SetBinContent(i,j,(float)wrongpt/(float)goodpt);
	etaptrate_mc_pses->SetBinError(i,j,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
      }
    }
  }
  */
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
  divpt_data->SetMarkerStyle(12);
  divpt_data->SetMarkerSize(0.9);
  divpt_data->SetMarkerColor(4);
  divpt_data->SetLineColor(4);
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
    divpt_data_b[i]->SetMarkerStyle(12);
    divpt_data_b[i]->SetMarkerSize(0.9);
    divpt_data_b[i]->SetMarkerColor(4);
    divpt_data_b[i]->SetLineColor(4);
  }
  //ptgood_data->Sumw2();
  //ptwrong_data->Sumw2();
  divpt_data->Sumw2();
  divpt_data->Divide(ptwrong_data,ptgood_data,1,1,"");
  for(int j=0; j<3;j++){
    //ptgood_data_b[j]->Sumw2();
    //ptwrong_data_b[j]->Sumw2();
    divpt_data_b[j]->Sumw2();
    divpt_data_b[j]->Divide(ptwrong_data_b[j],ptgood_data_b[j],1,1,"");
  }
  divpt_data->GetYaxis()->SetRangeUser(0.00001,1);
  divpt_data->Draw("E1");
  c1->SaveAs("../plots/Pt_TPDATA_bins.gif");
  for(int i=0;i<3;i++){
    tit = "../plots/Pt_TPDATA_bins_in_eta_bin_"+stuf[i]+".gif";
    divpt_data_b[i]->GetYaxis()->SetRangeUser(0.00001,1);
    divpt_data_b[i]->Draw("E1");
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
  diveta_data->SetMarkerStyle(12);
  diveta_data->SetMarkerSize(0.9);
  diveta_data->SetMarkerColor(4);
  diveta_data->SetLineColor(4);

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
    diveta_data_b[i]->SetMarkerStyle(12);
    diveta_data_b[i]->SetMarkerSize(0.9);
    diveta_data_b[i]->SetMarkerColor(4);
    diveta_data_b[i]->SetLineColor(4);
  }
  //etagood_data->Sumw2();
  //etawrong_data->Sumw2();
  diveta_data->Sumw2();
  diveta_data->Divide(etawrong_data,etagood_data,1,1,"");

  for(int j=0;j<5;j++){
    //etagood_data_b[j]->Sumw2();
    //etawrong_data_b[j]->Sumw2();
    diveta_data_b[j]->Sumw2();
    diveta_data_b[j]->Divide(etawrong_data_b[j],etagood_data_b[j],1,1,"");
  }
  diveta_data->GetYaxis()->SetRangeUser(0.00001,1);
  diveta_data->Draw("E1");
  c1->SaveAs("../plots/Eta_TPDATA_bins.gif");

  for(int i=0;i<5;i++){
    tit = "../plots/Eta_TPDATA_bins_in_pt_bin_"+stuf[i]+".gif";
    diveta_data_b[i]->GetYaxis()->SetRangeUser(0.00001,1);
    diveta_data_b[i]->Draw("E1");
    c1->SaveAs(tit);
  }
  //etaptwrong_data->Sumw2();
  //etaptgood_data->Sumw2();
  etaptrate_data->Sumw2();
  etaptrate_data->Divide(etaptwrong_data,etaptgood_data,1,1,"");
  /*
  ///////////////////// histogram data ses

  TH1F* ptgood_data_ses = (TH1F*)f3->FindObjectAny("GoodElPt_ses");
  TH1F* ptwrong_data_ses = (TH1F*)f3->FindObjectAny("WrongElPt_ses");
  TH1F* etagood_data_ses = (TH1F*)f3->FindObjectAny("GoodElEta_ses");
  TH1F* etawrong_data_ses = (TH1F*)f3->FindObjectAny("WrongElEta_ses");
  TH2F* etaptgood_data_ses = (TH2F*)f3->FindObjectAny("GoodEl2D_ses");
  TH2F* etaptwrong_data_ses = (TH2F*)f3->FindObjectAny("WrongEl2D_ses");
  TH2F* etaptrate_data_ses = new TH2F("EtaPtRate_TPDATAZ_ses","Fake rate in pt and Eta DATA Z",5,0,5,3,0,3);
  TH2F* etaptrate_data_pses = new TH2F("EtaPtRate_TPDATAZ_pses","Fake rate in pt and Eta DATA Z",5,0,5,3,0,3);
  TH1F* divpt_data_ses = new TH1F("divpt_data_ses","Fake percentage DATA pt",5,0,5); 
  TH1F* diveta_data_ses = new TH1F("diveta_data_ses","Fake percentage DATA eta",3,0,3); 
  TH1F* divpt_data_pses = new TH1F("divpt_data_pses","Fake percentage DATA pt",5,0,5); 
  TH1F* diveta_data_pses = new TH1F("diveta_data_pses","Fake percentage DATA eta",3,0,3); 
  TH1F* ptgood_data_ses_b[3];
  TH1F* ptwrong_data_ses_b[3];
  TH1F* etagood_data_ses_b[5];
  TH1F* etawrong_data_ses_b[5];
  TH1F* divpt_data_ses_b[3];
  TH1F* diveta_data_ses_b[5];
  TH1F* divpt_data_pses_b[3];
  TH1F* diveta_data_pses_b[5];
 
  for(int i=0;i<3;i++){
    tit = "Good_El_Pt_ses_in_eta_bin_"+stuf[i];
    ptgood_data_ses_b[i] = (TH1F*)f3->FindObjectAny(tit);
    tit = "Wrong_El_Pt_ses_in_eta_bin_"+stuf[i];
    ptwrong_data_ses_b[i] = (TH1F*)f3->FindObjectAny(tit);
    tit = "Fake_Q_Rate_TPDATAZ_ses_in_pt_for_eta_bin_"+stuf[i];
    divpt_data_ses_b[i]  = new TH1F(tit,tit,5,0,5);
    tit = "Fake_Q_Rate_TPDATAZ_pses_in_pt_for_eta_bin_"+stuf[i];
    divpt_data_pses_b[i]  = new TH1F(tit,tit,5,0,5);
  }
  for(int i=0;i<5;i++){
    tit = "Good_El_ses_Eta_in_pt_bin_"+stuf[i];
    etagood_data_ses_b[i] = (TH1F*)f3->FindObjectAny(tit);
    tit = "Wrong_El_ses_Eta_in_pt_bin_"+stuf[i];
    etawrong_data_ses_b[i] = (TH1F*)f3->FindObjectAny(tit);
    tit = "Fake_Q_Rate_TPDATAZ_ses_in_eta_for_pt_bin_"+stuf[i];
    diveta_data_ses_b[i]  = new TH1F(tit,tit,3,0,3);
    tit = "Fake_Q_Rate_TPDATAZ_pses_in_eta_for_pt_bin_"+stuf[i];
    diveta_data_pses_b[i]  = new TH1F(tit,tit,3,0,3);
  }

  divpt_data_ses->GetXaxis()->SetBinLabel(1,"5-10 GeV");
  divpt_data_ses->GetXaxis()->SetBinLabel(2,"10-20 GeV");
  divpt_data_ses->GetXaxis()->SetBinLabel(3,"20-40 GeV");
  divpt_data_ses->GetXaxis()->SetBinLabel(4,"40-70 GeV");
  divpt_data_ses->GetXaxis()->SetBinLabel(5," > 70 GeV");
  divpt_data_ses->GetXaxis()->SetTitle("PF El Pt (GeV)");
  divpt_data_ses->GetYaxis()->SetTitle("Charge miss-identification rate");
  divpt_data_ses->GetXaxis()->SetTitleOffset(1);
  divpt_data_ses->GetYaxis()->SetTitleOffset(2);
  divpt_data_ses->GetXaxis()->SetLabelFont(42);
  divpt_data_ses->GetXaxis()->SetTitleFont(42);
  divpt_data_ses->GetYaxis()->SetLabelFont(42);
  divpt_data_ses->GetYaxis()->SetTitleFont(42);
  divpt_data_ses->SetMarkerStyle(12);
  divpt_data_ses->SetMarkerSize(0.9);
  divpt_data_ses->SetMarkerColor(6);
  divpt_data_ses->SetLineColor(6);
  divpt_data_pses->GetXaxis()->SetBinLabel(1,"5-10 GeV");
  divpt_data_pses->GetXaxis()->SetBinLabel(2,"10-20 GeV");
  divpt_data_pses->GetXaxis()->SetBinLabel(3,"20-40 GeV");
  divpt_data_pses->GetXaxis()->SetBinLabel(4,"40-70 GeV");
  divpt_data_pses->GetXaxis()->SetBinLabel(5," > 70 GeV");
  divpt_data_pses->GetXaxis()->SetTitle("PF El Pt (GeV)");
  divpt_data_pses->GetYaxis()->SetTitle("Charge miss-identification rate");
  divpt_data_pses->GetXaxis()->SetTitleOffset(1);
  divpt_data_pses->GetYaxis()->SetTitleOffset(2);
  divpt_data_pses->GetXaxis()->SetLabelFont(42);
  divpt_data_pses->GetXaxis()->SetTitleFont(42);
  divpt_data_pses->GetYaxis()->SetLabelFont(42);
  divpt_data_pses->GetYaxis()->SetTitleFont(42);
  divpt_data_pses->SetMarkerStyle(12);
  divpt_data_pses->SetMarkerSize(0.9);
  divpt_data_pses->SetMarkerColor(8);
  divpt_data_pses->SetLineColor(8);
  for(int i=0;i<3;i++){
    divpt_data_ses_b[i]->GetXaxis()->SetBinLabel(1,"5-10 GeV");
    divpt_data_ses_b[i]->GetXaxis()->SetBinLabel(2,"10-20 GeV");
    divpt_data_ses_b[i]->GetXaxis()->SetBinLabel(3,"20-40 GeV");
    divpt_data_ses_b[i]->GetXaxis()->SetBinLabel(4,"40-70 GeV");
    divpt_data_ses_b[i]->GetXaxis()->SetBinLabel(5," > 70 GeV");
    divpt_data_ses_b[i]->GetXaxis()->SetTitle("PF El Pt (GeV)");
    divpt_data_ses_b[i]->GetYaxis()->SetTitle("Charge miss-identification rate");
    divpt_data_ses_b[i]->GetXaxis()->SetTitleOffset(1);
    divpt_data_ses_b[i]->GetYaxis()->SetTitleOffset(2);
    divpt_data_ses_b[i]->GetXaxis()->SetLabelFont(42);
    divpt_data_ses_b[i]->GetXaxis()->SetTitleFont(42);
    divpt_data_ses_b[i]->GetYaxis()->SetLabelFont(42);
    divpt_data_ses_b[i]->GetYaxis()->SetTitleFont(42);
    divpt_data_ses_b[i]->SetMarkerStyle(12);
    divpt_data_ses_b[i]->SetMarkerSize(0.9);
    divpt_data_ses_b[i]->SetMarkerColor(6);
    divpt_data_ses_b[i]->SetLineColor(6);

    /////////////
    divpt_data_pses_b[i]->GetXaxis()->SetBinLabel(1,"5-10 GeV");
    divpt_data_pses_b[i]->GetXaxis()->SetBinLabel(2,"10-20 GeV");
    divpt_data_pses_b[i]->GetXaxis()->SetBinLabel(3,"20-40 GeV");
    divpt_data_pses_b[i]->GetXaxis()->SetBinLabel(4,"40-70 GeV");
    divpt_data_pses_b[i]->GetXaxis()->SetBinLabel(5," > 70 GeV");
    divpt_data_pses_b[i]->GetXaxis()->SetTitle("PF El Pt (GeV)");
    divpt_data_pses_b[i]->GetYaxis()->SetTitle("Charge miss-identification rate");
    divpt_data_pses_b[i]->GetXaxis()->SetTitleOffset(1);
    divpt_data_pses_b[i]->GetYaxis()->SetTitleOffset(2);
    divpt_data_pses_b[i]->GetXaxis()->SetLabelFont(42);
    divpt_data_pses_b[i]->GetXaxis()->SetTitleFont(42);
    divpt_data_pses_b[i]->GetYaxis()->SetLabelFont(42);
    divpt_data_pses_b[i]->GetYaxis()->SetTitleFont(42);
    divpt_data_pses_b[i]->SetMarkerStyle(12);
    divpt_data_pses_b[i]->SetMarkerSize(0.9);
    divpt_data_pses_b[i]->SetMarkerColor(8);
    divpt_data_pses_b[i]->SetLineColor(8);
  }

  for(int i =1;i<=5; i++){
    int goodpt = ptgood_data_ses->GetBinContent(i);
    int wrongpt = ptwrong_data_ses->GetBinContent(i);
    int entries = goodpt + wrongpt; 
    if(goodpt != 0){
      divpt_data_ses->SetBinContent(i,(float)wrongpt/(float)goodpt);
      divpt_data_ses->SetBinError(i,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
    }
    wrongpt = ptwrong_data->GetBinContent(i);
    entries = goodpt + wrongpt; 
    if(goodpt != 0){
      divpt_data_pses->SetBinContent(i,(float)wrongpt/(float)goodpt);
      divpt_data_pses->SetBinError(i,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
    }
  }

  for(int j=0; j<3;j++){
    for(int i =1;i<=5; i++){
      int goodpt = ptgood_data_ses_b[j]->GetBinContent(i);
      int wrongpt = ptwrong_data_ses_b[j]->GetBinContent(i);
      int entries = goodpt + wrongpt;
      if(goodpt != 0){
	divpt_data_ses_b[j]->SetBinContent(i,(float)wrongpt/(float)goodpt);
	divpt_data_ses_b[j]->SetBinError(i,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
      }
      wrongpt = ptwrong_data_b[j]->GetBinContent(i);
      entries = goodpt + wrongpt;
      if(goodpt != 0){
	divpt_data_pses_b[j]->SetBinContent(i,(float)wrongpt/(float)goodpt);
	divpt_data_pses_b[j]->SetBinError(i,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
      }
    }
  }
  divpt_data_ses->GetYaxis()->SetRangeUser(0.00001,1);
  divpt_data_ses->Draw("E1");
  c1->SaveAs("../plots/Pt_TPDATAZ_ses_bins.gif");
  divpt_data_pses->GetYaxis()->SetRangeUser(0.00001,1);
  divpt_data_pses->Draw("E1");
  c1->SaveAs("../plots/Pt_TPDATAZ_pses_bins.gif");
  for(int i=0;i<3;i++){
    tit = "../plots/Pt_TPDATAZ_ses_bins_in_eta_bin_"+stuf[i]+".gif";
    divpt_data_ses_b[i]->GetYaxis()->SetRangeUser(0.00001,1);
    divpt_data_ses_b[i]->Draw("E1");
    c1->SaveAs(tit);
    tit = "../plots/Pt_TPDATAZ_pses_bins_in_eta_bin_"+stuf[i]+".gif";
    divpt_data_pses_b[i]->GetYaxis()->SetRangeUser(0.00001,1);
    divpt_data_pses_b[i]->Draw("E1");
    c1->SaveAs(tit);
  }

  diveta_data_ses->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
  diveta_data_ses->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
  diveta_data_ses->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
  diveta_data_ses->GetXaxis()->SetTitle("PF El #eta");
  diveta_data_ses->GetYaxis()->SetTitle("Charge miss-identification rate");
  diveta_data_ses->GetXaxis()->SetTitleOffset(1);
  diveta_data_ses->GetYaxis()->SetTitleOffset(2);
  diveta_data_ses->GetXaxis()->SetLabelFont(42);
  diveta_data_ses->GetXaxis()->SetTitleFont(42);
  diveta_data_ses->GetYaxis()->SetLabelFont(42);
  diveta_data_ses->GetYaxis()->SetTitleFont(42);
  diveta_data_ses->SetMarkerStyle(12);
  diveta_data_ses->SetMarkerSize(0.9);
  diveta_data_ses->SetMarkerColor(6);
  diveta_data_ses->SetLineColor(6);

  diveta_data_pses->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
  diveta_data_pses->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
  diveta_data_pses->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
  diveta_data_pses->GetXaxis()->SetTitle("PF El #eta");
  diveta_data_pses->GetYaxis()->SetTitle("Charge miss-identification rate");
  diveta_data_pses->GetXaxis()->SetTitleOffset(1);
  diveta_data_pses->GetYaxis()->SetTitleOffset(2);
  diveta_data_pses->GetXaxis()->SetLabelFont(42);
  diveta_data_pses->GetXaxis()->SetTitleFont(42);
  diveta_data_pses->GetYaxis()->SetLabelFont(42);
  diveta_data_pses->GetYaxis()->SetTitleFont(42);
  diveta_data_pses->SetMarkerStyle(12);
  diveta_data_pses->SetMarkerSize(0.9);
  diveta_data_pses->SetMarkerColor(8);
  diveta_data_pses->SetLineColor(8);

  for(int i=0;i<5;i++){
    diveta_data_ses_b[i]->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
    diveta_data_ses_b[i]->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
    diveta_data_ses_b[i]->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
    diveta_data_ses_b[i]->GetXaxis()->SetTitle("PF El #eta");
    diveta_data_ses_b[i]->GetYaxis()->SetTitle("Charge miss-identification rate");
    diveta_data_ses_b[i]->GetXaxis()->SetTitleOffset(1);
    diveta_data_ses_b[i]->GetYaxis()->SetTitleOffset(2);
    diveta_data_ses_b[i]->GetXaxis()->SetLabelFont(42);
    diveta_data_ses_b[i]->GetXaxis()->SetTitleFont(42);
    diveta_data_ses_b[i]->GetYaxis()->SetLabelFont(42);
    diveta_data_ses_b[i]->GetYaxis()->SetTitleFont(42);
    diveta_data_ses_b[i]->SetMarkerStyle(12);
    diveta_data_ses_b[i]->SetMarkerSize(0.9);
    diveta_data_ses_b[i]->SetMarkerColor(6);
    diveta_data_ses_b[i]->SetLineColor(6);
    /////////
    diveta_data_pses_b[i]->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
    diveta_data_pses_b[i]->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
    diveta_data_pses_b[i]->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
    diveta_data_pses_b[i]->GetXaxis()->SetTitle("PF El #eta");
    diveta_data_pses_b[i]->GetYaxis()->SetTitle("Charge miss-identification rate");
    diveta_data_pses_b[i]->GetXaxis()->SetTitleOffset(1);
    diveta_data_pses_b[i]->GetYaxis()->SetTitleOffset(2);
    diveta_data_pses_b[i]->GetXaxis()->SetLabelFont(42);
    diveta_data_pses_b[i]->GetXaxis()->SetTitleFont(42);
    diveta_data_pses_b[i]->GetYaxis()->SetLabelFont(42);
    diveta_data_pses_b[i]->GetYaxis()->SetTitleFont(42);
    diveta_data_pses_b[i]->SetMarkerStyle(12);
    diveta_data_pses_b[i]->SetMarkerSize(0.9);
    diveta_data_pses_b[i]->SetMarkerColor(8);
    diveta_data_pses_b[i]->SetLineColor(8);
  }

  for(int i =1;i<=3; i++){
    int goodpt = etagood_data_ses->GetBinContent(i);
    int wrongpt = etawrong_data_ses->GetBinContent(i);
    int entries = goodpt + wrongpt;//ptgood_data->GetEntries() + ptwrong_data->GetEntries();
    if(goodpt != 0 ){
      diveta_data_ses->SetBinContent(i,(float)wrongpt/(float)goodpt); 
      diveta_data_ses->SetBinError(i,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
    }
    wrongpt = etawrong_data->GetBinContent(i);
    entries = goodpt + wrongpt;//ptgood_data->GetEntries() + ptwrong_data->GetEntries();
    if(goodpt != 0 ){
      diveta_data_pses->SetBinContent(i,(float)wrongpt/(float)goodpt); 
      diveta_data_pses->SetBinError(i,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
    }
  }
  for(int j=0;j<5;j++){
    for(int i =1;i<=3; i++){
      int goodpt = etagood_data_ses_b[j]->GetBinContent(i);
      int wrongpt = etawrong_data_ses_b[j]->GetBinContent(i);
      int entries = goodpt+wrongpt;//ptgood_data->GetEntries() + ptwrong_data->GetEntries();
      if(goodpt != 0 ){
	diveta_data_ses_b[j]->SetBinContent(i,(float)wrongpt/(float)goodpt); 
	diveta_data_ses_b[j]->SetBinError(i,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
      }
      wrongpt = etawrong_data_b[j]->GetBinContent(i);
      entries = goodpt+wrongpt;//ptgood_data->GetEntries() + ptwrong_data->GetEntries();
      if(goodpt != 0 ){
	diveta_data_pses_b[j]->SetBinContent(i,(float)wrongpt/(float)goodpt); 
	diveta_data_pses_b[j]->SetBinError(i,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
      }
    }
  }
  diveta_data_ses->GetYaxis()->SetRangeUser(0.00001,1);
  diveta_data_ses->Draw("E1");
  c1->SaveAs("../plots/Eta_TPDATAZ_ses_bins.gif");

  diveta_data_pses->GetYaxis()->SetRangeUser(0.00001,1);
  diveta_data_pses->Draw("E1");
  c1->SaveAs("../plots/Eta_TPDATAZ_pses_bins.gif");

  for(int i=0;i<5;i++){
    tit = "../plots/Eta_TPDATAZ_ses_bins_in_pt_bin_"+stuf[i]+".gif";
    diveta_data_ses_b[i]->GetYaxis()->SetRangeUser(0.00001,1);
    diveta_data_ses_b[i]->Draw("E1");
    c1->SaveAs(tit);
    tit = "../plots/Eta_TPDATAZ_pses_bins_in_pt_bin_"+stuf[i]+".gif";
    diveta_data_pses_b[i]->GetYaxis()->SetRangeUser(0.00001,1);
    diveta_data_pses_b[i]->Draw("E1");
    c1->SaveAs(tit);
  }

  for(int i =1;i<=5; i++){
    for(int j =1;j<=3; j++){
      int goodpt = etaptgood_data_ses->GetBinContent(i,j);
      int wrongpt = etaptwrong_data_ses->GetBinContent(i,j);
      int entries = etaptgood_data_ses->GetEntries();
      if(goodpt != 0){
	etaptrate_data_ses->SetBinContent(i,j,(float)wrongpt/(float)goodpt);
	etaptrate_data_ses->SetBinError(i,j,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
      }
      wrongpt = etaptwrong_data->GetBinContent(i,j);
      int entries = goodpt + wrongpt;//etaptgood_data_ses->GetEntries();
      if(goodpt != 0){
	etaptrate_data_pses->SetBinContent(i,j,(float)wrongpt/(float)goodpt);
	etaptrate_data_pses->SetBinError(i,j,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
      }
    }
  }
 
  ////////////////////////// histograms data ses

  TH1F* ptgood_data_ses = (TH1F*)f3->FindObjectAny("GoodElPt_ses");
  TH1F* ptwrong_data_ses = (TH1F*)f3->FindObjectAny("WrongElPt_ses");
  TH1F* etagood_data_ses = (TH1F*)f3->FindObjectAny("GoodElEta_ses");
  TH1F* etawrong_data_ses = (TH1F*)f3->FindObjectAny("WrongElEta_ses");
  TH2F* etaptgood_data_ses = (TH2F*)f3->FindObjectAny("GoodEl2D_ses");
  TH2F* etaptwrong_data_ses = (TH2F*)f3->FindObjectAny("WrongEl2D_ses");
  TH2F* etaptrate_data_ses = new TH2F("EtaPtRate_DATA_SES","Fake rate in pt and Eta DATA_SES Z",5,0,5,3,0,3);
  TH1F* divpt_data_ses = new TH1F("divpt_data_ses","Fake percentage DATA_SES pt",5,0,5); 
  TH1F* diveta_data_ses = new TH1F("diveta_data_ses","Fake percentage DATA_SES eta",3,0,3); 
  TH1F* ptgood_data_ses_b[3];
  TH1F* ptwrong_data_ses_b[3];
  TH1F* etagood_data_ses_b[5];
  TH1F* etawrong_data_ses_b[5];
  TH1F* divpt_data_ses_b[3];
  TH1F* diveta_data_ses_b[5];
 
  for(int i=0;i<3;i++){
    tit = "Good_El_Pt_ses_in_eta_bin_"+stuf[i];
    ptgood_data_ses_b[i] = (TH1F*)f3->FindObjectAny(tit);
    tit = "Wrong_El_Pt_ses_in_eta_bin_"+stuf[i];
    ptwrong_data_ses_b[i] = (TH1F*)f3->FindObjectAny(tit);
    tit = "Fake_Q_Rate_TPDATA_SES_in_pt_for_eta_bin_"+stuf[i];
    divpt_data_ses_b[i]  = new TH1F(tit,tit,5,0,5);
  }
  for(int i=0;i<5;i++){
    tit = "Good_El_ses_Eta_in_pt_bin_"+stuf[i];
    etagood_data_ses_b[i] = (TH1F*)f3->FindObjectAny(tit);
    tit = "Wrong_El_ses_Eta_in_pt_bin_"+stuf[i];
    etawrong_data_ses_b[i] = (TH1F*)f3->FindObjectAny(tit);
    tit = "Fake_Q_Rate_TPDATA_SES_in_eta_for_pt_bin_"+stuf[i];
    diveta_data_ses_b[i]  = new TH1F(tit,tit,3,0,3);
  }
  divpt_data_ses->GetXaxis()->SetBinLabel(1,"5-10 GeV");
  divpt_data_ses->GetXaxis()->SetBinLabel(2,"10-20 GeV");
  divpt_data_ses->GetXaxis()->SetBinLabel(3,"20-40 GeV");
  divpt_data_ses->GetXaxis()->SetBinLabel(4,"40-70 GeV");
  divpt_data_ses->GetXaxis()->SetBinLabel(5," > 70 GeV");
  divpt_data_ses->GetXaxis()->SetTitle("PF El Pt (GeV)");
  divpt_data_ses->GetYaxis()->SetTitle("Charge miss-identification rate");
  divpt_data_ses->GetXaxis()->SetTitleOffset(1);
  divpt_data_ses->GetYaxis()->SetTitleOffset(2);
  divpt_data_ses->GetXaxis()->SetLabelFont(42);
  divpt_data_ses->GetXaxis()->SetTitleFont(42);
  divpt_data_ses->GetYaxis()->SetLabelFont(42);
  divpt_data_ses->GetYaxis()->SetTitleFont(42);
  divpt_data_ses->SetMarkerStyle(13);
  divpt_data_ses->SetMarkerSize(0.9);
  divpt_data_ses->SetMarkerColor(8);
  divpt_data_ses->SetLineColor(8);
  for(int i=0;i<3;i++){
    divpt_data_ses_b[i]->GetXaxis()->SetBinLabel(1,"5-10 GeV");
    divpt_data_ses_b[i]->GetXaxis()->SetBinLabel(2,"10-20 GeV");
    divpt_data_ses_b[i]->GetXaxis()->SetBinLabel(3,"20-40 GeV");
    divpt_data_ses_b[i]->GetXaxis()->SetBinLabel(4,"40-70 GeV");
    divpt_data_ses_b[i]->GetXaxis()->SetBinLabel(5," > 70 GeV");
    divpt_data_ses_b[i]->GetXaxis()->SetTitle("PF El Pt (GeV)");
    divpt_data_ses_b[i]->GetYaxis()->SetTitle("Charge miss-identification rate");
    divpt_data_ses_b[i]->GetXaxis()->SetTitleOffset(1);
    divpt_data_ses_b[i]->GetYaxis()->SetTitleOffset(2);
    divpt_data_ses_b[i]->GetXaxis()->SetLabelFont(42);
    divpt_data_ses_b[i]->GetXaxis()->SetTitleFont(42);
    divpt_data_ses_b[i]->GetYaxis()->SetLabelFont(42);
    divpt_data_ses_b[i]->GetYaxis()->SetTitleFont(42);
    divpt_data_ses_b[i]->SetMarkerStyle(13);
    divpt_data_ses_b[i]->SetMarkerSize(0.9);
    divpt_data_ses_b[i]->SetMarkerColor(8);
    divpt_data_ses_b[i]->SetLineColor(8);
  }

  for(int i =1;i<=5; i++){
    int goodpt = ptgood_data_ses->GetBinContent(i);
    int wrongpt = ptwrong_data_ses->GetBinContent(i);
    int entries = goodpt + wrongpt; 
    if(goodpt != 0){
      divpt_data_ses->SetBinContent(i,(float)wrongpt/(float)goodpt);
      divpt_data_ses->SetBinError(i,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
    }
  }

  for(int j=0; j<3;j++){
    for(int i =1;i<=5; i++){
      int goodpt = ptgood_data_ses_b[j]->GetBinContent(i);
      int wrongpt = ptwrong_data_ses_b[j]->GetBinContent(i);
      int entries = goodpt + wrongpt;
      if(goodpt != 0){
	divpt_data_ses_b[j]->SetBinContent(i,(float)wrongpt/(float)goodpt);
	divpt_data_ses_b[j]->SetBinError(i,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
      }
    }
  }
  divpt_data_ses->GetYaxis()->SetRangeUser(0.00001,1);
  divpt_data_ses->Draw("E1");
  c1->SaveAs("../plots/Pt_TPDATA_SES_bins.gif");
  for(int i=0;i<3;i++){
    tit = "../plots/Pt_TPDATA_SES_bins_in_eta_bin_"+stuf[i]+".gif";
    divpt_data_ses_b[i]->GetYaxis()->SetRangeUser(0.00001,1);
    divpt_data_ses_b[i]->Draw("E1");
    c1->SaveAs(tit);
  }

  diveta_data_ses->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
  diveta_data_ses->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
  diveta_data_ses->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
  diveta_data_ses->GetXaxis()->SetTitle("PF El #eta");
  diveta_data_ses->GetYaxis()->SetTitle("Charge miss-identification rate");
  diveta_data_ses->GetXaxis()->SetTitleOffset(1);
  diveta_data_ses->GetYaxis()->SetTitleOffset(2);
  diveta_data_ses->GetXaxis()->SetLabelFont(42);
  diveta_data_ses->GetXaxis()->SetTitleFont(42);
  diveta_data_ses->GetYaxis()->SetLabelFont(42);
  diveta_data_ses->GetYaxis()->SetTitleFont(42);
  diveta_data_ses->SetMarkerStyle(13);
  diveta_data_ses->SetMarkerSize(0.9);
  diveta_data_ses->SetMarkerColor(8);
  diveta_data_ses->SetLineColor(8);

  for(int i=0;i<5;i++){
    diveta_data_ses_b[i]->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
    diveta_data_ses_b[i]->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
    diveta_data_ses_b[i]->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
    diveta_data_ses_b[i]->GetXaxis()->SetTitle("PF El #eta");
    diveta_data_ses_b[i]->GetYaxis()->SetTitle("Charge miss-identification rate");
    diveta_data_ses_b[i]->GetXaxis()->SetTitleOffset(1);
    diveta_data_ses_b[i]->GetYaxis()->SetTitleOffset(2);
    diveta_data_ses_b[i]->GetXaxis()->SetLabelFont(42);
    diveta_data_ses_b[i]->GetXaxis()->SetTitleFont(42);
    diveta_data_ses_b[i]->GetYaxis()->SetLabelFont(42);
    diveta_data_ses_b[i]->GetYaxis()->SetTitleFont(42);
    diveta_data_ses_b[i]->SetMarkerStyle(13);
    diveta_data_ses_b[i]->SetMarkerSize(0.9);
    diveta_data_ses_b[i]->SetMarkerColor(8);
    diveta_data_ses_b[i]->SetLineColor(8);
  }

  for(int i =1;i<=3; i++){
    int goodpt = etagood_data_ses->GetBinContent(i);
    int wrongpt = etawrong_data_ses->GetBinContent(i);
    int entries = goodpt + wrongpt;//ptgood_data_ses->GetEntries() + ptwrong_data_ses->GetEntries();
    if(goodpt != 0 ){
      diveta_data_ses->SetBinContent(i,(float)wrongpt/(float)goodpt); 
      diveta_data_ses->SetBinError(i,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
    }
  }
  for(int j=0;j<5;j++){
    for(int i =1;i<=3; i++){
      int goodpt = etagood_data_ses_b[j]->GetBinContent(i);
      int wrongpt = etawrong_data_ses_b[j]->GetBinContent(i);
      int entries = goodpt+wrongpt;//ptgood_data_ses->GetEntries() + ptwrong_data_ses->GetEntries();
      if(goodpt != 0 ){
	diveta_data_ses_b[j]->SetBinContent(i,(float)wrongpt/(float)goodpt); 
	diveta_data_ses_b[j]->SetBinError(i,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
      }
    }
  }
  diveta_data_ses->GetYaxis()->SetRangeUser(0.00001,1);
  diveta_data_ses->Draw("E1");
  c1->SaveAs("../plots/Eta_TPDATA_SES_bins.gif");

  for(int i=0;i<5;i++){
    tit = "../plots/Eta_TPDATA_SES_bins_in_pt_bin_"+stuf[i]+".gif";
    diveta_data_ses_b[i]->GetYaxis()->SetRangeUser(0.00001,1);
    diveta_data_ses_b[i]->Draw("E1");
    c1->SaveAs(tit);
  }

  for(int i =1;i<=5; i++){
    for(int j =1;j<=3; j++){
      int goodpt = etaptgood_data_ses->GetBinContent(i,j);
      int wrongpt = etaptwrong_data_ses->GetBinContent(i,j);
      int entries = etaptgood_data_ses->GetEntries();
      if(goodpt != 0){
	etaptrate_data_ses->SetBinContent(i,j,(float)wrongpt/(float)goodpt);
	etaptrate_data_ses->SetBinError(i,j,sqrt((1-(float)wrongpt/(float)goodpt)/(float)entries)); 
      }
    }
  }
  */
  ///////////////////////comparisons

  TH1F* h1 = new TH1F("Comparisonallmeasurements","Comparing all measurements",5,0,5);
  for(int i=1;i<=5;i++){
    int ent = ptgood_data->GetBinContent(i) + 1;
    std::cout << "entries " << ent << std::endl; 
    float rat = (float)1/(float)ent;
    std::cout << "rate " << rat << std::endl; 
    float var = sqrt((float)(rat*(1-rat)/(float)ent));
    std::cout << "variance " << var << std::endl; 
    float lim = rat + 1.96*var;
    std::cout << "limit " << lim << std::endl; 
    h1->SetBinContent(i,lim);
  }
  h1->GetYaxis()->SetRangeUser(0.00001,2);
  h1->SetLineColor(4);
  h1->SetFillColor(4);
  h1->GetXaxis()->SetBinLabel(1,"5-10 GeV");
  h1->GetXaxis()->SetBinLabel(2,"10-20 GeV");
  h1->GetXaxis()->SetBinLabel(3,"20-40 GeV");
  h1->GetXaxis()->SetBinLabel(4,"40-70 GeV");
  h1->GetXaxis()->SetBinLabel(5," > 70 GeV");
  h1->GetXaxis()->SetTitle("PF El Pt (GeV)");
  h1->GetYaxis()->SetTitle("Charge miss-identification rate");
  h1->GetXaxis()->SetTitleOffset(1);
  h1->GetYaxis()->SetTitleOffset(2);
  h1->GetXaxis()->SetLabelFont(42);
  h1->GetXaxis()->SetTitleFont(42);
  h1->GetYaxis()->SetLabelFont(42);
  h1->GetYaxis()->SetTitleFont(42);
  h1->Draw();
  divpt->Draw("E1 SAME");
  divpt_mc->Draw("E1 SAME");
  divpt_mctz->Draw("E1 SAME");
  divpt_data->Draw("E1 SAME");
  TLegend *legend = new TLegend(0.5,0.6,0.9,0.9,"");
  legend->AddEntry(h1,"95 % C.L. Region Tag and Probe data", "f");
  legend->AddEntry(divpt,"Particle Gun", "f");
  legend->AddEntry(divpt_mctz,"MC Truth Z sample", "f");
  legend->AddEntry(divpt_mc,"MC Tag and Probe z sample", "f");
  legend->SetFillColor(0);
  legend->SetTextFont(42);
  legend->SetFillStyle(10);
  legend->SetBorderSize(10);
  legend->Draw("SAME");
  c1->SaveAs("../plots/Pt_All_comp.png");

  TH1F* h2 = new TH1F("Comparisonallmeasurements","Comparing all measurements",3,0,3);
  for(int i=1;i<=3;i++){
    int ent = etagood_data->GetBinContent(i) + 1;
    std::cout << "entries " << ent << std::endl; 
    float rat = (float)1/(float)ent;
    std::cout << "rate " << rat << std::endl; 
    float var = sqrt((float)(rat*(1-rat)/(float)ent));
    std::cout << "variance " << var << std::endl; 
    float lim = rat + 1.96*var;
    std::cout << "limit " << lim << std::endl; 
    h2->SetBinContent(i,lim);
  }
  h2->GetYaxis()->SetRangeUser(0.00001,2);
  h2->SetLineColor(4);
  h2->SetFillColor(4);
  h2->GetXaxis()->SetBinLabel(1," #eta < |0.8|");
  h2->GetXaxis()->SetBinLabel(2,"|0.8| < #eta  < |1.6|  ");
  h2->GetXaxis()->SetBinLabel(3,"#eta > 1.6");
  h2->GetXaxis()->SetTitle("PF El #eta");
  h2->GetYaxis()->SetTitle("Charge miss-identification rate");
  h2->GetXaxis()->SetTitleOffset(1);
  h2->GetYaxis()->SetTitleOffset(2);
  h2->GetXaxis()->SetLabelFont(42);
  h2->GetXaxis()->SetTitleFont(42);
  h2->GetYaxis()->SetLabelFont(42);
  h2->GetYaxis()->SetTitleFont(42);
  h2->Draw();
  diveta->Draw("E1 SAME");
  diveta_mc->Draw("E1 SAME");
  diveta_mctz->Draw("E1 SAME");
  diveta_data->Draw("E1 SAME");
  TLegend *legend = new TLegend(0.5,0.6,0.9,0.9,"");
  legend->AddEntry(h2,"95 % C.L. Region Tag and Probe data", "f");
  legend->AddEntry(diveta,"Particle Gun", "f");
  legend->AddEntry(diveta_mctz,"MC Truth Z sample", "f");
  legend->AddEntry(diveta_mc,"MC Tag and Probe z sample", "f");
  legend->SetFillColor(0);
  legend->SetTextFont(42);
  legend->SetFillStyle(10);
  legend->SetBorderSize(10);
  legend->Draw("SAME");
  c1->SaveAs("../plots/Eta_All_comp.png");

  for(int i=0;i<3;i++){
    tit = "../plots/Pt_All_comp_in_eta_bin_"+stuf[i]+".png";		
    for(int j=1;j<=5;j++){
      int ent = ptgood_data_b[i]->GetBinContent(j) + 1;
      std::cout << "entries " << ent << std::endl; 
      float rat = (float)1/(float)ent;
      std::cout << "rate " << rat << std::endl; 
      float var = sqrt((float)(rat*(1-rat)/(float)ent));
      std::cout << "variance " << var << std::endl; 
      float lim = rat + 1.96*var;
      std::cout << "limit " << lim << std::endl; 
      h1->SetBinContent(j,lim);
    }
    h1->Draw();
    divpt_data_b[i]->Draw("E1 SAME");
    divpt_mc_b[i]->Draw("E1 SAME");
    divpt_mctz_b[i]->Draw("E1 SAME");
    divpt_b[i]->Draw("E1 SAME");
    TLegend *legend = new TLegend(0.5,0.6,0.9,0.9,"");
    legend->AddEntry(h1,"95 % C.L. Region Tag and Probe data", "f");
    legend->AddEntry(divpt_b[i],"Particle Gun", "f");
    legend->AddEntry(divpt_mctz_b[i],"MC Truth Z sample", "f");
    legend->AddEntry(divpt_mc_b[i],"MC Tag and Probe z sample", "f");
    legend->SetFillColor(0);
    legend->SetTextFont(42);
    legend->SetFillStyle(10);
    legend->SetBorderSize(10);
    legend->Draw("SAME");
    c1->SaveAs(tit);
  }
  for(int i=0;i<5;i++){
    for(int j=1;j<=3;j++){
      int ent = etagood_data_b[i]->GetBinContent(j) + 1;
      std::cout << "entries " << ent << std::endl; 
      float rat = (float)1/(float)ent;
      std::cout << "rate " << rat << std::endl; 
      float var = sqrt((float)(rat*(1-rat)/(float)ent));
      std::cout << "variance " << var << std::endl; 
      float lim = rat + 1.96*var;
      std::cout << "limit " << lim << std::endl; 
      h2->SetBinContent(j,lim);
    }
    tit = "../plots/Eta_All_comp_in_pt_bin_"+stuf[i]+".png";
    diveta_b[i]->GetYaxis()->SetRangeUser(0.00001,1);
    h2->Draw();
    diveta_data_b[i]->Draw("E1 SAME");
    diveta_mc_b[i]->Draw("E1 SAME");
    diveta_mctz_b[i]->Draw("E1 SAME");
    diveta_b[i]->Draw("E1 SAME");
    TLegend *legend = new TLegend(0.5,0.6,0.9,0.9,"");
    legend->AddEntry(h2,"95 % C.L. Region Tag and Probe data", "f");
    legend->AddEntry(diveta_b[i],"Particle Gun", "f");
    legend->AddEntry(diveta_mctz_b[i],"MC Truth Z sample", "f");
    legend->AddEntry(diveta_mc_b[i],"MC Tag and Probe z sample", "f");
    legend->SetFillColor(0);
    legend->SetTextFont(42);
    legend->SetFillStyle(10);
    legend->SetBorderSize(10);
    legend->Draw("SAME");
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
  c1->SetLogy(0);
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
  c1->SaveAs("../plots/PtandEta_PG_3D.png");
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
  etaptrate_mc->GetZaxis()->SetTitle("Flip Rate Tag and Probe MCZ");
  etaptrate_mc->GetZaxis()->SetLabelFont(42);
  etaptrate_mc->GetZaxis()->SetTitleOffset(2);
  etaptrate_mc->GetZaxis()->SetTitleFont(42);
  etaptrate_mc->Draw("LEGO1 ");
  c1->SaveAs("../plots/PtandEta_TPMCZ_3D.gif");
  /*
  etaptrate_mc_ses->GetXaxis()->SetTitle("Pt (GeV)");
  etaptrate_mc_ses->GetXaxis()->SetLabelFont(42);
  etaptrate_mc_ses->GetXaxis()->SetTitleOffset(2);
  etaptrate_mc_ses->GetXaxis()->SetTitleFont(42);
  etaptrate_mc_ses->GetXaxis()->SetBinLabel(1,"5 < pt < 10");
  etaptrate_mc_ses->GetXaxis()->SetBinLabel(2,"10 < pt < 20");
  etaptrate_mc_ses->GetXaxis()->SetBinLabel(3,"20 < pt < 40");
  etaptrate_mc_ses->GetXaxis()->SetBinLabel(4,"40 < pt < 70");
  etaptrate_mc_ses->GetXaxis()->SetBinLabel(5,"pt > 70");
  etaptrate_mc_ses->GetXaxis()->SetLabelOffset(0.06);
  etaptrate_mc_ses->GetYaxis()->SetTitle("#eta");
  etaptrate_mc_ses->GetYaxis()->SetLabelFont(42);
  etaptrate_mc_ses->GetYaxis()->SetTitleOffset(2);
  etaptrate_mc_ses->GetYaxis()->SetTitleFont(42);
  etaptrate_mc_ses->GetYaxis()->SetBinLabel(1,"| #eta |  < 0.8");
  etaptrate_mc_ses->GetYaxis()->SetBinLabel(2,"0.8 < | #eta |  < 1.6");
  etaptrate_mc_ses->GetYaxis()->SetBinLabel(3,"1.6 < | #eta | < 2.4");
  etaptrate_mc_ses->GetZaxis()->SetTitle("Flip Rate Tag and Probe MCZ ses");
  etaptrate_mc_ses->GetZaxis()->SetLabelFont(42);
  etaptrate_mc_ses->GetZaxis()->SetTitleOffset(2);
  etaptrate_mc_ses->GetZaxis()->SetTitleFont(42);
  etaptrate_mc_ses->Draw("LEGO1 ");
  c1->SaveAs("../plots/PtandEta_TPMCZ_ses_3D.gif");

  etaptrate_mc_pses->GetXaxis()->SetTitle("Pt (GeV)");
  etaptrate_mc_pses->GetXaxis()->SetLabelFont(42);
  etaptrate_mc_pses->GetXaxis()->SetTitleOffset(2);
  etaptrate_mc_pses->GetXaxis()->SetTitleFont(42);
  etaptrate_mc_pses->GetXaxis()->SetBinLabel(1,"5 < pt < 10");
  etaptrate_mc_pses->GetXaxis()->SetBinLabel(2,"10 < pt < 20");
  etaptrate_mc_pses->GetXaxis()->SetBinLabel(3,"20 < pt < 40");
  etaptrate_mc_pses->GetXaxis()->SetBinLabel(4,"40 < pt < 70");
  etaptrate_mc_pses->GetXaxis()->SetBinLabel(5,"pt > 70");
  etaptrate_mc_pses->GetXaxis()->SetLabelOffset(0.06);
  etaptrate_mc_pses->GetYaxis()->SetTitle("#eta");
  etaptrate_mc_pses->GetYaxis()->SetLabelFont(42);
  etaptrate_mc_pses->GetYaxis()->SetTitleOffset(2);
  etaptrate_mc_pses->GetYaxis()->SetTitleFont(42);
  etaptrate_mc_pses->GetYaxis()->SetBinLabel(1,"| #eta |  < 0.8");
  etaptrate_mc_pses->GetYaxis()->SetBinLabel(2,"0.8 < | #eta |  < 1.6");
  etaptrate_mc_pses->GetYaxis()->SetBinLabel(3,"1.6 < | #eta | < 2.4");
  etaptrate_mc_pses->GetZaxis()->SetTitle("Flip Rate Tag and Probe MC Z probe ses");
  etaptrate_mc_pses->GetZaxis()->SetLabelFont(42);
  etaptrate_mc_pses->GetZaxis()->SetTitleOffset(2);
  etaptrate_mc_pses->GetZaxis()->SetTitleFont(42);
  etaptrate_mc_pses->Draw("LEGO1 ");
  c1->SaveAs("../plots/PtandEta_TPMCZ_pses_3D.gif");
  */
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
  /*
  etaptrate_data_pses->GetXaxis()->SetTitle("Pt (GeV)");
  etaptrate_data_pses->GetXaxis()->SetLabelFont(42);
  etaptrate_data_pses->GetXaxis()->SetTitleOffset(2);
  etaptrate_data_pses->GetXaxis()->SetTitleFont(42);
  etaptrate_data_pses->GetXaxis()->SetBinLabel(1,"5 < pt < 10");
  etaptrate_data_pses->GetXaxis()->SetBinLabel(2,"10 < pt < 20");
  etaptrate_data_pses->GetXaxis()->SetBinLabel(3,"20 < pt < 40");
  etaptrate_data_pses->GetXaxis()->SetBinLabel(4,"40 < pt < 70");
  etaptrate_data_pses->GetXaxis()->SetBinLabel(5,"pt > 70");
  etaptrate_data_pses->GetXaxis()->SetLabelOffset(0.06);
  etaptrate_data_pses->GetYaxis()->SetTitle("#eta");
  etaptrate_data_pses->GetYaxis()->SetLabelFont(42);
  etaptrate_data_pses->GetYaxis()->SetTitleOffset(2);
  etaptrate_data_pses->GetYaxis()->SetTitleFont(42);
  etaptrate_data_pses->GetYaxis()->SetBinLabel(1,"| #eta |  < 0.8");
  etaptrate_data_pses->GetYaxis()->SetBinLabel(2,"0.8 < | #eta |  < 1.6");
  etaptrate_data_pses->GetYaxis()->SetBinLabel(3,"1.6 < | #eta | < 2.4");
  etaptrate_data_pses->GetZaxis()->SetTitle("Flip Rate Tag and Probe Data Probe ses");
  etaptrate_data_pses->GetZaxis()->SetLabelFont(42);
  etaptrate_data_pses->GetZaxis()->SetTitleOffset(2);
  etaptrate_data_pses->GetZaxis()->SetTitleFont(42);
  etaptrate_data_pses->Draw("LEGO1 ");
  c1->SaveAs("../plots/PtandEta_TPDATA_PSES_3D.gif");

  etaptrate_data_ses->GetXaxis()->SetTitle("Pt (GeV)");
  etaptrate_data_ses->GetXaxis()->SetLabelFont(42);
  etaptrate_data_ses->GetXaxis()->SetTitleOffset(2);
  etaptrate_data_ses->GetXaxis()->SetTitleFont(42);
  etaptrate_data_ses->GetXaxis()->SetBinLabel(1,"5 < pt < 10");
  etaptrate_data_ses->GetXaxis()->SetBinLabel(2,"10 < pt < 20");
  etaptrate_data_ses->GetXaxis()->SetBinLabel(3,"20 < pt < 40");
  etaptrate_data_ses->GetXaxis()->SetBinLabel(4,"40 < pt < 70");
  etaptrate_data_ses->GetXaxis()->SetBinLabel(5,"pt > 70");
  etaptrate_data_ses->GetXaxis()->SetLabelOffset(0.06);
  etaptrate_data_ses->GetYaxis()->SetTitle("#eta");
  etaptrate_data_ses->GetYaxis()->SetLabelFont(42);
  etaptrate_data_ses->GetYaxis()->SetTitleOffset(2);
  etaptrate_data_ses->GetYaxis()->SetTitleFont(42);
  etaptrate_data_ses->GetYaxis()->SetBinLabel(1,"| #eta |  < 0.8");
  etaptrate_data_ses->GetYaxis()->SetBinLabel(2,"0.8 < | #eta |  < 1.6");
  etaptrate_data_ses->GetYaxis()->SetBinLabel(3,"1.6 < | #eta | < 2.4");
  etaptrate_data_ses->GetZaxis()->SetTitle("Flip Rate Tag and Probe Data Ses");
  etaptrate_data_ses->GetZaxis()->SetLabelFont(42);
  etaptrate_data_ses->GetZaxis()->SetTitleOffset(2);
  etaptrate_data_ses->GetZaxis()->SetTitleFont(42);
  etaptrate_data_ses->Draw("LEGO1 ");
  c1->SaveAs("../plots/PtandEta_TPDATA_SES_3D.gif");
  */
}
