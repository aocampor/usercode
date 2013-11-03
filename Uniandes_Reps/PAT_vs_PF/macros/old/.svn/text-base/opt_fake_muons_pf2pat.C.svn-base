{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Dec 16 18:20:41 2009) by ROOT version5.25/02
   TCanvas *c1 = new TCanvas("c1", "c1",1705,450,516,501);
   c1->Range(-5.658915,-6.342857,34.03101,34.02857);
   c1->SetFillColor(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.1425781);
   c1->SetBottomMargin(0.1571125);
   
   TH1F *optpurefakemu = new TH1F("optpurefakemu","prompt muons",10,0,30);
   optpurefakemu->SetBinContent(1,0.5);
   optpurefakemu->SetBinContent(2,0.5);
   optpurefakemu->SetBinContent(3,0.5);
   optpurefakemu->SetBinContent(4,1.5);
   optpurefakemu->SetBinContent(5,1.5);
   optpurefakemu->SetBinContent(6,5);
   optpurefakemu->SetBinContent(7,4);
   optpurefakemu->SetBinContent(8,7.5);
   optpurefakemu->SetBinContent(9,5);
   optpurefakemu->SetBinContent(10,0.5);
   optpurefakemu->SetBinError(1,0.5);
   optpurefakemu->SetBinError(2,0.5);
   optpurefakemu->SetBinError(3,0.5);
   optpurefakemu->SetBinError(4,0.5);
   optpurefakemu->SetBinError(5,0.5);
   optpurefakemu->SetBinError(6,0.5);
   optpurefakemu->SetBinError(7,0.5);
   optpurefakemu->SetBinError(8,0.5);
   optpurefakemu->SetBinError(9,0.5);
   optpurefakemu->SetBinError(10,0.5);
   optpurefakemu->SetMinimum(0);
   optpurefakemu->SetMaximum(30);
   optpurefakemu->SetEntries(10);
   
   TF1 *pol1 = new TF1("pol1","pol1",0,30);
   pol1->SetFillColor(19);
   pol1->SetFillStyle(0);
   pol1->SetLineColor(2);
   pol1->SetLineWidth(2);
   pol1->SetChisquare(157.297);
   pol1->SetNDF(8);
   pol1->SetParameter(0,0.3015152);
   pol1->SetParError(0,0.3174233);
   pol1->SetParLimits(0,0,0);
   pol1->SetParameter(1,0.1565657);
   pol1->SetParError(1,0.0183494);
   pol1->SetParLimits(1,0,0);
   optpurefakemu->GetListOfFunctions()->Add(pol1);
   
   TPaveStats *ptstats = new TPaveStats(0.5117188,0.6390658,0.8378906,0.8471338,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("Entries = 10     ");
   text = ptstats->AddText("#chi^{2} / ndf = 157.3 / 8");
   text = ptstats->AddText("p0       = 0.3015 #pm 0.3174 ");
   text = ptstats->AddText("p1       = 0.1566 #pm 0.0183 ");
   ptstats->SetOptStat(10);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   optpurefakemu->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(optpurefakemu->GetListOfFunctions());
   optpurefakemu->GetXaxis()->SetTitle("particle flow p_{T} (GeV)");
   optpurefakemu->GetXaxis()->SetLabelFont(42);
   optpurefakemu->GetXaxis()->SetTitleSize(0.05);
   optpurefakemu->GetXaxis()->SetTitleFont(42);
   optpurefakemu->GetYaxis()->SetTitle("combined pure fake cut");
   optpurefakemu->GetYaxis()->SetLabelFont(42);
   optpurefakemu->GetYaxis()->SetTitleSize(0.05);
   optpurefakemu->GetYaxis()->SetTitleFont(42);
   optpurefakemu->Draw("");
   
   TPaveText *pt = new TPaveText(0.2734375,0.9171975,0.5917969,0.9723992,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetTextFont(42);
   text = pt->AddText("prompt muons");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
