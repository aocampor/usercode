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
class SusyRead{
 public :
  TTree *fChain;
  Int_t  fCurrent; //!current Tree number in a TChain

  /////////Declaration of leaf type
  UInt_t EVENT,RUN,LUMISEC;
  UInt_t NJET,NPFJET,NEl,NPFEl,NMu,NPFMu,NTau,NPFTau;
  UInt_t El_EidTight[50],PFEl_EidTight[50];
  Double_t JET_ET[50],JET_PT[50],JET_PX[50],JET_PY[50],JET_PZ[50],JET_ETA[50],JET_PHI[50],JET_energy[50];
  Double_t PFJET_ET[50],PFJET_PT[50],PFJET_PX[50],PFJET_PY[50],PFJET_PZ[50],PFJET_ETA[50],PFJET_PHI[50],PFJET_energy[50];
  Double_t El_Charge[50],El_D0[50],El_ET[50],El_ETA[50],El_PHI[50],El_PT[50],El_PX[50],El_PY[50],El_PZ[50],El_ecalIso[50],El_hcalIso[50],El_energy[50],El_trackIso[50];
  Double_t PFEl_Charge[50],PFEl_D0[50],PFEl_ET[50],PFEl_ETA[50],PFEl_PHI[50],PFEl_PT[50],PFEl_PX[50],PFEl_PY[50],PFEl_PZ[50],PFEl_ecalIso[50],PFEl_hcalIso[50],PFEl_energy[50],PFEl_trackIso[50],PFEl_chargedHadronIso[50],PFEl_neutralHadronIso[50],PFEl_photonIso[50],PFEl_MVA[50],PFEl_HoE[50];
  Double_t Mu_Charge[50],Mu_Chi2dof[50],Mu_D0[50],Mu_ET[50],Mu_ETA[50],Mu_NHitsTrack[50],Mu_PHI[50],Mu_PT[50],Mu_PX[50],Mu_PY[50],Mu_PZ[50],Mu_ecalIso[50],Mu_energy[50],Mu_hcalIso[50],Mu_isGlobal[50],Mu_trackIso[50];
  Double_t PFMu_Charge[50],PFMu_Chi2dof[50],PFMu_D0[50],PFMu_ET[50],PFMu_ETA[50],PFMu_NHitsTrack[50],PFMu_PHI[50],PFMu_PT[50],PFMu_PX[50],PFMu_PY[50],PFMu_PZ[50],PFMu_ecalIso[50],PFMu_energy[50],PFMu_hcalIso[50],PFMu_isGlobal[50],PFMu_trackIso[50],PFMu_chargedHadronIso[50],PFMu_neutralHadronIso[50],PFMu_photonIso[50];
  Double_t MET,MET_PHI,PFMET,PFMET_PHI;
  Double_t Tau_Charge[50],Tau_ET[50],Tau_ETA[50],Tau_PHI[50],Tau_PT[50],Tau_PX[50],Tau_PY[50],Tau_PZ[50],Tau_TaNC[50],Tau_energy[50];
  Double_t PFTau_Charge[50],PFTau_ET[50],PFTau_ETA[50],PFTau_PHI[50],PFTau_PT[50],PFTau_PX[50],PFTau_PY[50],PFTau_PZ[50],PFTau_TaNC[50],PFTau_energy[50];
  ///////////pointers to the branches
  TBranch *b_EVENT,*b_RUN,*b_LUMISEC;
  TBranch *b_NJET,*b_NPFJET,*b_NEl,*b_NPFEl,*b_NMu,*b_NPFMu,*b_MET,*b_PFMET,*b_MET_PHI,*b_PFMET_PHI,*b_NTau,*b_NPFTau;
  TBranch *b_JET_ET,*b_JET_PT,*b_JET_PX,*b_JET_PY,*b_JET_PZ,*b_JET_ETA,*b_JET_PHI,*b_JET_energy;
  TBranch *b_PFJET_ET,*b_PFJET_PT,*b_PFJET_PX,*b_PFJET_PY,*b_PFJET_PZ,*b_PFJET_ETA,*b_PFJET_PHI,*b_PFJET_energy;
  TBranch *b_El_Charge,*b_El_D0,*b_El_ET,*b_El_ETA,*b_El_EidTight,*b_El_PHI,*b_El_PT,*b_El_PX,*b_El_PY,*b_El_PZ,*b_El_ecalIso,*b_El_hcalIso,*b_El_energy,*b_El_trackIso;
  TBranch *b_PFEl_Charge,*b_PFEl_D0,*b_PFEl_ET,*b_PFEl_ETA,*b_PFEl_EidTight,*b_PFEl_PHI,*b_PFEl_PT,*b_PFEl_PX,*b_PFEl_PY,*b_PFEl_PZ,*b_PFEl_ecalIso,*b_PFEl_hcalIso,*b_PFEl_energy,*b_PFEl_trackIso,*b_PFEl_chargedHadronIso,*b_PFEl_neutralHadronIso,*b_PFEl_photonIso,*b_PFEl_MVA,*b_PFEl_HoE;
  TBranch *b_Mu_Charge,*b_Mu_Chi2dof,*b_Mu_D0,*b_Mu_ET,*b_Mu_ETA,*b_Mu_NHitsTrack,*b_Mu_PHI,*b_Mu_PT,*b_Mu_PX,*b_Mu_PY,*b_Mu_PZ,*b_Mu_ecalIso,*b_Mu_energy,*b_Mu_hcalIso,*b_Mu_isGlobal,*b_Mu_trackIso;
  TBranch *b_PFMu_Charge,*b_PFMu_Chi2dof,*b_PFMu_D0,*b_PFMu_ET,*b_PFMu_ETA,*b_PFMu_NHitsTrack,*b_PFMu_PHI,*b_PFMu_PT,*b_PFMu_PX,*b_PFMu_PY,*b_PFMu_PZ,*b_PFMu_ecalIso,*b_PFMu_energy,*b_PFMu_hcalIso,*b_PFMu_isGlobal,*b_PFMu_trackIso,*b_PFMu_chargedHadronIso,*b_PFMu_neutralHadronIso,*b_PFMu_photonIso;
  TBranch *b_Tau_Charge,*b_Tau_ET,*b_Tau_ETA,*b_Tau_PHI,*b_Tau_PT,*b_Tau_PX,*b_Tau_PY,*b_Tau_PZ,*b_Tau_TaNC,*b_Tau_energy;
  TBranch *b_PFTau_Charge,*b_PFTau_ET,*b_PFTau_ETA,*b_PFTau_PHI,*b_PFTau_PT,*b_PFTau_PX,*b_PFTau_PY,*b_PFTau_PZ,*b_PFTau_TaNC,*b_PFTau_energy;
  ////CUTS
  static const double Jet_Pt_Cut = 30.;
  static const double Jet_Eta_Cut = 2.5;
  static const double Jet1_Pt_Cut = 60.;
  static const double HT_Cut = 150.;
  static const double HT_high_Cut = 350.;
  static const double MHT_Cut = 50.;
  static const double El_Pt_Cut = 10.;
  static const double El_MVA_Cut = 0.6;
  static const double El_HoE_Cut = 0.06;
  static const double El_Eta_Cut = 2.4;
  static const double El_D0_Cut = 0.02;
  static const double Mu_Pt_Cut = 10.;
  static const double Mu_Eta_Cut = 2.5;
  static const double Mu_Chi2dof_Cut = 10.;
  static const double Mu_NHits_Cut = 11;
  static const double Mu_D0_Cut = 0.02;
  static const double Mu_isGlobal_Cut = 0.02;
  static const double Met_Cut = 50.;
  static const double Met_high_Cut = 100.;
  static const double Tau_Pt_Cut = 15.;
  static const double Tau_Eta_Cut = 2.5;
  static const double luminosityint = 33.853969431;
  static const double Alphat_Cut = 0.7;

  SusyRead(TTree *tree=0,char *output="salida.root",double cs=1);

  virtual ~SusyRead();

  virtual Int_t    GetEntry(Long64_t entry);
  virtual Long64_t LoadTree(Long64_t entry);
  virtual void     Init(TTree *tree);
  virtual void     Loop();
  std::vector<std::vector<double> > AlphaT(std::vector<std::vector< double > >);
  std::vector<std::vector<double> > AlphaTReClus(std::vector<std::vector< double > >);

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
  TFolder *Alphat_Fol = gROOT->GetRootFolder()->AddFolder("Alphat","Alphat"); 
  TFolder *El_Fol = gROOT->GetRootFolder()->AddFolder("Electron","Electron"); 
  TFolder *sel_sing_lep = gROOT->GetRootFolder()->AddFolder("SingleLepton","SingleLepton"); 
  TFolder *sel_dob_lep = gROOT->GetRootFolder()->AddFolder("DoubleLepton","DoubleLepton"); 
  TFolder *dif_two_jets = gROOT->GetRootFolder()->AddFolder("Differences_two_jets","Differences_two_jets"); 

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

  TH1F *hist_double_lep_same_sign_PFee = new TH1F("PFDLSSee","PFDLSSee",2,0,2);
  TH1F *hist_double_lep_same_sign_PFemu = new TH1F("PFDLSSemu","PFDLSSemu",2,0,2);
  TH1F *hist_double_lep_same_sign_PFetau = new TH1F("PFDLSSetau","PFDLSSetau",2,0,2);
  TH1F *hist_double_lep_same_sign_PFmumu = new TH1F("PFDLSSmumu","PFDLSSmumu",2,0,2);
  TH1F *hist_double_lep_same_sign_PFmutau = new TH1F("PFDLSSmutau","PFDLSSmutau",2,0,2);
  TH1F *hist_double_lep_same_sign_PFtautau = new TH1F("PFDLSStautau","PFDLSStautau",2,0,2);

  hist_double_lep_same_sign_ee->Sumw2();
  hist_double_lep_same_sign_emu->Sumw2();
  hist_double_lep_same_sign_etau->Sumw2();
  hist_double_lep_same_sign_mumu->Sumw2();
  hist_double_lep_same_sign_mutau->Sumw2();
  hist_double_lep_same_sign_tautau->Sumw2();

  hist_double_lep_same_sign_PFee->Sumw2();
  hist_double_lep_same_sign_PFemu->Sumw2();
  hist_double_lep_same_sign_PFetau->Sumw2();
  hist_double_lep_same_sign_PFmumu->Sumw2();
  hist_double_lep_same_sign_PFmutau->Sumw2();
  hist_double_lep_same_sign_PFtautau->Sumw2();

  sel_dob_lep->Add(hist_double_lep_same_sign_ee);
  sel_dob_lep->Add(hist_double_lep_same_sign_emu);
  sel_dob_lep->Add(hist_double_lep_same_sign_etau);
  sel_dob_lep->Add(hist_double_lep_same_sign_mumu);
  sel_dob_lep->Add(hist_double_lep_same_sign_mutau);
  sel_dob_lep->Add(hist_double_lep_same_sign_tautau);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFee);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFemu);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFetau);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFmumu);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFmutau);
  sel_dob_lep->Add(hist_double_lep_same_sign_PFtautau);

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
  TH1F *hist_alphat_re_SLCuts = new TH1F("Events_after_alphat_re_and_SL_cuts","Events_after_alphat_and_SL_cuts",2,0,2);
  TH1F *hist_alphat_re_PFSLCuts = new TH1F("Events_after_alphat_re_and_PFSL_cuts","Events_after_alphat_and_PFSL_cuts",2,0,2);
  TH1F *hist_alphat_re_DLCuts = new TH1F("Events_after_alphat_re_and_DL_cuts","Events_after_alphat_and_DL_cuts",2,0,2);
  TH1F *hist_alphat_re_PFDLCuts = new TH1F("Events_after_alphat_re_and_PFDL_cuts","Events_after_alphat_and_PFDL_cuts",2,0,2);

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

  TH1F *hist_alphat_twojets_dif = new TH1F("Delta_SRandPF_alphat_twojets_present","Delta_SRandPF_alphat_twojets_present",200,-10,10);
  TH1F *hist_alphat_twoSRjets_notwoPFjets_metdif = new TH1F("Delta_SR_vs_PF_MET_alphat_twoSRjets_notwoPFjets","Delta_SR_vs_PF_MET_alphat_twoSRjets_notwoPFjets",200,-200,200);  
  TH1F *hist_alphat_twoSRjets_twoPFjets_metdif = new TH1F("Delta_SR_vs_PF_MET_alphat_twoSRjets_twoPFjets","Delta_SR_vs_PF_MET_alphat_twoSRjets_twoPFjets",200,-200,200);  
  TH1F *hist_totht_dif_sr_vs_pf = new TH1F("Diff_Tot_HT_SR_vs_PF","Diff_Tot_HT_SR_vs_PF",200,-200,200);
  TH1F *hist_totht_dif_sr_vs_pf_nopftwojets = new TH1F("Diff_Tot_HT_SR_vs_PF_nopftwojets","Diff_Tot_HT_SR_vs_PF_nopftwojets",200,-200,2000);

  hist_alphat_twojets_dif->Sumw2();
  hist_alphat_twoSRjets_notwoPFjets_metdif->Sumw2();
  hist_alphat_twoSRjets_twoPFjets_metdif->Sumw2();
  hist_totht_dif_sr_vs_pf->Sumw2();
  hist_totht_dif_sr_vs_pf_nopftwojets->Sumw2();

  dif_two_jets->Add(hist_alphat_twojets_dif);
  dif_two_jets->Add(hist_alphat_twoSRjets_notwoPFjets_metdif);
  dif_two_jets->Add(hist_alphat_twoSRjets_twoPFjets_metdif);
  dif_two_jets->Add(hist_totht_dif_sr_vs_pf);
  dif_two_jets->Add(hist_totht_dif_sr_vs_pf_nopftwojets);

  TH1F *hist_ele_multiplicity_after_pt_cut = new TH1F("Electron_multiplicity_after_pt_cut","Electron_multiplicity_after_pt_cut",10,0,10);
  TH1F *hist_ele_multiplicity_after_pt_eta_cut = new TH1F("Electron_multiplicity_after_eta_cut","Electron_multiplicity_after_eta_cut",10,0,10);
  TH1F *hist_PFele_multiplicity_after_pt_cut = new TH1F("PFElectron_multiplicity_after_pt_cut","PFElectron_multiplicity_after_pt_cut",10,0,10);
  TH1F *hist_PFele_multiplicity_after_pt_eta_cut = new TH1F("PFElectron_multiplicity_after_eta_cut","PFElectron_multiplicity_after_eta_cut",10,0,10);

  hist_ele_multiplicity_after_pt_cut->Sumw2();
  hist_ele_multiplicity_after_pt_eta_cut->Sumw2();
  hist_PFele_multiplicity_after_pt_cut->Sumw2();
  hist_PFele_multiplicity_after_pt_eta_cut->Sumw2();

  El_Fol->Add(hist_ele_multiplicity_after_pt_cut);
  El_Fol->Add(hist_ele_multiplicity_after_pt_eta_cut);
  El_Fol->Add(hist_PFele_multiplicity_after_pt_cut);
  El_Fol->Add(hist_PFele_multiplicity_after_pt_eta_cut);

  if (fChain == 0) return; 
  Long64_t nentries = fChain->GetEntriesFast();   
  cout<<"EVENTS "<< nentries<<endl; 
  Long64_t nbytes = 0, nb = 0; 
  //  nentries = 1000;
  if(weight != 1)
    weight = weight/double(nentries);
  //  std::cout << "The weight for this event is " << weight << std::endl;
  //////////////////////////////////////////
  ////Loop over the tree //////////////////////////
  ////////////////////////////////////////
  for (Long64_t jentry=0; jentry<nentries; jentry++) {
    if (jentry%50000 ==0) cout<<jentry<<" EVENTS ANALYZED"<<endl; 
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;      
    nb = fChain->GetEntry(jentry);   nbytes += nb;

    //std::cout << "New Event Run: " << RUN << " EVENT: " << EVENT << " LUMIsection: " << LUMISEC << endl; 

    bool two_leading_jets = false;
    bool two_leading_PFjets = false;

    std::vector<int> sel_pfmu;
    std::vector<int> sel_mu;
    std::vector<int> sel_el;
    std::vector<int> sel_pfel;
    std::vector<int> sel_jet;
    std::vector<int> sel_pfjet;
    std::vector<int> sel_tau;
    std::vector<int> sel_pftau;
    std::vector<double> htvec;
    std::vector<double> pfhtvec;
    std::vector<double> alphatvec;
    std::vector<double> pfalphatvec;
    for(int i=0;i<4;i++){
      alphatvec.push_back(0.);
      pfalphatvec.push_back(0.);
    }
    bool leading_jet = false;
    bool leading_pfjet = false;

    ////////////////////////////////////////
    /////////Tau cycle
    /////////////////////////////////////
    for(unsigned int i=0;i<NTau;i++){
      if(Tau_PT[i] > Tau_Pt_Cut )
	continue;
      if(fabs(Tau_ETA[i]) > Tau_Eta_Cut )
	continue;
      if(Tau_TaNC[i] == 0 )
	continue;
      sel_tau.push_back(i);
    }

    ////////////////////////////////////////
    /////////PF Tau cycle
    /////////////////////////////////////
    for(unsigned int i=0;i<NPFTau;i++){
      if(PFTau_PT[i] > Tau_Pt_Cut )
	continue;
      if(fabs(PFTau_ETA[i]) > Tau_Eta_Cut )
	continue;
      if(PFTau_TaNC[i] == 0 )
	continue;
      sel_pftau.push_back(i);
    }

    ///////////////////////////////////////
    ///////////////////Muon cycle
    ////////////////////////////////////
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
      sel_mu.push_back((int)i);
    }
    ///////////////////////////////////////
    ///////////////////PF Muon cycle
    ////////////////////////////////////
    for(unsigned int i=0;i<NPFMu;i++){
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
      sel_pfmu.push_back((int)i);
    }
    ///////////////////////////////////////////
    /////////////////Electron cycle
    //////////////////////////////////////
    int el_mult_after_pt_cut = 0;
    int el_mult_after_pt_eta_cut = 0;
    for(unsigned int i=0;i<NEl;i++){
      if(El_PT[i] < El_Pt_Cut)
	continue;
      el_mult_after_pt_cut++;
      if(fabs(El_ETA[i]) > El_Eta_Cut)
	continue;
      if(El_EidTight[i] != 1)
	continue;
      if(fabs(El_D0[i]) > El_D0_Cut )
	continue;
      el_mult_after_pt_eta_cut++;
      sel_el.push_back((int)i);
    }
    hist_ele_multiplicity_after_pt_cut->Fill(el_mult_after_pt_cut,weight);
    hist_ele_multiplicity_after_pt_eta_cut->Fill(el_mult_after_pt_eta_cut,weight);

    //////////////////////////////////////////////////////
    /////////////////PF Electron cycle
    ///////////////////////////////////////////////////////
    el_mult_after_pt_cut = 0;
    el_mult_after_pt_eta_cut = 0;
    for(unsigned int i=0;i<NPFEl;i++){
      if(PFEl_PT[i] < El_Pt_Cut)
	continue;
      el_mult_after_pt_cut++;
      if(fabs(PFEl_ETA[i]) > El_Eta_Cut)
	continue;
      el_mult_after_pt_eta_cut++;
      if(PFEl_MVA[i] < El_MVA_Cut)
	continue;
      //      if(PFEl_HoE[i] > El_HoE_Cut)
      //	continue;
      if(fabs(PFEl_D0[i]) > El_D0_Cut )
	continue;
      sel_pfel.push_back((int)i);
    }
    hist_PFele_multiplicity_after_pt_cut->Fill(el_mult_after_pt_cut,weight);
    hist_PFele_multiplicity_after_pt_eta_cut->Fill(el_mult_after_pt_eta_cut,weight);

    ///////////////////////////////////////////
    //////////Jet cycle
    //////////////////////////////////////////
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
      temp.push_back(JET_ET[i]);
      temp.push_back(JET_PT[i]);
      temp.push_back(JET_PX[i]);
      temp.push_back(JET_PY[i]);
      temp.push_back(JET_PZ[i]);
      temp.push_back(JET_ETA[i]);
      temp.push_back(JET_PHI[i]);
      //std::cout << " Jet " << i+1 << " pt " << JET_PT[i] << " eta: " << JET_ETA[i] << " phi: " << JET_PHI[i] << std::endl;
      Jets.push_back(temp);
      temp.clear();
      if(JET_PT[i] < Jet_Pt_Cut)
	continue;
      cont_jet_after_pt++;
      if(fabs(JET_ETA[i]) > Jet_Eta_Cut)
	continue;
      cont_jet_after_eta++;
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
      std::vector<std::vector<double> > result=AlphaT(Jets);
      alphatvec[0] = result[0][0];
      hist_alphat_njets_minimum_deltaht->Fill(result[0][0],weight);
      hist_deltaeta_vs_deltaphi_njets->Fill(result[0][3]-result[1][3],result[0][2]-result[1][2],weight);
      //      if(fabs(result[0][3]-result[1][3])<0.1 && fabs(result[0][2]-result[1][2]) < 0.1){
      //	std::cout << " \t eta1: " << result[0][2] << " phi1 " << result[0][3] << std::endl;
      // 	std::cout << " \t eta2: " << result[1][2] << " phi2 " << result[1][3] << std::endl;
      //	std::cout << "Pathological Event Run: " << RUN << " EVENT: " << EVENT << " LUMIsection: " << LUMISEC << endl; 
      //      }
      result.clear();
      result=AlphaTReClus(Jets);
      if(result[1][0] != 0 )
	hist_deltaeta_vs_deltaphi_njets_recluster->Fill(result[0][6]-result[1][6],result[0][5]-result[1][5],weight);
      hist_alphat_njets_as_two_jets->Fill(result[2][0],weight);
      hist_alphat_njets_as_reclustered->Fill(result[2][1],weight);
      hist_alphat_njets_as_reclustered_recomputed_ht->Fill(result[2][2],weight);
      alphatvec[1] = result[2][0];
      alphatvec[2] = result[2][1];
      alphatvec[3] = result[2][2];
    }

    ///////////////////////////////////////////
    //////////PFJet cycle
    ///////////////////////////////////
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
      temp.push_back(PFJET_ET[i]);
      temp.push_back(PFJET_PT[i]);
      temp.push_back(PFJET_PX[i]);
      temp.push_back(PFJET_PY[i]);
      temp.push_back(PFJET_PZ[i]);
      temp.push_back(PFJET_ETA[i]);
      temp.push_back(PFJET_PHI[i]);
      Jets.push_back(temp);
      temp.clear();
      if( PFJET_PT[i] < Jet_Pt_Cut )
	continue;
      cont_jet_after_pt++;
      if( fabs(PFJET_ETA[i]) > Jet_Eta_Cut)
	continue;
      cont_jet_after_eta++;
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
    if(sel_pfjet.size() == 2 && two_leading_PFjets){
      pftwojet = true;
      pfalphatvec[0] = sqrt( (jet2[0])/(2*jet1[0]*(1-cos(jet1[3]-jet2[3]))));
      hist_deltaeta_vs_deltaphi_2PFjets->Fill(jet1[3]-jet2[3],jet1[2]-jet2[2],weight);
      hist_alphat_twoPFjets->Fill(pfalphatvec[0],weight);
    }
    else if(sel_pfjet.size() > 2 && two_leading_PFjets){
      std::vector<std::vector<double> > result=AlphaT(Jets);
      hist_alphat_nPFjets_minimum_deltaht->Fill(result[0][0],weight);
      pfalphatvec[0] = result[0][0];
      hist_deltaeta_vs_deltaphi_nPFjets->Fill(result[0][3]-result[1][3],result[0][2]-result[1][2],weight);
      result.clear();
      result=AlphaTReClus(Jets);
      if(result[1][0] != 0 )
	hist_deltaeta_vs_deltaphi_nPFjets_recluster->Fill(result[0][6]-result[1][6],result[0][5]-result[1][5],weight);
      hist_alphat_nPFjets_as_two_jets->Fill(result[2][0],weight);
      hist_alphat_nPFjets_as_reclustered->Fill(result[2][1],weight);
      hist_alphat_nPFjets_as_reclustered_recomputed_ht->Fill(result[2][2],weight);
      pfalphatvec[1] = result[2][0];
      pfalphatvec[2] = result[2][1];
      pfalphatvec[3] = result[2][2];
    }

    /////////////////////////
    ////////jet comparison
    ///////////////
    /*
    if(srtwojet && pftwojet){
      std::cout << "Two Jets for both SR and PF, SR alphat: " << alphatvec[0] << " PF alphat: " << pfalphatvec[0] << " difference: " << alphatvec[0] - pfalphatvec[0] << std::endl;
      hist_alphat_twojets_dif->Fill(alphatvec[0] - pfalphatvec[0],weight);
      hist_alphat_twoSRjets_twoPFjets_metdif->Fill(MET-PFMET,weight);
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
    */
      /*
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

    //////////////////////////////
    ////////////////single lepton
    /////////////////////
    
    if(MET > Met_high_Cut && sel_jet.size() >= 2 && leading_jet){
      if(sel_jet.size()==2)
	hist_alphatdis_twojets_SL->Fill(alphatvec[0],weight);
      if(sel_jet.size() > 2){
	hist_alphat_njets_minimum_deltaht_SL->Fill(alphatvec[0],weight);
	hist_alphat_njets_as_reclustered_SL->Fill(alphatvec[2],weight);
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
    
    //////////////////////////////
    ////////////////single lepton PF
    /////////////////////
    if(PFMET > Met_high_Cut && sel_pfjet.size() >= 2 && leading_pfjet){
      if(sel_pfjet.size()==2)
	hist_alphatdis_twoPFjets_SL->Fill(pfalphatvec[0],weight);
      if(sel_pfjet.size() > 2){
	hist_alphat_nPFjets_minimum_deltaht_SL->Fill(pfalphatvec[0],weight);
	hist_alphat_nPFjets_as_reclustered_SL->Fill(pfalphatvec[2],weight);
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
    
    ///////////////////////////////////////
    /////////////////double lepton opposite sign
    ///////////////////////////////
    
    if(MET > Met_Cut && htvec[0] > HT_high_Cut && htvec[1] > MHT_Cut){
      if(sel_jet.size()==2)
	hist_alphatdis_twojets_DL->Fill(alphatvec[0],weight);
      if(sel_jet.size() > 2){
	hist_alphat_njets_minimum_deltaht_DL->Fill(alphatvec[0],weight);
	hist_alphat_njets_as_reclustered_DL->Fill(alphatvec[2],weight);
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


    if(PFMET > Met_Cut && pfhtvec[0] > HT_high_Cut && pfhtvec[1] > MHT_Cut){
      if(sel_pfjet.size()==2)
	hist_alphatdis_twoPFjets_DL->Fill(pfalphatvec[0],weight);
      if(sel_pfjet.size() > 2){
	hist_alphat_nPFjets_minimum_deltaht_DL->Fill(pfalphatvec[0],weight);
       	hist_alphat_nPFjets_as_reclustered_DL->Fill(pfalphatvec[2],weight);
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
    
    if(MET > Met_Cut && htvec[0] > HT_high_Cut && htvec[1] > MHT_Cut){

      ////////////////electron electron
      if(sel_el.size() == 2 && sel_mu.size() == 0 && sel_tau.size() == 0){
	if(El_Charge[sel_el[0]]*El_Charge[sel_el[1]] == 1)
	  hist_double_lep_same_sign_ee->Fill(1,weight);
      }
      ///////////////////////electron muon
      if(sel_el.size() == 1 && sel_mu.size() == 1 && sel_tau.size() == 0){
	if(El_Charge[sel_el[0]]*Mu_Charge[sel_mu[0]] == 1)
	  hist_double_lep_same_sign_emu->Fill(1,weight);
      }
      ///////////////////////electron tau
      if(sel_el.size() == 1 && sel_mu.size() == 0 && sel_tau.size() == 1){
	if(El_Charge[sel_el[0]]*Tau_Charge[sel_tau[0]] == 1)
	  hist_double_lep_same_sign_etau->Fill(1,weight);
      }
      ////////////////muon muon
      if(sel_el.size() == 0 && sel_mu.size() == 2 && sel_tau.size() == 0){
	if(Mu_Charge[sel_mu[0]]*Mu_Charge[sel_mu[1]] == 1)
	  hist_double_lep_same_sign_mumu->Fill(1,weight);
      }
      /////////////////////// muon tau
      if(sel_el.size() == 0 && sel_mu.size() == 1 && sel_tau.size() == 1){
	if(Mu_Charge[sel_mu[0]]*Tau_Charge[sel_tau[0]] == 1)
	  hist_double_lep_same_sign_mutau->Fill(1,weight);
      }
      /////////////////////// tau tau
      if(sel_el.size() == 0 && sel_mu.size() == 0 && sel_tau.size() == 2){
	if(Tau_Charge[sel_tau[0]]*Tau_Charge[sel_tau[1]] == 1)
	  hist_double_lep_same_sign_tautau->Fill(1,weight);
      }
    }
   
    if(PFMET > Met_Cut && pfhtvec[0] > HT_high_Cut && pfhtvec[1] > MHT_Cut){

      ////////////////electron electron
      if(sel_pfel.size() == 2 && sel_pfmu.size() == 0 && sel_pftau.size() == 0){
	if(PFEl_Charge[sel_pfel[0]]*PFEl_Charge[sel_pfel[1]] == 1)
	  hist_double_lep_same_sign_PFee->Fill(1,weight);
      }
      ///////////////////////electron muon
      if(sel_pfel.size() == 1 && sel_pfmu.size() == 1 && sel_pftau.size() == 0){
	if(PFEl_Charge[sel_pfel[0]]*PFMu_Charge[sel_pfmu[0]] == 1)
	  hist_double_lep_same_sign_PFemu->Fill(1,weight);
      }
      ///////////////////////electron tau
      if(sel_pfel.size() == 1 && sel_pfmu.size() == 0 && sel_pftau.size() == 1){
	if(PFEl_Charge[sel_pfel[0]]*PFTau_Charge[sel_pftau[0]] == 1)
	  hist_double_lep_same_sign_PFetau->Fill(1,weight);
      }
      ////////////////muon muon
      if(sel_pfel.size() == 0 && sel_pfmu.size() == 2 && sel_pftau.size() == 0){
	if(PFMu_Charge[sel_pfmu[0]]*PFMu_Charge[sel_pfmu[1]] == 1)
	  hist_double_lep_same_sign_PFmumu->Fill(1,weight);
      }
      /////////////////////// muon tau
      if(sel_pfel.size() == 0 && sel_pfmu.size() == 1 && sel_pftau.size() == 1){
	if(PFMu_Charge[sel_pfmu[0]]*PFTau_Charge[sel_pftau[0]] == 1)
	  hist_double_lep_same_sign_PFmutau->Fill(1,weight);
      }
      /////////////////////// tau tau
      if(sel_pfel.size() == 0 && sel_pfmu.size() == 0 && sel_pftau.size() == 2){
	if(PFTau_Charge[sel_pftau[0]]*PFTau_Charge[sel_pftau[1]] == 1)
	  hist_double_lep_same_sign_PFtautau->Fill(1,weight);
      }
    }

  }
  
  f2->cd();
  Jets_Fol->Write();
  Alphat_Fol->Write();
  El_Fol->Write();
  sel_sing_lep->Write();
  sel_dob_lep->Write();
  dif_two_jets->Write();
  f2->Close();
}

std::vector<std::vector<double> > SusyRead::AlphaTReClus(std::vector<std::vector< double > > Jetsp){
  float rmin = 10;
  std::vector<std::vector <double> > Jets1;
  std::vector<std::vector <double> > Jets2;
  std::vector <double> temp;
  Jets1.clear();
  Jets1 = Jetsp;
  int js = 0;
  std::vector<double> ht;
  for (unsigned int i=0;i<4;i++){
    ht.push_back(0.);
  }
  for(unsigned int i=0; i<Jets1.size(); i++){
    if(Jets1[i][1] > Jet_Pt_Cut){
      js++;
      ht[0]+=Jets1[i][1];
      ht[2]+=Jets1[i][2];
      ht[3]+=Jets1[i][3];
    }
  }
  ht[1]=sqrt(ht[2]*ht[2]+ht[3]*ht[3]);
  while( js > 2 ){
    //    Jets1.clear();
    Jets2.clear();
    int sel1 = 0;
    int sel2 = 0;
    double dimin = 1e09;
    double dijmin = 1e09;
    for (unsigned int i=0;i<Jets1.size();i++){
      double di = pow(Jets1[i][0],2);
      if(di < dimin){
	dimin = di;
	sel1 = i;
      }
    }
    for (unsigned int j=0;j<Jets1.size();j++){
      if((int)j != sel1){
	float etmin = 0;
	if(pow(Jets1[sel1][0],2) > pow(Jets1[j][0],2)) etmin = pow(Jets1[j][0],2);
	else etmin = pow(Jets1[sel1][0],2);
	float deltaeta = Jets1[sel1][5]-Jets1[j][5];
	float deltaphi = Jets1[sel1][6]-Jets1[j][6];
	float dr = deltaeta*deltaeta+deltaphi*deltaphi;
	double dij = etmin*dr/(rmin*rmin);
	if( dij < dijmin){
	  dijmin = dij;
	  sel2 = j;
	}
      }
    }
    rmin = sqrt(dijmin*rmin*rmin/dimin);
    for(unsigned int i= 0; i< Jets1.size(); i++ ){
      if((int)i == sel1){
	temp.clear();
	temp.push_back(Jets1[i][0]+Jets1[sel2][0]);
	temp.push_back(Jets1[i][1]+Jets1[sel2][1]);
	temp.push_back(Jets1[i][2]+Jets1[sel2][2]);
	temp.push_back(Jets1[i][2]+Jets1[sel2][3]);
	temp.push_back(Jets1[i][2]+Jets1[sel2][4]);
	temp.push_back((Jets1[i][0]*Jets1[i][5]+Jets1[sel2][0]*Jets1[sel2][5])/(Jets1[i][0]+Jets1[sel2][0]));
	temp.push_back((Jets1[i][0]*Jets1[i][6]+Jets1[sel2][0]*Jets1[sel2][6])/(Jets1[i][0]+Jets1[sel2][0]));
	Jets2.push_back(temp);
      }
      if((int)i != sel1 && (int)i != sel2)
	Jets2.push_back(Jets1[i]);
    }
    Jets1.clear();
    Jets1 = Jets2;
    js = 0;
    for(unsigned int i=0;i<Jets1.size();i++){
      double pt = sqrt(pow(Jets1[i][2],2)+pow(Jets1[i][3],2));
      if( pt > Jet_Pt_Cut && fabs(Jets1[i][5]) < 2.5){
	js++;
      }
    }
  }
  Jets2.clear();
  for(unsigned int j=0;j < Jets1.size();j++ ){
    double pt = sqrt(pow(Jets1[j][2],2)+pow(Jets1[j][3],2));
    if( pt > Jet_Pt_Cut &&  fabs(Jets1[j][5]) < 2.5)
      Jets2.push_back(Jets1[j]);
  }
  Jets1.clear();
  Jets1 = Jets2;
  Jets2.clear();
  float alphat2 = -1;
  float alphat3 = -1;
  float alphat4 = -1;
  if( Jets1.size() == 2){
    double pt1 = sqrt(pow(Jets1[0][2],2)+pow(Jets1[0][3],2));
    double pt2 = sqrt(pow(Jets1[1][2],2)+pow(Jets1[1][3],2));
    int may=0;
    int men=0;
    if(pt1<pt2)
      may = 1;
    else
      men =1;
    alphat2 = sqrt((Jets1[may][0])/(2*Jets1[men][0]*(1-cos(Jets1[may][6]-Jets1[men][6]))));
    double difht =  sqrt(pow(Jets1[may][2],2)+pow(Jets1[may][3],2)) -  sqrt(pow(Jets1[men][2],2)+pow(Jets1[men][3],2));
    alphat3 = 0.5*(ht[0]-difht)/(sqrt(ht[0]*ht[0]-ht[1]*ht[1]));
    float htp = sqrt(Jets1[0][2]*Jets1[0][2]+Jets1[0][3]*Jets1[0][3]) + sqrt(Jets1[1][2]*Jets1[1][2]+Jets1[1][3]*Jets1[1][3]);
    float njet_deltaht = fabs(sqrt(Jets1[may][3]*Jets1[may][3]+Jets1[may][2]*Jets1[may][2])-sqrt(Jets1[men][3]*Jets1[men][3]+Jets1[men][2]*Jets1[men][2]));
    float njet_mht = sqrt(pow(Jets1[may][3] + Jets1[men][3],2) + pow(Jets1[may][2] + Jets1[men][2],2));
    float num = htp - njet_deltaht;
    float den = sqrt(htp*htp-njet_mht*njet_mht);
    alphat4 = 0.5*num/den;
  }
  if(alphat2 == -1){
    temp.push_back(0.);
    temp.push_back(0.);
    Jets1.push_back(temp);
  }
  temp.clear();
  temp.push_back(alphat2);
  temp.push_back(alphat3);
  temp.push_back(alphat4);
  Jets1.push_back(temp);
  return Jets1;
}

std::vector< std::vector<double> >  SusyRead::AlphaT(std::vector<std::vector< double > > Jetsp){
  std::vector<double> njet_htvec;
  for(int i=0;i<5;i++){
    njet_htvec.push_back(0.);
  }
  std::vector<std::vector<double> > Jets;
  std::vector<double> pseudojet1;
  std::vector<double> pseudojet2;
  std::vector<std::vector<double> > pseudo;

  int jet_index_copy[50];
  int jet2_index_copy[50];

  for(int i=0;i<4;i++){
    pseudojet1.push_back(0.);
    pseudojet2.push_back(0.);
  }
  std::vector<double> temp;
  for(unsigned int i = 0; i<Jetsp.size(); i++ ){
    if(Jetsp[i][1] > Jet_Pt_Cut && fabs(Jetsp[i][5]) < 2.5){
      temp.push_back(Jetsp[i][0]);
      temp.push_back(Jetsp[i][1]);
      temp.push_back(Jetsp[i][2]);
      temp.push_back(Jetsp[i][3]);
      temp.push_back(Jetsp[i][4]);
      temp.push_back(Jetsp[i][5]);
      temp.push_back(Jetsp[i][6]);
      Jets.push_back(temp);
      njet_htvec[0] = njet_htvec[0] + temp[0];
      njet_htvec[1] = njet_htvec[1] + temp[1];
      njet_htvec[2] = njet_htvec[2] + temp[2];
      njet_htvec[3] = njet_htvec[3] + temp[3];
      njet_htvec[4] = njet_htvec[4] + temp[4];
      temp.clear();
    }
  }
  float temp_deltaht;
  //  float pt1,pt2,eta1,eta2,phi1,phi2;
  float njet_deltaht = 1e8;
  for(unsigned int n1=1;n1<=Jets.size()/2;n1++){
    int end_flag = 0;
    int jet_index[50];
    int jet2_index[50];
    for( int a=0; a<50; a++) jet_index[a] = -1;
    for(unsigned int a=0; a<n1; a++){
      jet_index[a] = n1-1-a;
    }
    jet_index[0] -= 1;
    while(end_flag==0){ //search all combinations for lowest deltaHT value
      jet_index[0]++;
      if((int)jet_index[0] == (int)Jets.size()){
	int carry=0;
	for(unsigned int a=1; a<n1; a++) {
	  if((int)jet_index[a] < (int)(Jets.size()-1-a)) { //find closest digit than can be incremented 
	    carry = a;
	    jet_index[a]++;
	  }
	}
	if(carry==0) {end_flag=1; continue;} //no more combinations
	for(int a=0; a<carry; a++) { //reset all previous digits; avoid double counting
	  jet_index[a] = jet_index[carry]+(carry-a);
	}
      }
      for(int k1 = 0; k1 < 50; k1++){
	jet2_index[k1]=-1;
      }
      for(unsigned int k1 = 0; k1 < Jets.size(); k1++){
	bool match=false;
	for(unsigned int k2 = 0; k2 < n1; k2++){
	  if((int)k1==jet_index[k2])
	    match = true;
	}
	if(!match)
	  jet2_index[k1]=k1;
      }
      //Compute deltaHT for given combination
      //	  float jet1_ht[5] = {0,0,0,0,0};
      std::vector<double> jet1_ht;
      std::vector<double> jet2_ht;
      for(int a=0;a<7;a++){
	jet1_ht.push_back(0.);
	jet2_ht.push_back(0.);
      }
      for(unsigned int a=0; a<n1; a++) {
	jet1_ht[0] += Jets[jet_index[a]][0];
	jet1_ht[1] += Jets[jet_index[a]][1];
	jet1_ht[2] += Jets[jet_index[a]][2];
	jet1_ht[3] += Jets[jet_index[a]][3];
	jet1_ht[4] += Jets[jet_index[a]][4];
	jet1_ht[5] += Jets[jet_index[a]][5]*Jets[jet_index[a]][0];
	jet1_ht[6] += Jets[jet_index[a]][6]*Jets[jet_index[a]][0];
      }
      jet1_ht[5]=jet1_ht[5]/jet1_ht[0];
      jet1_ht[6]=jet1_ht[6]/jet1_ht[0];
      //	  float jet2_ht[5] = {0,0,0,0,0};
      for(int k1=0; k1 < 50; k1++){
	if(jet2_index[k1]!=-1){
	  jet2_ht[5] += Jets[jet2_index[k1]][5]*Jets[jet2_index[k1]][0];
	  jet2_ht[6] += Jets[jet2_index[k1]][6]*Jets[jet2_index[k1]][0];
	  jet2_ht[0] += Jets[jet2_index[k1]][0];
	}
      }
      jet2_ht[5]=jet2_ht[5]/jet2_ht[0];
      jet2_ht[6]=jet2_ht[6]/jet2_ht[0];
      jet2_ht[0] = njet_htvec[0] - jet1_ht[0];
      jet2_ht[1] = njet_htvec[1] - jet1_ht[1];
      jet2_ht[2] = njet_htvec[2] - jet1_ht[2];
      jet2_ht[3] = njet_htvec[3] - jet1_ht[3];
      jet2_ht[4] = njet_htvec[4] - jet1_ht[4];
      //      temp_deltaht = fabs(sqrt(pow(jet1_ht[2],2)+pow(jet1_ht[3],2)) - sqrt(pow(jet2_ht[2],2)+pow(jet2_ht[3],2)));
      temp_deltaht = fabs(jet1_ht[1] - jet2_ht[1]);
      //save new deltaHT if it is smaller than previous smallest value                                                                       
      float temp1 = 0;
      float temp2 = 0;
      if(temp_deltaht < njet_deltaht) { 
	for(int l=0;l<50;l++){
	  jet_index_copy[l] =jet_index[l];
	  jet2_index_copy[l]=jet2_index[l];
	}
	njet_deltaht = temp_deltaht;
	//	temp1 = sqrt(pow(jet1_ht[0],2)+pow(jet1_ht[1],2));
	//	temp2 = sqrt(pow(jet2_ht[0],2)+pow(jet2_ht[1],2));
	temp1 = jet1_ht[1];
	temp2 = jet2_ht[1];
	if(temp1 > temp2){
	  //pseudojet1[1] = sqrt(pow(jet1_ht[2],2)+pow(jet1_ht[3],2));
	  //pseudojet2[1] = sqrt(pow(jet2_ht[2],2)+pow(jet2_ht[3],2));
	  pseudojet1[1] = jet1_ht[1];
	  pseudojet2[1] = jet2_ht[1];
	  pseudojet1[2] = jet1_ht[5];
	  pseudojet1[3] = jet1_ht[6];
	  pseudojet2[2] = jet2_ht[5];
	  pseudojet2[3] = jet2_ht[6];
	}
	else{
	  //pseudojet2[1] = sqrt(pow(jet1_ht[2],2)+pow(jet1_ht[3],2));
	  //pseudojet1[1] = sqrt(pow(jet2_ht[2],2)+pow(jet2_ht[3],2));
	  pseudojet1[1] = jet2_ht[1];
	  pseudojet2[1] = jet1_ht[1];
	  pseudojet2[2] = jet1_ht[5];
	  pseudojet2[3] = jet1_ht[6];
	  pseudojet1[2] = jet2_ht[5];
	  pseudojet1[3] = jet2_ht[6];
	}
      }
    } //end search all combinations for lowest deltaHT value 
  }
  //  std::cout << "the jets for the first pseudojet are: ";
  //  for(int k=0;k<50;k++){
  //    if(jet_index_copy[k] != -1)
  //      std::cout << " " << jet_index_copy[k]+1;
  //  }
  //  std::cout << std::endl;
  //  std::cout << "the jets for the second pseudojet are: ";
  //  for(int k=0;k<50;k++){
  //    if(jet2_index_copy[k] != -1)
  //      std::cout << " " << jet2_index_copy[k]+1;
  //  }
  //  std::cout << std::endl;

  //  std::cout << "Jet1: " << std::endl;
  //  std::cout << "\tpt " << pseudojet1[1] << std::endl;
  //  std::cout << "\teta " << pseudojet1[2] << std::endl;
  //  std::cout << "\tphi " << pseudojet1[3] << std::endl;
  //  std::cout << "Jet2: " << std::endl;
  //  std::cout << "\tpt " << pseudojet2[1] << std::endl;
  //  std::cout << "\teta " << pseudojet2[2] << std::endl;
  //  std::cout << "\tphi " << pseudojet2[3] << std::endl;
  //  std::cout << "Delta HT: " << temp_deltaht << std::endl;
  
  float num = njet_htvec[1] - njet_deltaht;
  float njet_mht = njet_htvec[2]*njet_htvec[2]+njet_htvec[3]*njet_htvec[3];
  float den = sqrt(njet_htvec[1]*njet_htvec[1]-njet_mht);
  float alphat = 0.5*num/den;
  pseudojet1[0] = alphat;
  pseudojet2[0] = alphat;
  pseudo.push_back(pseudojet1);
  pseudo.push_back(pseudojet2);
  return pseudo;
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

  fChain->SetBranchAddress("NPFJET", &NPFJET, &b_NPFJET);
  fChain->SetBranchAddress("PFJET_ET",PFJET_ET, &b_PFJET_ET);
  fChain->SetBranchAddress("PFJET_PT",PFJET_PT,&b_PFJET_PT);
  fChain->SetBranchAddress("PFJET_PX",PFJET_PX, &b_PFJET_PX);
  fChain->SetBranchAddress("PFJET_PY",PFJET_PY, &b_PFJET_PY);
  fChain->SetBranchAddress("PFJET_PZ",PFJET_PZ, &b_PFJET_PZ);
  fChain->SetBranchAddress("PFJET_ETA",PFJET_ETA, &b_PFJET_ETA);
  fChain->SetBranchAddress("PFJET_PHI",PFJET_PHI, &b_PFJET_PHI);
  fChain->SetBranchAddress("PFJET_energy",PFJET_energy, &b_PFJET_energy);

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
  fChain->SetBranchAddress("El_ecalIso",El_ecalIso,&b_El_ecalIso);
  fChain->SetBranchAddress("El_hcalIso",El_hcalIso,&b_El_hcalIso);
  fChain->SetBranchAddress("El_energy",El_energy,&b_El_energy);
  fChain->SetBranchAddress("El_trackIso",El_trackIso,&b_El_trackIso);

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
}
float SusyRead::dzero(float d0, float phi){
  return d0+0.0322* cos(phi);
}
