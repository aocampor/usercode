{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Dec 16 17:32:38 2009) by ROOT version5.25/02
   TCanvas *c1 = new TCanvas("c1", "c1",1649,404,552,524);
   c1->Range(-5.480769,-5.131579,34.03846,33.86842);
   c1->SetFillColor(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.1386861);
   c1->SetBottomMargin(0.131579);
   
   TH1F *optpurefakeel = new TH1F("optpurefakeel","particle flow electrons",10,0,30);
   optpurefakeel->SetBinContent(1,0.5);
   optpurefakeel->SetBinContent(2,0.5);
   optpurefakeel->SetBinContent(3,0.5);
   optpurefakeel->SetBinContent(4,0.5);
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
   pol1->SetLineWidth(3);
   pol1->SetChisquare(9.737502e-31);
   pol1->SetNDF(8);
   pol1->SetParameter(0,0.5);
   pol1->SetParError(0,0.3174233);
   pol1->SetParLimits(0,0,0);
   pol1->SetParameter(1,1.91392e-17);
   pol1->SetParError(1,0.0183494);
   pol1->SetParLimits(1,0,0);
   optpurefakeel->GetListOfFunctions()->Add(pol1);
   
   TPaveStats *ptstats = new TPaveStats(0.5145985,0.5870445,0.8558394,0.8441296,"brNDC");
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
   optpurefakeel->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(optpurefakeel->GetListOfFunctions());
   optpurefakeel->GetXaxis()->SetTitle("particle flow p_{T} (GeV)");
   optpurefakeel->GetXaxis()->SetLabelFont(42);
   optpurefakeel->GetXaxis()->SetTitleSize(0.05);
   optpurefakeel->GetXaxis()->SetTitleFont(42);
   optpurefakeel->GetYaxis()->SetTitle("combined Iso pure fake cut");
   optpurefakeel->GetYaxis()->SetLabelFont(42);
   optpurefakeel->GetYaxis()->SetTitleSize(0.05);
   optpurefakeel->GetYaxis()->SetTitleFont(42);
   optpurefakeel->Draw("");
   
   TPaveText *pt = new TPaveText(0.2007299,0.9210526,0.6624088,0.9777328,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetTextFont(42);
   text = pt->AddText("particle flow electrons");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
