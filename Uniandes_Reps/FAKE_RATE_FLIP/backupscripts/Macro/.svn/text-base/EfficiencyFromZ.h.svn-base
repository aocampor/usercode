//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Aug 25 18:50:58 2010 by ROOT version 5.22/00d
// from TTree fitter_tree/fitter_tree
// found on file: testNewWrite.root
//////////////////////////////////////////////////////////

#ifndef EfficiencyFromZ_h
#define EfficiencyFromZ_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

class EfficiencyFromZ {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types

   Float_t         probe_sc_et;
   Float_t         probe_sc_eta; 
   Float_t         probe_sc_phi;
   Int_t           probe_passing;
   Int_t           probe_passingALL;
   Int_t           probe_passingGsf;
   Int_t           probe_passingId;
   Int_t           probe_passingIso;
   Float_t         probe_gsfEle_et;
   Float_t         probe_gsfEle_eta;
   Float_t         probe_gsfEle_phi;
   Float_t         probe_gsfEle_pt;   
   Float_t         probe_gsfEle_ecaliso_dr04;   
   Float_t         probe_gsfEle_hcaliso_dr04;   
   Float_t         probe_gsfEle_trackiso_dr04;   
   Float_t         probe_gsfEle_isEB;
   Float_t         probe_gsfEle_isEE;
   Float_t         probe_sigmaietaieta;
   Float_t         probe_dphi;
   Float_t         probe_deta;
   Float_t         probe_hovere;
   Float_t         probe_dcot;
   Float_t         probe_dist;
   Float_t         probe_gsfcharge;
   Float_t         probe_kfcharge;
   Float_t         probe_nmisshits;
   Float_t         probe_sccharge;
   Float_t         tag_gsfEle_et;
   Float_t         tag_gsfEle_eta;
   Float_t         tag_gsfEle_phi;
   Float_t         tag_gsfEle_deltaPhi;
   Float_t         tag_gsfEle_bremFraction;
   Float_t         tag_gsfEle_charge;
   Float_t         pair_mass;


   // List of branches

   TBranch        *b_probe_sc_et;   //!
   TBranch        *b_probe_sc_eta;   //! 
   TBranch        *b_probe_sc_phi;   //!
   TBranch        *b_probe_passing;   //!
   TBranch        *b_probe_passingALL;   //!
   TBranch        *b_probe_passingGsf;   //!
   TBranch        *b_probe_passingId;   //!
   TBranch        *b_probe_passingIso;   //!
   TBranch        *b_probe_gsfEle_et;   //!
   TBranch        *b_probe_gsfEle_phi;   //!
   TBranch        *b_probe_gsfEle_pt;   //!
   TBranch        *b_probe_gsfEle_eta;   //!
   TBranch        *b_probe_gsfEle_ecaliso_dr04;   //!
   TBranch        *b_probe_gsfEle_hcaliso_dr04;   //!
   TBranch        *b_probe_gsfEle_trackiso_dr04;   //!
   TBranch        *b_probe_gsfEle_isEE;   //!
   TBranch        *b_probe_gsfEle_isEB;   //!
   TBranch        *b_probe_sigmaietaieta;   //!
   TBranch        *b_probe_dphi;   //!
   TBranch        *b_probe_deta;   //!
   TBranch        *b_probe_hovere;   //!
   TBranch        *b_probe_dcot;   //!
   TBranch        *b_probe_dist;   //!
   TBranch        *b_probe_gsfcharge;   //!
   TBranch        *b_probe_kfcharge;   //!
   TBranch        *b_probe_nmisshits;   //!
   TBranch        *b_probe_sccharge;   //!
   TBranch        *b_tag_gsfEle_et;   //!
   TBranch        *b_tag_gsfEle_eta;   //!
   TBranch        *b_tag_gsfEle_phi;   //!
   TBranch        *b_tag_gsfEle_charge;   //!
   TBranch        *b_tag_gsfEle_deltaPhi;
   TBranch        *b_tag_gsfEle_bremFraction;
   TBranch        *b_pair_mass;   //!


   EfficiencyFromZ(TTree *tree=0);
   virtual ~EfficiencyFromZ();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
 private:
   bool sc_;
};

#endif

#ifdef EfficiencyFromZ_cxx
EfficiencyFromZ::EfficiencyFromZ(TTree *tree, bool sc=true):
  sc_(sc)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("ciccio.root");
      if (!f) {
	//f = new TFile("../../root_files/Ju_Zdata.root");
	f = new TFile("../../root_files/temp_data.root");
        // f = new TFile("../../root_files/TagAndProbe_Tree.root");
	if (sc_) f->cd("ZZZ.root:/SCToGsf");
	else  f->cd("../../root_files/temp_data.root:/GsfToIso");
      }
      tree = (TTree*)gDirectory->Get("fitter_tree");

   }
   Init(tree);
}

EfficiencyFromZ::~EfficiencyFromZ()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t EfficiencyFromZ::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t EfficiencyFromZ::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (!fChain->InheritsFrom(TChain::Class()))  return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void EfficiencyFromZ::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("probe_sc_et", &probe_sc_et, &b_probe_sc_et);
   fChain->SetBranchAddress("probe_sc_eta", &probe_sc_eta, &b_probe_sc_eta);
   fChain->SetBranchAddress("probe_sc_phi", &probe_sc_phi, &b_probe_sc_phi);
   fChain->SetBranchAddress("probe_passing", &probe_passing, &b_probe_passing);
   fChain->SetBranchAddress("probe_passingALL", &probe_passingALL, &b_probe_passingALL);
   if(sc_)   fChain->SetBranchAddress("probe_passingGsf", &probe_passingGsf, &b_probe_passingGsf);
   fChain->SetBranchAddress("probe_passingId", &probe_passingId, &b_probe_passingId);
   fChain->SetBranchAddress("probe_passingIso", &probe_passingIso, &b_probe_passingIso);
   if (!sc_){
     fChain->SetBranchAddress("probe_gsfEle_et", &probe_gsfEle_et, &b_probe_gsfEle_et);
     fChain->SetBranchAddress("probe_gsfEle_eta", &probe_gsfEle_eta, &b_probe_gsfEle_eta);
     fChain->SetBranchAddress("probe_gsfEle_phi", &probe_gsfEle_phi, &b_probe_gsfEle_phi);
     fChain->SetBranchAddress("probe_gsfEle_pt", &probe_gsfEle_pt, &b_probe_gsfEle_pt);
     fChain->SetBranchAddress("probe_gsfEle_ecaliso_dr04", &probe_gsfEle_ecaliso_dr04, &b_probe_gsfEle_ecaliso_dr04);
     fChain->SetBranchAddress("probe_gsfEle_hcaliso_dr04", &probe_gsfEle_hcaliso_dr04, &b_probe_gsfEle_hcaliso_dr04);
     fChain->SetBranchAddress("probe_gsfEle_trackiso_dr04", &probe_gsfEle_trackiso_dr04, &b_probe_gsfEle_trackiso_dr04);
     fChain->SetBranchAddress("probe_gsfEle_isEE", &probe_gsfEle_isEE, &b_probe_gsfEle_isEE);
     fChain->SetBranchAddress("probe_gsfEle_isEB", &probe_gsfEle_isEB, &b_probe_gsfEle_isEB);
     fChain->SetBranchAddress("probe_gsfEle_sigmaIetaIeta", &probe_sigmaietaieta, &b_probe_sigmaietaieta);
     fChain->SetBranchAddress("probe_gsfEle_deltaPhi", &probe_dphi, &b_probe_dphi);
     fChain->SetBranchAddress("probe_gsfEle_deltaEta", &probe_deta, &b_probe_deta);
     fChain->SetBranchAddress("probe_gsfEle_HoverE", &probe_hovere, &b_probe_hovere);
     fChain->SetBranchAddress("probe_dcot", &probe_dcot, &b_probe_dcot);
     fChain->SetBranchAddress("probe_dist", &probe_dist, &b_probe_dist);
     fChain->SetBranchAddress("probe_gsfcharge", &probe_gsfcharge, &b_probe_gsfcharge);
     fChain->SetBranchAddress("probe_kfcharge", &probe_kfcharge, &b_probe_kfcharge);
     fChain->SetBranchAddress("probe_nmisshits", &probe_nmisshits, &b_probe_nmisshits);
     fChain->SetBranchAddress("probe_sccharge", &probe_sccharge, &b_probe_sccharge);
   }
   fChain->SetBranchAddress("tag_gsfEle_et", &tag_gsfEle_et, &b_tag_gsfEle_et);
   fChain->SetBranchAddress("tag_gsfEle_eta", &tag_gsfEle_eta, &b_tag_gsfEle_eta);
   fChain->SetBranchAddress("tag_gsfEle_phi", &tag_gsfEle_phi, &b_tag_gsfEle_phi);   
   fChain->SetBranchAddress("tag_gsfEle_charge", &tag_gsfEle_charge, &b_tag_gsfEle_charge);
   fChain->SetBranchAddress("tag_gsfEle_deltaPhi", &tag_gsfEle_deltaPhi, &b_tag_gsfEle_deltaPhi);  
   fChain->SetBranchAddress("tag_gsfEle_bremFraction", &tag_gsfEle_bremFraction, &b_tag_gsfEle_bremFraction);  
   fChain->SetBranchAddress("pair_mass", &pair_mass, &b_pair_mass);

   Notify();
}

Bool_t EfficiencyFromZ::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void EfficiencyFromZ::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t EfficiencyFromZ::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef EfficiencyFromZ_cxx
