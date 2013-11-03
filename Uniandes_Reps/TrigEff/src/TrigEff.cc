// -*- C++ -*-
//
// Package:    TrigEff
// Class:      TrigEff
// 
/**\class TrigEff TrigEff.cc UserCode/TrigEff/src/TrigEff.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Alberto Andres Ocampo Rios
//         Created:  Wed Apr  8 09:12:32 CEST 2009
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

#include "math.h"
//
// class decleration
//

class TrigEff : public edm::EDAnalyzer {
public:
  explicit TrigEff(const edm::ParameterSet&);
  ~TrigEff();


private:
  virtual void beginJob(const edm::EventSetup&) ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  TFile *hfile;
  TH1F *hdtoccphi;
  TH1F *hrpcdtexpphi;
  TH1F *hdtocceta;
  TH1F *hrpcdtexpeta;
  TH1F *hrpcphi;
  TH1F *hrpceta;
  TH1F *hdtphi;
  TH1F *hdteta;
  TH2F *hoccphieeta;
  TH2F *hexpphieeta;
  TH1F *hdr;

  edm::InputTag m_GMTInputTag;
  std::string root_file_name;
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
TrigEff::TrigEff(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
  root_file_name = iConfig.getUntrackedParameter<std::string>("histoName");
  m_GMTInputTag = iConfig.getParameter<edm::InputTag>("GMTInputTag");
}


TrigEff::~TrigEff()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
TrigEff::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace std;

   edm::Handle< std::vector <L1MuRegionalCand> > rpc_handle;
   iEvent.getByLabel("gtDigis","RPCb",rpc_handle);
   std::vector<L1MuRegionalCand>::const_iterator rpciter;
   edm::Handle< std::vector <L1MuRegionalCand> > dt_handle;
   iEvent.getByLabel("gtDigis","DT",dt_handle);
   std::vector<L1MuRegionalCand>::const_iterator dtiter;
   float difphi;
   float difeta;
   int difbx;
   float deltar;
   int contcoin;
   float phiaux=0;
   float etaaux=0;
   int contdt=0;
   int contrpc=0;
   int dtcont = 0;
   for(dtiter=dt_handle->begin();dtiter!=dt_handle->end();dtiter++){
     if ( !(*dtiter).empty() ){
       dtcont++;
       hdtphi->Fill((*dtiter).phiValue());
       hdteta->Fill((*dtiter).etaValue());
     }
   }
   for(rpciter=rpc_handle->begin();rpciter!=rpc_handle->end();rpciter++){
     if ( !(*rpciter).empty() ){
       hrpcphi->Fill((*rpciter).phiValue());
       hrpceta->Fill((*rpciter).phiValue());
     }
   }


   edm::Handle<L1MuGMTReadoutCollection> gmtrc_handle; 
   iEvent.getByLabel(m_GMTInputTag,gmtrc_handle);
   L1MuGMTReadoutCollection const* gmtrc = gmtrc_handle.product();
   
   std::vector<L1MuGMTReadoutRecord> gmt_records = gmtrc->getRecords();
   std::vector<L1MuGMTReadoutRecord>::const_iterator igmtrr;
   
   for(igmtrr=gmt_records.begin(); igmtrr!=gmt_records.end(); igmtrr++) {
     std::vector<L1MuRegionalCand> rmc;

     std::vector<L1MuRegionalCand> rmc1;
     std::vector<L1MuRegionalCand>::const_iterator iter1;
     std::vector<L1MuRegionalCand>::const_iterator iter2;
     rmc = igmtrr->getDTBXCands();
     rmc1 = igmtrr->getBrlRPCCands();
     for(iter1=rmc.begin(); iter1!=rmc.end(); iter1++) {
       if(!(*iter1).empty() and dtcont==1){
	 std::cout << "DT Phi: " << (*iter1).phiValue() << " DT eta: " << (*iter1).etaValue() << " DT bx: " << (*iter1).bx() << std::endl; 
	 contcoin=0;
	 for(iter2=rmc1.begin(); iter2!=rmc1.end(); iter2++) {
	   if ( !(*iter2).empty() ) {
	     std::cout << "\tRPC Phi: " << (*iter2).phiValue() << "RPC Eta: "<< (*iter2).etaValue() << " RPC bx " << (*iter2).bx() << std::endl;
	     difphi=(*iter1).phiValue()-(*iter2).phiValue();
	     difeta=(*iter1).etaValue()-(*iter2).etaValue();
	     difbx=(*iter1).bx()-(*iter2).bx();
	     deltar=sqrt(difphi*difphi+difeta*difeta);
	     hdr->Fill(deltar);
	     if(deltar<=0.5 and fabs(difbx)<=1){
	       contcoin++;
	       phiaux=(*iter2).phiValue();
	       etaaux=(*iter2).etaValue();
	     }
	   }
	 }
	 if(contcoin==1){
	   std::cout << "\t\tEvento eficiente: " << endl;
	   std::cout << "\t\tRPC Phi: " << phiaux << "RPC Eta: "<< etaaux << std::endl;
	   contrpc++;
	   hrpcdtexpphi->Fill((*iter1).phiValue());
	   hrpcdtexpeta->Fill((*iter1).etaValue());
	   hexpphieeta->Fill((*iter1).phiValue(),(*iter1).etaValue());
	 }
	 contdt++;
	 hdtoccphi->Fill((*iter1).phiValue());
	 hdtocceta->Fill((*iter1).etaValue());
	 hoccphieeta->Fill((*iter1).phiValue(),(*iter1).etaValue());
       }
     }
   }
   //   std::vector <L1MuRegionalCand> rpcrc_records = rpcrc_handle->getRecords();
   /*   for(dtiter=dt_handle->begin();dtiter!=dt_handle->end();dtiter++){
     if ( !(*dtiter).empty() and dtcont==1){
       //       hl1em->Fill(tempo);
	 std::cout << "DT Phi: " << (*dtiter).phiValue() << " DT eta: " << (*dtiter).etaValue() << " DT bx: " << (*dtiter).bx() << std::endl; 
	 contcoin=0;
       for(rpciter=rpc_handle->begin();rpciter!=rpc_handle->end();rpciter++){
	 if ( !(*rpciter).empty() ){
	   //hl1em->Fill(tempo);
	   std::cout << "\tRPC Phi: " << (*rpciter).phiValue() << "RPC Eta: "<< (*rpciter).etaValue() << " RPC bx " << (*rpciter).bx() << std::endl;
	   difphi=(*dtiter).phiValue()-(*rpciter).phiValue();
	   difeta=(*dtiter).etaValue()-(*rpciter).etaValue();
	   difbx=(*dtiter).bx()-(*rpciter).bx();
	   deltar=sqrt(difphi*difphi+difeta*difeta);
	   hdr->Fill(deltar);
	   if(deltar<=0.5 and fabs(difbx)<=1){
	     contcoin++;
	     phiaux=(*rpciter).phiValue();
	     etaaux=(*rpciter).etaValue();
	   } 
	 }
       }
       //if(contcoin<2){
       if(contcoin==1){
	 std::cout << "\t\tEvento eficiente: " << endl;
	 std::cout << "\t\tRPC Phi: " << phiaux << "RPC Eta: "<< etaaux << std::endl;
	 contrpc++;
	 hrpcdtexpphi->Fill((*dtiter).phiValue());
	 hrpcdtexpeta->Fill((*dtiter).etaValue());
	 hexpphieeta->Fill((*dtiter).phiValue(),(*dtiter).etaValue());
       }
       contdt++;
       hdtoccphi->Fill((*dtiter).phiValue());
       hdtocceta->Fill((*dtiter).etaValue());
       hoccphieeta->Fill((*dtiter).phiValue(),(*dtiter).etaValue());
	 //       }
     }
     }*/
   cout << "\t\t\t Dt tiene: " << contdt << " RPC tiene: " << contrpc << endl;
   //   std::vector <L1MuRegionalCand> rpcrc_records = rpcrc_handle->getRecords();


}


// ------------ method called once each job just before starting event loop  ------------
void 
TrigEff::beginJob(const edm::EventSetup&)
{
  hfile = new TFile(root_file_name.c_str(),"RECREATE");
  hdtoccphi = new TH1F("DTOccPhi","Occupancy for DT in phi",70,0,7);
  hrpcdtexpphi = new TH1F("RPCDTExpeOccPhi","RPC Expected from DT in phi",70,0,7);
  hdtocceta = new TH1F("DTOccEta","Occupancy for DT in eta ",20,-1.5,1.5);
  hrpcdtexpeta = new TH1F("RPCDTExpeOccEta","RPC Expected Occupancy from DT in eta ",20,-1.5,1.5);
  hoccphieeta = new TH2F("DTOccPhiEta","DT Occupancy phi and eta",70,0,7,20,-1.5,1.5);
  hexpphieeta = new TH2F("DTRPCExpPhiEta","DT RPC expectancy phi and eta",70,0,7,20,-1.5,1.5);
  hrpcphi = new TH1F("RPCPhi","Occupancy RPC in phi",70,0,7);
  hrpceta = new TH1F("RPCEta","Occupancy RPC in eta",20,-1.5,3);
  hdtphi = new TH1F("DTPhi","Occupancy DT in phi",70,0,7);
  hdteta = new TH1F("DTEta","Occupancy DT in eta",20,-1.5,1.5);
  hdr = new TH1F("Deltar","Delta R",100,0,4);
}

// ------------ method called once each job just after ending the event loop  ------------
void 
TrigEff::endJob() {
  hfile->cd();
  hdtoccphi->Write();
  hrpcdtexpphi->Write();
  hdtocceta->Write();
  hrpcdtexpeta->Write();
  hoccphieeta->Write();
  hexpphieeta->Write();
  hrpcphi->Write();
  hrpceta->Write();
  hdtphi->Write();
  hdteta->Write();
  hdr->Write();
  hfile->Close();
}

//define this as a plug-in
DEFINE_FWK_MODULE(TrigEff);
