{
//=========Macro generated from canvas: c1/c1
//=========  (Sat Mar  6 07:06:15 2010) by ROOT version5.26/00
   TCanvas *c1 = new TCanvas("c1", "c1",1301,377,921,540);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c1->Range(-5.617284,-3.75,50.98766,33.75);
   c1->SetBorderSize(2);
   c1->SetRightMargin(0.3707743);
   c1->SetFrameFillColor(0);
   
   TH1F *optPureHFpfMu_Gam_ = new TH1F("optPureHFpfMu_Gam_","optPureHFpfMu_Gam_",10,0,30);
   optPureHFpfMu_Gam_->SetBinContent(1,0.5);
   optPureHFpfMu_Gam_->SetBinContent(2,0.5);
   optPureHFpfMu_Gam_->SetBinContent(3,0.5);
   optPureHFpfMu_Gam_->SetBinContent(4,1);
   optPureHFpfMu_Gam_->SetBinContent(5,1.5);
   optPureHFpfMu_Gam_->SetBinContent(6,2);
   optPureHFpfMu_Gam_->SetBinContent(7,2.5);
   optPureHFpfMu_Gam_->SetBinContent(8,3);
   optPureHFpfMu_Gam_->SetBinContent(9,3);
   optPureHFpfMu_Gam_->SetBinContent(10,3.5);
   optPureHFpfMu_Gam_->SetBinError(1,0.5);
   optPureHFpfMu_Gam_->SetBinError(2,0.5);
   optPureHFpfMu_Gam_->SetBinError(3,0.5);
   optPureHFpfMu_Gam_->SetBinError(4,0.5);
   optPureHFpfMu_Gam_->SetBinError(5,0.5);
   optPureHFpfMu_Gam_->SetBinError(6,0.5);
   optPureHFpfMu_Gam_->SetBinError(7,0.5);
   optPureHFpfMu_Gam_->SetBinError(8,0.5);
   optPureHFpfMu_Gam_->SetBinError(9,0.5);
   optPureHFpfMu_Gam_->SetBinError(10,0.5);
   optPureHFpfMu_Gam_->SetMinimum(0);
   optPureHFpfMu_Gam_->SetMaximum(30);
   optPureHFpfMu_Gam_->SetEntries(10);
   
   TF1 *pol1 = new TF1("pol1","pol1",0,30);
   pol1->SetFillColor(19);
   pol1->SetFillStyle(0);
   pol1->SetLineWidth(3);
   pol1->SetChisquare(1.806061);
   pol1->SetNDF(8);
   pol1->SetParameter(0,-0.07878788);
   pol1->SetParError(0,0.3174233);
   pol1->SetParLimits(0,0,0);
   pol1->SetParameter(1,0.1252525);
   pol1->SetParError(1,0.0183494);
   pol1->SetParLimits(1,0,0);
   optPureHFpfMu_Gam_->GetListOfFunctions()->Add(pol1);
   
   TPaveStats *ptstats = new TPaveStats(0.64,0.51,1,0.75,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(19);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("#chi^{2} / ndf = 1.806 / 8");
   text = ptstats->AddText("Prob  = 0.9864");
   text = ptstats->AddText("p0       = -0.07879 #pm 0.31742 ");
   text = ptstats->AddText("p1       = 0.1253 #pm 0.0183 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(2210);
   ptstats->Draw();
   optPureHFpfMu_Gam_->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(optPureHFpfMu_Gam_->GetListOfFunctions());
   optPureHFpfMu_Gam_->GetXaxis()->SetTitle("Particle Flow Muon P_{T}(GeV)");
   optPureHFpfMu_Gam_->GetXaxis()->SetLabelFont(42);
   optPureHFpfMu_Gam_->GetXaxis()->SetTitleFont(42);
   optPureHFpfMu_Gam_->GetYaxis()->SetTitle("Gamma Isolation for PureHF cut (rej HF > 0.9)");
   optPureHFpfMu_Gam_->GetYaxis()->SetLabelFont(42);
   optPureHFpfMu_Gam_->GetYaxis()->SetTitleFont(42);
   optPureHFpfMu_Gam_->Draw("");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
