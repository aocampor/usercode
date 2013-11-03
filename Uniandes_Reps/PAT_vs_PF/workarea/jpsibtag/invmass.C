{
  TFile *f1 = TFile::Open("../../root_files/nutples/jpsi/jetmet_trigger.root");
  TCanvas *c1 = new TCanvas("c1", "c1",1568,273,700,502);
  gStyle->SetOptStat(1110);
  gStyle->SetOptTitle(1);
  gStyle->SetTitleFont(42);
  gStyle->SetFillColor(0);
  c1->Range(1.787199,-0.2844563,4.23632,16.27936);
  c1->SetFillColor(0);
  c1->SetBorderSize(0);
  c1->SetTickx(1);
  c1->SetTicky(1);
  c1->SetFrameBorderMode(0);

  TH1F *pfElEli = (TH1F*)f1->FindObjectAny("pfElEl");
  pfElEli->GetXaxis()->SetTitle("e-e InvMass (GeV)");
  pfElEli->GetXaxis()->SetRange(30,57);
  pfElEli->GetXaxis()->SetLabelFont(42);
  pfElEli->GetXaxis()->SetTitleFont(42);
  pfElEli->GetYaxis()->SetTitle("N. Events");
  pfElEli->GetYaxis()->SetLabelFont(42);
  pfElEli->GetYaxis()->SetTitleFont(42);
  pfElEli->Draw("");
  c1->SaveAs("InvMassEl.gif");
  TCanvas *c1 = new TCanvas("c1", "c1",1568,273,700,502);
  gStyle->SetOptStat(1110);
  gStyle->SetOptTitle(1);
  gStyle->SetTitleFont(42);
  gStyle->SetFillColor(0);
  c1->Range(1.787199,-0.2844563,4.23632,16.27936);
  c1->SetFillColor(0);
  c1->SetBorderSize(0);
  c1->SetTickx(1);
  c1->SetTicky(1);
  c1->SetFrameBorderMode(0);
  TH1F *pfMumui = (TH1F*)f1->FindObjectAny("MuMu");
  pfMumui->GetXaxis()->SetTitle("#mu-#mu InvMass (GeV)");
  pfMumui->GetXaxis()->SetRange(30,57);
  pfMumui->GetXaxis()->SetLabelFont(42);
  pfMumui->GetXaxis()->SetTitleFont(42);
  pfMumui->GetYaxis()->SetTitle("N. Events");
  pfMumui->GetYaxis()->SetLabelFont(42);
  pfMumui->GetYaxis()->SetTitleFont(42);
  pfMumui->Draw("");
  c1->SaveAs("InvMassmu.gif");

}
