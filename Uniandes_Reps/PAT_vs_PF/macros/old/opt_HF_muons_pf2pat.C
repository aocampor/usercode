{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Dec 16 18:16:50 2009) by ROOT version5.25/02
   TCanvas *c1 = new TCanvas("c1", "c1",1705,450,341,499);
   c1->Range(-5.658915,-6.342857,34.03101,34.02857);
   c1->SetFillColor(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.1425781);
   c1->SetBottomMargin(0.1571125);
   
   TH1F *optpureHFmu = new TH1F("optpureHFmu","particle flow muons ",10,0,30);
   optpureHFmu->SetBinContent(1,0.5);
   optpureHFmu->SetBinContent(2,0.5);
   optpureHFmu->SetBinContent(3,2.5);
   optpureHFmu->SetBinContent(4,4);
   optpureHFmu->SetBinContent(5,5.5);
   optpureHFmu->SetBinContent(6,7);
   optpureHFmu->SetBinContent(7,8.5);
   optpureHFmu->SetBinContent(8,9.5);
   optpureHFmu->SetBinContent(9,10.5);
   optpureHFmu->SetBinContent(10,12.5);
   optpureHFmu->SetBinError(1,0.5);
   optpureHFmu->SetBinError(2,0.5);
   optpureHFmu->SetBinError(3,0.5);
   optpureHFmu->SetBinError(4,0.5);
   optpureHFmu->SetBinError(5,0.5);
   optpureHFmu->SetBinError(6,0.5);
   optpureHFmu->SetBinError(7,0.5);
   optpureHFmu->SetBinError(8,0.5);
   optpureHFmu->SetBinError(9,0.5);
   optpureHFmu->SetBinError(10,0.5);
   optpureHFmu->SetMinimum(0);
   optpureHFmu->SetMaximum(30);
   optpureHFmu->SetEntries(10);
   
   TF1 *pol1 = new TF1("pol1","pol1",0,30);
   pol1->SetFillColor(19);
   pol1->SetFillStyle(0);
   pol1->SetLineColor(2);
   pol1->SetLineWidth(2);
   pol1->SetChisquare(5.490909);
   pol1->SetNDF(8);
   pol1->SetParameter(0,-0.8090909);
   pol1->SetParError(0,0.3174233);
   pol1->SetParLimits(0,0,0);
   pol1->SetParameter(1,0.4606061);
   pol1->SetParError(1,0.0183494);
   pol1->SetParLimits(1,0,0);
   optpureHFmu->GetListOfFunctions()->Add(pol1);
   
   TPaveStats *ptstats = new TPaveStats(0.5,0.6454352,0.8535156,0.8556263,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("Entries = 10     ");
   text = ptstats->AddText("#chi^{2} / ndf = 5.491 / 8");
   text = ptstats->AddText("p0       = -0.8091 #pm 0.3174 ");
   text = ptstats->AddText("p1       = 0.4606 #pm 0.0183 ");
   ptstats->SetOptStat(10);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   optpureHFmu->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(optpureHFmu->GetListOfFunctions());
   optpureHFmu->GetXaxis()->SetTitle("particle flow p_{T} (GeV)");
   optpureHFmu->GetXaxis()->SetLabelFont(42);
   optpureHFmu->GetXaxis()->SetTitleSize(0.05);
   optpureHFmu->GetXaxis()->SetTitleFont(42);
   optpureHFmu->GetYaxis()->SetTitle("combined pure Heavy Flavor cut");
   optpureHFmu->GetYaxis()->SetLabelFont(42);
   optpureHFmu->GetYaxis()->SetTitleSize(0.05);
   optpureHFmu->GetYaxis()->SetTitleFont(42);
   optpureHFmu->Draw("");
   
   TPaveText *pt = new TPaveText(0.1796875,0.9193206,0.6132812,0.9723992,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetTextFont(42);
   text = pt->AddText("particle flow muons ");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
