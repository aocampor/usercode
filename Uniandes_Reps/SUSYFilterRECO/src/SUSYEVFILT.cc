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
#include "DataFormats/GsfTrackReco/interface/GsfTrack.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
 #include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
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

  //  std::cout << "EVENTO " << iEvent.id() << std::endl;
  edm::Handle<reco::GsfElectronCollection> gsfElectrons;
  iEvent.getByLabel(conf_.getParameter<InputTag>("ElectronsColl"),gsfElectrons);
  std::cout  <<"Treating event "<<iEvent.id()
	     <<" with "<<gsfElectrons.product()->size()<<" electrons" << std::endl ;


  edm::Handle<edm::View<reco::Muon> > muonsHandle; // 
  iEvent.getByLabel(conf_.getParameter<InputTag>("MuonsColl"), muonsHandle);
  
  //Fill event entry in histogram of number of muons
  std:: cout << "Number of Muons: " << muonsHandle->size() << std::endl;
   
  Handle<PFCandidateCollection> pfCandidates;
  iEvent.getByLabel(conf_.getParameter<InputTag>("pfElectronsColl"), pfCandidates);
  reco::PFCandidateCollection newcol;
  newcol=*pfCandidates;

  std:: cout << "Number of pf electrons: " << pfCandidates->size() << std::endl;
  if(gsfElectrons.product()->size() > 0 || muonsHandle->size() > 0 || pfCandidates->size() > 0)
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
