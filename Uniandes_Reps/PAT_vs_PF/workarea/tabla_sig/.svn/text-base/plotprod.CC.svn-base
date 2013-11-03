{
  TCanvas *c1 = new TCanvas();
  gStyle->SetOptStat(2210);
  gStyle->SetOptFit(2210);
  gStyle->SetOptTitle(0);
  gStyle->SetFillColor(0);
  gStyle->SetStatBorderSize(0);
  gStyle->SetStatFont(42);
  c1->SetTickx(1);
  c1->SetTicky(1);
  TFile *f1 = TFile::Open("Significanceplots.root");

  TH1F *sigdifleptons = (TH1F*)f1->FindObjectAny("SignificanceDifferenceSRLvsPFL");
  sigdifleptons->GetXaxis()->SetTitle("Significance differences fixing jets and MET and changing leptons SR-PF");
  sigdifleptons->GetXaxis()->SetLabelFont(42);
  sigdifleptons->GetXaxis()->SetTitleFont(42);
  sigdifleptons->GetYaxis()->SetTitle("Number of entries");
  sigdifleptons->GetYaxis()->SetLabelFont(42);
  sigdifleptons->GetYaxis()->SetTitleFont(42);
  sigdifleptons->Draw();
  c1->SaveAs("Significance_differences_changing_leptons.gif");

  sigdifleptons = (TH1F*)f1->FindObjectAny("SignificanceDifferenceSRLvsPFLPFframework");
  sigdifleptons->GetXaxis()->SetTitle("Significance differences fixing PF jets and MET and changing leptons SR-PF");
  sigdifleptons->GetXaxis()->SetLabelFont(42);
  sigdifleptons->GetXaxis()->SetTitleFont(42);
  sigdifleptons->GetYaxis()->SetTitle("Number of entries");
  sigdifleptons->GetYaxis()->SetLabelFont(42);
  sigdifleptons->GetYaxis()->SetTitleFont(42);
  sigdifleptons->Draw();
  c1->SaveAs("Significance_differences_changing_leptons_inPF.gif");

  sigdifleptons = (TH1F*)f1->FindObjectAny("SignificanceDifferenceSRLvsPFLSRframework");
  sigdifleptons->GetXaxis()->SetTitle("Significance differences fixing SR jets and MET and changing leptons SR-PF");
  sigdifleptons->GetXaxis()->SetLabelFont(42);
  sigdifleptons->GetXaxis()->SetTitleFont(42);
  sigdifleptons->GetYaxis()->SetTitle("Number of entries");
  sigdifleptons->GetYaxis()->SetLabelFont(42);
  sigdifleptons->GetYaxis()->SetTitleFont(42);
  sigdifleptons->Draw();
  c1->SaveAs("Significance_differences_changing_leptons_inSR.gif");

  sigdifleptons = (TH1F*)f1->FindObjectAny("SignificanceDifferenceframeworks");
  sigdifleptons->GetXaxis()->SetTitle("Significance differences between SR-PF");
  sigdifleptons->GetXaxis()->SetLabelFont(42);
  sigdifleptons->GetXaxis()->SetTitleFont(42);
  sigdifleptons->GetYaxis()->SetTitle("Number of entries");
  sigdifleptons->GetYaxis()->SetLabelFont(42);
  sigdifleptons->GetYaxis()->SetTitleFont(42);
  sigdifleptons->Draw();
  c1->SaveAs("Significance_differences_between_SRandPF.gif");

  sigdifleptons = (TH1F*)f1->FindObjectAny("SignificanceDifferencesoftleptons");
  sigdifleptons->GetXaxis()->SetTitle("Significance differences between SR-PF soft leptons");
  sigdifleptons->GetXaxis()->SetLabelFont(42);
  sigdifleptons->GetXaxis()->SetTitleFont(42);
  sigdifleptons->GetYaxis()->SetTitle("Number of entries");
  sigdifleptons->GetYaxis()->SetLabelFont(42);
  sigdifleptons->GetYaxis()->SetTitleFont(42);
  sigdifleptons->Draw();
  c1->SaveAs("Significance_differences_between_SRandPF_softleptons.gif");
}
