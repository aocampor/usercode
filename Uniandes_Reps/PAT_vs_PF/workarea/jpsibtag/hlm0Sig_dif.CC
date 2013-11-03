{
  TH1F *h = new TH1F("SigDifSR","Significance difference between SRL and PFL SR-PF",1000,-10,10);
  //////////LM0 SRL-PFL
  ///el
  h->Fill(4.067994-4.76183);
  h->Fill(4.64383448-4.32889433);
  h->Fill(4.7296478-4.4076446);
  h->Fill(4.73790212-4.41631981);
  //mu
  h->Fill(7.2414881-6.6120485);
  h->Fill(8.0691-6.5029);
  h->Fill(8.97012833-7.217001);
  h->Fill(2.525537-7.416525);

  ///////////LM1 SRL-PFL
  ///el
  h->Fill(0.540203-0.626958);
  h->Fill(0.63783656-0.60295427);
  h->Fill(0.667942-0.6320338);
  h->Fill(0.66925599-0.63305704);
  ///mu
  h->Fill(0.9787537-0.9054015);
  h->Fill(1.08193751-0.96015413);
  h->Fill(1.35915157-1.20709667);
  h->Fill(0.39096514-1.27032213);

  //////LM0 SRL-PFl same sign double
  ////el
  h->Fill(5.149-5.024);
  h->Fill(3.493-3.662);
  h->Fill(3.314-3.667);
  h->Fill(3.342-3.667);
  ///mu
  h->Fill(20.856-5.661);
  h->Fill(6.073-5.850);
  h->Fill(5.865-5.85);
  h->Fill(5.892-5.986);
  ////elmu
  h->Fill(7.219-6.559); 
  h->Fill(5.04-5.24);
  h->Fill(4.999-4.906);
  h->Fill(3.358-4.954);
  
  //////LM1 SRL-PFl same sign double
  ////el
  h->Fill(0.75-0.855);
  h->Fill(0.616-0.703);
  h->Fill(0.628-0.737);
  h->Fill(0.628-0.737);
  ///mu
  h->Fill(3.585-0.987);
  h->Fill(1.067-1.059);
  h->Fill(1.313-1.295);
  h->Fill(1.226-1.28);
  ////elmu
  h->Fill(1.492-1.38);
  h->Fill(0.783-1.056);
  h->Fill(0.849-1.028);
  h->Fill(0.565-1.010);

  //////LM0 SRL-PFl opposite sign double
  ////el
  h->Fill(2.551-3.008);
  h->Fill(3.280-3.251);
  h->Fill(3.368-3.336);
  h->Fill(3.373-3.336);
  ///mu
  h->Fill(7.072-5.408);
  h->Fill(7.583-5.43);
  h->Fill(8.905-6.313);
  h->Fill(7.38-4.705);
  ////elmu
  h->Fill(2.896-3.109);
  h->Fill(3.927-3.686);
  h->Fill(4.186-4.159);
  h->Fill(3.588-4.304);

  //////LM1 SRL-PFl opposite sign double
  ////el
  h->Fill(0.684-0.817);
  h->Fill(0.789-0.864);
  h->Fill(0.815-0.887);
  h->Fill(0.818-0.887);
  ///mu
  h->Fill(1.841-1.522);
  h->Fill(1.840-1.532);
  h->Fill(2.18-1.831);
  h->Fill(1.769-1.344);
  ////elmu
  h->Fill(0.302-0.318);
  h->Fill(0.408-0.393);
  h->Fill(0.503-0.540);
  h->Fill(0.442-0.577);
  TCanvas *c1 = new TCanvas("c1","c1",1301,333,650,544);
  c1->SetFillColor(0);
  c1->SetBorderSize(0);
  c1->SetLeftMargin(0.172471);
  c1->SetRightMargin(0.15819237);
  c1->SetTopMargin(0.06916996);
  c1->SetBottomMargin(0.1304348);
  c1->SetTickx(1);
  c1->SetTicky(1);
  c1->SetFrameFillColor(0);
  c1->SetFrameBorderMode(0);
  gStyle->SetFillColor(0);
  gStyle->SetStatBorderSize(0);
  gStyle->SetStatFont(42);
  gStyle->SetOptStat(2210);
  gStyle->SetOptTitle(0);
  h->GetXaxis()->SetTitle("#Delta Significance (SRL-PFL)");
  h->GetXaxis()->SetLabelFont(42);
  h->GetXaxis()->SetTitleFont(42);
  h->GetYaxis()->SetTitle("Number of Entries");
  h->GetYaxis()->SetLabelFont(42);
  h->GetYaxis()->SetTitleOffset(1.7);
  h->GetYaxis()->SetTitleFont(42);
  h->Draw();
  c1->SaveAs("Significance_difference_between_SRLandPFL.gif");





  TH1F *hn = new TH1F("SigDifSRPF","Significance difference between SR and PF SR-PF",1000,-10,10);
  //////////LM0 SRL-PFL
  ///el
  hn->Fill(4.40679-7.7918);
  hn->Fill(4.64383448-7.333);
  hn->Fill(4.7296478-7.482);
  hn->Fill(4.73790212-7.4911);
  //mu
  hn->Fill(7.2414881-6.484);
  hn->Fill(8.0691-6.352);
  hn->Fill(8.97012833-6.947);
  hn->Fill(2.525537-7.2607);

  ///////////LM1 SRL-PFL
  ///el
  hn->Fill(0.540203-1.016);
  hn->Fill(0.63783656-1.035);
  hn->Fill(0.667942-1.105);
  hn->Fill(0.66925599-1.107);
  ///mu
  hn->Fill(0.9787537-0.899);
  hn->Fill(1.08193751-0.9534);
  hn->Fill(1.35915157-1.1759);
  hn->Fill(0.39096514-1.2538);

  //////LM0 SRL-PFl same sign double
  ////el
  //h->Fill(5.149-5.024);
  hn->Fill(3.493-6.8128);
  hn->Fill(3.314-7.4104);
  hn->Fill(3.342-7.4104);
  ///mu
  hn->Fill(20.856-6.6332);
  hn->Fill(6.073-6.293);
  hn->Fill(5.865-6.265);
  hn->Fill(5.892-6.3162);
  ////elmu
  hn->Fill(7.219-19.541); 
  hn->Fill(5.04-6.808);
  hn->Fill(4.999-5.921);
  hn->Fill(3.358-6.191);
  
  //////LM1 SRL-PFl same sign double
  ////el
  //h->Fill(0.75-0.855);
  hn->Fill(0.616-1.494);
  hn->Fill(0.628-1.733);
  hn->Fill(0.628-1.733);
  ///mu
  hn->Fill(3.585-1.1905);
  hn->Fill(1.067-1.1716);
  hn->Fill(1.313-1.4569);
  hn->Fill(1.226-1.45);
  ////elmu
  hn->Fill(1.492-4.36);
  hn->Fill(0.783-1.509);
  hn->Fill(0.849-1.381);
  hn->Fill(0.565-1.405);

  //////LM0 SRL-PFl opposite sign double
  ////el
  hn->Fill(2.551-4.401);
  hn->Fill(3.280-5.038);
  hn->Fill(3.368-5.153);
  hn->Fill(3.373-5.153);
  ///mu
  hn->Fill(7.072-5.425);
  hn->Fill(7.583-5.536);
  hn->Fill(8.905-6.564);
  hn->Fill(7.38-4.526);
  ////elmu
  hn->Fill(2.896-2.811);
  hn->Fill(3.927-4.486);
  hn->Fill(4.186-5.0605);
  hn->Fill(3.588-5.274);

  //////LM1 SRL-PFl opposite sign double
  ////el
  hn->Fill(0.684-1.391);
  hn->Fill(0.789-1.562);
  hn->Fill(0.815-1.5949);
  hn->Fill(0.818-1.5949);
  ///mu
  hn->Fill(1.841-1.631);
  hn->Fill(1.840-1.6444);
  hn->Fill(2.18-2.016);
  hn->Fill(1.769-1.373);
  ////elmu
  hn->Fill(0.302-0.327);
  hn->Fill(0.408-0.546);
  hn->Fill(0.503-0.753);
  hn->Fill(0.442-0.806);
  TCanvas *c1 = new TCanvas("c1","c1",1301,333,650,544);
  c1->SetFillColor(0);
  c1->SetBorderSize(0);
  c1->SetLeftMargin(0.172471);
  c1->SetRightMargin(0.15819237);
  c1->SetTopMargin(0.06916996);
  c1->SetBottomMargin(0.1304348);
  c1->SetTickx(1);
  c1->SetTicky(1);
  c1->SetFrameFillColor(0);
  c1->SetFrameBorderMode(0);
  gStyle->SetFillColor(0);
  gStyle->SetStatBorderSize(0);
  gStyle->SetStatFont(42);
  gStyle->SetOptStat(2210);
  gStyle->SetOptTitle(0);
  hn->GetXaxis()->SetTitle("#Delta Significance (SR-PF)");
  hn->GetXaxis()->SetLabelFont(42);
  hn->GetXaxis()->SetTitleFont(42);
  hn->GetYaxis()->SetTitle("Number of Entries");
  hn->GetYaxis()->SetLabelFont(42);
  hn->GetYaxis()->SetTitleOffset(1.7);
  hn->GetYaxis()->SetTitleFont(42);
  hn->Draw();
  c1->SaveAs("Significance_difference_between_SRandPF.gif");

  TH1F *h1 = new TH1F("SigDifPF","Significance difference between SRL and PFL usinf PF SR-PF",1000,-10,10);
  //////////LM0 SRL-PFL
  ///el
  h1->Fill(6.565-7.791);
  h1->Fill(7.412-7.333);
  h1->Fill(7.566-7.482);
  h1->Fill(7.581-7.491);
  //mu
  h1->Fill(6.999-6.484);
  h1->Fill(7.955-6.352);
  h1->Fill(8.797-6.947);
  h1->Fill(9.291-7.26);

  ///////////LM1 SRL-PFL
  ///el
  h1->Fill(0.85-1.016);
  h1->Fill(1.007-1.035);
  h1->Fill(1.072-1.105);
  h1->Fill(1.075-1.107);
  ///mu
  h1->Fill(0.961-0.899);
  h1->Fill(1.083-0.953);
  h1->Fill(1.347-1.175);
  h1->Fill(1.45-1.253);

  //////LM0 SRL-PFl same sign double
  ////el
  h1->Fill(7.529-9999);
  h1->Fill(6.478-6.812);
  h1->Fill(6.854-7.41);
  h1->Fill(6.922-7.41);
  ///mu
  h1->Fill(12.844-6.633);
  h1->Fill(7.842-6.293);
  h1->Fill(6.646-6.265);
  h1->Fill(6.76-6.316);
  ////elmu
  h1->Fill(13.612-19.541); 
  h1->Fill(6.616-6.808);
  h1->Fill(6.396-5.921);
  h1->Fill(6.618-6.191);
  
  //////LM1 SRL-PFl same sign double
  ////el
  h1->Fill(1.254-9999);
  h1->Fill(1.261-1.494);
  h1->Fill(1.363-1.733);
  h1->Fill(2.291-1.19);
  ///mu
  h1->Fill(2.291-1-19);
  h1->Fill(1.511-1.171);
  h1->Fill(1.626-1.456);
  h1->Fill(1.597-1.45);
  ////elmu
  h1->Fill(2.973-4.362);
  h1->Fill(1.141-1.509);
  h1->Fill(1.227-1.381);
  h1->Fill(1.267-1.405);

  //////LM1 SRL-PFl opposite sign double
  ////el
  h1->Fill(4.125-4.401);
  h1->Fill(5.358-5.038);
  h1->Fill(5.474-5.153);
  h1->Fill(5.474-5.153);
  ///mu
  h1->Fill(7.139-5.425);
  h1->Fill(7.618-5.536);
  h1->Fill(8.873-6.564);
  h1->Fill(6.764-4.526);
  ////elmu
  h1->Fill(2.967-2.811);
  h1->Fill(4.163-4.486);
  h1->Fill(4.918.5.06);
  h1->Fill(5.185-5.274);

  //////LM1 SRL-PFl opposite sign double
  ////el
  h1->Fill(1.200-1.391);
  h1->Fill(1.41-1.562);
  h1->Fill(1.459-1.594);
  h1->Fill(1.459-1.594);
  ///mu
  h1->Fill(1.966-1.631);
  h1->Fill(1.961-1.644);
  h1->Fill(2.337-2.016);
  h1->Fill(1.755-1.373);
  ////elmu
  h1->Fill(0.326-0.327);
  h1->Fill(0.471-0.546);
  h1->Fill(0.645-0.753);
  h1->Fill(0.699-0.806);
  TCanvas *c1 = new TCanvas("c1","c1",1301,333,650,544);
  c1->SetFillColor(0);
  c1->SetBorderSize(0);
  c1->SetLeftMargin(0.172471);
  c1->SetRightMargin(0.15819237);
  c1->SetTopMargin(0.06916996);
  c1->SetBottomMargin(0.1304348);
  c1->SetTickx(1);
  c1->SetTicky(1);
  c1->SetFrameFillColor(0);
  c1->SetFrameBorderMode(0);
  gStyle->SetFillColor(0);
  gStyle->SetStatBorderSize(0);
  gStyle->SetStatFont(42);
  gStyle->SetOptStat(2210);
  gStyle->SetOptTitle(0);
  h1->GetXaxis()->SetTitle("#Delta Significance (SRL-PFL)");
  h1->GetXaxis()->SetLabelFont(42);
  h1->GetXaxis()->SetTitleFont(42);
  h1->GetYaxis()->SetTitle("Number of Entries");
  h1->GetYaxis()->SetLabelFont(42);
  h1->GetYaxis()->SetTitleOffset(1.7);
  h1->GetYaxis()->SetTitleFont(42);
  h1->Draw();
  c1->SaveAs("Significance_difference_between_SRLandPFLforPFframe.gif");

  TH1F *h2 = new TH1F("SigDifSR5","Significance difference between SRL and PFL SR-PF pt less than 5",1000,-10,10);
  //////////LM0 SRL-PFL
  ///el
  h2->Fill(4.7296478-4.4076446);
  h2->Fill(4.73790212-4.41631981);
  //mu
  h2->Fill(8.97012833-7.217001);
  h2->Fill(2.525537-7.416525);

  ///////////LM1 SRL-PFL
  ///el
  h2->Fill(0.667942-0.6320338);
  h2->Fill(0.66925599-0.63305704);
  ///mu
  h2->Fill(1.35915157-1.20709667);
  h2->Fill(0.39096514-1.27032213);

  //////LM0 SRL-PFl same sign double
  ////el
  h2->Fill(3.314-3.667);
  h2->Fill(3.342-3.667);
  ///mu
  h2->Fill(5.865-5.85);
  h2->Fill(5.892-5.986);
  ////elmu
  h2->Fill(4.999-4.906);
  h2->Fill(3.358-4.954);
  
  //////LM1 SRL-PFl same sign double
  ////el
  h2->Fill(0.628-0.737);
  h2->Fill(0.628-0.737);
  ///mu
  h2->Fill(1.313-1.295);
  h2->Fill(1.226-1.28);
  ////elmu
  h2->Fill(0.849-1.028);
  h2->Fill(0.565-1.010);

  //////LM0 SRL-PFl opposite sign double
  ////el
  h2->Fill(3.368-3.336);
  h2->Fill(3.373-3.336);
  ///mu
  h2->Fill(8.905-6.313);
  h2->Fill(7.38-4.705);
  ////elmu
  h2->Fill(4.186-4.159);
  h2->Fill(3.588-4.304);

  //////LM1 SRL-PFl opposite sign double
  ////el
  h2->Fill(0.815-0.887);
  h2->Fill(0.818-0.887);
  ///mu
  h2->Fill(2.18-1.831);
  h2->Fill(1.769-1.344);
  ////elmu
  h2->Fill(0.503-0.540);
  h2->Fill(0.442-0.577);
  TCanvas *c1 = new TCanvas("c1","c1",1301,333,650,544);
  c1->SetFillColor(0);
  c1->SetBorderSize(0);
  c1->SetLeftMargin(0.172471);
  c1->SetRightMargin(0.15819237);
  c1->SetTopMargin(0.06916996);
  c1->SetBottomMargin(0.1304348);
  c1->SetTickx(1);
  c1->SetTicky(1);
  c1->SetFrameFillColor(0);
  c1->SetFrameBorderMode(0);
  gStyle->SetFillColor(0);
  gStyle->SetStatBorderSize(0);
  gStyle->SetStatFont(42);
  gStyle->SetOptStat(2210);
  gStyle->SetOptTitle(0);
  h2->GetXaxis()->SetTitle("#Delta Significance (SRL-PFL)");
  h2->GetXaxis()->SetLabelFont(42);
  h2->GetXaxis()->SetTitleFont(42);
  h2->GetYaxis()->SetTitle("Number of Entries");
  h2->GetYaxis()->SetLabelFont(42);
  h2->GetYaxis()->SetTitleOffset(1.7);
  h2->GetYaxis()->SetTitleFont(42);
  h2->Draw();
  c1->SaveAs("Significance_difference_between_SRLandPFLptbigger2and5.gif");

  TH1F *h3 = new TH1F("SigDifSR2","Significance difference between SRL and PFL SR-PF pt bigger than 2",1000,-10,10);
  //////////LM0 SRL-PFL
  ///el
  h3->Fill(4.73790212-4.41631981);
  //mu
  h3->Fill(2.525537-7.416525);

  ///////////LM1 SRL-PFL
  ///el
  h3->Fill(0.66925599-0.63305704);
  ///mu
  h3->Fill(0.39096514-1.27032213);

  //////LM0 SRL-PFl same sign double
  ////el
  h3->Fill(3.342-3.667);
  ///mu
  h3->Fill(5.892-5.986);
  ////elmu
  h3->Fill(3.358-4.954);
  
  //////LM1 SRL-PFl same sign double
  ////el
  h3->Fill(0.628-0.737);
  ///mu
  h3->Fill(1.226-1.28);
  ////elmu
  h3->Fill(0.565-1.010);

  //////LM0 SRL-PFl opposite sign double
  ////el
  h3->Fill(3.373-3.336);
  ///mu
  h3->Fill(7.38-4.705);
  ////elmu
  h3->Fill(3.588-4.304);

  //////LM1 SRL-PFl opposite sign double
  ////el
  h3->Fill(0.818-0.887);
  ///mu
  h3->Fill(1.769-1.344);
  ////elmu
  h3->Fill(0.442-0.577);
  TCanvas *c1 = new TCanvas("c1","c1",1301,333,650,544);
  c1->SetFillColor(0);
  c1->SetBorderSize(0);
  c1->SetLeftMargin(0.172471);
  c1->SetRightMargin(0.15819237);
  c1->SetTopMargin(0.06916996);
  c1->SetBottomMargin(0.1304348);
  c1->SetTickx(1);
  c1->SetTicky(1);
  c1->SetFrameFillColor(0);
  c1->SetFrameBorderMode(0);
  gStyle->SetFillColor(0);
  gStyle->SetStatBorderSize(0);
  gStyle->SetStatFont(42);
  gStyle->SetOptStat(2210);
  gStyle->SetOptTitle(0);
  h3->GetXaxis()->SetTitle("#Delta Significance (SRL-PFL)");
  h3->GetXaxis()->SetLabelFont(42);
  h3->GetXaxis()->SetTitleFont(42);
  h3->GetYaxis()->SetTitle("Number of Entries");
  h3->GetYaxis()->SetLabelFont(42);
  h3->GetYaxis()->SetTitleOffset(1.7);
  h3->GetYaxis()->SetTitleFont(42);
  h3->Draw();
  c1->SaveAs("Significance_difference_between_SRLandPFLptbigger2.gif");
}
