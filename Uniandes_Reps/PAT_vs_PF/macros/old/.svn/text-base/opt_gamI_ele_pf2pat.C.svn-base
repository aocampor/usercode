{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Dec 15 15:09:42 2009) by ROOT version5.25/02
   TCanvas *c1 = new TCanvas("c1", "c1",1600,321,700,502);
   c1->Range(-4.78022,-6.465518,33.46154,34.22414);
   c1->SetFillColor(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.125);
   c1->SetBottomMargin(0.1588983);
   
   TH1F *optEffEl_Gam_ = new TH1F("optEffEl_Gam_","particle flow electrons",10,0,30);
   optEffEl_Gam_->SetBinContent(1,1.5);
   optEffEl_Gam_->SetBinContent(2,1.5);
   optEffEl_Gam_->SetBinContent(3,1.5);
   optEffEl_Gam_->SetBinContent(4,2);
   optEffEl_Gam_->SetBinContent(5,2);
   optEffEl_Gam_->SetBinContent(6,2.5);
   optEffEl_Gam_->SetBinContent(7,2.5);
   optEffEl_Gam_->SetBinContent(8,2.5);
   optEffEl_Gam_->SetBinContent(9,2.5);
   optEffEl_Gam_->SetBinContent(10,2.5);
   optEffEl_Gam_->SetBinError(1,0.5);
   optEffEl_Gam_->SetBinError(2,0.5);
   optEffEl_Gam_->SetBinError(3,0.5);
   optEffEl_Gam_->SetBinError(4,0.5);
   optEffEl_Gam_->SetBinError(5,0.5);
   optEffEl_Gam_->SetBinError(6,0.5);
   optEffEl_Gam_->SetBinError(7,0.5);
   optEffEl_Gam_->SetBinError(8,0.5);
   optEffEl_Gam_->SetBinError(9,0.5);
   optEffEl_Gam_->SetBinError(10,0.5);
   optEffEl_Gam_->SetMinimum(0);
   optEffEl_Gam_->SetMaximum(30);
   optEffEl_Gam_->SetEntries(10);
   
   TF1 *pol1 = new TF1("pol1","pol1",0,30);
   pol1->SetFillColor(19);
   pol1->SetFillStyle(0);
   pol1->SetLineColor(2);
   pol1->SetLineWidth(1);
   pol1->SetChisquare(1.187879);
   pol1->SetNDF(8);
   pol1->SetParameter(0,1.40303);
   pol1->SetParError(0,0.3174233);
   pol1->SetParLimits(0,0,0);
   pol1->SetParameter(1,0.04646465);
   pol1->SetParError(1,0.0183494);
   pol1->SetParLimits(1,0,0);
   optEffEl_Gam_->GetListOfFunctions()->Add(pol1);
   
   TPaveStats *ptstats = new TPaveStats(0.5718391,0.6144068,0.8275862,0.8559322,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("Entries = 10     ");
   text = ptstats->AddText("#chi^{2} / ndf = 1.188 / 8");
   text = ptstats->AddText("p0       = 1.403 #pm 0.317 ");
   text = ptstats->AddText("p1       = 0.04646 #pm 0.01835 ");
   ptstats->SetOptStat(10);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   optEffEl_Gam_->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(optEffEl_Gam_->GetListOfFunctions());
   optEffEl_Gam_->SetMarkerStyle(20);
   optEffEl_Gam_->GetXaxis()->SetTitle("p_{T} (GeV)");
   optEffEl_Gam_->GetXaxis()->SetLabelFont(42);
   optEffEl_Gam_->GetXaxis()->SetTitleSize(0.05);
   optEffEl_Gam_->GetXaxis()->SetTitleFont(42);
   optEffEl_Gam_->GetYaxis()->SetTitle("gamma Isolation");
   optEffEl_Gam_->GetYaxis()->SetLabelFont(42);
   optEffEl_Gam_->GetYaxis()->SetTitleSize(0.05);
   optEffEl_Gam_->GetYaxis()->SetTitleFont(42);
   optEffEl_Gam_->Draw("");
   
   TPaveText *pt = new TPaveText(0.2298851,0.9173729,0.5833333,0.9661017,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetTextFont(42);
   text = pt->AddText("particle flow electrons");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
