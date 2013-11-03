{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Dec 16 18:39:03 2009) by ROOT version5.25/02
   TCanvas *c1 = new TCanvas("c1", "c1",1574,420,544,514);
   c1->Range(-6.709512,-7.384003,34.93573,51.20382);
   c1->SetFillColor(0);
   c1->SetBorderSize(2);
   c1->SetLeftMargin(0.1611111);
   c1->SetRightMargin(0.1185185);
   c1->SetTopMargin(0.07644628);
   c1->SetBottomMargin(0.1260331);
   
   TH1F *optpurefakemu = new TH1F("optpurefakemu","particle flow muons",10,0,30);
   optpurefakemu->SetBinContent(1,0.5);
   optpurefakemu->SetBinContent(2,2.5);
   optpurefakemu->SetBinContent(3,10.5);
   optpurefakemu->SetBinError(1,0.5);
   optpurefakemu->SetBinError(2,0.5);
   optpurefakemu->SetBinError(3,0.5);
   optpurefakemu->SetEntries(3);
   
   TF1 *pol1 = new TF1("pol1","pol1",0,30);
   pol1->SetFillColor(19);
   pol1->SetFillStyle(0);
   pol1->SetLineColor(2);
   pol1->SetLineWidth(1);
   pol1->SetChisquare(24);
   pol1->SetNDF(1);
   pol1->SetParameter(0,-3);
   pol1->SetParError(0,0.6038074);
   pol1->SetParLimits(0,0,0);
   pol1->SetParameter(1,1.666667);
   pol1->SetParError(1,0.1178511);
   pol1->SetParLimits(1,0,0);
   optpurefakemu->GetListOfFunctions()->Add(pol1);
   
   TPaveStats *ptstats = new TPaveStats(0.2611111,0.6921488,0.5648148,0.9049587,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("Entries = 3      ");
   text = ptstats->AddText("#chi^{2} / ndf =    24 / 1");
   text = ptstats->AddText("p0       =    -3 #pm 0.6 ");
   text = ptstats->AddText("p1       = 1.667 #pm 0.118 ");
   ptstats->SetOptStat(10);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   optpurefakemu->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(optpurefakemu->GetListOfFunctions());
   optpurefakemu->GetXaxis()->SetTitle("particle flow p_{T} (GeV)");
   optpurefakemu->GetXaxis()->SetLabelFont(42);
   optpurefakemu->GetXaxis()->SetTitleSize(0.05);
   optpurefakemu->GetXaxis()->SetTitleFont(42);
   optpurefakemu->GetYaxis()->SetTitle("combined fake cut");
   optpurefakemu->GetYaxis()->SetLabelFont(42);
   optpurefakemu->GetYaxis()->SetTitleFont(42);
   optpurefakemu->Draw("");
   
   TPaveText *pt = new TPaveText(0.2833333,0.9380165,0.7,0.9938017,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetTextFont(42);
   text = pt->AddText("particle flow muons");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
