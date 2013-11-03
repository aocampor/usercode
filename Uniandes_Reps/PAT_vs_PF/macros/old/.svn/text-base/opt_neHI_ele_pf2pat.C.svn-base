{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Dec 15 15:24:03 2009) by ROOT version5.25/02
   TCanvas *c1 = new TCanvas("c1", "c1",1600,321,700,502);
   c1->Range(-4.78022,-6.465518,33.46154,34.22414);
   c1->SetFillColor(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.125);
   c1->SetBottomMargin(0.1588983);
   
   TH1F *optEffEl_tot_ = new TH1F("optEffEl_tot_","particle flow electrons",10,0,30);
   optEffEl_tot_->SetBinContent(1,4);
   optEffEl_tot_->SetBinContent(2,4);
   optEffEl_tot_->SetBinContent(3,3.5);
   optEffEl_tot_->SetBinContent(4,4);
   optEffEl_tot_->SetBinContent(5,4);
   optEffEl_tot_->SetBinContent(6,4.5);
   optEffEl_tot_->SetBinContent(7,4.5);
   optEffEl_tot_->SetBinContent(8,4.5);
   optEffEl_tot_->SetBinContent(9,4.5);
   optEffEl_tot_->SetBinContent(10,4);
   optEffEl_tot_->SetBinError(1,0.5);
   optEffEl_tot_->SetBinError(2,0.5);
   optEffEl_tot_->SetBinError(3,0.5);
   optEffEl_tot_->SetBinError(4,0.5);
   optEffEl_tot_->SetBinError(5,0.5);
   optEffEl_tot_->SetBinError(6,0.5);
   optEffEl_tot_->SetBinError(7,0.5);
   optEffEl_tot_->SetBinError(8,0.5);
   optEffEl_tot_->SetBinError(9,0.5);
   optEffEl_tot_->SetBinError(10,0.5);
   optEffEl_tot_->SetMinimum(0);
   optEffEl_tot_->SetMaximum(30);
   optEffEl_tot_->SetEntries(10);
   
   TF1 *pol1 = new TF1("pol1","pol1",0,30);
   pol1->SetFillColor(19);
   pol1->SetFillStyle(0);
   pol1->SetLineColor(2);
   pol1->SetLineWidth(1);
   pol1->SetChisquare(2.763636);
   pol1->SetNDF(8);
   pol1->SetParameter(0,3.831818);
   pol1->SetParError(0,0.3174233);
   pol1->SetParLimits(0,0,0);
   pol1->SetParameter(1,0.02121212);
   pol1->SetParError(1,0.0183494);
   pol1->SetParLimits(1,0,0);
   optEffEl_tot_->GetListOfFunctions()->Add(pol1);
   
   TPaveStats *ptstats = new TPaveStats(0.5675287,0.6228814,0.8362069,0.8495763,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("Entries = 10     ");
   text = ptstats->AddText("#chi^{2} / ndf = 2.764 / 8");
   text = ptstats->AddText("p0       = 3.832 #pm 0.317 ");
   text = ptstats->AddText("p1       = 0.02121 #pm 0.01835 ");
   ptstats->SetOptStat(10);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   optEffEl_tot_->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(optEffEl_tot_->GetListOfFunctions());
   optEffEl_tot_->GetXaxis()->SetTitle("p_{T} (GeV)");
   optEffEl_tot_->GetXaxis()->SetLabelFont(42);
   optEffEl_tot_->GetXaxis()->SetTitleSize(0.05);
   optEffEl_tot_->GetXaxis()->SetTitleFont(42);
   optEffEl_tot_->GetYaxis()->SetTitle("Combined Isolation");
   optEffEl_tot_->GetYaxis()->SetLabelFont(42);
   optEffEl_tot_->GetYaxis()->SetTitleSize(0.05);
   optEffEl_tot_->GetYaxis()->SetTitleFont(42);
   optEffEl_tot_->Draw("");
   
   TPaveText *pt = new TPaveText(0.2241379,0.9173729,0.5775862,0.9661017,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetTextFont(42);
   text = pt->AddText("particle flow electrons");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
