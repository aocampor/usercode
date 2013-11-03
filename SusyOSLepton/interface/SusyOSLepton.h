// -*- C++ -*-
//
// Package:    SusyOSLepton
// Class:      SusyOSLepton
// 
/**\class SusyOSLepton SusyOSLepton.cc SusyAnalyzers/SusyOSLepton/src/SusyOSLepton.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Alberto Andres Ocampo Rios
//         Created:  Fri May 15 17:30:01 CEST 2009
// $Id: SusyOSLepton.h,v 1.1 2009/11/26 20:55:04 aocampor Exp $
//
//


// system include files

#include <memory>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include <vector>
#include <map>
#include <set>
#include <iterator>


// user include files

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ParameterSet/interface/InputTag.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "PhysicsTools/UtilAlgos/interface/TFileService.h"

// from physics Tools:

#include "PhysicsTools/UtilAlgos/interface/TFileService.h"

// dataformats

#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Photon.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/Common/interface/View.h"

//Root

#include "TFile.h"
#include "TH1I.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH2D.h"
#include "TGaxis.h"
#include "TString.h"
#include "TCanvas.h"



//
// class decleration
//

class SusyOSLepton : public edm::EDAnalyzer {
   public:
  
  explicit SusyOSLepton(const edm::ParameterSet&);
  
  ~SusyOSLepton();
  
  TH1I* Pass;
  TH1I* Tot;
  TH1I* NumberOfJetsBC;
  TH1I* NumberOfMuonsBC;
  TH1I* OSMnoE_Only;
  TH1I* OSMnoE_3J;

  TH1F* MuonIsoBC;
  TH1F* MuonPtBC;
  TH1F* MuonEtaBC;
  TH1F* MuonChi2DoFBC;
  TH1F* Muond0BC;
  TH1F* MuonTrkFndBC;
  TH1F* MuonHCalIsoDepBC;
  TH1F* MuonECalIsoDepBC;

  TH1F* JetPtBC;
  TH1F* JetEtaBC;
  TH1F* JetEMFBC;

  TH1I* NumberOfJetsAC;
  TH1I* NumberOfMuonsAC;
  TH1I* NumberHighPtJets;

  std::vector<TH1F*> MuonPt;
  std::vector<TH1F*> MuonEta;
  std::vector<TH1F*> MuonIso;
  std::vector<TH1F*> Muond0;
  std::vector<TH1F*> MuonChiDoF;
  std::vector<TH1F*> MuonValidHits;
  std::vector<TH1F*> MuonHCalE;
  std::vector<TH1F*> MuonECalE;

  std::vector<TH1F*> JetPt;
  std::vector<TH1F*> JetEta;
  std::vector<TH1F*> JetEMF;

  TH1F* METEtBC;
  TH1F* METEt;
  
  edm::InputTag MuonInputTag;
  edm::InputTag ElectronInputTag;
  edm::InputTag JetInputTag;
  edm::InputTag MetInputTag;

  std::vector<unsigned> CutsMask;

  float MuonIsoCut;
  float MuonPtCut;
  float MuonEtaCut;
  float MuonChiDoFCut;
  float Muond0Cut;
  float MuonHCalECut;
  float MuonECalECut;

  float ElecPtCut;
  float ElecEtaCut;
  float ElecIsoCut;
  float Elecd0Cut;

  float METCut;
  float JetPtCut;
  float JetEtaCut;
  float JetEMFCut;

  int MuonTrkCut;
  int ElectronCut;

  unsigned JetNumCut;

  int PF2PAT_var;
private:

  virtual void beginJob(const edm::EventSetup&) ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  int passCount;
  
  // ----------member data ---------------------------

};

