#include <string>
#include <stdlib>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
void nonprompt(string rootfile){
  TFolder *fol2 = gROOT->GetRootFolder()->AddFolder("Output","Output");

  TFile *f1 = TFile::Open(rootfile.c_str());
  TFolder *fol = f1->Get("Electron");
  TFile *f2 = new TFile("nonprompt.root","Recreate");

  TH2D* h1 = fol->FindObject("Loose_Electrons_pt_eta");
  TH2D* h2 = fol->FindObject("Tight_Electrons_pt_eta");

  TH1D* h1x = h1->ProjectionX("Pt",0,-1,"ed"); 
  TH1D* h2x = h2->ProjectionX("Pt2",0,-1,"ed"); 
  TH1D* hdivx = new TH1D("Division","Division",100,0,500);
  TH2D* h3 = new TH2D("BigDiv","BigDiv",6,0,6,5,0,5); 

  TH1D* h1xe = h1->ProjectionY("Eta",0,-1,"ed"); 
  TH1D* h2xe = h2->ProjectionY("Eta2",0,-1,"ed"); 
  TH1D* hdivxe = new TH1D("EtaDivision","EtaDivision",24,-3,3);

  TH2D* h1pf = fol->FindObject("Loose_PFElectrons_pt_eta");
  TH2D* h2pf = fol->FindObject("Tight_PFElectrons_pt_eta");

  TH1D* h1xpf = h1pf->ProjectionX("pfPt",0,-1,"ed"); 
  TH1D* h2xpf = h2pf->ProjectionX("pfPt2",0,-1,"ed"); 
  TH1D* hdivxpf = new TH1D("PFDivision","PFDivision",100,0,500);
  TH2D* h3pf = new TH2D("pfBigDiv","pfBigDiv",6,0,6,5,0,5); 

  TH1D* h1xepf = h1pf->ProjectionY("pfEta",0,-1,"ed"); 
  TH1D* h2xepf = h2pf->ProjectionY("pfEta2",0,-1,"ed"); 
  TH1D* hdivxepf = new TH1D("pfEtaDivision","pfEtaDivision",24,-3,3);

  f2->cd();
  fol2->Add(h1);
  fol2->Add(h2);
  fol2->Add(h1x);
  fol2->Add(h2x);
  fol2->Add(hdivx);
  fol2->Add(h1xe);
  fol2->Add(h2xe);
  fol2->Add(hdivxe);
  fol2->Add(h3);
  fol2->Add(h1pf);
  fol2->Add(h2pf);
  fol2->Add(h1xpf);
  fol2->Add(h2xpf);
  fol2->Add(hdivxpf);
  fol2->Add(h1xepf);
  fol2->Add(h2xepf);
  fol2->Add(hdivxepf);
  fol2->Add(h3pf);

  float pn[6][5];
  float pd[6][5];
  for(int i =0; i < 6; i++){
    for(int l = 0; l < 5; l++){
      pn[i][l] = 0;
      pd[i][l] = 0;
    }
  }
  for(int i =1; i <= 100; i++){
    for(int l = 1; l <=24; l++){
      if(i==1){
	if(l <= 5 ){
	  pd[0][0]+=h1->GetBinContent(i,l);
	  pn[0][0]+=h2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[0][1]+=h1->GetBinContent(i,l);
	  pn[0][1]+=h2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[0][2]+=h1->GetBinContent(i,l);
	  pn[0][2]+=h2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[0][3]+=h1->GetBinContent(i,l);
	  pn[0][3]+=h2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[0][4]+=h1->GetBinContent(i,l);
	  pn[0][4]+=h2->GetBinContent(i,l);
	}
      }
      else if(i==2){
	if(l <= 5 ){
	  pd[1][0]+=h1->GetBinContent(i,l);
	  pn[1][0]+=h2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[1][1]+=h1->GetBinContent(i,l);
	  pn[1][1]+=h2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[1][2]+=h1->GetBinContent(i,l);
	  pn[1][2]+=h2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[1][3]+=h1->GetBinContent(i,l);
	  pn[1][3]+=h2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[1][4]+=h1->GetBinContent(i,l);
	  pn[1][4]+=h2->GetBinContent(i,l);
	}
      }
      else if(i==3 || i == 4){
	if(l <= 5 ){
	  pd[2][0]+=h1->GetBinContent(i,l);
	  pn[2][0]+=h2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[2][1]+=h1->GetBinContent(i,l);
	  pn[2][1]+=h2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[2][2]+=h1->GetBinContent(i,l);
	  pn[2][2]+=h2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[2][3]+=h1->GetBinContent(i,l);
	  pn[2][3]+=h2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[2][4]+=h1->GetBinContent(i,l);
	  pn[2][4]+=h2->GetBinContent(i,l);
	}
      }
      else if(i >= 5 && i <= 10 ){
	if(l <= 5 ){
	  pd[3][0]+=h1->GetBinContent(i,l);
	  pn[3][0]+=h2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[3][1]+=h1->GetBinContent(i,l);
	  pn[3][1]+=h2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[3][2]+=h1->GetBinContent(i,l);
	  pn[3][2]+=h2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[3][3]+=h1->GetBinContent(i,l);
	  pn[3][3]+=h2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[3][4]+=h1->GetBinContent(i,l);
	  pn[3][4]+=h2->GetBinContent(i,l);
	}
      }
      else if(i >= 11 && i <= 20 ){
	if(l <= 5 ){
	  pd[4][0]+=h1->GetBinContent(i,l);
	  pn[4][0]+=h2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[4][1]+=h1->GetBinContent(i,l);
	  pn[4][1]+=h2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[4][2]+=h1->GetBinContent(i,l);
	  pn[4][2]+=h2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[4][3]+=h1->GetBinContent(i,l);
	  pn[4][3]+=h2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[4][4]+=h1->GetBinContent(i,l);
	  pn[4][4]+=h2->GetBinContent(i,l);
	}
      }
      else if(i >= 21 && i <= 100 ){
	if(l <= 5 ){
	  pd[5][0]+=h1->GetBinContent(i,l);
	  pn[5][0]+=h2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[5][1]+=h1->GetBinContent(i,l);
	  pn[5][1]+=h2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[5][2]+=h1->GetBinContent(i,l);
	  pn[5][2]+=h2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[5][3]+=h1->GetBinContent(i,l);
	  pn[5][3]+=h2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[5][4]+=h1->GetBinContent(i,l);
	  pn[5][4]+=h2->GetBinContent(i,l);
	}
      }
    }
  }

  cout << "electron" << endl;
  for(int i=0; i < 6; i++ ){
    for(int l=0; l < 5; l++){
      if(pd[i][l] != 0 ){
	float p = (float)pn[i][l]/pd[i][l];
	float n = pn[i][l]+pd[i][l];
	cout << "bin " << i << ", " << l << ": " << p << " +- " << sqrt(p*(1-p)/n)  << endl;
	h3->SetBinContent(i+1,l+1,p);
	h3->SetBinError(i+1,l+1,sqrt(p*(1-p)/n));
      }
    }
  }

  for(int i =0; i < 6; i++){
    for(int l = 0; l < 5; l++){
      pn[i][l] = 0;
      pd[i][l] = 0;
    }
  }

  for(int i =1; i <= 100; i++){
    for(int l = 1; l <=24; l++){
      if(i==1){
	if(l <= 5 ){
	  pd[0][0]+=h1pf->GetBinContent(i,l);
	  pn[0][0]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[0][1]+=h1pf->GetBinContent(i,l);
	  pn[0][1]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[0][2]+=h1pf->GetBinContent(i,l);
	  pn[0][2]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[0][3]+=h1pf->GetBinContent(i,l);
	  pn[0][3]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[0][4]+=h1pf->GetBinContent(i,l);
	  pn[0][4]+=h2pf->GetBinContent(i,l);
	}
      }
      else if(i==2){
	if(l <= 5 ){
	  pd[1][0]+=h1pf->GetBinContent(i,l);
	  pn[1][0]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[1][1]+=h1pf->GetBinContent(i,l);
	  pn[1][1]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[1][2]+=h1pf->GetBinContent(i,l);
	  pn[1][2]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[1][3]+=h1pf->GetBinContent(i,l);
	  pn[1][3]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[1][4]+=h1pf->GetBinContent(i,l);
	  pn[1][4]+=h2pf->GetBinContent(i,l);
	}
      }
      else if(i==3 || i == 4){
	if(l <= 5 ){
	  pd[2][0]+=h1pf->GetBinContent(i,l);
	  pn[2][0]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[2][1]+=h1pf->GetBinContent(i,l);
	  pn[2][1]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[2][2]+=h1pf->GetBinContent(i,l);
	  pn[2][2]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[2][3]+=h1pf->GetBinContent(i,l);
	  pn[2][3]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[2][4]+=h1pf->GetBinContent(i,l);
	  pn[2][4]+=h2pf->GetBinContent(i,l);
	}
      }
      else if(i >= 5 && i <= 10 ){
	if(l <= 5 ){
	  pd[3][0]+=h1pf->GetBinContent(i,l);
	  pn[3][0]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[3][1]+=h1pf->GetBinContent(i,l);
	  pn[3][1]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[3][2]+=h1pf->GetBinContent(i,l);
	  pn[3][2]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[3][3]+=h1pf->GetBinContent(i,l);
	  pn[3][3]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[3][4]+=h1pf->GetBinContent(i,l);
	  pn[3][4]+=h2pf->GetBinContent(i,l);
	}
      }
      else if(i >= 11 && i <= 20 ){
	if(l <= 5 ){
	  pd[4][0]+=h1pf->GetBinContent(i,l);
	  pn[4][0]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[4][1]+=h1pf->GetBinContent(i,l);
	  pn[4][1]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[4][2]+=h1pf->GetBinContent(i,l);
	  pn[4][2]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[4][3]+=h1pf->GetBinContent(i,l);
	  pn[4][3]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[4][4]+=h1pf->GetBinContent(i,l);
	  pn[4][4]+=h2pf->GetBinContent(i,l);
	}
      }
      else if(i >= 21 && i <= 100 ){
	if(l <= 5 ){
	  pd[5][0]+=h1pf->GetBinContent(i,l);
	  pn[5][0]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[5][1]+=h1pf->GetBinContent(i,l);
	  pn[5][1]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[5][2]+=h1pf->GetBinContent(i,l);
	  pn[5][2]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[5][3]+=h1pf->GetBinContent(i,l);
	  pn[5][3]+=h2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[5][4]+=h1pf->GetBinContent(i,l);
	  pn[5][4]+=h2pf->GetBinContent(i,l);
	}
      }
    }
  }

  cout << "pf electron" << endl;
  for(int i=0; i < 6; i++ ){
    for(int l=0; l < 5; l++){
      if(pd[i][l] != 0 ){
	float p = (float)pn[i][l]/pd[i][l];
	float n = pn[i][l]+pd[i][l];
	cout << "bin " << i << ", " << l << ": " << p << " +- " << sqrt(p*(1-p)/n)  << endl;
	h3pf->SetBinContent(i+1,l+1,p);
	h3pf->SetBinError(i+1,l+1,sqrt(p*(1-p)/n));
      }
    }
  }

  hdivx->Divide(h2x,h1x,1,1,"B");
  hdivxpf->Divide(h2xpf,h1xpf,1,1,"B");
  hdivxe->Divide(h2xe,h1xe,1,1,"B");
  hdivxepf->Divide(h2xepf,h1xepf,1,1,"B");

  TCanvas *c1 = new TCanvas();

  hdivx->GetXaxis()->SetRangeUser(2,220);
  hdivx->Draw();
  c1->SaveAs("Ept_ToverL_electrons.jpg");

  hdivxpf->GetXaxis()->SetRangeUser(2,220);
  hdivxpf->Draw();
  c1->SaveAs("Ept_ToverL_pfelectrons.jpg");

  hdivxe->Draw();
  c1->SaveAs("Eeta_ToverL_electrons.jpg");

  hdivxepf->Draw();
  c1->SaveAs("Eeta_ToverL_pfelectrons.jpg");

  /////////////muons

  TFolder *fol1 = f1->Get("Muon");

  TH2D* j1 = fol1->FindObject("Loose_Muons_pt_eta");
  TH2D* j2 = fol1->FindObject("Tight_Muons_pt_eta");

  TH1D* j1x = j1->ProjectionX("mPt",0,-1,"ed"); 
  TH1D* j2x = j2->ProjectionX("mPt2",0,-1,"ed"); 
  TH1D* jdivx = new TH1D("mDivision","mDivision",100,0,500);
  TH2D* j3 = new TH2D("mBigDiv","mBigDiv",6,0,6,5,0,5); 

  TH1D* j1xe = j1->ProjectionY("mEta",0,-1,"ed"); 
  TH1D* j2xe = j2->ProjectionY("mEta2",0,-1,"ed"); 
  TH1D* jdivxe = new TH1D("mEtaDivision","mEtaDivision",24,-3,3);

  TH2D* j1pf = fol1->FindObject("Loose_PFMuons_pt_eta");
  TH2D* j2pf = fol1->FindObject("Tight_PFMuons_pt_eta");

  TH1D* j1xpf = j1pf->ProjectionX("mpfPt",0,-1,"ed"); 
  TH1D* j2xpf = j2pf->ProjectionX("mpfPt2",0,-1,"ed"); 
  TH1D* jdivxpf = new TH1D("mPFDivision","mPFDivision",100,0,500);
  TH2D* j3pf = new TH2D("pfmBigDiv","pfmBigDiv",6,0,6,5,0,5); 

  TH1D* j1xepf = j1pf->ProjectionY("mpfEta",0,-1,"ed"); 
  TH1D* j2xepf = j2pf->ProjectionY("mpfEta2",0,-1,"ed"); 
  TH1D* jdivxepf = new TH1D("mpfEtaDivision","mpfEtaDivision",24,-3,3);

  f2->cd();
  fol2->Add(j1);
  fol2->Add(j2);
  fol2->Add(j1x);
  fol2->Add(j2x);
  fol2->Add(jdivx);
  fol2->Add(j1xe);
  fol2->Add(j2xe);
  fol2->Add(jdivxe);
  fol2->Add(j3);
  fol2->Add(j1pf);
  fol2->Add(j2pf);
  fol2->Add(j1xpf);
  fol2->Add(j2xpf);
  fol2->Add(jdivxpf);
  fol2->Add(j1xepf);
  fol2->Add(j2xepf);
  fol2->Add(jdivxepf);
  fol2->Add(j3pf);


  float pn[6][5];
  float pd[6][5];
  for(int i =0; i < 6; i++){
    for(int l = 0; l < 5; l++){
      pn[i][l] = 0;
      pd[i][l] = 0;
    }
  }
  for(int i =1; i <= 100; i++){
    for(int l = 1; l <=24; l++){
      if(i==1){
	if(l <= 5 ){
	  pd[0][0]+=j1->GetBinContent(i,l);
	  pn[0][0]+=j2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[0][1]+=j1->GetBinContent(i,l);
	  pn[0][1]+=j2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[0][2]+=j1->GetBinContent(i,l);
	  pn[0][2]+=j2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[0][3]+=j1->GetBinContent(i,l);
	  pn[0][3]+=j2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[0][4]+=j1->GetBinContent(i,l);
	  pn[0][4]+=j2->GetBinContent(i,l);
	}
      }
      else if(i==2){
	if(l <= 5 ){
	  pd[1][0]+=j1->GetBinContent(i,l);
	  pn[1][0]+=j2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[1][1]+=j1->GetBinContent(i,l);
	  pn[1][1]+=j2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[1][2]+=j1->GetBinContent(i,l);
	  pn[1][2]+=j2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[1][3]+=j1->GetBinContent(i,l);
	  pn[1][3]+=j2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[1][4]+=j1->GetBinContent(i,l);
	  pn[1][4]+=j2->GetBinContent(i,l);
	}
      }
      else if(i==3 || i == 4){
	if(l <= 5 ){
	  pd[2][0]+=j1->GetBinContent(i,l);
	  pn[2][0]+=j2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[2][1]+=j1->GetBinContent(i,l);
	  pn[2][1]+=j2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[2][2]+=j1->GetBinContent(i,l);
	  pn[2][2]+=j2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[2][3]+=j1->GetBinContent(i,l);
	  pn[2][3]+=j2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[2][4]+=j1->GetBinContent(i,l);
	  pn[2][4]+=j2->GetBinContent(i,l);
	}
      }
      else if(i >= 5 && i <= 10 ){
	if(l <= 5 ){
	  pd[3][0]+=j1->GetBinContent(i,l);
	  pn[3][0]+=j2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[3][1]+=j1->GetBinContent(i,l);
	  pn[3][1]+=j2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[3][2]+=j1->GetBinContent(i,l);
	  pn[3][2]+=j2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[3][3]+=j1->GetBinContent(i,l);
	  pn[3][3]+=j2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[3][4]+=j1->GetBinContent(i,l);
	  pn[3][4]+=j2->GetBinContent(i,l);
	}
      }
      else if(i >= 11 && i <= 20 ){
	if(l <= 5 ){
	  pd[4][0]+=j1->GetBinContent(i,l);
	  pn[4][0]+=j2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[4][1]+=j1->GetBinContent(i,l);
	  pn[4][1]+=j2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[4][2]+=j1->GetBinContent(i,l);
	  pn[4][2]+=j2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[4][3]+=j1->GetBinContent(i,l);
	  pn[4][3]+=j2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[4][4]+=j1->GetBinContent(i,l);
	  pn[4][4]+=j2->GetBinContent(i,l);
	}
      }
      else if(i >= 21 && i <= 100 ){
	if(l <= 5 ){
	  pd[5][0]+=j1->GetBinContent(i,l);
	  pn[5][0]+=j2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[5][1]+=j1->GetBinContent(i,l);
	  pn[5][1]+=j2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[5][2]+=j1->GetBinContent(i,l);
	  pn[5][2]+=j2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[5][3]+=j1->GetBinContent(i,l);
	  pn[5][3]+=j2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[5][4]+=j1->GetBinContent(i,l);
	  pn[5][4]+=j2->GetBinContent(i,l);
	}
      }
    }
  }

  cout << "muon" << endl;
  for(int i=0; i < 6; i++ ){
    for(int l=0; l < 5; l++){
      if(pd[i][l] != 0 ){
	float p = (float)pn[i][l]/pd[i][l];
	float n = pn[i][l]+pd[i][l];
	cout << "bin " << i << ", " << l << ": " << p << " +- " << sqrt(p*(1-p)/n)  << endl;
	j3->SetBinContent(i+1,l+1,p);
	j3->SetBinError(i+1,l+1,sqrt(p*(1-p)/n));
      }
    }
  }

  for(int i =0; i < 6; i++){
    for(int l = 0; l < 5; l++){
      pn[i][l] = 0;
      pd[i][l] = 0;
    }
  }

  for(int i =1; i <= 100; i++){
    for(int l = 1; l <=24; l++){
      if(i==1){
	if(l <= 5 ){
	  pd[0][0]+=j1pf->GetBinContent(i,l);
	  pn[0][0]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[0][1]+=j1pf->GetBinContent(i,l);
	  pn[0][1]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[0][2]+=j1pf->GetBinContent(i,l);
	  pn[0][2]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[0][3]+=j1pf->GetBinContent(i,l);
	  pn[0][3]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[0][4]+=j1pf->GetBinContent(i,l);
	  pn[0][4]+=j2pf->GetBinContent(i,l);
	}
      }
      else if(i==2){
	if(l <= 5 ){
	  pd[1][0]+=j1pf->GetBinContent(i,l);
	  pn[1][0]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[1][1]+=j1pf->GetBinContent(i,l);
	  pn[1][1]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[1][2]+=j1pf->GetBinContent(i,l);
	  pn[1][2]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[1][3]+=j1pf->GetBinContent(i,l);
	  pn[1][3]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[1][4]+=j1pf->GetBinContent(i,l);
	  pn[1][4]+=j2pf->GetBinContent(i,l);
	}
      }
      else if(i==3 || i == 4){
	if(l <= 5 ){
	  pd[2][0]+=j1pf->GetBinContent(i,l);
	  pn[2][0]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[2][1]+=j1pf->GetBinContent(i,l);
	  pn[2][1]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[2][2]+=j1pf->GetBinContent(i,l);
	  pn[2][2]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[2][3]+=j1pf->GetBinContent(i,l);
	  pn[2][3]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[2][4]+=j1pf->GetBinContent(i,l);
	  pn[2][4]+=j2pf->GetBinContent(i,l);
	}
      }
      else if(i >= 5 && i <= 10 ){
	if(l <= 5 ){
	  pd[3][0]+=j1pf->GetBinContent(i,l);
	  pn[3][0]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[3][1]+=j1pf->GetBinContent(i,l);
	  pn[3][1]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[3][2]+=j1pf->GetBinContent(i,l);
	  pn[3][2]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[3][3]+=j1pf->GetBinContent(i,l);
	  pn[3][3]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[3][4]+=j1pf->GetBinContent(i,l);
	  pn[3][4]+=j2pf->GetBinContent(i,l);
	}
      }
      else if(i >= 11 && i <= 20 ){
	if(l <= 5 ){
	  pd[4][0]+=j1pf->GetBinContent(i,l);
	  pn[4][0]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[4][1]+=j1pf->GetBinContent(i,l);
	  pn[4][1]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[4][2]+=j1pf->GetBinContent(i,l);
	  pn[4][2]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[4][3]+=j1pf->GetBinContent(i,l);
	  pn[4][3]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[4][4]+=j1pf->GetBinContent(i,l);
	  pn[4][4]+=j2pf->GetBinContent(i,l);
	}
      }
      else if(i >= 21 && i <= 100 ){
	if(l <= 5 ){
	  pd[5][0]+=j1pf->GetBinContent(i,l);
	  pn[5][0]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[5][1]+=j1pf->GetBinContent(i,l);
	  pn[5][1]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[5][2]+=j1pf->GetBinContent(i,l);
	  pn[5][2]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[5][3]+=j1pf->GetBinContent(i,l);
	  pn[5][3]+=j2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[5][4]+=j1pf->GetBinContent(i,l);
	  pn[5][4]+=j2pf->GetBinContent(i,l);
	}
      }
    }
  }

  cout << "pf muon" << endl;
  for(int i=0; i < 6; i++ ){
    for(int l=0; l < 5; l++){
      if(pd[i][l] != 0 ){
	float p = (float)pn[i][l]/pd[i][l];
	float n = pn[i][l]+pd[i][l];
	cout << "bin " << i << ", " << l << ": " << p << " +- " << sqrt(p*(1-p)/n)  << endl;
	j3pf->SetBinContent(i+1,l+1,p);
	j3pf->SetBinError(i+1,l+1,sqrt(p*(1-p)/n));
      }
    }
  }

  jdivx->Divide(j2x,j1x,1,1,"B");
  jdivxpf->Divide(j2xpf,j1xpf,1,1,"B");
  jdivxe->Divide(j2xe,j1xe,1,1,"B");
  jdivxepf->Divide(j2xepf,j1xepf,1,1,"B");

  jdivx->GetXaxis()->SetRangeUser(2,220);
  jdivx->Draw();
  c1->SaveAs("Ept_ToverL_muons.jpg");

  jdivxpf->GetXaxis()->SetRangeUser(2,220);
  jdivxpf->Draw();
  c1->SaveAs("Ept_ToverL_pfmuons.jpg");

  jdivxe->Draw();
  c1->SaveAs("Eeta_ToverL_muons.jpg");

  jdivxepf->Draw();
  c1->SaveAs("Eeta_ToverL_pfmuons.jpg");

  /////////////taus

  TFolder *fol3 = f1->Get("Tau");

  TH2D* k1 = fol3->FindObject("Loose_Tau_pt_eta");
  TH2D* k2 = fol3->FindObject("Tight_Tau_pt_eta");

  TH1D* k1x = k1->ProjectionX("tPt",0,-1,"ed"); 
  TH1D* k2x = k2->ProjectionX("tPt2",0,-1,"ed"); 
  TH1D* kdivx = new TH1D("tDivision","tDivision",100,0,500);
  TH2D* k3 = new TH2D("tBigDiv","tBigDiv",6,0,6,5,0,5); 

  TH1D* k1xe = k1->ProjectionY("tEta",0,-1,"ed"); 
  TH1D* k2xe = k2->ProjectionY("tEta2",0,-1,"ed"); 
  TH1D* kdivxe = new TH1D("tEtaDivision","tEtaDivision",24,-3,3);

  TH2D* k1pf = fol3->FindObject("Loose_PFTau_pt_eta");
  TH2D* k2pf = fol3->FindObject("Tight_PFTau_pt_eta");

  TH1D* k1xpf = k1pf->ProjectionX("tpfPt",0,-1,"ed"); 
  TH1D* k2xpf = k2pf->ProjectionX("tpfPt2",0,-1,"ed"); 
  TH1D* kdivxpf = new TH1D("tPFDivision","tPFDivision",100,0,500);
  TH2D* k3pf = new TH2D("tpfBigDiv","tpfBigDiv",6,0,6,5,0,5); 

  TH1D* k1xepf = k1pf->ProjectionY("tpfEta",0,-1,"ed"); 
  TH1D* k2xepf = k2pf->ProjectionY("tpfEta2",0,-1,"ed"); 
  TH1D* kdivxepf = new TH1D("tpfEtaDivision","tpfEtaDivision",24,-3,3);

  f2->cd();
  fol2->Add(k1);
  fol2->Add(k2);
  fol2->Add(k1x);
  fol2->Add(k2x);
  fol2->Add(kdivx);
  fol2->Add(k1xe);
  fol2->Add(k2xe);
  fol2->Add(kdivxe);
  fol2->Add(k3);
  fol2->Add(k1pf);
  fol2->Add(k2pf);
  fol2->Add(k1xpf);
  fol2->Add(k2xpf);
  fol2->Add(kdivxpf);
  fol2->Add(k1xepf);
  fol2->Add(k2xepf);
  fol2->Add(kdivxepf);
  fol2->Add(k3pf);

  for(int i =0; i < 6; i++){
    for(int l = 0; l < 5; l++){
      pn[i][l] = 0;
      pd[i][l] = 0;
    }
  }

  for(int i =1; i <= 100; i++){
    for(int l = 1; l <=24; l++){
      if(i==1){
	if(l <= 5 ){
	  pd[0][0]+=k1->GetBinContent(i,l);
	  pn[0][0]+=k2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[0][1]+=k1->GetBinContent(i,l);
	  pn[0][1]+=k2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[0][2]+=k1->GetBinContent(i,l);
	  pn[0][2]+=k2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[0][3]+=k1->GetBinContent(i,l);
	  pn[0][3]+=k2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[0][4]+=k1->GetBinContent(i,l);
	  pn[0][4]+=k2->GetBinContent(i,l);
	}
      }
      else if(i==2){
	if(l <= 5 ){
	  pd[1][0]+=k1->GetBinContent(i,l);
	  pn[1][0]+=k2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[1][1]+=k1->GetBinContent(i,l);
	  pn[1][1]+=k2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[1][2]+=k1->GetBinContent(i,l);
	  pn[1][2]+=k2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[1][3]+=k1->GetBinContent(i,l);
	  pn[1][3]+=k2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[1][4]+=k1->GetBinContent(i,l);
	  pn[1][4]+=k2->GetBinContent(i,l);
	}
      }
      else if(i==3 || i == 4){
	if(l <= 5 ){
	  pd[2][0]+=k1->GetBinContent(i,l);
	  pn[2][0]+=k2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[2][1]+=k1->GetBinContent(i,l);
	  pn[2][1]+=k2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[2][2]+=k1->GetBinContent(i,l);
	  pn[2][2]+=k2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[2][3]+=k1->GetBinContent(i,l);
	  pn[2][3]+=k2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[2][4]+=k1->GetBinContent(i,l);
	  pn[2][4]+=k2->GetBinContent(i,l);
	}
      }
      else if(i >= 5 && i <= 10 ){
	if(l <= 5 ){
	  pd[3][0]+=k1->GetBinContent(i,l);
	  pn[3][0]+=k2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[3][1]+=k1->GetBinContent(i,l);
	  pn[3][1]+=k2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[3][2]+=k1->GetBinContent(i,l);
	  pn[3][2]+=k2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[3][3]+=k1->GetBinContent(i,l);
	  pn[3][3]+=k2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[3][4]+=k1->GetBinContent(i,l);
	  pn[3][4]+=k2->GetBinContent(i,l);
	}
      }
      else if(i >= 11 && i <= 20 ){
	if(l <= 5 ){
	  pd[4][0]+=k1->GetBinContent(i,l);
	  pn[4][0]+=k2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[4][1]+=k1->GetBinContent(i,l);
	  pn[4][1]+=k2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[4][2]+=k1->GetBinContent(i,l);
	  pn[4][2]+=k2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[4][3]+=k1->GetBinContent(i,l);
	  pn[4][3]+=k2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[4][4]+=k1->GetBinContent(i,l);
	  pn[4][4]+=k2->GetBinContent(i,l);
	}
      }
      else if(i >= 21 && i <= 100 ){
	if(l <= 5 ){
	  pd[5][0]+=k1->GetBinContent(i,l);
	  pn[5][0]+=k2->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[5][1]+=k1->GetBinContent(i,l);
	  pn[5][1]+=k2->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[5][2]+=k1->GetBinContent(i,l);
	  pn[5][2]+=k2->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[5][3]+=k1->GetBinContent(i,l);
	  pn[5][3]+=k2->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[5][4]+=k1->GetBinContent(i,l);
	  pn[5][4]+=k2->GetBinContent(i,l);
	}
      }
    }
  }
  cout << "tau" << endl;
  for(int i=0; i < 6; i++ ){
    for(int l=0; l < 5; l++){
      if(pd[i][l] != 0 ){
	float p = (float)pn[i][l]/pd[i][l];
	float n = pn[i][l]+pd[i][l];
	cout << "bin " << i << ", " << l << ": " << p << " +- " << sqrt(p*(1-p)/n)  << endl;
	k3->SetBinContent(i+1,l+1,p);
	k3->SetBinError(i+1,l+1,sqrt(p*(1-p)/n));
      }
    }
  }

  for(int i =0; i < 6; i++){
    for(int l = 0; l < 5; l++){
      pn[i][l] = 0;
      pd[i][l] = 0;
    }
  }

  for(int i =1; i <= 100; i++){
    for(int l = 1; l <=24; l++){
      if(i==1){
	if(l <= 5 ){
	  pd[0][0]+=k1pf->GetBinContent(i,l);
	  pn[0][0]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[0][1]+=k1pf->GetBinContent(i,l);
	  pn[0][1]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[0][2]+=k1pf->GetBinContent(i,l);
	  pn[0][2]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[0][3]+=k1pf->GetBinContent(i,l);
	  pn[0][3]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[0][4]+=k1pf->GetBinContent(i,l);
	  pn[0][4]+=k2pf->GetBinContent(i,l);
	}
      }
      else if(i==2){
	if(l <= 5 ){
	  pd[1][0]+=k1pf->GetBinContent(i,l);
	  pn[1][0]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[1][1]+=k1pf->GetBinContent(i,l);
	  pn[1][1]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[1][2]+=k1pf->GetBinContent(i,l);
	  pn[1][2]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[1][3]+=k1pf->GetBinContent(i,l);
	  pn[1][3]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[1][4]+=k1pf->GetBinContent(i,l);
	  pn[1][4]+=k2pf->GetBinContent(i,l);
	}
      }
      else if(i==3 || i == 4){
	if(l <= 5 ){
	  pd[2][0]+=k1pf->GetBinContent(i,l);
	  pn[2][0]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[2][1]+=k1pf->GetBinContent(i,l);
	  pn[2][1]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[2][2]+=k1pf->GetBinContent(i,l);
	  pn[2][2]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[2][3]+=k1pf->GetBinContent(i,l);
	  pn[2][3]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[2][4]+=k1pf->GetBinContent(i,l);
	  pn[2][4]+=k2pf->GetBinContent(i,l);
	}
      }
      else if(i >= 5 && i <= 10 ){
	if(l <= 5 ){
	  pd[3][0]+=k1pf->GetBinContent(i,l);
	  pn[3][0]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[3][1]+=k1pf->GetBinContent(i,l);
	  pn[3][1]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[3][2]+=k1pf->GetBinContent(i,l);
	  pn[3][2]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[3][3]+=k1pf->GetBinContent(i,l);
	  pn[3][3]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[3][4]+=k1pf->GetBinContent(i,l);
	  pn[3][4]+=k2pf->GetBinContent(i,l);
	}
      }
      else if(i >= 11 && i <= 20 ){
	if(l <= 5 ){
	  pd[4][0]+=k1pf->GetBinContent(i,l);
	  pn[4][0]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[4][1]+=k1pf->GetBinContent(i,l);
	  pn[4][1]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[4][2]+=k1pf->GetBinContent(i,l);
	  pn[4][2]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[4][3]+=k1pf->GetBinContent(i,l);
	  pn[4][3]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[4][4]+=k1pf->GetBinContent(i,l);
	  pn[4][4]+=k2pf->GetBinContent(i,l);
	}
      }
      else if(i >= 21 && i <= 100 ){
	if(l <= 5 ){
	  pd[5][0]+=k1pf->GetBinContent(i,l);
	  pn[5][0]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 7 ){
	  pd[5][1]+=k1pf->GetBinContent(i,l);
	  pn[5][1]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 17 ){
	  pd[5][2]+=k1pf->GetBinContent(i,l);
	  pn[5][2]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 19 ){
	  pd[5][3]+=k1pf->GetBinContent(i,l);
	  pn[5][3]+=k2pf->GetBinContent(i,l);
	}
	else if( l <= 24 ){
	  pd[5][4]+=k1pf->GetBinContent(i,l);
	  pn[5][4]+=k2pf->GetBinContent(i,l);
	}
      }
    }
  }

  cout << "pf tau" << endl;
  for(int i=0; i < 6; i++ ){
    for(int l=0; l < 5; l++){
      if(pd[i][l] != 0 ){
	float p = (float)pn[i][l]/pd[i][l];
	float n = pn[i][l]+pd[i][l];
	cout << "bin " << i << ", " << l << ": " << p << " +- " << sqrt(p*(1-p)/n)  << endl;
	k3pf->SetBinContent(i+1,l+1,p);
	k3pf->SetBinError(i+1,l+1,sqrt(p*(1-p)/n));
      }
    }
  }

  kdivx->Divide(k2x,k1x,1,1,"B");
  kdivxpf->Divide(k2xpf,k1xpf,1,1,"B");
  kdivxe->Divide(k2xe,k1xe,1,1,"B");
  kdivxepf->Divide(k2xepf,k1xepf,1,1,"B");

  kdivx->GetXaxis()->SetRangeUser(2,220);
  kdivx->Draw();
  c1->SaveAs("Ept_ToverL_tau.jpg");

  kdivxpf->GetXaxis()->SetRangeUser(2,220);
  kdivxpf->Draw();
  c1->SaveAs("Ept_ToverL_pftau.jpg");

  kdivxe->Draw();
  c1->SaveAs("Eeta_ToverL_tau.jpg");

  kdivxepf->Draw();
  c1->SaveAs("Eeta_ToverL_pftau.jpg");

  h3->Draw("COLZ");
  f1->Close();

  f2->cd();
  fol2->Write();
  f2->Close();
}
