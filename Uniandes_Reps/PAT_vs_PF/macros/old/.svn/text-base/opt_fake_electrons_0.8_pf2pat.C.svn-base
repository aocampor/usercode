{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Dec 16 19:10:48 2009) by ROOT version5.25/02
   TCanvas *c1 = new TCanvas("c1", "c1",1555,361,469,489);
   c1->Range(-5.323944,-6.31579,33.97183,33.94737);
   c1->SetFillColor(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.1354839);
   c1->SetBottomMargin(0.1568628);
   
   TH1F *optpurefakeel = new TH1F("optpurefakeel","particle flow electrons",10,0,30);
   optpurefakeel->SetBinContent(1,0.5);
   optpurefakeel->SetBinContent(2,2.5);
   optpurefakeel->SetBinContent(3,2.5);
   optpurefakeel->SetBinContent(4,1);
   optpurefakeel->SetBinContent(5,0.5);
   optpurefakeel->SetBinContent(6,0.5);
   optpurefakeel->SetBinContent(7,0.5);
   optpurefakeel->SetBinContent(8,0.5);
   optpurefakeel->SetBinContent(9,0.5);
   optpurefakeel->SetBinContent(10,0.5);
   optpurefakeel->SetBinError(1,0.5);
   optpurefakeel->SetBinError(2,0.5);
   optpurefakeel->SetBinError(3,0.5);
   optpurefakeel->SetBinError(4,0.5);
   optpurefakeel->SetBinError(5,0.5);
   optpurefakeel->SetBinError(6,0.5);
   optpurefakeel->SetBinError(7,0.5);
   optpurefakeel->SetBinError(8,0.5);
   optpurefakeel->SetBinError(9,0.5);
   optpurefakeel->SetBinError(10,0.5);
   optpurefakeel->SetMinimum(0);
   optpurefakeel->SetMaximum(30);
   optpurefakeel->SetEntries(10);
   
   TF1 *pol1 = new TF1("pol1","pol1",0,30);
   pol1->SetFillColor(19);
   pol1->SetFillStyle(0);
   pol1->SetLineColor(2);
   pol1->SetLineWidth(2);
   pol1->SetChisquare(17.01818);
   pol1->SetNDF(8);
   pol1->SetParameter(0,1.722727);
   pol1->SetParError(0,0.3174233);
   pol1->SetParLimits(0,0,0);
   pol1->SetParameter(1,-0.05151515);
   pol1->SetParError(1,0.0183494);
   pol1->SetParLimits(1,0,0);
   optpurefakeel->GetListOfFunctions()->Add(pol1);
   
   TPaveStats *ptstats = new TPaveStats(0.4537634,0.627451,0.8129032,0.8714597,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("Entries = 10     ");
   text = ptstats->AddText("#chi^{2} / ndf = 17.02 / 8");
   text = ptstats->AddText("p0       = 1.723 #pm 0.317 ");
   text = ptstats->AddText("p1       = -0.05152 #pm 0.01835 ");
   ptstats->SetOptStat(10);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   optpurefakeel->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(optpurefakeel->GetListOfFunctions());
   optpurefakeel->SetMarkerStyle(20);
   optpurefakeel->GetXaxis()->SetTitle("particle flow p_{T} (GeV)");
   optpurefakeel->GetXaxis()->SetLabelFont(42);
   optpurefakeel->GetXaxis()->SetTitleFont(42);
   optpurefakeel->GetYaxis()->SetTitle("combined fake cut");
   optpurefakeel->GetYaxis()->SetLabelFont(42);
   optpurefakeel->GetYaxis()->SetTitleSize(0.05);
   optpurefakeel->GetYaxis()->SetTitleFont(42);
   optpurefakeel->Draw("");
   
   TPaveText *pt = new TPaveText(0.2688172,0.91939,0.7634409,0.9738562,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetTextFont(42);
   text = pt->AddText("particle flow electrons");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
