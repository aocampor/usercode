{

  gStyle->SetOptStat(0);
  TFile *_file0 = TFile::Open("iso.root");
  TLegend *tl = new TLegend(0.6,0.5,0.99,0.9);
  TCanvas *c3= new TCanvas("c3","c3",1000,300);
  c3->Divide(3,1);
  c3->cd(1);
  GoodCharge0->Draw();
  GoodCharge0->SetMinimum(0);
  GoodCharge0->SetMaximum(50);
  GoodCharge0->SetTitle("|#eta|<0.8");
  GoodCharge0->GetXaxis()->SetTitle("M(ee) GeV");
  GoodCharge0->GetYaxis()->SetTitle("Events / 2 GeV");
  WrongCharge0->SetLineColor(4);
  WrongCharge_maj0->SetLineColor(2);
  WrongCharge_three0->SetLineColor(3);
  WrongCharge0->Draw("same");
  WrongCharge_maj0->Draw("same"); 
  WrongCharge_three0->Draw("same"); 
  tl->AddEntry(GoodCharge0,"All combination","l");
  tl->AddEntry(WrongCharge0,"SS (only GSF)","l");
  tl->AddEntry(WrongCharge_maj0,"SS (majority)","l");
  tl->AddEntry(WrongCharge_three0,"SS (GSF==KF==SC)","l");
  tl->Draw();
  c3->cd(2);
  GoodCharge1->Draw();
  GoodCharge1->SetMinimum(0);
  GoodCharge1->SetMaximum(50);
  GoodCharge1->SetTitle("0.8<|#eta|<1.6");
  GoodCharge1->GetXaxis()->SetTitle("M(ee) GeV");
  GoodCharge1->GetYaxis()->SetTitle("Events / 2 GeV");
  WrongCharge1->SetLineColor(4);
  WrongCharge_maj1->SetLineColor(2);
  WrongCharge_three1->SetLineColor(3);
  WrongCharge1->Draw("same");
  WrongCharge_maj1->Draw("same"); 
  WrongCharge_three1->Draw("same"); 

  c3->cd(3);
  GoodCharge2->Draw();
  GoodCharge2->SetMinimum(0);
  GoodCharge2->SetMaximum(50);
  GoodCharge2->SetTitle("1.6<|#eta|<2.4");
  GoodCharge2->GetXaxis()->SetTitle("M(ee) GeV");
  GoodCharge2->GetYaxis()->SetTitle("Events / 2 GeV");
  WrongCharge2->SetLineColor(4);
  WrongCharge_maj2->SetLineColor(2);
  WrongCharge_three2->SetLineColor(3);
  WrongCharge2->Draw("same");
  WrongCharge_maj2->Draw("same"); 
  WrongCharge_three2->Draw("same"); 
  
}
