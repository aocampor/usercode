{
  TH1F *h = new TH1F("SigDifSR","Significance difference between SRL and PFL SR-PF",1000,-10,10);
  //////////LM0 SRL-PFL
  ///el
  h->Fill(6.15-7.15);
  h->Fill(7.27-6.602);
  h->Fill(7.37-6.69);
  h->Fill(7.38-6.7);
  //mu
  h->Fill(7.33-6.68);
  h->Fill(8.55-6.65);
  h->Fill(9.36-7.34);
  h->Fill(2.31-7.49);

  ///////////LM1 SRL-PFL
  ///el
  h->Fill(0.81-0.94);
  h->Fill(0.98-0.93);
  h->Fill(1.02-0.98);
  h->Fill(1.02-0.98);
  ///mu
  h->Fill(0.97-0.9);
  h->Fill(1.106-0.97);
  h->Fill(1.37-1.21);
  h->Fill(0.34-1.27);

  //////LM0 SRL-PFl same sign double
  ////el
  h->Fill(9.82-11.38);
  h->Fill(5.26-5.41);
  h->Fill(4.75-5.99);
  h->Fill(4.75-5.99);
  ///mu
  h->Fill(19.84-5.3);
  h->Fill(6.39-5.38);
  h->Fill(6.13-5.51);
  h->Fill(6.24-5.83);
  ////elmu
  h->Fill(11.06-17.12); 
  h->Fill(6.68-7.69);
  h->Fill(6.52-6.82);
  h->Fill(6.7-6.86);
  
  //////LM1 SRL-PFl same sign double
  ////el
  h->Fill(1.76-2.33);
  h->Fill(1.04-1.29);
  h->Fill(0.95-1.47);
  h->Fill(0.95-1.47);
  ///mu
  h->Fill(3.64-0.98);
  h->Fill(1.10-1.04);
  h->Fill(1.32-1.26);
  h->Fill(1.26-1.28);
  ////elmu
  h->Fill(2.32-3.62);
  h->Fill(1.1-1.58);
  h->Fill(1.16-1.44);
  h->Fill(1.19-1.42);

  //////LM0 SRL-PFl opposite sign double
  ////el
  h->Fill(4.08-4.43);
  h->Fill(5.78-4.92);
  h->Fill(5.88-5.05);
  h->Fill(5.88-5.05);
  ///mu
  h->Fill(7.01-5.43);
  h->Fill(8.07-5.43);
  h->Fill(9.49-6.29);
  h->Fill(3.42-4.68);
  ////elmu
  h->Fill(3.88-3.82);
  h->Fill(5.49-4.65);
  h->Fill(5.24-5.24);
  h->Fill(5.52-5.45);

  //////LM1 SRL-PFl opposite sign double
  ////el
  h->Fill(1.15-1.28);
  h->Fill(1.42-1.37);
  h->Fill(1.46-1.39);
  h->Fill(1.46-1.39);
  ///mu
  h->Fill(1.85-1.53);
  h->Fill(1.94-1.52);
  h->Fill(2.29-1.82);
  h->Fill(0.81-1.34);
  ////elmu
  h->Fill(0.42-0.41);
  h->Fill(0.57-0.51);
  h->Fill(0.65-0.71);
  h->Fill(0.70-0.77);
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
  hn->Fill(6.15-7.7918);
  hn->Fill(7.27-7.333);
  hn->Fill(7.37-7.482);
  hn->Fill(7.38-7.4911);
  //mu
  hn->Fill(7.33-6.484);
  hn->Fill(8.55-6.352);
  hn->Fill(9.36-6.947);
  hn->Fill(2.31-7.2607);

  ///////////LM1 SRL-PFL
  ///el
  hn->Fill(0.81-1.016);
  hn->Fill(0.98-1.035);
  hn->Fill(1.02-1.105);
  hn->Fill(1.02-1.107);
  ///mu
  hn->Fill(0.97-0.899);
  hn->Fill(1.10-0.9534);
  hn->Fill(1.37-1.1759);
  hn->Fill(0.34-1.2538);

  //////LM0 SRL-PFl same sign double
  ////el
  //h->Fill(9.82-5.024);
  hn->Fill(5.26-6.8128);
  hn->Fill(4.75-7.4104);
  hn->Fill(4.75-7.4104);
  ///mu
  hn->Fill(19.84-6.6332);
  hn->Fill(6.39-6.293);
  hn->Fill(6.13-6.265);
  hn->Fill(6.24-6.3162);
  ////elmu
  hn->Fill(11.06-19.541); 
  hn->Fill(6.68-6.808);
  hn->Fill(6.52-5.921);
  hn->Fill(6.7-6.191);
  
  //////LM1 SRL-PFl same sign double
  ////el
  //h->Fill(1.76-0.855);
  hn->Fill(1.04-1.494);
  hn->Fill(0.95-1.733);
  hn->Fill(0.95-1.733);
  ///mu
  hn->Fill(3.64-1.1905);
  hn->Fill(1.1-1.1716);
  hn->Fill(1.32-1.4569);
  hn->Fill(1.26-1.45);
  ////elmu
  hn->Fill(2.32-4.36);
  hn->Fill(1.1-1.509);
  hn->Fill(1.16-1.381);
  hn->Fill(1.19-1.405);

  //////LM0 SRL-PFl opposite sign double
  ////el
  hn->Fill(4.08-4.401);
  hn->Fill(5.78-5.038);
  hn->Fill(5.88-5.153);
  hn->Fill(5.88-5.153);
  ///mu
  hn->Fill(7.01-5.425);
  hn->Fill(8.07-5.536);
  hn->Fill(9.49-6.564);
  hn->Fill(3.42-4.526);
  ////elmu
  hn->Fill(3.88-2.811);
  hn->Fill(5.49-4.486);
  hn->Fill(5.24-5.0605);
  hn->Fill(5.52-5.274);

  //////LM1 SRL-PFl opposite sign double
  ////el
  hn->Fill(1.15-1.391);
  hn->Fill(1.42-1.562);
  hn->Fill(1.46-1.5949);
  hn->Fill(1.46-1.5949);
  ///mu
  hn->Fill(1.85-1.631);
  hn->Fill(1.94-1.6444);
  hn->Fill(2.29-2.016);
  hn->Fill(0.81-1.373);
  ////elmu
  hn->Fill(0.42-0.327);
  hn->Fill(0.57-0.546);
  hn->Fill(0.65-0.753);
  hn->Fill(0.7-0.806);
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
