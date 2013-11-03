// -*- C++ -*-
//
// Package:    RPCTriggerNoise
// Class:      RPCTriggerNoise
// 
/**\class RPCTriggerNoise RPCTriggerNoise.cc UserCode/RPCTriggerNoise/src/RPCTriggerNoise.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Alberto Andres Ocampo Rios
//         Created:  Thu Feb 19 11:27:07 CET 2009
// $Id: RPCTriggerNoise.cc,v 1.4 2009/08/16 12:01:16 aocampor Exp $
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
#include "FWCore/Framework/interface/Run.h"
#include "FWCore/ParameterSet/interface/InputTag.h"

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
//#include "CondTools/Hcal/interface/HcalL1TriggerObjectsHandler.h"
//#include "CondFormats/DataRecord/src/HcalL1TriggerObjectsRcd.cc"

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
#include <TStyle.h>

//string                                                                                                  
#include <string>


//
// class decleration
//

class RPCTriggerNoise : public edm::EDAnalyzer {
public:
  explicit RPCTriggerNoise(const edm::ParameterSet&);
  ~RPCTriggerNoise();
  
  
private:
  virtual void beginJob(const edm::EventSetup&) ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  virtual void BookFile();
  void statAnal(const TH1F* , TH1F* &,const int, const std::string);

  int binnum;
  int binbx;

  TFile *hfile;

  std::string nomrootfile;
  edm::InputTag m_GMTInputTag;
  std::string labelDT;
  edm::InputTag labelRPC;
  int hours;

  TH1F *ntrigmuon;
  TH1F *ntrigrpc;
  TH1F *ntrigrpcb;
  TH1F *ntrigrpcf;
  TH1F *ntrigrpcq;
  TH1F *ntrigdt;
  TH1F *ntrigcsc;
  //  TH1F *ntrigecal;

  TH1F *heven; 

  TH1F *ndigirpc;
  TH1F *ndigirpcnoise;
  /* TH1F *ndigidt;
  TH1F *ndigicsc;
  TH1F *nrechitecal;
  TH1F *nrechithcal;
  TH1F *ndigipixel;
  TH1F *ndigitracker;
  */
  TH1F *ndigirpc_rpc;
  /*  TH1F *ndigidt_rpc;
  TH1F *ndigicsc_rpc;
  TH1F *nrechitecal_rpc;
  TH1F *nrechithcal_rpc;
  TH1F *ndigipixel_rpc;
  TH1F *ndigitracker_rpc;
  */
  TH1F *ndigirpc_dt_csc;
  /*  TH1F *ndigidt_dt_csc;
  TH1F *ndigicsc_dt_csc;
  TH1F *nrechitecal_dt_csc;
  TH1F *nrechithcal_dt_csc;
  TH1F *ndigipixel_dt_csc;
  TH1F *ndigitracker_dt_csc;
  */
  TH1D *dbxrpc;
  TH1D *dbxdt;
  TH1D *dbxcsc;
  TH1D *dbxecal;

  TH1D *hphi;  
  TH1D *heta;
  TH2D *hphieta;

  TH1F *dtRateDist, *cscRateDist, *rpcTotRateDist, *rpcBrlRateDist, *rpcFwdRateDist;
  TH1F *Dna_Val;

  int prevbxrpc;
  int prevbxdt;
  int prevbxcsc;
  int prevbxecal;

  int prevevenrpc;
  int prevevendt;
  int prevevencsc;
  int prevevenecal;

  unsigned long long orbrpc;
  unsigned long long orbdt;
  unsigned long long orbcsc;
  unsigned long long orbecal;



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
RPCTriggerNoise::RPCTriggerNoise(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
  nomrootfile = iConfig.getUntrackedParameter<std::string>("root_file_name","RPCTriggerNoise.root");
  m_GMTInputTag = iConfig.getParameter<edm::InputTag>("GMTInputTag");
  binbx = iConfig.getUntrackedParameter<int>("bins");
  labelDT = iConfig.getUntrackedParameter<std::string>("labelDT");
  labelRPC = iConfig.getParameter<edm::InputTag>("labelRPC");
  hours = iConfig.getUntrackedParameter<int>("hours");
  BookFile();
}

RPCTriggerNoise::~RPCTriggerNoise()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


void RPCTriggerNoise::BookFile(){

  hfile = new TFile(nomrootfile.c_str(),"RECREATE");

  gStyle->SetPalette(1);

  binnum = hours*3600;

  heven = new TH1F("NEven", "Number of Events per second",binnum, 0,binnum);

  ntrigmuon = new TH1F("NTrigMuon", "Number of muon trig. candidate per event ",binnum, 0,binnum);
  ntrigrpc = new TH1F("NTrigRPC", "Number of RPC trig. candidate per event ",binnum, 0, binnum);
  ntrigrpcb = new TH1F("NTrigRPCBrl", "Number of RPC Barrel trig. candidate per event ",binnum, 0, binnum);
  ntrigrpcf = new TH1F("NTrigRPCFwd", "Number of RPC Forward trig. candidate per event ",binnum, 0, binnum);
  ntrigrpcq = new TH1F("NTrigRPCquality", "Number of RPC trig. candidate per event quality bigger or equal than 2 ",binnum, 0, binnum);
  ntrigdt = new TH1F("NTrigDT", "Number of DT trig. candidate per event ",binnum, 0, binnum);
  ntrigcsc = new TH1F("NTrigCSC", "Number of CSC trig. candidate per event ",binnum, 0, binnum);
  //  ntrigecal = new TH1F("NTrigECAL", "Number of ECAL trig. candidate per event ",binnum, 0, binnum);

  ndigirpc = new TH1F("NDigiRPC", "Number of RPC digis per event ",binnum, 0, binnum);
  ndigirpcnoise = new TH1F("NDigiRPCnoise", "Number of RPC digis per event bigger than a cut 80 digis ",binnum, 0, binnum);
  /*  ndigidt = new TH1F("NDigiDT", "Number of DT digis per event ",binnum, 0, binnum);
  ndigicsc = new TH1F("NDigiCSC", "Number of CSC digis per event ",binnum, 0, binnum);
  nrechitecal = new TH1F("NRecHitECAL", "Number of ECAL RecHits per event ",binnum, 0, binnum);
  nrechithcal = new TH1F("NRecHitHCAL", "Number of HCAL RecHits per event ",binnum, 0, binnum);
  ndigipixel = new TH1F("NDigiPixel", "Number of Pixel digis per event ",binnum, 0, binnum);
  ndigitracker = new TH1F("NDigiTracker", "Number of Tracker digis per event ",binnum, 0, binnum);
  */
  ndigirpc_rpc = new TH1F("NDigiRPC_TRPC", "Number of RPC digis per event with RPC trigger",binnum, 0, binnum);
  /*  ndigidt_rpc = new TH1F("NDigiDT_TRPC", "Number of DT digis per event with RPC trigger",binnum, 0, binnum);
  ndigicsc_rpc = new TH1F("NDigiCSC_TRPC", "Number of CSC digis per event with RPC trigger",binnum, 0, binnum);
  nrechitecal_rpc = new TH1F("NRecHitECAL_TRPC", "Number of ECAL RecHits per event with RPC trigger",binnum, 0, binnum);
  nrechithcal_rpc = new TH1F("NRecHitHCAL_TRPC", "Number of HCAL RecHits per event with RPC trigger",binnum, 0, binnum);
  ndigipixel_rpc = new TH1F("NDigiPixel_TRPC", "Number of Pixel digis per event with RPC trigger",binnum, 0, binnum);
  ndigitracker_rpc = new TH1F("NDigiTracker_TRPC", "Number of Tracker digis per event with RPC trigger",binnum, 0, binnum);
  */
  ndigirpc_dt_csc = new TH1F("NDigiRPC_TDT_CSC", "Number of RPC digis per event with DT-CSC trigger",binnum, 0, binnum);
  /*  ndigidt_dt_csc = new TH1F("NDigiDT_TDT_CSC", "Number of DT digis per event with DT-CSC trigger",binnum, 0, binnum);
  ndigicsc_dt_csc = new TH1F("NDigiCSC_TDT_CSC", "Number of CSC digis per event with DT-CSC trigger",binnum, 0, binnum);
  nrechitecal_dt_csc = new TH1F("NRecHitECAL_TDT_CSC", "Number of ECAL RecHits per event with DT-CSC trigger",binnum, 0, binnum);
  nrechithcal_dt_csc = new TH1F("NRecHitHCAL_TDT_CSC", "Number of HCAL RecHits per event with DT-CSC trigger",binnum, 0, binnum);
  ndigipixel_dt_csc = new TH1F("NDigiPixel_TDT_CSC", "Number of Pixel digis per event with DT-CSC trigger",binnum, 0, binnum);
  ndigitracker_dt_csc = new TH1F("NDigiTracker_TDT_CSC", "Number of Tracker digis per event with DT-CSC trigger",binnum, 0, binnum);
  */
  dbxrpc = new TH1D("BunchXDifrpc","Bx Difference rpc",binbx,0,500000);
  dbxdt = new TH1D("BunchXDifdt","Bx Difference dt",binbx,0,500000);
  dbxcsc = new TH1D("BunchXDifcsc","Bx Difference csc",binbx,0,500000);
  dbxecal = new TH1D("BunchXDifecal","Bx Difference ecal",binbx,0,500000);

  hphi = new TH1D("PhiUnderPeak","Phi Under Peak",70,0,7);
  heta = new TH1D("EtaUnderPeak","Eta Under Peak",50,-2,2);
  hphieta = new TH2D("PhiEtaPeak","Phi vs Eta Under Peak",70,0,7,50,-2,2);

  Dna_Val = new TH1F("Dna_Val","Density of Noise Activity",5,0.,5.);

  Dna_Val->GetXaxis()->SetBinLabel(1,"RPC_TOT");
  Dna_Val->GetXaxis()->SetBinLabel(2,"RPC_BRL");
  Dna_Val->GetXaxis()->SetBinLabel(3,"DT");
  Dna_Val->GetXaxis()->SetBinLabel(4,"RPC_FWD");
  Dna_Val->GetXaxis()->SetBinLabel(5,"CSC");

  /*
  dbxrpc->SetBit(TH1::kCanRebin);
  dbxdt->SetBit(TH1::kCanRebin);
  dbxcsc->SetBit(TH1::kCanRebin);
  dbxecal->SetBit(TH1::kCanRebin);
  */
  prevbxrpc=-1;
  prevbxdt =-1;
  prevbxcsc =-1;
  prevbxecal = -1;
  /*
  ntrigmuon->SetBit(TH1::kCanRebin);
  ntrigrpc->SetBit(TH1::kCanRebin); 
  ntrigdt->SetBit(TH1::kCanRebin); 
  ntrigcsc->SetBit(TH1::kCanRebin);
  ntrigecal->SetBit(TH1::kCanRebin);

  ndigirpc->SetBit(TH1::kCanRebin); 
  ndigirpcnoise->SetBit(TH1::kCanRebin); 
  ndigidt->SetBit(TH1::kCanRebin); 
  ndigicsc->SetBit(TH1::kCanRebin);
  nrechitecal->SetBit(TH1::kCanRebin);
  nrechithcal->SetBit(TH1::kCanRebin);
  ndigipixel->SetBit(TH1::kCanRebin);
  ndigitracker->SetBit(TH1::kCanRebin);

  ndigirpc_rpc->SetBit(TH1::kCanRebin);
  ndigidt_rpc->SetBit(TH1::kCanRebin); 
  ndigicsc_rpc->SetBit(TH1::kCanRebin);
  nrechitecal_rpc->SetBit(TH1::kCanRebin);
  nrechithcal_rpc->SetBit(TH1::kCanRebin);
  ndigipixel_rpc->SetBit(TH1::kCanRebin); 
  ndigitracker_rpc->SetBit(TH1::kCanRebin);

  ndigirpc_dt_csc->SetBit(TH1::kCanRebin); 
  ndigidt_dt_csc->SetBit(TH1::kCanRebin); 
  ndigicsc_dt_csc->SetBit(TH1::kCanRebin);
  nrechitecal_dt_csc->SetBit(TH1::kCanRebin);
  nrechithcal_dt_csc->SetBit(TH1::kCanRebin);
  ndigipixel_dt_csc->SetBit(TH1::kCanRebin); 
  ndigitracker_dt_csc->SetBit(TH1::kCanRebin);
  */
}

//
// member functions
//

// ------------ method called to for each event  ------------
void
RPCTriggerNoise::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace std;

   int bx = iEvent.bunchCrossing();
   int thisOrbit = iEvent.orbitNumber();
   double orbitTime = 0.03564*(double)thisOrbit +(double)((double)bx/100000.0);
   double tempo = (orbitTime/10000)*25;
   cout << "Tiempo en segundos: " << tempo << endl;

   heven->Fill(tempo);
   //___________________________________________________________________________                                                                                                                                   
   //---------------------------------------------------------------------------                                                                                                                                   
   //--------------------------------- Trigger section -------------------------                                                                                                                                   
   //___________________________________________________________________________                                                                                                                                   

   //----------------------------- ECAL TRIGGER -----------------------------------------------                                                                                                                      
   /*
   edm::Handle< l1extra::L1EmParticleCollection > emIsolColl ;
   iEvent.getByLabel("hltL1extraParticles","Isolated", emIsolColl ) ;
   //Get the L1 NonIsolated EM Collection                                                                                                                                                                          
   edm::Handle< l1extra::L1EmParticleCollection > emNonIsolColl ;
   iEvent.getByLabel("hltL1extraParticles","NonIsolated", emNonIsolColl ) ;
   if ((emIsolColl->size() + emNonIsolColl-> size())!=0 ) {
     ntrigecal->Fill(tempo,emIsolColl->size() + emNonIsolColl-> size());  
     if (prevbxecal == -1){
       prevbxecal = bx;
       prevevendt = iEvent.id().event();
       orbecal = iEvent.orbitNumber();
     }
     else {
       if(fabs(iEvent.id().event()-prevevenecal) == 1){
	 dbxecal->Fill(3564*(iEvent.orbitNumber()-orbecal)+bx-prevbxecal);
       }
       prevbxecal =bx;
       prevevenecal = iEvent.id().event();
       orbecal = iEvent.orbitNumber();
     }

   }



   //--------------------------------HCAL Trigger --------------------
   edm::ESHandle< HcalL1TriggerObjectsRcd> objecthandle;
   iSetup.get<HcalL1TriggerObjectsRcd>().get(objecthandle);
   myDBObject = new HcalL1TriggerObjects(*objecthandle.product() );*/

   //----------------------------- GLOBAL MUON TRIGGER ----------------------------------------                                                                                                                      

   edm::Handle<L1MuGMTReadoutCollection> gmtrc_handle;
   iEvent.getByLabel(m_GMTInputTag,gmtrc_handle);
   L1MuGMTReadoutCollection const* gmtrc = gmtrc_handle.product();

   std::vector<L1MuGMTReadoutRecord> gmt_records = gmtrc->getRecords();
   std::vector<L1MuGMTReadoutRecord>::const_iterator igmtrr;

   int idt;
   int icsc;
   int ihalo;
   int irpcb;
   int irpcbq;
   int irpcfq;
   int irpcf;
   
   bool dt_l1a = false;
   bool csc_l1a = false;
   bool halo_l1a = false;
   bool rpcb_l1a = false;
   bool rpcf_l1a = false;

   for(igmtrr=gmt_records.begin(); igmtrr!=gmt_records.end(); igmtrr++) {

     std::vector<L1MuRegionalCand>::const_iterator iter1;
     std::vector<L1MuRegionalCand> rmc;

     // DT muon candidates                                                                                                                                                                                         
     idt = 0;
     rmc = igmtrr->getDTBXCands();
     for(iter1=rmc.begin(); iter1!=rmc.end(); iter1++) {
       if ( !(*iter1).empty() ) {
	 idt++;
         if (prevbxdt == -1){
           prevbxdt = bx;
           orbdt = iEvent.orbitNumber();
           prevevendt = iEvent.id().event();
         }
         else {
           if(fabs(iEvent.id().event()-prevevendt) == 1){
             dbxdt->Fill(3564*(iEvent.orbitNumber()-orbdt)+bx-prevbxdt);
           }
           prevbxdt =bx;
           prevevendt = iEvent.id().event();
           orbdt = iEvent.orbitNumber();
         }
       }
     }

     ntrigdt->Fill(tempo,idt);
     if(igmtrr->getBxInEvent()==0 && idt>0) dt_l1a = true;
     // CSC muon candidates                                                                                                                                                                                        
     icsc = 0;
     ihalo = 0;
     rmc = igmtrr->getCSCCands();
     for(iter1=rmc.begin(); iter1!=rmc.end(); iter1++) {
       if ( !(*iter1).empty() ) {
         if (prevbxcsc == -1){
           prevbxcsc = bx;
           orbcsc = iEvent.orbitNumber();
           prevevencsc = iEvent.id().event();
         }
         else {
           if(fabs(iEvent.id().event()-prevevencsc) == 1){
	     dbxcsc->Fill(3564*(iEvent.orbitNumber()-orbcsc)+bx-prevbxcsc);
	   }
           prevbxcsc =bx;
           prevevencsc = iEvent.id().event();
           orbcsc = iEvent.orbitNumber();
         }

	 if((*iter1).isFineHalo()) {
	   ihalo++;
	 } else {
	   icsc++;
	 }
       }
     }
     
     ntrigcsc->Fill(tempo,icsc+ihalo);
     if(igmtrr->getBxInEvent()==0 && icsc>0) csc_l1a = true;
     if(igmtrr->getBxInEvent()==0 && ihalo>0) halo_l1a = true;

     // RPC barrel muon candidates                                                                                                                                                                                 
     irpcb = 0;
     irpcbq = 0;
     rmc = igmtrr->getBrlRPCCands();
     for(iter1=rmc.begin(); iter1!=rmc.end(); iter1++) {
       if ( !(*iter1).empty() ) {
	 irpcb++;
	 if((*iter1).quality()>=2){
	   irpcbq++;
	 }
         if (prevbxrpc == -1){
           prevbxrpc = bx;
           orbrpc = iEvent.orbitNumber();
           prevevenrpc = iEvent.id().event();

         }
         else {
           if(fabs(iEvent.id().event()-prevevenrpc) == 1){
             dbxrpc->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbxrpc);

           }
           prevbxrpc =bx;
           prevevenrpc = iEvent.id().event();
           orbrpc = iEvent.orbitNumber();
         }
	 hphi->Fill((*iter1).phiValue());
	 heta->Fill((*iter1).etaValue());
	 hphieta->Fill((*iter1).phiValue(),(*iter1).etaValue());
       }
     }

     if(igmtrr->getBxInEvent()==0 && irpcb>0) rpcb_l1a = true;
     // RPC endcap muon candidates                                                                                                                                                                                 
     irpcf = 0;
     irpcfq = 0;
     rmc = igmtrr->getFwdRPCCands();
     for(iter1=rmc.begin(); iter1!=rmc.end(); iter1++) {
       if ( !(*iter1).empty() ) {
	 irpcf++;
	 if((*iter1).quality()>=2){
	   irpcfq++;
	 }
         if (prevbxrpc == -1){
           prevbxrpc = bx;
           orbrpc = iEvent.orbitNumber();
           prevevenrpc = iEvent.id().event();
         }
         else {
           if(fabs(iEvent.id().event()-prevevenrpc) == 1){
             dbxrpc->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbxrpc);
           }
           prevbxrpc =bx;
           prevevenrpc = iEvent.id().event();
           orbrpc = iEvent.orbitNumber();
         }
       }
     }

     ntrigrpc->Fill(tempo,irpcb+irpcf);
     ntrigrpcb->Fill(tempo,irpcb);
     ntrigrpcf->Fill(tempo,irpcf);
     ntrigrpcq->Fill(tempo,irpcbq+irpcfq);
     ntrigmuon->Fill(tempo,irpcb+irpcf+icsc+ihalo+idt);

     if(igmtrr->getBxInEvent()==0 && irpcf>0) rpcf_l1a = true;
     
   }
   

   //___________________________________________________________________________                                                                                                                                   
   //---------------------------------------------------------------------------                                                                                                                                   
   //--------------------------------- Digi and RECHIT section -------------------------                                                                                                                           
   //___________________________________________________________________________                                                                                                                                   

   //----------------------------------------------------------------------------------------------------------                                                                                                                                                                                                             
   //------------------------------- RPC DIGI -----------------------------------------------------------------                                                                                                                                                                                                             
   
   edm::Handle<RPCDigiCollection> rpcdigis;
   //   iEvent.getByLabel("muonRPCDigis",rpcdigis);
   iEvent.getByLabel(labelRPC,rpcdigis);
   edm::ESHandle<RPCGeometry> rpcGeo;
   iSetup.get<MuonGeometryRecord>().get(rpcGeo);
   int counter = 0;

   for (TrackingGeometry::DetContainer::const_iterator it=rpcGeo->dets().begin();it<rpcGeo->dets().end();it++){
     if(dynamic_cast< RPCChamber* >( *it ) != 0 ){
       RPCChamber* ch = dynamic_cast< RPCChamber* >( *it );
       std::vector< const RPCRoll*> roles = (ch->rolls());
       for(std::vector<const RPCRoll*>::const_iterator r = roles.begin();r != roles.end(); ++r){
         RPCDetId rpcId = (*r)->id();
	 RPCDigiCollection::Range rpcRangeDigi=rpcdigis->get(rpcId);
         for (RPCDigiCollection::const_iterator digiIt = rpcRangeDigi.first;digiIt!=rpcRangeDigi.second;++digiIt){
	   counter++;
         }
       }
     }
   }
   ndigirpc->Fill(tempo,counter);   
   if(counter > 80){
     ndigirpcnoise->Fill(tempo,counter);
   }
   /*
   for (TrackingGeometry::DetContainer::const_iterator it=rpcGeo->dets().begin();it<rpcGeo->dets().end();it++){
     if(dynamic_cast< RPCChamber* >( *it ) != 0 ){
       RPCChamber* ch = dynamic_cast< RPCChamber* >( *it );
       std::vector< const RPCRoll*> roles = (ch->rolls());
       for(std::vector<const RPCRoll*>::const_iterator r = roles.begin();r != roles.end(); ++r){
	 RPCDetId rpcId = (*r)->id();
	 RPCGeomServ rpcsrv(rpcId);
	 string name = rpcsrv.name();
	 char nomchamb[50];
	 strcpy(nomchamb,name.c_str());
	 RPCDigiCollection::Range rpcRangeDigi=rpcdigis->get(rpcId);
	 int cont=0;
	 for (RPCDigiCollection::const_iterator digiIt = rpcRangeDigi.first;digiIt!=rpcRangeDigi.second;++digiIt){
	   cont++;
	 }
       }
     }
   }
*/

   //----------------------------------------------------------------------------------------------------------                
   
   if ((rpcb_l1a or rpcf_l1a) and (not (dt_l1a) and not (csc_l1a))){
     ndigirpc_rpc->Fill(tempo,counter);
   }
   if ((dt_l1a or csc_l1a or halo_l1a) and (not rpcb_l1a and not rpcf_l1a)){
     ndigirpc_dt_csc->Fill(tempo,counter);
   }


}


// ------------ method called once each job just before starting event loop  ------------
void 
RPCTriggerNoise::beginJob(const edm::EventSetup&)
{

}

// ------------ method called once each job just after ending the event loop  ------------
void 
RPCTriggerNoise::endJob() {

  heven->Write();

  ntrigmuon->Write();
  ntrigrpc->Write();
  ntrigrpcb->Write();
  ntrigrpcf->Write();
  ntrigrpcq->Write();
  ntrigdt->Write();
  ntrigcsc->Write();
  //  ntrigecal->Write();

  ndigirpc->Write(); 
  ndigirpcnoise->Write(); 

  ndigirpc_rpc->Write();
  /*  ndigidt_rpc->Write();
  ndigicsc_rpc->Write();
  */
  ndigirpc_dt_csc->Write(); 
  /*  ndigidt_dt_csc->Write();
  ndigicsc_dt_csc->Write();
  nrechitecal_dt_csc->Write();
  nrechithcal_dt_csc->Write();
  ndigipixel_dt_csc->Write(); 
  ndigitracker_dt_csc->Write();
  */
  dbxrpc->Write();
  dbxdt->Write();
  dbxcsc->Write();
  dbxecal->Write();

  hphi->Write();
  heta->Write();
  hphieta->Write();

  this->statAnal(ntrigrpc,rpcTotRateDist,1,"rpcTot");
  this->statAnal(ntrigrpcb,rpcBrlRateDist,2,"rpcBrl");
  this->statAnal(ntrigdt,dtRateDist,3,"dt");
  this->statAnal(ntrigrpcf,rpcFwdRateDist,4,"rpcFwd");
  this->statAnal(ntrigcsc,cscRateDist,5,"csc");


  hfile->Close();
}

void RPCTriggerNoise::statAnal(const TH1F *h1, TH1F* &rateDist, const int dnaBin, const std::string det){

  int rateMaxBin=h1->GetMaximumBin();
  float xMax=(float)h1->GetBinContent(rateMaxBin);xMax++;
  int nBinDist((int)xMax/5);
  std::string hName=det+"RateDist",hTitle="Trigger Rate Distribution for "+det+";Rate (Hz);Entries/5 Hz";
  rateDist=new TH1F(hName.c_str(),hTitle.c_str(),nBinDist,0.,xMax);

  int nBins=h1->GetNbinsX();
  std::vector<float> valVec;valVec.reserve(nBins);
  for(int b=1;b<=nBins;b++){
    float val=h1->GetBinContent(b);
    if(val!=0){
      valVec.push_back(val);
      rateDist->Fill(val);
    }
  }

  float mpv=rateDist->GetBinCenter(rateDist->GetMaximumBin());
  float ent=rateDist->GetEntries();

  float dispFromMax(0.);Double_t rmsWrtMax(0.);
  for(unsigned int i=0;i<valVec.size();i++){
    float dv=valVec[i];
    if(dv!=0){
      dispFromMax+=(dv-mpv)/mpv;
      rmsWrtMax+=pow((dv-mpv),2);
    }
  }
  rmsWrtMax=sqrt(rmsWrtMax/ent);
  //  xMax+=rateDist->GetBinWidth(nBinDist);
  int mpvPlusRms=rateDist->GetXaxis()->FindBin(mpv+rmsWrtMax);
  float Dna=(rateDist->Integral(mpvPlusRms,(int)xMax)*(xMax))/((xMax-mpvPlusRms)*ent);

  //  TH1F *Dna_Val=new TH1F("Dna_Val","Density of Noise Activity Estimator Valus",1,0.,1.);
  Dna_Val->SetBinContent(dnaBin,Dna);

  rateDist->Write();
  Dna_Val->Write();

}

//define this as a plug-in
DEFINE_FWK_MODULE(RPCTriggerNoise);
