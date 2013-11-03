#include "Riostream.h"
#include <math.h>
#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TGraph.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH2.h"
#include "TStyle.h"
#include "TFolder.h"
#include "TMath.h"
#include <math.h>
#include "TCanvas.h"
#include <iostream>
#include <fstream>
//////my function
#include "interface/constants.h"
#include "interface/AlphaT.h"
#include "interface/AlphaTReClus.h"
#include "interface/TauSel.h"
#include "interface/MuSel.h"
#include "interface/ElSel.h"
#include "interface/PFElSel.h"
#include "interface/LTprob.h"
#include "interface/invmass.h"

class SusyRead{
 public :
  TTree *fChain;
  Int_t  fCurrent; //!current Tree number in a TChain

  /////////Declaration of leaf type
  UInt_t EVENT,RUN,LUMISEC;
  UInt_t NJET,NPFJET,NEl,NPFEl,NMu,NPFMu,NTau,NPFTau,NJETak,NPFJETak;
  UInt_t El_EidTight[50],PFEl_EidTight[50];
  Double_t JET_ET[50],JET_PT[50],JET_PX[50],JET_PY[50],JET_PZ[50],JET_ETA[50],JET_PHI[50],JET_energy[50];
  Double_t JETak_ET[50],JETak_PT[50],JETak_PX[50],JETak_PY[50],JETak_PZ[50],JETak_ETA[50],JETak_PHI[50],JETak_energy[50];
  Double_t PFJET_ET[50],PFJET_PT[50],PFJET_PX[50],PFJET_PY[50],PFJET_PZ[50],PFJET_ETA[50],PFJET_PHI[50],PFJET_energy[50];
  Double_t PFJETak_ET[50],PFJETak_PT[50],PFJETak_PX[50],PFJETak_PY[50],PFJETak_PZ[50],PFJETak_ETA[50],PFJETak_PHI[50],PFJETak_energy[50];
  Double_t El_Charge[50],El_D0[50],El_ET[50],El_ETA[50],El_PHI[50],El_PT[50],El_PX[50],El_PY[50],El_PZ[50],El_ecalIso[50],El_hcalIso[50],El_energy[50],El_trackIso[50];
  UInt_t El_Conversion[50],El_LostHits[50],PFEl_Conversion[50],PFEl_LostHits[50];
  Double_t El_isChargeok[50],PFEl_isChargeok[50],El_HoE[50];
  Double_t JET_btagt[50],JET_btagl[50],PFJET_btagt[50],PFJET_btagl[50];
  Double_t JETak_btagt[50],JETak_btagl[50],PFJETak_btagt[50],PFJETak_btagl[50];
  Double_t PFEl_Charge[50],PFEl_D0[50],PFEl_ET[50],PFEl_ETA[50],PFEl_PHI[50],PFEl_PT[50],PFEl_PX[50],PFEl_PY[50],PFEl_PZ[50],PFEl_ecalIso[50],PFEl_hcalIso[50],PFEl_energy[50],PFEl_trackIso[50],PFEl_chargedHadronIso[50],PFEl_neutralHadronIso[50],PFEl_photonIso[50],PFEl_MVA[50],PFEl_HoE[50];
  Double_t Mu_Charge[50],Mu_Chi2dof[50],Mu_D0[50],Mu_ET[50],Mu_ETA[50],Mu_NHitsTrack[50],Mu_PHI[50],Mu_PT[50],Mu_PX[50],Mu_PY[50],Mu_PZ[50],Mu_ecalIso[50],Mu_energy[50],Mu_hcalIso[50],Mu_trackIso[50];
  UInt_t Mu_isGlobal[50],PFMu_isGlobal[50];
  Double_t PFMu_Charge[50],PFMu_Chi2dof[50],PFMu_D0[50],PFMu_ET[50],PFMu_ETA[50],PFMu_NHitsTrack[50],PFMu_PHI[50],PFMu_PT[50],PFMu_PX[50],PFMu_PY[50],PFMu_PZ[50],PFMu_ecalIso[50],PFMu_energy[50],PFMu_hcalIso[50],PFMu_trackIso[50],PFMu_chargedHadronIso[50],PFMu_neutralHadronIso[50],PFMu_photonIso[50];
  Double_t MET,MET_PHI,PFMET,PFMET_PHI,METak,METak_PHI;
  Double_t Tau_Charge[50],Tau_ET[50],Tau_ETA[50],Tau_PHI[50],Tau_PT[50],Tau_PX[50],Tau_PY[50],Tau_PZ[50],Tau_TaNC[50],Tau_energy[50];
  Double_t PFTau_Charge[50],PFTau_ET[50],PFTau_ETA[50],PFTau_PHI[50],PFTau_PT[50],PFTau_PX[50],PFTau_PY[50],PFTau_PZ[50],PFTau_TaNC[50],PFTau_energy[50];
  Double_t Tau_LTF[50],PFTau_LTF[50];
  ///////////pointers to the branches
  TBranch *b_EVENT,*b_RUN,*b_LUMISEC;
  TBranch *b_NJET,*b_NPFJET,*b_NEl,*b_NPFEl,*b_NMu,*b_NPFMu,*b_MET,*b_PFMET,*b_MET_PHI,*b_PFMET_PHI,*b_NTau,*b_NPFTau,*b_NJETak,*b_NPFJETak,*b_METak,*b_METak_PHI;
  TBranch *b_JET_ET,*b_JET_PT,*b_JET_PX,*b_JET_PY,*b_JET_PZ,*b_JET_ETA,*b_JET_PHI,*b_JET_energy;
  TBranch *b_JETak_ET,*b_JETak_PT,*b_JETak_PX,*b_JETak_PY,*b_JETak_PZ,*b_JETak_ETA,*b_JETak_PHI,*b_JETak_energy;
  TBranch *b_PFJET_ET,*b_PFJET_PT,*b_PFJET_PX,*b_PFJET_PY,*b_PFJET_PZ,*b_PFJET_ETA,*b_PFJET_PHI,*b_PFJET_energy;
  TBranch *b_PFJETak_ET,*b_PFJETak_PT,*b_PFJETak_PX,*b_PFJETak_PY,*b_PFJETak_PZ,*b_PFJETak_ETA,*b_PFJETak_PHI,*b_PFJETak_energy;
  TBranch *b_El_HoE,*b_El_Charge,*b_El_D0,*b_El_ET,*b_El_ETA,*b_El_EidTight,*b_El_PHI,*b_El_PT,*b_El_PX,*b_El_PY,*b_El_PZ,*b_El_ecalIso,*b_El_hcalIso,*b_El_energy,*b_El_trackIso;
  TBranch *b_PFEl_Charge,*b_PFEl_D0,*b_PFEl_ET,*b_PFEl_ETA,*b_PFEl_EidTight,*b_PFEl_PHI,*b_PFEl_PT,*b_PFEl_PX,*b_PFEl_PY,*b_PFEl_PZ,*b_PFEl_ecalIso,*b_PFEl_hcalIso,*b_PFEl_energy,*b_PFEl_trackIso,*b_PFEl_chargedHadronIso,*b_PFEl_neutralHadronIso,*b_PFEl_photonIso,*b_PFEl_MVA,*b_PFEl_HoE;
  TBranch *b_Mu_Charge,*b_Mu_Chi2dof,*b_Mu_D0,*b_Mu_ET,*b_Mu_ETA,*b_Mu_NHitsTrack,*b_Mu_PHI,*b_Mu_PT,*b_Mu_PX,*b_Mu_PY,*b_Mu_PZ,*b_Mu_ecalIso,*b_Mu_energy,*b_Mu_hcalIso,*b_Mu_isGlobal,*b_Mu_trackIso;
  TBranch *b_PFMu_Charge,*b_PFMu_Chi2dof,*b_PFMu_D0,*b_PFMu_ET,*b_PFMu_ETA,*b_PFMu_NHitsTrack,*b_PFMu_PHI,*b_PFMu_PT,*b_PFMu_PX,*b_PFMu_PY,*b_PFMu_PZ,*b_PFMu_ecalIso,*b_PFMu_energy,*b_PFMu_hcalIso,*b_PFMu_isGlobal,*b_PFMu_trackIso,*b_PFMu_chargedHadronIso,*b_PFMu_neutralHadronIso,*b_PFMu_photonIso;
  TBranch *b_Tau_Charge,*b_Tau_ET,*b_Tau_ETA,*b_Tau_PHI,*b_Tau_PT,*b_Tau_PX,*b_Tau_PY,*b_Tau_PZ,*b_Tau_TaNC,*b_Tau_energy;
  TBranch *b_PFTau_Charge,*b_PFTau_ET,*b_PFTau_ETA,*b_PFTau_PHI,*b_PFTau_PT,*b_PFTau_PX,*b_PFTau_PY,*b_PFTau_PZ,*b_PFTau_TaNC,*b_PFTau_energy;
  TBranch *b_El_Conversion,*b_El_LostHits,*b_El_isChargeok,*b_JET_btagl,*b_JET_btagt,*b_JETak_btagl,*b_JETak_btagt,*b_Tau_LTF,*b_PFEl_Conversion,*b_PFEl_LostHits,*b_PFEl_isChargeok,*b_PFJET_btagl,*b_PFJET_btagt,*b_PFTau_LTF,*b_PFJETak_btagl,*b_PFJETak_btagt;
  SusyRead(TTree *tree=0,char *output="salida.root",double cs=1);

  virtual ~SusyRead();

  virtual Int_t    GetEntry(Long64_t entry);
  virtual Long64_t LoadTree(Long64_t entry);
  virtual void     Init(TTree *tree);
  virtual void     Loop();
  
  float dzero(float, float);

  //output file
  TFile *f2;

  double weight;
};

int main(int argc, char *argv[]){
  std::cout << "Begining!!!!" << std::endl;
  std::cout << "input : " << argv[1] <<  std::endl;
  TFile * f1 = new TFile(argv[1]);
  f1->cd("susytree");
  TTree * g1 = (TTree*)gDirectory->FindObjectAny("SUSY_Tree");
  SusyRead * iso = new SusyRead(g1,argv[2],atof(argv[3]));
  iso->Loop();
  return 0;
}

void SusyRead::Loop(){
  std::cout << "Starting the Loop baby" <<  endl;

  ////////histograms
  TFolder *Jets_Fol = gROOT->GetRootFolder()->AddFolder("Jets","Jets"); 
  TFolder *HT_Fol = gROOT->GetRootFolder()->AddFolder("HT","HT"); 
  TFolder *Alphat_Fol = gROOT->GetRootFolder()->AddFolder("Alphat","Alphat"); 
  TFolder *Alphat_Fol_2jets = gROOT->GetRootFolder()->AddFolder("Alphat_2jets_big2","Alphat_2jets_big2"); 
  TFolder *El_Fol = gROOT->GetRootFolder()->AddFolder("Electron","Electron"); 
  TFolder *sel_sing_lep = gROOT->GetRootFolder()->AddFolder("SingleLepton","SingleLepton"); 
  TFolder *sel_dob_lep = gROOT->GetRootFolder()->AddFolder("DoubleLepton","DoubleLepton"); 
  TFolder *dif_two_jets = gROOT->GetRootFolder()->AddFolder("Differences_two_jets","Differences_two_jets"); 
  TFolder *Mu_Fol = gROOT->GetRootFolder()->AddFolder("Muon","Muon"); 
  TFolder *Tau_Fol = gROOT->GetRootFolder()->AddFolder("Tau","Tau"); 

  TH2F *hist_HT_vs_twolep = new TH2F("HT_vs_2leptons","HT_vs_2leptons",100,0,1000,6,0,6);
  TH2F *hist_PFHT_vs_twolep = new TH2F("PFHT_vs_2leptons","PFHT_vs_2leptons",100,0,1000,6,0,6);
  TH2F *hist_HT_vs_MET = new TH2F("HT_vs_MET","HT_vs_MET",100,0,1000,50,0,500);
  TH2F *hist_PFHT_vs_MET = new TH2F("PFHT_vs_MET","PFHT_vs_MET",100,0,1000,50,0,500);
  TH2F *hist_HT_vs_nlep = new TH2F("HT_vs_nleptons","HT_vs_nleptons",100,0,1000,10,0,10);
  TH2F *hist_PFHT_vs_nlep = new TH2F("PFHT_vs_nleptons","PFHT_vs_nleptons",100,0,1000,10,0,10);

  hist_HT_vs_twolep->Sumw2();
  hist_PFHT_vs_twolep->Sumw2();
  hist_HT_vs_nlep->Sumw2();
  hist_PFHT_vs_nlep->Sumw2();
  hist_HT_vs_MET->Sumw2();
  hist_PFHT_vs_MET->Sumw2();

  HT_Fol->Add(hist_HT_vs_twolep);
  HT_Fol->Add(hist_PFHT_vs_twolep);
  HT_Fol->Add(hist_HT_vs_nlep);
  HT_Fol->Add(hist_PFHT_vs_nlep);
  HT_Fol->Add(hist_HT_vs_MET);
  HT_Fol->Add(hist_PFHT_vs_MET);


  TH1F *hist_single_el = new TH1F("SLe","SLe",2,0,2);
  TH1F *hist_single_mu = new TH1F("SLmu","SLmu",2,0,2);
  TH1F *hist_single_tau = new TH1F("SLtau","SLtau",2,0,2);
  TH1F *hist_single_pfel = new TH1F("PFSLe","PFSLe",2,0,2);
  TH1F *hist_single_pfmu = new TH1F("PFSLmu","PFSLmu",2,0,2);
  TH1F *hist_single_pftau = new TH1F("PFSLtau","PFSLtau",2,0,2);

  hist_single_el->Sumw2();
  hist_single_mu->Sumw2();
  hist_single_tau->Sumw2();
  hist_single_pfel->Sumw2();
  hist_single_pfmu->Sumw2();
  hist_single_pftau->Sumw2();

  sel_sing_lep->Add(hist_single_el);
  sel_sing_lep->Add(hist_single_mu);
  sel_sing_lep->Add(hist_single_tau);
  sel_sing_lep->Add(hist_single_pfel);
  sel_sing_lep->Add(hist_single_pfmu);
  sel_sing_lep->Add(hist_single_pftau);

  TH1F *hist_double_lep_opp_sign_ee = new TH1F("DLOSee","DLOSee",2,0,2);
  TH1F *hist_double_lep_opp_sign_emu = new TH1F("DLOSemu","DLOSemu",2,0,2);
  TH1F *hist_double_lep_opp_sign_etau = new TH1F("DLOSetau","DLOSetau",2,0,2);
  TH1F *hist_double_lep_opp_sign_mumu = new TH1F("DLOSmumu","DLOSmumu",2,0,2);
  TH1F *hist_double_lep_opp_sign_mutau = new TH1F("DLOSmutau","DLOSmutau",2,0,2);
  TH1F *hist_double_lep_opp_sign_tautau = new TH1F("DLOStautau","DLOStautau",2,0,2);

  TH1F *hist_double_lep_opp_sign_PFee = new TH1F("PFDLOSee","PFDLOSee",2,0,2);
  TH1F *hist_double_lep_opp_sign_PFemu = new TH1F("PFDLOSemu","PFDLOSemu",2,0,2);
  TH1F *hist_double_lep_opp_sign_PFetau = new TH1F("PFDLOSetau","PFDLOSetau",2,0,2);
  TH1F *hist_double_lep_opp_sign_PFmumu = new TH1F("PFDLOSmumu","PFDLOSmumu",2,0,2);
  TH1F *hist_double_lep_opp_sign_PFmutau = new TH1F("PFDLOSmutau","PFDLOSmutau",2,0,2);
  TH1F *hist_double_lep_opp_sign_PFtautau = new TH1F("PFDLOStautau","PFDLOStautau",2,0,2);

  hist_double_lep_opp_sign_ee->Sumw2();
  hist_double_lep_opp_sign_emu->Sumw2();
  hist_double_lep_opp_sign_etau->Sumw2();
  hist_double_lep_opp_sign_mumu->Sumw2();
  hist_double_lep_opp_sign_mutau->Sumw2();
  hist_double_lep_opp_sign_tautau->Sumw2();

  hist_double_lep_opp_sign_PFee->Sumw2();
  hist_double_lep_opp_sign_PFemu->Sumw2();
  hist_double_lep_opp_sign_PFetau->Sumw2();
  hist_double_lep_opp_sign_PFmumu->Sumw2();
  hist_double_lep_opp_sign_PFmutau->Sumw2();
  hist_double_lep_opp_sign_PFtautau->Sumw2();

  sel_dob_lep->Add(hist_double_lep_opp_sign_ee);
  sel_dob_lep->Add(hist_double_lep_opp_sign_emu);
  sel_dob_lep->Add(hist_double_lep_opp_sign_etau);
  sel_dob_lep->Add(hist_double_lep_opp_sign_mumu);
  sel_dob_lep->Add(hist_double_lep_opp_sign_mutau);
  sel_dob_lep->Add(hist_double_lep_opp_sign_tautau);

  sel_dob_lep->Add(hist_double_lep_opp_sign_PFee);
  sel_dob_lep->Add(hist_double_lep_opp_sign_PFemu);
  sel_dob_lep->Add(hist_double_lep_opp_sign_PFetau);
  sel_dob_lep->Add(hist_double_lep_opp_sign_PFmumu);
  sel_dob_lep->Add(hist_double_lep_opp_sign_PFmutau);
  sel_dob_lep->Add(hist_double_lep_opp_sign_PFtautau);

  TH1F *hist_double_lep_same_sign_ee = new TH1F("DLSSee","DLSSee",2,0,2);
  TH1F *hist_double_lep_same_sign_emu = new TH1F("DLSSemu","DLSSemu",2,0,2);
  TH1F *hist_double_lep_same_sign_etau = new TH1F("DLSSetau","DLSSetau",2,0,2);
  TH1F *hist_double_lep_same_sign_mumu = new TH1F("DLSSmumu","DLSSmumu",2,0,2);
  TH1F *hist_double_lep_same_sign_mutau = new TH1F("DLSSmutau","DLSSmutau",2,0,2);
  TH1F *hist_double_lep_same_sign_tautau = new TH1F("DLSStautau","DLSStautau",2,0,2);

  TH1F *hist_double_lep_same_sign_ee_inc = new TH1F("DLSSee_inc","DLSSee_inc",2,0,2);
  TH1F *hist_double_lep_same_sign_emu_inc = new TH1F("DLSSemu_inc","DLSSemu_inc",2,0,2);
  TH1F *hist_double_lep_same_sign_etau_inc = new TH1F("DLSSetau_inc","DLSSetau_inc",2,0,2);
  TH1F *hist_double_lep_same_sign_mumu_inc = new TH1F("DLSSmumu_inc","DLSSmumu_inc",2,0,2);
  TH1F *hist_double_lep_same_sign_mutau_inc = new TH1F("DLSSmutau_inc","DLSSmutau_inc",2,0,2);
  TH1F *hist_double_lep_same_sign_tautau_inc = new TH1F("DLSStautau_inc","DLSStautau_inc",2,0,2);

  TH1F *hist_double_lep_same_sign_ee_back_2l = new TH1F("DLSSee_back_2l","DLSSee_back_2l",2,0,2);
  TH1F *hist_double_lep_same_sign_emu_back_2l = new TH1F("DLSSemu_back_2l","DLSSemu_back_2l",2,0,2);
  TH1F *hist_double_lep_same_sign_etau_back_2l = new TH1F("DLSSetau_back_2l","DLSSetau_back_2l",2,0,2);
  TH1F *hist_double_lep_same_sign_mumu_back_2l = new TH1F("DLSSmumu_back_2l","DLSSmumu_back_2l",2,0,2);
  TH1F *hist_double_lep_same_sign_mutau_back_2l = new TH1F("DLSSmutau_back_2l","DLSSmutau_back_2l",2,0,2);
  TH1F *hist_double_lep_same_sign_tautau_back_2l = new TH1F("DLSStautau_back_2l","DLSStautau_back_2l",2,0,2);

  TH1F *hist_double_lep_same_sign_ee_back_1l = new TH1F("DLSSee_back_1l","DLSSee_back_1l",2,0,2);
  TH1F *hist_double_lep_same_sign_emu_back_1l = new TH1F("DLSSemu_back_1l","DLSSemu_back_1l",2,0,2);
  TH1F *hist_double_lep_same_sign_etau_back_1l = new TH1F("DLSSetau_back_1l","DLSSetau_back_1l",2,0,2);
  TH1F *hist_double_lep_same_sign_mumu_back_1l = new TH1F("DLSSmumu_back_1l","DLSSmumu_back_1l",2,0,2);
  TH1F *hist_double_lep_same_sign_mutau_back_1l = new TH1F("DLSSmutau_back_1l","DLSSmutau_back_1l",2,0,2);
  TH1F *hist_double_lep_same_sign_tautau_back_1l = new TH1F("DLSStautau_back_1l","DLSStautau_back_1l",2,0,2);

  TH1F *hist_double_lep_same_sign_PFee = new TH1F("PFDLSSee","PFDLSSee",2,0,2);
  TH1F *hist_double_lep_same_sign_PFemu = new TH1F("PFDLSSemu","PFDLSSemu",2,0,2);
  TH1F *hist_double_lep_same_sign_PFetau = new TH1F("PFDLSSetau","PFDLSSetau",2,0,2);
  TH1F *hist_double_lep_same_sign_PFmumu = new TH1F("PFDLSSmumu","PFDLSSmumu",2,0,2);
  TH1F *hist_double_lep_same_sign_PFmutau = new TH1F("PFDLSSmutau","PFDLSSmutau",2,0,2);
  TH1F *hist_double_lep_same_sign_PFtautau = new TH1F("PFDLSStautau","PFDLSStautau",2,0,2);

  TH1F *hist_double_lep_same_sign_PFee_inc = new TH1F("PFDLSSee_inc","PFDLSSee_inc",2,0,2);
  TH1F *hist_double_lep_same_sign_PFemu_inc = new TH1F("PFDLSSemu_inc","PFDLSSemu_inc",2,0,2);
  TH1F *hist_double_lep_same_sign_PFetau_inc = new TH1F("PFDLSSetau_inc","PFDLSSetau_inc",2,0,2);
  TH1F *hist_double_lep_same_sign_PFmumu_inc = new TH1F("PFDLSSmumu_inc","PFDLSSmumu_inc",2,0,2);
  TH1F *hist_double_lep_same_sign_PFmutau_inc = new TH1F("PFDLSSmutau_inc","PFDLSSmutau_inc",2,0,2);
  TH1F *hist_double_lep_same_sign_PFtautau_inc = new TH1F("PFDLSStautau_inc","PFDLSStautau_inc",2,0,2);

  TH1F *hist_double_lep_same_sign_PFee_back_2l = new TH1F("PFDLSSee_back_2l","PFDLSSee_back_2l",2,0,2);
  TH1F *hist_double_lep_same_sign_PFemu_back_2l = new TH1F("PFDLSSemu_back_2l","PFDLSSemu_back_2l",2,0,2);
  TH1F *hist_double_lep_same_sign_PFetau_back_2l = new TH1F("PFDLSSetau_back_2l","PFDLSSetau_back_2l",2,0,2);
  TH1F *hist_double_lep_same_sign_PFmumu_back_2l = new TH1F("PFDLSSmumu_back_2l","PFDLSSmumu_back_2l",2,0,2);
  TH1F *hist_double_lep_same_sign_PFmutau_back_2l = new TH1F("PFDLSSmutau_back_2l","PFDLSSmutau_back_2l",2,0,2);
  TH1F *hist_double_lep_same_sign_PFtautau_back_2l = new TH1F("PFDLSStautau_back_2l","PFDLSStautau_back_2l",2,0,2);

  TH1F *hist_double_lep_same_sign_PFee_back_1l = new TH1F("PFDLSSee_back_1l","PFDLSSee_back_1l",2,0,2);
  TH1F *hist_double_lep_same_sign_PFemu_back_1l = new TH1F("PFDLSSemu_back_1l","PFDLSSemu_back_1l",2,0,2);
  TH1F *hist_double_lep_same_sign_PFetau_back_1l = new TH1F("PFDLSSetau_back_1l","PFDLSSetau_back_1l",2,0,2);
  TH1F *hist_double_lep_same_sign_PFmumu_back_1l = new TH1F("PFDLSSmumu_back_1l","PFDLSSmumu_back_1l",2,0,2);
  TH1F *hist_double_lep_same_sign_PFmutau_back_1l = new TH1F("PFDLSSmutau_back_1l","PFDLSSmutau_back_1l",2,0,2);
  TH1F *hist_double_lep_same_sign_PFtautau_back_1l = new TH1F("PFDLSStautau_back_1l","PFDLSStautau_back_1l",2,0,2);

  hist_double_lep_same_sign_ee->Sumw2();
  hist_double_lep_same_sign_emu->Sumw2();
  hist_double_lep_same_sign_etau->Sumw2();
  hist_double_lep_same_sign_mumu->Sumw2();
  hist_double_lep_same_sign_mutau->Sumw2();
  hist_double_lep_same_sign_tautau->Sumw2();

  hist_double_lep_same_sign_ee_inc->Sumw2();
  hist_double_lep_same_sign_emu_inc->Sumw2();
  hist_double_lep_same_sign_etau_inc->Sumw2();
  hist_double_lep_same_sign_mumu_inc->Sumw2();
  hist_double_lep_same_sign_mutau_inc->Sumw2();
  hist_double_lep_same_sign_tautau_inc->Sumw2();

  hist_double_lep_same_sign_ee_back_2l->Sumw2();
  hist_double_lep_same_sign_emu_back_2l->Sumw2();
  hist_double_lep_same_sign_etau_back_2l->Sumw2();
  hist_double_lep_same_sign_mumu_back_2l->Sumw2();
  hist_double_lep_same_sign_mutau_back_2l->Sumw2();
  hist_double_lep_same_sign_tautau_back_2l->Sumw2();

  hist_double_lep_same_sign_ee_back_1l->Sumw2();
  hist_double_lep_same_sign_emu_back_1l->Sumw2();
  hist_double_lep_same_sign_etau_back_1l->Sumw2();
  hist_double_lep_same_sign_mumu_back_1l->Sumw2();
  hist_double_lep_same_sign_mutau_back_1l->Sumw2();
  hist_double_lep_same_sign_tautau_back_1l->Sumw2();

  hist_double_lep_same_sign_PFee->Sumw2();
  hist_double_lep_same_sign_PFemu->Sumw2();
  hist_double_lep_same_sign_PFetau->Sumw2();
  hist_double_lep_same_sign_PFmumu->Sumw2();
  hist_double_lep_same_sign_PFmutau->Sumw2();
  hist_double_lep_same_sign_PFtautau->Sumw2();

  hist_double_lep_same_sign_PFee_inc->Sumw2();
  hist_double_lep_same_sign_PFemu_inc->Sumw2();
  hist_double_lep_same_sign_PFetau_inc->Sumw2();
  hist_double_lep_same_sign_PFmumu_inc->Sumw2();
  hist_double_lep_same_sign_PFmutau_inc->Sumw2();
  hist_double_lep_same_sign_PFtautau_inc->Sumw2();

  hist_double_lep_same_sign_PFee_back_2l->Sumw2();
  hist_double_lep_same_sign_PFemu_back_2l->Sumw2();
  hist_double_lep_same_sign_PFetau_back_2l->Sumw2();
  hist_double_lep_same_sign_PFmumu_back_2l->Sumw2();
  hist_double_lep_same_sign_PFmutau_back_2l->Sumw2();
  hist_double_lep_same_sign_PFtautau_back_2l->Sumw2();

  hist_double_lep_same_sign_PFee_back_1l->Sumw2();
  hist_double_lep_same_sign_PFemu_back_1l->Sumw2();
  hist_double_lep_same_sign_PFetau_back_1l->Sumw2();
  hist_double_lep_same_sign_PFmumu_back_1l->Sumw2();
  hist_double_lep_same_sign_PFmutau_back_1l->Sumw2();
  hist_double_lep_same_sign_PFtautau_back_1l->Sumw2();

  sel_dob_lep->Add(hist_double_lep_same_sign_ee);
  sel_dob_lep->Add(hist_double_lep_same_sign_emu);
  sel_dob_lep->Add(hist_double_lep_same_sign_etau);
  sel_dob_lep->Add(hist_double_lep_same_sign_mumu);
  sel_dob_lep->Add(hist_double_lep_same_sign_mutau);
  sel_dob_lep->Add(hist_double_lep_same_sign_tautau);

  sel_dob_lep->Add(hist_double_lep_same_sign_ee_inc);
  sel_dob_lep->Add(hist_double_lep_same_sign_emu_inc);
  sel_dob_lep->Add(hist_double_lep_same_sign_etau_inc);
  sel_dob_lep->Add(hist_double_lep_same_sign_mumu_inc);
  sel_dob_lep->Add(hist_double_lep_same_sign_mutau_inc);
  sel_dob_lep->Add(hist_double_lep_same_sign_tautau_inc);

  sel_dob_lep->Add(hist_double_lep_same_sign_PFee);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFemu);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFetau);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFmumu);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFmutau);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFtautau);

  sel_dob_lep->Add(hist_double_lep_same_sign_PFee_inc);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFemu_inc);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFetau_inc);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFmumu_inc);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFmutau_inc);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFtautau_inc);

  sel_dob_lep->Add(hist_double_lep_same_sign_ee_back_2l);
  sel_dob_lep->Add(hist_double_lep_same_sign_emu_back_2l);
  sel_dob_lep->Add(hist_double_lep_same_sign_etau_back_2l);
  sel_dob_lep->Add(hist_double_lep_same_sign_mumu_back_2l);
  sel_dob_lep->Add(hist_double_lep_same_sign_mutau_back_2l);
  sel_dob_lep->Add(hist_double_lep_same_sign_tautau_back_2l);

  sel_dob_lep->Add(hist_double_lep_same_sign_ee_back_1l);
  sel_dob_lep->Add(hist_double_lep_same_sign_emu_back_1l);
  sel_dob_lep->Add(hist_double_lep_same_sign_etau_back_1l);
  sel_dob_lep->Add(hist_double_lep_same_sign_mumu_back_1l);
  sel_dob_lep->Add(hist_double_lep_same_sign_mutau_back_1l);
  sel_dob_lep->Add(hist_double_lep_same_sign_tautau_back_1l);

  sel_dob_lep->Add(hist_double_lep_same_sign_PFee_back_2l);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFemu_back_2l);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFetau_back_2l);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFmumu_back_2l);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFmutau_back_2l);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFtautau_back_2l);

  sel_dob_lep->Add(hist_double_lep_same_sign_PFee_back_1l);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFemu_back_1l);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFetau_back_1l);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFmumu_back_1l);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFmutau_back_1l);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFtautau_back_1l);

  TH1F *hist_HT = new TH1F("HT","HT",1000,0,5000);
  TH1F *hist_MHT = new TH1F("MHT","MHT",1000,0,5000);
  TH1F *hist_PFHT = new TH1F("PFHT","PFHT",1000,0,5000);
  TH1F *hist_PFMHT = new TH1F("PFMHT","PFMHT",1000,0,5000);

  TH1F *hist_jet_multiplicity_after_pt_cut = new TH1F("JetMultiplicityAfterPtCut","JetMultiplicityAfterPtCut",30,0,30);
  TH1F *hist_jet_multiplicity_after_eta_cut = new TH1F("JetMultiplicityAfterEtaCut","JetMultiplicityAfterEtaCut",30,0,30);
  TH1F *hist_jet_multiplicity_after_pt_eta_cut = new TH1F("JetMultiplicityAfterPtEtaCut","JetMultiplicityAfterPtEtaCut",30,0,30);
  TH1F *hist_PFjet_multiplicity_after_pt_cut = new TH1F("PFJetMultiplicityAfterPtCut","PFJetMultiplicityAfterPtCut",30,0,30);
  TH1F *hist_PFjet_multiplicity_after_eta_cut = new TH1F("PFJetMultiplicityAfterEtaCut","PFJetMultiplicityAfterEtaCut",30,0,30);
  TH1F *hist_PFjet_multiplicity_after_pt_eta_cut = new TH1F("PFJetMultiplicityAfterPtEtaCut","PFJetMultiplicityAfterPtEtaCut",30,0,30);
  TH2F *hist_n_SR_vs_PF_jets = new TH2F("Number_of_SR_vs_PF_jets_before_cuts","Number_of_SR_vs_PF_jets_before_cuts",20,0,20,20,0,20);
  TH2F *hist_n_SR_vs_PF_jets_after = new TH2F("Number_of_SR_vs_PF_jets_after_cuts","Number_of_SR_vs_PF_jets_after_cuts",20,0,20,20,0,20);
  TH2F *hist_n_SR_vs_PF_jets_peak_reclus_dif = new TH2F("Number_of_SR_vs_PF_jets_reclus_dif","Number_of_SR_vs_PF_jets_reclus_dif",20,0,20,20,0,20);
  TH2F *hist_n_SR_vs_PF_jets_peak_reclus_dif_after = new TH2F("Number_of_SR_vs_PF_jets_reclus_dif_after","Number_of_SR_vs_PF_jets_reclus_dif_after",20,0,20,20,0,20);

  TH1F *hist_HTak = new TH1F("HTak","HTak",1000,0,5000);
  TH1F *hist_MHTak = new TH1F("MHTak","MHTak",1000,0,5000);
  TH1F *hist_PFHTak = new TH1F("PFHTak","PFHTak",1000,0,5000);
  TH1F *hist_PFMHTak = new TH1F("PFMHTak","PFMHTak",1000,0,5000);

  TH1F *hist_jet_multiplicity_after_pt_cutak = new TH1F("JetMultiplicityAfterPtCutak","JetMultiplicityAfterPtCutak",30,0,30);
  TH1F *hist_jet_multiplicity_after_eta_cutak = new TH1F("JetMultiplicityAfterEtaCutak","JetMultiplicityAfterEtaCutak",30,0,30);
  TH1F *hist_jet_multiplicity_after_pt_eta_cutak = new TH1F("JetMultiplicityAfterPtEtaCutak","JetMultiplicityAfterPtEtaCutak",30,0,30);
  TH1F *hist_PFjet_multiplicity_after_pt_cutak = new TH1F("PFJetMultiplicityAfterPtCutak","PFJetMultiplicityAfterPtCutak",30,0,30);
  TH1F *hist_PFjet_multiplicity_after_eta_cutak = new TH1F("PFJetMultiplicityAfterEtaCutak","PFJetMultiplicityAfterEtaCutak",30,0,30);
  TH1F *hist_PFjet_multiplicity_after_pt_eta_cutak = new TH1F("PFJetMultiplicityAfterPtEtaCutak","PFJetMultiplicityAfterPtEtaCutak",30,0,30);
  TH2F *hist_n_SR_vs_PF_jetsak = new TH2F("Number_of_SR_vs_PF_jets_before_cutsak","Number_of_SR_vs_PF_jets_before_cutsak",20,0,20,20,0,20);
  TH2F *hist_n_SR_vs_PF_jets_afterak = new TH2F("Number_of_SR_vs_PF_jets_after_cutsak","Number_of_SR_vs_PF_jets_after_cutsak",20,0,20,20,0,20);
  TH2F *hist_n_SR_vs_PF_jets_peak_reclus_difak = new TH2F("Number_of_SR_vs_PF_jets_reclus_difak","Number_of_SR_vs_PF_jets_reclus_difak",20,0,20,20,0,20);
  TH2F *hist_n_SR_vs_PF_jets_peak_reclus_dif_afterak = new TH2F("Number_of_SR_vs_PF_jets_reclus_dif_afterak","Number_of_SR_vs_PF_jets_reclus_dif_afterak",20,0,20,20,0,20);


  hist_HT->Sumw2();
  hist_MHT->Sumw2();
  hist_PFHT->Sumw2();
  hist_PFMHT->Sumw2();
  hist_jet_multiplicity_after_pt_cut->Sumw2();
  hist_jet_multiplicity_after_eta_cut->Sumw2();
  hist_jet_multiplicity_after_pt_eta_cut->Sumw2();
  hist_PFjet_multiplicity_after_pt_cut->Sumw2();
  hist_PFjet_multiplicity_after_eta_cut->Sumw2();
  hist_PFjet_multiplicity_after_pt_eta_cut->Sumw2();
  hist_n_SR_vs_PF_jets->Sumw2();
  hist_n_SR_vs_PF_jets_after->Sumw2();
  hist_n_SR_vs_PF_jets_peak_reclus_dif->Sumw2();
  hist_n_SR_vs_PF_jets_peak_reclus_dif_after->Sumw2();

  hist_HTak->Sumw2();
  hist_MHTak->Sumw2();
  hist_PFHTak->Sumw2();
  hist_PFMHTak->Sumw2();
  hist_jet_multiplicity_after_pt_cutak->Sumw2();
  hist_jet_multiplicity_after_eta_cutak->Sumw2();
  hist_jet_multiplicity_after_pt_eta_cutak->Sumw2();
  hist_PFjet_multiplicity_after_pt_cutak->Sumw2();
  hist_PFjet_multiplicity_after_eta_cutak->Sumw2();
  hist_PFjet_multiplicity_after_pt_eta_cutak->Sumw2();
  hist_n_SR_vs_PF_jetsak->Sumw2();
  hist_n_SR_vs_PF_jets_afterak->Sumw2();
  hist_n_SR_vs_PF_jets_peak_reclus_difak->Sumw2();
  hist_n_SR_vs_PF_jets_peak_reclus_dif_afterak->Sumw2();

  Jets_Fol->Add(hist_PFjet_multiplicity_after_pt_cut);
  Jets_Fol->Add(hist_PFjet_multiplicity_after_eta_cut);
  Jets_Fol->Add(hist_PFjet_multiplicity_after_pt_eta_cut);
  Jets_Fol->Add(hist_jet_multiplicity_after_pt_cut);
  Jets_Fol->Add(hist_jet_multiplicity_after_eta_cut);
  Jets_Fol->Add(hist_jet_multiplicity_after_pt_eta_cut);
  Jets_Fol->Add(hist_HT);
  Jets_Fol->Add(hist_PFHT);
  Jets_Fol->Add(hist_MHT);
  Jets_Fol->Add(hist_PFMHT);
  Jets_Fol->Add(hist_n_SR_vs_PF_jets);
  Jets_Fol->Add(hist_n_SR_vs_PF_jets_after);
  Jets_Fol->Add(hist_n_SR_vs_PF_jets_peak_reclus_dif);
  Jets_Fol->Add(hist_n_SR_vs_PF_jets_peak_reclus_dif_after);

  Jets_Fol->Add(hist_PFjet_multiplicity_after_pt_cutak);
  Jets_Fol->Add(hist_PFjet_multiplicity_after_eta_cutak);
  Jets_Fol->Add(hist_PFjet_multiplicity_after_pt_eta_cutak);
  Jets_Fol->Add(hist_jet_multiplicity_after_pt_cutak);
  Jets_Fol->Add(hist_jet_multiplicity_after_eta_cutak);
  Jets_Fol->Add(hist_jet_multiplicity_after_pt_eta_cutak);
  Jets_Fol->Add(hist_HTak);
  Jets_Fol->Add(hist_PFHTak);
  Jets_Fol->Add(hist_MHTak);
  Jets_Fol->Add(hist_PFMHTak);
  Jets_Fol->Add(hist_n_SR_vs_PF_jetsak);
  Jets_Fol->Add(hist_n_SR_vs_PF_jets_afterak);
  Jets_Fol->Add(hist_n_SR_vs_PF_jets_peak_reclus_difak);
  Jets_Fol->Add(hist_n_SR_vs_PF_jets_peak_reclus_dif_afterak);

  TH1F *hist_alphat_twojets = new TH1F("AlphaT_2Jets_case","AlphaT_2Jets_case",400,0,20);  
  TH1F *hist_alphat_njets_minimum_deltaht = new TH1F("Alphat_njets_case_minimum_deltaht","Alphat_njets_case_minimum_deltaht",400,0,20);
  TH1F *hist_alphat_njets_as_two_jets = new TH1F("Alphat_njets_as_two_jets","Alphat_njets_as_two_jets",400,0,20);
  TH1F *hist_alphat_njets_as_reclustered = new TH1F("Alphat_njets_case_as_reclustered","Alphat_njets_case_as_reclustered",400,0,20);
  TH1F *hist_alphat_njets_as_reclustered_recomputed_ht = new TH1F("Alphat_njets_case_as_reclustered_recomputed_ht","Alphat_njets_case_as_reclustered_recomputed_ht",400,0,20);
  TH1F *hist_alphat_twoPFjets = new TH1F("AlphaT_2PFJets_case","AlphaT_2PFJets_case",400,0,20);  
  TH1F *hist_alphat_nPFjets_minimum_deltaht = new TH1F("Alphat_nPFjets_case_minimum_deltaht","Alphat_nPFjets_case_minimum_deltaht",400,0,20);
  TH1F *hist_alphat_nPFjets_as_two_jets = new TH1F("Alphat_nPFjets_as_two_jets","Alphat_nPFjets_as_two_jets",400,0,20);
  TH1F *hist_alphat_nPFjets_as_reclustered = new TH1F("Alphat_nPFjets_case_as_reclustered","Alphat_nPFjets_case_as_reclustered",400,0,20);
  TH1F *hist_alphat_nPFjets_as_reclustered_recomputed_ht = new TH1F("Alphat_nPFjets_case_as_reclustered_recomputed_ht","Alphat_nPFjets_case_as_reclustered_recomputed_ht",400,0,20);
  TH2F *hist_deltaeta_vs_deltaphi_2jets = new TH2F("DeltaEta_vs_DeltaPhi_2Jets_case","DeltaEta_vs_DeltaPhi_2Jets_case",240,-6,6,200,-5,5);
  TH2F *hist_deltaeta_vs_deltaphi_2PFjets = new TH2F("DeltaEta_vs_DeltaPhi_2PFJets_case","DeltaEta_vs_DeltaPhi_2PFJets_case",240,-6,6,200,-5,5);
  TH2F *hist_deltaeta_vs_deltaphi_njets = new TH2F("DeltaEta_vs_DeltaPhi_nJets_case","DeltaEta_vs_DeltaPhi_nJets_case",240,-6,6,200,-5,5);
  TH2F *hist_deltaeta_vs_deltaphi_njets_recluster = new TH2F("DeltaEta_vs_DeltaPhi_nJets_case_recluster","DeltaEta_vs_DeltaPhi_nJets_case_recluster",240,-6,6,200,-5,5);
  TH2F *hist_deltaeta_vs_deltaphi_nPFjets_recluster = new TH2F("DeltaEta_vs_DeltaPhi_nPFJets_case_recluster","DeltaEta_vs_DeltaPhi_nPFJets_case_recluster",240,-6,6,200,-5,5);
  TH2F *hist_deltaeta_vs_deltaphi_nPFjets = new TH2F("DeltaEta_vs_DeltaPhi_nPFJets_case","DeltaEta_vs_DeltaPhi_nPFJets_case",240,-6,6,200,-5,5);

  TH1F *hist_alphat_SLCuts = new TH1F("Events_after_alphat_and_SL_cuts","Events_after_alphat_and_SL_cuts",2,0,2);
  TH1F *hist_alphat_PFSLCuts = new TH1F("Events_after_alphat_and_PFSL_cuts","Events_after_alphat_and_PFSL_cuts",2,0,2);
  TH1F *hist_alphat_DLCuts = new TH1F("Events_after_alphat_and_DL_cuts","Events_after_alphat_and_DL_cuts",2,0,2);
  TH1F *hist_alphat_PFDLCuts = new TH1F("Events_after_alphat_and_PFDL_cuts","Events_after_alphat_and_PFDL_cuts",2,0,2);
  TH1F *hist_alphat_re_SLCuts = new TH1F("Events_after_alphat_re_and_SL_cuts","Events_after_alphat_re_and_SL_cuts",2,0,2);
  TH1F *hist_alphat_re_PFSLCuts = new TH1F("Events_after_alphat_re_and_PFSL_cuts","Events_after_re_alphat_and_PFSL_cuts",2,0,2);
  TH1F *hist_alphat_re_DLCuts = new TH1F("Events_after_alphat_re_and_DL_cuts","Events_after_alphat_re_and_DL_cuts",2,0,2);
  TH1F *hist_alphat_re_PFDLCuts = new TH1F("Events_after_alphat_re_and_PFDL_cuts","Events_after_alphat_re_and_PFDL_cuts",2,0,2);

  TH1F *hist_alphat_2j_SLCuts = new TH1F("Events_after_alphat_2jets_and_SL_cuts","Events_after_alphat_2jets_and_SL_cuts",2,0,2);
  TH1F *hist_alphat_2j_PFSLCuts = new TH1F("Events_after_alphat_2jets_and_PFSL_cuts","Events_after_alphat_2jets_and_PFSL_cuts",2,0,2);
  TH1F *hist_alphat_2j_DLCuts = new TH1F("Events_after_alphat_2jets_and_DL_cuts","Events_after_alphat_2jets_and_DL_cuts",2,0,2);
  TH1F *hist_alphat_2j_PFDLCuts = new TH1F("Events_after_alphat_2jets_and_PFDL_cuts","Events_after_alphat_2jets_and_PFDL_cuts",2,0,2);

  TH1F *hist_alphat_nj_SLCuts = new TH1F("Events_after_alphat_njets_and_SL_cuts","Events_after_alphat_njets_and_SL_cuts",2,0,2);
  TH1F *hist_alphat_nj_PFSLCuts = new TH1F("Events_after_alphat_njets_and_PFSL_cuts","Events_after_alphat_njets_and_PFSL_cuts",2,0,2);
  TH1F *hist_alphat_nj_DLCuts = new TH1F("Events_after_alphat_njets_and_DL_cuts","Events_after_alphat_njets_and_DL_cuts",2,0,2);
  TH1F *hist_alphat_nj_PFDLCuts = new TH1F("Events_after_alphat_njets_and_PFDL_cuts","Events_after_alphat_njets_and_PFDL_cuts",2,0,2);
  TH1F *hist_alphat_nj_re_SLCuts = new TH1F("Events_after_alphat_njets_re_and_SL_cuts","Events_after_alphat_njets_and_SL_cuts",2,0,2);
  TH1F *hist_alphat_nj_re_PFSLCuts = new TH1F("Events_after_alphat_njets_re_and_PFSL_cuts","Events_after_alphat_njets_re_and_PFSL_cuts",2,0,2);
  TH1F *hist_alphat_nj_re_DLCuts = new TH1F("Events_after_alphat_njets_re_and_DL_cuts","Events_after_alphat_njets_re_and_DL_cuts",2,0,2);
  TH1F *hist_alphat_nj_re_PFDLCuts = new TH1F("Events_after_alphat_njets_re_and_PFDL_cuts","Events_after_alphat_njets_re_and_PFDL_cuts",2,0,2);

  TH1F *hist_alphatdis_twojets_SL = new TH1F("AlphaT_2Jets_case_SL","AlphaT_2Jets_case_SL",400,0,20);  
  TH1F *hist_alphatdis_twoPFjets_SL = new TH1F("AlphaT_2PFJets_case_SL","AlphaT_2PFJets_case_SL",400,0,20);  
  TH1F *hist_alphatdis_twojets_DL = new TH1F("AlphaT_2Jets_case_DL","AlphaT_2Jets_case_DL",400,0,20);  
  TH1F *hist_alphatdis_twoPFjets_DL = new TH1F("AlphaT_2PFJets_case_DL","AlphaT_2PFJets_case_DL",400,0,20);  

  TH1F *hist_alphat_njets_minimum_deltaht_SL = new TH1F("Alphat_njets_case_minimum_deltaht_SL","Alphat_njets_case_minimum_deltaht_SL",400,0,20);
  TH1F *hist_alphat_nPFjets_minimum_deltaht_SL = new TH1F("Alphat_nPFjets_case_minimum_deltaht_SL","Alphat_nPFjets_case_minimum_deltaht_SL",400,0,20);
  TH1F *hist_alphat_njets_minimum_deltaht_DL = new TH1F("Alphat_njets_case_minimum_deltaht_DL","Alphat_njets_case_minimum_deltaht_DL",400,0,20);
  TH1F *hist_alphat_nPFjets_minimum_deltaht_DL = new TH1F("Alphat_nPFjets_case_minimum_deltaht_DL","Alphat_nPFjets_case_minimum_deltaht_DL",400,0,20);

  TH1F *hist_alphat_njets_as_reclustered_SL = new TH1F("Alphat_njets_case_as_reclustered_SL","Alphat_njets_case_as_reclustered_SL",400,0,20);
  TH1F *hist_alphat_nPFjets_as_reclustered_SL = new TH1F("Alphat_nPFjets_case_as_reclustered_SL","Alphat_nPFjets_case_as_reclustered_SL",400,0,20);
  TH1F *hist_alphat_njets_as_reclustered_DL = new TH1F("Alphat_njets_case_as_reclustered_DL","Alphat_njets_case_as_reclustered_DL",400,0,20);
  TH1F *hist_alphat_nPFjets_as_reclustered_DL = new TH1F("Alphat_nPFjets_case_as_reclustered_DL","Alphat_nPFjets_case_as_reclustered_DL",400,0,20);

  ////////////////////////////////////////

  TH1F *hist_alphat_twojetsak = new TH1F("AlphaT_2Jets_caseak","akAlphaT_2Jets_case",400,0,20);  
  TH1F *hist_alphat_njets_minimum_deltahtak = new TH1F("Alphat_njets_case_minimum_deltahtak","akAlphat_njets_case_minimum_deltaht",400,0,20);
  TH1F *hist_alphat_njets_as_two_jetsak = new TH1F("Alphat_njets_as_two_jetsak","akAlphat_njets_as_two_jets",400,0,20);
  TH1F *hist_alphat_njets_as_reclusteredak = new TH1F("Alphat_njets_case_as_reclusteredak","akAlphat_njets_case_as_reclustered",400,0,20);
  TH1F *hist_alphat_njets_as_reclustered_recomputed_htak = new TH1F("Alphat_njets_case_as_reclustered_recomputed_htak","akAlphat_njets_case_as_reclustered_recomputed_ht",400,0,20);
  TH1F *hist_alphat_twoPFjetsak = new TH1F("AlphaT_2PFJets_caseak","akAlphaT_2PFJets_case",400,0,20);  
  TH1F *hist_alphat_nPFjets_minimum_deltahtak = new TH1F("Alphat_nPFjets_case_minimum_deltahtak","akAlphat_nPFjets_case_minimum_deltaht",400,0,20);
  TH1F *hist_alphat_nPFjets_as_two_jetsak = new TH1F("Alphat_nPFjets_as_two_jetsak","akAlphat_nPFjets_as_two_jets",400,0,20);
  TH1F *hist_alphat_nPFjets_as_reclusteredak = new TH1F("Alphat_nPFjets_case_as_reclusteredak","akAlphat_nPFjets_case_as_reclustered",400,0,20);
  TH1F *hist_alphat_nPFjets_as_reclustered_recomputed_htak = new TH1F("Alphat_nPFjets_case_as_reclustered_recomputed_htak","akAlphat_nPFjets_case_as_reclustered_recomputed_ht",400,0,20);
  TH2F *hist_deltaeta_vs_deltaphi_2jetsak = new TH2F("DeltaEta_vs_DeltaPhi_2Jets_caseak","akDeltaEta_vs_DeltaPhi_2Jets_case",240,-6,6,200,-5,5);
  TH2F *hist_deltaeta_vs_deltaphi_2PFjetsak = new TH2F("DeltaEta_vs_DeltaPhi_2PFJets_caseak","akDeltaEta_vs_DeltaPhi_2PFJets_case",240,-6,6,200,-5,5);
  TH2F *hist_deltaeta_vs_deltaphi_njetsak = new TH2F("DeltaEta_vs_DeltaPhi_nJets_caseak","akDeltaEta_vs_DeltaPhi_nJets_case",240,-6,6,200,-5,5);
  TH2F *hist_deltaeta_vs_deltaphi_njets_reclusterak = new TH2F("DeltaEta_vs_DeltaPhi_nJets_case_reclusterak","akDeltaEta_vs_DeltaPhi_nJets_case_recluster",240,-6,6,200,-5,5);
  TH2F *hist_deltaeta_vs_deltaphi_nPFjets_reclusterak = new TH2F("DeltaEta_vs_DeltaPhi_nPFJets_case_reclusterak","akDeltaEta_vs_DeltaPhi_nPFJets_case_recluster",240,-6,6,200,-5,5);
  TH2F *hist_deltaeta_vs_deltaphi_nPFjetsak = new TH2F("DeltaEta_vs_DeltaPhi_nPFJets_caseak","akDeltaEta_vs_DeltaPhi_nPFJets_case",240,-6,6,200,-5,5);

  TH1F *hist_alphat_SLCutsak = new TH1F("Events_after_alphat_and_SL_cutsak","akEvents_after_alphat_and_SL_cuts",2,0,2);
  TH1F *hist_alphat_PFSLCutsak = new TH1F("Events_after_alphat_and_PFSL_cutsak","akEvents_after_alphat_and_PFSL_cuts",2,0,2);
  TH1F *hist_alphat_DLCutsak = new TH1F("Events_after_alphat_and_DL_cutsak","akEvents_after_alphat_and_DL_cuts",2,0,2);
  TH1F *hist_alphat_PFDLCutsak = new TH1F("Events_after_alphat_and_PFDL_cutsak","akEvents_after_alphat_and_PFDL_cuts",2,0,2);
  TH1F *hist_alphat_re_SLCutsak = new TH1F("Events_after_alphat_re_and_SL_cutsak","akEvents_after_alphat_re_and_SL_cuts",2,0,2);
  TH1F *hist_alphat_re_PFSLCutsak = new TH1F("Events_after_alphat_re_and_PFSL_cutsak","akEvents_after_re_alphat_and_PFSL_cuts",2,0,2);
  TH1F *hist_alphat_re_DLCutsak = new TH1F("Events_after_alphat_re_and_DL_cutsak","akEvents_after_alphat_re_and_DL_cuts",2,0,2);
  TH1F *hist_alphat_re_PFDLCutsak = new TH1F("Events_after_alphat_re_and_PFDL_cutsak","akEvents_after_alphat_re_and_PFDL_cuts",2,0,2);

  TH1F *hist_alphat_2j_SLCutsak = new TH1F("Events_after_alphat_2jets_and_SL_cutsak","akEvents_after_alphat_2jets_and_SL_cuts",2,0,2);
  TH1F *hist_alphat_2j_PFSLCutsak = new TH1F("Events_after_alphat_2jets_and_PFSL_cutsak","akEvents_after_alphat_2jets_and_PFSL_cuts",2,0,2);
  TH1F *hist_alphat_2j_DLCutsak = new TH1F("Events_after_alphat_2jets_and_DL_cutsak","akEvents_after_alphat_2jets_and_DL_cuts",2,0,2);
  TH1F *hist_alphat_2j_PFDLCutsak = new TH1F("Events_after_alphat_2jets_and_PFDL_cutsak","akEvents_after_alphat_2jets_and_PFDL_cuts",2,0,2);

  TH1F *hist_alphat_nj_SLCutsak = new TH1F("Events_after_alphat_njets_and_SL_cutsak","akEvents_after_alphat_njets_and_SL_cuts",2,0,2);
  TH1F *hist_alphat_nj_PFSLCutsak = new TH1F("Events_after_alphat_njets_and_PFSL_cutsak","akEvents_after_alphat_njets_and_PFSL_cuts",2,0,2);
  TH1F *hist_alphat_nj_DLCutsak = new TH1F("Events_after_alphat_njets_and_DL_cutsak","akEvents_after_alphat_njets_and_DL_cuts",2,0,2);
  TH1F *hist_alphat_nj_PFDLCutsak = new TH1F("Events_after_alphat_njets_and_PFDL_cutsak","akEvents_after_alphat_njets_and_PFDL_cuts",2,0,2);
  TH1F *hist_alphat_nj_re_SLCutsak = new TH1F("Events_after_alphat_njets_re_and_SL_cutsak","akEvents_after_alphat_njets_and_SL_cuts",2,0,2);
  TH1F *hist_alphat_nj_re_PFSLCutsak = new TH1F("Events_after_alphat_njets_re_and_PFSL_cutsak","akEvents_after_alphat_njets_re_and_PFSL_cuts",2,0,2);
  TH1F *hist_alphat_nj_re_DLCutsak = new TH1F("Events_after_alphat_njets_re_and_DL_cutsak","akEvents_after_alphat_njets_re_and_DL_cuts",2,0,2);
  TH1F *hist_alphat_nj_re_PFDLCutsak = new TH1F("Events_after_alphat_njets_re_and_PFDL_cutsak","akEvents_after_alphat_njets_re_and_PFDL_cuts",2,0,2);

  TH1F *hist_alphatdis_twojets_SLak = new TH1F("AlphaT_2Jets_case_SLak","akAlphaT_2Jets_case_SL",400,0,20);  
  TH1F *hist_alphatdis_twoPFjets_SLak = new TH1F("AlphaT_2PFJets_case_SLak","akAlphaT_2PFJets_case_SL",400,0,20);  
  TH1F *hist_alphatdis_twojets_DLak = new TH1F("AlphaT_2Jets_case_DLak","akAlphaT_2Jets_case_DL",400,0,20);  
  TH1F *hist_alphatdis_twoPFjets_DLak = new TH1F("AlphaT_2PFJets_case_DLak","akAlphaT_2PFJets_case_DL",400,0,20);  

  TH1F *hist_alphat_njets_minimum_deltaht_SLak = new TH1F("Alphat_njets_case_minimum_deltaht_SLak","akAlphat_njets_case_minimum_deltaht_SL",400,0,20);
  TH1F *hist_alphat_nPFjets_minimum_deltaht_SLak = new TH1F("Alphat_nPFjets_case_minimum_deltaht_SLak","akAlphat_nPFjets_case_minimum_deltaht_SL",400,0,20);
  TH1F *hist_alphat_njets_minimum_deltaht_DLak = new TH1F("Alphat_njets_case_minimum_deltaht_DLak","akAlphat_njets_case_minimum_deltaht_DL",400,0,20);
  TH1F *hist_alphat_nPFjets_minimum_deltaht_DLak = new TH1F("Alphat_nPFjets_case_minimum_deltaht_DLak","akAlphat_nPFjets_case_minimum_deltaht_DL",400,0,20);

  TH1F *hist_alphat_njets_as_reclustered_SLak = new TH1F("Alphat_njets_case_as_reclustered_SLak","akAlphat_njets_case_as_reclustered_SL",400,0,20);
  TH1F *hist_alphat_nPFjets_as_reclustered_SLak = new TH1F("Alphat_nPFjets_case_as_reclustered_SLak","akAlphat_nPFjets_case_as_reclustered_SL",400,0,20);
  TH1F *hist_alphat_njets_as_reclustered_DLak = new TH1F("Alphat_njets_case_as_reclustered_DLak","akAlphat_njets_case_as_reclustered_DL",400,0,20);
  TH1F *hist_alphat_nPFjets_as_reclustered_DLak = new TH1F("Alphat_nPFjets_case_as_reclustered_DLak","akAlphat_nPFjets_case_as_reclustered_DL",400,0,20);

  hist_alphatdis_twojets_SL->Sumw2();
  hist_alphatdis_twoPFjets_SL->Sumw2();
  hist_alphatdis_twojets_DL->Sumw2();
  hist_alphatdis_twoPFjets_DL->Sumw2();

  hist_alphat_njets_minimum_deltaht_SL->Sumw2();
  hist_alphat_nPFjets_minimum_deltaht_SL->Sumw2();
  hist_alphat_njets_minimum_deltaht_DL->Sumw2();
  hist_alphat_nPFjets_minimum_deltaht_DL->Sumw2();

  hist_alphat_njets_as_reclustered_SL->Sumw2();
  hist_alphat_nPFjets_as_reclustered_SL->Sumw2();
  hist_alphat_njets_as_reclustered_DL->Sumw2();
  hist_alphat_nPFjets_as_reclustered_DL->Sumw2();

  hist_alphat_twojets->Sumw2();
  hist_alphat_njets_minimum_deltaht->Sumw2();
  hist_alphat_njets_as_two_jets->Sumw2();
  hist_alphat_njets_as_reclustered->Sumw2();
  hist_alphat_njets_as_reclustered_recomputed_ht->Sumw2();
  hist_alphat_twoPFjets->Sumw2();
  hist_alphat_nPFjets_minimum_deltaht->Sumw2();
  hist_alphat_nPFjets_as_two_jets->Sumw2();
  hist_alphat_nPFjets_as_reclustered->Sumw2();
  hist_alphat_nPFjets_as_reclustered_recomputed_ht->Sumw2();
  hist_deltaeta_vs_deltaphi_2jets->Sumw2();
  hist_deltaeta_vs_deltaphi_2PFjets->Sumw2();
  hist_deltaeta_vs_deltaphi_njets->Sumw2();
  hist_deltaeta_vs_deltaphi_njets_recluster->Sumw2();
  hist_deltaeta_vs_deltaphi_nPFjets_recluster->Sumw2();
  hist_deltaeta_vs_deltaphi_nPFjets->Sumw2();
  hist_alphat_SLCuts->Sumw2();
  hist_alphat_PFSLCuts->Sumw2();
  hist_alphat_DLCuts->Sumw2();
  hist_alphat_PFDLCuts->Sumw2();
  hist_alphat_re_SLCuts->Sumw2();
  hist_alphat_re_PFSLCuts->Sumw2();
  hist_alphat_re_DLCuts->Sumw2();
  hist_alphat_re_PFDLCuts->Sumw2();

  hist_alphat_2j_SLCuts->Sumw2();
  hist_alphat_2j_PFSLCuts->Sumw2();
  hist_alphat_2j_DLCuts->Sumw2();
  hist_alphat_2j_PFDLCuts->Sumw2();

  hist_alphat_nj_SLCuts->Sumw2();
  hist_alphat_nj_PFSLCuts->Sumw2();
  hist_alphat_nj_DLCuts->Sumw2();
  hist_alphat_nj_PFDLCuts->Sumw2();
  hist_alphat_nj_re_SLCuts->Sumw2();
  hist_alphat_nj_re_PFSLCuts->Sumw2();
  hist_alphat_nj_re_DLCuts->Sumw2();
  hist_alphat_nj_re_PFDLCuts->Sumw2();

  /////////////////////////////////
  hist_alphatdis_twojets_SLak->Sumw2();
  hist_alphatdis_twoPFjets_SLak->Sumw2();
  hist_alphatdis_twojets_DLak->Sumw2();
  hist_alphatdis_twoPFjets_DLak->Sumw2();

  hist_alphat_njets_minimum_deltaht_SLak->Sumw2();
  hist_alphat_nPFjets_minimum_deltaht_SLak->Sumw2();
  hist_alphat_njets_minimum_deltaht_DLak->Sumw2();
  hist_alphat_nPFjets_minimum_deltaht_DLak->Sumw2();

  hist_alphat_njets_as_reclustered_SLak->Sumw2();
  hist_alphat_nPFjets_as_reclustered_SLak->Sumw2();
  hist_alphat_njets_as_reclustered_DLak->Sumw2();
  hist_alphat_nPFjets_as_reclustered_DLak->Sumw2();

  hist_alphat_twojetsak->Sumw2();
  hist_alphat_njets_minimum_deltahtak->Sumw2();
  hist_alphat_njets_as_two_jetsak->Sumw2();
  hist_alphat_njets_as_reclusteredak->Sumw2();
  hist_alphat_njets_as_reclustered_recomputed_htak->Sumw2();
  hist_alphat_twoPFjetsak->Sumw2();
  hist_alphat_nPFjets_minimum_deltahtak->Sumw2();
  hist_alphat_nPFjets_as_two_jetsak->Sumw2();
  hist_alphat_nPFjets_as_reclusteredak->Sumw2();
  hist_alphat_nPFjets_as_reclustered_recomputed_htak->Sumw2();
  hist_deltaeta_vs_deltaphi_2jetsak->Sumw2();
  hist_deltaeta_vs_deltaphi_2PFjetsak->Sumw2();
  hist_deltaeta_vs_deltaphi_njetsak->Sumw2();
  hist_deltaeta_vs_deltaphi_njets_reclusterak->Sumw2();
  hist_deltaeta_vs_deltaphi_nPFjets_reclusterak->Sumw2();
  hist_deltaeta_vs_deltaphi_nPFjetsak->Sumw2();
  hist_alphat_SLCutsak->Sumw2();
  hist_alphat_PFSLCutsak->Sumw2();
  hist_alphat_DLCutsak->Sumw2();
  hist_alphat_PFDLCutsak->Sumw2();
  hist_alphat_re_SLCutsak->Sumw2();
  hist_alphat_re_PFSLCutsak->Sumw2();
  hist_alphat_re_DLCutsak->Sumw2();
  hist_alphat_re_PFDLCutsak->Sumw2();

  hist_alphat_2j_SLCutsak->Sumw2();
  hist_alphat_2j_PFSLCutsak->Sumw2();
  hist_alphat_2j_DLCutsak->Sumw2();
  hist_alphat_2j_PFDLCutsak->Sumw2();

  hist_alphat_nj_SLCutsak->Sumw2();
  hist_alphat_nj_PFSLCutsak->Sumw2();
  hist_alphat_nj_DLCutsak->Sumw2();
  hist_alphat_nj_PFDLCutsak->Sumw2();
  hist_alphat_nj_re_SLCutsak->Sumw2();
  hist_alphat_nj_re_PFSLCutsak->Sumw2();
  hist_alphat_nj_re_DLCutsak->Sumw2();
  hist_alphat_nj_re_PFDLCutsak->Sumw2();


  Alphat_Fol->Add(hist_alphat_twojets);
  Alphat_Fol->Add(hist_alphat_njets_minimum_deltaht);
  Alphat_Fol->Add(hist_alphat_njets_as_two_jets);
  Alphat_Fol->Add(hist_alphat_njets_as_reclustered);
  Alphat_Fol->Add(hist_alphat_njets_as_reclustered_recomputed_ht);
  Alphat_Fol->Add(hist_alphat_twoPFjets);
  Alphat_Fol->Add(hist_alphat_nPFjets_minimum_deltaht);
  Alphat_Fol->Add(hist_alphat_nPFjets_as_two_jets);
  Alphat_Fol->Add(hist_alphat_nPFjets_as_reclustered);
  Alphat_Fol->Add(hist_alphat_nPFjets_as_reclustered_recomputed_ht);
  Alphat_Fol->Add(hist_deltaeta_vs_deltaphi_2jets);
  Alphat_Fol->Add(hist_deltaeta_vs_deltaphi_2PFjets);
  Alphat_Fol->Add(hist_deltaeta_vs_deltaphi_njets);
  Alphat_Fol->Add(hist_deltaeta_vs_deltaphi_njets_recluster);
  Alphat_Fol->Add(hist_deltaeta_vs_deltaphi_nPFjets_recluster);
  Alphat_Fol->Add(hist_deltaeta_vs_deltaphi_nPFjets);

  Alphat_Fol->Add(hist_alphat_SLCuts);
  Alphat_Fol->Add(hist_alphat_PFSLCuts);
  Alphat_Fol->Add(hist_alphat_DLCuts);
  Alphat_Fol->Add(hist_alphat_PFDLCuts);
  Alphat_Fol->Add(hist_alphat_re_SLCuts);
  Alphat_Fol->Add(hist_alphat_re_PFSLCuts);
  Alphat_Fol->Add(hist_alphat_re_DLCuts);
  Alphat_Fol->Add(hist_alphat_re_PFDLCuts);

  Alphat_Fol->Add(hist_alphat_2j_SLCuts);
  Alphat_Fol->Add(hist_alphat_2j_PFSLCuts);
  Alphat_Fol->Add(hist_alphat_2j_DLCuts);
  Alphat_Fol->Add(hist_alphat_2j_PFDLCuts);

  Alphat_Fol->Add(hist_alphat_nj_SLCuts);
  Alphat_Fol->Add(hist_alphat_nj_PFSLCuts);
  Alphat_Fol->Add(hist_alphat_nj_DLCuts);
  Alphat_Fol->Add(hist_alphat_nj_PFDLCuts);
  Alphat_Fol->Add(hist_alphat_nj_re_SLCuts);
  Alphat_Fol->Add(hist_alphat_nj_re_PFSLCuts);
  Alphat_Fol->Add(hist_alphat_nj_re_DLCuts);
  Alphat_Fol->Add(hist_alphat_nj_re_PFDLCuts);

  Alphat_Fol->Add(hist_alphatdis_twojets_SL);
  Alphat_Fol->Add(hist_alphatdis_twoPFjets_SL);
  Alphat_Fol->Add(hist_alphatdis_twojets_DL);
  Alphat_Fol->Add(hist_alphatdis_twoPFjets_DL);

  Alphat_Fol->Add(hist_alphat_njets_minimum_deltaht_SL);
  Alphat_Fol->Add(hist_alphat_nPFjets_minimum_deltaht_SL);
  Alphat_Fol->Add(hist_alphat_njets_minimum_deltaht_DL);
  Alphat_Fol->Add(hist_alphat_nPFjets_minimum_deltaht_DL);

  Alphat_Fol->Add(hist_alphat_njets_as_reclustered_SL);
  Alphat_Fol->Add(hist_alphat_nPFjets_as_reclustered_SL);
  Alphat_Fol->Add(hist_alphat_njets_as_reclustered_DL);
  Alphat_Fol->Add(hist_alphat_nPFjets_as_reclustered_DL);
  ////////////////////////////

  Alphat_Fol->Add(hist_alphat_twojetsak);
  Alphat_Fol->Add(hist_alphat_njets_minimum_deltahtak);
  Alphat_Fol->Add(hist_alphat_njets_as_two_jetsak);
  Alphat_Fol->Add(hist_alphat_njets_as_reclusteredak);
  Alphat_Fol->Add(hist_alphat_njets_as_reclustered_recomputed_htak);
  Alphat_Fol->Add(hist_alphat_twoPFjetsak);
  Alphat_Fol->Add(hist_alphat_nPFjets_minimum_deltahtak);
  Alphat_Fol->Add(hist_alphat_nPFjets_as_two_jetsak);
  Alphat_Fol->Add(hist_alphat_nPFjets_as_reclusteredak);
  Alphat_Fol->Add(hist_alphat_nPFjets_as_reclustered_recomputed_htak);
  Alphat_Fol->Add(hist_deltaeta_vs_deltaphi_2jetsak);
  Alphat_Fol->Add(hist_deltaeta_vs_deltaphi_2PFjetsak);
  Alphat_Fol->Add(hist_deltaeta_vs_deltaphi_njetsak);
  Alphat_Fol->Add(hist_deltaeta_vs_deltaphi_njets_reclusterak);
  Alphat_Fol->Add(hist_deltaeta_vs_deltaphi_nPFjets_reclusterak);
  Alphat_Fol->Add(hist_deltaeta_vs_deltaphi_nPFjetsak);

  Alphat_Fol->Add(hist_alphat_SLCutsak);
  Alphat_Fol->Add(hist_alphat_PFSLCutsak);
  Alphat_Fol->Add(hist_alphat_DLCutsak);
  Alphat_Fol->Add(hist_alphat_PFDLCutsak);
  Alphat_Fol->Add(hist_alphat_re_SLCutsak);
  Alphat_Fol->Add(hist_alphat_re_PFSLCutsak);
  Alphat_Fol->Add(hist_alphat_re_DLCutsak);
  Alphat_Fol->Add(hist_alphat_re_PFDLCutsak);

  Alphat_Fol->Add(hist_alphat_2j_SLCutsak);
  Alphat_Fol->Add(hist_alphat_2j_PFSLCutsak);
  Alphat_Fol->Add(hist_alphat_2j_DLCutsak);
  Alphat_Fol->Add(hist_alphat_2j_PFDLCutsak);

  Alphat_Fol->Add(hist_alphat_nj_SLCutsak);
  Alphat_Fol->Add(hist_alphat_nj_PFSLCutsak);
  Alphat_Fol->Add(hist_alphat_nj_DLCutsak);
  Alphat_Fol->Add(hist_alphat_nj_PFDLCutsak);
  Alphat_Fol->Add(hist_alphat_nj_re_SLCutsak);
  Alphat_Fol->Add(hist_alphat_nj_re_PFSLCutsak);
  Alphat_Fol->Add(hist_alphat_nj_re_DLCutsak);
  Alphat_Fol->Add(hist_alphat_nj_re_PFDLCutsak);

  Alphat_Fol->Add(hist_alphatdis_twojets_SLak);
  Alphat_Fol->Add(hist_alphatdis_twoPFjets_SLak);
  Alphat_Fol->Add(hist_alphatdis_twojets_DLak);
  Alphat_Fol->Add(hist_alphatdis_twoPFjets_DLak);

  Alphat_Fol->Add(hist_alphat_njets_minimum_deltaht_SLak);
  Alphat_Fol->Add(hist_alphat_nPFjets_minimum_deltaht_SLak);
  Alphat_Fol->Add(hist_alphat_njets_minimum_deltaht_DLak);
  Alphat_Fol->Add(hist_alphat_nPFjets_minimum_deltaht_DLak);

  Alphat_Fol->Add(hist_alphat_njets_as_reclustered_SLak);
  Alphat_Fol->Add(hist_alphat_nPFjets_as_reclustered_SLak);
  Alphat_Fol->Add(hist_alphat_njets_as_reclustered_DLak);
  Alphat_Fol->Add(hist_alphat_nPFjets_as_reclustered_DLak);

  TH1F *hist_alphat_twojets_dif = new TH1F("Delta_SRandPF_alphat_twojets_present","Delta_SRandPF_alphat_twojets_present",200,-10,10);
  TH1F *hist_alphat_twoSRjets_notwoPFjets_metdif = new TH1F("Delta_SR_vs_PF_MET_alphat_twoSRjets_notwoPFjets","Delta_SR_vs_PF_MET_alphat_twoSRjets_notwoPFjets",200,-200,200);  
  TH1F *hist_alphat_twoSRjets_twoPFjets_metdif = new TH1F("Delta_SR_vs_PF_MET_alphat_twoSRjets_twoPFjets","Delta_SR_vs_PF_MET_alphat_twoSRjets_twoPFjets",200,-200,200);  
  TH1F *hist_totht_dif_sr_vs_pf = new TH1F("Diff_Tot_HT_SR_vs_PF","Diff_Tot_HT_SR_vs_PF",200,-200,200);
  TH1F *hist_totht_dif_sr_vs_pf_nopftwojets = new TH1F("Diff_Tot_HT_SR_vs_PF_nopftwojets","Diff_Tot_HT_SR_vs_PF_nopftwojets",200,-200,2000);
  TH1F *hist_dif_alphat_mindht_SR_PF = new TH1F("Diff_MinDHt_SR-PF","Diff_MinDHt_SR-PF",200,-20,20);
  TH1F *hist_dif_alphat_Reclus_SR_PF = new TH1F("Diff_Reclus_SR-PF","Diff_Reclus_SR-PF",200,-20,20);
  TH1F *hist_dif_alphat_SR_mindht_reclus = new TH1F("Diff_SR_MinDHt-Reclus","Diff_SR_MinDHt-Reclus",200,-20,20);
  TH1F *hist_dif_alphat_PF_mindht_reclus = new TH1F("Diff_PF_MinDHt-Reclus","Diff_PF_MinDHt-Reclus",200,-20,20);
  TH2F *hist_deltaeta_vs_deltaphi_peakPF_recluster = new TH2F("DeltaEta_vs_DeltaPhi_peakPF_recluster","DeltaEta_vs_DeltaPhi_peakPF_recluster",240,-6,6,200,-5,5);

  TH2F *hist_deltaeta_vs_deltaphi_peakPF_mindht = new TH2F("DeltaEta_vs_DeltaPhi_peakPF_mindht","DeltaEta_vs_DeltaPhi_peakPF_mindht",240,-6,6,200,-5,5);
  TH2F *hist_deltaeta_vs_deltaphi_peakSR_recluster = new TH2F("DeltaEta_vs_DeltaPhi_peakSR_recluster","DeltaEta_vs_DeltaPhi_peakSR_recluster",240,-6,6,200,-5,5);
  TH2F *hist_deltaeta_vs_deltaphi_peakSR_mindht = new TH2F("DeltaEta_vs_DeltaPhi_peakSR_mindht","DeltaEta_vs_DeltaPhi_peakSR_mindht",240,-6,6,200,-5,5);

  TH2F *hist_deltaeta_vs_deltaphi_peakSR_recluster_1p = new TH2F("DeltaEta_vs_DeltaPhi_peakSR_recluster_1p","DeltaEta_vs_DeltaPhi_peakSR_recluster_1p",240,-6,6,200,-5,5);
  TH2F *hist_deltaeta_vs_deltaphi_peakSR_mindht_1p = new TH2F("DeltaEta_vs_DeltaPhi_peakSR_mindht_1p","DeltaEta_vs_DeltaPhi_peakSR_mindht_1p",240,-6,6,200,-5,5);

  TH1F *hist_deltaeta_firstjet_peakPF_mindht_recluster = new TH1F("DeltaEta_firstjet_peakPF_mindht_recluster","DeltaEta_firstjet_peakPF_mindht_recluster",50,-10,10);
  TH1F *hist_deltaphi_firstjet_peakPF_mindht_recluster = new TH1F("DeltaPhi_firstjet_peakPF_mindht_recluster","DeltaPhi_firstjet_peakPF_mindht_recluster",120,-6,6);
  TH1F *hist_deltaeta_secondjet_peakPF_mindht_recluster = new TH1F("DeltaEta_secondjet_peakPF_mindht_recluster","DeltaEta_secondjet_peakPF_mindht_recluster",50,-10,10);
  TH1F *hist_deltaphi_secondjet_peakPF_mindht_recluster = new TH1F("DeltaPhi_secondjet_peakPF_mindht_recluster","DeltaPhi_secondjet_peakPF_mindht_recluster",120,-6,6);
  TH1F *hist_deltaeta_firstjet_peakSR_mindht_recluster = new TH1F("DeltaEta_firstjet_peakSR_mindht_recluster","DeltaEta_firstjet_peakSR_mindht_recluster",50,-10,10);
  TH1F *hist_deltaphi_firstjet_peakSR_mindht_recluster = new TH1F("DeltaPhi_firstjet_peakSR_mindht_recluster","DeltaPhi_firstjet_peakSR_mindht_recluster",120,-6,6);
  TH1F *hist_deltaeta_secondjet_peakSR_mindht_recluster = new TH1F("DeltaEta_secondjet_peakSR_mindht_recluster","DeltaEta_secondjet_peakSR_mindht_recluster",50,-10,10);
  TH1F *hist_deltaphi_secondjet_peakSR_mindht_recluster = new TH1F("DeltaPhi_secondjet_peakSR_mindht_recluster","DeltaPhi_secondjet_peakSR_mindht_recluster",120,-6,6);
  TH1F *hist_deltaeta_firstjet_peak_SR_vs_PF_mindht = new TH1F("DeltaEta_firstjet_peak_SR_vs_PF_mindht","DeltaEta_firstjet_peak_SR_vs_PF_mindht",50,-10,10);
  TH1F *hist_deltaphi_firstjet_peak_SR_vs_PF_mindht = new TH1F("DeltaPhi_firstjet_peak_SR_vs_PF_mindht","DeltaPhi_firstjet_peak_SR_vs_PF_mindht",120,-6,6);
  TH1F *hist_deltaeta_secondjet_peak_SR_vs_PF_mindht = new TH1F("DeltaEta_secondjet_peak_SR_vs_PF_mindht","DeltaEta_secondjet_peak_SR_vs_PF_mindht",50,-10,10);
  TH1F *hist_deltaphi_secondjet_peak_SR_vs_PF_mindht = new TH1F("DeltaPhi_secondjet_peak_SR_vs_PF_mindht","DeltaPhi_secondjet_peak_SR_vs_PF_mindht",120,-6,6);
  TH1F *hist_deltaeta_firstjet_peak_SR_vs_PF_recluster = new TH1F("DeltaEta_firstjet_peak_SR_vs_PF_recluster","DeltaEta_firstjet_peak_SR_vs_PF_recluster",50,-10,10);
  TH1F *hist_deltaphi_firstjet_peak_SR_vs_PF_recluster = new TH1F("DeltaPhi_firstjet_peak_SR_vs_PF_recluster","DeltaPhi_firstjet_peak_SR_vs_PF_recluster",120,-6,6);
  TH1F *hist_deltaeta_secondjet_peak_SR_vs_PF_recluster = new TH1F("DeltaEta_secondjet_peak_SR_vs_PF_recluster","DeltaEta_secondjet_peak_SR_vs_PF_recluster",50,-10,10);
  TH1F *hist_deltaphi_secondjet_peak_SR_vs_PF_recluster = new TH1F("DeltaPhi_secondjet_peak_SR_vs_PF_recluster","DeltaPhi_secondjet_peak_SR_vs_PF_recluster",120,-6,6);


  TH1F *hist_firstPFjet_peak_pt = new TH1F("FirstPFJet_pt_peak","FirstPFJet_pt_peak",100,0,500);
  TH1F *hist_firstPFjet_peak_eta = new TH1F("FirstPFJet_eta_peak","FirstPFJet_eta_peak",100,-5,5);
  TH1F *hist_firstPFjet_peak_phi = new TH1F("FirstPFJet_phi_peak","FirstPFJet_phi_peak",100,-6.5,6.5);
  TH1F *hist_secondPFjet_peak_pt = new TH1F("SecondPFJet_pt_peak","SecondPFJet_pt_peak",100,0,500);
  TH1F *hist_secondPFjet_peak_eta = new TH1F("SecondPFJet_eta_peak","SecondPFJet_eta_peak",100,-5,5);
  TH1F *hist_secondPFjet_peak_phi = new TH1F("SecondPFJet_phi_peak","SecondPFJet_phi_peak",100,-6.5,6.5);
  TH1F *hist_firstSRjet_peak_pt = new TH1F("FirstSRJet_pt_peak","FirstSRJet_pt_peak",100,0,500);
  TH1F *hist_firstSRjet_peak_eta = new TH1F("FirstSRJet_eta_peak","FirstSRJet_eta_peak",100,-5,5);
  TH1F *hist_firstSRjet_peak_phi = new TH1F("FirstSRJet_phi_peak","FirstSRJet_phi_peak",100,-6.5,6.5);
  TH1F *hist_secondSRjet_peak_pt = new TH1F("SecondSRJet_pt_peak","SecondSRJet_pt_peak",100,0,500);
  TH1F *hist_secondSRjet_peak_eta = new TH1F("SecondSRJet_eta_peak","SecondSRJet_eta_peak",100,-5,5);
  TH1F *hist_secondSRjet_peak_phi = new TH1F("SecondSRJet_phi_peak","SecondSRJet_phi_peak",100,-6.5,6.5);

  hist_alphat_twojets_dif->Sumw2();
  hist_alphat_twoSRjets_notwoPFjets_metdif->Sumw2();
  hist_alphat_twoSRjets_twoPFjets_metdif->Sumw2();
  hist_totht_dif_sr_vs_pf->Sumw2();
  hist_totht_dif_sr_vs_pf_nopftwojets->Sumw2();
  hist_dif_alphat_mindht_SR_PF->Sumw2();
  hist_dif_alphat_Reclus_SR_PF->Sumw2();
  hist_dif_alphat_SR_mindht_reclus->Sumw2();
  hist_dif_alphat_PF_mindht_reclus->Sumw2();
  hist_deltaeta_vs_deltaphi_peakPF_recluster->Sumw2();
  hist_firstPFjet_peak_pt->Sumw2();
  hist_firstPFjet_peak_eta->Sumw2();
  hist_firstPFjet_peak_phi->Sumw2();
  hist_secondPFjet_peak_pt->Sumw2();
  hist_secondPFjet_peak_eta->Sumw2();
  hist_secondPFjet_peak_phi->Sumw2();
  hist_firstSRjet_peak_pt->Sumw2();
  hist_firstSRjet_peak_eta->Sumw2();
  hist_firstSRjet_peak_phi->Sumw2();
  hist_secondSRjet_peak_pt->Sumw2();
  hist_secondSRjet_peak_eta->Sumw2();
  hist_secondSRjet_peak_phi->Sumw2();

  hist_deltaeta_vs_deltaphi_peakPF_mindht->Sumw2();
  hist_deltaeta_vs_deltaphi_peakSR_recluster->Sumw2();
  hist_deltaeta_vs_deltaphi_peakSR_mindht->Sumw2();

  hist_deltaeta_vs_deltaphi_peakSR_recluster_1p->Sumw2();
  hist_deltaeta_vs_deltaphi_peakSR_mindht_1p->Sumw2();

  hist_deltaeta_firstjet_peakPF_mindht_recluster->Sumw2();
  hist_deltaphi_firstjet_peakPF_mindht_recluster->Sumw2();
  hist_deltaeta_secondjet_peakPF_mindht_recluster->Sumw2();
  hist_deltaphi_secondjet_peakPF_mindht_recluster->Sumw2();
  hist_deltaeta_firstjet_peakSR_mindht_recluster->Sumw2();
  hist_deltaphi_firstjet_peakSR_mindht_recluster->Sumw2();
  hist_deltaeta_secondjet_peakSR_mindht_recluster->Sumw2();
  hist_deltaphi_secondjet_peakSR_mindht_recluster->Sumw2();
  hist_deltaeta_firstjet_peak_SR_vs_PF_mindht->Sumw2();
  hist_deltaphi_firstjet_peak_SR_vs_PF_mindht->Sumw2();
  hist_deltaeta_secondjet_peak_SR_vs_PF_mindht->Sumw2();
  hist_deltaphi_secondjet_peak_SR_vs_PF_mindht->Sumw2();
  hist_deltaeta_firstjet_peak_SR_vs_PF_recluster->Sumw2();
  hist_deltaphi_firstjet_peak_SR_vs_PF_recluster->Sumw2();
  hist_deltaeta_secondjet_peak_SR_vs_PF_recluster->Sumw2();
  hist_deltaphi_secondjet_peak_SR_vs_PF_recluster->Sumw2();

  dif_two_jets->Add(hist_alphat_twojets_dif);
  dif_two_jets->Add(hist_alphat_twoSRjets_notwoPFjets_metdif);
  dif_two_jets->Add(hist_alphat_twoSRjets_twoPFjets_metdif);
  dif_two_jets->Add(hist_totht_dif_sr_vs_pf);
  dif_two_jets->Add(hist_totht_dif_sr_vs_pf_nopftwojets);
  dif_two_jets->Add(hist_dif_alphat_mindht_SR_PF);
  dif_two_jets->Add(hist_dif_alphat_Reclus_SR_PF);
  dif_two_jets->Add(hist_dif_alphat_SR_mindht_reclus);
  dif_two_jets->Add(hist_dif_alphat_PF_mindht_reclus);
  dif_two_jets->Add(hist_deltaeta_vs_deltaphi_peakPF_recluster);
  dif_two_jets->Add(hist_firstPFjet_peak_pt);
  dif_two_jets->Add(hist_firstPFjet_peak_eta);
  dif_two_jets->Add(hist_firstPFjet_peak_phi);
  dif_two_jets->Add(hist_secondPFjet_peak_pt);
  dif_two_jets->Add(hist_secondPFjet_peak_eta);
  dif_two_jets->Add(hist_secondPFjet_peak_phi);
  dif_two_jets->Add(hist_firstSRjet_peak_pt);
  dif_two_jets->Add(hist_firstSRjet_peak_eta);
  dif_two_jets->Add(hist_firstSRjet_peak_phi);
  dif_two_jets->Add(hist_secondSRjet_peak_pt);
  dif_two_jets->Add(hist_secondSRjet_peak_eta);
  dif_two_jets->Add(hist_secondSRjet_peak_phi);
  dif_two_jets->Add(hist_deltaeta_vs_deltaphi_peakPF_mindht);
  dif_two_jets->Add(hist_deltaeta_vs_deltaphi_peakSR_recluster);
  dif_two_jets->Add(hist_deltaeta_vs_deltaphi_peakSR_mindht);

  dif_two_jets->Add(hist_deltaeta_vs_deltaphi_peakSR_recluster_1p);
  dif_two_jets->Add(hist_deltaeta_vs_deltaphi_peakSR_mindht_1p);

  dif_two_jets->Add(hist_deltaeta_firstjet_peakPF_mindht_recluster);
  dif_two_jets->Add(hist_deltaphi_firstjet_peakPF_mindht_recluster);
  dif_two_jets->Add(hist_deltaeta_secondjet_peakPF_mindht_recluster);
  dif_two_jets->Add(hist_deltaphi_secondjet_peakPF_mindht_recluster);
  dif_two_jets->Add(hist_deltaeta_firstjet_peakSR_mindht_recluster);
  dif_two_jets->Add(hist_deltaphi_firstjet_peakSR_mindht_recluster);
  dif_two_jets->Add(hist_deltaeta_secondjet_peakSR_mindht_recluster);
  dif_two_jets->Add(hist_deltaphi_secondjet_peakSR_mindht_recluster);
  dif_two_jets->Add(hist_deltaeta_firstjet_peak_SR_vs_PF_mindht);
  dif_two_jets->Add(hist_deltaphi_firstjet_peak_SR_vs_PF_mindht);
  dif_two_jets->Add(hist_deltaeta_secondjet_peak_SR_vs_PF_mindht);
  dif_two_jets->Add(hist_deltaphi_secondjet_peak_SR_vs_PF_mindht);
  dif_two_jets->Add(hist_deltaeta_firstjet_peak_SR_vs_PF_recluster);
  dif_two_jets->Add(hist_deltaphi_firstjet_peak_SR_vs_PF_recluster);
  dif_two_jets->Add(hist_deltaeta_secondjet_peak_SR_vs_PF_recluster);
  dif_two_jets->Add(hist_deltaphi_secondjet_peak_SR_vs_PF_recluster);

  TH1F *hist_ele_multiplicity_after_pt_cut = new TH1F("Electron_multiplicity_after_pt_cut","Electron_multiplicity_after_pt_cut",10,0,10);
  TH1F *hist_PFele_multiplicity_after_pt_cut = new TH1F("PFElectron_multiplicity_after_pt_cut","PFElectron_multiplicity_after_pt_cut",10,0,10);
  TH2F *hist_ele_loose_pt_eta = new TH2F("Loose_Electrons_pt_eta","Loose_Electrons_pt_eta",100,0,500,24,-3,3);
  TH2F *hist_ele_tight_pt_eta = new TH2F("Tight_Electrons_pt_eta","Tight_Electrons_pt_eta",100,0,500,24,-3,3);
  TH2F *hist_pfele_loose_pt_eta = new TH2F("Loose_PFElectrons_pt_eta","Loose_PFElectrons_pt_eta",100,0,500,24,-3,3);
  TH2F *hist_pfele_tight_pt_eta = new TH2F("Tight_PFElectrons_pt_eta","Tight_PFElectrons_pt_eta",100,0,500,24,-3,3);
  TH1F *hist_el_invmass = new TH1F("El_invmass","El_invmass",100,0,500);
  TH1F *hist_pfel_invmass = new TH1F("PFEl_invmass","PFEl_invmass",100,0,500);
  TH1F *hist_ell_invmass = new TH1F("El_loose_invmass","El_loose_invmass",100,0,500);
  TH1F *hist_pfell_invmass = new TH1F("PFEl_loose_invmass","PFEl_loose_invmass",100,0,500);

  hist_ele_multiplicity_after_pt_cut->Sumw2();
  hist_PFele_multiplicity_after_pt_cut->Sumw2();
  hist_ele_loose_pt_eta->Sumw2();
  hist_ele_tight_pt_eta->Sumw2();
  hist_pfele_loose_pt_eta->Sumw2();
  hist_pfele_tight_pt_eta->Sumw2();
  hist_el_invmass->Sumw2();
  hist_pfel_invmass->Sumw2();
  hist_ell_invmass->Sumw2();
  hist_pfell_invmass->Sumw2();

  El_Fol->Add(hist_ele_multiplicity_after_pt_cut);
  El_Fol->Add(hist_PFele_multiplicity_after_pt_cut);
  El_Fol->Add(hist_ele_loose_pt_eta);
  El_Fol->Add(hist_ele_tight_pt_eta);
  El_Fol->Add(hist_pfele_loose_pt_eta);
  El_Fol->Add(hist_pfele_tight_pt_eta);
  El_Fol->Add(hist_el_invmass);
  El_Fol->Add(hist_pfel_invmass);
  El_Fol->Add(hist_ell_invmass);
  El_Fol->Add(hist_pfell_invmass);

  TH2F *hist_muo_loose_pt_eta = new TH2F("Loose_Muons_pt_eta","Loose_Muons_pt_eta",100,0,500,24,-3,3);
  TH2F *hist_muo_tight_pt_eta = new TH2F("Tight_Muons_pt_eta","Tight_Muons_pt_eta",100,0,500,24,-3,3);
  TH2F *hist_pfmuo_loose_pt_eta = new TH2F("Loose_PFMuons_pt_eta","Loose_PFMuons_pt_eta",100,0,500,24,-3,3);
  TH2F *hist_pfmuo_tight_pt_eta = new TH2F("Tight_PFMuons_pt_eta","Tight_PFMuons_pt_eta",100,0,500,24,-3,3);

  TH1F *hist_mu_invmass = new TH1F("Mu_invmass","Mu_invmass",100,0,500);
  TH1F *hist_pfmu_invmass = new TH1F("PFMu_invmass","PFMu_invmass",100,0,500);
  TH1F *hist_mul_invmass = new TH1F("Mu_loose_invmass","Mu_loose_invmass",100,0,500);
  TH1F *hist_pfmul_invmass = new TH1F("PFMu_loose_invmass","PFMu_loose_invmass",100,0,500);

  hist_muo_loose_pt_eta->Sumw2();
  hist_muo_tight_pt_eta->Sumw2();
  hist_pfmuo_loose_pt_eta->Sumw2();
  hist_pfmuo_tight_pt_eta->Sumw2();
  hist_mu_invmass->Sumw2();
  hist_pfmu_invmass->Sumw2();
  hist_mul_invmass->Sumw2();
  hist_pfmul_invmass->Sumw2();

  Mu_Fol->Add(hist_muo_loose_pt_eta);
  Mu_Fol->Add(hist_muo_tight_pt_eta);
  Mu_Fol->Add(hist_pfmuo_loose_pt_eta);
  Mu_Fol->Add(hist_pfmuo_tight_pt_eta);
  Mu_Fol->Add(hist_mu_invmass);
  Mu_Fol->Add(hist_pfmu_invmass);
  Mu_Fol->Add(hist_mul_invmass);
  Mu_Fol->Add(hist_pfmul_invmass);

  TH2F *hist_tau_loose_pt_eta = new TH2F("Loose_Tau_pt_eta","Loose_Tau_pt_eta",100,0,500,24,-3,3);
  TH2F *hist_tau_tight_pt_eta = new TH2F("Tight_Tau_pt_eta","Tight_Tau_pt_eta",100,0,500,24,-3,3);
  TH2F *hist_pftau_loose_pt_eta = new TH2F("Loose_PFTau_pt_eta","Loose_PFTau_pt_eta",100,0,500,24,-3,3);
  TH2F *hist_pftau_tight_pt_eta = new TH2F("Tight_PFTau_pt_eta","Tight_PFTau_pt_eta",100,0,500,24,-3,3);

  hist_tau_loose_pt_eta->Sumw2();
  hist_tau_tight_pt_eta->Sumw2();
  hist_pftau_loose_pt_eta->Sumw2();
  hist_pftau_tight_pt_eta->Sumw2();

  Tau_Fol->Add(hist_tau_loose_pt_eta);
  Tau_Fol->Add(hist_tau_tight_pt_eta);
  Tau_Fol->Add(hist_pftau_loose_pt_eta);
  Tau_Fol->Add(hist_pftau_tight_pt_eta);

  TH1F *hist_2jets_dl_big2_eta_firstjet = new TH1F("Alphat_2Jets_case_DL_big2_eta_firstjet","Alphat_2Jets_case_DL_big2_eta_firstjet",100,-5,5);
  TH1F *hist_2jets_dl_big2_eta_secjet = new TH1F("Alphat_2Jets_case_DL_big2_eta_secjet","Alphat_2Jets_case_DL_big2_eta_secjet",100,-5,5);
  TH1F *hist_2jets_dl_big2_phi_firstjet = new TH1F("Alphat_2Jets_case_DL_big2_phi_firstjet","Alphat_2Jets_case_DL_big2_phi_firstjet",80,-4,4);
  TH1F *hist_2jets_dl_big2_phi_secjet = new TH1F("Alphat_2Jets_case_DL_big2_phi_secjet","Alphat_2Jets_case_DL_big2_phi_secjet",80,-4,4);
  TH2F *hist_2jets_dl_big2_etaphi_firstjet = new TH2F("Alphat_2Jets_case_DL_big2_etaphi_firstjet","Alphat_2Jets_case_DL_big2_etaphi_firstjet",80,-4,4,100,-5,5);
  TH2F *hist_2jets_dl_big2_etaphi_secjet = new TH2F("Alphat_2Jets_case_DL_big2_etaphi_secjet","Alphat_2Jets_case_DL_big2_etaphi_secjet",80,-4,4,100,-5,5);
  TH1F *hist_2jets_dl_big2_pt_firstjet = new TH1F("Alphat_2Jets_case_DL_big2_pt_firstjet","Alphat_2Jets_case_DL_big2_pt_firstjet",500,0,2000);
  TH1F *hist_2jets_dl_big2_pt_secjet = new TH1F("Alphat_2Jets_case_DL_big2_pt_secjet","Alphat_2Jets_case_DL_big2_pt_secjet",500,0,2000);
  TH2F *hist_deltaeta_vs_deltaphi_big2 = new TH2F("DeltaEta_vs_DeltaPhi_big2_case","DeltaEta_vs_DeltaPhi_big2_case",240,-6,6,200,-5,5);

  TH1F *hist_2jets_dl_smallreg_eta_firstjet = new TH1F("Alphat_2Jets_case_DL_smallreg_eta_firstjet","Alphat_2Jets_case_DL_smallreg_eta_firstjet",100,-5,5);
  TH1F *hist_2jets_dl_smallreg_eta_secjet = new TH1F("Alphat_2Jets_case_DL_smallreg_eta_secjet","Alphat_2Jets_case_DL_smallreg_eta_secjet",100,-5,5);
  TH1F *hist_2jets_dl_smallreg_phi_firstjet = new TH1F("Alphat_2Jets_case_DL_smallreg_phi_firstjet","Alphat_2Jets_case_DL_smallreg_phi_firstjet",80,-4,4);
  TH1F *hist_2jets_dl_smallreg_phi_secjet = new TH1F("Alphat_2Jets_case_DL_smallreg_phi_secjet","Alphat_2Jets_case_DL_smallreg_phi_secjet",80,-4,4);
  TH1F *hist_2jets_dl_smallreg_pt_firstjet = new TH1F("Alphat_2Jets_case_DL_smallreg_pt_firstjet","Alphat_2Jets_case_DL_smallreg_pt_firstjet",500,0,2000);
  TH1F *hist_2jets_dl_smallreg_pt_secjet = new TH1F("Alphat_2Jets_case_DL_smallreg_pt_secjet","Alphat_2Jets_case_DL_smallreg_pt_secjet",500,0,2000);
  TH2F *hist_deltaeta_vs_deltaphi_smallreg = new TH2F("DeltaEta_vs_DeltaPhi_smallreg_case","DeltaEta_vs_DeltaPhi_smallreg_case",240,-6,6,200,-5,5);

  TH1F *hist_2jets_dl_antismallreg_eta_firstjet = new TH1F("Alphat_2Jets_case_DL_antismallreg_eta_firstjet","Alphat_2Jets_case_DL_antismallreg_eta_firstjet",100,-5,5);
  TH1F *hist_2jets_dl_antismallreg_eta_secjet = new TH1F("Alphat_2Jets_case_DL_antismallreg_eta_secjet","Alphat_2Jets_case_DL_antismallreg_eta_secjet",100,-5,5);
  TH1F *hist_2jets_dl_antismallreg_phi_firstjet = new TH1F("Alphat_2Jets_case_DL_antismallreg_phi_firstjet","Alphat_2Jets_case_DL_antismallreg_phi_firstjet",80,-4,4);
  TH1F *hist_2jets_dl_antismallreg_phi_secjet = new TH1F("Alphat_2Jets_case_DL_antismallreg_phi_secjet","Alphat_2Jets_case_DL_antismallreg_phi_secjet",80,-4,4);
  TH1F *hist_2jets_dl_antismallreg_pt_firstjet = new TH1F("Alphat_2Jets_case_DL_antismallreg_pt_firstjet","Alphat_2Jets_case_DL_antismallreg_pt_firstjet",500,0,2000);
  TH1F *hist_2jets_dl_antismallreg_pt_secjet = new TH1F("Alphat_2Jets_case_DL_antismallreg_pt_secjet","Alphat_2Jets_case_DL_antismallreg_pt_secjet",500,0,2000);
  TH2F *hist_deltaeta_vs_deltaphi_antismallreg = new TH2F("DeltaEta_vs_DeltaPhi_antismallreg_case","DeltaEta_vs_DeltaPhi_antismallreg_case",240,-6,6,200,-5,5);

  TH2F *hist_deltaeta_vs_deltaphi_final = new TH2F("DeltaEta_vs_DeltaPhi_final_case","DeltaEta_vs_DeltaPhi_final_case",240,-6,6,200,-5,5);
  ///////////////////////////

  TH1F *hist_2jets_dl_big2_eta_firstjetak = new TH1F("Alphat_2Jets_case_DL_big2_eta_firstjetak","akAlphat_2Jets_case_DL_big2_eta_firstjet",100,-5,5);
  TH1F *hist_2jets_dl_big2_eta_secjetak = new TH1F("Alphat_2Jets_case_DL_big2_eta_secjetak","akAlphat_2Jets_case_DL_big2_eta_secjet",100,-5,5);
  TH1F *hist_2jets_dl_big2_phi_firstjetak = new TH1F("Alphat_2Jets_case_DL_big2_phi_firstjetak","akAlphat_2Jets_case_DL_big2_phi_firstjet",80,-4,4);
  TH1F *hist_2jets_dl_big2_phi_secjetak = new TH1F("Alphat_2Jets_case_DL_big2_phi_secjetak","akAlphat_2Jets_case_DL_big2_phi_secjet",80,-4,4);
  TH2F *hist_2jets_dl_big2_etaphi_firstjetak = new TH2F("Alphat_2Jets_case_DL_big2_etaphi_firstjetak","akAlphat_2Jets_case_DL_big2_etaphi_firstjet",80,-4,4,100,-5,5);
  TH2F *hist_2jets_dl_big2_etaphi_secjetak = new TH2F("Alphat_2Jets_case_DL_big2_etaphi_secjetak","akAlphat_2Jets_case_DL_big2_etaphi_secjet",80,-4,4,100,-5,5);
  TH1F *hist_2jets_dl_big2_pt_firstjetak = new TH1F("Alphat_2Jets_case_DL_big2_pt_firstjetak","akAlphat_2Jets_case_DL_big2_pt_firstjet",500,0,2000);
  TH1F *hist_2jets_dl_big2_pt_secjetak = new TH1F("Alphat_2Jets_case_DL_big2_pt_secjetak","akAlphat_2Jets_case_DL_big2_pt_secjet",500,0,2000);
  TH2F *hist_deltaeta_vs_deltaphi_big2ak = new TH2F("DeltaEta_vs_DeltaPhi_big2_caseak","akDeltaEta_vs_DeltaPhi_big2_case",240,-6,6,200,-5,5);

  TH1F *hist_2jets_dl_smallreg_eta_firstjetak = new TH1F("Alphat_2Jets_case_DL_smallreg_eta_firstjetak","akAlphat_2Jets_case_DL_smallreg_eta_firstjet",100,-5,5);
  TH1F *hist_2jets_dl_smallreg_eta_secjetak = new TH1F("Alphat_2Jets_case_DL_smallreg_eta_secjetak","akAlphat_2Jets_case_DL_smallreg_eta_secjet",100,-5,5);
  TH1F *hist_2jets_dl_smallreg_phi_firstjetak = new TH1F("Alphat_2Jets_case_DL_smallreg_phi_firstjetak","akAlphat_2Jets_case_DL_smallreg_phi_firstjet",80,-4,4);
  TH1F *hist_2jets_dl_smallreg_phi_secjetak = new TH1F("Alphat_2Jets_case_DL_smallreg_phi_secjetak","akAlphat_2Jets_case_DL_smallreg_phi_secjet",80,-4,4);
  TH1F *hist_2jets_dl_smallreg_pt_firstjetak = new TH1F("Alphat_2Jets_case_DL_smallreg_pt_firstjetak","akAlphat_2Jets_case_DL_smallreg_pt_firstjet",500,0,2000);
  TH1F *hist_2jets_dl_smallreg_pt_secjetak = new TH1F("Alphat_2Jets_case_DL_smallreg_pt_secjetak","akAlphat_2Jets_case_DL_smallreg_pt_secjet",500,0,2000);
  TH2F *hist_deltaeta_vs_deltaphi_smallregak = new TH2F("DeltaEta_vs_DeltaPhi_smallreg_caseak","akDeltaEta_vs_DeltaPhi_smallreg_case",240,-6,6,200,-5,5);

  TH1F *hist_2jets_dl_antismallreg_eta_firstjetak = new TH1F("Alphat_2Jets_case_DL_antismallreg_eta_firstjetak","akAlphat_2Jets_case_DL_antismallreg_eta_firstjet",100,-5,5);
  TH1F *hist_2jets_dl_antismallreg_eta_secjetak = new TH1F("Alphat_2Jets_case_DL_antismallreg_eta_secjetak","akAlphat_2Jets_case_DL_antismallreg_eta_secjet",100,-5,5);
  TH1F *hist_2jets_dl_antismallreg_phi_firstjetak = new TH1F("Alphat_2Jets_case_DL_antismallreg_phi_firstjetak","akAlphat_2Jets_case_DL_antismallreg_phi_firstjet",80,-4,4);
  TH1F *hist_2jets_dl_antismallreg_phi_secjetak = new TH1F("Alphat_2Jets_case_DL_antismallreg_phi_secjetak","akAlphat_2Jets_case_DL_antismallreg_phi_secjet",80,-4,4);
  TH1F *hist_2jets_dl_antismallreg_pt_firstjetak = new TH1F("Alphat_2Jets_case_DL_antismallreg_pt_firstjetak","akAlphat_2Jets_case_DL_antismallreg_pt_firstjet",500,0,2000);
  TH1F *hist_2jets_dl_antismallreg_pt_secjetak = new TH1F("Alphat_2Jets_case_DL_antismallreg_pt_secjetak","akAlphat_2Jets_case_DL_antismallreg_pt_secjet",500,0,2000);
  TH2F *hist_deltaeta_vs_deltaphi_antismallregak = new TH2F("DeltaEta_vs_DeltaPhi_antismallreg_caseak","akDeltaEta_vs_DeltaPhi_antismallreg_case",240,-6,6,200,-5,5);

  TH2F *hist_deltaeta_vs_deltaphi_finalak = new TH2F("DeltaEta_vs_DeltaPhi_final_caseak","akDeltaEta_vs_DeltaPhi_final_case",240,-6,6,200,-5,5);

  Alphat_Fol_2jets->Add(hist_2jets_dl_big2_eta_firstjet);
  Alphat_Fol_2jets->Add(hist_2jets_dl_big2_eta_secjet);
  Alphat_Fol_2jets->Add(hist_2jets_dl_big2_phi_firstjet);
  Alphat_Fol_2jets->Add(hist_2jets_dl_big2_phi_secjet);
  Alphat_Fol_2jets->Add(hist_2jets_dl_big2_etaphi_firstjet);
  Alphat_Fol_2jets->Add(hist_2jets_dl_big2_etaphi_secjet);
  Alphat_Fol_2jets->Add(hist_2jets_dl_big2_pt_firstjet);
  Alphat_Fol_2jets->Add(hist_2jets_dl_big2_pt_secjet);
  Alphat_Fol_2jets->Add(hist_deltaeta_vs_deltaphi_big2);

  Alphat_Fol_2jets->Add(hist_2jets_dl_smallreg_eta_firstjet);
  Alphat_Fol_2jets->Add(hist_2jets_dl_smallreg_eta_secjet);
  Alphat_Fol_2jets->Add(hist_2jets_dl_smallreg_phi_firstjet);
  Alphat_Fol_2jets->Add(hist_2jets_dl_smallreg_phi_secjet);
  Alphat_Fol_2jets->Add(hist_2jets_dl_smallreg_pt_firstjet);
  Alphat_Fol_2jets->Add(hist_2jets_dl_smallreg_pt_secjet);
  Alphat_Fol_2jets->Add(hist_deltaeta_vs_deltaphi_smallreg);

  Alphat_Fol_2jets->Add(hist_2jets_dl_antismallreg_eta_firstjet);
  Alphat_Fol_2jets->Add(hist_2jets_dl_antismallreg_eta_secjet);
  Alphat_Fol_2jets->Add(hist_2jets_dl_antismallreg_phi_firstjet);
  Alphat_Fol_2jets->Add(hist_2jets_dl_antismallreg_phi_secjet);
  Alphat_Fol_2jets->Add(hist_2jets_dl_antismallreg_pt_firstjet);
  Alphat_Fol_2jets->Add(hist_2jets_dl_antismallreg_pt_secjet);
  Alphat_Fol_2jets->Add(hist_deltaeta_vs_deltaphi_antismallreg);
  Alphat_Fol_2jets->Add(hist_deltaeta_vs_deltaphi_final);

  //////////////////////

  Alphat_Fol_2jets->Add(hist_2jets_dl_big2_eta_firstjetak);
  Alphat_Fol_2jets->Add(hist_2jets_dl_big2_eta_secjetak);
  Alphat_Fol_2jets->Add(hist_2jets_dl_big2_phi_firstjetak);
  Alphat_Fol_2jets->Add(hist_2jets_dl_big2_phi_secjetak);
  Alphat_Fol_2jets->Add(hist_2jets_dl_big2_etaphi_firstjetak);
  Alphat_Fol_2jets->Add(hist_2jets_dl_big2_etaphi_secjetak);
  Alphat_Fol_2jets->Add(hist_2jets_dl_big2_pt_firstjetak);
  Alphat_Fol_2jets->Add(hist_2jets_dl_big2_pt_secjetak);
  Alphat_Fol_2jets->Add(hist_deltaeta_vs_deltaphi_big2ak);

  Alphat_Fol_2jets->Add(hist_2jets_dl_smallreg_eta_firstjetak);
  Alphat_Fol_2jets->Add(hist_2jets_dl_smallreg_eta_secjetak);
  Alphat_Fol_2jets->Add(hist_2jets_dl_smallreg_phi_firstjetak);
  Alphat_Fol_2jets->Add(hist_2jets_dl_smallreg_phi_secjetak);
  Alphat_Fol_2jets->Add(hist_2jets_dl_smallreg_pt_firstjetak);
  Alphat_Fol_2jets->Add(hist_2jets_dl_smallreg_pt_secjetak);
  Alphat_Fol_2jets->Add(hist_deltaeta_vs_deltaphi_smallregak);

  Alphat_Fol_2jets->Add(hist_2jets_dl_antismallreg_eta_firstjetak);
  Alphat_Fol_2jets->Add(hist_2jets_dl_antismallreg_eta_secjetak);
  Alphat_Fol_2jets->Add(hist_2jets_dl_antismallreg_phi_firstjetak);
  Alphat_Fol_2jets->Add(hist_2jets_dl_antismallreg_phi_secjetak);
  Alphat_Fol_2jets->Add(hist_2jets_dl_antismallreg_pt_firstjetak);
  Alphat_Fol_2jets->Add(hist_2jets_dl_antismallreg_pt_secjetak);
  Alphat_Fol_2jets->Add(hist_deltaeta_vs_deltaphi_antismallregak);
  Alphat_Fol_2jets->Add(hist_deltaeta_vs_deltaphi_finalak);


  if (fChain == 0) return; 
  Long64_t nentries = fChain->GetEntriesFast();   
  cout<<"EVENTS "<< nentries<<endl; 
  Long64_t nbytes = 0, nb = 0; 
  //  nentries = 900000;
  if(weight != 1)
    weight = weight/double(nentries);
  //  std::cout << "The weight for this event is " << weight << std::endl;
  //////////////////////////////////////////
  ////Loop over the tree //////////////////////////
  ////////////////////////////////////////
  for (Long64_t jentry=0; jentry<nentries; jentry++) {
    //for (Long64_t jentry=900000; jentry<nentries; jentry++) {
    if (jentry%50000 ==0) cout<<jentry<<" EVENTS ANALYZED"<<endl; 
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    //    if(EVENT != 1210889) continue;
    //    std::cout << "New Event Run: " << RUN << " EVENT: " << EVENT << " LUMIsection: " << LUMISEC << endl; 

    bool two_leading_jets = false;
    bool two_leading_PFjets = false;
    bool two_leading_jetsak = false;
    bool two_leading_PFjetsak = false;

    std::vector<int> sel_pfmu;
    std::vector<int> sel_mu;
    std::vector<int> sel_el;
    std::vector<int> sel_pfel;
    std::vector<int> sel_jet;
    std::vector<int> sel_pfjet;
    std::vector<int> sel_jetak;
    std::vector<int> sel_pfjetak;
    std::vector<int> sel_tau;
    std::vector<int> sel_pftau;

    std::vector<int> sell_pfmu;
    std::vector<int> sell_mu;
    std::vector<int> sell_el;
    std::vector<int> sell_pfel;
    std::vector<int> sell_tau;
    std::vector<int> sell_pftau;

    std::vector<double> htvec;
    std::vector<double> pfhtvec;
    std::vector<double> alphatvec;
    std::vector<double> pfalphatvec;

    std::vector<double> htvecak;
    std::vector<double> pfhtvecak;
    std::vector<double> alphatvecak;
    std::vector<double> pfalphatvecak;

    for(int i=0;i<4;i++){
      alphatvec.push_back(0.);
      pfalphatvec.push_back(0.);
      alphatvecak.push_back(0.);
      pfalphatvecak.push_back(0.);
    }
    bool leading_jet = false;
    bool leading_pfjet = false;
    bool leading_jetak = false;
    bool leading_pfjetak = false;
    float etap,phip,drp;

    //    std::cout << "Tau cycle" << std::endl;

    std::vector<std::vector<double> > all_lep;
    std::vector<std::vector<double> > all_pflep;
    all_lep.clear();
    all_pflep.clear();
    std::vector<double> lep_temp;
    std::vector<std::vector<double> > all_llep;
    std::vector<std::vector<double> > all_pfllep;
    all_llep.clear();
    all_pfllep.clear();
    std::vector<double> llep_temp;
    ////////////////////////////////////////
    /////////Tau cycle
    /////////////////////////////////////
    lep_temp.clear();
    llep_temp.clear();
    for(unsigned int i=0;i<NTau;i++){
      /////////////Selecting taus by cuts 
      if(Tau_PT[i] < Tau_Pt_Cut )
	continue;
      if(fabs( Tau_ETA[i] ) > Tau_Eta_Cut )
	continue;
      if(Tau_LTF[i] == 0)
	continue;      
      etap=0;phip=0;drp=100;     
      for(unsigned int j = 0; j<NJET; j++ ){
	if(JET_PT[j] < Jet_Pt_Cut )
	  continue;
	if(fabs(JET_ETA[j]) > Jet_Eta_Cut)
	  continue;
	etap = JET_ETA[j] - Tau_ETA[i];
	phip = JET_PHI[j] - Tau_PHI[i];
	if( sqrt(etap*etap + phip*phip) < drp)
	  drp = sqrt(etap*etap + phip*phip);
      }
      if(drp < 0.1)
	continue;
      hist_tau_loose_pt_eta->Fill(Tau_PT[i],Tau_ETA[i]);

      if(Tau_TaNC[i] == 0){
	llep_temp.push_back((double)Tau_PT[i]);
	llep_temp.push_back((double)Tau_ETA[i]);
	llep_temp.push_back((double)Tau_PHI[i]);
	llep_temp.push_back((double)Tau_Charge[i]);
	llep_temp.push_back((double)3);
	llep_temp.push_back((double)Tau_energy[i]);
	llep_temp.push_back((double)Tau_PX[i]);
	llep_temp.push_back((double)Tau_PY[i]);
	llep_temp.push_back((double)Tau_PZ[i]);
	all_llep.push_back(llep_temp);
	llep_temp.clear();	
	sell_tau.push_back(i);
	continue;
      }
      lep_temp.push_back((double)Tau_PT[i]);
      lep_temp.push_back((double)Tau_ETA[i]);
      lep_temp.push_back((double)Tau_PHI[i]);
      lep_temp.push_back((double)Tau_Charge[i]);
      lep_temp.push_back((double)3);
      lep_temp.push_back((double)Tau_energy[i]);
      lep_temp.push_back((double)Tau_PX[i]);
      lep_temp.push_back((double)Tau_PY[i]);
      lep_temp.push_back((double)Tau_PZ[i]);
      all_lep.push_back(lep_temp);
      lep_temp.clear();
      hist_tau_tight_pt_eta->Fill(Tau_PT[i],Tau_ETA[i]);
      sel_tau.push_back(i);
    }

    ////////////////////////////////////////
    /////////PF Tau cycle
    /////////////////////////////////////
    lep_temp.clear();
    for(unsigned int i=0;i<NPFTau;i++){
      if(PFTau_PT[i] < Tau_Pt_Cut )
	continue;
      if(fabs( PFTau_ETA[i] ) > Tau_Eta_Cut )
	continue;
      if(PFTau_LTF[i] == 0)
	continue;
      
      etap=0;phip=0;drp=100;     
      for(unsigned int j = 0; j<NPFJET; j++ ){
	if(PFJET_PT[j] < Jet_Pt_Cut )
	  continue;
	if(fabs(PFJET_ETA[j]) > Jet_Eta_Cut)
	  continue;
	etap = PFJET_ETA[j] - PFTau_ETA[i];
	phip = PFJET_PHI[j] - PFTau_PHI[i];
	if( sqrt(etap*etap + phip*phip) < drp)
	  drp = sqrt(etap*etap + phip*phip);
      }
      if(drp < 0.1)
	continue;

      hist_pftau_loose_pt_eta->Fill(PFTau_PT[i],PFTau_ETA[i]);

      if(PFTau_TaNC[i] == 0){
	llep_temp.push_back((double)PFTau_PT[i]);
	llep_temp.push_back((double)PFTau_ETA[i]);
	llep_temp.push_back((double)PFTau_PHI[i]);
	llep_temp.push_back((double)PFTau_Charge[i]);
	llep_temp.push_back((double)3);
	llep_temp.push_back((double)PFTau_energy[i]);
	llep_temp.push_back((double)PFTau_PX[i]);
	llep_temp.push_back((double)PFTau_PY[i]);
	llep_temp.push_back((double)PFTau_PZ[i]);
	all_pfllep.push_back(llep_temp);
	llep_temp.clear();      
	sell_pftau.push_back(i);
	continue;
      }
      lep_temp.push_back((double)PFTau_PT[i]);
      lep_temp.push_back((double)PFTau_ETA[i]);
      lep_temp.push_back((double)PFTau_PHI[i]);
      lep_temp.push_back((double)PFTau_Charge[i]);
      lep_temp.push_back((double)3);
      lep_temp.push_back((double)PFTau_energy[i]);
      lep_temp.push_back((double)PFTau_PX[i]);
      lep_temp.push_back((double)PFTau_PY[i]);
      lep_temp.push_back((double)PFTau_PZ[i]);
      all_pflep.push_back(lep_temp);
      lep_temp.clear();

      hist_pftau_tight_pt_eta->Fill(PFTau_PT[i],PFTau_ETA[i]);
      sel_pftau.push_back(i);
    }

    ///////////////////////////////////////
    ///////////////////Muon cycle
    ////////////////////////////////////
    lep_temp.clear();
    for(unsigned int i=0;i<NMu;i++){
      if(Mu_PT[i] < Mu_Pt_Cut )
	continue;
      if(fabs(Mu_ETA[i]) > Mu_Eta_Cut )
	continue;
      if(Mu_Chi2dof[i] > Mu_Chi2dof_Cut)
	continue;
      if(Mu_NHitsTrack[i] < Mu_NHits_Cut)
	continue;
      if(fabs(Mu_D0[i]) > Mu_D0_Cut)
	continue;
      if(Mu_isGlobal[i] == 0 )
	continue;
      
      ////////// no jet closer than Dr < 0.4
      etap=0;phip=0;drp=100;     
      for(unsigned int j = 0; j<NJET; j++ ){
	if(JET_PT[j] < Jet_Pt_Cut )
	  continue;
	if(fabs(JET_ETA[j]) > Jet_Eta_Cut)
	  continue;
	etap = JET_ETA[j] - Mu_ETA[i];
	phip = JET_PHI[j] - Mu_PHI[i];
	if( sqrt(etap*etap + phip*phip) < drp)
	  drp = sqrt(etap*etap + phip*phip);
      }
      if(drp < 0.4)
	continue;

      ////////////loose muon definition!!!!!!
      if( fabs(Mu_ETA[i]) > 1.44 ){
	if( (Mu_trackIso[i] + Mu_ecalIso[i] + Mu_hcalIso[i])/Mu_PT[i] > 0.15 ){
	  llep_temp.push_back((double)Mu_PT[i]);
	  llep_temp.push_back((double)Mu_ETA[i]);
	  llep_temp.push_back((double)Mu_PHI[i]);
	  llep_temp.push_back((double)Mu_Charge[i]);
	  llep_temp.push_back((double)2);
	  llep_temp.push_back((double)Mu_energy[i]);
	  llep_temp.push_back((double)Mu_PX[i]);
	  llep_temp.push_back((double)Mu_PY[i]);
	  llep_temp.push_back((double)Mu_PZ[i]);
	  all_llep.push_back(llep_temp);
	  llep_temp.clear();
	  sell_mu.push_back((int)i); 
	  continue;
	}
      }
      else if( fabs(Mu_ETA[i]) <= 1.44 ){
	if( Mu_ecalIso[i] - 1 > 0){
	  if( (Mu_trackIso[i] + Mu_ecalIso[i] - 1 + Mu_hcalIso[i])/Mu_PT[i] > 0.15 ){
	    llep_temp.push_back((double)Mu_PT[i]);
	    llep_temp.push_back((double)Mu_ETA[i]);
	    llep_temp.push_back((double)Mu_PHI[i]);
	    llep_temp.push_back((double)Mu_Charge[i]);
	    llep_temp.push_back((double)2);
	    llep_temp.push_back((double)Mu_energy[i]);
	    llep_temp.push_back((double)Mu_PX[i]);
	    llep_temp.push_back((double)Mu_PY[i]);
	    llep_temp.push_back((double)Mu_PZ[i]);
	    all_llep.push_back(llep_temp);
	    llep_temp.clear();
	    sell_mu.push_back((int)i); 
	    continue;
	  }
	}
	else{
	  if( (Mu_trackIso[i] + Mu_hcalIso[i])/Mu_PT[i] > 0.15 ){
	    llep_temp.push_back((double)Mu_PT[i]);
	    llep_temp.push_back((double)Mu_ETA[i]);
	    llep_temp.push_back((double)Mu_PHI[i]);
	    llep_temp.push_back((double)Mu_Charge[i]);
	    llep_temp.push_back((double)2);
	    llep_temp.push_back((double)Mu_energy[i]);
	    llep_temp.push_back((double)Mu_PX[i]);
	    llep_temp.push_back((double)Mu_PY[i]);
	    llep_temp.push_back((double)Mu_PZ[i]);
	    all_llep.push_back(llep_temp);
	    llep_temp.clear();
	    sell_mu.push_back((int)i); 
	    continue;
	  }
	}
      }
      lep_temp.push_back((double)Mu_PT[i]);
      lep_temp.push_back((double)Mu_ETA[i]);
      lep_temp.push_back((double)Mu_PHI[i]);
      lep_temp.push_back((double)Mu_Charge[i]);
      lep_temp.push_back((double)2);
      lep_temp.push_back((double)Mu_energy[i]);
      lep_temp.push_back((double)Mu_PX[i]);
      lep_temp.push_back((double)Mu_PY[i]);
      lep_temp.push_back((double)Mu_PZ[i]);
      all_lep.push_back(lep_temp);
      lep_temp.clear();
      sel_mu.push_back((int)i); 
    }
    //////////////invariant mass
    if(sel_mu.size() == 2 && Mu_Charge[sel_mu[0]]*Mu_Charge[sel_mu[1]] == 1){
      hist_mu_invmass->Fill(invmass(Mu_energy[sel_mu[0]],Mu_PX[sel_mu[0]],Mu_PY[sel_mu[0]],Mu_PZ[sel_mu[0]],Mu_energy[sel_mu[1]],Mu_PX[sel_mu[1]],Mu_PY[sel_mu[1]],Mu_PZ[sel_mu[1]]),weight);
    }
    if(sell_mu.size() == 2 && Mu_Charge[sell_mu[0]]*Mu_Charge[sell_mu[1]] == 1){
      hist_mul_invmass->Fill(invmass(Mu_energy[sell_mu[0]],Mu_PX[sell_mu[0]],Mu_PY[sell_mu[0]],Mu_PZ[sell_mu[0]],Mu_energy[sell_mu[1]],Mu_PX[sell_mu[1]],Mu_PY[sell_mu[1]],Mu_PZ[sell_mu[1]]),weight);
    }
    //////////////////cycle done for background estimation
    for(unsigned int i=0;i<NMu;i++){
      if(Mu_PT[i] < Mu_Pt_Cut )
	continue;
      if(fabs(Mu_ETA[i]) > Mu_Eta_Cut )
	continue;
      if(Mu_Chi2dof[i] > Mu_Chi2dof_Cut)
	continue;
      if(Mu_NHitsTrack[i] < Mu_NHits_Cut)
	continue;
      if(fabs(Mu_D0[i]) > Mu_D0_Cut)
	continue;
      if(Mu_isGlobal[i] == 0 )
	continue;
      
      etap=0;phip=0;drp=100;     
      for(unsigned int j = 0; j<NJET; j++ ){
	if(JET_PT[j] < Jet_Pt_Cut )
	  continue;
	if(fabs(JET_ETA[j]) > Jet_Eta_Cut)
	  continue;
	etap = JET_ETA[j] - Mu_ETA[i];
	phip = JET_PHI[j] - Mu_PHI[i];
	if( sqrt(etap*etap + phip*phip) < drp)
	  drp = sqrt(etap*etap + phip*phip);
      }
      if(drp < 0.4)
	continue;
      
      etap=0;phip=0;drp=100;     
      for(unsigned int j = 0; j<NJET; j++ ){
	if(JET_PT[j] < Jet_Pt_Cut )
	  continue;
	if(fabs(JET_ETA[j]) > Jet_Eta_Cut)
	  continue;
	if(JET_btagl[j] == 1){
	  etap = JET_ETA[j] - Mu_ETA[i];
	  phip = JET_PHI[j] - Mu_PHI[i]; 
	  drp = sqrt(etap*etap + phip*phip);
	  break;
	}
      }
      if(drp < 1)
	continue;
      hist_muo_loose_pt_eta->Fill(Mu_PT[i],Mu_ETA[i]);
      if( fabs(Mu_ETA[i]) > 1.44 ){
	if( (Mu_trackIso[i] + Mu_ecalIso[i] + Mu_hcalIso[i])/Mu_PT[i] > 0.15 )
	  continue;
      }
      else if( fabs(Mu_ETA[i]) <= 1.44 ){
	if( Mu_ecalIso[i] - 1 > 0){
	  if( (Mu_trackIso[i] + Mu_ecalIso[i] - 1 + Mu_hcalIso[i])/Mu_PT[i] > 0.15 )
	    continue;
	}
	else{
	  if( (Mu_trackIso[i] + Mu_hcalIso[i])/Mu_PT[i] > 0.15 )
	    continue;
	}
      }
      hist_muo_tight_pt_eta->Fill(Mu_PT[i],Mu_ETA[i]);
    }

    ///////////////////////////////////////
    ///////////////////PF Muon cycle
    ////////////////////////////////////
    lep_temp.clear();
    for(unsigned int i=0;i<NPFMu;i++){
      if(Mu_PT[i] < Mu_Pt_Cut )
	continue;
      if(fabs(Mu_ETA[i]) > Mu_Eta_Cut )
	continue;
      if(Mu_Chi2dof[i] > Mu_Chi2dof_Cut)
	continue;
      if(Mu_NHitsTrack[i] < Mu_NHits_Cut)
	continue;
      if(fabs(Mu_D0[i]) > Mu_D0_Cut)
	continue;
      if(Mu_isGlobal[i] == 0 )
	continue;
      
      /////// requiring no muons close to a jet
      etap=0;phip=0;drp=100;     
      for(unsigned int j = 0; j<NPFJET; j++ ){
	if(PFJET_PT[j] < Jet_Pt_Cut )
	  continue;
	if(fabs(PFJET_ETA[j]) > Jet_Eta_Cut)
	  continue;
	etap = PFJET_ETA[j] - PFMu_ETA[i];
	phip = PFJET_PHI[j] - PFMu_PHI[i];
	if( sqrt(etap*etap + phip*phip) < drp)
	  drp = sqrt(etap*etap + phip*phip);
      }
      if(drp < 0.4)
	continue;


      if( fabs(PFMu_ETA[i]) > 1.44 ){
	if( (PFMu_trackIso[i] + PFMu_ecalIso[i] + PFMu_hcalIso[i])/PFMu_PT[i] > 0.15 ){
	  llep_temp.push_back((double)PFMu_PT[i]);
	  llep_temp.push_back((double)PFMu_ETA[i]);
	  llep_temp.push_back((double)PFMu_PHI[i]);
	  llep_temp.push_back((double)PFMu_Charge[i]);
	  llep_temp.push_back((double)2);
	  llep_temp.push_back((double)PFMu_energy[i]);
	  llep_temp.push_back((double)PFMu_PX[i]);
	  llep_temp.push_back((double)PFMu_PY[i]);
	  llep_temp.push_back((double)PFMu_PZ[i]);
	  all_pfllep.push_back(llep_temp);
	  llep_temp.clear();      
	  sell_pfmu.push_back((int)i);      
	  continue;
	}
      }
      else if( fabs(PFMu_ETA[i]) <= 1.44 ){
	if( PFMu_ecalIso[i] - 1 > 0){
	  if( (PFMu_trackIso[i] + PFMu_ecalIso[i] - 1 + PFMu_hcalIso[i])/PFMu_PT[i] > 0.15 ){
	    llep_temp.push_back((double)PFMu_PT[i]);
	    llep_temp.push_back((double)PFMu_ETA[i]);
	    llep_temp.push_back((double)PFMu_PHI[i]);
	    llep_temp.push_back((double)PFMu_Charge[i]);
	    llep_temp.push_back((double)2);
	    llep_temp.push_back((double)PFMu_energy[i]);
	    llep_temp.push_back((double)PFMu_PX[i]);
	    llep_temp.push_back((double)PFMu_PY[i]);
	    llep_temp.push_back((double)PFMu_PZ[i]);
	    all_pfllep.push_back(llep_temp);
	    llep_temp.clear();      
	    sell_pfmu.push_back((int)i);      
	    continue;
	  }
	}
	else{
	  if( (PFMu_trackIso[i] + PFMu_hcalIso[i])/PFMu_PT[i] > 0.15 ){
	    llep_temp.push_back((double)PFMu_PT[i]);
	    llep_temp.push_back((double)PFMu_ETA[i]);
	    llep_temp.push_back((double)PFMu_PHI[i]);
	    llep_temp.push_back((double)PFMu_Charge[i]);
	    llep_temp.push_back((double)2);
	    llep_temp.push_back((double)PFMu_energy[i]);
	    llep_temp.push_back((double)PFMu_PX[i]);
	    llep_temp.push_back((double)PFMu_PY[i]);
	    llep_temp.push_back((double)PFMu_PZ[i]);
	    all_pfllep.push_back(llep_temp);
	    llep_temp.clear();      
	    sell_pfmu.push_back((int)i);      
	    continue;
	  }
	}
      }
      lep_temp.push_back((double)PFMu_PT[i]);
      lep_temp.push_back((double)PFMu_ETA[i]);
      lep_temp.push_back((double)PFMu_PHI[i]);
      lep_temp.push_back((double)PFMu_Charge[i]);
      lep_temp.push_back((double)2);
      lep_temp.push_back((double)PFMu_energy[i]);
      lep_temp.push_back((double)PFMu_PX[i]);
      lep_temp.push_back((double)PFMu_PY[i]);
      lep_temp.push_back((double)PFMu_PZ[i]);
      all_pflep.push_back(lep_temp);
      lep_temp.clear();
      sel_pfmu.push_back((int)i);      
    }
    //////////////invariant mass
    if(sel_pfmu.size() == 2 && PFMu_Charge[sel_pfmu[0]]*PFMu_Charge[sel_pfmu[1]] == 1){
      hist_pfmu_invmass->Fill(invmass(PFMu_energy[sel_pfmu[0]],PFMu_PX[sel_pfmu[0]],PFMu_PY[sel_pfmu[0]],PFMu_PZ[sel_pfmu[0]],PFMu_energy[sel_pfmu[1]],PFMu_PX[sel_pfmu[1]],PFMu_PY[sel_pfmu[1]],PFMu_PZ[sel_pfmu[1]]),weight);
    }
    if(sell_pfmu.size() == 2 && PFMu_Charge[sell_pfmu[0]]*PFMu_Charge[sell_pfmu[1]] == 1){
      hist_pfmul_invmass->Fill(invmass(PFMu_energy[sell_pfmu[0]],PFMu_PX[sell_pfmu[0]],PFMu_PY[sell_pfmu[0]],PFMu_PZ[sell_pfmu[0]],PFMu_energy[sell_pfmu[1]],PFMu_PX[sell_pfmu[1]],PFMu_PY[sell_pfmu[1]],PFMu_PZ[sell_pfmu[1]]),weight);
    }
    ///////////// fake estimation
    for(unsigned int i=0;i<NPFMu;i++){
      if(Mu_PT[i] < Mu_Pt_Cut )
	continue;
      if(fabs(Mu_ETA[i]) > Mu_Eta_Cut )
	continue;
      if(Mu_Chi2dof[i] > Mu_Chi2dof_Cut)
	continue;
      if(Mu_NHitsTrack[i] < Mu_NHits_Cut)
	continue;
      if(fabs(Mu_D0[i]) > Mu_D0_Cut)
	continue;
      if(Mu_isGlobal[i] == 0 )
	continue;
      
      /////// requiring no jet close to the muon
      etap=0;phip=0;drp=100;     
      for(unsigned int j = 0; j<NPFJET; j++ ){
	if(PFJET_PT[j] < Jet_Pt_Cut )
	  continue;
	if(fabs(PFJET_ETA[j]) > Jet_Eta_Cut)
	  continue;
	etap = PFJET_ETA[j] - PFMu_ETA[i];
	phip = PFJET_PHI[j] - PFMu_PHI[i];
	if( sqrt(etap*etap + phip*phip) < drp)
	  drp = sqrt(etap*etap + phip*phip);
      }
      if(drp < 0.4)
	continue;
      
      /////////btag opposite muon
      etap=0,phip=0,drp=100;     
      for(unsigned int j = 0; j<NPFJET; j++ ){
	if(PFJET_PT[j] < Jet_Pt_Cut )
	  continue;
	if(fabs(PFJET_ETA[j]) > Jet_Eta_Cut)
	  continue;
	if(PFJET_btagl[j] == 1){
	  etap = PFJET_ETA[j]-PFMu_ETA[i];
	  phip = PFJET_PHI[j]-PFMu_PHI[i]; 
	  drp=sqrt(etap*etap + phip*phip);
	  break;
	}
      }
      if(drp < 1)
	continue;
      hist_pfmuo_loose_pt_eta->Fill(PFMu_PT[i],PFMu_ETA[i]);
      if( fabs(PFMu_ETA[i]) > 1.44 ){
	if( (PFMu_trackIso[i] + PFMu_ecalIso[i] + PFMu_hcalIso[i])/PFMu_PT[i] > 0.15 )
	  continue;
      }
      else if( fabs(PFMu_ETA[i]) <= 1.44 ){
	if( PFMu_ecalIso[i] - 1 > 0){
	  if( (PFMu_trackIso[i] + PFMu_ecalIso[i] - 1 + PFMu_hcalIso[i])/PFMu_PT[i] > 0.15 )
	    continue;
	}
	else{
	  if( (PFMu_trackIso[i] + PFMu_hcalIso[i])/PFMu_PT[i] > 0.15 )
	    continue;
	}
      }
      hist_pfmuo_tight_pt_eta->Fill(PFMu_PT[i],PFMu_ETA[i]);
    }

    //    std::cout << "Electron cycle" << std::endl;
    ///////////////////////////////////////////
    /////////////////Electron cycle
    //////////////////////////////////////
    int el_mult_after_pt_cut = 0;
    lep_temp.clear();
    for(unsigned int i=0;i<NEl;i++){
      if(El_PT[i] < El_Pt_Cut)
	continue;
      if(fabs(El_ETA[i]) > El_Eta_Cut)
	continue;
      if(fabs(El_D0[i]) > El_D0_Cut )
	continue;
      if(El_Conversion[i] == 1)
      	continue;
      if(El_LostHits[i] >= 1)
	continue;
      if(El_isChargeok[i] == 0)
	continue;
      if( fabs(El_ETA[i]) > 1.44 ){
	if( (El_trackIso[i] + El_ecalIso[i] + El_hcalIso[i])/El_PT[i] > 0.15 )
	  continue;
      }
      else if( fabs(El_ETA[i]) <= 1.44 ){
	if( El_ecalIso[i] - 1 > 0){
	  if( (El_trackIso[i] + El_ecalIso[i] - 1 + El_hcalIso[i])/El_PT[i] > 0.15 )
	    continue;
	}
	else{
	  if( (El_trackIso[i] + El_hcalIso[i])/El_PT[i] > 0.15 )
	    continue;
	}
      }
      
      ////////no jets near the electron
      etap=0;phip=0;drp=100;     
      for(unsigned int j = 0; j<NJET; j++ ){
	if(JET_PT[j] < Jet_Pt_Cut )
	  continue;
	if(fabs(JET_ETA[j]) > Jet_Eta_Cut)
	  continue;
	etap = JET_ETA[j] - El_ETA[i];
	phip = JET_PHI[j] - El_PHI[i];
	if( sqrt(etap*etap + phip*phip) < drp)
	  drp = sqrt(etap*etap + phip*phip);
      }
      if(drp < 0.4)
	continue;

      hist_ele_loose_pt_eta->Fill(El_PT[i],El_ETA[i]);
      if(El_EidTight[i] != 1){
	llep_temp.push_back((double)El_PT[i]);
	llep_temp.push_back((double)El_ETA[i]);
	llep_temp.push_back((double)El_PHI[i]);
	llep_temp.push_back((double)El_Charge[i]);
	llep_temp.push_back((double)1);
	llep_temp.push_back((double)El_energy[i]);
	llep_temp.push_back((double)El_PX[i]);
	llep_temp.push_back((double)El_PY[i]);
	llep_temp.push_back((double)El_PZ[i]);
	all_llep.push_back(llep_temp);
	llep_temp.clear();
	sell_el.push_back((int)i);
	continue;
      }
      if(El_HoE[i] > El_HoE_Cut){
	llep_temp.push_back((double)El_PT[i]);
	llep_temp.push_back((double)El_ETA[i]);
	llep_temp.push_back((double)El_PHI[i]);
	llep_temp.push_back((double)El_Charge[i]);
	llep_temp.push_back((double)1);
	llep_temp.push_back((double)El_energy[i]);
	llep_temp.push_back((double)El_PX[i]);
	llep_temp.push_back((double)El_PY[i]);
	llep_temp.push_back((double)El_PZ[i]);
	all_llep.push_back(llep_temp);
	llep_temp.clear();
	sell_el.push_back((int)i);
	continue;
      }
      hist_ele_tight_pt_eta->Fill(El_PT[i],El_ETA[i]);
      el_mult_after_pt_cut++;
      lep_temp.push_back((double)El_PT[i]);
      lep_temp.push_back((double)El_ETA[i]);
      lep_temp.push_back((double)El_PHI[i]);
      lep_temp.push_back((double)El_Charge[i]);
      lep_temp.push_back((double)1);
      lep_temp.push_back((double)El_energy[i]);
      lep_temp.push_back((double)El_PX[i]);
      lep_temp.push_back((double)El_PY[i]);
      lep_temp.push_back((double)El_PZ[i]);
      all_lep.push_back(lep_temp);
      lep_temp.clear();
      sel_el.push_back((int)i);
    }
    hist_ele_multiplicity_after_pt_cut->Fill(el_mult_after_pt_cut,weight);

    //////////////invariant mass
    if(sel_el.size() == 2 && El_Charge[sel_el[0]]*El_Charge[sel_el[1]] == 1){
      hist_el_invmass->Fill(invmass(El_energy[sel_el[0]],El_PX[sel_el[0]],El_PY[sel_el[0]],El_PZ[sel_el[0]],El_energy[sel_el[1]],El_PX[sel_el[1]],El_PY[sel_el[1]],El_PZ[sel_el[1]]),weight);
    }
    if(sell_el.size() == 2 && El_Charge[sell_el[0]]*El_Charge[sell_el[1]] == 1){
      hist_ell_invmass->Fill(invmass(El_energy[sell_el[0]],El_PX[sell_el[0]],El_PY[sell_el[0]],El_PZ[sell_el[0]],El_energy[sell_el[1]],El_PX[sell_el[1]],El_PY[sell_el[1]],El_PZ[sell_el[1]]),weight);
    }
    //////////////////////////////////////////////////////
    /////////////////PF Electron cycle
    ///////////////////////////////////////////////////////
    el_mult_after_pt_cut = 0;
    lep_temp.clear();
    for(unsigned int i=0;i<NPFEl;i++){
      if(PFEl_PT[i] < El_Pt_Cut)
	continue;
      if(fabs(PFEl_ETA[i]) > El_Eta_Cut)
	continue;
      if(fabs(PFEl_D0[i]) > El_D0_Cut )
	continue;
      if(PFEl_Conversion[i] == 1)
	continue;
      if(PFEl_LostHits[i] >= 1)
	continue;
      if(PFEl_isChargeok[i] == 0)
	continue;
      if( fabs(PFEl_ETA[i]) > 1.44 ){
	if( (PFEl_trackIso[i] + PFEl_ecalIso[i] + PFEl_hcalIso[i])/PFEl_PT[i] > 0.15 )
	  continue;
      }
      else if( fabs(PFEl_ETA[i]) <= 1.44 ){
	if( PFEl_ecalIso[i] - 1 > 0){
	  if( (PFEl_trackIso[i] + PFEl_ecalIso[i] - 1 + PFEl_hcalIso[i])/PFEl_PT[i] > 0.15 )
	    continue;
	}
	else{
	  if( (PFEl_trackIso[i] + PFEl_hcalIso[i])/PFEl_PT[i] > 0.15 )
	    continue;
	}
      }
      
      etap=0;phip=0;drp=100;     
      for(unsigned int j = 0; j<NPFJET; j++ ){
	if(PFJET_PT[j] < Jet_Pt_Cut )
	  continue;
	if(fabs(PFJET_ETA[j]) > Jet_Eta_Cut)
	  continue;
	etap = PFJET_ETA[j] - PFEl_ETA[i];
	phip = PFJET_PHI[j] - PFEl_PHI[i];
	if( sqrt(etap*etap + phip*phip) < drp)
	  drp = sqrt(etap*etap + phip*phip);
      }
      if(drp < 0.4)
	continue;

      hist_pfele_loose_pt_eta->Fill(PFEl_PT[i],PFEl_ETA[i]);

      if(PFEl_EidTight[i] != 1){
	llep_temp.push_back((double)PFEl_PT[i]);
	llep_temp.push_back((double)PFEl_ETA[i]);
	llep_temp.push_back((double)PFEl_PHI[i]);
	llep_temp.push_back((double)PFEl_Charge[i]);
	llep_temp.push_back((double)1);
	llep_temp.push_back((double)PFEl_energy[i]);
	llep_temp.push_back((double)PFEl_PX[i]);
	llep_temp.push_back((double)PFEl_PY[i]);
	llep_temp.push_back((double)PFEl_PZ[i]);
	all_pfllep.push_back(llep_temp);
	llep_temp.clear();      
	sell_pfel.push_back((int)i);
	continue;
      }
      if(PFEl_HoE[i] > El_HoE_Cut){
	llep_temp.push_back((double)PFEl_PT[i]);
	llep_temp.push_back((double)PFEl_ETA[i]);
	llep_temp.push_back((double)PFEl_PHI[i]);
	llep_temp.push_back((double)PFEl_Charge[i]);
	llep_temp.push_back((double)1);
	llep_temp.push_back((double)PFEl_energy[i]);
	llep_temp.push_back((double)PFEl_PX[i]);
	llep_temp.push_back((double)PFEl_PY[i]);
	llep_temp.push_back((double)PFEl_PZ[i]);
	all_pfllep.push_back(llep_temp);
	llep_temp.clear();      
	sell_pfel.push_back((int)i);
	continue;
      }
      //      if(PFEl_MVA[i] > El_MVA_Cut)
      //      	continue;

      hist_pfele_tight_pt_eta->Fill(PFEl_PT[i],PFEl_ETA[i]);
      el_mult_after_pt_cut++;
      lep_temp.push_back((double)PFEl_PT[i]);
      lep_temp.push_back((double)PFEl_ETA[i]);
      lep_temp.push_back((double)PFEl_PHI[i]);
      lep_temp.push_back((double)PFEl_Charge[i]);
      lep_temp.push_back((double)1);
      lep_temp.push_back((double)PFEl_energy[i]);
      lep_temp.push_back((double)PFEl_PX[i]);
      lep_temp.push_back((double)PFEl_PY[i]);
      lep_temp.push_back((double)PFEl_PZ[i]);
      all_pflep.push_back(lep_temp);
      lep_temp.clear();
      sel_pfel.push_back((int)i);
    }
    hist_PFele_multiplicity_after_pt_cut->Fill(el_mult_after_pt_cut,weight);

    //////////////invariant mass
    if(sel_pfel.size() == 2 && PFEl_Charge[sel_pfel[0]]*PFEl_Charge[sel_pfel[1]] == 1){
      hist_pfel_invmass->Fill(invmass(PFEl_energy[sel_pfel[0]],PFEl_PX[sel_pfel[0]],PFEl_PY[sel_pfel[0]],PFEl_PZ[sel_pfel[0]],PFEl_energy[sel_pfel[1]],PFEl_PX[sel_pfel[1]],PFEl_PY[sel_pfel[1]],PFEl_PZ[sel_pfel[1]]),weight);
    }
    if(sell_pfel.size() == 2 && PFEl_Charge[sell_pfel[0]]*PFEl_Charge[sell_pfel[1]] == 1){
      hist_pfell_invmass->Fill(invmass(PFEl_energy[sell_pfel[0]],PFEl_PX[sell_pfel[0]],PFEl_PY[sell_pfel[0]],PFEl_PZ[sell_pfel[0]],PFEl_energy[sell_pfel[1]],PFEl_PX[sell_pfel[1]],PFEl_PY[sell_pfel[1]],PFEl_PZ[sell_pfel[1]]),weight);
    }

    ///////////////////////////////////////////
    //////////Jet cycle
    //////////////////////////////////////////
    //    cout << "jet cycle" << endl;
    int cont_jet_after_pt = 0;
    int cont_jet_after_eta = 0;
    std::vector<double> jet1;
    std::vector<double> jet2;
    for(int i=0;i<4;i++){
      jet1.push_back(0.);
      jet2.push_back(0.);
    }
    std::vector<std::vector<double> > Jets;
    std::vector<double> temp;
    temp.clear();
    for(unsigned int i=0;i<4;i++){
      htvec.push_back(0.);
    }
    //    std::cout << "NJET " << NJET << std::endl;

    for(unsigned int i = 0; i<NJET; i++ ){
      temp.clear();
      temp.push_back(JET_ET[i]);
      temp.push_back(JET_PT[i]);
      temp.push_back(JET_PX[i]);
      temp.push_back(JET_PY[i]);
      temp.push_back(JET_PZ[i]);
      temp.push_back(JET_ETA[i]);
      temp.push_back(JET_PHI[i]);
      //std::cout << " Jet " << i+1 << " pt " << JET_PT[i] << " eta: " << JET_ETA[i] << " phi: " << JET_PHI[i] << std::endl;
      //Jets.push_back(temp);
      if(JET_PT[i] < Jet_Pt_Cut)
	continue;
      cont_jet_after_pt++;
      if(fabs(JET_ETA[i]) > Jet_Eta_Cut)
	continue;
      cont_jet_after_eta++;
      Jets.push_back(temp);
      temp.clear();
      if(JET_PT[i] > jet1[1]){
	jet1[1] = JET_PT[i];
	jet1[0] = JET_ET[i];
	jet1[3] = JET_PHI[i];
	jet1[2] = JET_ETA[i];
	if(JET_PT[i] > Jet1_Pt_Cut)
	  leading_jet = true;
      }
      else if(JET_PT[i] > jet2[1] && JET_PT[i] < jet1[1]){
	jet2[1] = JET_PT[i];
	jet2[0] = JET_ET[i];
	jet2[3] = JET_PHI[i];
	jet2[2] = JET_ETA[i];
      }
      htvec[0]+=JET_PT[i];
      htvec[2]+=JET_PX[i];
      htvec[3]+=JET_PY[i];
      sel_jet.push_back(i);
    }
    hist_HT->Fill(htvec[0],weight);
    htvec[1]=sqrt(htvec[2]*htvec[2]+htvec[3]*htvec[3]);
    hist_MHT->Fill(htvec[1],weight);

    hist_jet_multiplicity_after_pt_cut->Fill(cont_jet_after_pt,weight);
    hist_jet_multiplicity_after_eta_cut->Fill(cont_jet_after_eta,weight);

    if( sel_jet.size() >= 2 && leading_jet)
      two_leading_jets = true;

    bool srtwojet = false; 
    float angle_mindht[4]={0,0,0,0};
    float angle_reclus[4]={0,0,0,0};

    if( sel_jet.size() == 2 && two_leading_jets){
      srtwojet = true;
      alphatvec[0] = sqrt( (jet2[0])/(2*jet1[0]*(1-cos(jet1[3]-jet2[3]))));
      alphatvec[1] = alphatvec[0];
      alphatvec[2] = alphatvec[0];
      alphatvec[3] = alphatvec[0];
      hist_deltaeta_vs_deltaphi_2jets->Fill(jet1[3]-jet2[3],jet1[2]-jet2[2],weight);
      hist_alphat_twojets->Fill(alphatvec[0],weight);
    }
    else if(sel_jet.size() > 2 && two_leading_jets){
      //      cout << Jets.size() << endl;
      std::vector<std::vector<double> > result=AlphaT(Jets);
      alphatvec[0] = result[0][0];
      hist_alphat_njets_minimum_deltaht->Fill(result[0][0],weight);
      hist_deltaeta_vs_deltaphi_njets->Fill(result[0][3]-result[1][3],result[0][2]-result[1][2],weight);
      angle_mindht[0] = result[0][2];  ///////eta
      angle_mindht[1] = result[1][2];
      angle_mindht[2] = result[0][3]; ////////phi
      angle_mindht[3] = result[1][3];

      //      if(fabs(result[0][3]-result[1][3])<0.1 && fabs(result[0][2]-result[1][2]) < 0.1){
      //	std::cout << " \t eta1: " << result[0][2] << " phi1 " << result[0][3] << std::endl;
      // 	std::cout << " \t eta2: " << result[1][2] << " phi2 " << result[1][3] << std::endl;
      //	std::cout << "Pathological Event Run: " << RUN << " EVENT: " << EVENT << " LUMIsection: " << LUMISEC << endl; 
      //      }
      result.clear();
      result=AlphaTReClus(Jets);
      if(result.size() == 3){
	if(result[1][0] != 0 )
	  hist_deltaeta_vs_deltaphi_njets_recluster->Fill(result[0][6]-result[1][6],result[0][5]-result[1][5],weight);
	angle_reclus[0] = result[0][5]; //////eta
	angle_reclus[1] = result[1][5];
	angle_reclus[2] = result[0][6]; /////phi
	angle_reclus[3] = result[1][6];
	
	hist_alphat_njets_as_two_jets->Fill(result[2][0],weight);
	hist_alphat_njets_as_reclustered->Fill(result[2][1],weight);
	hist_alphat_njets_as_reclustered_recomputed_ht->Fill(result[2][2],weight);
	alphatvec[1] = result[2][0];
	alphatvec[2] = result[2][1];
	alphatvec[3] = result[2][2];
      }
    }

    ///////////////////////////////////////////
    //////////Jetak cycle
    //////////////////////////////////////////
    //    cout << "ak jet cycle " << endl;
    cont_jet_after_pt = 0;
    cont_jet_after_eta = 0;
    jet1.clear();
    jet2.clear();
    for(int i=0;i<4;i++){
      jet1.push_back(0.);
      jet2.push_back(0.);
    }
    Jets.clear();
    temp.clear();
    for(unsigned int i=0;i<4;i++){
      htvecak.push_back(0.);
    }

    for(unsigned int i = 0; i<NJETak; i++ ){
      temp.clear();
      temp.push_back(JETak_ET[i]);
      temp.push_back(JETak_PT[i]);
      temp.push_back(JETak_PX[i]);
      temp.push_back(JETak_PY[i]);
      temp.push_back(JETak_PZ[i]);
      temp.push_back(JETak_ETA[i]);
      temp.push_back(JETak_PHI[i]);
      if(JETak_PT[i] < Jet_Pt_Cut)
	continue;
      cont_jet_after_pt++;
      if(fabs(JETak_ETA[i]) > Jet_Eta_Cut)
	continue;
      cont_jet_after_eta++;
      Jets.push_back(temp);
      temp.clear();
      if(JETak_PT[i] > jet1[1]){
	jet1[1] = JETak_PT[i];
	jet1[0] = JETak_ET[i];
	jet1[3] = JETak_PHI[i];
	jet1[2] = JETak_ETA[i];
	if(JETak_PT[i] > Jet1_Pt_Cut)
	  leading_jetak = true;
      }
      else if(JETak_PT[i] > jet2[1] && JETak_PT[i] < jet1[1]){
	jet2[1] = JETak_PT[i];
	jet2[0] = JETak_ET[i];
	jet2[3] = JETak_PHI[i];
	jet2[2] = JETak_ETA[i];
      }
      htvecak[0]+=JETak_PT[i];
      htvecak[2]+=JETak_PX[i];
      htvecak[3]+=JETak_PY[i];
      sel_jetak.push_back(i);
    }
    hist_HTak->Fill(htvecak[0],weight);
    htvecak[1]=sqrt(htvecak[2]*htvecak[2]+htvecak[3]*htvecak[3]);
    hist_MHTak->Fill(htvecak[1],weight);

    hist_jet_multiplicity_after_pt_cutak->Fill(cont_jet_after_pt,weight);
    hist_jet_multiplicity_after_eta_cutak->Fill(cont_jet_after_eta,weight);

    if( sel_jetak.size() >= 2 && leading_jetak)
      two_leading_jetsak = true;

    bool srtwojetak = false; 
    float angle_mindhtak[4]={0,0,0,0};
    float angle_reclusak[4]={0,0,0,0};

    if( sel_jetak.size() == 2 && two_leading_jetsak){
      srtwojetak = true;
      alphatvecak[0] = sqrt( (jet2[0])/(2*jet1[0]*(1-cos(jet1[3]-jet2[3]))));
      //      cout << "caso 2 jetsak " << alphatvecak[0] << endl;
      alphatvecak[1] = alphatvecak[0];
      alphatvecak[2] = alphatvecak[0];
      alphatvecak[3] = alphatvecak[0];
      hist_deltaeta_vs_deltaphi_2jetsak->Fill(jet1[3]-jet2[3],jet1[2]-jet2[2],weight);
      hist_alphat_twojetsak->Fill(alphatvecak[0],weight);
    }
    else if(sel_jetak.size() > 2 && two_leading_jetsak){
      //      cout << Jets.size() << endl;
      std::vector<std::vector<double> > result=AlphaT(Jets);
      alphatvecak[0] = result[0][0];
      //      cout << "caso mas de dos jetsak " << alphatvecak[0] << endl; 
      hist_alphat_njets_minimum_deltahtak->Fill(result[0][0],weight);
      hist_deltaeta_vs_deltaphi_njetsak->Fill(result[0][3]-result[1][3],result[0][2]-result[1][2],weight);
      angle_mindhtak[0] = result[0][2];  ///////eta
      angle_mindhtak[1] = result[1][2];
      angle_mindhtak[2] = result[0][3]; ////////phi
      angle_mindhtak[3] = result[1][3];

      result.clear();
      result=AlphaTReClus(Jets);
      if(result.size() == 3){
	if(result[1][0] != 0 )
	  hist_deltaeta_vs_deltaphi_njets_reclusterak->Fill(result[0][6]-result[1][6],result[0][5]-result[1][5],weight);
	angle_reclusak[0] = result[0][5]; //////eta
	angle_reclusak[1] = result[1][5];
	angle_reclusak[2] = result[0][6]; /////phi
	angle_reclusak[3] = result[1][6];
	
	hist_alphat_njets_as_two_jetsak->Fill(result[2][0],weight);
	hist_alphat_njets_as_reclusteredak->Fill(result[2][1],weight);
	hist_alphat_njets_as_reclustered_recomputed_htak->Fill(result[2][2],weight);
	alphatvecak[1] = result[2][0];
	alphatvecak[2] = result[2][1];
	alphatvecak[3] = result[2][2];
      }
    }


    ///////////////////////////////////////////
    //////////PFJet cycle
    ///////////////////////////////////
    //    cout << "pf jet " << endl;
    cont_jet_after_pt = 0;
    cont_jet_after_eta = 0;
    jet1.clear();
    jet2.clear();
    for(int i=0;i<4;i++){
      jet1.push_back(0.);
      jet2.push_back(0.);
    }
    //    alphat = -1;
    Jets.clear();
    temp.clear();
    for(unsigned int i=0;i<4;i++){
      pfhtvec.push_back(0.);
    }
    for(unsigned int i = 0; i<NPFJET; i++ ){
      temp.clear();
      temp.push_back(PFJET_ET[i]);
      temp.push_back(PFJET_PT[i]);
      temp.push_back(PFJET_PX[i]);
      temp.push_back(PFJET_PY[i]);
      temp.push_back(PFJET_PZ[i]);
      temp.push_back(PFJET_ETA[i]);
      temp.push_back(PFJET_PHI[i]);
      //Jets.push_back(temp);
      if( PFJET_PT[i] < Jet_Pt_Cut )
	continue;
      cont_jet_after_pt++;
      if( fabs(PFJET_ETA[i]) > Jet_Eta_Cut)
	continue;
      cont_jet_after_eta++;
      Jets.push_back(temp);
      temp.clear();
      if(PFJET_PT[i] > jet1[1]){
	jet1[1] = PFJET_PT[i];
	jet1[0] = PFJET_ET[i];
	jet1[3] = PFJET_PHI[i];
	jet1[2] = PFJET_ETA[i];
	if(PFJET_PT[i] > Jet1_Pt_Cut)
	  leading_pfjet = true;
      }
      else if(PFJET_PT[i] > jet2[1] && PFJET_PT[i] < jet1[1]){
	jet2[1] = PFJET_PT[i];
	jet2[0] = PFJET_ET[i];
	jet2[3] = PFJET_PHI[i];
	jet2[2] = PFJET_ETA[i];
      }
      pfhtvec[0]+=JET_PT[i];
      pfhtvec[2]+=JET_PX[i];
      pfhtvec[3]+=JET_PY[i];
      sel_pfjet.push_back(i);
    }
    hist_PFHT->Fill(pfhtvec[0],weight);
    pfhtvec[1] = sqrt(pfhtvec[2]*pfhtvec[2]+pfhtvec[3]*pfhtvec[3]);

    hist_PFMHT->Fill(pfhtvec[1],weight);
    hist_PFjet_multiplicity_after_pt_cut->Fill(cont_jet_after_pt,weight);
    hist_PFjet_multiplicity_after_eta_cut->Fill(cont_jet_after_eta,weight);

    if( sel_pfjet.size() >= 2 && leading_pfjet)
      two_leading_PFjets = true;

    bool pftwojet = false;
    float pfangle_mindht[4]={0,0,0,0};
    float pfangle_reclus[4]={0,0,0,0};

    if(sel_pfjet.size() == 2 && two_leading_PFjets){
      pftwojet = true;
      pfalphatvec[0] = sqrt( (jet2[0])/(2*jet1[0]*(1-cos(jet1[3]-jet2[3]))));
      pfalphatvec[1] = pfalphatvec[0];
      pfalphatvec[2] = pfalphatvec[0];
      pfalphatvec[3] = pfalphatvec[0];
      hist_deltaeta_vs_deltaphi_2PFjets->Fill(jet1[3]-jet2[3],jet1[2]-jet2[2],weight);
      hist_alphat_twoPFjets->Fill(pfalphatvec[0],weight);
    }
    else if(sel_pfjet.size() > 2 && two_leading_PFjets){
      std::vector<std::vector<double> > result=AlphaT(Jets);
      hist_alphat_nPFjets_minimum_deltaht->Fill(result[0][0],weight);
      pfalphatvec[0] = result[0][0];
      hist_deltaeta_vs_deltaphi_nPFjets->Fill(result[0][3]-result[1][3],result[0][2]-result[1][2],weight);
      pfangle_mindht[0]=result[0][2]; ///////eta
      pfangle_mindht[1]=result[1][2];
      pfangle_mindht[2]=result[0][3];  ///////phi
      pfangle_mindht[3]=result[1][3];

      result.clear();
      result=AlphaTReClus(Jets);
      if(result.size() == 3){
	if(result[1][0] != 0 )
	  hist_deltaeta_vs_deltaphi_nPFjets_recluster->Fill(result[0][6]-result[1][6],result[0][5]-result[1][5],weight);
	pfangle_reclus[0]=result[0][5];    /////eta
	pfangle_reclus[1]=result[1][5];
	pfangle_reclus[2]=result[0][6];   //////phi
	pfangle_reclus[3]=result[1][6];
	hist_alphat_nPFjets_as_two_jets->Fill(result[2][0],weight);
	hist_alphat_nPFjets_as_reclustered->Fill(result[2][1],weight);
	hist_alphat_nPFjets_as_reclustered_recomputed_ht->Fill(result[2][2],weight);
	pfalphatvec[1] = result[2][0];
	pfalphatvec[2] = result[2][1];
	pfalphatvec[3] = result[2][2];
      }
    }

    ///////////////////////////////////////////
    //////////PFJetak cycle
    ///////////////////////////////////
    //    cout << "pfjet ak " << endl;
    cont_jet_after_pt = 0;
    cont_jet_after_eta = 0;
    jet1.clear();
    jet2.clear();
    for(int i=0;i<4;i++){
      jet1.push_back(0.);
      jet2.push_back(0.);
    }
    //    alphat = -1;
    Jets.clear();
    temp.clear();
    for(unsigned int i=0;i<4;i++){
      pfhtvecak.push_back(0.);
    }
    for(unsigned int i = 0; i<NPFJETak; i++ ){
      temp.clear();
      temp.push_back(PFJETak_ET[i]);
      temp.push_back(PFJETak_PT[i]);
      temp.push_back(PFJETak_PX[i]);
      temp.push_back(PFJETak_PY[i]);
      temp.push_back(PFJETak_PZ[i]);
      temp.push_back(PFJETak_ETA[i]);
      temp.push_back(PFJETak_PHI[i]);
      //Jets.push_back(temp);
      if( PFJETak_PT[i] < Jet_Pt_Cut )
	continue;
      cont_jet_after_pt++;
      if( fabs(PFJETak_ETA[i]) > Jet_Eta_Cut)
	continue;
      cont_jet_after_eta++;
      Jets.push_back(temp);
      temp.clear();
      if(PFJETak_PT[i] > jet1[1]){
	jet1[1] = PFJETak_PT[i];
	jet1[0] = PFJETak_ET[i];
	jet1[3] = PFJETak_PHI[i];
	jet1[2] = PFJETak_ETA[i];
	if(PFJETak_PT[i] > Jet1_Pt_Cut)
	  leading_pfjetak = true;
      }
      else if(PFJETak_PT[i] > jet2[1] && PFJETak_PT[i] < jet1[1]){
	jet2[1] = PFJETak_PT[i];
	jet2[0] = PFJETak_ET[i];
	jet2[3] = PFJETak_PHI[i];
	jet2[2] = PFJETak_ETA[i];
      }
      pfhtvecak[0]+=JETak_PT[i];
      pfhtvecak[2]+=JETak_PX[i];
      pfhtvecak[3]+=JETak_PY[i];
      sel_pfjetak.push_back(i);
    }
    hist_PFHTak->Fill(pfhtvecak[0],weight);
    pfhtvecak[1] = sqrt(pfhtvecak[2]*pfhtvecak[2]+pfhtvecak[3]*pfhtvecak[3]);

    hist_PFMHTak->Fill(pfhtvecak[1],weight);
    hist_PFjet_multiplicity_after_pt_cutak->Fill(cont_jet_after_pt,weight);
    hist_PFjet_multiplicity_after_eta_cutak->Fill(cont_jet_after_eta,weight);

    if( sel_pfjetak.size() >= 2 && leading_pfjetak)
      two_leading_PFjetsak = true;

    bool pftwojetak = false;
    float pfangle_mindhtak[4]={0,0,0,0};
    float pfangle_reclusak[4]={0,0,0,0};

    if(sel_pfjetak.size() == 2 && two_leading_PFjetsak){
      pftwojetak = true;
      pfalphatvecak[0] = sqrt( (jet2[0])/(2*jet1[0]*(1-cos(jet1[3]-jet2[3]))));
      pfalphatvecak[1] = pfalphatvecak[0];
      pfalphatvecak[2] = pfalphatvecak[0];
      pfalphatvecak[3] = pfalphatvecak[0];
      hist_deltaeta_vs_deltaphi_2PFjetsak->Fill(jet1[3]-jet2[3],jet1[2]-jet2[2],weight);
      hist_alphat_twoPFjetsak->Fill(pfalphatvecak[0],weight);
    }
    else if(sel_pfjetak.size() > 2 && two_leading_PFjetsak){
      std::vector<std::vector<double> > result=AlphaT(Jets);
      hist_alphat_nPFjets_minimum_deltahtak->Fill(result[0][0],weight);
      pfalphatvecak[0] = result[0][0];
      hist_deltaeta_vs_deltaphi_nPFjetsak->Fill(result[0][3]-result[1][3],result[0][2]-result[1][2],weight);
      pfangle_mindhtak[0]=result[0][2]; ///////eta
      pfangle_mindhtak[1]=result[1][2];
      pfangle_mindhtak[2]=result[0][3];  ///////phi
      pfangle_mindhtak[3]=result[1][3];

      result.clear();
      result=AlphaTReClus(Jets);
      if(result.size() == 3){
	if(result[1][0] != 0 )
	  hist_deltaeta_vs_deltaphi_nPFjets_reclusterak->Fill(result[0][6]-result[1][6],result[0][5]-result[1][5],weight);
	pfangle_reclusak[0]=result[0][5];    /////eta
	pfangle_reclusak[1]=result[1][5];
	pfangle_reclusak[2]=result[0][6];   //////phi
	pfangle_reclusak[3]=result[1][6];
       	hist_alphat_nPFjets_as_two_jetsak->Fill(result[2][0],weight);
	hist_alphat_nPFjets_as_reclusteredak->Fill(result[2][1],weight);
	hist_alphat_nPFjets_as_reclustered_recomputed_htak->Fill(result[2][2],weight);
	pfalphatvecak[1] = result[2][0];
	pfalphatvecak[2] = result[2][1];
	pfalphatvecak[3] = result[2][2];
      }
    }

    /////////////////////////
    ////////jet comparison
    ///////////////
    hist_n_SR_vs_PF_jets->Fill(NJET,NPFJET);
    hist_n_SR_vs_PF_jets_after->Fill(sel_jet.size(),sel_pfjet.size());
    if(srtwojet && pftwojet){
      hist_alphat_twojets_dif->Fill(alphatvec[0] - pfalphatvec[0],weight);
      hist_alphat_twoSRjets_twoPFjets_metdif->Fill(MET-PFMET,weight);
    }
    else if( sel_jet.size() > 2 && sel_pfjet.size() > 2){
      hist_dif_alphat_mindht_SR_PF->Fill(alphatvec[0]-pfalphatvec[0]);
      hist_dif_alphat_Reclus_SR_PF->Fill(alphatvec[2]-pfalphatvec[2]);
      if(alphatvec[2]-pfalphatvec[2] <= 1.6 && alphatvec[2]-pfalphatvec[2] >= 1.2){
	//	std::cout << "New Event Run: " << RUN << " EVENT: " << EVENT << " LUMIsection: " << LUMISEC << endl; 
	hist_n_SR_vs_PF_jets_peak_reclus_dif_after->Fill(sel_jet.size(),sel_pfjet.size());
	hist_n_SR_vs_PF_jets_peak_reclus_dif->Fill(NJET,NPFJET);
	float pfeta1=-100,pfphi1=-100,pfeta2=-100,pfphi2=-100,eta1=-100,eta2=-100,phi1=-100,phi2=-100;
	float pfeta1re=-100,pfphi1re=-100,pfeta2re=-100,pfphi2re=-100,eta1re=-100,eta2re=-100,phi1re=-100,phi2re=-100;
	pfeta1 = pfangle_mindht[0];
	pfphi1 = pfangle_mindht[2];
	pfeta2 = pfangle_mindht[1];
	pfphi2 = pfangle_mindht[3];
	pfeta1re = pfangle_reclus[0];
	pfphi1re = pfangle_reclus[2];
	pfeta2re = pfangle_reclus[1];
	pfphi2re = pfangle_reclus[3];
	if( sqrt( pow(pfeta1 - angle_mindht[0],2) + pow(pfphi1 - angle_mindht[2],2)) < sqrt( pow(pfeta1 - angle_mindht[1],2) + pow(pfphi1 - angle_mindht[3],2)) ){
	  eta1 = angle_mindht[0];
	  phi1 = angle_mindht[2];
	  eta2 = angle_mindht[1];
	  phi2 = angle_mindht[3];
	}
	else{
	  eta1 = angle_mindht[1];
	  phi1 = angle_mindht[3];
	  eta2 = angle_mindht[0];
	  phi2 = angle_mindht[2];
	}
	if( sqrt( pow(pfeta1 - angle_reclus[0],2) + pow(pfphi1 - angle_reclus[2],2)) < sqrt( pow(pfeta1 - angle_reclus[1],2) + pow(pfphi1 - angle_reclus[3],2)) ){
	  eta1re = angle_reclus[0];
	  phi1re = angle_reclus[2];
	  eta2re = angle_reclus[1];
	  phi2re = angle_reclus[3];
	}
	else{
	  eta1re = angle_reclus[1];
	  phi1re = angle_reclus[3];
	  eta2re = angle_reclus[0];
	  phi2re = angle_reclus[2];
	}
	hist_deltaeta_vs_deltaphi_peakPF_recluster->Fill(pfeta1re-pfeta2re,pfphi1re-pfphi2re,weight);
	hist_deltaeta_vs_deltaphi_peakPF_mindht->Fill(pfeta1-pfeta2,pfphi1-pfphi2,weight);
	hist_deltaeta_vs_deltaphi_peakSR_recluster->Fill(phi1re-phi2re,eta1re-eta2re,weight);
	hist_deltaeta_vs_deltaphi_peakSR_mindht->Fill(phi1-phi2,eta1-eta2,weight);
	hist_deltaeta_firstjet_peakPF_mindht_recluster->Fill(pfeta1-pfeta1re);
	hist_deltaphi_firstjet_peakPF_mindht_recluster->Fill(pfphi1-pfphi1re);
	hist_deltaeta_secondjet_peakPF_mindht_recluster->Fill(pfeta2-pfeta2re);
	hist_deltaphi_secondjet_peakPF_mindht_recluster->Fill(pfphi2-pfphi2re);
	hist_deltaeta_firstjet_peakSR_mindht_recluster->Fill(eta1-eta1re);
	hist_deltaphi_firstjet_peakSR_mindht_recluster->Fill(phi1-phi1re);
	hist_deltaeta_secondjet_peakSR_mindht_recluster->Fill(eta2-eta2re);
	hist_deltaphi_secondjet_peakSR_mindht_recluster->Fill(phi2-phi2re);
	hist_deltaeta_firstjet_peak_SR_vs_PF_mindht->Fill(eta1-pfeta1);
	hist_deltaphi_firstjet_peak_SR_vs_PF_mindht->Fill(phi1-pfphi1);
	hist_deltaeta_secondjet_peak_SR_vs_PF_mindht->Fill(eta2-pfeta2);
	hist_deltaphi_secondjet_peak_SR_vs_PF_mindht->Fill(phi2-pfphi2);
	hist_deltaeta_firstjet_peak_SR_vs_PF_recluster->Fill(eta1re-pfeta1re);
	hist_deltaphi_firstjet_peak_SR_vs_PF_recluster->Fill(phi1re-pfphi1re);
	hist_deltaeta_secondjet_peak_SR_vs_PF_recluster->Fill(eta2re-pfeta2re);
	hist_deltaphi_secondjet_peak_SR_vs_PF_recluster->Fill(phi2re-pfphi2re);

	int fir=0,se=0;
	float firma=0,sema=0;
	for(unsigned int i = 0; i < sel_jet.size(); i++ ){
	  //	  std::cout << "\tJet number " << i << " pt, eta, phi, et: " << JET_PT[sel_jet[i]] << " " << JET_ETA[sel_jet[i]] << " " << JET_PHI[sel_jet[i]] << " " << JET_ET[sel_jet[i]] << std::endl; 
	  if(JET_PT[sel_jet[i]]>firma){
	    fir=i;
	    firma = JET_PT[sel_jet[i]];
	  }
	  if(JET_PT[sel_jet[i]]<firma && JET_PT[sel_jet[i]]>sema){
	    se=sel_jet[i];
	    sema=JET_PT[sel_jet[i]];
	  }
	}
	hist_firstSRjet_peak_pt->Fill(JET_PT[fir]);
	hist_firstSRjet_peak_eta->Fill(JET_ETA[fir]);
	hist_firstSRjet_peak_phi->Fill(JET_PHI[fir]);
	hist_secondSRjet_peak_pt->Fill(JET_PT[se]);
	hist_secondSRjet_peak_eta->Fill(JET_ETA[se]);
	hist_secondSRjet_peak_phi->Fill(JET_PHI[se]);
	fir=0;se=0;
	firma=0;sema=0;
	for(unsigned int i = 0; i<sel_pfjet.size(); i++ ){
	  //	  std::cout << "\t\t PFJet number " << i << " pt, eta, phi, et: " << PFJET_PT[sel_pfjet[i]] << " " << PFJET_ETA[sel_pfjet[i]] << " " << PFJET_PHI[sel_pfjet[i]] << " " << PFJET_ET[sel_pfjet[i]] << std::endl; 
	  if(PFJET_PT[sel_pfjet[i]]>firma){
	    fir=sel_pfjet[i];
	    firma = PFJET_PT[sel_pfjet[i]];
	  }
	  if(PFJET_PT[sel_pfjet[i]]<firma && PFJET_PT[sel_pfjet[i]]>sema){
	    se=sel_pfjet[i];
	    sema=PFJET_PT[sel_pfjet[i]];
	  }
	}
	hist_firstPFjet_peak_pt->Fill(PFJET_PT[fir]);
	hist_firstPFjet_peak_eta->Fill(PFJET_ETA[fir]);
	hist_firstPFjet_peak_phi->Fill(PFJET_PHI[fir]);
	hist_secondPFjet_peak_pt->Fill(PFJET_PT[se]);
	hist_secondPFjet_peak_eta->Fill(PFJET_ETA[se]);
	hist_secondPFjet_peak_phi->Fill(PFJET_PHI[se]);
      }
      else if(fabs(alphatvec[2]-pfalphatvec[2]) <= 1){
	float pfeta1=-100,pfphi1=-100,pfeta2=-100,pfphi2=-100,eta1=-100,eta2=-100,phi1=-100,phi2=-100;
	float pfeta1re=-100,pfphi1re=-100,pfeta2re=-100,pfphi2re=-100,eta1re=-100,eta2re=-100,phi1re=-100,phi2re=-100;
	pfeta1 = pfangle_mindht[0];
	pfphi1 = pfangle_mindht[2];
	pfeta2 = pfangle_mindht[1];
	pfphi2 = pfangle_mindht[3];
	pfeta1re = pfangle_reclus[0];
	pfphi1re = pfangle_reclus[2];
	pfeta2re = pfangle_reclus[1];
	pfphi2re = pfangle_reclus[3];
	if( sqrt( pow(pfeta1 - angle_mindht[0],2) + pow(pfphi1 - angle_mindht[2],2)) < sqrt( pow(pfeta1 - angle_mindht[1],2) + pow(pfphi1 - angle_mindht[3],2)) ){
	  eta1 = angle_mindht[0];
	  phi1 = angle_mindht[2];
	  eta2 = angle_mindht[1];
	  phi2 = angle_mindht[3];
	}
	else{
	  eta1 = angle_mindht[1];
	  phi1 = angle_mindht[3];
	  eta2 = angle_mindht[0];
	  phi2 = angle_mindht[2];
	}
	if( sqrt( pow(pfeta1 - angle_reclus[0],2) + pow(pfphi1 - angle_reclus[2],2)) < sqrt( pow(pfeta1 - angle_reclus[1],2) + pow(pfphi1 - angle_reclus[3],2)) ){
	  eta1re = angle_reclus[0];
	  phi1re = angle_reclus[2];
	  eta2re = angle_reclus[1];
	  phi2re = angle_reclus[3];
	}
	else{
	  eta1re = angle_reclus[1];
	  phi1re = angle_reclus[3];
	  eta2re = angle_reclus[0];
	  phi2re = angle_reclus[2];
	}
	if(eta1re == 0 && eta2re == 0 && phi1re == 0 && phi2re == 0)
	  float a = 0;
	else{
	  hist_deltaeta_vs_deltaphi_peakSR_recluster_1p->Fill(phi1re-phi2re,eta1re-eta2re,weight);
	  hist_deltaeta_vs_deltaphi_peakSR_mindht_1p->Fill(phi1-phi2,eta1-eta2,weight);
	  /*
	  if(phi1re-phi2re == 0 && eta1re-eta2re == 0){
	    cout << "phi1 " << phi1re << endl;
	    cout << "phi2 " << phi2re << endl;
	    cout << "eta1 " << eta1re << endl;
	    cout << "eta2 " << eta2re << endl;
	  }
	  */
	}
      } 
      hist_dif_alphat_SR_mindht_reclus->Fill(alphatvec[0]-alphatvec[2]);
      hist_dif_alphat_PF_mindht_reclus->Fill(pfalphatvec[0]-pfalphatvec[2]);
    }
    /*
      std::cout << "Two Jets for both SR and PF, SR alphat: " << alphatvec[0] << " PF alphat: " << pfalphatvec[0] << " difference: " << alphatvec[0] - pfalphatvec[0] << std::endl;
      float totht = 0;
      totht+=htvec[0];
      for(unsigned int i = 0; i<sel_el.size(); i++)
	totht+=sel_el[i];
      for(unsigned int i = 0; i<sel_mu.size(); i++)
	totht+=sel_mu[i];
      for(unsigned int i = 0; i<sel_tau.size(); i++)
	totht+=sel_tau[i];
      float totpfht = 0;
      totpfht+=pfhtvec[0];
      for(unsigned int i = 0; i<sel_pfel.size(); i++)
	totpfht+=sel_pfel[i];
      for(unsigned int i = 0; i<sel_pfmu.size(); i++)
	totpfht+=sel_pfmu[i];
      for(unsigned int i = 0; i<sel_pftau.size(); i++)
	totpfht+=sel_pftau[i];
      hist_totht_dif_sr_vs_pf->Fill(totht-totpfht,weight);
    }
    else if(srtwojet && ! pftwojet && sel_pfjet.size() == 1){
      std::cout << "pf alphat " << pfalphatvec[0] << std::endl;
      hist_alphat_twoSRjets_notwoPFjets_metdif->Fill(MET-PFMET,weight);
      float totht = 0;
      totht+=htvec[0];
      for(unsigned int i = 0; i<sel_el.size(); i++)
	totht+=sel_el[i];
      for(unsigned int i = 0; i<sel_mu.size(); i++)
	totht+=sel_mu[i];
      for(unsigned int i = 0; i<sel_tau.size(); i++)
	totht+=sel_tau[i];
      float totpfht = 0;
      totpfht+=pfhtvec[0];
      for(unsigned int i = 0; i<sel_pfel.size(); i++)
	totpfht+=sel_pfel[i];
      for(unsigned int i = 0; i<sel_pfmu.size(); i++)
	totpfht+=sel_pfmu[i];
      for(unsigned int i = 0; i<sel_pftau.size(); i++)
	totpfht+=sel_pftau[i];
      hist_totht_dif_sr_vs_pf_nopftwojets->Fill(totht-totpfht,weight);
    }
    else if(srtwojet && !pftwojet && sel_pfjet.size() >2 ){
      std::cout << "engendro" << std::endl;
    }
   
      std::cout << "\n Two sr jet not two pf jet event, Run: " << RUN << " EVENT: " << EVENT << " LUMIsection: " << LUMISEC << std::endl;    
      std::cout << "\t SR jets before cuts: " << NJET << " SR jets after cuts : " << sel_jet.size(); 
      for(unsigned int i = 0; i<NJET; i++ ){
	std::cout << "\n\t\t Jet ET " << JET_ET[i] << " pt " << JET_PT[i] << " px " << JET_PX[i] << " py " << JET_PY[i] << " pz " << JET_PZ[i]
		  << " eta " << JET_ETA[i] << " phi " << JET_PHI[i];
	if(JET_PT[i] < Jet_Pt_Cut)
	  continue;
	if(fabs(JET_ETA[i]) > Jet_Eta_Cut)
	  continue;
	std::cout << " pass ";
      }
      std::cout << "\n\t PF jets before cuts: " << NPFJET << " PF jets after cuts : " << sel_pfjet.size(); 
      for(unsigned int i = 0; i<NPFJET; i++ ){
	std::cout << "\n\t\t PFJet ET " << PFJET_ET[i] << " pt " << PFJET_PT[i] << " px " << PFJET_PX[i] << " py " << PFJET_PY[i] << " pz " << PFJET_PZ[i]
		  << " eta " << PFJET_ETA[i] << " phi " << PFJET_PHI[i];
	if(PFJET_PT[i] < Jet_Pt_Cut)
	  continue;
	if(fabs(PFJET_ETA[i]) > Jet_Eta_Cut)
	  continue;
	std::cout << " pass ";
      }
      std::cout << "\n \tSR Tau before cuts: " << NTau << " sr taus after cuts : " << sel_tau.size(); 
      for(unsigned int i=0;i<NTau;i++){
	std::cout << "\n\t\t SR Tau ET " << Tau_ET[i] << " pt " << Tau_PT[i] << " px " << Tau_PX[i] << " py " << Tau_PY[i] << " pz " << Tau_PZ[i]
		  << " eta " << Tau_ETA[i] << " phi " << Tau_PHI[i];
	if((Tau_PT[i] > Tau_Pt_Cut) && (fabs(Tau_ETA[i]) > Tau_Eta_Cut) )
	  std::cout << " pass ";
      }
      std::cout << "\n \tPF Tau before cuts: " << NPFTau << " PF taus after cuts : " << sel_pftau.size(); 
      for(unsigned int i=0;i<NPFTau;i++){
	std::cout << "\n\t\t PF Tau ET " << PFTau_ET[i] << " pt " << PFTau_PT[i] << " px " << PFTau_PX[i] << " py " << PFTau_PY[i] << " pz " << PFTau_PZ[i]
		  << " eta " << PFTau_ETA[i] << " phi " << PFTau_PHI[i] << " discr: " << PFTau_TaNC[i];
	if((PFTau_PT[i] > Tau_Pt_Cut) && (fabs(PFTau_ETA[i]) > Tau_Eta_Cut) )
	  std::cout << " pass ";
      }
      std::cout << "\n \tPF electrons before cuts: " << NPFEl << " PF electrons after cuts : " << sel_pfel.size(); 
      for(unsigned int i=0;i<NPFEl;i++){
	std::cout << "\n\t\t PF Electron ET " << PFEl_ET[i] << " pt " << PFEl_PT[i] << " px " << PFEl_PX[i] << " py " << PFEl_PY[i] << " pz " << PFEl_PZ[i] << " eta " << PFEl_ETA[i] << " phi " << PFEl_PHI[i];
	if(PFEl_PT[i] < El_Pt_Cut)
	  continue;
	if(fabs(PFEl_ETA[i]) > El_Eta_Cut)
	  continue;
	if(PFEl_MVA[i] < El_MVA_Cut)
	  continue;
	if(fabs(PFEl_D0[i]) > El_D0_Cut )
	  continue;
	std::cout << " pass ";
      }
      std::cout << "\n \tPF muons before cuts: " << NPFMu << " PF muons after cuts : " << sel_pfmu.size(); 
      for(unsigned int i=0;i<NPFMu;i++){
	std::cout << "\n\t\t PF Muons ET " << PFMu_ET[i] << " pt " << PFMu_PT[i] << " px " << PFMu_PX[i] << " py " << PFMu_PY[i] << " pz " << PFMu_PZ[i] << " eta " << PFMu_ETA[i] << " phi " << PFMu_PHI[i];
	if(PFMu_PT[i] < Mu_Pt_Cut )
	  continue;
	if(fabs(PFMu_ETA[i]) > Mu_Eta_Cut )
	  continue;
	if(PFMu_Chi2dof[i] > Mu_Chi2dof_Cut)
	  continue;
	if(PFMu_NHitsTrack[i] < Mu_NHits_Cut)
	  continue;
	if(fabs(PFMu_D0[i]) > Mu_D0_Cut)
	  continue;
	if(PFMu_isGlobal[i] == 0 )
	  continue;
	std::cout << " pass ";
      }
    }
      */

    //    cout << "single lepton cycle" << endl;

    //////////////////////////////
    ////////////////single lepton
    /////////////////////
    
    if(MET > Met_high_Cut && sel_jet.size() >= 2 && leading_jet){
      if(sel_jet.size()==2){
	hist_alphatdis_twojets_SL->Fill(alphatvec[0],weight);
	if( alphatvec[0] > Alphat_Cut )
	  hist_alphat_2j_SLCuts->Fill(1,weight);
      }
      if(sel_jet.size() > 2){
	hist_alphat_njets_minimum_deltaht_SL->Fill(alphatvec[0],weight);
	hist_alphat_njets_as_reclustered_SL->Fill(alphatvec[2],weight);
	if( alphatvec[0] > Alphat_Cut )
	  hist_alphat_nj_SLCuts->Fill(1,weight);
	if( alphatvec[2] > Alphat_Cut )
	  hist_alphat_nj_re_SLCuts->Fill(1,weight);
      }
      if( alphatvec[0] > Alphat_Cut )
	hist_alphat_SLCuts->Fill(1,weight);
      if( alphatvec[2] > Alphat_Cut )
	hist_alphat_re_SLCuts->Fill(1,weight);
      if(sel_el.size() == 1 && sel_mu.size() == 0 && sel_tau.size() == 0){
	hist_single_el->Fill(1,weight);
      }
      if(sel_mu.size() == 1 && sel_el.size() == 0 && sel_tau.size() == 0){
	hist_single_mu->Fill(1,weight);
      }
      if(sel_tau.size() == 1 && sel_mu.size() == 0 && sel_el.size() == 0){
	hist_single_tau->Fill(1,weight);
      }
    }
    //    cout << "single lepton  ak cycle" << endl;
    if(METak > Met_high_Cut && sel_jetak.size() >= 2 && leading_jetak){
      if(sel_jetak.size()==2){
	hist_alphatdis_twojets_SLak->Fill(alphatvecak[0],weight);
	if( alphatvecak[0] > Alphat_Cut )
	  hist_alphat_2j_SLCutsak->Fill(1,weight);
      }
      if(sel_jetak.size() > 2){
	hist_alphat_njets_minimum_deltaht_SLak->Fill(alphatvecak[0],weight);
	hist_alphat_njets_as_reclustered_SLak->Fill(alphatvecak[2],weight);
	if( alphatvecak[0] > Alphat_Cut )
	  hist_alphat_nj_SLCutsak->Fill(1,weight);
	if( alphatvecak[2] > Alphat_Cut )
	  hist_alphat_nj_re_SLCutsak->Fill(1,weight);
      }
      if( alphatvecak[0] > Alphat_Cut )
	hist_alphat_SLCutsak->Fill(1,weight);
      if( alphatvecak[2] > Alphat_Cut )
	hist_alphat_re_SLCutsak->Fill(1,weight);
    }
    
    //////////////////////////////
    ////////////////single lepton PF
    /////////////////////
    //    cout << "single lepton pf cycle" << endl;
    if(PFMET > Met_high_Cut && sel_pfjet.size() >= 2 && leading_pfjet){
      if(sel_pfjet.size()==2){
	hist_alphatdis_twoPFjets_SL->Fill(pfalphatvec[0],weight);
	if( pfalphatvec[0] > Alphat_Cut)
	  hist_alphat_2j_PFSLCuts->Fill(1,weight);
      }
      if(sel_pfjet.size() > 2){
	hist_alphat_nPFjets_minimum_deltaht_SL->Fill(pfalphatvec[0],weight);
	hist_alphat_nPFjets_as_reclustered_SL->Fill(pfalphatvec[2],weight);
	if( pfalphatvec[0] > Alphat_Cut)
	  hist_alphat_nj_PFSLCuts->Fill(1,weight);
	if( pfalphatvec[2] > Alphat_Cut)
	  hist_alphat_nj_re_PFSLCuts->Fill(1,weight);
      }
      if( pfalphatvec[0] > Alphat_Cut)
	hist_alphat_PFSLCuts->Fill(1,weight);
      if( pfalphatvec[2] > Alphat_Cut)
	hist_alphat_re_PFSLCuts->Fill(1,weight);
      if(sel_pfel.size() == 1 && sel_pfmu.size() == 0 && sel_pftau.size() == 0){
	hist_single_pfel->Fill(1,weight);
      }
      if(sel_pfmu.size() == 1 && sel_pfel.size() == 0 && sel_pftau.size() == 0) {
	hist_single_pfmu->Fill(1,weight);
      }
      if(sel_pftau.size() == 1 && sel_pfmu.size() == 0 && sel_pfel.size() == 0){
	hist_single_pftau->Fill(1,weight);
      }
    }
    //    cout << "single lepton cycle pf" << endl;
    if(PFMET > Met_high_Cut && sel_pfjetak.size() >= 2 && leading_pfjetak){
      if(sel_pfjetak.size()==2){
	hist_alphatdis_twoPFjets_SLak->Fill(pfalphatvecak[0],weight);
	if( pfalphatvecak[0] > Alphat_Cut)
	  hist_alphat_2j_PFSLCutsak->Fill(1,weight);
      }
      if(sel_pfjetak.size() > 2){
	hist_alphat_nPFjets_minimum_deltaht_SLak->Fill(pfalphatvecak[0],weight);
	hist_alphat_nPFjets_as_reclustered_SLak->Fill(pfalphatvecak[2],weight);
	if( pfalphatvecak[0] > Alphat_Cut)
	  hist_alphat_nj_PFSLCutsak->Fill(1,weight);
	if( pfalphatvecak[2] > Alphat_Cut)
	  hist_alphat_nj_re_PFSLCutsak->Fill(1,weight);
      }
      if( pfalphatvecak[0] > Alphat_Cut)
	hist_alphat_PFSLCutsak->Fill(1,weight);
      if( pfalphatvecak[2] > Alphat_Cut)
	hist_alphat_re_PFSLCutsak->Fill(1,weight);

    }
    
    ///////////////////////////////////////
    /////////////////double lepton opposite sign
    ///////////////////////////////
    //    cout << "METak " << METak << " Htak: " << htvecak[0] << " mhtak: " << htvecak[1] << endl;
    //    cout << "double  lepton ak cycle" << endl;
    if(METak > Met_Cut && htvecak[0] > HT_high_Cut && htvecak[1] > MHT_Cut){
      //      cout << "number of ak jets " << sel_jetak.size() << endl;
      if(sel_jetak.size()==2){
	float jet1pt = 0, jet2pt = 0, jet1eta = 0, jet2eta = 0, jet1phi = 0 ,jet2phi = 0;
	bool stat = false;
	for(unsigned int i = 0; i<NJETak; i++ ){
	  if(JETak_PT[i] < Jet_Pt_Cut)
	    continue;
	  if(fabs(JETak_ETA[i]) > Jet_Eta_Cut)
	    continue;
	  if(JETak_PT[i] > jet1pt){
	    jet1pt = JETak_PT[i];
	    jet1phi = JETak_PHI[i];
	    jet1eta = JETak_ETA[i];
	  }
	  else if(JETak_PT[i] > jet2pt && JETak_PT[i] < jet1pt){
	    jet2pt = JETak_PT[i];
	    jet2phi = JETak_PHI[i];
	    jet2eta = JETak_ETA[i];
	  }
	}
	//	cout << "alphatvecak[0] " << alphatvecak[0] << endl;
	if(alphatvecak[0] > 2){
	  hist_2jets_dl_big2_eta_firstjetak->Fill(jet1eta,weight);
	  hist_2jets_dl_big2_phi_firstjetak->Fill(jet1phi,weight);
	  hist_2jets_dl_big2_eta_secjetak->Fill(jet2eta,weight);
	  hist_2jets_dl_big2_phi_secjetak->Fill(jet2phi,weight);
	  hist_2jets_dl_big2_pt_firstjetak->Fill(jet1pt,weight);
	  hist_2jets_dl_big2_pt_secjetak->Fill(jet2pt,weight);
	  hist_2jets_dl_big2_etaphi_firstjetak->Fill(jet1eta,jet1phi,weight);
	  hist_2jets_dl_big2_etaphi_secjetak->Fill(jet2eta,jet2phi,weight);
	  hist_deltaeta_vs_deltaphi_big2ak->Fill(jet1eta-jet2eta,jet1phi-jet2phi,weight);
	  if((fabs(jet1eta - jet2eta) < 1.5 && fabs(jet1eta - jet2eta) > 0.5) && (fabs(jet1phi - jet2phi) < 0.06) ){
	    stat =  true;
	    hist_2jets_dl_smallreg_eta_firstjetak->Fill(jet1eta,weight);
	    hist_2jets_dl_smallreg_phi_firstjetak->Fill(jet1phi,weight);
	    hist_2jets_dl_smallreg_eta_secjetak->Fill(jet2eta,weight);
	    hist_2jets_dl_smallreg_phi_secjetak->Fill(jet2phi,weight);
	    hist_2jets_dl_smallreg_pt_firstjetak->Fill(jet1pt,weight);
	    hist_2jets_dl_smallreg_pt_secjetak->Fill(jet2pt,weight);
	    hist_deltaeta_vs_deltaphi_smallregak->Fill(jet1eta-jet2eta,jet1phi-jet2phi,weight);
	  }
	  if( (fabs(jet1eta - jet2eta) > 1.5 || fabs(jet1eta - jet2eta) < 0.5) && fabs(jet1phi - jet2phi) > 0.06){
	    hist_2jets_dl_antismallreg_eta_firstjetak->Fill(jet1eta,weight);
	    hist_2jets_dl_antismallreg_phi_firstjetak->Fill(jet1phi,weight);
	    hist_2jets_dl_antismallreg_eta_secjetak->Fill(jet2eta,weight);
	    hist_2jets_dl_antismallreg_phi_secjetak->Fill(jet2phi,weight);
	    hist_2jets_dl_antismallreg_pt_firstjetak->Fill(jet1pt,weight);
	    hist_2jets_dl_antismallreg_pt_secjetak->Fill(jet2pt,weight);
	    hist_deltaeta_vs_deltaphi_antismallregak->Fill(jet1eta-jet2eta,jet1phi-jet2phi,weight);
	  }
	}
	if(!stat){
	  hist_alphatdis_twojets_DLak->Fill(alphatvecak[0],weight);
	  hist_deltaeta_vs_deltaphi_finalak->Fill(jet1eta-jet2eta,jet1phi-jet2phi,weight);
	}
	if( alphatvecak[0] > Alphat_Cut)
	  hist_alphat_2j_DLCutsak->Fill(1,weight);
      }
      //      cout << "number of sel jetsak " << sel_jetak.size() << endl;
      if(sel_jetak.size() > 2){
	//	cout << " alphatvecak[0] " << alphatvecak[0] << endl; 
	//	cout << " alphatvecak[2] " << alphatvecak[2] << endl; 
	hist_alphat_njets_minimum_deltaht_DLak->Fill(alphatvecak[0],weight);
	hist_alphat_njets_as_reclustered_DLak->Fill(alphatvecak[2],weight);
	if( alphatvecak[0] > Alphat_Cut)
	  hist_alphat_nj_DLCutsak->Fill(1,weight);
	if( alphatvecak[2] > Alphat_Cut)
	  hist_alphat_nj_re_DLCutsak->Fill(1,weight);
      }
      if( alphatvecak[0] > Alphat_Cut)
	hist_alphat_DLCutsak->Fill(1,weight);
      if( alphatvecak[2] > Alphat_Cut)
	hist_alphat_re_DLCutsak->Fill(1,weight);

    }
    //    cout << "double lepton lepton cycle" << endl;    
    if(MET > Met_Cut && htvec[0] > HT_high_Cut && htvec[1] > MHT_Cut){
      if(sel_jet.size()==2){
	float jet1pt = 0, jet2pt = 0, jet1eta = 0, jet2eta = 0, jet1phi = 0 ,jet2phi = 0;
	bool stat = false;
	for(unsigned int i = 0; i<NJET; i++ ){
	  if(JET_PT[i] < Jet_Pt_Cut)
	    continue;
	  if(fabs(JET_ETA[i]) > Jet_Eta_Cut)
	    continue;
	  if(JET_PT[i] > jet1pt){
	    jet1pt = JET_PT[i];
	    jet1phi = JET_PHI[i];
	    jet1eta = JET_ETA[i];
	  }
	  else if(JET_PT[i] > jet2pt && JET_PT[i] < jet1pt){
	    jet2pt = JET_PT[i];
	    jet2phi = JET_PHI[i];
	    jet2eta = JET_ETA[i];
	  }
	}
	if(alphatvec[0] > 2){
	  hist_2jets_dl_big2_eta_firstjet->Fill(jet1eta,weight);
	  hist_2jets_dl_big2_phi_firstjet->Fill(jet1phi,weight);
	  hist_2jets_dl_big2_eta_secjet->Fill(jet2eta,weight);
	  hist_2jets_dl_big2_phi_secjet->Fill(jet2phi,weight);
	  hist_2jets_dl_big2_pt_firstjet->Fill(jet1pt,weight);
	  hist_2jets_dl_big2_pt_secjet->Fill(jet2pt,weight);
	  hist_2jets_dl_big2_etaphi_firstjet->Fill(jet1phi,jet1eta,weight);
	  hist_2jets_dl_big2_etaphi_secjet->Fill(jet2phi,jet2eta,weight);
	  hist_deltaeta_vs_deltaphi_big2->Fill(jet1phi-jet2phi,jet1eta-jet2eta,weight);
	  if((fabs(jet1eta - jet2eta) < 1.5 && fabs(jet1eta - jet2eta) > 0.5) && (fabs(jet1phi - jet2phi) < 0.06) ){
	    stat =  true;
	    hist_2jets_dl_smallreg_eta_firstjet->Fill(jet1eta,weight);
	    hist_2jets_dl_smallreg_phi_firstjet->Fill(jet1phi,weight);
	    hist_2jets_dl_smallreg_eta_secjet->Fill(jet2eta,weight);
	    hist_2jets_dl_smallreg_phi_secjet->Fill(jet2phi,weight);
	    hist_2jets_dl_smallreg_pt_firstjet->Fill(jet1pt,weight);
	    hist_2jets_dl_smallreg_pt_secjet->Fill(jet2pt,weight);
	    hist_deltaeta_vs_deltaphi_smallreg->Fill(jet1phi-jet2phi,jet1eta-jet2eta,weight);
	  }
	  if( (fabs(jet1eta - jet2eta) > 1.5 || fabs(jet1eta - jet2eta) < 0.5) && fabs(jet1phi - jet2phi) > 0.06){
	    hist_2jets_dl_antismallreg_eta_firstjet->Fill(jet1eta,weight);
	    hist_2jets_dl_antismallreg_phi_firstjet->Fill(jet1phi,weight);
	    hist_2jets_dl_antismallreg_eta_secjet->Fill(jet2eta,weight);
	    hist_2jets_dl_antismallreg_phi_secjet->Fill(jet2phi,weight);
	    hist_2jets_dl_antismallreg_pt_firstjet->Fill(jet1pt,weight);
	    hist_2jets_dl_antismallreg_pt_secjet->Fill(jet2pt,weight);
	    hist_deltaeta_vs_deltaphi_antismallreg->Fill(jet1phi-jet2phi,jet1eta-jet2eta,weight);
	  }
	}
	if(!stat){
	  hist_alphatdis_twojets_DL->Fill(alphatvec[0],weight);
	  hist_deltaeta_vs_deltaphi_final->Fill(jet1phi-jet2phi,jet1eta-jet2eta,weight);
	}
	if( alphatvec[0] > Alphat_Cut)
	  hist_alphat_2j_DLCuts->Fill(1,weight);
      }
      if(sel_jet.size() > 2){
	hist_alphat_njets_minimum_deltaht_DL->Fill(alphatvec[0],weight);
	hist_alphat_njets_as_reclustered_DL->Fill(alphatvec[2],weight);
	if( alphatvec[0] > Alphat_Cut)
	  hist_alphat_nj_DLCuts->Fill(1,weight);
	if( alphatvec[2] > Alphat_Cut)
	  hist_alphat_nj_re_DLCuts->Fill(1,weight);
      }
      if( alphatvec[0] > Alphat_Cut)
	hist_alphat_DLCuts->Fill(1,weight);
      if( alphatvec[2] > Alphat_Cut)
	hist_alphat_re_DLCuts->Fill(1,weight);
      ////////////////electron electron
      if(sel_el.size() == 2 && sel_mu.size() == 0 && sel_tau.size() == 0){
	if(El_Charge[sel_el[0]] + El_Charge[sel_el[1]] == 0)
	  hist_double_lep_opp_sign_ee->Fill(1,weight);
      }
      ///////////////////////electron muon
      if(sel_el.size() == 1 && sel_mu.size() == 1 && sel_tau.size() == 0){
	if(El_Charge[sel_el[0]] + Mu_Charge[sel_mu[0]] == 0)
	  hist_double_lep_opp_sign_emu->Fill(1,weight);
      }
      ///////////////////////electron tau
      if(sel_el.size() == 1 && sel_mu.size() == 0 && sel_tau.size() == 1){
	if(El_Charge[sel_el[0]] + Tau_Charge[sel_tau[0]] == 0)
	  hist_double_lep_opp_sign_etau->Fill(1,weight);
      }
      ////////////////muon muon
      if(sel_el.size() == 0 && sel_mu.size() == 2 && sel_tau.size() == 0){
	if(Mu_Charge[sel_mu[0]] + Mu_Charge[sel_mu[1]] == 0)
	  hist_double_lep_opp_sign_mumu->Fill(1,weight);
      }
      /////////////////////// muon tau
      if(sel_el.size() == 0 && sel_mu.size() == 1 && sel_tau.size() == 1){
	if(Mu_Charge[sel_mu[0]] + Tau_Charge[sel_tau[0]] == 0)
	  hist_double_lep_opp_sign_mutau->Fill(1,weight);
      }
      /////////////////////// tau tau
      if(sel_el.size() == 0 && sel_mu.size() == 0 && sel_tau.size() == 2){
	if(Tau_Charge[sel_tau[0]] + Tau_Charge[sel_tau[1]] == 0)
	  hist_double_lep_opp_sign_tautau->Fill(1,weight);
      }
    }
    
    //    cout << "double lepton ak cycle" << endl;
    if(PFMET > Met_Cut && pfhtvecak[0] > HT_high_Cut && pfhtvecak[1] > MHT_Cut){
      if(sel_pfjetak.size()==2){
	hist_alphatdis_twoPFjets_DLak->Fill(pfalphatvecak[0],weight);
	if( pfalphatvecak[0] > Alphat_Cut)
	  hist_alphat_2j_PFDLCutsak->Fill(1,weight);
      }
      if(sel_pfjetak.size() > 2){
	hist_alphat_nPFjets_minimum_deltaht_DLak->Fill(pfalphatvecak[0],weight);
       	hist_alphat_nPFjets_as_reclustered_DLak->Fill(pfalphatvecak[2],weight);
	if( pfalphatvecak[0] > Alphat_Cut)
	  hist_alphat_nj_PFDLCutsak->Fill(1,weight);
	if( pfalphatvecak[2] > Alphat_Cut)
	  hist_alphat_nj_re_PFDLCutsak->Fill(1,weight);
      }
      if( pfalphatvecak[0] > Alphat_Cut)
	hist_alphat_PFDLCutsak->Fill(1,weight);
      if( pfalphatvecak[2] > Alphat_Cut)
	hist_alphat_re_PFDLCutsak->Fill(1,weight);

    }
    //    cout << "double lepton cycle" << endl;
    if(PFMET > Met_Cut && pfhtvec[0] > HT_high_Cut && pfhtvec[1] > MHT_Cut){
      if(sel_pfjet.size()==2){
	hist_alphatdis_twoPFjets_DL->Fill(pfalphatvec[0],weight);
	if( pfalphatvec[0] > Alphat_Cut)
	  hist_alphat_2j_PFDLCuts->Fill(1,weight);
      }
      if(sel_pfjet.size() > 2){
	hist_alphat_nPFjets_minimum_deltaht_DL->Fill(pfalphatvec[0],weight);
       	hist_alphat_nPFjets_as_reclustered_DL->Fill(pfalphatvec[2],weight);
	if( pfalphatvec[0] > Alphat_Cut)
	  hist_alphat_nj_PFDLCuts->Fill(1,weight);
	if( pfalphatvec[2] > Alphat_Cut)
	  hist_alphat_nj_re_PFDLCuts->Fill(1,weight);
      }
      if( pfalphatvec[0] > Alphat_Cut)
	hist_alphat_PFDLCuts->Fill(1,weight);
      if( pfalphatvec[2] > Alphat_Cut)
	hist_alphat_re_PFDLCuts->Fill(1,weight);
      ////////////////electron electron
      if(sel_pfel.size() == 2 && sel_pfmu.size() == 0 && sel_pftau.size() == 0){
	if(PFEl_Charge[sel_pfel[0]] + PFEl_Charge[sel_pfel[1]] == 0)
	  hist_double_lep_opp_sign_PFee->Fill(1,weight);
      }
      ///////////////////////electron muon
      if(sel_pfel.size() == 1 && sel_pfmu.size() == 1 && sel_pftau.size() == 0){
	if(PFEl_Charge[sel_pfel[0]] + PFMu_Charge[sel_pfmu[0]] == 0)
	  hist_double_lep_opp_sign_PFemu->Fill(1,weight);
      }
      ///////////////////////electron tau
      if(sel_pfel.size() == 1 && sel_pfmu.size() == 0 && sel_pftau.size() == 1){
	if(PFEl_Charge[sel_pfel[0]] + PFTau_Charge[sel_pftau[0]] == 0)
	  hist_double_lep_opp_sign_PFetau->Fill(1,weight);
      }
      ////////////////muon muon
      if(sel_pfel.size() == 0 && sel_pfmu.size() == 2 && sel_pftau.size() == 0){
	if(PFMu_Charge[sel_pfmu[0]] + PFMu_Charge[sel_pfmu[1]] == 0)
	  hist_double_lep_opp_sign_PFmumu->Fill(1,weight);
      }
      /////////////////////// muon tau
      if(sel_pfel.size() == 0 && sel_pfmu.size() == 1 && sel_pftau.size() == 1){
	if(PFMu_Charge[sel_pfmu[0]] + PFTau_Charge[sel_pftau[0]] == 0)
	  hist_double_lep_opp_sign_PFmutau->Fill(1,weight);
      }
      /////////////////////// tau tau
      if(sel_pfel.size() == 0 && sel_pfmu.size() == 0 && sel_pftau.size() == 2){
	if(PFTau_Charge[sel_pftau[0]] + PFTau_Charge[sel_pftau[1]] == 0)
	  hist_double_lep_opp_sign_PFtautau->Fill(1,weight);
      }
    }
    
    ///////////////////////////////////////
    /////////////////double lepton same sign
    ///////////////////////////////
    //    std::cout << " same sign prompts " << std::endl;

    if(sel_el.size() == 2 && sel_mu.size() == 0 && sel_tau.size() == 0)
      if(El_Charge[sel_el[0]]*El_Charge[sel_el[1]] == 1)
	hist_HT_vs_twolep->Fill( (double)htvec[0],0.,weight);
    if(sel_el.size() == 1 && sel_mu.size() == 1 && sel_tau.size() == 0)
      if(El_Charge[sel_el[0]]*Mu_Charge[sel_mu[0]] == 1)
	hist_HT_vs_twolep->Fill( (double)htvec[0],1.,weight);
    if(sel_el.size() == 1 && sel_mu.size() == 0 && sel_tau.size() == 1)
      if(El_Charge[sel_el[0]]*Tau_Charge[sel_tau[0]] == 1)
	hist_HT_vs_twolep->Fill((double)htvec[0],2.,weight);
    if(sel_el.size() == 0 && sel_mu.size() == 2 && sel_tau.size() == 0)
      if(Mu_Charge[sel_mu[0]]*Mu_Charge[sel_mu[1]] == 1)
	hist_HT_vs_twolep->Fill((double)htvec[0],3.,weight);
    if(sel_el.size() == 0 && sel_mu.size() == 1 && sel_tau.size() == 1)
      if(Mu_Charge[sel_mu[0]]*Tau_Charge[sel_tau[0]] == 1)
	hist_HT_vs_twolep->Fill((double)htvec[0],4.,weight);
    if(sel_el.size() == 0 && sel_mu.size() == 0 && sel_tau.size() == 2)
      if(Tau_Charge[sel_tau[0]]*Tau_Charge[sel_tau[1]] == 1)
	hist_HT_vs_twolep->Fill((double)htvec[0],5.,weight);

    hist_HT_vs_MET->Fill((double)htvec[0],MET,weight);
    hist_HT_vs_nlep->Fill((double)htvec[0],(double)(sel_el.size()+sel_mu.size()+sel_tau.size()),weight);

    if(MET > Met_Cut && htvec[0] > HT_high_Cut){ //&& htvec[1] > MHT_Cut){
      /////////inclusive signals
      if(all_lep.size() > 2){      
	double ptmax=0,pt2=0,pt3=0;
	int max=0,sec=0,thir=0;
	bool zveto = false;
	for(unsigned int con=0;con < all_lep.size(); con++){
	  if(all_lep[con][0] > ptmax){
	    ptmax = all_lep[con][0]; 
	    max = con;
	  }
	  else if(all_lep[con][0] > pt2 && all_lep[con][0] <= ptmax){
	    pt2 = all_lep[con][0];
	    sec = con;
	  }
	  else if(all_lep[con][0] > pt3 && all_lep[con][0] <= pt2){
	    pt3 = all_lep[con][0];
	    thir = con;
	  }
	}
	double mass = invmass(all_lep[max][5],all_lep[max][6],all_lep[max][7],all_lep[max][8],all_lep[thir][5],all_lep[thir][6],all_lep[thir][7],all_lep[thir][8]);
	if(all_lep[max][3]*all_lep[thir][3] == -1 && (mass > 76 && mass < 106) && all_lep[thir][4] == all_lep[max][4])
	  zveto = true;

	mass = invmass(all_lep[max][5],all_lep[max][6],all_lep[max][7],all_lep[max][8],all_lep[sec][5],all_lep[sec][6],all_lep[sec][7],all_lep[sec][8]); 
	if(all_lep[max][3]*all_lep[sec][3] == -1 && (mass > 76 && mass < 106) && all_lep[sec][4] == all_lep[max][4])
	  zveto = true;

	mass = invmass(all_lep[thir][5],all_lep[thir][6],all_lep[thir][7],all_lep[thir][8],all_lep[sec][5],all_lep[sec][6],all_lep[sec][7],all_lep[sec][8]); 
	if(all_lep[thir][3]*all_lep[sec][3] == -1 && (mass > 76 && mass < 106) && all_lep[thir][4] == all_lep[sec][4])
	  zveto = true;

	if(!zveto){
	  /////////electron electron
	  if( ((all_lep[max][4] == 1 && all_lep[sec][4] == 1) && all_lep[max][3]*all_lep[sec][3] == 1)) 
	    hist_double_lep_same_sign_ee_inc->Fill(1,weight);
	  
	  /////////electron muon
	  if( ((all_lep[max][4] == 1 && all_lep[sec][4] == 2) && all_lep[max][3]*all_lep[sec][3] == 1) || ((all_lep[max][4] == 2 && all_lep[sec][4] == 1) && all_lep[max][3]*all_lep[sec][3] == 1) )
	    hist_double_lep_same_sign_emu_inc->Fill(1,weight);
	  
	  /////////electron tau
	  if( ((all_lep[max][4] == 1 && all_lep[sec][4] == 3) && all_lep[max][3]*all_lep[sec][3] == 1) || ((all_lep[max][4] == 3 && all_lep[sec][4] == 1) && all_lep[max][3]*all_lep[sec][3] == 1))
	    hist_double_lep_same_sign_etau_inc->Fill(1,weight);
	  
	  ////////muon muon
	  if( ((all_lep[max][4] == 2 && all_lep[sec][4] == 2) && all_lep[max][3]*all_lep[sec][3] == 1))
	    hist_double_lep_same_sign_mumu_inc->Fill(1,weight);
	  
	  /////////muon tau
	  if( ((all_lep[max][4] == 2 && all_lep[sec][4] == 3) && all_lep[max][3]*all_lep[sec][3] == 1) || ((all_lep[max][4] == 3 && all_lep[sec][4] == 2) && all_lep[max][3]*all_lep[sec][3] == 1))
	    hist_double_lep_same_sign_mutau_inc->Fill(1,weight);
	  
	  ////////tau tau
	  if( ((all_lep[max][4] == 3 && all_lep[sec][4] == 3) && all_lep[max][3]*all_lep[sec][3] == 1))
	    hist_double_lep_same_sign_tautau_inc->Fill(1,weight);
	  
	}
      }

      ////////exclusive
      ////////////////electron electron
      if(sel_el.size() == 2 && sel_mu.size() == 0 && sel_tau.size() == 0)
	if(El_Charge[sel_el[0]]*El_Charge[sel_el[1]] == 1){
	  hist_double_lep_same_sign_ee->Fill(1,weight);
	  hist_double_lep_same_sign_ee_inc->Fill(1,weight);
	}
      ///////////////////////electron muon
      if(sel_el.size() == 1 && sel_mu.size() == 1 && sel_tau.size() == 0)
	if(El_Charge[sel_el[0]]*Mu_Charge[sel_mu[0]] == 1){
	  hist_double_lep_same_sign_emu->Fill(1,weight);
	  hist_double_lep_same_sign_emu_inc->Fill(1,weight);
	}
      ///////////////////////electron tau
      if(sel_el.size() == 1 && sel_mu.size() == 0 && sel_tau.size() == 1)
	if(El_Charge[sel_el[0]]*Tau_Charge[sel_tau[0]] == 1){
	  hist_double_lep_same_sign_etau->Fill(1,weight);
	  hist_double_lep_same_sign_etau_inc->Fill(1,weight);
	}
      ////////////////muon muon
      if(sel_el.size() == 0 && sel_mu.size() == 2 && sel_tau.size() == 0)
	if(Mu_Charge[sel_mu[0]]*Mu_Charge[sel_mu[1]] == 1){
	  hist_double_lep_same_sign_mumu->Fill(1,weight);
	  hist_double_lep_same_sign_mumu_inc->Fill(1,weight);
	}
      /////////////////////// muon tau
      if(sel_el.size() == 0 && sel_mu.size() == 1 && sel_tau.size() == 1)
	if(Mu_Charge[sel_mu[0]]*Tau_Charge[sel_tau[0]] == 1){
	  hist_double_lep_same_sign_mutau->Fill(1,weight);
	  hist_double_lep_same_sign_mutau_inc->Fill(1,weight);
	}
      /////////////////////// tau tau
      if(sel_el.size() == 0 && sel_mu.size() == 0 && sel_tau.size() == 2)
	if(Tau_Charge[sel_tau[0]]*Tau_Charge[sel_tau[1]] == 1){
	  hist_double_lep_same_sign_tautau->Fill(1,weight);
	  hist_double_lep_same_sign_tautau_inc->Fill(1,weight);
	}
      //      std::cout << " same sign 2 fakes " << std::endl;

      /////////// background estimation 2 fakes
      ////////////////electron electron
      if(sell_el.size() == 2 && sel_el.size() == 0 && sel_mu.size() == 0 && sel_tau.size() == 0)
	if(El_Charge[sell_el[0]]*El_Charge[sell_el[1]] == 1){
	  hist_double_lep_same_sign_ee_back_2l->Fill(1,weight*LTprob(1,0,El_PT[sell_el[0]],El_ETA[sell_el[0]])*LTprob(1,0,El_PT[sell_el[1]],El_ETA[sell_el[1]]));
	}
      ///////////////////////electron muon
      if(sell_el.size() == 1 && sel_el.size() == 0 && sell_mu.size() == 1 && sel_mu.size() == 0 && sel_tau.size() == 0)
	if(El_Charge[sell_el[0]]*Mu_Charge[sell_mu[0]] == 1){
	  hist_double_lep_same_sign_emu_back_2l->Fill(1,weight*LTprob(1,0,El_PT[sell_el[0]],El_ETA[sell_el[0]])*LTprob(2,0,Mu_PT[sell_mu[0]],Mu_ETA[sell_mu[0]]));
	}
      ///////////////////////electron tau
      if(sell_el.size() == 1 && sel_el.size() == 0 && sel_mu.size() == 0 && sell_tau.size() == 1 && sel_tau.size() == 0)
	if(El_Charge[sell_el[0]]*Tau_Charge[sell_tau[0]] == 1){
	  hist_double_lep_same_sign_etau_back_2l->Fill(1,weight*LTprob(1,0,El_PT[sell_el[0]],El_ETA[sell_el[0]])*LTprob(3,0,Tau_PT[sell_tau[0]],Mu_ETA[sell_tau[0]]));
	}
      ////////////////muon muon
      if(sel_el.size() == 0 && sell_mu.size() == 2 && sel_mu.size() == 0 && sel_tau.size() == 0)
	if(Mu_Charge[sell_mu[0]]*Mu_Charge[sell_mu[1]] == 1){
	  hist_double_lep_same_sign_mumu_back_2l->Fill(1,weight*LTprob(2,0,Mu_PT[sell_mu[0]],Mu_ETA[sell_mu[0]])*LTprob(2,0,Mu_PT[sell_mu[1]],Mu_ETA[sell_mu[1]]));
	}
      /////////////////////// muon tau
      if(sel_el.size() == 0 && sell_mu.size() == 1 && sel_mu.size() == 0 && sell_tau.size() == 1 && sel_tau.size() == 0)
	if(Mu_Charge[sell_mu[0]]*Tau_Charge[sell_tau[0]] == 1){
	  hist_double_lep_same_sign_mutau_back_2l->Fill(1,weight*LTprob(2,0,Mu_PT[sell_mu[0]],Mu_ETA[sell_mu[0]])*LTprob(3,0,Tau_PT[sell_tau[0]],Tau_ETA[sell_tau[0]]));
	}
      /////////////////////// tau tau
      if(sel_el.size() == 0 && sel_mu.size() == 0 && sell_tau.size() == 2 && sel_tau.size() == 0)
	if(Tau_Charge[sell_tau[0]]*Tau_Charge[sell_tau[1]] == 1){
	  hist_double_lep_same_sign_tautau_back_2l->Fill(1,weight*LTprob(2,0,Tau_PT[sell_tau[0]],Tau_ETA[sell_tau[0]])*LTprob(3,0,Tau_PT[sell_tau[1]],Tau_ETA[sell_tau[1]]));
	}
      //      std::cout << " same sign 1 fake " << std::endl;
      /////////// background estimation 1 fake
      ////////////////electron electron
      if(sell_el.size() == 1 && sel_el.size() == 1 && sel_mu.size() == 0 && sel_tau.size() == 0 )
	if(El_Charge[sel_el[0]]*El_Charge[sell_el[0]] == 1){
	  hist_double_lep_same_sign_ee_back_1l->Fill(1,weight*LTprob(1,0,El_PT[sel_el[0]],El_ETA[sel_el[0]])*LTprob(1,0,El_PT[sell_el[0]],El_ETA[sell_el[0]]));
	}
      ///////////////////////electron muon
      if(sel_el.size() == 1 && sell_mu.size() == 1 && sel_tau.size() == 0)
	if(El_Charge[sel_el[0]]*Mu_Charge[sell_mu[0]] == 1){
	  hist_double_lep_same_sign_emu_back_1l->Fill(1,weight*LTprob(1,0,El_PT[sel_el[0]],El_ETA[sel_el[0]])*LTprob(2,0,Mu_PT[sell_mu[0]],Mu_ETA[sell_mu[0]]));
	}
      if(sell_el.size() == 1 && sel_mu.size() == 1 && sel_tau.size() == 0)
	if(El_Charge[sell_el[0]]*Mu_Charge[sel_mu[0]] == 1){
	  hist_double_lep_same_sign_emu_back_1l->Fill(1,weight*LTprob(1,0,El_PT[sell_el[0]],El_ETA[sell_el[0]])*LTprob(2,0,Mu_PT[sel_mu[0]],Mu_ETA[sel_mu[0]]));
	}
      ///////////////////////electron tau
      if(sel_el.size() == 1 && sel_mu.size() == 0 && sell_tau.size() == 1)
	if(El_Charge[sel_el[0]]*Tau_Charge[sell_tau[0]] == 1){
	  hist_double_lep_same_sign_etau_back_1l->Fill(1,weight*LTprob(1,0,El_PT[sel_el[0]],El_ETA[sel_el[0]])*LTprob(3,0,Tau_PT[sell_tau[1]],Mu_ETA[sell_tau[1]]));
	}
      if(sell_el.size() == 1 && sel_mu.size() == 0 && sel_tau.size() == 1)
	if(El_Charge[sell_el[0]]*Tau_Charge[sel_tau[0]] == 1){
	  hist_double_lep_same_sign_etau_back_1l->Fill(1,weight*LTprob(1,0,El_PT[sell_el[0]],El_ETA[sell_el[0]])*LTprob(3,0,Tau_PT[sel_tau[1]],Mu_ETA[sel_tau[1]]));
	}
      ////////////////muon muon
      if(sel_el.size() == 0 && sell_mu.size() == 1 && sel_mu.size() == 1 && sel_tau.size() == 0)
	if(Mu_Charge[sel_mu[0]]*Mu_Charge[sell_mu[0]] == 1){
	  hist_double_lep_same_sign_mumu_back_1l->Fill(1,weight*LTprob(2,0,Mu_PT[sel_mu[0]],Mu_ETA[sel_mu[0]])*LTprob(2,0,Mu_PT[sell_mu[0]],Mu_ETA[sell_mu[0]]));
	}
      /////////////////////// muon tau
      if(sel_el.size() == 0 && sel_mu.size() == 1 && sell_tau.size() == 1)
	if(Mu_Charge[sel_mu[0]]*Tau_Charge[sell_tau[0]] == 1){
	  hist_double_lep_same_sign_mutau_back_1l->Fill(1,weight*LTprob(2,0,Mu_PT[sel_mu[0]],Mu_ETA[sel_mu[0]])*LTprob(3,0,Tau_PT[sell_tau[0]],Tau_ETA[sell_tau[0]]));
	}
      if(sel_el.size() == 0 && sell_mu.size() == 1 && sel_tau.size() == 1)
	if(Mu_Charge[sell_mu[0]]*Tau_Charge[sel_tau[0]] == 1){
	  hist_double_lep_same_sign_mutau_back_1l->Fill(1,weight*LTprob(2,0,Mu_PT[sell_mu[0]],Mu_ETA[sell_mu[0]])*LTprob(3,0,Tau_PT[sel_tau[0]],Tau_ETA[sel_tau[0]]));
	}
      /////////////////////// tau tau
      if(sel_el.size() == 0 && sel_mu.size() == 0 && sel_tau.size() == 1 && sell_tau.size() == 1)
	if(Tau_Charge[sel_tau[0]]*Tau_Charge[sell_tau[0]] == 1){
	  hist_double_lep_same_sign_tautau_back_1l->Fill(1,weight*LTprob(2,0,Tau_PT[sel_tau[0]],Tau_ETA[sel_tau[0]])*LTprob(3,0,Tau_PT[sell_tau[0]],Tau_ETA[sell_tau[0]]));
	}
    }

    //    std::cout << "pf same sign prompts " << std::endl;
    if(sel_pfel.size() == 2 && sel_pfmu.size() == 0 && sel_pftau.size() == 0)
      if(PFEl_Charge[sel_pfel[0]]*PFEl_Charge[sel_pfel[1]] == 1)
	hist_PFHT_vs_twolep->Fill( (double)pfhtvec[0],0.,weight);
    if(sel_pfel.size() == 1 && sel_pfmu.size() == 1 && sel_pftau.size() == 0)
      if(PFEl_Charge[sel_pfel[0]]*PFMu_Charge[sel_pfmu[0]] == 1)
	hist_PFHT_vs_twolep->Fill( (double)pfhtvec[0],1.,weight);
    if(sel_pfel.size() == 1 && sel_pfmu.size() == 0 && sel_pftau.size() == 1)
      if(PFEl_Charge[sel_pfel[0]]*PFTau_Charge[sel_pftau[0]] == 1)
	hist_PFHT_vs_twolep->Fill((double)pfhtvec[0],2.,weight);
    if(sel_pfel.size() == 0 && sel_pfmu.size() == 2 && sel_pftau.size() == 0)
      if(PFMu_Charge[sel_pfmu[0]]*PFMu_Charge[sel_pfmu[1]] == 1)
	hist_PFHT_vs_twolep->Fill((double)pfhtvec[0],3.,weight);
    if(sel_pfel.size() == 0 && sel_pfmu.size() == 1 && sel_pftau.size() == 1)
      if(PFMu_Charge[sel_pfmu[0]]*PFTau_Charge[sel_pftau[0]] == 1)
	hist_PFHT_vs_twolep->Fill((double)pfhtvec[0],4.,weight);
    if(sel_pfel.size() == 0 && sel_pfmu.size() == 0 && sel_pftau.size() == 2)
      if(PFTau_Charge[sel_pftau[0]]*PFTau_Charge[sel_pftau[1]] == 1)
	hist_PFHT_vs_twolep->Fill((double)pfhtvec[0],5.,weight);

    hist_PFHT_vs_MET->Fill((double)pfhtvec[0],PFMET,weight);
    hist_PFHT_vs_nlep->Fill((double)pfhtvec[0],(double)(sel_pfel.size()+sel_pfmu.size()+sel_pftau.size()),weight);

    if(PFMET > Met_Cut && pfhtvec[0] > HT_high_Cut){ //&& pfhtvec[1] > MHT_Cut){
      if(all_pflep.size() > 2){      
	double ptmax=0,pt2=0,pt3=0;
	int max=0,sec=0,thir=0;
	bool zveto = false;
	for(unsigned int con=0;con < all_pflep.size(); con++){
	  if(all_pflep[con][0] > ptmax){
	    ptmax = all_pflep[con][0]; 
	    max = con;
	  }
	  else if(all_pflep[con][0] > pt2 && all_pflep[con][0] <= ptmax){
	    pt2 = all_pflep[con][0];
	    sec = con;
	  }
	  else if(all_pflep[con][0] > pt3 && all_pflep[con][0] <= pt2){
	    pt3 = all_pflep[con][0];
	    thir = con;
	  }
	}
	double mass = invmass(all_pflep[max][5],all_pflep[max][6],all_pflep[max][7],all_pflep[max][8],all_pflep[thir][5],all_pflep[thir][6],all_pflep[thir][7],all_pflep[thir][8]);
	if(all_pflep[max][3]*all_pflep[thir][3] == -1 && (mass > 76 && mass < 106) && all_pflep[thir][4] == all_pflep[max][4])
	  zveto = true;

	mass = invmass(all_pflep[max][5],all_pflep[max][6],all_pflep[max][7],all_pflep[max][8],all_pflep[sec][5],all_pflep[sec][6],all_pflep[sec][7],all_pflep[sec][8]); 
	if(all_pflep[max][3]*all_pflep[sec][3] == -1 && (mass > 76 && mass < 106) && all_pflep[sec][4] == all_pflep[max][4])
	  zveto = true;

	mass = invmass(all_pflep[thir][5],all_pflep[thir][6],all_pflep[thir][7],all_pflep[thir][8],all_pflep[sec][5],all_pflep[sec][6],all_pflep[sec][7],all_pflep[sec][8]); 
	if(all_pflep[thir][3]*all_pflep[sec][3] == -1 && (mass > 76 && mass < 106) && all_pflep[thir][4] == all_pflep[sec][4])
	  zveto = true;

	if(!zveto){
	  /////////electron electron
	  if( ((all_pflep[max][4] == 1 && all_pflep[sec][4] == 1) && all_pflep[max][3]*all_pflep[sec][3] == 1)) 
	    hist_double_lep_same_sign_PFee_inc->Fill(1,weight);
	  
	  /////////electron muon
	  if( ((all_pflep[max][4] == 1 && all_pflep[sec][4] == 2) && all_pflep[max][3]*all_pflep[sec][3] == 1) || ((all_pflep[max][4] == 2 && all_pflep[sec][4] == 1) && all_pflep[max][3]*all_pflep[sec][3] == 1))
	    hist_double_lep_same_sign_PFemu_inc->Fill(1,weight);
	  
	  /////////electron tau
	  if( ((all_pflep[max][4] == 1 && all_pflep[sec][4] == 3) && all_pflep[max][3]*all_pflep[sec][3] == 1) || ((all_pflep[max][4] == 3 && all_pflep[sec][4] == 1) && all_pflep[max][3]*all_pflep[sec][3] == 1))
	    hist_double_lep_same_sign_PFetau_inc->Fill(1,weight);
	  
	  ////////muon muon
	  if( ((all_pflep[max][4] == 2 && all_pflep[sec][4] == 2) && all_pflep[max][3]*all_pflep[sec][3] == 1)) 
	    hist_double_lep_same_sign_PFmumu_inc->Fill(1,weight);
	  
	  /////////muon tau
	  if( ((all_pflep[max][4] == 2 && all_pflep[sec][4] == 3) && all_pflep[max][3]*all_pflep[sec][3] == 1) || ((all_pflep[max][4] == 3 && all_pflep[sec][4] == 2) && all_pflep[max][3]*all_pflep[sec][3] == 1))
	    hist_double_lep_same_sign_PFmutau_inc->Fill(1,weight);
	  
	  ////////tau tau
	  if( ((all_pflep[max][4] == 3 && all_pflep[sec][4] == 3) && all_pflep[max][3]*all_pflep[sec][3] == 1))
	    hist_double_lep_same_sign_PFtautau_inc->Fill(1,weight);
  
	}
      }

      ////////exclusive
      ////////////////electron electron
      if(sel_pfel.size() == 2 && sel_pfmu.size() == 0 && sel_pftau.size() == 0)
	if(PFEl_Charge[sel_pfel[0]]*PFEl_Charge[sel_pfel[1]] == 1){
	  hist_double_lep_same_sign_PFee->Fill(1,weight);
	  hist_double_lep_same_sign_PFee_inc->Fill(1,weight);
	}
      ///////////////////////electron muon
      if(sel_pfel.size() == 1 && sel_pfmu.size() == 1 && sel_pftau.size() == 0)
	if(PFEl_Charge[sel_pfel[0]]*PFMu_Charge[sel_pfmu[0]] == 1){
	  hist_double_lep_same_sign_PFemu->Fill(1,weight);
	  hist_double_lep_same_sign_PFemu_inc->Fill(1,weight);
	}
      ///////////////////////electron tau
      if(sel_pfel.size() == 1 && sel_pfmu.size() == 0 && sel_pftau.size() == 1)
	if(PFEl_Charge[sel_pfel[0]]*PFTau_Charge[sel_pftau[0]] == 1){
	  hist_double_lep_same_sign_PFetau->Fill(1,weight);
	  hist_double_lep_same_sign_PFetau_inc->Fill(1,weight);
	}
      ////////////////muon muon
      if(sel_pfel.size() == 0 && sel_pfmu.size() == 2 && sel_pftau.size() == 0)
	if(PFMu_Charge[sel_pfmu[0]]*PFMu_Charge[sel_pfmu[1]] == 1){
	  hist_double_lep_same_sign_PFmumu->Fill(1,weight);
	  hist_double_lep_same_sign_PFmumu_inc->Fill(1,weight);
	}
      /////////////////////// muon tau
      if(sel_pfel.size() == 0 && sel_pfmu.size() == 1 && sel_pftau.size() == 1)
	if(PFMu_Charge[sel_pfmu[0]]*PFTau_Charge[sel_pftau[0]] == 1){
	  hist_double_lep_same_sign_PFmutau->Fill(1,weight);
	  hist_double_lep_same_sign_PFmutau_inc->Fill(1,weight);
	}
      /////////////////////// tau tau
      if(sel_pfel.size() == 0 && sel_pfmu.size() == 0 && sel_pftau.size() == 2)
	if(PFTau_Charge[sel_pftau[0]]*PFTau_Charge[sel_pftau[1]] == 1){
	  hist_double_lep_same_sign_PFtautau->Fill(1,weight);
	  hist_double_lep_same_sign_PFtautau_inc->Fill(1,weight);
	}

      /////////// background estimation 2 fakes
      ////////////////electron electron
      if(sell_pfel.size() == 2 && sel_pfel.size() == 0 && sel_pfmu.size() == 0 && sel_pftau.size() == 0){
	if(PFEl_Charge[sell_pfel[0]]*PFEl_Charge[sell_pfel[1]] == 1)
	  hist_double_lep_same_sign_PFee_back_2l->Fill(1,weight*LTprob(1,1,PFEl_PT[sell_pfel[0]],PFEl_ETA[sell_pfel[0]])*LTprob(1,1,PFEl_PT[sell_pfel[1]],PFEl_ETA[sell_pfel[1]]));
      }
      ///////////////////////electron muon
      if(sell_pfel.size() == 1 && sel_pfel.size() == 0 && sell_pfmu.size() == 1 && sel_pfmu.size()== 0 && sel_pftau.size() == 0){
	if(PFEl_Charge[sell_pfel[0]]*PFMu_Charge[sell_pfmu[0]] == 1)
	  hist_double_lep_same_sign_PFemu_back_2l->Fill(1,weight*LTprob(1,1,PFEl_PT[sell_pfel[0]],PFEl_ETA[sell_pfel[0]])*LTprob(2,1,PFMu_PT[sell_pfmu[0]],PFMu_ETA[sell_pfmu[0]]));
      }
      ///////////////////////electron tau
      if(sell_pfel.size() == 1 && sel_pfel.size() == 0 && sel_pfmu.size() == 0 && sell_pftau.size() == 1 && sel_pftau.size() == 0){
	if(PFEl_Charge[sell_pfel[0]]*PFTau_Charge[sell_pftau[0]] == 1)
	  hist_double_lep_same_sign_PFetau_back_2l->Fill(1,weight*LTprob(1,1,PFEl_PT[sell_pfel[0]],PFEl_ETA[sell_pfel[0]])*LTprob(3,1,PFTau_PT[sell_pftau[0]],PFMu_ETA[sell_pftau[0]]));
      }
      ////////////////muon muon
      if(sel_pfel.size() == 0 && sell_pfmu.size() == 2 && sel_pfmu.size()== 0 && sel_pftau.size() == 0){
	if(PFMu_Charge[sell_pfmu[0]]*PFMu_Charge[sell_pfmu[1]] == 1)
	  hist_double_lep_same_sign_PFmumu_back_2l->Fill(1,weight*LTprob(2,1,PFMu_PT[sell_pfmu[0]],PFMu_ETA[sell_pfmu[0]])*LTprob(2,1,PFMu_PT[sell_pfmu[1]],PFMu_ETA[sell_pfmu[1]]));
      }
      /////////////////////// muon tau
      if(sel_pfel.size() == 0 && sell_pfmu.size() == 1 && sel_pfmu.size() == 0 && sell_pftau.size() == 1 && sel_pftau.size()== 0){
	if(PFMu_Charge[sell_pfmu[0]]*PFTau_Charge[sell_pftau[0]] == 1)
	  hist_double_lep_same_sign_PFmutau_back_2l->Fill(1,weight*LTprob(2,1,PFMu_PT[sell_pfmu[0]],PFMu_ETA[sell_pfmu[0]])*LTprob(3,1,PFTau_PT[sell_pftau[0]],PFTau_ETA[sell_pftau[0]]));
      }
      /////////////////////// tau tau
      if(sel_pfel.size() == 0 && sel_pfmu.size() == 0 && sell_pftau.size() == 2 && sel_pftau.size()== 0){
	if(PFTau_Charge[sell_pftau[0]]*PFTau_Charge[sell_pftau[1]] == 1)
	  hist_double_lep_same_sign_PFtautau_back_2l->Fill(1,weight*LTprob(2,1,PFTau_PT[sell_pftau[0]],PFTau_ETA[sell_pftau[0]])*LTprob(3,1,PFTau_PT[sell_pftau[1]],PFTau_ETA[sell_pftau[1]]));
      }

      /////////// background estimation 1 fake
      ////////////////electron electron
      if(sell_pfel.size() == 1 && sel_pfel.size() == 1 && sel_pfmu.size() == 0 && sel_pftau.size() == 0 )
	if(PFEl_Charge[sel_pfel[0]]*PFEl_Charge[sell_pfel[0]] == 1){
	  hist_double_lep_same_sign_PFee_back_1l->Fill(1,weight*LTprob(1,1,PFEl_PT[sel_pfel[0]],PFEl_ETA[sel_pfel[0]])*LTprob(1,1,PFEl_PT[sell_pfel[0]],PFEl_ETA[sell_pfel[0]]));
	}
      ///////////////////////electron muon
      if(sel_pfel.size() == 1 && sell_pfmu.size() == 1 && sel_pftau.size() == 0)
	if(PFEl_Charge[sel_pfel[0]]*PFMu_Charge[sell_pfmu[0]] == 1){
	  hist_double_lep_same_sign_PFemu_back_1l->Fill(1,weight*LTprob(1,1,PFEl_PT[sel_pfel[0]],PFEl_ETA[sel_pfel[0]])*LTprob(2,1,PFMu_PT[sell_pfmu[0]],PFMu_ETA[sell_pfmu[0]]));
	}
      if(sell_pfel.size() == 1 && sel_pfmu.size() == 1 && sel_pftau.size() == 0)
	if(PFEl_Charge[sell_pfel[0]]*PFMu_Charge[sel_pfmu[0]] == 1){
	  hist_double_lep_same_sign_PFemu_back_1l->Fill(1,weight*LTprob(1,1,PFEl_PT[sell_pfel[0]],PFEl_ETA[sell_pfel[0]])*LTprob(2,1,PFMu_PT[sel_pfmu[0]],PFMu_ETA[sel_pfmu[0]]));
	}
      ///////////////////////electron tau
      if(sel_pfel.size() == 1 && sel_pfmu.size() == 0 && sell_pftau.size() == 1)
	if(PFEl_Charge[sel_pfel[0]]*PFTau_Charge[sell_pftau[0]] == 1){
	  hist_double_lep_same_sign_PFetau_back_1l->Fill(1,weight*LTprob(1,1,PFEl_PT[sel_pfel[0]],PFEl_ETA[sel_pfel[0]])*LTprob(3,1,PFTau_PT[sell_pftau[1]],PFMu_ETA[sell_pftau[1]]));
	}
      if(sell_pfel.size() == 1 && sel_pfmu.size() == 0 && sel_pftau.size() == 1)
	if(PFEl_Charge[sell_pfel[0]]*PFTau_Charge[sel_pftau[0]] == 1){
	  hist_double_lep_same_sign_PFetau_back_1l->Fill(1,weight*LTprob(1,1,PFEl_PT[sell_pfel[0]],PFEl_ETA[sell_pfel[0]])*LTprob(3,1,PFTau_PT[sel_pftau[1]],PFMu_ETA[sel_pftau[1]]));
	}
      ////////////////muon muon
      if(sel_pfel.size() == 0 && sell_pfmu.size() == 1 && sel_pfmu.size() == 1 && sel_pftau.size() == 0)
	if(PFMu_Charge[sel_pfmu[0]]*PFMu_Charge[sell_pfmu[0]] == 1){
	  hist_double_lep_same_sign_PFmumu_back_1l->Fill(1,weight*LTprob(2,1,PFMu_PT[sel_pfmu[0]],PFMu_ETA[sel_pfmu[0]])*LTprob(2,1,PFMu_PT[sell_pfmu[0]],PFMu_ETA[sell_pfmu[0]]));
	}
      /////////////////////// muon tau
      if(sel_pfel.size() == 0 && sel_pfmu.size() == 1 && sell_pftau.size() == 1)
	if(PFMu_Charge[sel_pfmu[0]]*PFTau_Charge[sell_pftau[0]] == 1){
	  hist_double_lep_same_sign_PFmutau_back_1l->Fill(1,weight*LTprob(2,1,PFMu_PT[sel_pfmu[0]],PFMu_ETA[sel_pfmu[0]])*LTprob(3,1,PFTau_PT[sell_pftau[0]],PFTau_ETA[sell_pftau[0]]));
	}
      if(sel_pfel.size() == 0 && sell_pfmu.size() == 1 && sel_pftau.size() == 1)
	if(PFMu_Charge[sell_pfmu[0]]*PFTau_Charge[sel_pftau[0]] == 1){
	  hist_double_lep_same_sign_PFmutau_back_1l->Fill(1,weight*LTprob(2,1,PFMu_PT[sell_pfmu[0]],PFMu_ETA[sell_pfmu[0]])*LTprob(3,1,PFTau_PT[sel_pftau[0]],PFTau_ETA[sel_pftau[0]]));
	}
      /////////////////////// tau tau
      if(sel_pfel.size() == 0 && sel_pfmu.size() == 0 && sel_pftau.size() == 1 && sell_pftau.size() == 1)
	if(PFTau_Charge[sel_pftau[0]]*PFTau_Charge[sell_pftau[0]] == 1){
	  hist_double_lep_same_sign_PFtautau_back_1l->Fill(1,weight*LTprob(2,1,PFTau_PT[sel_pftau[0]],PFTau_ETA[sel_pftau[0]])*LTprob(3,1,PFTau_PT[sell_pftau[0]],PFTau_ETA[sell_pftau[0]]));
	}
    }
    //    cout << "final del evento" << endl;
  }

  f2->cd();
  Jets_Fol->Write();
  Alphat_Fol->Write();
  Alphat_Fol_2jets->Write();
  El_Fol->Write();
  sel_sing_lep->Write();
  sel_dob_lep->Write();
  dif_two_jets->Write();
  Mu_Fol->Write();
  Tau_Fol->Write();
  HT_Fol->Write();
  f2->Close();

}

SusyRead::SusyRead(TTree *tree,char *output, double cs){
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.
  if (tree == 0) {
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../root/QCD_Pt1400_Spring10-START3X_V26_S09-v1.root");

    tree = (TTree*)gDirectory->Get("SUSY_Tree");

  }
  Init(tree);
  f2=new TFile(output,"recreate");
  std::cout << "Cross section: " << cs << std::endl;
  std::cout << "Integrated luminosity" << luminosityint << std::endl;
  if(cs == 1)
    weight = 1;
  else
    weight = cs*luminosityint;

}

SusyRead::~SusyRead()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

Int_t SusyRead::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}

Long64_t SusyRead::LoadTree(Long64_t entry)
{
  // Set the environment to read one entry 
  if (!fChain) return -5;
  Long64_t centry = fChain->LoadTree(entry);
  if (centry < 0) return centry;
  if (!fChain->InheritsFrom(TChain::Class()))  return centry;
  TChain *chain = (TChain*)fChain;
  if (chain->GetTreeNumber() != fCurrent) {
    fCurrent = chain->GetTreeNumber();

  }
  return centry;
}

void SusyRead::Init(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated                                                                        
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF  
  if (!tree) return;
  fChain = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);

  fChain->SetBranchAddress("EVENT", &EVENT, &b_EVENT);
  fChain->SetBranchAddress("RUN", &RUN, &b_RUN);
  fChain->SetBranchAddress("LUMISEC", &LUMISEC, &b_LUMISEC);

  fChain->SetBranchAddress("NJET", &NJET, &b_NJET);
  fChain->SetBranchAddress("JET_ET",JET_ET, &b_JET_ET);
  fChain->SetBranchAddress("JET_PT",JET_PT,&b_JET_PT);
  fChain->SetBranchAddress("JET_PX",JET_PX, &b_JET_PX);
  fChain->SetBranchAddress("JET_PY",JET_PY, &b_JET_PY);
  fChain->SetBranchAddress("JET_PZ",JET_PZ, &b_JET_PZ);
  fChain->SetBranchAddress("JET_ETA",JET_ETA, &b_JET_ETA);
  fChain->SetBranchAddress("JET_PHI",JET_PHI, &b_JET_PHI);
  fChain->SetBranchAddress("JET_energy",JET_energy, &b_JET_energy);
  fChain->SetBranchAddress("JET_btagl",JET_btagl, &b_JET_btagl);
  fChain->SetBranchAddress("JET_btagt",JET_btagt, &b_JET_btagt);

  fChain->SetBranchAddress("NJETak", &NJETak, &b_NJETak);
  fChain->SetBranchAddress("JETak_ET",JETak_ET, &b_JETak_ET);
  fChain->SetBranchAddress("JETak_PT",JETak_PT,&b_JETak_PT);
  fChain->SetBranchAddress("JETak_PX",JETak_PX, &b_JETak_PX);
  fChain->SetBranchAddress("JETak_PY",JETak_PY, &b_JETak_PY);
  fChain->SetBranchAddress("JETak_PZ",JETak_PZ, &b_JETak_PZ);
  fChain->SetBranchAddress("JETak_ETA",JETak_ETA, &b_JETak_ETA);
  fChain->SetBranchAddress("JETak_PHI",JETak_PHI, &b_JETak_PHI);
  fChain->SetBranchAddress("JETak_energy",JETak_energy, &b_JETak_energy);
  fChain->SetBranchAddress("JETak_btagl",JETak_btagl, &b_JETak_btagl);
  fChain->SetBranchAddress("JETak_btagt",JETak_btagt, &b_JETak_btagt);

  fChain->SetBranchAddress("NPFJET", &NPFJET, &b_NPFJET);
  fChain->SetBranchAddress("PFJET_ET",PFJET_ET, &b_PFJET_ET);
  fChain->SetBranchAddress("PFJET_PT",PFJET_PT,&b_PFJET_PT);
  fChain->SetBranchAddress("PFJET_PX",PFJET_PX, &b_PFJET_PX);
  fChain->SetBranchAddress("PFJET_PY",PFJET_PY, &b_PFJET_PY);
  fChain->SetBranchAddress("PFJET_PZ",PFJET_PZ, &b_PFJET_PZ);
  fChain->SetBranchAddress("PFJET_ETA",PFJET_ETA, &b_PFJET_ETA);
  fChain->SetBranchAddress("PFJET_PHI",PFJET_PHI, &b_PFJET_PHI);
  fChain->SetBranchAddress("PFJET_energy",PFJET_energy, &b_PFJET_energy);
  fChain->SetBranchAddress("PFJET_btagl",PFJET_btagl, &b_PFJET_btagl);
  fChain->SetBranchAddress("PFJET_btagt",PFJET_btagt, &b_PFJET_btagt);

  fChain->SetBranchAddress("NPFJETak", &NPFJETak, &b_NPFJETak);
  fChain->SetBranchAddress("PFJETak_ET",PFJETak_ET, &b_PFJETak_ET);
  fChain->SetBranchAddress("PFJETak_PT",PFJETak_PT,&b_PFJETak_PT);
  fChain->SetBranchAddress("PFJETak_PX",PFJETak_PX, &b_PFJETak_PX);
  fChain->SetBranchAddress("PFJETak_PY",PFJETak_PY, &b_PFJETak_PY);
  fChain->SetBranchAddress("PFJETak_PZ",PFJETak_PZ, &b_PFJETak_PZ);
  fChain->SetBranchAddress("PFJETak_ETA",PFJETak_ETA, &b_PFJETak_ETA);
  fChain->SetBranchAddress("PFJETak_PHI",PFJETak_PHI, &b_PFJETak_PHI);
  fChain->SetBranchAddress("PFJETak_energy",PFJETak_energy, &b_PFJETak_energy);
  fChain->SetBranchAddress("PFJETak_btagl",PFJETak_btagl, &b_PFJETak_btagl);
  fChain->SetBranchAddress("PFJETak_btagt",PFJETak_btagt, &b_PFJETak_btagt);

  fChain->SetBranchAddress("NEl", &NEl, &b_NEl);
  fChain->SetBranchAddress("El_Charge",El_Charge,&b_El_Charge);
  fChain->SetBranchAddress("El_D0",El_D0,&b_El_D0);
  fChain->SetBranchAddress("El_ET",El_ET,&b_El_ET);
  fChain->SetBranchAddress("El_ETA",El_ETA,&b_El_ETA);
  fChain->SetBranchAddress("El_EidTight",El_EidTight,&b_El_EidTight);
  fChain->SetBranchAddress("El_PHI",El_PHI,&b_El_PHI);
  fChain->SetBranchAddress("El_PT",El_PT,&b_El_PT);
  fChain->SetBranchAddress("El_PX",El_PX,&b_El_PX);
  fChain->SetBranchAddress("El_PY",El_PY,&b_El_PY);
  fChain->SetBranchAddress("El_PZ",El_PZ,&b_El_PZ);
  fChain->SetBranchAddress("El_HoE",El_HoE,&b_El_HoE);
  fChain->SetBranchAddress("El_ecalIso",El_ecalIso,&b_El_ecalIso);
  fChain->SetBranchAddress("El_hcalIso",El_hcalIso,&b_El_hcalIso);
  fChain->SetBranchAddress("El_energy",El_energy,&b_El_energy);
  fChain->SetBranchAddress("El_trackIso",El_trackIso,&b_El_trackIso);
  fChain->SetBranchAddress("El_Conversion",El_Conversion,&b_El_Conversion);
  fChain->SetBranchAddress("El_LostHits",El_LostHits,&b_El_LostHits);
  fChain->SetBranchAddress("El_isChargeok",El_isChargeok,&b_El_isChargeok);

  fChain->SetBranchAddress("NPFEl", &NPFEl, &b_NPFEl);
  fChain->SetBranchAddress("PFEl_Charge",PFEl_Charge,&b_PFEl_Charge);
  fChain->SetBranchAddress("PFEl_D0",PFEl_D0,&b_PFEl_D0);
  fChain->SetBranchAddress("PFEl_ET",PFEl_ET,&b_PFEl_ET);
  fChain->SetBranchAddress("PFEl_ETA",PFEl_ETA,&b_PFEl_ETA);
  fChain->SetBranchAddress("PFEl_EidTight",PFEl_EidTight,&b_PFEl_EidTight);
  fChain->SetBranchAddress("PFEl_PHI",PFEl_PHI,&b_PFEl_PHI);
  fChain->SetBranchAddress("PFEl_PT",PFEl_PT,&b_PFEl_PT);
  fChain->SetBranchAddress("PFEl_PX",PFEl_PX,&b_PFEl_PX);
  fChain->SetBranchAddress("PFEl_PY",PFEl_PY,&b_PFEl_PY);
  fChain->SetBranchAddress("PFEl_PZ",PFEl_PZ,&b_PFEl_PZ);
  fChain->SetBranchAddress("PFEl_ecalIso",PFEl_ecalIso,&b_PFEl_ecalIso);
  fChain->SetBranchAddress("PFEl_hcalIso",PFEl_hcalIso,&b_PFEl_hcalIso);
  fChain->SetBranchAddress("PFEl_energy",PFEl_energy,&b_PFEl_energy);
  fChain->SetBranchAddress("PFEl_trackIso",PFEl_trackIso,&b_PFEl_trackIso);
  fChain->SetBranchAddress("PFEl_chargedHadronIso",PFEl_chargedHadronIso,&b_PFEl_chargedHadronIso);
  fChain->SetBranchAddress("PFEl_neutralHadronIso",PFEl_neutralHadronIso,&b_PFEl_neutralHadronIso);
  fChain->SetBranchAddress("PFEl_photonIso",PFEl_photonIso,&b_PFEl_photonIso);
  fChain->SetBranchAddress("PFEl_MVA",PFEl_MVA,&b_PFEl_MVA);
  fChain->SetBranchAddress("PFEl_HoE",PFEl_HoE,&b_PFEl_HoE);
  fChain->SetBranchAddress("PFEl_Conversion",PFEl_Conversion,&b_PFEl_Conversion);
  fChain->SetBranchAddress("PFEl_LostHits",PFEl_LostHits,&b_PFEl_LostHits);
  fChain->SetBranchAddress("PFEl_isChargeok",PFEl_isChargeok,&b_PFEl_isChargeok);

  fChain->SetBranchAddress("NMu",&NMu,&b_NMu);
  fChain->SetBranchAddress("Mu_Charge",Mu_Charge,&b_Mu_Charge);
  fChain->SetBranchAddress("Mu_Chi2dof",Mu_Chi2dof,&b_Mu_Chi2dof);
  fChain->SetBranchAddress("Mu_D0",Mu_D0,&b_Mu_D0);
  fChain->SetBranchAddress("Mu_ET",Mu_ET,&b_Mu_ET);
  fChain->SetBranchAddress("Mu_ETA",Mu_ETA,&b_Mu_ETA);
  fChain->SetBranchAddress("Mu_NHitsTrack",Mu_NHitsTrack,&b_Mu_NHitsTrack);
  fChain->SetBranchAddress("Mu_PHI",Mu_PHI,&b_Mu_PHI);
  fChain->SetBranchAddress("Mu_PT",Mu_PT,&b_Mu_PT);
  fChain->SetBranchAddress("Mu_PX",Mu_PX,&b_Mu_PX);
  fChain->SetBranchAddress("Mu_PY",Mu_PY,&b_Mu_PY);
  fChain->SetBranchAddress("Mu_PZ",Mu_PZ,&b_Mu_PZ);
  fChain->SetBranchAddress("Mu_ecalIso",Mu_ecalIso,&b_Mu_ecalIso);
  fChain->SetBranchAddress("Mu_energy",Mu_energy,&b_Mu_energy);
  fChain->SetBranchAddress("Mu_hcalIso",Mu_hcalIso,&b_Mu_hcalIso);
  fChain->SetBranchAddress("Mu_isGlobal",Mu_isGlobal,&b_Mu_isGlobal);
  fChain->SetBranchAddress("Mu_trackIso",Mu_trackIso,&b_Mu_trackIso);

  fChain->SetBranchAddress("NPFMu",&NPFMu,&b_NPFMu);
  fChain->SetBranchAddress("PFMu_Charge",PFMu_Charge,&b_PFMu_Charge);
  fChain->SetBranchAddress("PFMu_Chi2dof",PFMu_Chi2dof,&b_PFMu_Chi2dof);
  fChain->SetBranchAddress("PFMu_D0",PFMu_D0,&b_PFMu_D0);
  fChain->SetBranchAddress("PFMu_ET",PFMu_ET,&b_PFMu_ET);
  fChain->SetBranchAddress("PFMu_ETA",PFMu_ETA,&b_PFMu_ETA);
  fChain->SetBranchAddress("PFMu_NHitsTrack",PFMu_NHitsTrack,&b_PFMu_NHitsTrack);
  fChain->SetBranchAddress("PFMu_PHI",PFMu_PHI,&b_PFMu_PHI);
  fChain->SetBranchAddress("PFMu_PT",PFMu_PT,&b_PFMu_PT);
  fChain->SetBranchAddress("PFMu_PX",PFMu_PX,&b_PFMu_PX);
  fChain->SetBranchAddress("PFMu_PY",PFMu_PY,&b_PFMu_PY);
  fChain->SetBranchAddress("PFMu_PZ",PFMu_PZ,&b_PFMu_PZ);
  fChain->SetBranchAddress("PFMu_ecalIso",PFMu_ecalIso,&b_PFMu_ecalIso);
  fChain->SetBranchAddress("PFMu_energy",PFMu_energy,&b_PFMu_energy);
  fChain->SetBranchAddress("PFMu_hcalIso",PFMu_hcalIso,&b_PFMu_hcalIso);
  fChain->SetBranchAddress("PFMu_isGlobal",PFMu_isGlobal,&b_PFMu_isGlobal);
  fChain->SetBranchAddress("PFMu_trackIso",PFMu_trackIso,&b_PFMu_trackIso);
  fChain->SetBranchAddress("PFMu_neutralHadronIso",PFMu_neutralHadronIso,&b_PFMu_neutralHadronIso);
  fChain->SetBranchAddress("PFMu_chargedHadronIso",PFMu_chargedHadronIso,&b_PFMu_chargedHadronIso);
  fChain->SetBranchAddress("PFMu_photonIso",PFMu_photonIso,&b_PFMu_photonIso);

  fChain->SetBranchAddress("MET",&MET,&b_MET);
  fChain->SetBranchAddress("MET_PHI",&MET_PHI,&b_MET_PHI);

  fChain->SetBranchAddress("METak",&METak,&b_METak);
  fChain->SetBranchAddress("METak_PHI",&METak_PHI,&b_METak_PHI);

  fChain->SetBranchAddress("PFMET",&PFMET,&b_PFMET);
  fChain->SetBranchAddress("PFMET_PHI",&PFMET_PHI,&b_PFMET_PHI);

  fChain->SetBranchAddress("NTau",&NTau,&b_NTau);
  fChain->SetBranchAddress("Tau_Charge",Tau_Charge,&b_Tau_Charge);
  fChain->SetBranchAddress("Tau_ET",Tau_ET,&b_Tau_ET);
  fChain->SetBranchAddress("Tau_ETA",Tau_ETA,&b_Tau_ETA);
  fChain->SetBranchAddress("Tau_PHI",Tau_PHI,&b_Tau_PHI);
  fChain->SetBranchAddress("Tau_PT",Tau_PT,&b_Tau_PT);
  fChain->SetBranchAddress("Tau_PX",Tau_PX,&b_Tau_PX);
  fChain->SetBranchAddress("Tau_PY",Tau_PY,&b_Tau_PY);
  fChain->SetBranchAddress("Tau_PZ",Tau_PZ,&b_Tau_PZ);
  fChain->SetBranchAddress("Tau_TaNC",Tau_TaNC,&b_Tau_TaNC);
  fChain->SetBranchAddress("Tau_energy",Tau_energy,&b_Tau_energy);
  fChain->SetBranchAddress("Tau_LTF",Tau_LTF,&b_Tau_LTF);

  fChain->SetBranchAddress("NPFTau",&NPFTau,&b_NPFTau);
  fChain->SetBranchAddress("PFTau_Charge",PFTau_Charge,&b_PFTau_Charge);
  fChain->SetBranchAddress("PFTau_ET",PFTau_ET,&b_PFTau_ET);
  fChain->SetBranchAddress("PFTau_ETA",PFTau_ETA,&b_PFTau_ETA);
  fChain->SetBranchAddress("PFTau_PHI",PFTau_PHI,&b_PFTau_PHI);
  fChain->SetBranchAddress("PFTau_PT",PFTau_PT,&b_PFTau_PT);
  fChain->SetBranchAddress("PFTau_PX",PFTau_PX,&b_PFTau_PX);
  fChain->SetBranchAddress("PFTau_PY",PFTau_PY,&b_PFTau_PY);
  fChain->SetBranchAddress("PFTau_PZ",PFTau_PZ,&b_PFTau_PZ);
  fChain->SetBranchAddress("PFTau_TaNC",PFTau_TaNC,&b_PFTau_TaNC);
  fChain->SetBranchAddress("PFTau_energy",PFTau_energy,&b_PFTau_energy);
  fChain->SetBranchAddress("PFTau_LTF",PFTau_LTF,&b_PFTau_LTF);
}
float SusyRead::dzero(float d0, float phi){
  return d0+0.0322* cos(phi);
}
