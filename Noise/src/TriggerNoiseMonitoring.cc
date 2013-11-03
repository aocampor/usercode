// -*- C++ -*-
//
// Package:    TriggerNoiseMonitoring
// Class:      TriggerNoiseMonitoring
// 
/**\class

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/



// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Run.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/InputTag.h"
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

//------------------------TRIGGER---------------------------------------------

#include "DataFormats/L1Trigger/interface/L1EmParticle.h"
#include "DataFormats/L1Trigger/interface/L1EmParticleFwd.h"
#include "DataFormats/L1Trigger/interface/L1JetParticle.h"
#include "DataFormats/L1Trigger/interface/L1JetParticleFwd.h"
#include "DataFormats/L1Trigger/interface/L1MuonParticle.h"
#include "DataFormats/L1Trigger/interface/L1MuonParticleFwd.h"
#include "DataFormats/L1Trigger/interface/L1EtMissParticle.h"
#include "DataFormats/L1Trigger/interface/L1EtMissParticleFwd.h"
#include "DataFormats/L1GlobalMuonTrigger/interface/L1MuRegionalCand.h"
#include "DataFormats/L1GlobalMuonTrigger/interface/L1MuGMTReadoutCollection.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutRecord.h"
#include "DataFormats/L1GlobalCaloTrigger/interface/L1GctEtSums.h"
#include "DataFormats/L1GlobalCaloTrigger/interface/L1GctCollections.h"
#include "DataFormats/L1GlobalCaloTrigger/interface/L1GctJetCounts.h"
#include "DataFormats/L1CaloTrigger/interface/L1CaloCollections.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerEvmReadoutRecord.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerObjectMapRecord.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerObjectMap.h"
#include "DataFormats/L1GlobalMuonTrigger/interface/L1MuGMTReadoutCollection.h"
#include "DataFormats/L1GlobalMuonTrigger/interface/L1MuGMTCand.h"
#include "DataFormats/L1GlobalMuonTrigger/interface/L1MuGMTExtendedCand.h"
#include "CondFormats/L1TObjects/interface/L1GtParameters.h"
#include "CondFormats/DataRecord/interface/L1GtParametersRcd.h"
#include "DataFormats/L1GlobalMuonTrigger/interface/L1MuGMTCand.h"
#include "DataFormats/L1GlobalMuonTrigger/interface/L1MuGMTExtendedCand.h"

// ---------------------- DT STUFF -------------------------------------------
#include "DataFormats/MuonData/interface/MuonDigiCollection.h"
#include "Geometry/DTGeometry/interface/DTGeometry.h"
#include "Geometry/DTGeometry/interface/DTLayer.h"
#include "DataFormats/DTDigi/interface/DTDigiCollection.h"
#include "DataFormats/MuonDetId/interface/DTWireId.h"
#include "DataFormats/MuonDetId/interface/DTLayerId.h"
#include "CondFormats/DTObjects/interface/DTT0.h"
#include "DataFormats/DTDigi/interface/DTDigi.h"
#include "DataFormats/DTDigi/interface/DTDigiCollection.h"

//----------------------------------------------------------------------------
//---------------------- CSC STUFF -------------------------------------------

#include "DataFormats/CSCDigi/interface/CSCWireDigiCollection.h"
#include "Geometry/CSCGeometry/interface/CSCLayerGeometry.h"
#include "Geometry/CSCGeometry/interface/CSCGeometry.h"
#include "DataFormats/MuonDetId/interface/CSCDetId.h"
#include "DataFormats/CSCDigi/interface/CSCWireDigi.h"
#include "DataFormats/CSCDigi/interface/CSCWireDigiCollection.h"
#include "DataFormats/CSCDigi/interface/CSCStripDigi.h"
#include "DataFormats/CSCDigi/interface/CSCStripDigiCollection.h"

//---------------------------------------------------------------------------
//---------------------- HCAL STUFF -----------------------------------------

#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"
#include "DataFormats/HcalDigi/interface/HcalDigiCollections.h"
#include "TBDataFormats/HcalTBObjects/interface/HcalTBTriggerData.h"
#include "DataFormats/HcalDetId/interface/HcalElectronicsId.h"
#include "DataFormats/HcalRecHit/interface/HcalCalibRecHit.h"


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
//-------------------- PIXEL STUFF ------------------------------------------

#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h" 
#include "DataFormats/SiStripDetId/interface/SiStripDetId.h"
#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "Geometry/TrackerGeometryBuilder/interface/PixelGeomDetUnit.h"
#include "Geometry/TrackerGeometryBuilder/interface/PixelGeomDetType.h"

#include "DataFormats/SiPixelDetId/interface/PixelSubdetector.h"
#include "DataFormats/SiPixelDetId/interface/PXBDetId.h"
#include "DataFormats/SiPixelDetId/interface/PXFDetId.h"

#include "DataFormats/TrackerRecHit2D/interface/SiPixelRecHit.h"
#include "DataFormats/TrackerRecHit2D/interface/SiPixelRecHitCollection.h"
#include "DataFormats/SiPixelDetId/interface/PXBDetId.h"
#include "DataFormats/SiPixelDetId/interface/PXFDetId.h"
#include "DataFormats/SiPixelDetId/interface/PixelSubdetector.h"

#include "DataFormats/Common/interface/DetSetVector.h"
#include "DataFormats/SiPixelDigi/interface/PixelDigi.h"
#include "DataFormats/SiPixelDigi/interface/PixelDigiCollection.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/SiStripDigi/interface/SiStripDigi.h"

// For the big pixel recongnition
#include "Geometry/TrackerTopology/interface/RectangularPixelTopology.h"


//---------------------------------------------------------------------------



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

class TriggerNoiseMonitoring : public edm::EDAnalyzer {
   public:
      explicit TriggerNoiseMonitoring(const edm::ParameterSet&);
      ~TriggerNoiseMonitoring();
      void bookTree();

   private:
      virtual void beginJob(const edm::EventSetup&) ;
      void beginRun(const edm::Run&, const edm::EventSetup&);     
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

  TFile *hfile;
  TTree *htree;
  TTree *htreeN;
  
  long long tempo;
  char nomchamb[50];
  int neven;
  int nrun;
  int lumisection;
  std::string root_file_name;
  unsigned int bsec;
  unsigned int esec; 

  bool dt_l1a;
  bool csc_l1a;
  bool halo_l1a;
  bool rpcb_l1a;
  bool rpcf_l1a;
  bool hcal;
  bool ecal;

  int irpcb;
  int irpcf;
  int idt;
  int icsc;
  int ihalo;
  int iecalo;
  int ihcalo;

  int nrpcdigiroll;
  int nrpcdigi;
  int nrpcdiginoise;
  int ndtdigi;
  int ncscdigi;
  int necalorechit;
  int nhcalorechit;
  int npixeldigi;
  int ntrackerdigi;
  int nrechitpixel;

  int thisOrbit;
  int evbx;
  int orbitTime;

  edm::InputTag m_GMTInputTag;

  std::string labelDT;
};

using namespace edm;
using namespace std;

void TriggerNoiseMonitoring::beginJob(const edm::EventSetup&)
{

  dt_l1a = false;
  csc_l1a = false;
  halo_l1a = false;
  rpcb_l1a = false;
  rpcf_l1a = false;

  irpcb = 0;
  irpcf = 0;
  idt= 0;
  icsc = 0;
  ihalo = 0;
  iecalo = 0;
  ihcalo = 0;

  nrpcdigiroll = 0;
  nrpcdigi = 0;
  nrpcdiginoise = 0;
  ndtdigi = 0;
  ncscdigi = 0;
  necalorechit = 0;
  nhcalorechit = 0;
  npixeldigi = 0;
  ntrackerdigi = 0;
  nrechitpixel = 0;

  thisOrbit = 0;
  evbx = -999;
  orbitTime = -999;

  bookTree();  
}

void TriggerNoiseMonitoring::bookTree(){

  hfile = new TFile(root_file_name.c_str(),"RECREATE");
  hfile->cd();

  htree = new TTree("RPCTriggerNoiseMonitoring", "RPC  Trigger Noise Monitoring");

  htreeN = new TTree("RPCNoiseMonitoring", "RPC Noise Monitoring");

  htree->Branch("nrun", &nrun, "nrun/I");
  htree->Branch("neven", &neven, "neven/I");

  htreeN->Branch("nrun", &nrun, "nrun/I");
  htreeN->Branch("neven", &neven, "neven/I");

  htreeN->Branch("nomchamb", &nomchamb, "nomchamb[50]/C");

  htreeN->Branch("tempo", &tempo, "tempo/I");
  htreeN->Branch("bsec", &bsec, "bsec/I");
  htreeN->Branch("esec", &esec, "esec/I");
  htreeN->Branch("lumisection",&lumisection,"lumisection/I");
  htreeN->Branch("thisOrbit", &thisOrbit, "thisOrbit/I");
  htreeN->Branch("evbx", &evbx, "evbx/I");
  htreeN->Branch("orbitTime", &orbitTime, "orbitTime/I");


  htree->Branch("tempo", &tempo, "tempo/I");  
  htree->Branch("bsec", &bsec, "bsec/I");
  htree->Branch("esec", &esec, "esec/I");
  htree->Branch("lumisection",&lumisection,"lumisection/I");
  htree->Branch("thisOrbit", &thisOrbit, "thisOrbit/I");
  htree->Branch("evbx", &evbx, "evbx/I");
  htree->Branch("orbitTime", &orbitTime, "orbitTime/I");

  htree->Branch("dt_l1a", &dt_l1a,"dt_l1a/B");
  htree->Branch("csc_l1a", &csc_l1a,"csc_l1a/B");
  htree->Branch("halo_l1a", &halo_l1a,"halo_l1a/B");
  htree->Branch("rpcb_l1a", &rpcb_l1a,"rpcb_l1a/B");
  htree->Branch("rpcf_l1a", &rpcf_l1a,"rpcf_l1a/B");
  htree->Branch("ecal", &ecal,"ecal/B");
  htree->Branch("hcal", &hcal,"hcal/B");

  htree->Branch("irpcb", &irpcb,"irpcb/I");
  htree->Branch("irpcf", &irpcf,"irpcf/I");
  htree->Branch("idt", &idt,"idt/I");
  htree->Branch("icsc", &icsc,"icsc/I");
  htree->Branch("ihalo", &ihalo,"ihalo/I");
  htree->Branch("iecalo", &iecalo,"iecalo/I");
  htree->Branch("ihcalo", &ihcalo,"ihcalo/I");

  htreeN->Branch("nrpcdigiroll", &nrpcdigiroll, "nrpcdigiroll/I");

  htree->Branch("nrpcdigi", &nrpcdigi, "nrpcdigi/I");
  htree->Branch("nrpcdiginoise", &nrpcdiginoise, "nrpcdiginoise/I");
  htree->Branch("ndtdigi", &ndtdigi, "ndtdigi/I");
  htree->Branch("ncscdigi", &ncscdigi, "ncscdigi/I");
  htree->Branch("necalorechit", &necalorechit, "necalorechit/I");
  htree->Branch("nhcalorechit", &nhcalorechit, "nhcalorechit/I");
  htree->Branch("npixeldigi", &npixeldigi, "npixeldigi/I");
  htree->Branch("nrechitpixel", &nrechitpixel, "nrechitpixel/I");
  htree->Branch("ntrackerdigi", &ntrackerdigi, "ntrackerdigi/I");

}

void TriggerNoiseMonitoring::beginRun(const edm::Run& r, const edm::EventSetup& eventSetup){
  Timestamp btime = r.beginTime();
  Timestamp etime = r.endTime();

  bsec = btime.value() >> 32; 
  unsigned int busec = 0xFFFFFFFF & btime.value() ;

  esec = etime.value() >> 32; 
  unsigned int eusec = 0xFFFFFFFF & etime.value() ;
}



TriggerNoiseMonitoring::TriggerNoiseMonitoring(const edm::ParameterSet& iConfig)
{
  labelDT = iConfig.getUntrackedParameter<string>("labelDT");  
 
  m_GMTInputTag = iConfig.getParameter<edm::InputTag>("GMTInputTag");

  root_file_name = iConfig.getUntrackedParameter<string>("histoName");
}


TriggerNoiseMonitoring::~TriggerNoiseMonitoring(){}

void
TriggerNoiseMonitoring::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{


  int bx = iEvent.bunchCrossing();
  int thisOrbit = iEvent.orbitNumber();
  orbitTime = 3564*thisOrbit + bx;

  TimeValue_t time=iEvent.time().value(); 
  timeval *tmval=(timeval*)&time;
  neven = iEvent.id().event();
  nrun = iEvent.id().run();
  tempo = tmval->tv_usec;
  lumisection=iEvent.luminosityBlock();


  //___________________________________________________________________________
  //---------------------------------------------------------------------------
  //--------------------------------- Trigger section -------------------------
  //___________________________________________________________________________

//----------------------------- ECAL TRIGGER -----------------------------------------------

  edm::Handle< l1extra::L1EmParticleCollection > emIsolColl ;
  iEvent.getByLabel("hltL1extraParticles","Isolated", emIsolColl ) ;
  //Get the L1 NonIsolated EM Collection
  edm::Handle< l1extra::L1EmParticleCollection > emNonIsolColl ;
  iEvent.getByLabel("hltL1extraParticles","NonIsolated", emNonIsolColl ) ;

  iecalo = 0;
  iecalo = emIsolColl->size() + emNonIsolColl-> size();
  
//----------------------------- GLOBAL MUON TRIGGER ----------------------------------------

  edm::Handle<L1MuGMTReadoutCollection> gmtrc_handle; 
  iEvent.getByLabel(m_GMTInputTag,gmtrc_handle);
  L1MuGMTReadoutCollection const* gmtrc = gmtrc_handle.product();
  
  std::vector<L1MuGMTReadoutRecord> gmt_records = gmtrc->getRecords();
  std::vector<L1MuGMTReadoutRecord>::const_iterator igmtrr;
  
  for(igmtrr=gmt_records.begin(); igmtrr!=gmt_records.end(); igmtrr++) {
    
    std::vector<L1MuRegionalCand>::const_iterator iter1;
    std::vector<L1MuRegionalCand> rmc;
    
    // DT muon candidates
    idt = 0;
    rmc = igmtrr->getDTBXCands();
    for(iter1=rmc.begin(); iter1!=rmc.end(); iter1++) {
      if ( !(*iter1).empty() ) {
	idt++;
      }
    }
     
    if(igmtrr->getBxInEvent()==0 && idt>0) dt_l1a = true;
    
    // CSC muon candidates
    icsc = 0;
    ihalo = 0;
    rmc = igmtrr->getCSCCands();
    for(iter1=rmc.begin(); iter1!=rmc.end(); iter1++) {
      if ( !(*iter1).empty() ) {
	if((*iter1).isFineHalo()) {
	  ihalo++;
	} else {
	  icsc++;
	}
      }
    }
     
    if(igmtrr->getBxInEvent()==0 && icsc>0) csc_l1a = true;
    if(igmtrr->getBxInEvent()==0 && ihalo>0) halo_l1a = true;
     
    // RPC barrel muon candidates
    irpcb = 0;
    rmc = igmtrr->getBrlRPCCands();
    for(iter1=rmc.begin(); iter1!=rmc.end(); iter1++) {
      if ( !(*iter1).empty() ) {
	irpcb++;
      }
    }
     
    if(igmtrr->getBxInEvent()==0 && irpcb>0) rpcb_l1a = true;
    
    // RPC endcap muon candidates
    irpcf = 0;
    rmc = igmtrr->getFwdRPCCands();
    for(iter1=rmc.begin(); iter1!=rmc.end(); iter1++) {
      if ( !(*iter1).empty() ) {
	irpcf++;
      }
    }
     
    if(igmtrr->getBxInEvent()==0 && irpcf>0) rpcf_l1a = true;
    
  }
  
  //___________________________________________________________________________
  //---------------------------------------------------------------------------
  //--------------------------------- Digi and RECHIT section -------------------------
  //___________________________________________________________________________


  //---------------------------------------------------------------------------------------------------------
  //------------------------------------- DT DIGIS ----------------------------------------------------------

  Handle<DTDigiCollection> dtDigis;
  iEvent.getByLabel(labelDT, dtDigis);
  
  ESHandle<DTGeometry> muonGeom;
  iSetup.get<MuonGeometryRecord>().get(muonGeom);

  ndtdigi = 0;
  DTDigiCollection::DigiRangeIterator detUnitIt;
  for (detUnitIt=dtDigis->begin();
       detUnitIt!=dtDigis->end();
       ++detUnitIt){
    
    const DTLayerId& id = (*detUnitIt).first;
    const DTDigiCollection::Range& range = (*detUnitIt).second;
    
    for (DTDigiCollection::const_iterator digiIt = range.first;
	 digiIt!=range.second;
	 ++digiIt){
      ndtdigi++;
    }// for digis in layer
  }// for layers

  //---------------------------------------------------------------------------------------------------------
  //----------------------------------- CSC DIGIS -----------------------------------------------------------
  
  edm::Handle<CSCStripDigiCollection> strips;
  iEvent.getByLabel("muonCSCDigis","MuonCSCStripDigi",strips);

  // count the number of fired strips.
  // I am using a crude indicator of signal - this is fast and adequate for
  // this purpose, but it would be poor for actual CSC studies.
  ncscdigi = 0;
  for (CSCStripDigiCollection::DigiRangeIterator jS=strips->begin(); jS!=strips->end(); jS++) {
    std::vector<CSCStripDigi>::const_iterator stripItA = (*jS).second.first;
    std::vector<CSCStripDigi>::const_iterator lastStripA = (*jS).second.second;
    for( ; stripItA != lastStripA; ++stripItA) {
      std::vector<int> myADCVals = stripItA->getADCCounts();
      int iDiff = myADCVals[4]+myADCVals[5]-myADCVals[0]-myADCVals[1];
      if (iDiff > 30) {
	ncscdigi++;
      }
    }
  }

  //-------------------------------------------------------------------------------------------------------
  //------------------------------- ECAL DIGIS ------------------------------------------------------------

  edm::Handle<EcalRecHitCollection> EBhits;
  edm::Handle<EcalRecHitCollection> EEhits;
  iEvent.getByLabel("ecalRecHit","EcalRecHitsEB", EBhits);
  iEvent.getByLabel("ecalRecHit","EcalRecHitsEE", EEhits);

  necalorechit = 0;
  for (EcalRecHitCollection::const_iterator hitItr = EBhits->begin(); hitItr != EBhits->end(); ++hitItr)
  {
    EcalRecHit hit = (*hitItr);
    DetId det = hit.id();
    float ampli = hit.energy();
    necalorechit++;
  } 

  for (EcalRecHitCollection::const_iterator hitItr = EEhits->begin(); hitItr != EEhits->end(); ++hitItr)
  {
    EcalRecHit hit = (*hitItr);
    DetId det = hit.id();
    float ampli = hit.energy();
    necalorechit++;
  } 

  //-------------------------------------------------------------------------------------------------------
  //------------------------------- HCAL RECHIT ------------------------------------------------------------
  
  edm::Handle<HBHERecHitCollection> hbherh;  iEvent.getByLabel("hbhereco",hbherh);
  edm::Handle<HORecHitCollection> horh;  iEvent.getByLabel("horeco",horh);
  edm::Handle<HFRecHitCollection> hfrh;  iEvent.getByLabel("hfreco",hfrh);
  
  HBHERecHitCollection::const_iterator hbheit;
  HORecHitCollection::const_iterator hoit;
  HFRecHitCollection::const_iterator hfit;
  nhcalorechit = 0;

  float energy = 0;
  for (hbheit  = hbherh->begin(); 
       hbheit != hbherh->end();
       hbheit++) {
       energy = 0;
       energy = hbheit->energy();
       HcalDetId id = hbheit->id();
       nhcalorechit++;
  }
  for (hbheit  = hbherh->begin();
       hbheit != hbherh->end();
       hbheit++) {
       energy = 0;
       energy = hbheit->energy();
       HcalDetId id = hbheit->id();
       nhcalorechit++;
  }
  for (hoit  = horh->begin();
       hoit != horh->end();
       hoit++) {
       energy = 0;
       energy = hoit->energy();
       nhcalorechit++;
  }
  for (hfit  = hfrh->begin();
       hfit != hfrh->end();
       hfit++) {
       energy = 0;
       energy = hfit->energy();
       nhcalorechit++;
  }

  //--------------------------------------------------------------------------------------------------------
  //------------------------------- PIXEL DIGI -------------------------------------------------------------

  edm::Handle< edm::DetSetVector<PixelDigi> > pixelDigis;
  iEvent.getByLabel( "siPixelDigis" , pixelDigis);

  npixeldigi = 0;
  edm::DetSetVector<PixelDigi>::const_iterator DSViter;
  for(DSViter = pixelDigis->begin(); DSViter != pixelDigis->end(); DSViter++) {

    unsigned int detid = DSViter->id; // = rawid
    DetId detId(detid);
    unsigned int detType=detId.det(); // det type, tracker=1
    unsigned int subid=detId.subdetId(); //subdetector type, barrel=1
    npixeldigi += DSViter->size();
  }

  //----------------------------------------------------------------------------------------------------------
  //------------------------------ TRACKER DIGI --------------------------------------------------------------

  Handle<edm::DetSetVector<SiStripDigi> > digis;
  iEvent.getByLabel("siStripDigis","ZeroSuppressed",digis);
  ntrackerdigi = 0;
  for(edm::DetSetVector<SiStripDigi>::const_iterator it = digis->begin();it!=digis->end();it++) {
    SiStripDetId det(it->detId());
    ntrackerdigi += it->size();
  }

  //----------------------------------------------------------------------------------------------------------
  //------------------------------- RPC DIGI -----------------------------------------------------------------

  edm::Handle<RPCDigiCollection> rpcdigis;
  iEvent.getByLabel("muonRPCDigis",rpcdigis);
  edm::ESHandle<RPCGeometry> rpcGeo;
  iSetup.get<MuonGeometryRecord>().get(rpcGeo);

  nrpcdigi = 0; 
  nrpcdiginoise = 0;
  for (TrackingGeometry::DetContainer::const_iterator it=rpcGeo->dets().begin();it<rpcGeo->dets().end();it++){
    if(dynamic_cast< RPCChamber* >( *it ) != 0 ){
      RPCChamber* ch = dynamic_cast< RPCChamber* >( *it ); 
      std::vector< const RPCRoll*> roles = (ch->rolls());
      for(std::vector<const RPCRoll*>::const_iterator r = roles.begin();r != roles.end(); ++r){
	RPCDetId rpcId = (*r)->id();
	RPCGeomServ rpcsrv(rpcId);
	//	cout << "rpcsrv: " << rpcsrv.name() << endl;
	string name = rpcsrv.name();
	strcpy(nomchamb,name.c_str());
	RPCDigiCollection::Range rpcRangeDigi=rpcdigis->get(rpcId);
	int cont=0;
	for (RPCDigiCollection::const_iterator digiIt = rpcRangeDigi.first;digiIt!=rpcRangeDigi.second;++digiIt){
	  cont++;
	}
	if(cont!=0){
	  nrpcdigiroll = cont;
	  std::cout << "camara: " << nomchamb << " digisrol: " << nrpcdigiroll << std::endl;
	  htreeN->Fill();
	}
	nrpcdigi += nrpcdigiroll;
	nrpcdigiroll=0;
	std::cout << "nrpcdigi: " << nrpcdigi << std::endl;
      }
      if(nrpcdigi > 80){
	nrpcdiginoise = nrpcdigi;
      }
    }
  }
  //----------------------------------------------------------------------------------------------------------
  htree->Fill();
}

void 
TriggerNoiseMonitoring::endJob() {
  htree->Print();
  htree->Write();
  htreeN->Print();
  htreeN->Write();
  hfile->Write();
  hfile->Close();
}

//define this as a plug-in
DEFINE_FWK_MODULE(TriggerNoiseMonitoring);
