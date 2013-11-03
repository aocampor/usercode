// -*- C++ -*-
//
// Package:    Noise
// Class:      Noise
// 
/**\class Noise Noise.cc UserCode/Noise/src/Noise.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Alberto Andres Ocampo Rios
//         Created:  Mon Oct 27 18:37:24 CET 2008
// $Id$
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Run.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

///Data Format
#include "DataFormats/RPCDigi/interface/RPCDigi.h"
#include "DataFormats/RPCDigi/interface/RPCDigiCollection.h"
#include "DataFormats/MuonDetId/interface/RPCDetId.h"
#include "DataFormats/RPCRecHit/interface/RPCRecHitCollection.h"
#include "DataFormats/GeometrySurface/interface/LocalError.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"

///Geometry
#include "FWCore/Framework/interface/ESHandle.h"
#include "Geometry/RPCGeometry/interface/RPCGeometry.h"
#include "Geometry/Records/interface/MuonGeometryRecord.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"
#include "Geometry/RPCGeometry/interface/RPCGeomServ.h"
#include "Geometry/CommonTopologies/interface/RectangularStripTopology.h"

//Time stuff
#include "DataFormats/Provenance/interface/Timestamp.h"
#include <sys/time.h>

//root sweet root
#include <TROOT.h>
#include "TPaletteAxis.h"
#include "TTimeStamp.h"
#include "TTree.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TString.h"
#include "TFolder.h"

//string
#include <string>

//
// class decleration
//

class Noise : public edm::EDAnalyzer {
   public:
      explicit Noise(const edm::ParameterSet&);
      ~Noise();
      void bookTree();

   private:
      virtual void beginJob(const edm::EventSetup&) ;
      void beginRun(const edm::Run&, const edm::EventSetup&);     
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

  TFile *hfile;
  TTree *htree;
  
  long long tempo;
  char nomchamb[50];
  int neven;
  int nrun;
  int ndigi;
  int lumisection;
  std::string root_file_name;
  unsigned int bsec;
  unsigned int esec; 


      // ----------member data ---------------------------
};


using namespace edm;
using namespace std;

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
Noise::Noise(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
  root_file_name=iConfig.getUntrackedParameter<string>("histoName");

}


Noise::~Noise()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
Noise::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  edm::Handle<RPCDigiCollection> rpcdigis;
  iEvent.getByLabel("rpcunpacker",rpcdigis);
  edm::ESHandle<RPCGeometry> rpcGeo;
  iSetup.get<MuonGeometryRecord>().get(rpcGeo);

  TimeValue_t time=iEvent.time().value(); 
  timeval *tmval=(timeval*)&time;
  cout << "iEvent.id().event(): " << iEvent.id().event() << endl;   
  neven = iEvent.id().event();
  cout << "iEvent.id().run(): " << iEvent.id().run() << endl;   
  nrun = iEvent.id().run();
  cout << "timestamp: " << tmval->tv_usec << endl;
  tempo = tmval->tv_usec;
  lumisection=iEvent.luminosityBlock();

  for (TrackingGeometry::DetContainer::const_iterator it=rpcGeo->dets().begin();it<rpcGeo->dets().end();it++){
    if(dynamic_cast< RPCChamber* >( *it ) != 0 ){
      RPCChamber* ch = dynamic_cast< RPCChamber* >( *it ); 
      std::vector< const RPCRoll*> roles = (ch->rolls());
      for(std::vector<const RPCRoll*>::const_iterator r = roles.begin();r != roles.end(); ++r){
	RPCDetId rpcId = (*r)->id();
	RPCGeomServ rpcsrv(rpcId);
	cout << "rpcsrv: " << rpcsrv.name() << endl;
	string name = rpcsrv.name();
	strcpy(nomchamb,name.c_str());
	RPCDigiCollection::Range rpcRangeDigi=rpcdigis->get(rpcId);
	int cont=0;
	for (RPCDigiCollection::const_iterator digiIt = rpcRangeDigi.first;digiIt!=rpcRangeDigi.second;++digiIt){
	  cont++;
	}
	if(cont!=0){
	  ndigi = cont;
	  htree->Fill();
	}
      }
    }
  }

  //  RPCDigiCollection::DigiRangeIterator collectionItr;
  //  for(collectionItr=rpcdigis->begin(); collectionItr!=rpcdigis->end(); ++collectionItr){
    
  //    RPCDetId detId=(*collectionItr).first; 
  //    uint32_t id=detId();
  //    RPCGeomServ rpcsrv(detId);
  //    cout << "rpcsrv: " << rpcsrv.name() << endl;
  //    string name = rpcsrv.name();
  //    strcpy(nomchamb,name.c_str());
  //    htree->Fill();

  //  }

}


// ------------ method called once each job just before starting event loop  ------------
void 
Noise::beginJob(const edm::EventSetup&)
{
  bookTree();  
}

// ------------ method called once each job just after ending the event loop  ------------
void 
Noise::endJob() {
  htree->Print();
  htree->Write();
  hfile->Write();
  hfile->Close();
}

void Noise::bookTree(){

  hfile = new TFile(root_file_name.c_str(),"RECREATE");
  hfile->cd();

  htree = new TTree("RPCNoise", "RPC Noise");

  htree->Branch("nrun", &nrun, "nrun/I");
  htree->Branch("neven", &neven, "neven/I");
  htree->Branch("ndigi", &ndigi, "ndigi/I");
  htree->Branch("nomchamb", &nomchamb, "nomchamb[50]/C");
  htree->Branch("tempo", &tempo, "tempo/I");  
  htree->Branch("bsec", &bsec, "bsec/I");
  htree->Branch("esec", &esec, "esec/I");
  htree->Branch("lumisection",&lumisection,"lumisection/I");

}

void Noise::beginRun(const edm::Run& r, const edm::EventSetup& eventSetup){
  Timestamp btime = r.beginTime();
  Timestamp etime = r.endTime();

  bsec = btime.value() >> 32; 
  unsigned int busec = 0xFFFFFFFF & btime.value() ;

  esec = etime.value() >> 32; 
  unsigned int eusec = 0xFFFFFFFF & etime.value() ;
  std::cout<<"BEGIN RUN: "<<bsec<<"  "<<busec<<std::endl;
  std::cout<<"END RUN: "<<esec<<"  "<<eusec<<std::endl;

  //  getUTCtime((timeval*) a, timeval* b)

}


//define this as a plug-in
DEFINE_FWK_MODULE(Noise);
