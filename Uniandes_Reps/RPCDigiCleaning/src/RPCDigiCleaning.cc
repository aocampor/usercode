// -*- C++ -*-
//
// Package:    RPCDigiCleaning
// Class:      RPCDigiCleaning
// 
/**\class RPCDigiCleaning RPCDigiCleaning.cc UserCode/RPCDigiCleaning/src/RPCDigiCleaning.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Alberto Andres Ocampo Rios
//         Created:  Wed Jun 10 11:04:32 CEST 2009
// $Id: RPCDigiCleaning.cc,v 1.1 2009/07/14 09:02:59 aocampor Exp $
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/Run.h"
#include "FWCore/ParameterSet/interface/InputTag.h"

///Data Format                                                                                                                                                                                                    
#include "DataFormats/RPCDigi/interface/RPCDigi.h"
#include "DataFormats/RPCDigi/interface/RPCDigiCollection.h"
#include "DataFormats/MuonDetId/interface/RPCDetId.h"
#include "DataFormats/RPCRecHit/interface/RPCRecHitCollection.h"
#include "DataFormats/GeometrySurface/interface/LocalError.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"

#include "SimDataFormats/TrackingHit/interface/PSimHitContainer.h"
#include "SimMuon/RPCDigitizer/src/RPCSynchronizer.h"

///Geometry                                                                                                                                                                                                       
#include "FWCore/Framework/interface/ESHandle.h"
#include "Geometry/RPCGeometry/interface/RPCGeometry.h"
#include "Geometry/Records/interface/MuonGeometryRecord.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"
#include "Geometry/RPCGeometry/interface/RPCGeomServ.h"
#include "Geometry/CommonTopologies/interface/RectangularStripTopology.h"
#include "Geometry/RPCGeometry/interface/RPCRollSpecs.h"
#include "Geometry/CommonTopologies/interface/StripTopology.h"
//#include "SimMuon/RPCDigitizer/src/RPCDigitizer.h"

#include "SimDataFormats/RPCDigiSimLink/interface/RPCDigiSimLink.h"
//
// class decleration
//

class RPCDigiCleaning : public edm::EDProducer {
public:
  explicit RPCDigiCleaning(const edm::ParameterSet&);
  ~RPCDigiCleaning();

private:
  virtual void beginJob(const edm::EventSetup&) ;
  virtual void produce(edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  
  edm::InputTag m_GMTInputTag;      
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

RPCDigiCleaning::RPCDigiCleaning(const edm::ParameterSet& iConfig)
{
  produces<RPCDigiCollection>(); 
  m_GMTInputTag = iConfig.getParameter<edm::InputTag>("GMTInputTag");
  //  produces<RPCDigiSimLink>("RPCDigiSimLink");
   //register your products
/* Examples
   produces<ExampleData2>();

   //if do put with a label
   produces<ExampleData2>("label");
*/
   //now do what ever other initialization is needed
  
}


RPCDigiCleaning::~RPCDigiCleaning()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
RPCDigiCleaning::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
  edm::Handle<RPCDigiCollection> rpcdigis;
  iEvent.getByLabel(m_GMTInputTag,rpcdigis);
  //  iEvent.getByLabel("muonRPCDigis",rpcdigis);
  edm::ESHandle<RPCGeometry> rpcGeo;
  iSetup.get<MuonGeometryRecord>().get(rpcGeo);

  //  RPCDigiCollection newrpcdigis;

  std::auto_ptr<RPCDigiCollection> pDigis(new RPCDigiCollection());


  for (TrackingGeometry::DetContainer::const_iterator it=rpcGeo->dets().begin();it<rpcGeo->dets().end();it++){
    if(dynamic_cast< RPCChamber* >( *it ) != 0 ){
      RPCChamber* ch = dynamic_cast< RPCChamber* >( *it );
      std::vector< const RPCRoll*> roles = (ch->rolls());
      
      for(std::vector<const RPCRoll*>::const_iterator r = roles.begin();r != roles.end(); ++r){
	RPCDetId rpcId = (*r)->id();
	RPCDigiCollection::Range rpcRangeDigi=rpcdigis->get(rpcId);
	std::vector<long> dig;
	std::vector< std::vector <long> > prev;
	prev.clear();
	//	std::vector< >
	for (RPCDigiCollection::const_iterator digiIt = rpcRangeDigi.first;digiIt!=rpcRangeDigi.second;++digiIt){
	  //	   cout << "Bx: " << (*digiIt).bx() << " rawId: " << rpcId.rawId() << " strip: " << (*digiIt).strip() << " conter: " << counter << endl;
	  dig.clear();
	  bool verheit = false;
	  dig.push_back((*digiIt).bx());
	  dig.push_back(rpcId.rawId());
	  dig.push_back((*digiIt).strip());
	  for(int i=0;i<prev.size();i++){
	    if(prev[i][0]==dig[0] and prev[i][1]==dig[1] and prev[i][2] == dig[2]) verheit = true;
	    //cout << "\t prev: " << prev[i][0] << " " << prev[i][1] << " " << prev[i][2] << endl;
	  }
	  prev.push_back(dig);
	  (*pDigis).insertDigi(rpcId,(*digiIt));

	}
      }
    }
  }


  iEvent.put(pDigis);
  //  iEvent.put(RPCDigitSimLink,"RPCDigiSimLink");

/* This is an event example
   //Read 'ExampleData' from the Event
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);

   //Use the ExampleData to create an ExampleData2 which 
   // is put into the Event
   std::auto_ptr<ExampleData2> pOut(new ExampleData2(*pIn));
   iEvent.put(pOut);
*/

/* this is an EventSetup example
   //Read SetupData from the SetupRecord in the EventSetup
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
*/
 
}

// ------------ method called once each job just before starting event loop  ------------
void 
RPCDigiCleaning::beginJob(const edm::EventSetup&)
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
RPCDigiCleaning::endJob() {
}

//define this as a plug-in
DEFINE_FWK_MODULE(RPCDigiCleaning);
