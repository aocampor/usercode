////Root includes
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
#include "TMath.h"
#include "TCanvas.h"
#include <iostream>
#include <fstream>

///Class Definition
class IsolOpt {
public :
  TTree  *fChain;   //!pointer to the analyzed TTree or TChain 
  Int_t  fCurrent; //!current Tree number in a TChain

  // Declaration of leaf types
  UInt_t Run,Event,Lumi;
  UInt_t Jet15, Jet30, Jet50, HT100, EG2;
  Double_t PFHT;
  Double_t pfjetPt[70],pfjetEta[70],pfjetPhi[70],calomuPt[70],calomuEta[70],calomuPhi[70];
  UInt_t pfNjets, NCaloMu;

  UInt_t  pfNbtagjets;
  Double_t pfbtagjetPt[70];
  Double_t pfbtagjetEta[70];
  Double_t  pfbtagjetPhi[70];
  Double_t pfbtagjetDisc[70];

  UInt_t pfNel;
  Double_t pfelPt[70];
  Double_t pfelPhi[70];
  Double_t pfelEta[70];
  Double_t pfelhoe[70];
  Double_t elIdPfpi[70];
  Double_t elIsoGamma[70];
  Double_t elIsoNHad[70];
  Double_t elIsoChHad[70];
  Double_t pfelGsfCharge[70];
  Double_t pfelKfCharge[70];

  Double_t pfelD0[70];
  Double_t pfelMC[70];

  UInt_t pfNelfake;
  Double_t pfelfakeMVA[70];
  Double_t pfelfakeEta[70];
  Double_t pfelfakePhi[70];

  UInt_t pfNelc;
  Double_t pfelcanMVA[70];
  Double_t pfelcanEta[70];
  Double_t pfelcanPhi[70];
  Double_t pfelcanPt[70];
  UInt_t pfelcanIsKF[70];
  UInt_t pfelcanNumInnerTHits[70];
  UInt_t pfelcanNumValidPHits[70];
  UInt_t pfelcanNumLostPHits[70];
  UInt_t pfelcanGSFHits[70];
  UInt_t pfelcanIsConv[70];
  Double_t pfelcanGSFd0[70];
  Double_t pfelcanGSFdz[70];
  Double_t pfelcanPx[70];
  Double_t pfelcanPy[70];
  Double_t pfelcanPz[70];
  Double_t pfelcanEnergy[70];
  Double_t pfelcanGSFpx[70];
  Double_t pfelcanGSFpy[70];
  Double_t pfelcanGSFpz[70];
  Double_t pfelcanGSFEnergy[70];
  Double_t pfelcanKFPx[70];
  Double_t pfelcanKFPy[70];
  Double_t pfelcanKFPz[70];
  Double_t pfelcanKFEnergy[70];
  Double_t pfelcanVProb[4900];
  Double_t pfelcanVd0[4900];
  Double_t pfelcanCharge[70];

  UInt_t Npfmu;
  Double_t pfmuPt[70];
  Double_t pfmuPhi[70];
  Double_t pfmuEta[70];
  Double_t muIsoGamma[70];
  Double_t muIsoNHad[70];
  Double_t muIsoChHad[70];
  Double_t pfmuIsTracker[70];
  Double_t pfmuIsGlobal[70];
  Double_t pfmuCharge[70];
  Double_t pfmuD0[70];
  Double_t pfmuTkHits[70];
  Double_t pfmuGlobChi2[70];
  Double_t pfmuMC[70];

  UInt_t Nmu;
  Double_t muPt[70];
  Double_t muPhi[70];
  Double_t muEta[70];
  Double_t muIsTracker[70];
  Double_t muIsGlobal[70];
  Double_t muCharge[70];
  Double_t muD0[70];
  Double_t muPx[70];
  Double_t muPy[70];
  Double_t muPz[70];
  Double_t muEnergy[70];
  Double_t muVProb[4900];
  Double_t muVd0[4900];

  TBranch *b_Run, *b_Event, *b_Lumi;
  TBranch *b_Jet15, *b_Jet30, *b_Jet50, *b_HT100, *b_EG2;
  TBranch *b_PFHT,*b_pfNjets,*b_NCaloMu;
  TBranch *b_pfjetPt,*b_pfjetEta,*b_pfjetPhi,*b_calomuPt,*b_calomuEta,*b_calomuPhi;

  TBranch *b_pfNbtagjets;
  TBranch *b_pfbtagjetPt;
  TBranch *b_pfbtagjetEta;
  TBranch *b_pfbtagjetPhi;
  TBranch *b_pfbtagjetDisc;

  TBranch *b_pfNel;
  TBranch *b_pfelPt;
  TBranch *b_pfelPhi;
  TBranch *b_pfelEta;
  TBranch *b_pfelhoe;
  TBranch *b_elIdPfpi;
  TBranch *b_elIsoGamma;
  TBranch *b_elIsoNHad;
  TBranch *b_elIsoChHad;
  TBranch *b_pfelGsfCharge;
  TBranch *b_pfelKfCharge;

  TBranch *b_pfelD0;
  TBranch *b_pfelMC;

  TBranch *b_pfNelfake;
  TBranch *b_pfelfakeMVA;
  TBranch *b_pfelfakeEta;
  TBranch *b_pfelfakePhi;

  TBranch *b_pfNelc;
  TBranch *b_pfelcanMVA;
  TBranch *b_pfelcanEta;
  TBranch *b_pfelcanPhi;
  TBranch *b_pfelcanPt;
  TBranch *b_pfelcanIsKF;
  TBranch *b_pfelcanNumInnerTHits;
  TBranch *b_pfelcanNumValidPHits;
  TBranch *b_pfelcanNumLostPHits;
  TBranch *b_pfelcanGSFHits;
  TBranch *b_pfelcanIsConv;
  TBranch *b_pfelcanGSFd0;
  TBranch *b_pfelcanGSFdz;
  TBranch *b_pfelcanPx;
  TBranch *b_pfelcanPy;
  TBranch *b_pfelcanPz;
  TBranch *b_pfelcanEnergy;
  TBranch *b_pfelcanGSFpx;
  TBranch *b_pfelcanGSFpy;
  TBranch *b_pfelcanGSFpz;
  TBranch *b_pfelcanGSFEnergy;
  TBranch *b_pfelcanKFPx;
  TBranch *b_pfelcanKFPy;
  TBranch *b_pfelcanKFPz;
  TBranch *b_pfelcanKFEnergy;
  TBranch *b_pfelcanVProb;
  TBranch *b_pfelcanVd0;
  TBranch *b_pfelcanCharge;

  TBranch *b_Npfmu;
  TBranch *b_pfmuPt;
  TBranch *b_pfmuPhi;
  TBranch *b_pfmuEta;
  TBranch *b_muIsoGamma;
  TBranch *b_muIsoNHad;
  TBranch *b_muIsoChHad;
  TBranch *b_pfmuIsTracker;
  TBranch *b_pfmuIsGlobal;
  TBranch *b_pfmuCharge;
  TBranch *b_pfmuD0;
  TBranch *b_pfmuTkHits;
  TBranch *b_pfmuGlobChi2;
  TBranch *b_pfmuMC;

  TBranch *b_Nmu;
  TBranch *b_muPt;
  TBranch *b_muPhi;
  TBranch *b_muEta;
  TBranch *b_muIsTracker;
  TBranch *b_muIsGlobal;
  TBranch *b_muCharge;
  TBranch *b_muD0;
  TBranch *b_muPx;
  TBranch *b_muPy;
  TBranch *b_muPz;
  TBranch *b_muEnergy;
  TBranch *b_muVProb;
  TBranch *b_muVd0;

//functions, constructors and destructors
  
  IsolOpt(TTree *tree=0);

  virtual ~IsolOpt();

  virtual Int_t    GetEntry(Long64_t entry);
  virtual Long64_t LoadTree(Long64_t entry);
  virtual void     Init(TTree *tree);
  virtual void     Loop();
  //  virtual void     PFLoop();
  virtual Bool_t   Notify();
  virtual void     Show(Long64_t entry = -1);

  float dzero(float, float);
  float invmass(float,float,float,float,float,float,float,float);

  //output file
  TFile *f2;

};

int main(int argc, char *argv[]){
  std::cout << "Begining!!!!" << std::endl;
  std::cout << "input : " << argv[1] <<  std::endl;
  TFile * f1 = new TFile(argv[1]);
  f1->cd("demo");
  ///////
  TTree * g1 = (TTree*)gDirectory->FindObjectAny("allData");
  IsolOpt * iso = new IsolOpt(g1);
  iso->Loop();
  return 0;
}

void IsolOpt::Loop(){
  ///////////configuration variables
  bool print = false;
  double HT_cut = 0;

  ///getting the entries
  if (fChain == 0) return; 
  Long64_t nentries = fChain->GetEntriesFast();   
  cout<<"EVENTS "<< nentries<<endl; 
  Long64_t nbytes = 0, nb = 0; 
  int srfel = 0;
  int pffel = 0;
  ////Loop over the tree
  for (Long64_t jentry=0; jentry<nentries; jentry++) {
    if (jentry%1000 ==0) cout<<jentry<<" EVENTS ANALYZED"<<endl; 
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;      
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    if(print) cout << "PF HT: "<< PFHT << endl;
    if(PFHT > HT_cut){
      for(unsigned int i = 0; i<pfNelc;i++){
	if(print) cout << i+1 << " pf El MVA: "<< pfelcanMVA[i] << endl;
	if(pfelcanMVA[i] < -1.0)
	  continue;
	if(print) cout << "pf El conv: "<< pfelcanIsConv[i] << endl;
	if(pfelcanIsConv[i] == 1)
	  continue;
	if(print) cout << "pf El nlost pixel hits: "<< pfelcanNumLostPHits[i] << endl;
	if(pfelcanNumLostPHits[i] > 1)
	  continue;
	for(unsigned int j = 0; j<pfNelc;j++){
	  if(print) cout << j+1 << " pf El MVA: "<< pfelcanMVA[j] << endl;
	  if(pfelcanMVA[j] < -1.0)
	    continue;
	  if(print) cout << "pf El conv: "<< pfelcanIsConv[j] << endl;
	  if(pfelcanIsConv[j] == 1)
	    continue;
	  if(print) cout << "pf El nlost pixel hits: "<< pfelcanNumLostPHits[j] << endl;
	  if(pfelcanNumLostPHits[j] > 1)
	    continue;
	  if(print) cout << i << " " << j << " pf vprob: "<< pfelcanVProb[pfNelc*i+j] << endl;
	  if(pfelcanVProb[pfNelc*i+j] < 0.1)
	    continue;
	  if(print) cout << "checking charges " << pfelcanCharge[i] << " " << pfelcanCharge[j] << endl;
	  if(pfelcanCharge[i] == pfelcanCharge[j])
	    continue;
	  float im = invmass(pfelcanEnergy[i],pfelcanPx[i],pfelcanPy[i],pfelcanPz[i],
		  pfelcanEnergy[j],pfelcanPx[j],pfelcanPy[j],pfelcanPz[j]);
	  cout << "Invariant mass electrons " << im << endl; 
	}
      }

      if(print) cout << "Run: " << Run << " Event: " << Event << " Lumi: " << Lumi << endl; 
      if(Nmu > 50)
	if(print) cout << "Number of muons: " << NCaloMu << endl;
      for(unsigned int i =0; i< pfNelc; i++){
	for(unsigned int j =0; j< pfNelc; j++){
	  if(print) cout << "\t pfel vprob " << pfelcanVProb[pfNelc*i+j] << " vd0: " << pfelcanVd0[pfNelc*i+j] << " pt " << i+1 << " " << pfelcanPt[i] << " pt " << j+1<< " " << pfelcanPt[j] << endl;
	} 
      }
    }
  }
  f2->Close();

}

float IsolOpt::invmass(float e1,float px1,float py1,float pz1,float e2,float px2,float py2,float pz2){
  return sqrt(e1*e2-px1*px2-py1*py2-pz1*pz2);
}
float IsolOpt::dzero(float d0, float phi){
  return d0+0.0322* cos(phi);
}

IsolOpt::IsolOpt(TTree *tree)
{
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.
  if (tree == 0) {
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../prov1a.root");
    if (!f) {
      f = new TFile("/Users/aocampor/Desktop/PAT_vs_PF/root_files/nutples/LM0_pfandpat_ntuple.root");
      f->cd("/Users/aocampor/Desktop/PAT_vs_PF/root_files/nutples/LM0_pfandpat_ntuple.root:/demo");
    }
    tree = (TTree*)gDirectory->Get("allData");

  }
  Init(tree);
  f2=new TFile("bbb.root","recreate");
}

IsolOpt::~IsolOpt()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

Int_t IsolOpt::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}
Long64_t IsolOpt::LoadTree(Long64_t entry)
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

void IsolOpt::Init(TTree *tree)
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

  fChain->SetBranchAddress("run", &Run, &b_Run);
  fChain->SetBranchAddress("event", &Event, &b_Event);
  fChain->SetBranchAddress("lumi", &Lumi, &b_Lumi);
  fChain->SetBranchAddress("is_jet15", &Jet15, &b_Jet15);
  fChain->SetBranchAddress("is_jet30", &Jet30, &b_Jet30);
  fChain->SetBranchAddress("is_jet50U", &Jet50, &b_Jet50);
  fChain->SetBranchAddress("is_HT100", &HT100, &b_HT100);
  fChain->SetBranchAddress("is_EG2", &EG2, &b_EG2);
  fChain->SetBranchAddress("pfHt", &PFHT, &b_PFHT);
  fChain->SetBranchAddress("pfNjets", &pfNjets, &b_pfNjets);
  fChain->SetBranchAddress("pfjetPt",pfjetPt , &b_pfjetPt);
  fChain->SetBranchAddress("pfjetEta", pfjetEta, &b_pfjetEta);
  fChain->SetBranchAddress("pfjetPhi", pfjetPhi , &b_pfjetPhi);
  fChain->SetBranchAddress("NCaloMu", &NCaloMu, &b_NCaloMu);
  fChain->SetBranchAddress("calomuPt", calomuPt, &b_calomuPt);
  fChain->SetBranchAddress("calomuEta", calomuEta, &b_calomuEta);
  fChain->SetBranchAddress("calomuPhi", calomuPhi, &b_calomuPhi);

  fChain->SetBranchAddress("pfNbtagjets",&pfNbtagjets,&b_pfNbtagjets);
  fChain->SetBranchAddress("pfbtagjetPt",pfbtagjetPt, &b_pfbtagjetPt);
  fChain->SetBranchAddress("pfbtagjetEta",pfbtagjetEta,&b_pfbtagjetEta);
  fChain->SetBranchAddress("pfbtagjetPhi",pfbtagjetPhi,&b_pfbtagjetPhi);
  fChain->SetBranchAddress("pfbtagjetDisc",pfbtagjetDisc,&b_pfbtagjetDisc);

  fChain->SetBranchAddress("pfNel",&pfNel,&b_pfNel);
  fChain->SetBranchAddress("pfelPt",pfelPt,&b_pfelPt);
  fChain->SetBranchAddress("pfelPhi",pfelPhi,&b_pfelPhi);
  fChain->SetBranchAddress("pfelEta",pfelEta,&b_pfelEta);
  fChain->SetBranchAddress("pfelhoe",pfelhoe,&b_pfelhoe);
  fChain->SetBranchAddress("elIdPfpi",elIdPfpi,&b_elIdPfpi);
  fChain->SetBranchAddress("elIsoGamma",elIsoGamma,&b_elIsoGamma);
  fChain->SetBranchAddress("elIsoNHad",elIsoNHad,&b_elIsoNHad);
  fChain->SetBranchAddress("elIsoChHad",elIsoChHad,&b_elIsoChHad);
  fChain->SetBranchAddress("pfelGsfCharge",pfelGsfCharge,&b_pfelGsfCharge);
  fChain->SetBranchAddress("pfelKfCharge",pfelKfCharge,&b_pfelKfCharge);

  fChain->SetBranchAddress("pfelD0",pfelD0,&b_pfelD0);
  fChain->SetBranchAddress("pfelMC",pfelMC,&b_pfelMC);

  fChain->SetBranchAddress("pfNelfake",&pfNelfake,&b_pfNelfake);
  fChain->SetBranchAddress("pfelfakeMVA",pfelfakeMVA,&b_pfelfakeMVA);
  fChain->SetBranchAddress("pfelfakeEta",pfelfakeEta,&b_pfelfakeEta);
  fChain->SetBranchAddress("pfelfakePhi",pfelfakePhi,&b_pfelfakePhi);

  fChain->SetBranchAddress("pfNelc",&pfNelc,&b_pfNelc);
  fChain->SetBranchAddress("pfelcanMVA",pfelcanMVA,&b_pfelcanMVA);
  fChain->SetBranchAddress("pfelcanEta",pfelcanEta,&b_pfelcanEta);
  fChain->SetBranchAddress("pfelcanPhi",pfelcanPhi,&b_pfelcanPhi);
  fChain->SetBranchAddress("pfelcanPt",pfelcanPt,&b_pfelcanPt);
  fChain->SetBranchAddress("pfelcanIsKF",pfelcanIsKF,&b_pfelcanIsKF);
  fChain->SetBranchAddress("pfelcanNumInnerTHits",pfelcanNumInnerTHits,&b_pfelcanNumInnerTHits);
  fChain->SetBranchAddress("pfelcanNumValidPHits",pfelcanNumValidPHits,&b_pfelcanNumValidPHits);
  fChain->SetBranchAddress("pfelcanNumLostPHits",pfelcanNumLostPHits,&b_pfelcanNumLostPHits);
  fChain->SetBranchAddress("pfelcanGSFHits",pfelcanGSFHits,&b_pfelcanGSFHits);
  fChain->SetBranchAddress("pfelcanIsConv",pfelcanIsConv,&b_pfelcanIsConv);
  fChain->SetBranchAddress("pfelcanGSFd0",pfelcanGSFd0,&b_pfelcanGSFd0);
  fChain->SetBranchAddress("pfelcanGSFdz",pfelcanGSFdz,&b_pfelcanGSFdz);
  fChain->SetBranchAddress("pfelcanPx",pfelcanPx,&b_pfelcanPx);
  fChain->SetBranchAddress("pfelcanPy",pfelcanPy,&b_pfelcanPy);
  fChain->SetBranchAddress("pfelcanPz",pfelcanPz,&b_pfelcanPz);
  fChain->SetBranchAddress("pfelcanEnergy",pfelcanEnergy,&b_pfelcanEnergy);
  fChain->SetBranchAddress("pfelcanGSFpx",pfelcanGSFpx,&b_pfelcanGSFpx);
  fChain->SetBranchAddress("pfelcanGSFpy",pfelcanGSFpy,&b_pfelcanGSFpy);
  fChain->SetBranchAddress("pfelcanGSFpz",pfelcanGSFpz,&b_pfelcanGSFpz);
  fChain->SetBranchAddress("pfelcanGSFEnergy",pfelcanGSFEnergy,&b_pfelcanGSFEnergy);
  fChain->SetBranchAddress("pfelcanKFPx",pfelcanKFPx,&b_pfelcanKFPx);
  fChain->SetBranchAddress("pfelcanKFPy",pfelcanKFPy,&b_pfelcanKFPy);
  fChain->SetBranchAddress("pfelcanKFPz",pfelcanKFPz,&b_pfelcanKFPz);
  fChain->SetBranchAddress("pfelcanKFEnergy",pfelcanKFEnergy,&b_pfelcanKFEnergy);
  fChain->SetBranchAddress("pfelcanVProb",pfelcanVProb,&b_pfelcanVProb);
  fChain->SetBranchAddress("pfelcanVd0",pfelcanVd0,&b_pfelcanVd0);
  fChain->SetBranchAddress("pfelcanCharge",pfelcanCharge,&b_pfelcanCharge);

  fChain->SetBranchAddress("Npfmu",&Npfmu,&b_Npfmu);
  fChain->SetBranchAddress("pfmuPt",pfmuPt,&b_pfmuPt);
  fChain->SetBranchAddress("pfmuPhi",pfmuPhi,&b_pfmuPhi);
  fChain->SetBranchAddress("pfmuEta",pfmuEta,&b_pfmuEta);
  fChain->SetBranchAddress("muIsoGamma",muIsoGamma,&b_muIsoGamma);
  fChain->SetBranchAddress("muIsoNHad",muIsoNHad,&b_muIsoNHad);
  fChain->SetBranchAddress("muIsoChHad",muIsoChHad,&b_muIsoChHad);
  fChain->SetBranchAddress("pfmuIsTracker",pfmuIsTracker,&b_pfmuIsTracker);
  fChain->SetBranchAddress("pfmuIsGlobal",pfmuIsGlobal,&b_pfmuIsGlobal);
  fChain->SetBranchAddress("pfmuCharge",pfmuCharge,&b_pfmuCharge);
  fChain->SetBranchAddress("pfmuD0",pfmuD0,&b_pfmuD0);
  fChain->SetBranchAddress("pfmuTkHits",pfmuTkHits,&b_pfmuTkHits);
  fChain->SetBranchAddress("pfmuGlobChi2",pfmuGlobChi2,&b_pfmuGlobChi2);
  fChain->SetBranchAddress("pfmuMC",pfmuMC,&b_pfmuMC);

  fChain->SetBranchAddress("Nmu",&Nmu,&b_Nmu);
  fChain->SetBranchAddress("muPt",muPt,&b_muPt);
  fChain->SetBranchAddress("muPhi",muPhi,&b_muPhi);
  fChain->SetBranchAddress("muEta",muEta,&b_muEta);
  fChain->SetBranchAddress("muIsTracker",muIsTracker,&b_muIsTracker);
  fChain->SetBranchAddress("muIsGlobal",muIsGlobal,&b_muIsGlobal);
  fChain->SetBranchAddress("muCharge",muCharge,&b_muCharge);
  fChain->SetBranchAddress("muD0",muD0,&b_muD0);
  fChain->SetBranchAddress("muPx",muPx,&b_muPx);
  fChain->SetBranchAddress("muPy",muPy,&b_muPy);
  fChain->SetBranchAddress("muPz",muPz,&b_muPz);
  fChain->SetBranchAddress("muEnergy",muEnergy,&b_muEnergy);
  fChain->SetBranchAddress("muVProb",muVProb,&b_muVProb);
  fChain->SetBranchAddress("muVd0",muVd0,&b_muVd0);

  Notify();
}

Bool_t IsolOpt::Notify()
{
  // The Notify() function is called when a new file is opened. This 
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.
  return kTRUE;
}

void IsolOpt::Show(Long64_t entry)
{
  // Print contents of entry.                               
  // If entry is not specified, print current entry 
  if (!fChain) return;
  fChain->Show(entry);
}
/*
Int_t IsolOpt::Cut(Long64_t entry)
{
  // This function may be called from Loop.                                                                                                                                                                        
  // returns  1 if entry is accepted.                                                                                                                                                                              
  // returns -1 otherwise.                                                                                                                                                                                         
  return 1;
}
*/
