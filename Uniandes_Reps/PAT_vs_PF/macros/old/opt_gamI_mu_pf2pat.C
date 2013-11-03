{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Dec 15 15:58:01 2009) by ROOT version5.25/02
   TCanvas *c1 = new TCanvas("c1", "c1",1519,365,700,502);
   c1->Range(-5.568182,-5.614525,33.97727,33.93855);
   c1->SetFillColor(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.1408046);
   c1->SetBottomMargin(0.1419491);
   
   TH1F *optEffMu_Gam_ = new TH1F("optEffMu_Gam_","particle flow muons ",10,0,30);
   optEffMu_Gam_->SetBinContent(1,1.5);
   optEffMu_Gam_->SetBinContent(2,2);
   optEffMu_Gam_->SetBinContent(3,2);
   optEffMu_Gam_->SetBinContent(4,2.5);
   optEffMu_Gam_->SetBinContent(5,2.5);
   optEffMu_Gam_->SetBinContent(6,2.5);
   optEffMu_Gam_->SetBinContent(7,2.5);
   optEffMu_Gam_->SetBinContent(8,2.5);
   optEffMu_Gam_->SetBinContent(9,2.5);
   optEffMu_Gam_->SetBinContent(10,2.5);
   optEffMu_Gam_->SetBinError(1,0.5);
   optEffMu_Gam_->SetBinError(2,0.5);
   optEffMu_Gam_->SetBinError(3,0.5);
   optEffMu_Gam_->SetBinError(4,0.5);
   optEffMu_Gam_->SetBinError(5,0.5);
   optEffMu_Gam_->SetBinError(6,0.5);
   optEffMu_Gam_->SetBinError(7,0.5);
   optEffMu_Gam_->SetBinError(8,0.5);
   optEffMu_Gam_->SetBinError(9,0.5);
   optEffMu_Gam_->SetBinError(10,0.5);
   optEffMu_Gam_->SetMinimum(0);
   optEffMu_Gam_->SetMaximum(30);
   optEffMu_Gam_->SetEntries(10);
   
   TF1 *pol1 = new TF1("pol1","pol1",0,30);
   pol1->SetFillColor(19);
   pol1->SetFillStyle(0);
   pol1->SetLineColor(2);
   pol1->SetLineWidth(1);
   pol1->SetChisquare(1.672727);
   pol1->SetNDF(8);
   pol1->SetParameter(0,1.845455);
   pol1->SetParError(0,0.3174233);
   pol1->SetParLimits(0,0,0);
   pol1->SetParameter(1,0.03030303);
   pol1->SetParError(1,0.0183494);
   pol1->SetParLimits(1,0,0);
   optEffMu_Gam_->GetListOfFunctions()->Add(pol1);
   
   TPaveStats *ptstats = new TPaveStats(0.5689655,0.6016949,0.8591954,0.8665254,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("Entries = 10     ");
   text = ptstats->AddText("#chi^{2} / ndf = 1.673 / 8");
   text = ptstats->AddText("p0       = 1.845 #pm 0.317 ");
   text = ptstats->AddText("p1       = 0.0303 #pm 0.0183 ");
   ptstats->SetOptStat(10);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   optEffMu_Gam_->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(optEffMu_Gam_->GetListOfFunctions());
   optEffMu_Gam_->GetXaxis()->SetTitle("p_{T} (GeV)");
   optEffMu_Gam_->GetXaxis()->SetLabelFont(42);
   optEffMu_Gam_->GetXaxis()->SetTitleFont(42);
   optEffMu_Gam_->GetYaxis()->SetTitle("gamma Isolation");
   optEffMu_Gam_->GetYaxis()->SetLabelFont(42);
   optEffMu_Gam_->GetYaxis()->SetTitleSize(0.05);
   optEffMu_Gam_->GetYaxis()->SetTitleFont(42);
   optEffMu_Gam_->Draw("");
   
   TPaveText *pt = new TPaveText(0.1824713,0.9300847,0.5071839,0.9851695,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetTextFont(42);
   text = pt->AddText("particle flow muons ");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
