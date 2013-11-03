{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Dec 15 15:03:47 2009) by ROOT version5.25/02
   TCanvas *c1 = new TCanvas("c1", "c1",1600,321,700,502);
   c1->Range(-4.78022,-6.465518,33.46154,34.22414);
   c1->SetFillColor(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.125);
   c1->SetBottomMargin(0.1588983);
   
   TH1F *optEffEl_ChHad_ = new TH1F("optEffEl_ChHad_","Particle Flow electrons",10,0,30);
   optEffEl_ChHad_->SetBinContent(1,3.5);
   optEffEl_ChHad_->SetBinContent(2,2);
   optEffEl_ChHad_->SetBinContent(3,2.5);
   optEffEl_ChHad_->SetBinContent(4,2.5);
   optEffEl_ChHad_->SetBinContent(5,2.5);
   optEffEl_ChHad_->SetBinContent(6,2.5);
   optEffEl_ChHad_->SetBinContent(7,2.5);
   optEffEl_ChHad_->SetBinContent(8,2.5);
   optEffEl_ChHad_->SetBinContent(9,2.5);
   optEffEl_ChHad_->SetBinContent(10,2.5);
   optEffEl_ChHad_->SetBinError(1,0.5);
   optEffEl_ChHad_->SetBinError(2,0.5);
   optEffEl_ChHad_->SetBinError(3,0.5);
   optEffEl_ChHad_->SetBinError(4,0.5);
   optEffEl_ChHad_->SetBinError(5,0.5);
   optEffEl_ChHad_->SetBinError(6,0.5);
   optEffEl_ChHad_->SetBinError(7,0.5);
   optEffEl_ChHad_->SetBinError(8,0.5);
   optEffEl_ChHad_->SetBinError(9,0.5);
   optEffEl_ChHad_->SetBinError(10,0.5);
   optEffEl_ChHad_->SetMinimum(0);
   optEffEl_ChHad_->SetMaximum(30);
   optEffEl_ChHad_->SetEntries(10);
   
   TF1 *pol1 = new TF1("pol1","pol1",0,30);
   pol1->SetFillColor(19);
   pol1->SetFillStyle(0);
   pol1->SetLineColor(2);
   pol1->SetLineWidth(1);
   pol1->SetChisquare(4.533333);
   pol1->SetNDF(8);
   pol1->SetParameter(0,2.716667);
   pol1->SetParError(0,0.3174233);
   pol1->SetParLimits(0,0,0);
   pol1->SetParameter(1,-0.01111111);
   pol1->SetParError(1,0.0183494);
   pol1->SetParLimits(1,0,0);
   optEffEl_ChHad_->GetListOfFunctions()->Add(pol1);
   
   TPaveStats *ptstats = new TPaveStats(0.6235632,0.6059322,0.8922414,0.8601695,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(2);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("Entries = 10     ");
   text = ptstats->AddText("#chi^{2} / ndf = 4.533 / 8");
   text = ptstats->AddText("p0       = 2.717 #pm 0.317 ");
   text = ptstats->AddText("p1       = -0.01111 #pm 0.01835 ");
   ptstats->SetOptStat(10);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   optEffEl_ChHad_->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(optEffEl_ChHad_->GetListOfFunctions());
   optEffEl_ChHad_->SetLineWidth(2);
   optEffEl_ChHad_->GetXaxis()->SetTitle("p_{T} (GeV)");
   optEffEl_ChHad_->GetXaxis()->SetLabelFont(42);
   optEffEl_ChHad_->GetXaxis()->SetTitleSize(0.05);
   optEffEl_ChHad_->GetXaxis()->SetTitleFont(42);
   optEffEl_ChHad_->GetYaxis()->SetTitle("charged Hadron");
   optEffEl_ChHad_->GetYaxis()->SetLabelFont(42);
   optEffEl_ChHad_->GetYaxis()->SetTitleSize(0.05);
   optEffEl_ChHad_->GetYaxis()->SetTitleFont(42);
   optEffEl_ChHad_->Draw("");
   
   TPaveText *pt = new TPaveText(0.2528736,0.9131356,0.6163793,0.9618644,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetTextFont(42);
   text = pt->AddText("Particle Flow electrons");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
