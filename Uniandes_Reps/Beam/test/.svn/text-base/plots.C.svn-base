void plots(){
  
  TFile* file = new TFile("Time_analysis_63050.root");
  TFile* file_0 = new TFile("RPCEvoOccupancies_BeamHalo_62815.root");
  //  TH1F *tmpw1 = new TH1F("tmpw2","HV scan",500000,0,535000);
  TH1F* tmp1 = (TH1F *) file->Get("Barrel_digis_vs_event");
  tmp1->SetLineColor(kRed);
  TH1F* tmp2 = (TH1F *) file->Get("Endcap_digis_vs_event");
  tmp2->SetLineColor(kBlue);
  TH1F* tmp3 = (TH1F *) file->Get("Barrel_Endcap_digis_vs_event");
  tmp3->SetLineColor(kGreen);
  TH1F* tmp4 = (TH1F *) file_0->Get("totalBarrelOcc");
  tmp4->SetLineColor(kGreen);
  TH1F* tmp5 = (TH1F *) file_0->Get("totalForwardOcc");
  tmp5->SetLineColor(kRed);
  TH1F* tmp6 = (TH1F *) file_0->Get("totalOcc");
  tmp6->SetLineColor(kBlue);
  TCanvas *c1 = new TCanvas("c1","c1",1600,750);
  c1->Divide(3,2);
  c1->cd(1);
  tmp1->Draw();
  c1->cd(2);
  tmp2->Draw();
  c1->cd(3);
  tmp3->Draw();
  c1->cd(4);
  tmp4->Draw();
  c1->cd(5);
  tmp5->Draw();
  c1->cd(6);
  tmp6->Draw();
  


}
