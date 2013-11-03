{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Sep  1 11:32:47 2010) by ROOT version5.26/00
   TCanvas *c1 = new TCanvas("c1", "c1",1568,273,700,502);
   c1->Range(1.787199,-0.2844563,4.23632,16.27936);
   c1->SetFillColor(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetFrameBorderMode(0);
   
   TH1F *pfElEl = new TH1F("pfElEl","Invariant mass pf electron electron",100,0,7);
   pfElEl->SetBinContent(29,2);
   pfElEl->SetBinContent(30,9);
   pfElEl->SetBinContent(31,14);
   pfElEl->SetBinContent(32,9);
   pfElEl->SetBinContent(33,10);
   pfElEl->SetBinContent(34,13);
   pfElEl->SetBinContent(35,7);
   pfElEl->SetBinContent(36,7);
   pfElEl->SetBinContent(37,8);
   pfElEl->SetBinContent(38,9);
   pfElEl->SetBinContent(39,10);
   pfElEl->SetBinContent(40,4);
   pfElEl->SetBinContent(41,7);
   pfElEl->SetBinContent(42,7);
   pfElEl->SetBinContent(43,7);
   pfElEl->SetBinContent(44,9);
   pfElEl->SetBinContent(45,7);
   pfElEl->SetBinContent(46,13);
   pfElEl->SetBinContent(47,8);
   pfElEl->SetBinContent(48,5);
   pfElEl->SetBinContent(49,6);
   pfElEl->SetBinContent(50,4);
   pfElEl->SetBinContent(51,7);
   pfElEl->SetBinContent(52,5);
   pfElEl->SetBinContent(53,4);
   pfElEl->SetBinContent(54,3);
   pfElEl->SetBinContent(55,7);
   pfElEl->SetBinContent(56,2);
   pfElEl->SetBinContent(57,3);
   pfElEl->SetBinContent(58,2);
   pfElEl->SetEntries(208);
   
   TPaveStats *ptstats = new TPaveStats(0.6752874,0.720339,0.8764368,0.8792373,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("Entries = 208    ");
   text = ptstats->AddText("Mean  =   2.85");
   text = ptstats->AddText("RMS   = 0.5355");
   ptstats->SetOptStat(1110);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   pfElEl->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(pfElEl->GetListOfFunctions());
   pfElEl->GetXaxis()->SetTitle("e-e InvMass (GeV)");
   pfElEl->GetXaxis()->SetRange(30,57);
   pfElEl->GetXaxis()->SetLabelFont(42);
   pfElEl->GetXaxis()->SetTitleFont(42);
   pfElEl->GetYaxis()->SetTitle("N. Events");
   pfElEl->GetYaxis()->SetLabelFont(42);
   pfElEl->GetYaxis()->SetTitleFont(42);
   pfElEl->Draw("");
   
   TPaveText *pt = new TPaveText(0.2025862,0.9088983,0.7442529,0.9639831,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(2);
   pt->SetTextFont(42);
   text = pt->AddText("Invariant mass pf electron electron");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
