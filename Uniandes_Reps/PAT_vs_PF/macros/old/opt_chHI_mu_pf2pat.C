{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Dec 15 15:51:05 2009) by ROOT version5.25/02
   TCanvas *c1 = new TCanvas("c1", "c1",1519,365,700,502);
   c1->Range(-5.568182,-5.614525,33.97727,33.93855);
   c1->SetFillColor(0);
   c1->SetBorderSize(2);
   c1->SetLeftMargin(0.1408046);
   c1->SetBottomMargin(0.1419491);
   
   TH1F *optEffMu_ChHad_ = new TH1F("optEffMu_ChHad_","particle flow muons ",10,0,30);
   optEffMu_ChHad_->SetBinContent(1,2.5);
   optEffMu_ChHad_->SetBinContent(2,3);
   optEffMu_ChHad_->SetBinContent(3,3);
   optEffMu_ChHad_->SetBinContent(4,3);
   optEffMu_ChHad_->SetBinContent(5,3);
   optEffMu_ChHad_->SetBinContent(6,2.5);
   optEffMu_ChHad_->SetBinContent(7,3);
   optEffMu_ChHad_->SetBinContent(8,2.5);
   optEffMu_ChHad_->SetBinContent(9,2.5);
   optEffMu_ChHad_->SetBinContent(10,2.5);
   optEffMu_ChHad_->SetBinError(1,0.5);
   optEffMu_ChHad_->SetBinError(2,0.5);
   optEffMu_ChHad_->SetBinError(3,0.5);
   optEffMu_ChHad_->SetBinError(4,0.5);
   optEffMu_ChHad_->SetBinError(5,0.5);
   optEffMu_ChHad_->SetBinError(6,0.5);
   optEffMu_ChHad_->SetBinError(7,0.5);
   optEffMu_ChHad_->SetBinError(8,0.5);
   optEffMu_ChHad_->SetBinError(9,0.5);
   optEffMu_ChHad_->SetBinError(10,0.5);
   optEffMu_ChHad_->SetMinimum(0);
   optEffMu_ChHad_->SetMaximum(30);
   optEffMu_ChHad_->SetEntries(10);
   
   TF1 *pol1 = new TF1("pol1","pol1",0,30);
   pol1->SetFillColor(19);
   pol1->SetFillStyle(0);
   pol1->SetLineColor(2);
   pol1->SetLineWidth(1);
   pol1->SetChisquare(1.987879);
   pol1->SetNDF(8);
   pol1->SetParameter(0,2.94697);
   pol1->SetParError(0,0.3174233);
   pol1->SetParLimits(0,0,0);
   pol1->SetParameter(1,-0.01313131);
   pol1->SetParError(1,0.0183494);
   pol1->SetParLimits(1,0,0);
   optEffMu_ChHad_->GetListOfFunctions()->Add(pol1);
   
   TPaveStats *ptstats = new TPaveStats(0.6020115,0.6716102,0.8635057,0.8834746,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetTextAlign(12);
   TText *text = ptstats->AddText("Entries = 10     ");
   text = ptstats->AddText("#chi^{2} / ndf = 1.988 / 8");
   text = ptstats->AddText("p0       = 2.947 #pm 0.317 ");
   text = ptstats->AddText("p1       = -0.01313 #pm 0.01835 ");
   ptstats->SetOptStat(10);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   optEffMu_ChHad_->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(optEffMu_ChHad_->GetListOfFunctions());
   optEffMu_ChHad_->GetXaxis()->SetTitle("p_{T} (GeV)");
   optEffMu_ChHad_->GetXaxis()->SetLabelFont(42);
   optEffMu_ChHad_->GetXaxis()->SetTitleSize(0.05);
   optEffMu_ChHad_->GetXaxis()->SetTitleFont(42);
   optEffMu_ChHad_->GetYaxis()->SetTitle("charged Hadron Isolation");
   optEffMu_ChHad_->GetYaxis()->SetLabelFont(42);
   optEffMu_ChHad_->GetYaxis()->SetTitleSize(0.05);
   optEffMu_ChHad_->GetYaxis()->SetTitleFont(42);
   optEffMu_ChHad_->Draw("");
   
   TPaveText *pt = new TPaveText(0.3074713,0.9152542,0.6307471,0.970339,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetTextFont(42);
   text = pt->AddText("particle flow muons ");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
