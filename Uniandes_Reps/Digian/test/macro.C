void macro(){
  TFile* file = new TFile("Bx.root");
  TFile* file_0 = new TFile("test/Bx.root");
  
  TH1F* tmp1 = (TH1F *) file->Get("Digis_per_Event");
  tmp1->SetLineColor(kRed);
  TH1F* tmp2 = (TH1F *) file_0->Get("Digis_per_Event");
  tmp2->SetLineColor(kBlue);

  TCanvas *c1 = new TCanvas("c1","c1",1600,750);
  c1->Divide(2,1);
  c1->cd(1);
  tmp1->Draw();
  c1->cd(2);
  tmp2->Draw();
}
