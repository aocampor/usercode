#define EfficiencyFromZ_cxx
#include "EfficiencyFromZ.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TString.h>
#include <stdio.h>
#include <stdlib.h>
void EfficiencyFromZ::Loop()
{
  TFile *hfile;
  if(sc_)hfile = new TFile("gsf.root","RECREATE","Tracking Efficiency");
  else hfile =  new TFile("../../root_files/iso_data.root","RECREATE","Identification Efficiency");

  TH1F *PosMassEta[3];
  TH1F *EleMassEta[3];
  TH1F *SelPosMassEta[3];
  TH1F *SelEleMassEta[3];

 
  TH1F *GoodCharge[3];
  TH1F *WrongCharge[3];
  TH1F *WrongCharge_maj[3];   
  TH1F *WrongCharge_three[3];    
  TH1F *GoodElPt;
  TH1F *WrongElPt;
  TH1F *GoodElEta;
  TH1F *WrongElEta;
  TH1F *GoodElPt_b[3];
  TH1F *WrongElPt_b[3];
  TH1F *GoodElEta_b[5];
  TH1F *WrongElEta_b[5];
  TH2F *GoodEl2D;
  TH2F *WrongEl2D;

  TH1F *GoodElPt_ses;
  TH1F *WrongElPt_ses;
  TH1F *GoodElEta_ses;
  TH1F *WrongElEta_ses;
  TH1F *GoodElPt_ses_b[3];
  TH1F *WrongElPt_ses_b[3];
  TH1F *GoodElEta_ses_b[5];
  TH1F *WrongElEta_ses_b[5];
  TH2F *GoodEl2D_ses;
  TH2F *WrongEl2D_ses;
  
  TString suff[6]={"0","1","2","3","4","5"};

  GoodElPt =  new TH1F("GoodElPt","Well Reconstructed Electrons in pt",5,0,5);
  WrongElPt =  new TH1F("WrongElPt","Bad Reconstructed Electrons in pt",5,0,5);
  GoodElEta =  new TH1F("GoodElEta","Well Reconstructed Electrons in Eta",3,0,3);
  WrongElEta =  new TH1F("WrongElEta","Bad Reconstructed Electrons in Eta",3,0,3);
  GoodEl2D =  new TH2F("GoodEl2D","Well Reconstructed Electrons in pt, Eta",5,0,5,3,0,3);
  WrongEl2D =  new TH2F("WrongEl2D","Bad Reconstructed Electrons in pt, Eta",5,0,5,3,0,3);

  GoodElPt_ses =  new TH1F("GoodElPt_ses","Well Reconstructed Electrons in pt",5,0,5);
  WrongElPt_ses =  new TH1F("WrongElPt_ses","Bad Reconstructed Electrons in pt",5,0,5);
  GoodElEta_ses =  new TH1F("GoodElEta_ses","Well Reconstructed Electrons in Eta",3,0,3);
  WrongElEta_ses =  new TH1F("WrongElEta_ses","Bad Reconstructed Electrons in Eta",3,0,3);
  GoodEl2D_ses =  new TH2F("GoodEl2D_ses","Well Reconstructed Electrons in pt, Eta",5,0,5,3,0,3);
  WrongEl2D_ses =  new TH2F("WrongEl2D_ses","Bad Reconstructed Electrons in pt, Eta",5,0,5,3,0,3);

  TString tit = "";
  for(int i=0;i<3;i++){
    tit = "Good_El_Pt_in_eta_bin_"+suff[i+1];
    GoodElPt_b[i] = new TH1F(tit,tit,5,0,5);
    tit = "Wrong_El_Pt_in_eta_bin_"+suff[i+1];
    WrongElPt_b[i] = new TH1F(tit,tit,5,0,5);
    tit = "Good_El_Pt_ses_in_eta_bin_"+suff[i+1];
    GoodElPt_ses_b[i] = new TH1F(tit,tit,5,0,5);
    tit = "Wrong_El_Pt_ses_in_eta_bin_"+suff[i+1];
    WrongElPt_ses_b[i] = new TH1F(tit,tit,5,0,5);

  }
  for(int i=0;i<5;i++){
    tit = "Good_El_Eta_in_pt_bin_"+suff[i+1];
    GoodElEta_b[i] = new TH1F(tit,tit,3,0,3);
    tit = "Wrong_El_Eta_in_pt_bin_"+suff[i+1];
    WrongElEta_b[i] = new TH1F(tit,tit,3,0,3);
    tit = "Good_El_ses_Eta_in_pt_bin_"+suff[i+1];
    GoodElEta_ses_b[i] = new TH1F(tit,tit,3,0,3);
    tit = "Wrong_El_ses_Eta_in_pt_bin_"+suff[i+1];
    WrongElEta_ses_b[i] = new TH1F(tit,tit,3,0,3);
  }
  for (int  iMass=0; iMass<3;iMass++){
    TString pme="PosMassEta"+suff[iMass];
    PosMassEta[iMass]=new TH1F(pme,pme,60,60,120);
    TString spme="SelPosMassEta"+suff[iMass];
    SelPosMassEta[iMass]=new TH1F(spme,spme,60,60,120);
    TString eme="EleMassEta"+suff[iMass];
    EleMassEta[iMass]=new TH1F(eme,eme,60,60,120);
    TString seme="SelEleMassEta"+suff[iMass];
    SelEleMassEta[iMass]=new TH1F(seme,seme,60,60,120);
    if  (!sc_) {
      TString gc="GoodCharge"+suff[iMass];
      GoodCharge[iMass]=new TH1F(gc,gc,30,60,120);
      TString wc="WrongCharge"+suff[iMass];
      WrongCharge[iMass]=new TH1F(wc,wc,30,60,120);
      TString wc_maj="WrongCharge_maj"+suff[iMass];
      WrongCharge_maj[iMass]=new TH1F(wc_maj,wc_maj,30,60,120);
      TString wc_three="WrongCharge_three"+suff[iMass];
      WrongCharge_three[iMass]=new TH1F(wc_three,wc_three,30,60,120);   
    }
  }
  if (fChain == 0) return;
  cout<<"OK" <<endl;
  Long64_t nentries = fChain->GetEntriesFast();
  
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    
    if ( sc_ && probe_sc_et<20) continue;
    if (sc_ && fabs(probe_sc_eta)>2.4)continue;
    if (fabs(probe_sc_eta)>1.44 && fabs(probe_sc_eta)<1.56) continue;
    if (!sc_ && probe_gsfEle_et<20) continue;
    if (!sc_ && fabs(probe_gsfEle_eta)>2.4)continue;
    int ib=(sc_) ? int(fabs(probe_sc_eta)/0.8):
      int(fabs(probe_gsfEle_eta)/0.8);

    int ibpt;
    if(probe_gsfEle_pt >= 5 && probe_gsfEle_pt < 10 )
      ibpt = 0;
    else if(probe_gsfEle_pt >= 10 && probe_gsfEle_pt < 20)
      ibpt =1;
    else if(probe_gsfEle_pt >= 20 && probe_gsfEle_pt < 40)
      ibpt = 2;
    else if(probe_gsfEle_pt >= 40 && probe_gsfEle_pt < 70)
      ibpt = 3;
    else if(probe_gsfEle_pt >= 70)
      ibpt = 4;
  
    bool elsel = false;
    float iso = (probe_gsfEle_ecaliso_dr04 + probe_gsfEle_hcaliso_dr04 + probe_gsfEle_trackiso_dr04)/probe_gsfEle_pt; 
    bool vbtf80 = false;
    if( probe_gsfEle_isEB == 1 && probe_sigmaietaieta < 0.01 && probe_dphi < 0.06 && probe_deta < 0.004 && probe_hovere < 0.04)
      vbtf80 = true;
    if( probe_gsfEle_isEE == 1 && probe_sigmaietaieta < 0.03 && probe_dphi < 0.03 && probe_deta < 0.007 && probe_hovere < 0.025)
      vbtf80 = true;
    if( probe_gsfEle_pt > 20 && iso < 0.1 && vbtf80 && fabs(probe_gsfEle_eta) < 2.5 && probe_nmisshits == 0 && probe_dcot < 0.02 && probe_dist < 0.02)
      elsel = true;

    if (tag_gsfEle_charge>0){
      EleMassEta[ib]->Fill(pair_mass);
      if(sc_){

	if (probe_passing)  SelEleMassEta[ib]->Fill(pair_mass);}
      else{
	//	cout<<"WWW "<<tag_gsfEle_deltaPhi<<" "<<tag_gsfEle_bremFraction<<endl;
	bool chargeok=(probe_gsfcharge==probe_kfcharge)&&(probe_gsfcharge==probe_sccharge);
	bool convok= (probe_nmisshits<=1) &&( fabs(probe_dcot)>0.02 ||  fabs(probe_dist)>0.02) ;
	if (probe_passingALL && chargeok){
	  SelEleMassEta[ib]->Fill(pair_mass);
	}
	if (fabs(tag_gsfEle_eta)<1.0  &&fabs(tag_gsfEle_deltaPhi)<0.01 && tag_gsfEle_bremFraction<0.3 && convok && probe_passing){
	  GoodCharge[ib]->Fill(pair_mass);
	  GoodElPt_ses->Fill(ibpt,1);
	  GoodElEta_ses->Fill(ib,1);
	  GoodElPt_ses_b[ib]->Fill(ibpt);
	  GoodElEta_ses_b[ibpt]->Fill(ib);
	  GoodEl2D_ses->Fill(ibpt,ib,1);
 	  if (tag_gsfEle_charge*probe_gsfcharge>0){
	    WrongCharge[ib]->Fill(pair_mass);
	    WrongElPt_ses->Fill(ibpt,1);
	    WrongElEta_ses->Fill(ib,1);
	    WrongEl2D_ses->Fill(ibpt,ib,1);
	    WrongElPt_ses_b[ib]->Fill(ibpt);
	    WrongElEta_ses_b[ibpt]->Fill(ib);
	  }
 	  if (chargeok && elsel && (tag_gsfEle_charge*probe_gsfcharge>0)){
	    WrongCharge_three[ib]->Fill(pair_mass);
	    WrongElPt->Fill(ibpt,1);
	    WrongElEta->Fill(ib,1);
	    WrongEl2D->Fill(ibpt,ib,1);
	    WrongElPt_b[ib]->Fill(ibpt);
	    WrongElEta_b[ibpt]->Fill(ib);
	  }
	  if( chargeok && elsel){
	    GoodElPt->Fill(ibpt,1);
	    GoodElEta->Fill(ib,1);
	    GoodElPt_b[ib]->Fill(ibpt);
	    GoodElEta_b[ibpt]->Fill(ib);
	    GoodEl2D->Fill(ibpt,ib,1);
	  }
 	  float majch=(probe_gsfcharge+probe_kfcharge+probe_sccharge);
 	  if (tag_gsfEle_charge*majch>0)  WrongCharge_maj[ib]->Fill(pair_mass);

	}
      }
    }
    if (tag_gsfEle_charge<0){
      PosMassEta[ib]->Fill(pair_mass); 
      if(sc_){
	if (probe_passing) SelPosMassEta[ib]->Fill(pair_mass);}
      else{
	bool chargeok=(probe_gsfcharge==probe_kfcharge)&&(probe_gsfcharge==probe_sccharge);
	bool convok= (probe_nmisshits<=1) &&( fabs(probe_dcot)>0.02 ||  fabs(probe_dist)>0.02) ;
	if (probe_passingALL && chargeok ){
	  SelPosMassEta[ib]->Fill(pair_mass);
	}
	if (fabs(tag_gsfEle_eta)<1.0  &&fabs(tag_gsfEle_deltaPhi)<0.01 && tag_gsfEle_bremFraction<0.3 && convok && probe_passing){
	  GoodCharge[ib]->Fill(pair_mass);
	  GoodElPt_ses->Fill(ibpt,1);
	  GoodElEta_ses->Fill(ib,1);
	  GoodElPt_ses_b[ib]->Fill(ibpt);
	  GoodElEta_ses_b[ibpt]->Fill(ib);
	  GoodEl2D_ses->Fill(ibpt,ib,1);
 	  if (tag_gsfEle_charge*probe_gsfcharge>0){
	    WrongCharge[ib]->Fill(pair_mass);
	    WrongElPt_ses->Fill(ibpt,1);
	    WrongElEta_ses->Fill(ib,1);
	    WrongEl2D_ses->Fill(ibpt,ib,1);
	    WrongElPt_ses_b[ib]->Fill(ibpt);
	    WrongElEta_ses_b[ibpt]->Fill(ib);
	  }
 	  if ((chargeok) && (tag_gsfEle_charge*probe_gsfcharge>0)){
	    WrongCharge_three[ib]->Fill(pair_mass);
	    WrongElPt->Fill(ibpt,1);
	    WrongElEta->Fill(ib,1);
	    WrongEl2D->Fill(ibpt,ib,1);
	    WrongElPt_b[ib]->Fill(ibpt);
	    WrongElEta_b[ibpt]->Fill(ib);
	  }
	  if(chargeok){
	    GoodElPt->Fill(ibpt,1);
	    GoodElEta->Fill(ib,1);
	    GoodEl2D->Fill(ibpt,ib,1);
	    GoodElPt_b[ib]->Fill(ibpt);
	    GoodElEta_b[ibpt]->Fill(ib);
	  }
 	  float majch=(probe_gsfcharge+probe_kfcharge+probe_sccharge);
 	  if (tag_gsfEle_charge*majch>0)  WrongCharge_maj[ib]->Fill(pair_mass);

	}
      }
    }   
  }
  cout<<"OK2" <<endl;
  hfile->Write();
  //   hfile.Close();
  
  
}
