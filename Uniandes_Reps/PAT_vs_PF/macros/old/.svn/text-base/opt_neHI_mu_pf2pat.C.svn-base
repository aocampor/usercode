{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Dec 15 16:07:04 2009) by ROOT version5.25/02
   TCanvas *c1 = new TCanvas("c1", "c1",1580,342,700,502);
   c1->Range(-5.568182,-1.509431,33.97727,6.894717);
   c1->SetFillColor(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.1408046);
   c1->SetBottomMargin(0.1419491);
   
   TH1F *optEffMu_NeHad_ = new TH1F("optEffMu_NeHad_","particle flow muons ",10,0,30);
   optEffMu_NeHad_->SetBinContent(1,0.5);
   optEffMu_NeHad_->SetBinContent(2,0.5);
   optEffMu_NeHad_->SetBinContent(3,0.5);
   optEffMu_NeHad_->SetBinContent(4,0.5);
   optEffMu_NeHad_->SetBinContent(5,0.5);
   optEffMu_NeHad_->SetBinContent(6,0.5);
   optEffMu_NeHad_->SetBinContent(7,0.5);
   optEffMu_NeHad_->SetBinContent(8,0.5);
   optEffMu_NeHad_->SetBinContent(9,0.5);
   optEffMu_NeHad_->SetBinContent(10,0.5);
   optEffMu_NeHad_->SetBinError(1,0.5);
   optEffMu_NeHad_->SetBinError(2,0.5);
   optEffMu_NeHad_->SetBinError(3,0.5);
   optEffMu_NeHad_->SetBinError(4,0.5);
   optEffMu_NeHad_->SetBinError(5,0.5);
   optEffMu_NeHad_->SetBinError(6,0.5);
   optEffMu_NeHad_->SetBinError(7,0.5);
   optEffMu_NeHad_->SetBinError(8,0.5);
   optEffMu_NeHad_->SetBinError(9,0.5);
   optEffMu_NeHad_->SetBinError(10,0.5);
   optEffMu_NeHad_->SetMinimum(-0.3164696);
   optEffMu_NeHad_->SetMaximum(6.057863);
   optEffMu_NeHad_->SetEntries(10);
   
   TF1 *pol1 = new TF1("pol1","pol1",0,30);
   pol1->SetFillColor(19);
   pol1->SetFillStyle(0);
   pol1->SetLineColor(2);
   pol1->SetLineWidth(1);
   pol1->SetChisquare(9.737502e-31);
   pol1->SetNDF(8);
   pol1->SetParameter(0,0.5);
   pol1->SetParError(0,0.3174233);
   pol1->SetParLimits(0,0,0);
   pol1->SetParameter(1,1.91392e-17);
   pol1->SetParError(1,0.0183494);
   pol1->SetParLimits(1,0,0);
   optEffMu_NeHad_->GetListOfFunctions()->Add(pol1);
   
   TPaveStats *ptstats = new TPaveStats(0.6034483,0.5995763,0.8893678,0.8601695,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("Entries = 10     ");
   text = ptstats->AddText("#chi^{2} / ndf = 9.738e-31 / 8");
   text = ptstats->AddText("p0       =   0.5 #pm 0.3 ");
   text = ptstats->AddText("p1       = 1.914e-17 #pm 1.835e-02 ");
   ptstats->SetOptStat(10);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   optEffMu_NeHad_->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(optEffMu_NeHad_->GetListOfFunctions());
   optEffMu_NeHad_->GetXaxis()->SetTitle("p_{T} (GeV)");
   optEffMu_NeHad_->GetXaxis()->SetLabelFont(42);
   optEffMu_NeHad_->GetXaxis()->SetTitleSize(0.05);
   optEffMu_NeHad_->GetXaxis()->SetTitleFont(42);
   optEffMu_NeHad_->GetYaxis()->SetTitle("neutral hadron Isolation");
   optEffMu_NeHad_->GetYaxis()->SetTitleSize(0.05);
   optEffMu_NeHad_->GetYaxis()->SetTitleFont(42);
   optEffMu_NeHad_->Draw("");
   
   TPaveText *pt = new TPaveText(0.2227011,0.9194915,0.545977,0.9745763,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetTextFont(42);
   text = pt->AddText("particle flow muons ");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
