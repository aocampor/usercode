void plots(){
  TFile* file = new TFile("tt_copy.root");
  TH1D* tmp1;
  file->GetObjectAny("/reconstructions/caloZMassRecophi",tmp1);
  TCanvas *c1 = new TCanvas("c1","c1");
  tmp1->Draw();

}
