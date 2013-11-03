// -*- C++ -*-
//
// Package:    SUSYEVFILT
// Class:      SUSYEVFILT
// 
/**\class SUSYEVFILT SUSYEVFILT.cc SUSY/SUSYEVFILT/src/SUSYEVFILT.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  
//         Created:  Wed Jun  2 11:29:33 CEST 2010
// $Id$
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDFilter.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidateFwd.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/EgammaReco/interface/ElectronSeedFwd.h"
#include "DataFormats/EgammaReco/interface/ElectronSeed.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "TTree.h"
#include "TH1F.h"
#include "TNtuple.h"
#include "TLorentzVector.h"

//
// class declaration
//

  using namespace edm;
  using namespace std;
  using namespace reco;
  using namespace pat;

class SUSYEVFILT : public edm::EDFilter {
   public:
      explicit SUSYEVFILT(const edm::ParameterSet&);
      ~SUSYEVFILT();

   private:
      virtual void beginJob() ;
      virtual bool filter(edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

      ParameterSet conf_;      
      // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
SUSYEVFILT::SUSYEVFILT(const edm::ParameterSet& iConfig): conf_(iConfig)
{
   //now do what ever initialization is needed

}


SUSYEVFILT::~SUSYEVFILT()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called on each new Event  ------------
bool
SUSYEVFILT::filter(edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  std::cout << "EVENTO " << iEvent.id() << std::endl;
  float HT=0;
  float pfHT=0;

  int njets = 0;
  int pfnjets = 0;

  Handle< vector<pat::Jet> > PatJets;
  iEvent.getByLabel(conf_.getParameter<InputTag>("JetsColl"),PatJets);
  for (vector<pat::Jet>::const_iterator 
	 jb=PatJets->begin();jb!=PatJets->end();++jb){ 
    if (jb->pt()>50){
      HT+=jb->pt();
      njets = njets + 1; 
    }
  }

  Handle< vector<pat::Jet> > pfPatJets;
  iEvent.getByLabel(conf_.getParameter<InputTag>("pfJetsColl"),pfPatJets);
  for (vector<pat::Jet>::const_iterator 
	 jb=pfPatJets->begin();jb!=pfPatJets->end();++jb){ 
    if (jb->pt()>50){
      pfHT+=jb->pt();
      pfnjets = pfnjets + 1; 
    }
  }

  Handle< vector<pat::Tau> > PatTaus;
  iEvent.getByLabel(conf_.getParameter<InputTag>("TausColl"),PatTaus);
  for (vector<pat::Tau>::const_iterator 
	 tb=PatTaus->begin();tb!=PatTaus->end();++tb) HT+=tb->pt();

  Handle< vector<pat::Tau> > pfPatTaus;
  iEvent.getByLabel(conf_.getParameter<InputTag>("pfTausColl"),pfPatTaus);
  for (vector<pat::Tau>::const_iterator 
	 tb=pfPatTaus->begin();tb!=pfPatTaus->end();++tb) pfHT+=tb->pt();

  int nele =0;  
  Handle< vector<pat::Electron> > PatElectrons;
  iEvent.getByLabel(conf_.getParameter<InputTag>("ElectronsColl"),PatElectrons);
  for (vector<pat::Electron>::const_iterator 
	 eeb=PatElectrons->begin();eeb!=PatElectrons->end() ;++eeb){
    HT+=eeb->pt();
    nele++;
  }

  int npfele =0;  
  Handle< vector<pat::Electron> > pfPatElectrons;
  iEvent.getByLabel(conf_.getParameter<InputTag>("pfElectronsColl"),pfPatElectrons);
  for (vector<pat::Electron>::const_iterator 
	 eeb=pfPatElectrons->begin();eeb!=pfPatElectrons->end() ;++eeb){
    pfHT+=eeb->pt();
    npfele++;
  }
  
  int nmu =0;  
  Handle< vector<pat::Muon> > PatMuons;
  iEvent.getByLabel(conf_.getParameter<InputTag>("MuonsColl"),PatMuons);
  for (vector<pat::Muon>::const_iterator
	 mb=PatMuons->begin();mb!=PatMuons->end();++mb){
    HT+=mb->pt();
    nmu++;
  }

  int npfmu =0;  
  Handle< vector<pat::Muon> > pfPatMuons;
  iEvent.getByLabel(conf_.getParameter<InputTag>("pfMuonsColl"),pfPatMuons);
  for (vector<pat::Muon>::const_iterator
	 mb=pfPatMuons->begin();mb!=pfPatMuons->end();++mb){
    pfHT+=mb->pt();
    npfmu++;
  }

  if ( nele != 0 or npfele != 0 or nmu != 0 or npfmu != 0 )
    return true; 
  else
    return false;

}

// ------------ method called once each job just before starting event loop  ------------
void 
SUSYEVFILT::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
SUSYEVFILT::endJob() {
}

//define this as a plug-in
DEFINE_FWK_MODULE(SUSYEVFILT);
