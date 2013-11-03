
// -*- C++ -*-
//
// Package:    CosmicsCaloCom
// Class:      CosmicsCaloCom
// 
/**\class CosmicsCaloCom CosmicsCaloCom.cc UserCode/CosmicsCaloCom/src/CosmicsCaloCom.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Alberto Andres Ocampo Rios
//         Created:  Thu Oct 22 16:30:03 CEST 2009
// $Id$
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ParameterSet/interface/InputTag.h"
#include "FWCore/ServiceRegistry/interface/Service.h"


#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/MuonReco/interface/CaloMuon.h"

#include "DataFormats/TrackReco/interface/Track.h"

/// Stand Alone Guess 

#include "MagneticField/Engine/interface/MagneticField.h"
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include "Geometry/Records/interface/GlobalTrackingGeometryRecord.h"
#include "Geometry/CommonDetUnit/interface/GlobalTrackingGeometry.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"


#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "DataFormats/TrajectorySeed/interface/TrajectorySeedCollection.h"
#include "RecoMuon/TrackingTools/interface/MuonPatternRecoDumper.h"
#include "DataFormats/RecoCandidate/interface/RecoCandidate.h"
#include "DataFormats/Common/interface/EDProduct.h"
#include "DataFormats/Common/interface/Ref.h"

///Track parameters includes

#include "TrackingTools/TrackAssociator/interface/TrackDetectorAssociator.h"
#include "TrackingTools/Records/interface/TrackingComponentsRecord.h"

//CaloMuon parameters includes

#include "RecoMuon/MuonIdentification/interface/MuonCaloCompatibility.h"

#include "PhysicsTools/UtilAlgos/interface/TFileService.h"
#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/MonitorElement.h"
#include "TH1F.h"

/////CSC

//#include "DataFormats/CSCDigi/interface/CSCWireDigiCollection.h"
//#include "DataFormats/CSCDigi/interface/CSCWireDigi.h"
#include "DataFormats/CSCDigi/interface/CSCStripDigi.h"
#include "DataFormats/CSCDigi/interface/CSCStripDigiCollection.h"
//#include "DataFormats/CSCDigi/interface/CSCComparatorDigiCollection.h"
//#include "DataFormats/CSCDigi/interface/CSCALCTDigiCollection.h"
//#include "DataFormats/CSCDigi/interface/CSCDDUStatusDigiCollection.h"
#include "DataFormats/CSCDigi/interface/CSCCLCTDigiCollection.h"
//#include "DataFormats/CSCDigi/interface/CSCRPCDigiCollection.h"
#include "DataFormats/CSCDigi/interface/CSCCorrelatedLCTDigiCollection.h"
#include "DataFormats/CSCDigi/interface/CSCDCCFormatStatusDigiCollection.h"

//---------------------------------------------------------------------------                             
//---------------------- ECAL STUFF -----------------------------------------                             
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/EcalDigi/interface/EcalDigiCollections.h"
#include "Geometry/EcalMapping/interface/EcalElectronicsMapping.h"
#include "Geometry/EcalMapping/interface/EcalMappingRcd.h"
#include "DataFormats/EcalDetId/interface/EcalElectronicsId.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"
#include "Geometry/EcalMapping/interface/EcalElectronicsMapping.h"
#include "Geometry/CaloTopology/interface/CaloTopology.h"
#include "Geometry/CaloEventSetup/interface/CaloTopologyRecord.h"
#include "CaloOnlineTools/EcalTools/interface/EcalFedMap.h"
//---------------------------------------------------------------------------                             
//---------------------- HCAL STUFF -----------------------------------------                             

#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"
#include "DataFormats/HcalDigi/interface/HcalDigiCollections.h"
#include "TBDataFormats/HcalTBObjects/interface/HcalTBTriggerData.h"
#include "DataFormats/HcalDetId/interface/HcalElectronicsId.h"
#include "DataFormats/HcalRecHit/interface/HcalCalibRecHit.h"

//
// class decleration
//

class CosmicsCaloCom : public edm::EDAnalyzer {
public:
  explicit CosmicsCaloCom(const edm::ParameterSet&);
  ~CosmicsCaloCom();

private:
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  int ncalom;
  int nmuons;
  TH1F* hcccm;
  TrackDetectorAssociator trackAssociator_;
  TrackAssociatorParameters parameters_;
  MuonCaloCompatibility muonCaloCompatibility_;


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
CosmicsCaloCom::CosmicsCaloCom(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
  edm::Service < TFileService > fservice;
  hcccm = fservice->make<TH1F>("CaloCompatibilitycosmics","CaloCompatibilitycosmics",100,0,1);


}


CosmicsCaloCom::~CosmicsCaloCom()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
CosmicsCaloCom::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
  edm::Handle<reco::MuonCollection> muons;
  iEvent.getByLabel("muons",muons);

  edm::Handle<reco::CaloMuonCollection> cmuons;
  iEvent.getByType(cmuons);

  edm::Handle<reco::TrackCollection> tracks;
  iEvent.getByLabel("generalTracks",tracks);

  //  edm::Handle<CSCWireDigiCollection> wires;
  edm::Handle<CSCStripDigiCollection> jS;
  //  edm::Handle<CSCComparatorDigiCollection> comparators;
  //  edm::Handle<CSCALCTDigiCollection> alcts;
  //  edm::Handle<CSCCLCTDigiCollection> clcts;
  //  edm::Handle<CSCRPCDigiCollection> rpcs;
  edm::Handle<CSCCorrelatedLCTDigiCollection> correlatedlcts;
  //  edm::Handle<CSCDDUStatusDigiCollection> dduStatusDigi;
  //  edm::Handle<CSCDCCFormatStatusDigiCollection> formatStatusDigi;

  //  edm::Handle<CSCStripDigiCollection> strips;
  //  iEvent.getByLabel("csctfDigis",strips);
  // count the number of fired strips.                                                                                                                                                                                                                                                                                     
  // I am using a crude indicator of signal - this is fast and adequate for                                                                                                                                                                                                                                                
  // this purpose, but it would be poor for actual CSC studies.                                                                                                                                                                                                                                                            
  //  int ncscdigi = 0;
  //  for (CSCStripDigiCollection::DigiRangeIterator jS=strips->begin(); jS!=strips->end(); jS++) {
  //    std::vector<CSCStripDigi>::const_iterator stripItA = (*jS).second.first;
  //    std::vector<CSCStripDigi>::const_iterator lastStripA = (*jS).second.second;
  //    for( ; stripItA != lastStripA; ++stripItA) {
  //      std::vector<int> myADCVals = stripItA->getADCCounts();
  //      int iDiff = myADCVals[4]+myADCVals[5]-myADCVals[0]-myADCVals[1];
  //      if (iDiff > 30) {
  //	stripItA->print();  
  //	ncscdigi++;
  //      }
  //    }
  //  }
  //  std::cout << " Number of CSC digis" << ncscdigi << std::endl;

  iEvent.getByLabel("csctfDigis",correlatedlcts);


  edm::ESHandle<Propagator> propagator;
  iSetup.get<TrackingComponentsRecord>().get("SteppingHelixPropagatorAny", propagator); 
  trackAssociator_.setPropagator(propagator.product());

  for (CSCCorrelatedLCTDigiCollection::DigiRangeIterator j=correlatedlcts->begin(); j!=correlatedlcts->end(); j++) {
    std::vector<CSCCorrelatedLCTDigi>::const_iterator digiItr = (*j).second.first;
    std::vector<CSCCorrelatedLCTDigi>::const_iterator last = (*j).second.second;
    for( ; digiItr != last; ++digiItr) {
      std::cout << "CSC digi" << std::endl;
      digiItr->print();
    }
  }


  for (unsigned int i=0; i < muons->size(); ++i){
    nmuons++;
  }
  for (unsigned int j=0; j < cmuons->size(); ++j){
    ncalom++;
    hcccm->Fill((*cmuons)[j].caloCompatibility());
  }
  std::cout << "There are " << muons->size() << " Reco Muons and " << cmuons->size() << " calo muons in the event." << std::endl;

  ///////////////ECAL

  edm::Handle<EcalRecHitCollection> EBhits;
  edm::Handle<EcalRecHitCollection> EEhits;
  iEvent.getByLabel("ecalRecHit","EcalRecHitsEB", EBhits);
  iEvent.getByLabel("ecalRecHit","EcalRecHitsEE", EEhits);

  int necalorechit = 0;
  for (EcalRecHitCollection::const_iterator hitItr = EBhits->begin(); hitItr != EBhits->end(); ++hitItr)
    {
      EcalRecHit hit = (*hitItr);
      DetId det = hit.id();
      //       float ampli = hit.energy();
      necalorechit++;
      std::cout << "\tEcal Barrel: " << det() << std::endl;
    }
  
  for (EcalRecHitCollection::const_iterator hitItr = EEhits->begin(); hitItr != EEhits->end(); ++hitItr)
    {
      EcalRecHit hit = (*hitItr);
      DetId det = hit.id();
      //float ampli = hit.energy();
      necalorechit++;
      std::cout << "\tEcal Endcap: " << det() << std::endl;
    }
  std::cout << "There are " << necalorechit << " hits " << std::endl; 
  //-------------------------------------------------------------------------------------------------------                                                                                                                                                                                                                
  //------------------------------- HCAL RECHIT ------------------------------------------------------------                                                                                                                                                                                                               

  edm::Handle<HBHERecHitCollection> hbherh;  iEvent.getByLabel("hbhereco",hbherh);
  edm::Handle<HORecHitCollection> horh;  iEvent.getByLabel("horeco",horh);
  edm::Handle<HFRecHitCollection> hfrh;  iEvent.getByLabel("hfreco",hfrh);
  HBHERecHitCollection::const_iterator hbheit;
  HORecHitCollection::const_iterator hoit;
  HFRecHitCollection::const_iterator hfit;
  int nhcalorechit = 0;

  float energy = 0;

  for (hbheit  = hbherh->begin();
       hbheit != hbherh->end();
       hbheit++) {
    energy = 0;
    energy = hbheit->energy();
    HcalDetId id = hbheit->id();
    std::cout << "\t\tHBHE Rec Hits: "  << id() << std::endl;
    nhcalorechit++;

  }
  for (hoit  = horh->begin();
       hoit != horh->end();
       hoit++) {
    energy = 0;
    energy = hoit->energy();
    HcalDetId id = hoit->id();
    std::cout << "\t\tHO Rec Hits: "  << id() << std::endl;
    nhcalorechit++;
  }
  for (hfit  = hfrh->begin();
       hfit != hfrh->end();
       hfit++) {
    energy = 0;
    energy = hfit->energy();
    HcalDetId id = hfit->id();
    std::cout << "\t\tHF Rec Hits: "  << id() << std::endl;
    nhcalorechit++;
  }
  //  nrechithcal->Fill(tempo,nhcalorechit);

  std::cout << "\t\tThere were " << nhcalorechit << " rec hits in the hcal "<< std::endl;
}


// ------------ method called once each job just before starting event loop  ------------
void 
CosmicsCaloCom::beginJob()
{
  ncalom = 0;
  nmuons = 0;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
CosmicsCaloCom::endJob() {
  std::cout << "Total Number of calo muons was: " << ncalom << std::endl;
  std::cout << "Total Number of Reco muons was: " << nmuons << std::endl;
}

//define this as a plug-in
DEFINE_FWK_MODULE(CosmicsCaloCom);
