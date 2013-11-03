{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Dec 16 17:50:28 2009) by ROOT version5.25/02
   TCanvas *c1 = new TCanvas("c1", "c1",1613,442,435,449);
   c1->Range(-5.723077,-6.11465,34.06154,33.9172);
   c1->SetFillColor(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.1438515);
   c1->SetBottomMargin(0.1527446);
   c1->SetFrameBorderMode(0);
   
   TH1F *optpureHFel = new TH1F("optpureHFel","particle flow electrons",10,0,30);
   optpureHFel->SetBinContent(1,0.5);
   optpureHFel->SetBinContent(2,0.5);
   optpureHFel->SetBinContent(3,1.5);
   optpureHFel->SetBinContent(4,3);
   optpureHFel->SetBinContent(5,4);
   optpureHFel->SetBinContent(6,4.5);
   optpureHFel->SetBinContent(7,5);
   optpureHFel->SetBinContent(8,6.5);
   optpureHFel->SetBinContent(9,6.5);
   optpureHFel->SetBinContent(10,6.5);
   optpureHFel->SetBinError(1,0.5);
   optpureHFel->SetBinError(2,0.5);
   optpureHFel->SetBinError(3,0.5);
   optpureHFel->SetBinError(4,0.5);
   optpureHFel->SetBinError(5,0.5);
   optpureHFel->SetBinError(6,0.5);
   optpureHFel->SetBinError(7,0.5);
   optpureHFel->SetBinError(8,0.5);
   optpureHFel->SetBinError(9,0.5);
   optpureHFel->SetBinError(10,0.5);
   optpureHFel->SetMinimum(0);
   optpureHFel->SetMaximum(30);
   optpureHFel->SetEntries(10);
   
   TF1 *pol1 = new TF1("pol1","pol1",0,30);
   pol1->SetFillColor(19);
   pol1->SetFillStyle(0);
   pol1->SetLineColor(2);
   pol1->SetLineWidth(2);
   pol1->SetChisquare(9.054545);
   pol1->SetNDF(8);
   pol1->SetParameter(0,-0.01363636);
   pol1->SetParError(0,0.3174233);
   pol1->SetParLimits(0,0,0);
   pol1->SetParameter(1,0.2575758);
   pol1->SetParError(1,0.0183494);
   pol1->SetParLimits(1,0,0);
   optpureHFel->GetListOfFunctions()->Add(pol1);
   
   TPaveStats *ptstats = new TPaveStats(0.4802784,0.6181384,0.8491879,0.8448687,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("Entries = 10     ");
   text = ptstats->AddText("#chi^{2} / ndf = 9.055 / 8");
   text = ptstats->AddText("p0       = -0.01364 #pm 0.31742 ");
   text = ptstats->AddText("p1       = 0.2576 #pm 0.0183 ");
   ptstats->SetOptStat(10);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   optpureHFel->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(optpureHFel->GetListOfFunctions());
   optpureHFel->GetXaxis()->SetTitle("particle flow p_{T} (GeV)");
   optpureHFel->GetXaxis()->SetLabelFont(42);
   optpureHFel->GetXaxis()->SetTitleSize(0.05);
   optpureHFel->GetXaxis()->SetTitleFont(42);
   optpureHFel->GetYaxis()->SetTitle("combined iso pure Heavy Flavor cut");
   optpureHFel->GetYaxis()->SetTitleSize(0.05);
   optpureHFel->GetYaxis()->SetTitleFont(42);
   optpureHFel->Draw("");
   
   TPaveText *pt = new TPaveText(0.2018561,0.9164678,0.7099768,0.9689737,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetTextFont(42);
   text = pt->AddText("particle flow electrons");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
