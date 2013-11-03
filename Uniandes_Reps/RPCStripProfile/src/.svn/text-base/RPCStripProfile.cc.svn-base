// -*- C++ -*-
//
// Package:    RPCStripProfile
// Class:      RPCStripProfile
// 
/**\class RPCStripProfile RPCStripProfile.cc UserCode/RPCStripProfile/src/RPCStripProfile.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Alberto Andres Ocampo Rios
//         Created:  Fri Jun 12 09:55:10 CEST 2009
// $Id: RPCStripProfile.cc,v 1.6 2009/12/16 09:00:16 aocampor Exp $
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/Run.h"
#include "FWCore/ParameterSet/interface/InputTag.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "DataFormats/RPCDigi/interface/RPCDigi.h"
#include "DataFormats/RPCDigi/interface/RPCDigiCollection.h"
#include "DataFormats/MuonDetId/interface/RPCDetId.h"
#include "DataFormats/RPCRecHit/interface/RPCRecHitCollection.h"
#include "DataFormats/GeometrySurface/interface/LocalError.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "DataFormats/Common/interface/Handle.h"

#include "Geometry/RPCGeometry/interface/RPCGeometry.h"
#include "Geometry/Records/interface/MuonGeometryRecord.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"
#include "Geometry/RPCGeometry/interface/RPCGeomServ.h"
#include "Geometry/CommonTopologies/interface/RectangularStripTopology.h"
#include "Geometry/RPCGeometry/interface/RPCRollSpecs.h"
#include "Geometry/CommonTopologies/interface/StripTopology.h"

#include "DataFormats/Provenance/interface/Timestamp.h"
#include "DataFormats/MuonDetId/interface/MuonSubdetId.h"
#include <DataFormats/RPCRecHit/interface/RPCRecHit.h>
#include "DataFormats/GeometrySurface/interface/LocalError.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "DataFormats/GeometrySurface/interface/Surface.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/TrackReco/interface/Track.h"

//physics tools
#include "PhysicsTools/UtilAlgos/interface/TFileService.h"

#include "RecoMuon/MeasurementDet/interface/MuonDetLayerMeasurements.h"
#include "RecoMuon/TrackingTools/interface/MuonServiceProxy.h"
#include <Geometry/DTGeometry/interface/DTGeometry.h>
#include <Geometry/CSCGeometry/interface/CSCGeometry.h>
#include <Geometry/RPCGeometry/interface/RPCChamber.h>
#include "Geometry/Records/interface/GlobalTrackingGeometryRecord.h"
#include "Geometry/RPCGeometry/interface/RPCGeomServ.h"
#include "MagneticField/Engine/interface/MagneticField.h"
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "TrackPropagation/SteppingHelixPropagator/interface/SteppingHelixPropagator.h"
#include "TrackingTools/Records/interface/TrackingComponentsRecord.h"
#include "PhysicsTools/UtilAlgos/interface/TFileService.h"
#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/MonitorElement.h"
//#include "DQM/RPCMonitorDigi/interface/RPCEfficiencyFromTrack.h"                                                                                    
#include "DQM/RPCMonitorDigi/interface/utils.h"
#include "Alignment/MuonAlignmentAlgorithms/interface/SegmentToTrackAssociator.h"

//#include "DQM/RPCMonitorDigi/interface/noiseRPCOffline.h"

#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include "RecoMuon/Navigation/interface/DirectMuonNavigation.h"
//#include "TrackingTools/TransientTrackinkgRecHit/interface/TransientTrackingRecHit.h"                                                               
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "TrackingTools/KalmanUpdators/interface/Chi2MeasurementEstimator.h"
#include "DataFormats/DTRecHit/interface/DTRecSegment4DCollection.h"
#include "DataFormats/DTRecHit/interface/DTRecHitCollection.h"
#include "TH1.h"
#include <iostream>
#include <cmath>
#include <assert.h>
//Time stuff 
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
#include <TStyle.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>

using namespace std; 
using namespace edm; 
//
// class decleration
//
class SegmentToTrackAssociator;

class RPCStripProfile : public edm::EDAnalyzer {
public:
  explicit RPCStripProfile(const edm::ParameterSet&);
  ~RPCStripProfile();
  virtual void beginJob(const edm::EventSetup&) ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  
  typedef vector<Trajectory> Trajectories;
  map<string, MonitorElement*> DraftbookDetUnitTrackEff(RPCDetId& , const EventSetup&);
  map<string, map<string, MonitorElement*> > noiseRPCbookDet( const EventSetup& );
  inline ESHandle<Propagator> propagator() const;  
  
private:
  bool EffSaveRootFile, Verbose_ ;
  vector<string> RPC_idList;

  // noise container                                                                                                                                  
  map<RPCDetId,int> noiseMap;
  map<RPCDetId,float> areaMap;

  int Run;
  int eventNumber;
  int ientry;
  time_t aTime;

  // global histograms                                                                                                                                
  TH1F * hNoiseBX, * hNoiseBX_v07, * hnTracksPerEvent,* hnTracksPerEvent_noisyRPC;
  TH1F * hNoiseByRoll;
  TH1F * eventperbin;
  TH1F * h_RPCStripsByEvent,* h_NoisyStripsByEvent, * h_NoisyRollsByEvent, * h_NoisyStripsByRoll;

  TH2F * hRPCGlobalXY, *hRPCnoiseXY_wm2, *hRPCnoiseXY_wm1, *hRPCnoiseXY_w0, *hRPCnoiseXY_wp1, *hRPCnoiseXY_wp2;

  uint32_t minRPCHits_ ;
  InputTag DT4DSegments_;
  InputTag CSCSegments_;
  InputTag RPCRecHits_;
  InputTag RPCDigis_;
  InputTag Tracks_;
  bool Debug_;
  string Propagator_, Eff_, Ineff_;
  int minNum_;
  // counters of n seg per chamber and per track                                                                                                      
  int n1seg0tkSeg, n1seg1tkSeg, n2seg0tkSeg, n2seg1tkSeg;
  // counters for noise study                                                                                                                         
  int nEvents;
  int barrel_timeEv[5][12];
  vector< RPCRoll*> RPCrolls;
  map<string,RPCDetId> RPCNameMap;
  map<RPCDetId,int> segmentCounter, goodMatches, badMatches;
  map<string, map<string, MonitorElement*> >  meCollection;
  map<RPCDetId,int> mapForFilling;
  map<int, map<RPCDetId,int > > wheelMap;
  map<int,TH2F*> wheelsPred, wheelsObs,wheelsEff;

  InputTag thePropagatorName;
  mutable Propagator* prop;

  SegmentToTrackAssociator *theSegmentsAssociator;

  std::vector<TH2F*> chamhis;
  int hours;
  int reg;
  int subreg;
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

RPCStripProfile::RPCStripProfile(const edm::ParameterSet& iConfig)
{
  
 //now do what ever initialization is needed

  const ParameterSet SegmentsTrackAssociatorParameters = iConfig.getParameter<ParameterSet>("SegmentsTrackAssociatorParameters");
  theSegmentsAssociator = new SegmentToTrackAssociator(SegmentsTrackAssociatorParameters);

  //debug                                                                                                                                             
  Debug_ = iConfig.getUntrackedParameter<bool>("Debug",false);

  //verbose                                                                                                                                           
  Verbose_ = iConfig.getUntrackedParameter<bool>("Verbose",false);

  //RPC hits and digis                                                                                                                                
  RPCRecHits_ = iConfig.getParameter<InputTag>("RPCRecHits");
  RPCDigis_ =  iConfig.getParameter<InputTag>("RPCDigis");
  DT4DSegments_ = iConfig.getParameter<InputTag>("DT4DSegments");
  CSCSegments_ = iConfig.getParameter<InputTag>("CSCSegments");

  //Reconstructed tracks                                                                                                                              
  Tracks_ = iConfig.getParameter<InputTag>("Tracks");

  //Propagator for track-RPC intersections                                                                                                            
  Propagator_ = iConfig.getParameter<string>("Propagator");


  //cut values                                                                                                                                        
  // minRPCHits_ = iConfig.getUntrackedParameter<int>("minimumNumberOfRPCHits",0);                                                                        
  m_GMTInputTag = iConfig.getParameter<edm::InputTag>("GMTInputTag");
  hours = iConfig.getUntrackedParameter<int>("bins");
  reg = iConfig.getUntrackedParameter<int>("region");
  subreg = iConfig.getUntrackedParameter<int>("subregion");



}


RPCStripProfile::~RPCStripProfile()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
RPCStripProfile::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

   edm::ESHandle<RPCGeometry> rpcGeo;
   iSetup.get<MuonGeometryRecord>().get(rpcGeo);
   std::string name;
   std::string name1;
   edm::Handle<RPCDigiCollection> rpcdigis;
   //   iEvent.getByLabel("muonRPCDigis",rpcdigis);
   iEvent.getByLabel(m_GMTInputTag,rpcdigis);///"muonRPCDigis",rpcdigis);
   float tempo = iEvent.id().event()/20000;

   eventperbin->Fill(tempo);

   int bx = iEvent.bunchCrossing();
   int thisOrbit = iEvent.orbitNumber();
   double orbitTime = 0.03564*(double)thisOrbit +(double)((double)bx/100000.0);
   //   unsigned long long tempo = (orbitTime/10000)*25;
   //tempo = iEvent.id().event()/100;
   /*   TimeValue_t time=iEvent.time().value();
   timeval *tmval=(timeval*)&time;
   if(!inicio){
     primotempo = tmval->tv_usec;
     inicio = true;
     }*/
   //   unsigned long long tempo;
   //   unsigned long long tempo1 = tmval->tv_usec - primotempo;

   //trigger =  false;

   if(Debug_) //cout<< " mark 0 "<<endl;

   //some variables to be used for the storage names                                                                                                   
   char meIdRPC [128];
   char meIdNoiseRPC [128];

   // Get the DT 4D segment collection from the event                                                                                                  
   Handle<DTRecSegment4DCollection> allDT4DSegments;
   iEvent.getByLabel(DT4DSegments_, allDT4DSegments);

   //RPC hits and digis                                                                                                                                
   Handle<RPCRecHitCollection > rpcRecHits;
   iEvent.getByLabel(RPCRecHits_,rpcRecHits);

   //Input tracks                                                                                                                                      
   edm::Handle< edm::View < reco::Track > > Tracks;
   iEvent.getByLabel(Tracks_,Tracks);

   //Geometry, magnetic field and tracks                                                                                                               
   ESHandle<MagneticField> MagneticField;
   iSetup.get<IdealMagneticFieldRecord>().get(MagneticField);

   ESHandle<DTGeometry> dtGeometry;
   iSetup.get<MuonGeometryRecord>().get(dtGeometry);

   ESHandle<CSCGeometry> cscGeometry;
   iSetup.get<MuonGeometryRecord>().get(cscGeometry);

   ESHandle<RPCGeometry> rpcGeometry;
   iSetup.get<MuonGeometryRecord>().get(rpcGeometry);

   ESHandle<Propagator> propagator;
   iSetup.get<TrackingComponentsRecord>().get(Propagator_, propagator);

   ESHandle<GlobalTrackingGeometry> TrackingGeometry;
   iSetup.get<GlobalTrackingGeometryRecord>().get(TrackingGeometry);

   Run = iEvent.id().run();
   eventNumber = iEvent.id().event();
   ientry++;
   // reset barrel sector container for noise studies                                                                                                  
   bool taggedBarrelSectors[5][12];
   for (int i=0;i<5;i++) { // 12 sectors                                                                                                               
     for (int j=0;j<12;j++) {  // 5 wheels                                                                                                             
       taggedBarrelSectors[i][j]=false;
     }
   }


   map<DTChamberId,int> nSegmentsByChamber, nTrackSegmentsByChamber;
   std::vector<DTChamber*> DTChamberList = dtGeometry->chambers();
   std::vector<DTChamber*>::iterator itDTChamberList;

   // reset DT segment by chamber container                                                                                                            
   for(itDTChamberList = DTChamberList.begin(); itDTChamberList != DTChamberList.end(); itDTChamberList++) {
     DTChamber* theDTChamber = (*itDTChamberList);
     nSegmentsByChamber[(*theDTChamber).id()]=0;
     nTrackSegmentsByChamber[(*theDTChamber).id()]=0;
   }


   //loop over the tracks                                                                                                                              
   if(Debug_) //cout<< " mark 1 "<<endl;
   //cout <<"Tracks size " << Tracks->size() << endl;
   // check all DT segments                                                                                                                            
   //cout <<"AllDTsegments size " << allDT4DSegments->size() << endl;

   hnTracksPerEvent->Fill(Tracks->size());
   //cout << "mark 1" << endl;
   // maps for checks of nosiy strips, and noisy rolls per event                                                                                       
   int tempNumberNoisyStripsByEvent=0;
   map<RPCDetId,bool> tempMapIsNoisyRoll;
   map<RPCDetId,int> tempMapNumberNoisyStripsByRoll;
   for(vector< RPCRoll*>::iterator RPCIt = RPCrolls.begin(); RPCIt != RPCrolls.end();RPCIt++){
     RPCDetId detId = (*RPCIt)->id();
     tempMapNumberNoisyStripsByRoll[detId] = 0;
     tempMapIsNoisyRoll[detId] = false;
   }
   nEvents++;
   // loop over all DT segments                                                                                                                        
   int isg2=0;
   //cout << "mark 2" << endl;
   for (DTRecSegment4DCollection::const_iterator segment4D = allDT4DSegments->begin();
	segment4D!=allDT4DSegments->end();
	++segment4D){
     isg2++;
     const DTChamber* ch = dtGeometry->chamber(segment4D->chamberId());
     //     int station = (*ch).id().station();
     int sector = (*ch).id().sector();
     int wheel = (*ch).id().wheel();
     nSegmentsByChamber[(*ch).id()]++;
     // tag sectors where segments are found (so i'll study the noise in other sectors)                                                                
     if ((*ch).id().sector()==13) sector = 4;   // sector 13 means one of the two station 4 of sector 4                                                
     if ((*ch).id().sector()==14) sector = 10;  // sector 14 means one of the two station 4 of sector 10                                               
     taggedBarrelSectors[wheel+2][sector-1] = true;
   }
   //cout << "mark 3" << endl;
   // increment timeVector just for sectors not involved by segments (is needed to calculate total daq time for noise measurement)                     
   for (int i=0;i<5;i++) {
     for (int j=0;j<12;j++) {
       if (!taggedBarrelSectors[i][j]) barrel_timeEv[i][j]++;
     }
   }
   // loop on RPC REC HIts and fill occupancy plots                                                                                                    
   //cout << "mark 4" << endl;
   int irpcRec=0;
   int rpcStripsByEvent=0;
   for (RPCRecHitCollection::const_iterator rpc_it = rpcRecHits->begin(); rpc_it!=rpcRecHits->end(); ++rpc_it){
     irpcRec++;
     RPCDetId detId=rpc_it->rpcId();

     RPCGeomServ RPCname(detId);
     const RPCRoll * r1;
     r1 = rpcGeometry->roll(detId);

     string nameRoll = RPCname.name();
     int rpcStrip = rpc_it->firstClusterStrip();
     int rpcMult = rpc_it->clusterSize();
     LocalPoint recHitLocal = rpc_it->localPosition();
     if (r1->isBarrel()) rpcStripsByEvent += rpcMult;

     // occupancy                                                                                                                                      
     GlobalPoint rpcGlobalPos= r1->surface().toGlobal(recHitLocal);
     float xrpc = rpcGlobalPos.x();
     float yrpc = rpcGlobalPos.y();

     if (r1->isBarrel()) hRPCGlobalXY->Fill(xrpc,yrpc);

     char detUnitLabel[128];
     //cout << "mark 4.1" << endl;
     sprintf(detUnitLabel ,"%s",nameRoll.c_str());

     map<string, map<string,MonitorElement*> >::iterator meItr = meCollection.find(nameRoll);
     map<string, MonitorElement*> meMap=meCollection[nameRoll];
     //     sprintf(meIdRPC,"RPCDataOccupancy_%s",detUnitLabel);
     //cout << "mark 4.2" << endl;
     //     for (int i=rpcStrip; i<rpcStrip+rpcMult; i++) meMap[meIdRPC]->Fill(i);
     //cout << "mark 4.3" << endl;
     if (!taggedBarrelSectors[detId.ring()+2][detId.sector()-1] ) { // not related to any DT segment i assume is rpc noise                             
       hnTracksPerEvent_noisyRPC->Fill(Tracks->size());
       //cout << "mark 4.4" << endl;
       sprintf(meIdNoiseRPC,"RPCNoiseOccupancy_%s",detUnitLabel);
       //       meMap[meIdNoiseRPC]->Fill(rpcStrip);  // fill just the first strip. I really want to count the cluters not the fired strips                     
       noiseMap[detId]++;
       //cout << "mark 4.5" << endl;
       if (r1->isBarrel()) {  // this part just for barrel                                                                                             
	 tempMapIsNoisyRoll[detId] = true;
	 tempMapNumberNoisyStripsByRoll[detId]+=rpcMult;
	 tempNumberNoisyStripsByEvent+=rpcMult;
	 //cout << "mark 4.6" << endl;
	 if (detId.ring()==-2) hRPCnoiseXY_wm2->Fill(xrpc,yrpc);
	 if (detId.ring()==-1) hRPCnoiseXY_wm1->Fill(xrpc,yrpc);
	 if (detId.ring()==0) hRPCnoiseXY_w0->Fill(xrpc,yrpc);
	 if (detId.ring()==1) hRPCnoiseXY_wp1->Fill(xrpc,yrpc);
	 if (detId.ring()==2) hRPCnoiseXY_wp2->Fill(xrpc,yrpc);
	 //cout << "mark 4.7" << endl;
	 hNoiseBX->Fill(rpc_it->BunchX());
       }
     }
   }
   //cout << "mark 5" << endl;
   // fill histos for nosisy strips and rolls by event (barrel only)                                                                                   
   int nNoisyRolls=0;
   h_NoisyStripsByEvent->Fill(tempNumberNoisyStripsByEvent);
   h_RPCStripsByEvent->Fill(rpcStripsByEvent);
   for(vector< RPCRoll*>::iterator RPCIt = RPCrolls.begin(); RPCIt != RPCrolls.end();RPCIt++){
     RPCDetId detId = (*RPCIt)->id();
     if (tempMapIsNoisyRoll[detId]) {
       nNoisyRolls++;
       h_NoisyStripsByRoll->Fill(tempMapNumberNoisyStripsByRoll[detId]);
     }
   }
   //cout << "mark 6" << endl;
   h_NoisyRollsByEvent->Fill(nNoisyRolls);
   //cout << "entry: " << ientry << "    run " << Run << " event " << eventNumber << "  noisy strips " << tempNumberNoisyStripsByEvent << "    noisy rolls " << nNoisyRolls << "      total strips " << rpcStripsByEvent << endl;
   for(size_t trackidx = 0; trackidx < Tracks->size(); trackidx++){
     //     double pt = (*Tracks)[trackidx].pt();
     //    hTrackPt->Fill(pt);                                                                                                                         
     //    histoTrackSize->Fill(Tracks->size());                                                                                                       
     reco::Track recoTrack((*Tracks)[trackidx]);
     reco::TransientTrack track((*Tracks)[trackidx], &*MagneticField, TrackingGeometry);

     //    histoChi2->Fill(track.normalizedChi2());                                                                                                    
     // get segments from track                                                                                                                        

     MuonTransientTrackingRecHit::MuonRecHitContainer segmentsFromTrack = theSegmentsAssociator->associate(iEvent, iSetup, recoTrack , "CosmicLike");
     int iseg=0;
     for (MuonTransientTrackingRecHit::MuonRecHitContainer::const_iterator segment=segmentsFromTrack.begin();
	  segment!=segmentsFromTrack.end(); segment++) {

       DetId id = (*segment)->geographicalId();

       iseg++;
       // hits from DT segments                                                                                                                        
       if (id.det() == DetId::Muon && id.subdetId() == MuonSubdetId::DT ) {
	 const DTRecSegment4D *seg4D = dynamic_cast<const DTRecSegment4D*>((*segment)->hit());
	 const DTChamber* ch = dtGeometry->chamber(seg4D->chamberId());
	 //	 int station = (*ch).id().station();
	 //	 int sector = (*ch).id().sector();
	 //	 int wheel = (*ch).id().wheel();
	 if((*seg4D).hasPhi())
	   nTrackSegmentsByChamber[(*ch).id()]++;
	 /*float xDT = (*seg4D).localPosition().x();
	 float yDT = (*seg4D).localPosition().y();
	 float zDT = (*seg4D).localPosition().z();
	 float dxdzDT = (*seg4D).localDirection().x()/(*seg4D).localDirection().z();
	 float dydzDT = (*seg4D).localDirection().y()/(*seg4D).localDirection().z();
	 */
       }

       // hits from CSC segments                                                                                                                       
       if (id.det() == DetId::Muon && id.subdetId() == MuonSubdetId::CSC ) {
	 //      cout << "segment " << iseg << " is a CSC segment  " << endl;                                                                          
	 //      cout << "CSC segment size" << (*segment)->recHits().size() << endl;                                                                   
       }
     }
   } // end loop on muon tracks                                                                                                                        
   //cout << "mark 7" << endl;
   for(itDTChamberList = DTChamberList.begin(); itDTChamberList != DTChamberList.end(); itDTChamberList++) {
     DTChamber* theDTChamber = (*itDTChamberList);
     if (nSegmentsByChamber[(*theDTChamber).id()]==1) {
       if (nTrackSegmentsByChamber[(*theDTChamber).id()]==1) n1seg1tkSeg++;
       if (nTrackSegmentsByChamber[(*theDTChamber).id()]==0) n1seg0tkSeg++;
     }
     if (nSegmentsByChamber[(*theDTChamber).id()]==2) {
       if (nTrackSegmentsByChamber[(*theDTChamber).id()]==1) n2seg1tkSeg++;
       if (nTrackSegmentsByChamber[(*theDTChamber).id()]==0) n2seg0tkSeg++;
     }

   }


   for (TrackingGeometry::DetContainer::const_iterator it=rpcGeo->dets().begin();it<rpcGeo->dets().end();it++){
     if(dynamic_cast< RPCChamber* >( *it ) != 0 ){
       RPCChamber* ch = dynamic_cast< RPCChamber* >( *it );
       std::vector< const RPCRoll*> roles = (ch->rolls());
       
       for(std::vector<const RPCRoll*>::const_iterator h = roles.begin();h != roles.end(); ++h){
	 RPCDetId rpcId1 = (*h)->id();
	 RPCDigiCollection::Range rpcRangeDigi=rpcdigis->get(rpcId1);
	 RPCGeomServ rpcsrv(rpcId1);
	 if (!taggedBarrelSectors[rpcId1.ring()+2][rpcId1.sector()-1] ) { // not related to any DT segment i assume is rpc noise                             
	 for (RPCDigiCollection::const_iterator digiIt = rpcRangeDigi.first;digiIt!=rpcRangeDigi.second;++digiIt){
	   
	   for(std::vector< TH2F* >::const_iterator r = chamhis.begin(); r != chamhis.end(); ++r){
	     name = (*r)->GetName();	   
	     name1 = rpcsrv.name(); 
	     //	     std::cout << "name histogram: " << name << " name geometry: " << name1 << " digis: " << (*digiIt).strip()  << " name compare: " << strcmp(name.c_str(),name1.c_str()) << std::endl;
	     if( strcmp(name.c_str(),name1.c_str()) == 0 ){

	       //	       std::cout << "tempo: " << tempo << " strip: " << (*digiIt).strip() << std::endl;
	       (*r)->Fill((int)tempo,(*digiIt).strip());
	     }
	   }
	 }
	 }
       }
     }
   }
}


// ------------ method called once each job just before starting event loop  ------------
void 
RPCStripProfile::beginJob(const edm::EventSetup& iSetup)
{
   edm::ESHandle<RPCGeometry> rpcGeo;
   iSetup.get<MuonGeometryRecord>().get(rpcGeo);
   edm::Service<TFileService> fservice;

   //  dbe = Service<DQMStore>().operator->();
   
   //   hl1em = fservice->make<TH1F>("OrbitTimelhccond","Orbit Time",54000,0,54000);
   
   hNoiseBX = fservice->make<TH1F>("noiseBX","noiseBX",7,-3.5,3.5);
   hNoiseByRoll = fservice->make<TH1F>("noiseByRoll","noise by roll",100,0.,1.);
   hnTracksPerEvent = fservice->make<TH1F>("nTrackPerEvent","n.of tracks per event",7,-.5,6.5);
   hnTracksPerEvent_noisyRPC = fservice->make<TH1F>("nTrackPerEvent_noisyRPC","n.of tracks per event (noisy RPC)",7,-.5,6.5);
   
   h_RPCStripsByEvent = fservice->make<TH1F>("NumberRPCStripsByEvent","Number of RPC strips By event",100,-.5,99.5);
   h_NoisyStripsByEvent = fservice->make<TH1F>("NumberNoisyStripsByEvent","Number of Noisy strips By event",100,-.5,99.5);
   h_NoisyRollsByEvent = fservice->make<TH1F>("NumberNoisyRollsByEvent","Number of Noisy Rolls By event",100,-.5,99.5);
   h_NoisyStripsByRoll = fservice->make<TH1F>("NumberNoisyStripsByRoll","Number of Noisy strips By roll",100,-.5,99.5);
   
   // occupancy                                                                                                                                        
   hRPCGlobalXY = fservice->make<TH2F>("RPCGlobalXY","RPC cluster global position",800,-800.,800.,800,-800.,800.);
   hRPCnoiseXY_wm2 = fservice->make<TH2F>("RPCnoiseXY_w-2","RPC noise cluster position (W-2)",800,-800.,800.,800,-800.,800.);
   hRPCnoiseXY_wm1 = fservice->make<TH2F>("RPCnoiseXY_w-1","RPC noise cluster position (W-1)",800,-800.,800.,800,-800.,800.);
   hRPCnoiseXY_w0 = fservice->make<TH2F>("RPCnoiseXY_w0","RPC noise cluster position (W0)",800,-800.,800.,800,-800.,800.);
   hRPCnoiseXY_wp1 = fservice->make<TH2F>("RPCnoiseXY_w+1","RPC noise cluster position (W+1)",800,-800.,800.,800,-800.,800.);
   hRPCnoiseXY_wp2 = fservice->make<TH2F>("RPCnoiseXY_w+2","RPC noise cluster position (W+2)",800,-800.,800.,800,-800.,800.);
   
   TH2F* histo;

   int time = hours;

   eventperbin = fservice->make<TH1F>("Timeperbin","Time per bin",time,0,time);
   for (TrackingGeometry::DetContainer::const_iterator it=rpcGeo->dets().begin();it<rpcGeo->dets().end();it++){
     if(dynamic_cast< RPCChamber* >( *it ) != 0 ){
       RPCChamber* ch = dynamic_cast< RPCChamber* >( *it );
       std::vector< const RPCRoll*> roles = (ch->rolls());
       
       for(std::vector<const RPCRoll*>::const_iterator h = roles.begin();h != roles.end(); ++h){
	 RPCDetId rpcId1 = (*h)->id();
	 RPCGeomServ rpcsrv(rpcId1);

	 std::string nombre = rpcsrv.name();
	 if(reg == 0){
	   if( rpcId1.region() == reg and rpcId1.ring() == subreg){
	     histo = fservice->make<TH2F>(nombre.c_str(),nombre.c_str(),(int)time,0.,(double)time,(int)(*h)->nstrips(),1,(double)(*h)->nstrips()+1);
	     chamhis.push_back(histo);
	     //	     std::cout << rpcsrv.name() << " number of strips: " <<  (*h)->nstrips() << std::endl;
	   }
	 }
	 else{
	   if(rpcId1.region()==reg and rpcId1.station()==subreg){
	     histo = fservice->make<TH2F>(nombre.c_str(),nombre.c_str(),(int)time,0.,(double)time,(int)(*h)->nstrips(),0.,(double)(*h)->nstrips());
	     chamhis.push_back(histo);
	     //	     std::cout << rpcsrv.name() << " number of strips: " <<  (*h)->nstrips() << std::endl;
	   }
	 }
       }
     }
   }
   ESHandle<RPCGeometry> rpcGeometry;
   iSetup.get<MuonGeometryRecord>().get(rpcGeometry);
   RPCrolls= rpcGeometry->rolls() ;
   ientry=0;
   for(vector< RPCRoll*>::iterator RPCIt = RPCrolls.begin(); RPCIt != RPCrolls.end();RPCIt++){
     RPCDetId detId = (*RPCIt)->id();
     // reset noise map
     noiseMap[detId] =0;    
     // roll dimension
     float stripLength = (*RPCIt)->surface().bounds().length();
     float rollWidth = (*RPCIt)->nstrips() * (*RPCIt)->pitch();
     float area = stripLength * rollWidth;
     RPCGeomServ RPCname(detId);
     areaMap[detId] = area;
     //    cout << "roll " << RPCname.name() << "  stripLength: " << stripLength << "   nstirps " << (*RPCIt)->nstrips() << "  pitch " <<(*RPCIt)->pitch() << " rollWidth " << rollWidth << "   area " << area << endl;
   }    


   //book all the RPC
   //   meCollection = noiseRPCbookDet(iSetup)  ;
   n1seg0tkSeg=0;
   n1seg1tkSeg=0;
   n2seg0tkSeg=0;
   n2seg1tkSeg=0;
   // reset noise variables
   nEvents=0;
   for (int i=0;i<5;i++) {
     for (int j=0;j<12;j++) {
       barrel_timeEv[i][j]=0;
     }
   }
}

// ------------ method called once each job just after ending the event loop  ------------
void 
RPCStripProfile::endJob() {
  for(std::vector< TH2F* >::const_iterator r = chamhis.begin(); r != chamhis.end(); ++r){
    (*r)->SetOption("COLZ");
  }
  //////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////

  cout << "**** Summary **** " << endl;
  cout << "segments:   1 segment in chamber, 0 segment from track " << n1seg0tkSeg << endl;
  cout << "segments:   2 or more segment in chamber, 0 segment from track " << n2seg0tkSeg << endl;
  cout << "segments:   1 segment in chamber, 1 segment from track " << n1seg1tkSeg << endl;
  cout << "segments:   2 or more segment in chamber, 1 segment from track " << n2seg1tkSeg << endl;

  cout << "*** Noise summary *** " << endl;
  cout << "Total number of events " << nEvents << endl;
  for (int i=0;i<5;i++) {
    for (int j=0;j<12;j++) {
      cout << "Wheel " << i-2 << "  sector " << j+1 << "  time integral " << barrel_timeEv[i][j] << endl;;
    }
  }
  for(vector< RPCRoll*>::iterator RPCIt = RPCrolls.begin(); RPCIt != RPCrolls.end();RPCIt++){
    RPCDetId detId = (*RPCIt)->id();
    RPCGeomServ RPCname(detId);
    if ((*RPCIt)->isBarrel()) {
      double timeDAQ = barrel_timeEv[detId.ring()+2][detId.sector()-1]*175.*1.0E-9; // total number of tagged events * 7 bx
      double area = areaMap[detId];
      double noise;
      if (timeDAQ>0) {
	noise = noiseMap[detId]/(area*timeDAQ);
      } else {noise = -1.;}
      cout << "roll " << RPCname.name() << "  noise: " << noiseMap[detId] << " time integrated " << timeDAQ << " noise Norm " << noise << endl;
      hNoiseByRoll->Fill(noise);      
    }
  }    
 


  ////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////

}

//define this as a plug-in
DEFINE_FWK_MODULE(RPCStripProfile);
