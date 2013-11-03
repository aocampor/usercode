// -*- C++ -*-
//
// Package:    TBXanal
// Class:      TBXanal
// 
/**\class TBXanal TBXanal.cc UserCode/TBXanal/src/TBXanal.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Alberto Andres Ocampo Rios
//         Created:  Fri Feb 13 13:22:19 CET 2009
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
#include "FWCore/ParameterSet/interface/InputTag.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"


////Data Format

#include "DataFormats/RPCDigi/interface/RPCDigi.h"
#include "DataFormats/RPCDigi/interface/RPCDigiCollection.h"
#include "DataFormats/MuonDetId/interface/RPCDetId.h"
#include "DataFormats/RPCRecHit/interface/RPCRecHitCollection.h"


///Geometry
#include "FWCore/Framework/interface/ESHandle.h"
#include "Geometry/RPCGeometry/interface/RPCGeometry.h"
#include "Geometry/Records/interface/MuonGeometryRecord.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"
#include "Geometry/RPCGeometry/interface/RPCGeomServ.h"
#include "Geometry/CommonTopologies/interface/RectangularStripTopology.h"


/////Trigger
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
#include "DataFormats/L1GlobalMuonTrigger/interface/L1MuGMTExtendedCand.h"
#include "CondFormats/L1TObjects/interface/L1GtParameters.h"
#include "CondFormats/DataRecord/interface/L1GtParametersRcd.h"



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

#include "DataFormats/Provenance/interface/Timestamp.h"
#include <sys/time.h>

//
// class decleration
//

class TBXanal : public edm::EDAnalyzer {
public:
  explicit TBXanal(const edm::ParameterSet&);
  ~TBXanal();
  
private:
  virtual void beginJob(const edm::EventSetup&) ;
  void beginRun(const edm::Run&, const edm::EventSetup&);
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  
  TFile *hfile;
  TH1F *h1;
  TH1D *h2;
  TH1F *h3;
  TH1F *h5;
  TH1D *h4;
  TH1D *h6;
  TH1D *h9;
  TH1D *h10;
  TH1D *h11;
  TH1D *h12;
  TH1D *h13;
  TH1I *h14;
  TH1I *h19;
  TH1I *h20;
  TH1D *h7;
  TH1D *h8;
  TH1D *h15;
  TH1D *h16;
  TH1D *h17;
  TH1D *h18;
  TH1D *h21;
  TH1D *h22;
  TH2D *h23;
  TH1D *h24;
  //  TH1D *h25;
  //  TH1D *h26;
  TH1I *h27;
  TH1I *h28;
  TH1I *h29;
  TH1D *h10_2;
  TH1D *h13_2;
  TH1D *h10_3;
  TH1D *h13_3;
  TH1D *h10_4;
  TH1D *h13_4;
  TH1D *h10_5;
  TH1D *h13_5;
  TH1D *h10_6;
  TH1D *h13_6;
  TH1D *h10_7;
  TH1D *h13_7;
  TH1D *h10_8;
  TH1D *h13_8;
  TH1D *h10_9;
  TH1D *h13_9;
  TH1D *h10_10;
  TH1D *h13_10;
  TH1D *h10_11;
  TH1D *h13_11;
  TH1D *h10_12;
  TH1D *h13_12;
  TH1D *h10_13;
  TH1D *h13_13;

  int nbinsbx;
  int preveven;
  int prevevendt;
  int prevevencsc;
  int prevdig;
  std::string root_file_name;
  unsigned int bsec;
  unsigned int esec; 
  int prevbx;
  int prevbxdt;
  int prevbxcsc;
  unsigned long long orbrpc;
  unsigned long long orbdt;
  unsigned long long orbcsc;

  edm::InputTag m_GMTInputTag;
  const RPCDigiCollection *rpcdigi;
  std::vector<std::vector < int > > prevvec;
  std::vector<std::vector < int > > actvec;
  std::vector<std::vector < int > > trigprev;
  std::vector<std::vector < int > > trigact;



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

void TBXanal::beginRun(const edm::Run& r, const edm::EventSetup& eventSetup){

  //std::cout << "Begin the run" << std::endl;
  edm::Timestamp btime = r.beginTime();
  edm::Timestamp etime = r.endTime();

  bsec = btime.value() >> 32;
  unsigned int busec = 0xFFFFFFFF & btime.value() ;

  esec = etime.value() >> 32;
  unsigned int eusec = 0xFFFFFFFF & etime.value() ;
  
  //  //std::cout << "Begin time : " << busec << std::endl;
  //  //std::cout << "End time : " << eusec << std::endl;

}


TBXanal::TBXanal(const edm::ParameterSet& iConfig)

{
  //std::cout << "Constructor al pelo"  << std::endl;
  root_file_name = iConfig.getUntrackedParameter<std::string>("histoName");
  m_GMTInputTag = iConfig.getParameter<edm::InputTag>("GMTInputTag");
 //now do what ever initialization is needed
  nbinsbx = iConfig.getUntrackedParameter<int>("numbins");
  prevdig = -1;
}


TBXanal::~TBXanal()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
TBXanal::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace std;


   int bx = iEvent.bunchCrossing();
   int thisOrbit = iEvent.orbitNumber();
   double orbitTime = 0.03564*(double)thisOrbit +(double)((double)bx/100000.0);
   double tempo = (orbitTime/10000)*25;
   bool trigger = false;
   bool dig = false;
   bool peak2 = false;
   bool peak1 = false;
   bool peak3 = false;
   bool peak4 = false;
   bool peak5 = false;
   bool peak6 = false;
   bool peak7 = false;
   bool peak8 = false;
   bool peak9 = false;
   bool peak10 = false;
   bool peak11 = false;
   bool peak12 = false;
   bool peak13 = false;
   bool strips = false;

   std::cout << "Event: " << iEvent.id().event() << std::endl;
   /*   ////std::cout << "BX: " << bx << endl;
   cout << "Orbit Number : " << thisOrbit << endl;
   cout << "Orbit Time : " << (orbitTime/10000)*25 << endl;*/

   /*TimeValue_t time=iEvent.time().value(); 
   timeval *tmval=(timeval*)&time;
   neven = iEvent.id().event();
   nrun = iEvent.id().run();
   tempo = tmval->tv_usec;
   lumisection=iEvent.luminosityBlock();
   */

  
   //----------------------------- GLOBAL MUON TRIGGER ----------------------------------------
   edm::Handle<RPCDigiCollection> digis; 
   iEvent.getByLabel("muonRPCDigis",digis);
   edm::ESHandle<RPCGeometry> pDD;
   iSetup.get<MuonGeometryRecord>().get( pDD );
   int condis;
   int condisbx;
   
   for (RPCDigiCollection::DigiRangeIterator iter=digis->begin();iter!=digis->end(); iter++) {
     const RPCDetId& id = (*iter).first;
     const RPCRoll* roll = dynamic_cast<const RPCRoll* >( pDD->roll(id));
     const RPCDigiCollection::Range& range = (*iter).second;
     RPCGeomServ rpcsrv(id);
     std::string nameRoll = rpcsrv.name();

     std::vector<int> vec;
     condis=0;
     condisbx=0;
     for (RPCDigiCollection::const_iterator digiIt = range.first;digiIt!=range.second;++digiIt){
       condis++;
       if(digiIt->bx()==0){
	 condisbx++;
	 std::cout << "\t Chambers " << nameRoll << " RawId: " << id.rawId() << " strip: " << digiIt->strip() << " bx: " << digiIt->bx() << std::endl;
       }
       vec.clear();
       vec.push_back(id.rawId());
       vec.push_back(digiIt->strip());
       vec.push_back(digiIt->bx());
       actvec.push_back(vec);
       if(digiIt->bx()==0)
	 trigact.push_back(vec);

       //if((id.rawId()==637633773 and digiIt->strip()==23 and digiIt->bx()==0 ) or ( id.rawId() == 637633741 and digiIt->strip()==35 and digiIt->bx()==0) ){
       //	 strips = true;
       //	 std::cout << "Chambers " << nameRoll << std::endl;
	 //	 }
       //       if( iEvent.id().event()==2025364 or iEvent.id().event()==2025367 or iEvent.id().event()==2025368 or iEvent.id().event()==2025369 or iEvent.id().event()==2025370){
       //       std::cout << "analyzer comienza " << iEvent.id().event() << std::endl;
       //       std::cout << "Raw Id : " << id.rawId() << " Strip: " << digiIt->strip() << " Bunch Crossing: "  << digiIt->bx() << std::endl;
       // }
     } 
     h27->Fill(condis);
     h28->Fill(condisbx);
     h29->Fill(condis-condisbx);
   }

   if (prevdig==-1){
     prevdig = iEvent.id().event();
     prevvec = actvec;     
     trigprev = trigact;
   }
   else{
     /*     if (prevvec==actvec){
       std::cout << "analyzer comienza " << iEvent.id().event() << " evento previo: " << preveven << std::endl;
       h24->Fill(tempo);
       }*/
     if(prevvec.size() == actvec.size()){
       int cont=0;
       for(int i=0;i<prevvec.size();i++ ){
	 for (int j=0;j<actvec.size();j++ ){
	   if( prevvec[i][0]==actvec[j][0] and prevvec[i][1]==actvec[j][1] and prevvec[i][2]==actvec[j][2]){
	     cont++;
	     break;
	   }
	 }
       }
       if( cont == prevvec.size() ){
	 //	 std::cout << "Evento actual " << iEvent.id().event() << " evento previo: " << preveven << " Digis iguales" << std::endl;
	 h24->Fill(tempo);
	 dig = true;
	 h14->Fill(prevvec.size());
       }
     }
     if(trigprev.size()==trigact.size()){
       int cont =0;
       for(int i=0;i<trigprev.size();i++ ){
	 for(int j=0;j<trigact.size();j++ ){
	   //std::cout << "Condicion: " << trigprev[i][0] << " == " << trigact[j][0] << " y " <<  trigprev[i][1] << " == " << trigact[j][1] <<  std::endl;
	   if( trigprev[i][0]==trigact[j][0] and trigprev[i][1]==trigact[j][1]){
	     cont++;
	     std::cout << "\t\t Repeated Trigger Raw Id: " << trigact[j][0] << " strips " << trigprev[i][1] << endl;
	     h20->Fill(trigact[j][1]);
	     break;
	   }
	 }
       }
       if(cont==trigprev.size()){
	   std::cout << "\t\t\t Trigger actual " << iEvent.id().event() << " Trigger previo: " << preveven << " Triggers iguales" << std::endl;
	   std::cout << "\t\t\t\t Trigger previo: " << std::endl;
	   for(int i=0;i<trigprev.size();i++ ){
	     std::cout << trigprev[i][0] << " " << trigprev[i][1] << std::endl; 
	   }
	   std::cout << "\t\t\t\t Trigger actual: " << std::endl;
	   for(int i=0;i<trigact.size();i++ ){
	     std::cout << trigact[i][0] << " " << trigact[i][1] << std::endl; 
	   }
	   trigger = true;
	   h19->Fill(trigprev.size());
       }
     }     

     prevvec.clear();
     trigprev.clear();
     trigprev = trigact;
     prevvec = actvec;
     actvec.clear(); 
     trigact.clear();
   }

   edm::Handle<L1MuGMTReadoutCollection> gmtrc_handle; 
   iEvent.getByLabel(m_GMTInputTag,gmtrc_handle);
   L1MuGMTReadoutCollection const* gmtrc = gmtrc_handle.product();
   
   std::vector<L1MuGMTReadoutRecord> gmt_records = gmtrc->getRecords();
   std::vector<L1MuGMTReadoutRecord>::const_iterator igmtrr;
   
   for(igmtrr=gmt_records.begin(); igmtrr!=gmt_records.end(); igmtrr++) {
     
     std::vector<L1MuRegionalCand>::const_iterator iter1;
     std::vector<L1MuRegionalCand> rmc;
     
     rmc = igmtrr->getDTBXCands();
     int bxdtcan = 0;
     for(iter1=rmc.begin(); iter1!=rmc.end(); iter1++) {
       if ( !(*iter1).empty()) {
	 h3->Fill(tempo);
	 bxdtcan++;
	 std::cout << "\t\t\tDT Trigger Candidate number: " << bxdtcan << " eta Value " <<  (*iter1).etaValue() << " Phi value: " << (*iter1).phiValue();
	 std::cout << " ptValue: " << (*iter1).ptValue() << " charge: " << (*iter1).chargeValue();
	 std::cout << " quality: " << (*iter1).quality() << " bx: " << (*iter1).bx() << " orbit time: " << 3564*iEvent.orbitNumber() + bx;
	 std::cout << " time: " << tempo << std::endl;
	 if (prevbxdt == -1){
	   prevbxdt = bx;
	   orbdt = iEvent.orbitNumber();
	   prevevendt = iEvent.id().event();
	 }
	 else {
	   if(fabs(iEvent.id().event()-prevevendt) == 1){
	     h4->Fill(3564*(iEvent.orbitNumber()-orbdt)+bx-prevbxdt);
	   }
	   prevbxdt =bx;
	   prevevendt = iEvent.id().event();
	   orbdt = iEvent.orbitNumber();
	 }
	 
       }
     }
     
     // CSC muon candidates
     rmc = igmtrr->getCSCCands();
     int bxcsccan = 0;
     for(iter1=rmc.begin(); iter1!=rmc.end(); iter1++) {
       if ( !(*iter1).empty() ) {
	 h5->Fill(tempo);
	 bxcsccan++;
	 std::cout << "\t\t\tCSC Trigger Candidate number: " << bxcsccan << " eta Value " <<  (*iter1).etaValue() << " Phi value: " << (*iter1).phiValue();
	 std::cout << " ptValue: " << (*iter1).ptValue() << " charge: " << (*iter1).chargeValue();
	 std::cout << " quality: " << (*iter1).quality() << " bx: " << (*iter1).bx() << " orbit time: " << 3564*iEvent.orbitNumber() + bx;
	 std::cout << " time: " << tempo << std::endl;
	 if (prevbxcsc == -1){
	   prevbxcsc = bx;
	   orbcsc = iEvent.orbitNumber();
	   prevevencsc = iEvent.id().event();
	 }
	 else {
	   if(fabs(iEvent.id().event()-prevevencsc) == 1){
	     h6->Fill(3564*(iEvent.orbitNumber()-orbcsc)+bx-prevbxcsc);
	   }
	   prevbxcsc =bx;
	   prevevencsc = iEvent.id().event();
	   orbcsc = iEvent.orbitNumber();
	 }
       }
     }
     
     rmc = igmtrr->getBrlRPCCands();
     int bxcont = 0;
     for(iter1=rmc.begin(); iter1!=rmc.end(); iter1++) {
       if ( !(*iter1).empty() ) {
	 bxcont++;
	 h1->Fill(tempo);
	 h21->Fill((*iter1).phiValue());
	 h22->Fill((*iter1).etaValue());
	 h23->Fill((*iter1).phiValue(),(*iter1).etaValue());
	 std::cout << "\t\t\tRPC Barrel trigger candidate number: " << bxcont;
	 std::cout << "Phi: " << (*iter1).phiValue() << " Eta: " << (*iter1).etaValue();
	 std::cout << " ptValue: " << (*iter1).ptValue() << " charge: " << (*iter1).chargeValue();
	 std::cout << " quality: " << (*iter1).quality() << " bx: " << (*iter1).bx() << " orbit time: " << 3564*iEvent.orbitNumber() + bx;
	 std::cout << " time: " << tempo << std::endl;
	 if (prevbx == -1){
	   prevbx = bx;
	   orbrpc = iEvent.orbitNumber();
	   preveven = iEvent.id().event();
	 }
	 else {
	   double dif;
	   if(fabs(iEvent.id().event()-preveven) == 1){
	     dif=3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx;
	     h2->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	     h9->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	     if((*iter1).bx()==0)
	       h15->Fill(dif);
	     if((*iter1).bx()==1)
	       h16->Fill(dif);
	     if((*iter1).bx()==2)
	       h17->Fill(dif);
	     if((*iter1).bx()==3)
	       h18->Fill(dif);

	     if((*iter1).phiValue() > 0 and (*iter1).phiValue() <= 0.2 and (*iter1).etaValue()>=0.6 and (*iter1).etaValue() <= 0.8)
	       peak1 = true;
	     if((*iter1).etaValue() >= -0.75 and (*iter1).etaValue() <= 0.62 and (*iter1).phiValue() >= 0.2 and (*iter1).phiValue() <= 0.5)
	       peak2 = true;
	     if((*iter1).phiValue() >= 2.2 and (*iter1).phiValue() <= 2.5 and (*iter1).etaValue()>=0.5 and (*iter1).etaValue() <= 0.7)
	       peak3 = true;
	     if((*iter1).phiValue() >= 1 and (*iter1).phiValue() <= 1.2 and (*iter1).etaValue()>=0 and (*iter1).etaValue() <= 0.1)
	       peak4 = true;
	     if((*iter1).phiValue() >= 1.5 and (*iter1).phiValue() <= 1.8 and (*iter1).etaValue() >= 0 and (*iter1).etaValue() <= 0.1)
	       peak5 = true;
	     if((*iter1).phiValue() >= 2 and (*iter1).phiValue() <= 2.2 and (*iter1).etaValue() >= 0 and (*iter1).etaValue() <= 0.1)
	       peak6 = true;
	     if((*iter1).phiValue() >= 1.6 and (*iter1).phiValue() <= 1.8 and (*iter1).etaValue()>= -0.4 and (*iter1).etaValue() <= -0.3)
	       peak7 = true;
	     if((*iter1).phiValue() >= 1.5  and (*iter1).phiValue() <= 1.8 and (*iter1).etaValue()>= -0.75 and (*iter1).etaValue() <= -0.6)
	       peak8 = true;
	     if((*iter1).phiValue() >= 2 and (*iter1).phiValue() <= 2.2 and (*iter1).etaValue() >= -0.75 and (*iter1).etaValue() <= -0.6)
	       peak9 = true;
	     if((*iter1).phiValue() >= 2.3 and (*iter1).phiValue() <= 2.9 and (*iter1).etaValue() >= -0.75 and (*iter1).etaValue() <= -0.6)
	       peak10 = true;
	     if((*iter1).phiValue() >= 3 and (*iter1).phiValue() <= 3.3 and (*iter1).etaValue() >= -0.6 and (*iter1).etaValue() <= -0.45)
	       peak11 = true;
	     if((*iter1).phiValue() >= 4.3 and (*iter1).phiValue() <= 4.6 and (*iter1).etaValue() >= 0.6 and (*iter1).etaValue() <= 0.8 )
	       peak12 = true;
	     if((*iter1).phiValue() >= 4.6 and (*iter1).phiValue() <= 4.9 and (*iter1).etaValue() >= 0 and (*iter1).etaValue() <= 0.1)
	       peak13 = true;
	   }
	   if(trigger){
	     h7->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h11->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(dig){
	     h8->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h12->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }

	   if(peak1){
	     h10->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak2){
	     h10_2->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_2->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak3){
	     h10_3->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_3->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak4){
	     h10_4->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_4->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak5){
	     h10_5->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_5->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak6){
	     h10_6->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_6->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak7){
	     h10_7->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_7->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak8){
	     h10_8->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_8->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak9){
	     h10_9->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_9->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak10){
	     h10_10->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_10->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak11){
	     h10_11->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_11->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak12){
	     h10_12->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_12->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak13){
	     h10_13->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_13->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }

	   /*	   if(strips){
	     h25->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h26->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	     }*/
	   prevbx =bx;
	   preveven = iEvent.id().event();
	   orbrpc = iEvent.orbitNumber();
	 }
       }
     }
     
     rmc = igmtrr->getFwdRPCCands();
     for(iter1=rmc.begin(); iter1!=rmc.end(); iter1++) {
       if ( !(*iter1).empty() ) {
	 // irpcf++;
	 h1->Fill(tempo);
	 std::cout << "Consecutive trigger Event id for Endcap: " << iEvent.id().event() << std::endl;
	 std::cout << "Phi: " << (*iter1).phiValue() << " Eta: " << (*iter1).etaValue();
	 std::cout << " ptValue: " << (*iter1).ptValue() << " charge: " << (*iter1).chargeValue();
	 std::cout << " quality: " << (*iter1).quality() << " bx: " << (*iter1).bx() << " orbit time: " << 3564*iEvent.orbitNumber() + bx;
	 std::cout << " time: " << tempo << std::endl;
	 if (prevbx == -1){
	   prevbx = bx;
	   orbrpc = iEvent.orbitNumber();
	   preveven = iEvent.id().event();
	   
	 }
	 else {
	   double dif;
	   if(fabs(iEvent.id().event()-preveven) == 1){
	     dif=3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx;
	     h2->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	     h9->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	     if((*iter1).bx()==0)
	       h15->Fill(dif);
	     if((*iter1).bx()==1)
	       h16->Fill(dif);
	     if((*iter1).bx()==2)
	       h17->Fill(dif);
	     if((*iter1).bx()==3)
	       h18->Fill(dif);
	     if((*iter1).phiValue() > 0 and (*iter1).phiValue() <= 0.2 and (*iter1).etaValue()>=0.6 and (*iter1).etaValue() <= 0.8)
	       peak1 = true;
	     if((*iter1).etaValue() >= -0.75 and (*iter1).etaValue() <= 0.62 and (*iter1).phiValue() >= 0.2 and (*iter1).phiValue() <= 0.5)
	       peak2 = true;
	     if((*iter1).phiValue() >= 2.2 and (*iter1).phiValue() <= 2.5 and (*iter1).etaValue()>=0.5 and (*iter1).etaValue() <= 0.7)
	       peak3 = true;
	     if((*iter1).phiValue() >= 1 and (*iter1).phiValue() <= 1.2 and (*iter1).etaValue()>=0 and (*iter1).etaValue() <= 0.1)
	       peak4 = true;
	     if((*iter1).phiValue() >= 1.5 and (*iter1).phiValue() <= 1.8 and (*iter1).etaValue() >= 0 and (*iter1).etaValue() <= 0.1)
	       peak5 = true;
	     if((*iter1).phiValue() >= 2 and (*iter1).phiValue() <= 2.2 and (*iter1).etaValue() >= 0 and (*iter1).etaValue() <= 0.1)
	       peak6 = true;
	     if((*iter1).phiValue() >= 1.6 and (*iter1).phiValue() <= 1.8 and (*iter1).etaValue()>= -0.4 and (*iter1).etaValue() <= -0.3)
	       peak7 = true;
	     if((*iter1).phiValue() >= 1.5  and (*iter1).phiValue() <= 1.8 and (*iter1).etaValue()>= -0.75 and (*iter1).etaValue() <= -0.6)
	       peak8 = true;
	     if((*iter1).phiValue() >= 2 and (*iter1).phiValue() <= 2.2 and (*iter1).etaValue() >= -0.75 and (*iter1).etaValue() <= -0.6)
	       peak9 = true;
	     if((*iter1).phiValue() >= 2.3 and (*iter1).phiValue() <= 2.9 and (*iter1).etaValue() >= -0.75 and (*iter1).etaValue() <= -0.6)
	       peak10 = true;
	     if((*iter1).phiValue() >= 3 and (*iter1).phiValue() <= 3.3 and (*iter1).etaValue() >= -0.6 and (*iter1).etaValue() <= -0.45)
	       peak11 = true;
	     if((*iter1).phiValue() >= 4.3 and (*iter1).phiValue() <= 4.6 and (*iter1).etaValue() >= 0.6 and (*iter1).etaValue() <= 0.8 )
	       peak12 = true;
	     if((*iter1).phiValue() >= 4.6 and (*iter1).phiValue() <= 4.9 and (*iter1).etaValue() >= 0 and (*iter1).etaValue() <= 0.1)
	       peak13 = true;

	     h21->Fill((*iter1).phiValue());
	     h22->Fill((*iter1).etaValue());
	     h23->Fill((*iter1).phiValue(),(*iter1).etaValue());
	    // std::cout << "Event id: " << iEvent.id().event() << std::endl;
	    // std::cout << "Phi: " << (*iter1).phiValue() << " Eta: " << (*iter1).etaValue();
	    // std::cout << " ptValue: " << (*iter1).ptValue() << " charge: " << (*iter1).chargeValue();
	    // std::cout << " quality: " << (*iter1).quality() << " bx: " << (*iter1).bx();
	    // std::cout << " time: " << tempo << std::endl;
	   
	     //h2->Fill(fabs(bx-prevbx));
	   }
	   if(trigger){
	     h7->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else
	     h11->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   if(dig){
	     h8->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else
	     h12->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   if(peak1){
	     h10->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak2){
	     h10_2->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_2->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak3){
	     h10_3->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_3->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak4){
	     h10_4->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_4->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak5){
	     h10_5->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_5->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak6){
	     h10_6->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_6->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak7){
	     h10_7->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_7->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak8){
	     h10_8->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_8->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak9){
	     h10_9->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_9->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak10){
	     h10_10->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_10->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak11){
	     h10_11->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_11->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak12){
	     h10_12->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_12->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   if(peak13){
	     h10_13->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   else{
	     h13_13->Fill(3564*(iEvent.orbitNumber()-orbrpc)+bx-prevbx);
	   }
	   prevbx =bx;
	   preveven = iEvent.id().event();
	   orbrpc = iEvent.orbitNumber();
	 }
       }
     }
   }

}





// ------------ method called once each job just before starting event loop  ------------
void 
TBXanal::beginJob(const edm::EventSetup&)
{
  ////std::cout << "begin job" << std::endl;
  hfile = new TFile(root_file_name.c_str(),"RECREATE");
  //  h1 = new TH1F("OrbitTime","Orbit Time",7200,0,7200);
  h1 = new TH1F("OrbitTime","Orbit Time",nbinsbx,0,1);
  h2 = new TH1D("BunchXDif","Bx Difference",nbinsbx,0,1);
  h9 = new TH1D("BunchXDifzoom","Bx Difference",nbinsbx,0,nbinsbx);
  h7 = new TH1D("BunchXDifsametrig","Bx Difference for events with same trigger",nbinsbx,0,nbinsbx);
  h8 = new TH1D("BunchXDifsamedigis","Bx Difference for events with same digis",nbinsbx,0,nbinsbx);
  h10 = new TH1D("BunchXDifsameangular","Bx Difference for events with geometrical peak",nbinsbx,0,nbinsbx);
  h11 = new TH1D("BunchXDifsametrigfalse","Bx Difference for events with same trigger false",nbinsbx,0,nbinsbx);
  h12 = new TH1D("BunchXDifsamedigisfalse","Bx Difference for events with same digis false",nbinsbx,0,nbinsbx);
  h13 = new TH1D("BunchXDifsameangularfalse","Bx Difference for events with geometrical peak false",nbinsbx,0,nbinsbx);
  h15 = new TH1D("BunchXDifBx0","Bx Difference bx 0",nbinsbx,0,1);
  h16 = new TH1D("BunchXDifBx1","Bx Difference bx 1",nbinsbx,0,1);
  h17 = new TH1D("BunchXDifBx2","Bx Difference bx 2",nbinsbx,0,1);
  h18 = new TH1D("BunchXDifBx3","Bx Difference bx 3",nbinsbx,0,1);
  h14 = new TH1I("NumberRepeatedDig","Number of repeated digis in exact consecutive events",101,0,100);
  h19 = new TH1I("NumberRepeatedtrig","Number of repeated digis in exact consecutive trigger events bx=0",101,0,100);
  h20 = new TH1I("StripsIncludedinRepeatedtrig","strips fired for repeated trigger in consecutive events",100,0,100);
  h21 = new TH1D("Phidistribution","Phi distribution for trigger cand",70,0,7);
  h22 = new TH1D("Etadistribution","Eta distribution for trigger cand",50,-2,2);
  h23 = new TH2D("PhiEtaDistribution","Phi vs Eta ",70,0,7,50,-2,2);
  h24 = new TH1D("OrbitTimerepeateddigi","Orbit Time for identical digis",nbinsbx,0,1);
  //  h35B = new TH1F("OrbitTimedt","Orbit Time dt",7200,0,7200);
  h3 = new TH1F("OrbitTimedt","Orbit Time dt",nbinsbx,0,1);
  h4 = new TH1D("BunchXDifdt","Bx Difference dt",nbinsbx,0,1);
  //  h5 = new TH1F("OrbitTimecsc","Orbit Time csc",7200,0,7200);
  h5 = new TH1F("OrbitTimecsc","Orbit Time csc",nbinsbx,0,1);
  h6 = new TH1D("BunchXDifcsc","Bx Difference csc",nbinsbx,0,1);
  //  h25 = new TH1D("BunchXDifstrips","Bx Difference strips",nbinsbx,0,1);
  //  h26 = new TH1D("BunchXDifstripsfalse","Bx Difference strips false",nbinsbx,0,1);
  h27 = new TH1I("DistNumberOfdigisPerChamber","Distribution of the number of digis per chamber distribution",101,0,100);
  h28 = new TH1I("DistNumberOfdigisPerChamberbx0","Distribution of the number of digis per chamber distribution bx =0",101,0,100);
  h29 = new TH1I("DistNumberOfdigisPerChamberotherbx","Distribution of the number of digis per chamber distribution bx !=0",101,0,100);
  h10_2 = new TH1D("BunchXDifpeak2","Bx Difference for events with geometrical peak",nbinsbx,0,nbinsbx);
  h13_2 = new TH1D("BunchXDifpick2false","Bx Difference for events with geometrical peak false",nbinsbx,0,nbinsbx);
  h10_3 = new TH1D("BunchXDifpeak3","Bx Difference for events with geometrical peak",nbinsbx,0,nbinsbx);
  h13_3 = new TH1D("BunchXDifpeak3false","Bx Difference for events with geometrical peak false",nbinsbx,0,nbinsbx);
  h10_4 = new TH1D("BunchXDifpeak4","Bx Difference for events with geometrical peak",nbinsbx,0,nbinsbx);
  h13_4 = new TH1D("BunchXDifpeak4false","Bx Difference for events with geometrical peak false",nbinsbx,0,nbinsbx);
  h10_5 = new TH1D("BunchXDifpeak5","Bx Difference for events with geometrical peak",nbinsbx,0,nbinsbx);
  h13_5 = new TH1D("BunchXDifpeak5false","Bx Difference for events with geometrical peak false",nbinsbx,0,nbinsbx);
  h10_6 = new TH1D("BunchXDifpeak6","Bx Difference for events with geometrical peak",nbinsbx,0,nbinsbx);
  h13_6 = new TH1D("BunchXDifpeak6false","Bx Difference for events with geometrical peak false",nbinsbx,0,nbinsbx);
  h10_7 = new TH1D("BunchXDifpeak7","Bx Difference for events with geometrical peak",nbinsbx,0,nbinsbx);
  h13_7 = new TH1D("BunchXDifpeak7false","Bx Difference for events with geometrical peak false",nbinsbx,0,nbinsbx);
  h10_8 = new TH1D("BunchXDifpeak8","Bx Difference for events with geometrical peak",nbinsbx,0,nbinsbx);
  h13_8 = new TH1D("BunchXDifpeak8false","Bx Difference for events with geometrical peak false",nbinsbx,0,nbinsbx);
  h10_9 = new TH1D("BunchXDifpeak9","Bx Difference for events with geometrical peak",nbinsbx,0,nbinsbx);
  h13_9 = new TH1D("BunchXDifpeak9false","Bx Difference for events with geometrical peak false",nbinsbx,0,nbinsbx);
  h10_10 = new TH1D("BunchXDifpeak10","Bx Difference for events with geometrical peak",nbinsbx,0,nbinsbx);
  h13_10 = new TH1D("BunchXDifpeak10false","Bx Difference for events with geometrical peak false",nbinsbx,0,nbinsbx);
  h10_11 = new TH1D("BunchXDifpeak11","Bx Difference for events with geometrical peak",nbinsbx,0,nbinsbx);
  h13_11 = new TH1D("BunchXDifpeak11false","Bx Difference for events with geometrical peak false",nbinsbx,0,nbinsbx);
  h10_12 = new TH1D("BunchXDifpeak12","Bx Difference for events with geometrical peak",nbinsbx,0,nbinsbx);
  h13_12 = new TH1D("BunchXDifpeak12false","Bx Difference for events with geometrical peak false",nbinsbx,0,nbinsbx);
  h10_13 = new TH1D("BunchXDifpeak13","Bx Difference for events with geometrical peak",nbinsbx,0,nbinsbx);
  h13_13 = new TH1D("BunchXDifpeak13false","Bx Difference for events with geometrical peak false",nbinsbx,0,nbinsbx);

  ////std::cout << "booking" << std::endl;

  h1->SetBit(TH1::kCanRebin);
  h2->SetBit(TH1::kCanRebin);
  //  h7->SetBit(TH1::kCanRebin);
  h3->SetBit(TH1::kCanRebin);
  h4->SetBit(TH1::kCanRebin);
  h5->SetBit(TH1::kCanRebin);
  h6->SetBit(TH1::kCanRebin);
  //  h8->SetBit(TH1::kCanRebin);
  //  h10->SetBit(TH1::kCanRebin);
  h15->SetBit(TH1::kCanRebin);
  h16->SetBit(TH1::kCanRebin);
  //  h11->SetBit(TH1::kCanRebin);
  //  h12->SetBit(TH1::kCanRebin);
  //  h13->SetBit(TH1::kCanRebin);
  h17->SetBit(TH1::kCanRebin);
  //  h19->SetBit(TH1::kCanRebin);
  //  h14->SetBit(TH1::kCanRebin);
  //  h25->SetBit(TH1::kCanRebin);
  //  h26->SetBit(TH1::kCanRebin);

  ////std::cout << "rebining" << std::endl;
  prevbx=-1;
  prevbxdt =-1;
  prevbxcsc =-1;
  ////std::cout<<"finishing" << std::endl;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
TBXanal::endJob() {

  hfile->cd();
  h1->Write();
  h2->Write();
  h3->Write();
  h4->Write();
  h5->Write();
  h6->Write();
  h7->Write();
  h9->Write();
  h8->Write();
  h10->Write();
  h15->Write();
  h16->Write();
  h11->Write();
  h12->Write();
  h13->Write();
  h17->Write();
  h18->Write();
  h20->Write();
  h21->Write();
  h22->Write();
  h23->Write();
  h14->Write();
  h19->Write();
  h24->Write();
  //  h25->Write();
  //  h26->Write();
  h27->Write();
  h28->Write();
  h29->Write();
  h10_2->Write();
  h13_2->Write();
  h10_3->Write();
  h13_3->Write();
  h10_4->Write();
  h13_4->Write();
  h10_5->Write();
  h13_5->Write();
  h10_6->Write();
  h13_6->Write();
  h10_7->Write();
  h13_7->Write();
  h10_8->Write();
  h13_8->Write();
  h10_9->Write();
  h13_9->Write();
  h10_10->Write();
  h13_10->Write();
  h10_11->Write();
  h13_11->Write();
  h10_12->Write();
  h13_12->Write();
  h10_13->Write();
  h13_13->Write();
  hfile->Close();
}

//define this as a plug-in
DEFINE_FWK_MODULE(TBXanal);
