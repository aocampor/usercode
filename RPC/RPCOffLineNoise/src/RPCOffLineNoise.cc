// -*- C++ -*-
//
// Package:    RPCOffLineNoise
// Class:      RPCOffLineNoise
// 
/**\class RPCOffLineNoise RPCOffLineNoise.cc UserCode/RPCOffLineNoise/src/RPCOffLineNoise.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Alberto Andres Ocampo Rios
//         Created:  Wed Feb 25 09:44:49 CET 2009
// $Id: RPCOffLineNoise.cc,v 1.6 2009/10/29 15:33:51 aocampor Exp $
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
#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
///Data Format 

#include "DataFormats/RPCDigi/interface/RPCDigi.h"
#include "DataFormats/RPCDigi/interface/RPCDigiCollection.h"
#include "DataFormats/MuonDetId/interface/RPCDetId.h"
#include "DataFormats/RPCRecHit/interface/RPCRecHitCollection.h"
#include "DataFormats/GeometrySurface/interface/LocalError.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "DataFormats/Common/interface/Handle.h"
///Geometry 

#include "Geometry/RPCGeometry/interface/RPCGeometry.h"
#include "Geometry/Records/interface/MuonGeometryRecord.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"
#include "Geometry/RPCGeometry/interface/RPCGeomServ.h"
#include "Geometry/CommonTopologies/interface/RectangularStripTopology.h"
#include "Geometry/RPCGeometry/interface/RPCRollSpecs.h"
#include "Geometry/CommonTopologies/interface/StripTopology.h"
/////Trigger
/*
#include "DataFormats/L1Trigger/interface/L1MuonParticle.h"
#include "DataFormats/L1Trigger/interface/L1MuonParticleFwd.h"
#include "DataFormats/L1GlobalMuonTrigger/interface/L1MuRegionalCand.h"
#include "DataFormats/L1GlobalMuonTrigger/interface/L1MuGMTReadoutCollection.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutRecord.h"
#include "DataFormats/L1GlobalCaloTrigger/interface/L1GctEtSums.h"
#include "DataFormats/L1GlobalCaloTrigger/interface/L1GctCollections.h"
#include "DataFormats/L1GlobalCaloTrigger/interface/L1GctJetCounts.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerEvmReadoutRecord.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerObjectMapRecord.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerObjectMap.h"
#include "DataFormats/L1GlobalMuonTrigger/interface/L1MuGMTCand.h"
#include "DataFormats/L1GlobalMuonTrigger/interface/L1MuGMTExtendedCand.h"*/
#include "DataFormats/Provenance/interface/Timestamp.h"
#include "DataFormats/MuonDetId/interface/MuonSubdetId.h"
#include <DataFormats/RPCRecHit/interface/RPCRecHit.h>
#include "DataFormats/GeometrySurface/interface/LocalError.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "DataFormats/GeometrySurface/interface/Surface.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/TrackReco/interface/Track.h"/*
#include "CondFormats/L1TObjects/interface/L1GtParameters.h"
#include "CondFormats/DataRecord/interface/L1GtParametersRcd.h"*/
////Davide
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
#include "CommonTools/UtilAlgos/interface/TFileService.h"
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


class RPCOffLineNoise : public edm::EDAnalyzer {
public:
  explicit RPCOffLineNoise(const edm::ParameterSet& );
  ~RPCOffLineNoise();
  virtual void beginRun(edm::Run const&, edm::EventSetup const&);
  virtual void endRun(edm::Run const&, edm::EventSetup const&);
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  
  typedef vector<Trajectory> Trajectories;
  map<string, MonitorElement*> DraftbookDetUnitTrackEff(RPCDetId& , const EventSetup&);
  map<string, map<string, MonitorElement*> > noiseRPCbookDet( const EventSetup& );
  inline ESHandle<Propagator> propagator() const;
  
private:
  
  virtual void BookFile();

  bool EffSaveRootFile, Verbose_ ;
  vector<string> RPC_idList;

  // noise container                                                                                                                                  
  map<RPCDetId,int> noiseMap;
  map<RPCDetId,float> areaMap;

  int Run;
  int eventNumber;
  int ientry;
  time_t aTime;

  // ofstream* effFile;                                                                                                                               
  //  ofstream* inefficient;                                                                                                                          
  //  string EffRootFileName;                                                                                                                         

  //  vector<RPCRoll *> sortedRolls;                                                                                                                  

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


  //  DQMStore * dbe;


  int binnum;

  //  TFile *hfile;

  std::string nomrootfile;
  edm::InputTag m_GMTInputTag;
  std::string labelDT;
  bool noise_flag;
  int noise_limit;
  int hours;
  bool inicio;

  bool trigger; 
  int bxtrigger ;

  unsigned long long primotempo;
  double rawm2[12]; 
  double rawm1[12]; 
  double raw0[12]; 
  double raw1[12]; 
  double raw2[12]; 
  double rawd1[18];
  double rawd2[18];
  double rawd3[18];


  bool area;

  TH1F *hl1em;
  TH1F *occbarrel;
  TH1F *occbarrel1;
  TH1F *occEnd;
  TH2F *occwheelbarrel;
  TH2F *occdiskendcap;
  TH2F *occbrlend;

  std::vector<std::string> wheels;
  std::vector<std::string> sec;
  std::vector<std::string> rbs;
  std::vector<std::string> dir;
  std::vector<std::string> disks;
  std::vector<std::string> RES;
  std::vector<std::string> secd;
  std::vector<std::string> secdis;
  std::vector<std::string> dirdis;

  std::vector<TH2F*> wheelhis;
  std::vector<TH2F*> diskhis;
  std::vector<TH2F*> chamwheelhis;
  std::vector<TH2F*> chamdiskhis;

  std::vector<TH1F*> wheelprof;
  std::vector<TH1F*> diskprof;
  std::vector<TH1F*> chamwheelprof;
  std::vector<TH1F*> chamdiskprof;
  std::vector<TH1F*> towerprof;
  std::vector<TH1F*> wheelNoiseDist;
  std::vector<TH1F*> diskNoiseDist;

  TH1F *brlNoiseDist, *fwdNoiseDist, *overallNoiseDist;
  Service<TFileService> fs;
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
RPCOffLineNoise::RPCOffLineNoise(const edm::ParameterSet& iConfig)
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

  nomrootfile = iConfig.getUntrackedParameter<std::string>("root_file_name","RPCTriggerNoise.root");
  m_GMTInputTag = iConfig.getParameter<edm::InputTag>("GMTInputTag");
  //binnum = iConfig.getUntrackedParameter<int>("bins");
  labelDT = iConfig.getUntrackedParameter<std::string>("labelDT");
  noise_flag = iConfig.getUntrackedParameter<bool>("noise");
  noise_limit = iConfig.getUntrackedParameter<int>("limit");
  hours = iConfig.getUntrackedParameter<int>("bins");
  BookFile();
  inicio = false;
  area = false;

}


RPCOffLineNoise::~RPCOffLineNoise()
{
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)
}

void RPCOffLineNoise::BookFile(){


  wheels.push_back("W-2");
  wheels.push_back("W-1");
  wheels.push_back("W+0");
  wheels.push_back("W+1");
  wheels.push_back("W+2");

  sec.push_back("S01");
  sec.push_back("S02");
  sec.push_back("S03");
  sec.push_back("S04");
  sec.push_back("S05");
  sec.push_back("S06");
  sec.push_back("S07");
  sec.push_back("S08");
  sec.push_back("S09");
  sec.push_back("S10");
  sec.push_back("S11");
  sec.push_back("S12");

  rbs.push_back("RB1in");
  rbs.push_back("RB1out");
  rbs.push_back("RB2in");
  rbs.push_back("RB2out");
  rbs.push_back("RB3+");
  rbs.push_back("RB3-");
  rbs.push_back("RB4+");
  rbs.push_back("RB4-");
  rbs.push_back("RB4++");
  rbs.push_back("RB4+-");
  rbs.push_back("RB4--");
  rbs.push_back("RB4-+");

  dir.push_back("Forward");
  dir.push_back("Backward");
  dir.push_back("Middle");

  disks.push_back("R1");
  disks.push_back("R2");
  disks.push_back("R3");

  RES.push_back("RE-3");
  RES.push_back("RE-2");
  RES.push_back("RE-1");
  RES.push_back("RE+1");
  RES.push_back("RE+2");
  RES.push_back("RE+3");

  secd.push_back("S01");
  secd.push_back("S02");
  secd.push_back("S03");
  secd.push_back("S04");
  secd.push_back("S05");
  secd.push_back("S06");

  secdis.push_back("CH01");
  secdis.push_back("CH02");
  secdis.push_back("CH03");
  secdis.push_back("CH04");
  secdis.push_back("CH05");
  secdis.push_back("CH06");
  secdis.push_back("CH07");
  secdis.push_back("CH08");
  secdis.push_back("CH09");
  secdis.push_back("CH10");
  secdis.push_back("CH11");
  secdis.push_back("CH12");
  secdis.push_back("CH13");
  secdis.push_back("CH14");
  secdis.push_back("CH15");
  secdis.push_back("CH16");
  secdis.push_back("CH17");
  secdis.push_back("CH18");
  secdis.push_back("CH19");
  secdis.push_back("CH20");
  secdis.push_back("CH21");
  secdis.push_back("CH22");
  secdis.push_back("CH23");
  secdis.push_back("CH24");
  secdis.push_back("CH25");
  secdis.push_back("CH26");
  secdis.push_back("CH27");
  secdis.push_back("CH28");
  secdis.push_back("CH29");
  secdis.push_back("CH30");
  secdis.push_back("CH31");
  secdis.push_back("CH32");
  secdis.push_back("CH33");
  secdis.push_back("CH34");
  secdis.push_back("CH35");
  secdis.push_back("CH36");

  dirdis.push_back("A");
  dirdis.push_back("B");
  dirdis.push_back("C");

  //Histograms                                                                                                                                        
  //  Service<TFileService> fs;
  //  dbe = Service<DQMStore>().operator->();

  hl1em = fs->make<TH1F>("OrbitTimelhccond","Orbit Time",54000,0,54000);

  hNoiseBX = fs->make<TH1F>("noiseBX","noiseBX",7,-3.5,3.5);
  hNoiseByRoll = fs->make<TH1F>("noiseByRoll","noise by roll",10000,0.,100.);
  hnTracksPerEvent = fs->make<TH1F>("nTrackPerEvent","n.of tracks per event",7,-.5,6.5);
  hnTracksPerEvent_noisyRPC = fs->make<TH1F>("nTrackPerEvent_noisyRPC","n.of tracks per event (noisy RPC)",7,-.5,6.5);

  h_RPCStripsByEvent = fs->make<TH1F>("NumberRPCStripsByEvent","Number of RPC strips By event",100,-.5,99.5);
  h_NoisyStripsByEvent = fs->make<TH1F>("NumberNoisyStripsByEvent","Number of Noisy strips By event",100,-.5,99.5);
  h_NoisyRollsByEvent = fs->make<TH1F>("NumberNoisyRollsByEvent","Number of Noisy Rolls By event",100,-.5,99.5);
  h_NoisyStripsByRoll = fs->make<TH1F>("NumberNoisyStripsByRoll","Number of Noisy strips By roll",100,-.5,99.5);

  // occupancy                                                                                                                                        
  hRPCGlobalXY = fs->make<TH2F>("RPCGlobalXY","RPC cluster global position",800,-800.,800.,800,-800.,800.);
  hRPCnoiseXY_wm2 = fs->make<TH2F>("RPCnoiseXY_w-2","RPC noise cluster position (W-2)",800,-800.,800.,800,-800.,800.);
  hRPCnoiseXY_wm1 = fs->make<TH2F>("RPCnoiseXY_w-1","RPC noise cluster position (W-1)",800,-800.,800.,800,-800.,800.);
  hRPCnoiseXY_w0 = fs->make<TH2F>("RPCnoiseXY_w0","RPC noise cluster position (W0)",800,-800.,800.,800,-800.,800.);
  hRPCnoiseXY_wp1 = fs->make<TH2F>("RPCnoiseXY_w+1","RPC noise cluster position (W+1)",800,-800.,800.,800,-800.,800.);
  hRPCnoiseXY_wp2 = fs->make<TH2F>("RPCnoiseXY_w+2","RPC noise cluster position (W+2)",800,-800.,800.,800,-800.,800.);

  binnum = hours;

  occbarrel = fs->make<TH1F>("Occbarrel","Occupancy for Barrel",binnum,0,binnum);
  occbarrel1 = fs->make<TH1F>("Occbarrel1","Occupancy for Barrel",binnum,0,binnum);

  occEnd = fs->make<TH1F>("OccEndcapForward","Occupancy for Endcap",binnum,0,binnum);                                                                                                                                                     
  occwheelbarrel = fs->make<TH2F>("occwheelbarrel","Global Barrel Plot",binnum,0,binnum,5,0,5);                                                                                                                                                                 
  occdiskendcap = fs->make<TH2F>("occdiskendcap","Global Endcap Plot",binnum,0,binnum,6,0,6);
  occbrlend = fs->make<TH2F>("occbarlend","Global Endcap and Barrel",binnum,0,binnum,3,0,3); 

  brlNoiseDist = fs->make<TH1F>("brlNoiseDist","Barrel Occupancy Distribution",1000,0.,1000);
  fwdNoiseDist = fs->make<TH1F>("fwdNoiseDist","Endcap Occupancy Distribution",1000,0.,1000);
  overallNoiseDist = fs->make<TH1F>("overallNoiseDist","RPC System Occupancy Distribution",1000,0.,1000);
  /*
  hfile = new TFile(nomrootfile.c_str(),"RECREATE");
  binnum = hours*3600;
  occbarrel = new TH1F("Occbarrel","Occupancy for Barrel",binnum,0,binnum);
  occbarrel1 = new TH1F("Occbarrel1","Occupancy for Barrel",binnum,0,binnum);

  occEnd = new TH1F("OccEndcapForward","Occupancy for Endcap",binnum,0,binnum);                                                                                                                                                     
  occwheelbarrel = new TH2F("occwheelbarrel","Global Barrel Plot",binnum,0,binnum,5,0,5);                                                                                                                                                                 
  occdiskendcap = new TH2F("occdiskendcap","Global Endcap Plot",binnum,0,binnum,6,0,6);
  occbrlend = new TH2F("occbarlend","Global Endcap and Barrel",binnum,0,binnum,3,0,3); 

  brlNoiseDist = new TH1F("brlNoiseDist","Barrel Occupancy Distribution",1000,0.,1000);
  fwdNoiseDist = new TH1F("fwdNoiseDist","Endcap Occupancy Distribution",1000,0.,1000);
  overallNoiseDist = new TH1F("overallNoiseDist","RPC System Occupancy Distribution",1000,0.,1000);
  */
  gStyle->SetPalette(1);
  
  for(std::vector<std::string>::const_iterator r = RES.begin(); r!=RES.end();++r){
    std::string auxd;
    auxd.assign(*r);
    string auxt=auxd;
    auxd="occDist_"+auxd;
    auxt.append(" Occupancies Distribution;Number of Digi;Entries");
    TH1F *diskdist = fs->make<TH1F>(auxd.c_str(),auxt.c_str(),1000,0.,1000);
    diskNoiseDist.push_back(diskdist);
 
    for(std::vector<std::string>::const_iterator d = disks.begin(); d!=disks.end();++d){
      for(std::vector<std::string>::const_iterator s = secd.begin(); s!=secd.end();++s){
	std::string aux;
	std::string aux1;
	std::string aux2;

        aux.assign(*r);
	aux.append("_");
        aux.append(*d);
        aux.append("_");
        aux.append(*s);
	aux1.assign(aux);
        aux1.append(" noise");

        TH2F *histochamdisk = fs->make<TH2F>(aux.c_str(),aux1.c_str(),binnum,0,binnum,18,0,18);
	aux="endcapSectorProf_"+aux;
	aux1.append(" Profile");
	TH1F *profchamdisk = fs->make<TH1F>(aux.c_str(),aux1.c_str(),18,0,18);

        int co=1;
        for(std::vector<std::string>::const_iterator se = secdis.begin(); se!=secdis.end();++se){
          for(std::vector<std::string>::const_iterator di = dirdis.begin(); di!=dirdis.end();++di){
            if(((*s).compare("S01")==0) and ((*se).compare("CH02")==0 or (*se).compare("CH03")==0 or (*se).compare("CH04")==0 or (*se).compare("CH05")==0 or (*se).compare("CH06")==0 or (*se).compare("CH07")==0)){

              aux2.assign(*r);
              aux2.append("_");
              aux2.append(*d);
              aux2.append("_");
              aux2.append(*se);
              aux2.append("_");
              aux2.append(*di);
              histochamdisk->GetYaxis()->SetBinLabel(co,aux2.c_str());
	      profchamdisk->GetXaxis()->SetBinLabel(co,aux2.c_str());
              co=co+1;
           }
            else if(((*s).compare("S02")==0) and ((*se).compare("CH08")==0 or (*se).compare("CH09")==0 or (*se).compare("CH10")==0 or (*se).compare("CH11")==0 or (*se).compare("CH12")==0 or (*se).compare("CH13")==0)){
              aux2.assign(*r);
              aux2.append("_");
              aux2.append(*d);
              aux2.append("_");
              aux2.append(*se);
              aux2.append("_");
              aux2.append(*di);
              histochamdisk->GetYaxis()->SetBinLabel(co,aux2.c_str());
	      profchamdisk->GetXaxis()->SetBinLabel(co,aux2.c_str());
              co = co + 1;
            }
            else if(((*s).compare("S03")==0) and ((*se).compare("CH14")==0 or (*se).compare("CH15")==0 or (*se).compare("CH16")==0 or (*se).compare("CH17")==0 or (*se).compare("CH18")==0 or (*se).compare("CH19")==0)){
              aux2.assign(*r);
              aux2.append("_");
              aux2.append(*d);
              aux2.append("_");
              aux2.append(*se);
              aux2.append("_");
              aux2.append(*di);
              histochamdisk->GetYaxis()->SetBinLabel(co,aux2.c_str());
	      profchamdisk->GetXaxis()->SetBinLabel(co,aux2.c_str());
              co = co + 1;
            }
            else if(((*s).compare("S04")==0) and ((*se).compare("CH20")==0 or (*se).compare("CH21")==0 or (*se).compare("CH22")==0 or (*se).compare("CH23")==0 or (*se).compare("CH24")==0 or (*se).compare("CH25")==0)){
              aux2.assign(*r);
              aux2.append("_");
              aux2.append(*d);
              aux2.append("_");
              aux2.append(*se);
              aux2.append("_");
              aux2.append(*di);
              histochamdisk->GetYaxis()->SetBinLabel(co,aux2.c_str());
	      profchamdisk->GetXaxis()->SetBinLabel(co,aux2.c_str());
              co = co + 1;
            }
            else if(((*s).compare("S05")==0) and ((*se).compare("CH26")==0 or (*se).compare("CH27")==0 or (*se).compare("CH28")==0 or (*se).compare("CH29")==0 or (*se).compare("CH30")==0 or (*se).compare("CH31")==0)){
              aux2.assign(*r);
              aux2.append("_");
              aux2.append(*d);
              aux2.append("_");
              aux2.append(*se);
              aux2.append("_");
              aux2.append(*di);
              histochamdisk->GetYaxis()->SetBinLabel(co,aux2.c_str());
	      profchamdisk->GetXaxis()->SetBinLabel(co,aux2.c_str());
              co = co + 1;
            }
            else if(((*s).compare("S06")==0) and ((*se).compare("CH01")==0 or (*se).compare("CH32")==0 or (*se).compare("CH33")==0 or (*se).compare("CH34")==0 or (*se).compare("CH35")==0 or (*se).compare("CH36")==0)){
              aux2.assign(*r);
              aux2.append("_");
              aux2.append(*d);
              aux2.append("_");
              aux2.append(*se);
              aux2.append("_");
              aux2.append(*di);
              histochamdisk->GetYaxis()->SetBinLabel(co,aux2.c_str());
	      profchamdisk->GetXaxis()->SetBinLabel(co,aux2.c_str());
              co = co + 1;
            }
          }
        }
        chamdiskhis.push_back(histochamdisk);
	chamdiskprof.push_back(profchamdisk);
      }
    }
  }

  for(std::vector<std::string>::const_iterator w = wheels.begin(); w!= wheels.end(); ++w){
    std::string aux;
    std::string aux1;

    aux.assign("Barrel ");
    aux.append(*w);
    aux.append(" Noise");

    TH2F *histowheel = fs->make<TH2F>((*w).c_str(),aux.c_str(),binnum,0,binnum,12,0,12);
    string auxt=aux;
    aux.append(" Profile");
    string auxname="wheelProf_"+(*w);
    TH1F *profwheel = fs->make<TH1F>(auxname.c_str(),aux.c_str(),12,0,12);

    string auxd="occDist_"+(*w);
    auxt.append(" Occupancies Distribution;Occupancies;Entries");
    TH1F *wheeldist = fs->make<TH1F>(auxd.c_str(),auxt.c_str(),1000,0.,1000);
    wheelNoiseDist.push_back(wheeldist);

    int co = 1;
    for(std::vector<std::string>::const_iterator s = sec.begin(); s!= sec.end(); ++s){
      aux1.assign(*w);
      aux1.append("_");
      aux1.append((*s));
      histowheel->GetYaxis()->SetBinLabel(co,aux1.c_str());
      profwheel->GetXaxis()->SetBinLabel(co,aux1.c_str());
      co = co + 1;
    }
    wheelhis.push_back(histowheel);
    wheelprof.push_back(profwheel);
  }

  for(std::vector<std::string>::const_iterator w = wheels.begin(); w!= wheels.end(); ++w){

    string auxname;

    auxname.assign(*w);
    auxname.append("_");

    string farname ="towerProf_"+auxname+"Far",nearname="towerProf_"+auxname+"Near";
    string auxfar=auxname+"Far Tower Noise",auxnear=auxname+"Near Tower Noise";
    TH1F *nearprof = fs->make<TH1F>(nearname.c_str(),auxnear.c_str(),102,0,102);
    TH1F *farprof = fs->make<TH1F>(farname.c_str(),auxfar.c_str(),106,0,106);

    int frBin(1),nrBin(1);
    for(std::vector<std::string>::const_iterator s = sec.begin(); s!= sec.end(); ++s){
      std::string aux;
      std::string aux1;
      std::string aux2;
      
      aux.assign(*w);
      aux.append("_");
      aux.append((*s));
      aux1.assign(aux);
      aux1.append(" Noise");

      TH2F *chamwheel;
      TH1F *wheelcham;
      
      if((*s).compare("S04")==0){
        chamwheel = fs->make<TH2F>(aux.c_str(),aux1.c_str(),binnum,0,binnum,21,0,21);
	aux="barrelSectorProf_"+aux;
	aux1.append(" Profile");
	wheelcham = fs->make<TH1F>(aux.c_str(),aux1.c_str(),21,0,21);
      }
      else {
        chamwheel = fs->make<TH2F>(aux.c_str(),aux1.c_str(),binnum,0,binnum,17,0,17);
	aux="barrelSectorProf_"+aux;
	aux1.append(" Profile");
	wheelcham = fs->make<TH1F>(aux.c_str(),aux1.c_str(),17,0,17);
      }

      int co = 1;
      for(std::vector<std::string>::const_iterator r = rbs.begin(); r!= rbs.end(); ++r){
        for(std::vector<std::string>::const_iterator j = dir.begin(); j!= dir.end(); ++j){
          if(((*r).compare("RB4++")==0 or (*r).compare("RB4+-")==0 or (*r).compare("RB4--")==0 or (*r).compare("RB4-+")==0) and (*s).compare("S04")!=0  ){
            break;
          }
          else if(((*s).compare("S04")==0) and ((*r).compare("RB4+")==0 or (*r).compare("RB4-")==0 )){
            break;
          }
          else if((*r).compare("RB2in")==0 and ((*w).compare("W+2")==0 or (*w).compare("W-2")==0 ) and (*j).compare("Middle")==0 ){
            break;
          }
          else if((*r).compare("RB2out")==0 and ((*w).compare("W+0")==0 or (*w).compare("W+1")==0 or (*w).compare("W-1")==0 ) and (*j).compare("Middle")==0 ){
            break;
          }
          else if(((*r).compare("RB1in")==0 or (*r).compare("RB1out")==0 or (*r).compare("RB3+")==0 or (*r).compare("RB3-")==0 or (*r).compare("RB4+")==0 or (*r).compare("RB4-")==0 or (*r).compare("RB4++")==0 or (*r).compare("RB4+-")==0 or (*r).compare("RB4--")==0 or (*r).compare("RB4-+")==0 ) and (*j).compare("Middle")==0 ){
            break;
          }
          else {
            aux2.assign(*w);
            aux2.append("_");
            aux2.append(*r);
            aux2.append("_");
            aux2.append(*s);
            aux2.append("_");
            aux2.append(*j);
            chamwheel->GetYaxis()->SetBinLabel(co,aux2.c_str());
	    wheelcham->GetXaxis()->SetBinLabel(co,aux2.c_str());
	    if((*s).compare("S01")==0 || (*s).compare("S02")==0 || (*s).compare("S03")==0 || (*s).compare("S10")==0 || (*s).compare("S11")==0 || (*s).compare("S12")==0){
	      nearprof->GetXaxis()->SetBinLabel(nrBin,aux2.c_str());
	      nrBin++;
	    }
	    else {
	      farprof->GetXaxis()->SetBinLabel(frBin,aux2.c_str());
	      frBin++;
	    }
            co = co+1;
          }
        }
      }
      chamwheelhis.push_back(chamwheel);
      chamwheelprof.push_back(wheelcham);
    }
    towerprof.push_back(nearprof);
    towerprof.push_back(farprof);
  }

  for(std::vector<std::string>::const_iterator r = RES.begin(); r!= RES.end(); ++r){

    std::string aux;
    aux.assign(*r);
    aux.append(" Noise");

    TH2F *histodisk = fs->make<TH2F>((*r).c_str(),aux.c_str(),binnum,0,binnum,18,0,18);
    aux.append(" Profile");
    string auxnm="diskProf_"+(*r);
    TH1F *profdisk = fs->make<TH1F>(auxnm.c_str(),aux.c_str(),18,0,18);

    int co =1;
    for(std::vector<std::string>::const_iterator d = disks.begin(); d!= disks.end(); ++d){
      for(std::vector<std::string>::const_iterator s = secd.begin(); s!= secd.end(); ++s){
	std::string aux1;

        aux1.assign(*r);
        aux1.append("_");
        aux1.append(*d);
        aux1.append("_");
        aux1.append(*s);
        histodisk->GetYaxis()->SetBinLabel(co,aux1.c_str());
	profdisk->GetXaxis()->SetBinLabel(co,aux1.c_str());
        co = co +1;
      }
    }
    diskhis.push_back(histodisk);
    diskprof.push_back(profdisk);
  }


  occwheelbarrel->GetYaxis()->SetBinLabel(1,"W-2");
  occwheelbarrel->GetYaxis()->SetBinLabel(2,"W-1");
  occwheelbarrel->GetYaxis()->SetBinLabel(3,"W+0");
  occwheelbarrel->GetYaxis()->SetBinLabel(4,"W+1");
  occwheelbarrel->GetYaxis()->SetBinLabel(5,"W+2");

  occdiskendcap->GetYaxis()->SetBinLabel(1,"RE-3");
  occdiskendcap->GetYaxis()->SetBinLabel(2,"RE-2");
  occdiskendcap->GetYaxis()->SetBinLabel(3,"RE-1");
  occdiskendcap->GetYaxis()->SetBinLabel(4,"RE+1");
  occdiskendcap->GetYaxis()->SetBinLabel(5,"RE+2");
  occdiskendcap->GetYaxis()->SetBinLabel(6,"RE+3");

  occbrlend->GetYaxis()->SetBinLabel(1,"E+");
  occbrlend->GetYaxis()->SetBinLabel(2,"Barrel");
  occbrlend->GetYaxis()->SetBinLabel(3,"E-");

  //  occbarrel->SetBit(TH1::kCanRebin);
  //  occEnd->SetBit(TH1::kCanRebin);

}
//
// member functions
//

// ------------ method called to for each event  ------------
void
RPCOffLineNoise::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  int bx = iEvent.bunchCrossing();
  if(Debug_) cout << "BunchCrossing " << bx << endl;
  int thisOrbit = iEvent.orbitNumber();
  if(Debug_) cout << "Orbit number: " << thisOrbit << endl;
  double orbitTime = 0.03564*(double)thisOrbit +(double)((double)bx/100000.0);
  if(Debug_) cout << "OrbitTime " << orbitTime << endl;
  //unsigned long long tempo = (orbitTime/10000)*25;
  TimeValue_t time=iEvent.time().value();
  if(Debug_) cout << "Time " << time << endl;
  timeval *tmval=(timeval*)&time;
  if(Debug_) cout << "tmval " << tmval << endl;
  if(!inicio){
    primotempo = tmval->tv_usec;
    inicio = true;
  }
  //   unsigned long long tempo;
  unsigned long long tempo1 = tmval->tv_usec - primotempo;
  if(Debug_) cout << "tempo1 " << tempo1 << endl;
  int tempo = iEvent.id().event()/5000;
  trigger =  false;
  if(Debug_) cout << "tempo " << tempo << endl;
  if(Debug_) cout << "eventperbin " << eventperbin << endl;
  
  eventperbin->Fill(tempo);
  
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

   edm::Handle<RPCDigiCollection> rpcdigis;
   //   iEvent.getByLabel("muonRPCDigis",rpcdigis);
   iEvent.getByLabel(m_GMTInputTag,rpcdigis);///"muonRPCDigis",rpcdigis);
   edm::ESHandle<RPCGeometry> rpcGeo;
   iSetup.get<MuonGeometryRecord>().get(rpcGeo);

   /*   edm::Handle< std::vector <L1MuRegionalCand> > rpcrc_handle;
   iEvent.getByLabel("l1RpcEmulDigis","RPCb",rpcrc_handle);
   std::vector<L1MuRegionalCand>::const_iterator iter1;*/
   //   std::vector <L1MuRegionalCand> rpcrc_records = rpcrc_handle->getRecords();

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

   hnTracksPerEvent->Fill(Tracks->size());
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
   // increment timeVector just for sectors not involved by segments (is needed to calculate total daq time for noise measurement)                     
   for (int i=0;i<5;i++) {
     for (int j=0;j<12;j++) {
       if (!taggedBarrelSectors[i][j]) barrel_timeEv[i][j]++;
     }
   }
   // loop on RPC REC HIts and fill occupancy plots                                                                                                    

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

     sprintf(detUnitLabel ,"%s",nameRoll.c_str());

     map<string, map<string,MonitorElement*> >::iterator meItr = meCollection.find(nameRoll);
     map<string, MonitorElement*> meMap=meCollection[nameRoll];
     //     sprintf(meIdRPC,"RPCDataOccupancy_%s",detUnitLabel);

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
   ////////////////////////////acaba davide continuo yo parcero!

   /*   double etav=0;
   double phiv=0;
   double qualityv=0;
   double ptValuev=0;
      for(iter1=rpcrc_handle->begin();iter1!=rpcrc_handle->end();iter1++){
     if ( !(*iter1).empty() ){
       hl1em->Fill(tempo);
       bxtrigger = (*iter1).bx();
       etav = (*iter1).etaValue();
       phiv = (*iter1).phiValue();
       qualityv =  (*iter1).quality();
       ptValuev =  (*iter1).ptValue();
       trigger = true;
     }
     }

   if(trigger)
     std::cout << "Triggered Event: " << iEvent.id().event() << " Bx:  " << bxtrigger << " Eta: " << etav << " Phi: " << phiv << " quality: " << qualityv << " ptValue: " << ptValuev << std::endl;
   */
   int counter = 0;
   if(!area){
     area = true;
     for (int j = 0; j<12;j++){
       rawm2[j]=0;
       rawm1[j]=0;
       raw0[j]=0;
       raw1[j]=0;
       raw2[j]=0;
     }
     for (int k = 0; k<18; k++){
       rawd1[k] = 0;
       rawd2[k] = 0;
       rawd3[k] = 0;
     }     
     for (TrackingGeometry::DetContainer::const_iterator it=rpcGeo->dets().begin();it<rpcGeo->dets().end();it++){
       if(dynamic_cast< RPCChamber* >( *it ) != 0 ){
	 RPCChamber* ch = dynamic_cast< RPCChamber* >( *it );
	 std::vector< const RPCRoll*> roles = (ch->rolls());
	 
	 for(std::vector<const RPCRoll*>::const_iterator h = roles.begin();h != roles.end(); ++h){
	   RPCDetId rpcId1 = (*h)->id();
	   RPCGeomServ rpcsrv(rpcId1);
	   const RPCRollSpecs * rollsp1 = (*h)->specs();
	   const StripTopology & strtop1 = rollsp1->specificTopology();

	   float chamber_ar1 = strtop1.nstrips()*strtop1.stripLength()*strtop1.pitch();

	   std::cout << "Area de la camara: " << chamber_ar1 << " nombre de la camara: " << rpcsrv.name() << " Numero de strips: " << strtop1.nstrips() << " strip lenght: "  << strtop1.stripLength() << " strip pitch: " << strtop1.pitch(); 
	   std::cout << " ring: " << rpcId1.ring() << " roll: " << rpcId1.roll() << " sector: " << rpcId1.sector() << " station: " << rpcId1.station() << " subsector: " << rpcId1.subsector() << std::endl;
	   if(rpcId1.region()==1){
	     if(rpcId1.station()==1){
	       if(rpcId1.ring()==1){
		 rawd1[rpcId1.sector()-1] += chamber_ar1;
	       }  
	       else 
		 if(rpcId1.ring()==2){
		   rawd1[rpcId1.sector()+5] += chamber_ar1;
		 }  
		 else
		   if(rpcId1.ring()==3){
		     rawd1[rpcId1.sector()+11] += chamber_ar1;
		   }  
	     }
	     else
	       if(rpcId1.station()==2){
		 if(rpcId1.ring()==1){
		   rawd2[rpcId1.sector()-1] += chamber_ar1;
		 }  
		 else 
		   if(rpcId1.ring()==2){
		     rawd2[rpcId1.sector()+5] += chamber_ar1;
		   }  
		   else
		     if(rpcId1.ring()==3){
		       rawd2[rpcId1.sector()+11] += chamber_ar1;
		     }  
	       }
	       else{
		 if(rpcId1.ring()==1){
		   rawd3[rpcId1.sector()-1] += chamber_ar1;
		 }  
		 else 
		   if(rpcId1.ring()==2){
		     rawd3[rpcId1.sector()+5] += chamber_ar1;
		   }  
		   else
		     if(rpcId1.ring()==3){
		       rawd3[rpcId1.sector()+11] += chamber_ar1;
		     }  
	       }
	   }
	   if(rpcId1.region()==0){
	     if(rpcId1.ring()==-2)
	       rawm2[rpcId1.sector()-1] += chamber_ar1;
	     else
	       if(rpcId1.ring()==-1)
		 rawm1[rpcId1.sector()-1] += chamber_ar1;
	       else
		 if(rpcId1.ring()==0)
		   raw0[rpcId1.sector()-1] += chamber_ar1;
		 else
		   if(rpcId1.ring()==1)
		     raw1[rpcId1.sector()-1] += chamber_ar1;
		   else
		     if(rpcId1.ring()==2)
		       raw2[rpcId1.sector()-1] += chamber_ar1;
	   }
	 }
       }
     }
     for (int k=0;k<18;k++){
       //cout << "Areas d1 " << rawd1[k] << endl;
       //cout << "Areas d2 " << rawd2[k] << endl;
       //cout << "Areas d3 " << rawd3[k] << endl;
     }
   }     
   
   /*   double tempm2 = rawm2[0]+rawm2[1]+rawm2[2]+rawm2[3]+rawm2[4]+rawm2[5]+rawm2[6]+rawm2[7]+rawm2[8]+rawm2[9]+rawm2[10]+rawm2[11];
   double tempm1 = rawm1[0]+rawm1[1]+rawm1[2]+rawm1[3]+rawm1[4]+rawm1[5]+rawm1[6]+rawm1[7]+rawm1[8]+rawm1[9]+rawm1[10]+rawm1[11];
   double temp0 = raw0[0]+raw0[1]+raw0[2]+raw0[3]+raw0[4]+raw0[5]+raw0[6]+raw0[7]+raw0[8]+raw0[9]+raw0[10]+raw0[11];
   double temp1 = raw1[0]+raw1[1]+raw1[2]+raw1[3]+raw1[4]+raw1[5]+raw1[6]+raw1[7]+raw1[8]+raw1[9]+raw1[10]+raw1[11];
   double temp2 = raw2[0]+raw2[1]+raw2[2]+raw2[3]+raw2[4]+raw2[5]+raw2[6]+raw2[7]+raw2[8]+raw2[9]+raw2[10]+raw2[11];
   double tempd1 = rawd1[0]+rawd1[1]+rawd1[2]+rawd1[3]+rawd1[4]+rawd1[5]+rawd1[6]+rawd1[7]+rawd1[8]+rawd1[9]+rawd1[10]+rawd1[11] + rawd1[12] +rawd1[13] +rawd1[14] +rawd1[15] +rawd1[16] +rawd1[17];
   double tempd2 = rawd2[0]+rawd2[1]+rawd2[2]+rawd2[3]+rawd2[4]+rawd2[5]+rawd2[6]+rawd2[7]+rawd2[8]+rawd2[9]+rawd2[10]+rawd2[11] + rawd2[12] +rawd2[13] +rawd2[14] +rawd2[15] +rawd2[16] +rawd2[17];
   double tempd3 = rawd3[0]+rawd3[1]+rawd3[2]+rawd3[3]+rawd3[4]+rawd3[5]+rawd3[6]+rawd3[7]+rawd3[8]+rawd3[9]+rawd3[10]+rawd3[11] + rawd3[12] +rawd3[13] +rawd3[14] +rawd3[15] +rawd3[16] +rawd3[17];
   */

   for (TrackingGeometry::DetContainer::const_iterator it=rpcGeo->dets().begin();it<rpcGeo->dets().end();it++){
     if(dynamic_cast< RPCChamber* >( *it ) != 0 ){
       RPCChamber* ch = dynamic_cast< RPCChamber* >( *it );
       std::vector< const RPCRoll*> roles = (ch->rolls());
       
       for(std::vector<const RPCRoll*>::const_iterator r = roles.begin();r != roles.end(); ++r){
         RPCDetId rpcId = (*r)->id();
	 RPCDigiCollection::Range rpcRangeDigi=rpcdigis->get(rpcId);
	 if (!taggedBarrelSectors[rpcId.ring()+2][rpcId.sector()-1] ) { // not related to any DT segment i assume is rpc noise                             
	   for (RPCDigiCollection::const_iterator digiIt = rpcRangeDigi.first;digiIt!=rpcRangeDigi.second;++digiIt){
	     counter++;
	   }
	 }
       }
     }
   }

   for (TrackingGeometry::DetContainer::const_iterator it=rpcGeo->dets().begin();it<rpcGeo->dets().end();it++){
     if(dynamic_cast< RPCChamber* >( *it ) != 0 ){
       RPCChamber* ch = dynamic_cast< RPCChamber* >( *it );
       std::vector< const RPCRoll*> roles = (ch->rolls());

       for(std::vector<const RPCRoll*>::const_iterator r = roles.begin();r != roles.end(); ++r){
         RPCDetId rpcId = (*r)->id();
         RPCGeomServ rpcsrv(rpcId);

	 const RPCRollSpecs * rollsp = (*r)->specs();
	 const StripTopology & strtop = rollsp->specificTopology();
	 float chamber_area = strtop.nstrips()*strtop.stripLength()*strtop.pitch();

	 string name = rpcsrv.name();
         char nomchamb[50];
         strcpy(nomchamb,name.c_str());
	 RPCDigiCollection::Range rpcRangeDigi=rpcdigis->get(rpcId);
         int cont=0;
	 int nStrips=(*r)->nstrips();
	 //	 std::vector<long> dig;
	 //	 std::vector< std::vector <long> > prev;
	 //	 prev.clear();
	 if (!taggedBarrelSectors[rpcId.ring()+2][rpcId.sector()-1] ) { // not related to any DT segment i assume is rpc noise                             
         for (RPCDigiCollection::const_iterator digiIt = rpcRangeDigi.first;digiIt!=rpcRangeDigi.second;++digiIt){
	   //	   dig.clear();
	   //	   bool verheit = false;
	   //	   dig.push_back((*digiIt).bx());
	   //	   dig.push_back(rpcId.rawId());
	   //	   dig.push_back((*digiIt).strip());
	   //	   for(int i=0;i<prev.size();i++){
	   //	     if(prev[i][0]==dig[0] and prev[i][1]==dig[1] and prev[i][2] == dig[2]) verheit = true;
	     //cout << "\t prev: " << prev[i][0] << " " << prev[i][1] << " " << prev[i][2] << endl;
	   //	   }
	   //	   prev.push_back(dig);
	   //	   if(!verheit)
	   cont++;
	   //	   std::cout << "Vamos en la cámara: " << name << " van: " << cont << " Hits." << std::endl;
         }

         if(cont!=0){

	   //	   overallNoiseDist->Fill(cont/chamber_area);
	   overallNoiseDist->Fill(cont);

	   if(rpcId.region()==0){

	     std::string aux;
	     aux.assign("W");
	     if(rpcId.ring()>=0)
	       aux.append("+");
	     char aux1[2];
	     int numero=sprintf(aux1,"%d",rpcId.ring());
	     aux.append(aux1);
	     aux.append("_S");
	     if(rpcId.sector()<10){
	       aux.append("0");
	     }
	     numero =sprintf(aux1,"%d",rpcId.sector());
	     aux.append(aux1);

	     for(std::vector<TH2F*>::const_iterator w = wheelhis.begin(); w != wheelhis.end(); ++w){
	       for(int k=1;k<=12;k++){
		 std::string nom;
		 nom.assign((*w)->GetYaxis()->GetBinLabel(k));
		 //std::cout << nom << " Chamber Area: " << chamber_area << std::endl;
		 if(aux.compare(nom)==0){
		   if(noise_flag){
		     if(noise_limit<counter){
		       if(rpcId.ring()==-2){
			 //			 (*w)->Fill(tempo,k-1,cont/rawm2[k-1]);
			 (*w)->Fill(tempo,k-1,cont);
			 //			 std::cout << "Area sector " << nom << ": " << rawm2[k-1] << " ratio " << cont/rawm2[k-1] << std::endl;
		       }
		       else
			 if(rpcId.ring()==-1)
			   (*w)->Fill(tempo,k-1,cont);
			   //(*w)->Fill(tempo,k-1,cont/rawm1[k-1]);
			 else 
			   if(rpcId.ring()==0)
			     (*w)->Fill(tempo,k-1,cont);
		       //			     (*w)->Fill(tempo,k-1,cont/raw0[k-1]);
			   else
			     if(rpcId.ring()==1)
			       (*w)->Fill(tempo,k-1,cont);
		       //			       (*w)->Fill(tempo,k-1,cont/raw1[k-1]);
			     else
			     if(rpcId.ring()==2)
			       (*w)->Fill(tempo,k-1,cont);
		       //			       (*w)->Fill(tempo,k-1,cont/raw2[k-1]);
		     }
		   }
		   else{
		       if(rpcId.ring()==-2)
			 (*w)->Fill(tempo,k-1,cont);
		       //			 (*w)->Fill(tempo,k-1,cont/rawm2[k-1]);
		       else
			 if(rpcId.ring()==-1)
			   (*w)->Fill(tempo,k-1,cont);
		       //			   (*w)->Fill(tempo,k-1,cont/rawm1[k-1]);
			 else 
			   if(rpcId.ring()==0)
			     (*w)->Fill(tempo,k-1,cont);
		       //			     (*w)->Fill(tempo,k-1,cont/raw0[k-1]);
			   else
			     if(rpcId.ring()==1)
			       (*w)->Fill(tempo,k-1,cont);
		       //			       (*w)->Fill(tempo,k-1,cont/raw1[k-1]);
			     else
			     if(rpcId.ring()==2)
			       (*w)->Fill(tempo,k-1,cont);
		       //      (*w)->Fill(tempo,k-1,cont/raw2[k-1]);
		   }
		 }
	       }
	     }
	     brlNoiseDist->Fill(cont/chamber_area);
	     //	     brlNoiseDist->Fill(cont/chamber_area);

	     for(std::vector<TH1F*>::const_iterator wp = wheelprof.begin(); wp != wheelprof.end(); ++wp){
	       for(int k=1;k<=12;k++){
		 std::string nom;
		 nom.assign((*wp)->GetXaxis()->GetBinLabel(k));
		 if(aux.compare(nom)==0){
		   if(noise_flag){
		     if(noise_limit<counter)
		       (*wp)->Fill(k-1,cont/nStrips);
		   }
		   else{
		     (*wp)->Fill(k-1,cont/nStrips);
		   }
		 }
	       }
	     }

	     aux.assign("W");
	     if(rpcId.ring()>=0)
	       aux.append("+");
	     numero=sprintf(aux1,"%d",rpcId.ring());
	     aux.append(aux1);
	     aux.append("_RB");
	     numero=sprintf(aux1,"%d",rpcId.station());
	     aux.append(aux1);
	     bool vai=false;
	     if(rpcId.station() == 4){
	       if(rpcId.sector() == 4){
		 if(rpcId.subsector()==1)
		   aux.append("--");
		 else 
		   if(rpcId.subsector()==2)
		     aux.append("-+");
		   else
		     if(rpcId.subsector()==3)
		       aux.append("+-");
		     else
		       if(rpcId.subsector()==4)
			 aux.append("++");
	       }
	       else{
		 if(rpcId.subsector()==1)
		   aux.append("-");
		 else
		   if(rpcId.subsector()==2)
		     aux.append("+");
	       }
	     }
	     else
	       if(rpcId.station()==3){
		 if(rpcId.subsector()==1)
		   aux.append("-");
		 else
		   if(rpcId.subsector()==2)
		     aux.append("+");
	       }
	       else
		 if(rpcId.station()==1 || rpcId.station() == 2){
		   if(rpcId.layer()==1)
		     aux.append("in");
		   else
		     if(rpcId.layer()==2)
		       aux.append("out");
		 }
	     aux.append("_S");
             if(rpcId.sector()<10){
               aux.append("0");
             }
             numero =sprintf(aux1,"%d",rpcId.sector());
             aux.append(aux1);	     
	     if(rpcId.roll()==1)
               aux.append("_Backward");
	     if(rpcId.roll()==2)
               aux.append("_Middle");
	     if(rpcId.roll()==3)
               aux.append("_Forward");

	     for(std::vector<TH2F*>::const_iterator w = chamwheelhis.begin(); w != chamwheelhis.end(); ++w){
	       for(int k =1;k<=(*w)->GetYaxis()->GetNbins();k++){
		 std::string nom;
		 nom.assign((*w)->GetYaxis()->GetBinLabel(k));
		 //		 std::cout << "Nombre " << nom << std::endl;
		 if(vai){
		   //  std::cout << "Nombre del Digi: " << aux << std::endl;
		   //		   std::cout << "Nombre del bin: " << nom << std::endl;
		   //		   std::cout << "Comparacion entre ellos: " << aux.compare(nom) << std::endl;
		 }
		 if(aux.compare(nom)==0){
		   if(noise_flag){
                     if(noise_limit<counter)
                       (*w)->Fill(tempo,k-1,cont);
		       //                       (*w)->Fill(tempo,k-1,cont/chamber_area);
                   }
                   else{
                     (*w)->Fill(tempo,k-1,cont);
		     //                     (*w)->Fill(tempo,k-1,cont/chamber_area);
                   }
		 }
	       } 
	     }

	     fwdNoiseDist->Fill(cont);
	     //	     fwdNoiseDist->Fill(cont/chamber_area);

	     for(std::vector<TH1F*>::const_iterator wc = chamwheelprof.begin(); wc != chamwheelprof.end(); ++wc){
	       for(int k =1;k<=(*wc)->GetXaxis()->GetNbins();k++){
		 std::string nom;
		 nom.assign((*wc)->GetXaxis()->GetBinLabel(k));
		 if(vai){
		   //std::cout << "Nombre del Digi: " << aux << std::endl;
		   //std::cout << "Nombre del bin: " << nom << std::endl;
		   //std::cout << "Comparacion entre ellos: " << aux.compare(nom) << std::endl;
		 }
		 if(aux.compare(nom)==0){
		   if(noise_flag){
                     if(noise_limit<counter)
                       (*wc)->Fill(k-1,cont/nStrips);
                   }
                   else{
                     (*wc)->Fill(k-1,cont/nStrips);
                   }
		 }
	       } 
	     }

	     for(std::vector<TH1F*>::const_iterator wc = towerprof.begin(); wc != towerprof.end(); ++wc){
	       for(int k =1;k<=(*wc)->GetXaxis()->GetNbins();k++){
		 std::string nom;
		 nom.assign((*wc)->GetXaxis()->GetBinLabel(k));
		 if(vai){
		   //std::cout << "Nombre del Digi: " << aux << std::endl;
		   //std::cout << "Nombre del bin: " << nom << std::endl;
		   //std::cout << "Comparacion entre ellos: " << aux.compare(nom) << std::endl;
		 }
		 if(aux.compare(nom)==0){
		   if(noise_flag){
                     if(noise_limit<counter)
                       (*wc)->Fill(k-1,cont/nStrips);
                   }
                   else{
                     (*wc)->Fill(k-1,cont/nStrips);
                   }
		 }
	       } 
	     }

 	     std::vector<TH1F*>::const_iterator wd=wheelNoiseDist.begin();
	     string wl=aux.substr(1,3);int wln=atoi(wl.c_str());
 	     switch(wln){
 	     case -2:
 	       (*wd)->Fill(cont);
	       // 	       (*wd)->Fill(cont/chamber_area);
 	       break;
 	     case -1:
 	       wd++;
 	       (*wd)->Fill(cont);
	       // 	       (*wd)->Fill(cont/chamber_area);
 	       break;
 	     case 0:
 	       wd+=2;
 	       (*wd)->Fill(cont);
	       // 	       (*wd)->Fill(cont/chamber_area);
 	       break;
 	     case 1:
 	       wd+=3;
 	       (*wd)->Fill(cont);
	       // 	       (*wd)->Fill(cont/chamber_area);
 	       break;
 	     case 2:
 	       wd+=4;
 	       (*wd)->Fill(cont);
	       // 	       (*wd)->Fill(cont/chamber_area);
 	       break;
 	     }
	   }
	   
	   else {

	     std::string aux;
	     aux.assign("RE");
	     if(rpcId.region()==-1)
	       aux.append("-");    
	     if(rpcId.region()==1)
	       aux.append("+");
	     char aux1[2];
	     int numero=sprintf(aux1,"%d",rpcId.station());
	     aux.append(aux1);
	     aux.append("_");
	     if(rpcId.ring()==1)
	       aux.append("R1_CH");
	     if(rpcId.ring()==2)
	       aux.append("R2_CH");
	     if(rpcId.ring()==3)
	       aux.append("R3_CH");
	     int x = (rpcId.sector()-1)*6+1+rpcId.subsector();
	     if (x==37)
	       x=1;
	     if (x<10)
	       aux.append("0");
	     numero = sprintf(aux1,"%d_",x);
	     aux.append(aux1);
	     if(rpcId.roll()==3)
	       aux.append("C");
	     if(rpcId.roll()==2)
	       aux.append("B");
	     if(rpcId.roll()==1)
	       aux.append("A");

	     for(std::vector<TH2F*>::const_iterator d = chamdiskhis.begin(); d != chamdiskhis.end(); ++d){ 
	       for(int k=1;k<=18;k++){
		 std::string nom;
		 nom.assign((*d)->GetYaxis()->GetBinLabel(k));
		 //	 std::cout << "Nombre " << nom << std::endl;
		 if(aux.compare(nom)==0){
		   if(noise_flag){
                     if(noise_limit<counter)
                       (*d)->Fill(tempo,k-1,cont);
		     //                       (*d)->Fill(tempo,k-1,cont/chamber_area);

                   }
                   else{
		     //                     (*d)->Fill(tempo,k-1,cont/chamber_area);
                     (*d)->Fill(tempo,k-1,cont);
                   }
		 }
	       }
	     }

	     for(std::vector<TH2F*>::const_iterator dp = chamdiskhis.begin(); dp != chamdiskhis.end(); ++dp){ 
	       for(int k=1;k<=18;k++){
		 std::string nom;
		 nom.assign((*dp)->GetXaxis()->GetBinLabel(k));

		 if(aux.compare(nom)==0){
		   if(noise_flag){
                     if(noise_limit<counter)
                       (*dp)->Fill(k-1,cont/nStrips);
                   }
                   else{
                     (*dp)->Fill(k-1,cont/nStrips);
                   }
		 }
	       }
	     }
	     
             aux.assign("RE");
             if(rpcId.region()==-1)
               aux.append("-");
             if(rpcId.region()==1)
               aux.append("+");
	     numero=sprintf(aux1,"%d",rpcId.station());
             aux.append(aux1);
             aux.append("_");
	     if(rpcId.ring()==1)
	       aux.append("R1_S0");
             if(rpcId.ring()==2)
               aux.append("R2_S0");
             if(rpcId.ring()==3)
               aux.append("R3_S0");
             numero = sprintf(aux1,"%d",rpcId.subsector());
             aux.append(aux1);
	     
             for(std::vector<TH2F*>::const_iterator d = diskhis.begin(); d != diskhis.end(); ++d){
               for(int k=1;k<=18;k++){
		 std::string nom;
                 nom.assign((*d)->GetYaxis()->GetBinLabel(k));
                 if(aux.compare(nom)==0){
		   if(noise_flag){
                     if(noise_limit<counter){
		       //std::cout << "Nombre cosa: " << nom << std::endl;
		       if(rpcId.station()==1){
			 if(rpcId.ring()==1){
			   (*d)->Fill(tempo,k-1,cont);
			   //			   (*d)->Fill(tempo,k-1,cont/rawd1[rpcId.sector()-1]);
			 }
			 else
			   if(rpcId.ring()==2){
			     (*d)->Fill(tempo,k-1,cont);
			     //			     (*d)->Fill(tempo,k-1,cont/rawd1[rpcId.sector()+5]);
			   }
			   else
			     if(rpcId.ring()==3){
			       (*d)->Fill(tempo,k-1,cont);
			       //			       (*d)->Fill(tempo,k-1,cont/rawd1[rpcId.sector()+11]);
			     }
		       }
		       else
			 if(rpcId.station()==2){
			   if(rpcId.ring()==1){
			     (*d)->Fill(tempo,k-1,cont);
			     //			     (*d)->Fill(tempo,k-1,cont/rawd2[rpcId.sector()-1]);
			   }
			   else
			     if(rpcId.ring()==2){
			       (*d)->Fill(tempo,k-1,cont);
			       //			       (*d)->Fill(tempo,k-1,cont/rawd2[rpcId.sector()+5]);
			     }
			     else
			       if(rpcId.ring()==3){
				 (*d)->Fill(tempo,k-1,cont);
				 //				 (*d)->Fill(tempo,k-1,cont/rawd2[rpcId.sector()+11]);
			       }
			 }
			 else
			   if(rpcId.station()==3){
			     if(rpcId.ring()==1){
			       (*d)->Fill(tempo,k-1,cont);
			       //			       (*d)->Fill(tempo,k-1,cont/rawd3[rpcId.sector()-1]);
			     }
			     else
			       if(rpcId.ring()==2){
				 (*d)->Fill(tempo,k-1,cont);
				 //				 (*d)->Fill(tempo,k-1,cont/rawd3[rpcId.sector()+5]);
			       }
			       else
				 if(rpcId.ring()==3){
				   (*d)->Fill(tempo,k-1,cont);
				   //				   (*d)->Fill(tempo,k-1,cont/rawd3[rpcId.sector()+11]);
				 }
			   }
		     }
                   }
                   else{
		     if(rpcId.station()==1){
		       if(rpcId.ring()==1){
			 (*d)->Fill(tempo,k-1,cont);
			 //			 (*d)->Fill(tempo,k-1,cont/rawd1[rpcId.sector()-1]);
		       }
		       else
			 if(rpcId.ring()==2){
			   (*d)->Fill(tempo,k-1,cont);
			   //			   (*d)->Fill(tempo,k-1,cont/rawd1[rpcId.sector()+5]);
			 }
			 else
			   if(rpcId.ring()==3){
			     (*d)->Fill(tempo,k-1,cont);
			     //			     (*d)->Fill(tempo,k-1,cont/rawd1[rpcId.sector()+11]);
			   }
		     }
		     else
		       if(rpcId.station()==2){
			 if(rpcId.ring()==1){
			   (*d)->Fill(tempo,k-1,cont);
			   //			   (*d)->Fill(tempo,k-1,cont/rawd2[rpcId.sector()-1]);
			 }
			 else
			   if(rpcId.ring()==2){
			     (*d)->Fill(tempo,k-1,cont);
			     //			     (*d)->Fill(tempo,k-1,cont/rawd2[rpcId.sector()+5]);
			   }
			   else
			     if(rpcId.ring()==3){
			       (*d)->Fill(tempo,k-1,cont);
			       //			       (*d)->Fill(tempo,k-1,cont/rawd2[rpcId.sector()+11]);
			     }
		       }
		       else
			 if(rpcId.station()==3){
			   if(rpcId.ring()==1){
			     (*d)->Fill(tempo,k-1,cont);
			     //			     (*d)->Fill(tempo,k-1,cont/rawd3[rpcId.sector()-1]);
			   }
			   else
			     if(rpcId.ring()==2){
			       (*d)->Fill(tempo,k-1,cont);
			       //			       (*d)->Fill(tempo,k-1,cont/rawd3[rpcId.sector()+5]);
			     }
			     else
			       if(rpcId.ring()==3){
				 (*d)->Fill(tempo,k-1,cont);
				 //(*d)->Fill(tempo,k-1,cont/rawd3[rpcId.sector()+11]);
			       }
			 }
		     
                   }
                 }
               }
             }
	     
             for(std::vector<TH1F*>::const_iterator dc = diskprof.begin(); dc != diskprof.end(); ++dc){
               for(int k=1;k<=18;k++){
		 std::string nom;
                 nom.assign((*dc)->GetXaxis()->GetBinLabel(k));
                 if(aux.compare(nom)==0){
		   if(noise_flag){
                     if(noise_limit<counter)
                       (*dc)->Fill(k-1,cont/nStrips);
                   }
                   else{
                     (*dc)->Fill(k-1,cont/nStrips);
                   }
                 }
               }
             }
	     
	     std::vector<TH1F*>::const_iterator dd=diskNoiseDist.begin();
	     string dl=aux.substr(2,4);int dln=atoi(dl.c_str());
	     switch(dln){
	     case -3:
	       (*dd)->Fill(cont);
	       //	       (*dd)->Fill(cont/chamber_area);
	       break;
	     case -2:
	       dd++;
	       //	       (*dd)->Fill(cont/chamber_area);
	       (*dd)->Fill(cont);
	       break;
	     case -1:
	       dd+=2;
	       (*dd)->Fill(cont);
	       //	       (*dd)->Fill(cont/chamber_area);
	       break;
	     case 1:
	       dd+=3;
	       //	       (*dd)->Fill(cont/chamber_area);
	       (*dd)->Fill(cont);
	       break;
	     case 2:
	       dd+=4;
	       //	       (*dd)->Fill(cont/chamber_area);
	       (*dd)->Fill(cont);
	       break;
	     case 3:
	       dd+=5;
	       //(*dd)->Fill(cont/chamber_area);
	       (*dd)->Fill(cont);
	       break;
	     }
	   }	   
	   
	   if(rpcId.region()!=0){
	     
	     if(rpcId.region()==-1){
	       if(rpcId.station()==3){
		 if(noise_flag){
		   if(noise_limit<counter)
		     occdiskendcap->Fill(tempo,0.,cont);
//		     occdiskendcap->Fill(tempo,0.,cont/tempd3);
		 }
		 else{
		   occdiskendcap->Fill(tempo,0.,cont);
		   //		   occdiskendcap->Fill(tempo,0.,cont/tempd3);
		 }
	       }
	       else
		 if(rpcId.station()==2){
		   if(noise_flag){
                     if(noise_limit<counter)
		       occdiskendcap->Fill(tempo,1,cont);
		     //		       occdiskendcap->Fill(tempo,1,cont/tempd2);
                   }
                   else{
		     occdiskendcap->Fill(tempo,1,cont);
		     //		     occdiskendcap->Fill(tempo,1,cont/tempd2);
                   }
		 }
		 else
		   if(rpcId.station()==1){
		     if(noise_flag){
		       if(noise_limit<counter)
			 occdiskendcap->Fill(tempo,2,cont);
		       //			 occdiskendcap->Fill(tempo,2,cont/tempd1);
		     }
		     else{
		       occdiskendcap->Fill(tempo,2,cont);
		       //		       occdiskendcap->Fill(tempo,2,cont/tempd1);
		     }
		   }
	     }
	     else
               if(rpcId.station()==3){
		 if(noise_flag){
		   if(noise_limit<counter)
		     occdiskendcap->Fill(tempo,5,cont);
		   //		     occdiskendcap->Fill(tempo,5,cont/tempd3);
		 }
		 else{
		   occdiskendcap->Fill(tempo,5,cont);
		   //		   occdiskendcap->Fill(tempo,5,cont/tempd3);
		 }
               }
	       else
                 if(rpcId.station()==2){
		   if(noise_flag){
                     if(noise_limit<counter)
		       occdiskendcap->Fill(tempo,4,cont);
		     //		       occdiskendcap->Fill(tempo,4,cont/tempd2);
                   }
                   else{
		     occdiskendcap->Fill(tempo,4,cont);
		     //		     occdiskendcap->Fill(tempo,4,cont/tempd2);
                   }
                 }
                 else
                   if(rpcId.station()==1){
		     if(noise_flag){
		       if(noise_limit<counter)
			 occdiskendcap->Fill(tempo,3,cont);
		       //			 occdiskendcap->Fill(tempo,3,cont/tempd1);
		     }
		     else{
		       occdiskendcap->Fill(tempo,3,cont);
		       //		       occdiskendcap->Fill(tempo,3,cont/tempd1);
		     }
                   }
	   }

           if(rpcId.region() == 0 ){
	     if(noise_flag){
	       if(noise_limit<counter){
		 occbarrel->Fill(tempo,cont);
		 occbarrel1->Fill(tempo1,cont);
		 occbrlend->Fill(tempo,1,cont);
		 //		 occbarrel->Fill(tempo,cont/(tempm2+tempm1+temp0+temp1+temp2));
		 //		 occbarrel1->Fill(tempo1,cont/(tempm2+tempm1+temp0+temp1+temp2));
		 //		 occbrlend->Fill(tempo,1,cont/(tempm2+tempm1+temp0+temp1+temp2));
	       }
	     }
	     else{
	       occbarrel->Fill(tempo,cont);
	       occbarrel1->Fill(tempo1,cont);
	       occbrlend->Fill(tempo,1,cont);
	       //	       occbarrel->Fill(tempo,cont/(tempm2+tempm1+temp0+temp1+temp2));
	       //	       occbarrel1->Fill(tempo1,cont/(tempm2+tempm1+temp0+temp1+temp2));
	       //	       occbrlend->Fill(tempo,1,cont/(tempm2+tempm1+temp0+temp1+temp2));
	     }
	     
	     if(rpcId.ring()==-2){
	       if(noise_flag){
		 if(noise_limit<counter){
		   occwheelbarrel->Fill(tempo,0.,cont);
		   //		   occwheelbarrel->Fill(tempo,0.,cont/(tempm2));
		 }
	       }
	       else{
		 occwheelbarrel->Fill(tempo,0.,cont);
		 //		 occwheelbarrel->Fill(tempo,0.,cont/(tempm2));
	       }
	     }
	     else 
	       if(rpcId.ring()==-1){
		 if(noise_flag){
		   if(noise_limit<counter)
		     occwheelbarrel->Fill(tempo,1,cont);
		   //		     occwheelbarrel->Fill(tempo,1,cont/(tempm1));
		 }
		 else{
		   occwheelbarrel->Fill(tempo,1,cont);
		   //		   occwheelbarrel->Fill(tempo,1,cont/(tempm1));
		 }
	       }
	       else
		 if(rpcId.ring()==0){
		   if(noise_flag){
                     if(noise_limit<counter)
		       occwheelbarrel->Fill(tempo,2,cont);
		     //		       occwheelbarrel->Fill(tempo,2,cont/(temp0));
                   }
                   else{
		     occwheelbarrel->Fill(tempo,2,cont);
		     //		     occwheelbarrel->Fill(tempo,2,cont/(temp0));
                   }
		 }
		 else
		   if(rpcId.ring()==1){
		     if(noise_flag){
		       if(noise_limit<counter)
			 occwheelbarrel->Fill(tempo,3,cont);
		       //			 occwheelbarrel->Fill(tempo,3,cont/(temp1));
		     }
		     else{
		       occwheelbarrel->Fill(tempo,3,cont);
		       //		       occwheelbarrel->Fill(tempo,3,cont/(temp1));
		     }
		   }
		   else
		     if(rpcId.ring()==2){
		       if(noise_flag){
			 if(noise_limit<counter)
			   occwheelbarrel->Fill(tempo,4,cont);
			 //			   occwheelbarrel->Fill(tempo,4,cont/(temp2));
		       }
		       else{
			 occwheelbarrel->Fill(tempo,4,cont);
			 //			 occwheelbarrel->Fill(tempo,4,cont/(temp2));
		       }
		     }
	   }
           else {
	     if(noise_flag){
	       if(noise_limit<counter)
		 occEnd->Fill(tempo,cont);
	       //		 occEnd->Fill(tempo,cont/(tempd1+tempd1+tempd3));
	     }
	     else{
	       occEnd->Fill(tempo,cont);
	       //	       occEnd->Fill(tempo,cont/(tempd1+tempd1+tempd3));
	     }
             if (rpcId.region() == -1){
	       if(noise_flag){
		 if(noise_limit<counter)
		   occbrlend->Fill(tempo,2,cont);
		 //		   occbrlend->Fill(tempo,2,cont/(tempd1+tempd1+tempd3));
	       }
	       else{
		 occbrlend->Fill(tempo,2,cont);
		 //		 occbrlend->Fill(tempo,2,cont/(tempd1+tempd1+tempd3));
	       }
	     }
             else if (rpcId.region() == 1){
	       if(noise_flag){
		 if(noise_limit<counter)
		   occbrlend->Fill(tempo,0.,cont);
		 //		   occbrlend->Fill(tempo,0.,cont/(tempd1+tempd1+tempd3));
	       }
	       else{
		 occbrlend->Fill(tempo,0.,cont);
		 //		 occbrlend->Fill(tempo,0.,cont/(tempd1+tempd1+tempd3));
	       }
	     }
           }
         }
	 }
       }
     }
   }
}
	   

// ------------ method called once each job just before starting event loop  ------------
void RPCOffLineNoise::beginJob(){

}

void 
RPCOffLineNoise::beginRun(const edm::Run & run, const edm::EventSetup & eventSetup)
{

  cout << "Begin Job " << endl;
  ESHandle<RPCGeometry> rpcGeometry;
  eventSetup.get<MuonGeometryRecord>().get(rpcGeometry);
  RPCrolls= rpcGeometry->rolls() ;
  ientry=0;
  //  edm::Service<TFileService> fs;

  int time = hours;

  eventperbin = fs->make<TH1F>("Timeperbin","Time per bin",time,0,time);


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
  meCollection = noiseRPCbookDet(eventSetup)  ;
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

void 
RPCOffLineNoise::endRun(const edm::Run & run, const edm::EventSetup & eventSetup)
{

  //cout <<"**** Summary **** " << endl;
  //cout <<"segments:   1 segment in chamber, 0 segment from track " << n1seg0tkSeg << endl;
  //cout <<"segments:   2 or more segment in chamber, 0 segment from track " << n2seg0tkSeg << endl;
  //cout <<"segments:   1 segment in chamber, 1 segment from track " << n1seg1tkSeg << endl;
  //cout <<"segments:   2 or more segment in chamber, 1 segment from track " << n2seg1tkSeg << endl;

  //cout <<"*** Noise summary *** " << endl;
  //cout <<"Total number of events " << nEvents << endl;
  for (int i=0;i<5;i++) {
    for (int j=0;j<12;j++) {
      //cout <<"Wheel " << i-2 << "  sector " << j+1 << "  time integral " << barrel_timeEv[i][j] << endl;;
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
      //cout <<"roll " << RPCname.name() << "  noise: " << noiseMap[detId] << " time integrated " << timeDAQ << " noise Norm " << noise << endl;
      hNoiseByRoll->Fill(noise);
    }
  }

  //cout <<"save root file" << endl;

  occbrlend->SetOption("COLZ");
  occdiskendcap->SetOption("COLZ");
  occwheelbarrel->SetOption("COLZ");

  //  dbe->save("noiseRPCOffline.root");
  /*  occbarrel->Write();
  occbarrel1->Write();
  occEnd->Write();
  occwheelbarrel->Write();
  occdiskendcap->Write();
  occbrlend->Write();

  hl1em->Write();

  brlNoiseDist->Write();
  fwdNoiseDist->Write();
  overallNoiseDist->Write();
  */
  for(std::vector<TH2F*>::const_iterator i=wheelhis.begin();i!=wheelhis.end();++i ){
    (*i)->SetOption("COLZ");//(*i)->Write();
  }

  for(std::vector<TH2F*>::const_iterator i=diskhis.begin();i!=diskhis.end();++i ){
    (*i)->SetOption("COLZ");//(*i)->Write();
  }

  for(std::vector<TH2F*>::const_iterator i=chamwheelhis.begin();i!=chamwheelhis.end();++i ){
    (*i)->SetOption("COLZ");//(*i)->Write();
  }

  for(std::vector<TH2F*>::const_iterator i=chamdiskhis.begin();i!=chamdiskhis.end();++i ){
    (*i)->SetOption("COLZ");//(*i)->Write();
  }
  /*
  for(std::vector<TH1F*>::const_iterator i=wheelprof.begin();i!=wheelprof.end();++i )(*i)->Write();

  for(std::vector<TH1F*>::const_iterator i=diskprof.begin();i!=diskprof.end();++i )(*i)->Write();

  for(std::vector<TH1F*>::const_iterator i=chamwheelprof.begin();i!=chamwheelprof.end();++i )(*i)->Write();

  for(std::vector<TH1F*>::const_iterator i=chamdiskprof.begin();i!=chamdiskprof.end();++i )(*i)->Write();

  for(vector<TH1F*>::const_iterator i=towerprof.begin();i!=towerprof.end();++i)(*i)->Write();

  for(vector<TH1F*>::const_iterator wd=wheelNoiseDist.begin();wd!=wheelNoiseDist.end();wd++)(*wd)->Write();

  for(vector<TH1F*>::const_iterator dd=diskNoiseDist.begin();dd!=diskNoiseDist.end();dd++)(*dd)->Write();
  */
//   TH1F *Dna_val=new TH1F("Dna_val","Value of \"Density Noise Activity\" Estimator",1,0.,1.);

//  hfile->Close();

}

// ------------ method called once each job just after ending the event loop  ------------
void 
RPCOffLineNoise::endJob() {

}

map<string, map<string, MonitorElement*> >
RPCOffLineNoise::noiseRPCbookDet( const edm::EventSetup &
				  eventSetup)
{
  //  RPCGeometry                                                                                                                                     
  map<string, map<string, MonitorElement*> > meCollection;

  ESHandle<RPCGeometry> rpcGeometry;
  eventSetup.get<MuonGeometryRecord>().get(rpcGeometry);

  vector< RPCRoll*> rolls= rpcGeometry->rolls() ;
  for(vector< RPCRoll*>::iterator RPCIt = rolls.begin(); RPCIt != rolls.end();
      RPCIt++){
    RPCDetId detId = (*RPCIt)->id();
    map<string, MonitorElement*> meMap;

    string regionName;
    string ringType;
    if(detId.region()==0) {
      regionName="Barrel";
      ringType="Wheel";
    }
    else{
      ringType="Disk";
      if(detId.region() == -1) regionName="Endcap-";
      if(detId.region() ==  1) regionName="Endcap+";
    }

    char  folder[120];
    sprintf(folder,"RPC/noiseOffline/%s/%s_%d/station_%d/sector_%d",regionName.c_str(),ringType.c_str(),
            detId.ring(),detId.station(),detId.sector());

    //    dbe->setCurrentFolder(folder);
    int strips = 0; double lastvalue = 0.;
    strips = (*RPCIt)->nstrips();

    if(strips == 0 ) strips = 1;
    lastvalue=(double)strips+0.5;

    RPCGeomServ RPCname(detId);
    std::string nameRoll = RPCname.name();

    char detUnitLabel[128];
    char layerLabel[128];

    sprintf(detUnitLabel ,"%s",nameRoll.c_str());
    sprintf(layerLabel ,"%s",nameRoll.c_str());

    char meId [128];
    char meTitle [128];

    //Begin booking                                                                                                                                   
    //    sprintf(meId,"ExpectedOccupancyFromTrack_%s",detUnitLabel);                                                                                 
    //   sprintf(meTitle,"ExpectedOccupancyFromTrack_for_%s",layerLabel);                                                                             
    //   meMap[meId] = dbe->book1D(meId, meTitle, strips, 0.5, lastvalue);                                                                            

    sprintf(meId,"RPCDataOccupancy_%s",detUnitLabel);
    sprintf(meTitle,"RPCDataOccupancy_for_%s",layerLabel);
    //    meMap[meId] = dbe->book1D(meId, meTitle, strips, 0.5, lastvalue);
    sprintf(meId,"RPCNoiseOccupancy_%s",detUnitLabel);
    sprintf(meTitle,"RPCNoiseOccupancy_for_%s",layerLabel);
    //    meMap[meId] = dbe->book1D(meId, meTitle, strips, 0.5, lastvalue);
    /*                                                                                                                                                
    sprintf(meId,"Residuals_%s",detUnitLabel);                                                                                                        
    sprintf(meTitle,"Residuals_for_%s",layerLabel);                                                                                                   
    meMap[meId] = dbe->book1D(meId, meTitle, 150,-49.5, 49.);                                                                                         
                                                                                                                                                      
    sprintf(meId,"EfficienyFromTrackExtrapolation_%s",detUnitLabel);                                                                                  
    sprintf(meTitle,"EfficienyFromTrackExtrapolation_for_%s",layerLabel);                                                                             
    meMap[meId] = dbe->book1D(meId, meTitle, strips, 0.5, lastvalue);                                                                                 
                                                                                                                                                      
    sprintf(meId,"ClusterSize_%s",detUnitLabel);                                                                                                      
    sprintf(meTitle,"ClusterSize_for_%s",layerLabel);                                                                                                 
    meMap[meId] = dbe->book1D(meId, meTitle,10,0.5,10.5);                                                                                             
    */
    sprintf(meId,"BunchX_%s",detUnitLabel);
    sprintf(meTitle,"BunchX_for_%s",layerLabel);
    //    meMap[meId] = dbe->book1D(meId, meTitle,13,-6.5,6.5);
    meCollection[nameRoll] = meMap;
  }
  return meCollection;
}

//define this as a plug-in
DEFINE_FWK_MODULE(RPCOffLineNoise);
