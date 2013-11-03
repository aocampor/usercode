{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Dec 16 18:47:02 2009) by ROOT version5.25/02
   TCanvas *c1 = new TCanvas("c1", "c1",1574,420,544,514);
   c1->Range(-5.085996,-4.740933,34.71744,32.87565);
   c1->SetFillColor(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.1277778);
   c1->SetRightMargin(0.1185185);
   c1->SetTopMargin(0.07644628);
   c1->SetBottomMargin(0.1260331);
   c1->SetFrameBorderMode(0);
   
   TH1F *optoptimalmu = new TH1F("optoptimalmu","particle flow muons",10,0,30);
   optoptimalmu->SetBinContent(1,2);
   optoptimalmu->SetBinContent(2,5);
   optoptimalmu->SetBinContent(3,7.5);
   optoptimalmu->SetBinContent(4,9);
   optoptimalmu->SetBinContent(5,10.5);
   optoptimalmu->SetBinContent(6,11);
   optoptimalmu->SetBinContent(7,11);
   optoptimalmu->SetBinContent(8,11);
   optoptimalmu->SetBinContent(9,10);
   optoptimalmu->SetBinContent(10,11);
   optoptimalmu->SetBinError(1,0.5);
   optoptimalmu->SetBinError(2,0.5);
   optoptimalmu->SetBinError(3,0.5);
   optoptimalmu->SetBinError(4,0.5);
   optoptimalmu->SetBinError(5,0.5);
   optoptimalmu->SetBinError(6,0.5);
   optoptimalmu->SetBinError(7,0.5);
   optoptimalmu->SetBinError(8,0.5);
   optoptimalmu->SetBinError(9,0.5);
   optoptimalmu->SetBinError(10,0.5);
   optoptimalmu->SetMinimum(0);
   optoptimalmu->SetMaximum(30);
   optoptimalmu->SetEntries(10);
   
   TF1 *pol1 = new TF1("pol1","pol1",0,30);
   pol1->SetFillColor(19);
   pol1->SetFillStyle(0);
   pol1->SetLineColor(2);
   pol1->SetLineWidth(1);
   pol1->SetChisquare(106.8242);
   pol1->SetNDF(8);
   pol1->SetParameter(0,4.557576);
   pol1->SetParError(0,0.3174233);
   pol1->SetParLimits(0,0,0);
   pol1->SetParameter(1,0.2828283);
   pol1->SetParError(1,0.0183494);
   pol1->SetParLimits(1,0,0);
   optoptimalmu->GetListOfFunctions()->Add(pol1);
   
   TPaveStats *ptstats = new TPaveStats(0.4518519,0.6260331,0.8092593,0.8904959,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("Entries = 10     ");
   text = ptstats->AddText("#chi^{2} / ndf = 106.8 / 8");
   text = ptstats->AddText("p0       = 4.558 #pm 0.317 ");
   text = ptstats->AddText("p1       = 0.2828 #pm 0.0183 ");
   ptstats->SetOptStat(10);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   optoptimalmu->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(optoptimalmu->GetListOfFunctions());
   optoptimalmu->GetXaxis()->SetTitle("particle flow p_{T} (GeV)");
   optoptimalmu->GetXaxis()->SetLabelFont(42);
   optoptimalmu->GetXaxis()->SetTitleSize(0.05);
   optoptimalmu->GetXaxis()->SetTitleFont(42);
   optoptimalmu->GetYaxis()->SetTitle("combined optimal cut");
   optoptimalmu->GetYaxis()->SetLabelFont(42);
   optoptimalmu->GetYaxis()->SetTitleSize(0.05);
   optoptimalmu->GetYaxis()->SetTitleFont(42);
   optoptimalmu->Draw("");
   
   TPaveText *pt = new TPaveText(0.1888889,0.9318182,0.6074074,0.9855372,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetTextFont(42);
   text = pt->AddText("particle flow muons");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
