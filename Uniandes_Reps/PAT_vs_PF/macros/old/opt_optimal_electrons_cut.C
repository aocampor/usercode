{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Dec 16 17:38:31 2009) by ROOT version5.25/02
   TCanvas *c1 = new TCanvas("c1", "c1",1649,404,552,524);
   c1->Range(-5.480769,-5.131579,34.03846,33.86842);
   c1->SetFillColor(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.1386861);
   c1->SetBottomMargin(0.131579);
   
   TH1F *optoptimalel = new TH1F("optoptimalel","particle flow electrons",10,0,30);
   optoptimalel->SetBinContent(1,3);
   optoptimalel->SetBinContent(2,2.5);
   optoptimalel->SetBinContent(3,3);
   optoptimalel->SetBinContent(4,3);
   optoptimalel->SetBinContent(5,3);
   optoptimalel->SetBinContent(6,3);
   optoptimalel->SetBinContent(7,2.5);
   optoptimalel->SetBinContent(8,2);
   optoptimalel->SetBinContent(9,2);
   optoptimalel->SetBinContent(10,2);
   optoptimalel->SetBinError(1,0.5);
   optoptimalel->SetBinError(2,0.5);
   optoptimalel->SetBinError(3,0.5);
   optoptimalel->SetBinError(4,0.5);
   optoptimalel->SetBinError(5,0.5);
   optoptimalel->SetBinError(6,0.5);
   optoptimalel->SetBinError(7,0.5);
   optoptimalel->SetBinError(8,0.5);
   optoptimalel->SetBinError(9,0.5);
   optoptimalel->SetBinError(10,0.5);
   optoptimalel->SetMinimum(0);
   optoptimalel->SetMaximum(30);
   optoptimalel->SetEntries(10);
   
   TF1 *pol1 = new TF1("pol1","pol1",0,30);
   pol1->SetFillColor(19);
   pol1->SetFillStyle(0);
   pol1->SetLineColor(2);
   pol1->SetLineWidth(1);
   pol1->SetChisquare(3.224242);
   pol1->SetNDF(8);
   pol1->SetParameter(0,3.175758);
   pol1->SetParError(0,0.3174233);
   pol1->SetParLimits(0,0,0);
   pol1->SetParameter(1,-0.03838384);
   pol1->SetParError(1,0.0183494);
   pol1->SetParLimits(1,0,0);
   optoptimalel->GetListOfFunctions()->Add(pol1);
   
   TPaveStats *ptstats = new TPaveStats(0.5237226,0.5870445,0.8594891,0.8562753,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("Entries = 10     ");
   text = ptstats->AddText("#chi^{2} / ndf = 3.224 / 8");
   text = ptstats->AddText("p0       = 3.176 #pm 0.317 ");
   text = ptstats->AddText("p1       = -0.03838 #pm 0.01835 ");
   ptstats->SetOptStat(10);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   optoptimalel->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(optoptimalel->GetListOfFunctions());
   optoptimalel->GetXaxis()->SetTitle("particle flow p_{T} (GeV)");
   optoptimalel->GetXaxis()->SetLabelFont(42);
   optoptimalel->GetXaxis()->SetTitleSize(0.05);
   optoptimalel->GetXaxis()->SetTitleFont(42);
   optoptimalel->GetYaxis()->SetTitle("combined iso optimal cut");
   optoptimalel->GetYaxis()->SetLabelFont(42);
   optoptimalel->GetYaxis()->SetTitleSize(0.05);
   optoptimalel->GetYaxis()->SetTitleFont(42);
   optoptimalel->Draw("");
   
   TPaveText *pt = new TPaveText(0.2062044,0.9068826,0.6678832,0.9595142,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetTextFont(42);
   text = pt->AddText("particle flow electrons");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
