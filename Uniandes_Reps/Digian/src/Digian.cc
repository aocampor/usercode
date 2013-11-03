// -*- C++ -*-
//
// Package:    Digian
// Class:      Digian
// 
/**\class Digian Digian.cc UserCode/Digian/src/Digian.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  pts/61
//         Created:  Fri Feb 29 11:13:15 CET 2008
// $Id$
//
//


// system include files
#include <memory>
#include <TRandom.h> 
//#include <unistd.h>
#include <string>
#include "DQM/RPCMonitorDigi/interface/RPCMonitorDigi.h"


// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

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
#include "Geometry/RPCGeometry/interface/RPCGeometry.h"
#include "Geometry/Records/interface/MuonGeometryRecord.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"
#include "Geometry/RPCGeometry/interface/RPCGeomServ.h"

#include "TROOT.h"
#include "TMath.h"

#include "TFile.h"
#include "TH1F.h"

//
// class decleration
//

class Digian : public edm::EDAnalyzer {
public:
  explicit Digian(const edm::ParameterSet&);
  ~Digian();
  
  
private:
  virtual void beginJob(const edm::EventSetup&) ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  int numberless;
  TFile* theFile;
  TH1F *hbx;
  TH1F *hbadbx;
  TH1F *hdigperev;
  TH1F *digidis; 
  TH1F *numclust;
  TH1F *tamclust;
  int numclus;
  int tamclus;
  int iter2;
  int bin2;
  int iter;
  int sumdi;
  int bin;



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
Digian::Digian(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
	numberless=0;
}


Digian::~Digian()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
Digian::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace std;

  
  /// DIGI     
   edm::Handle<RPCDigiCollection> rpcdigis;
   iEvent.getByType(rpcdigis);
   
  /// RecHits
   edm::Handle<RPCRecHitCollection> rpcHits;
   iEvent.getByType(rpcHits);
  
   int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,c9=0,c0=0,c10=0;
   RPCDigiCollection::DigiRangeIterator collectionItr;
   int numberdigis = 0;
   //   cout << "Event number: " << iEvent.id() << endl;
   int countdi=0;
   for(collectionItr=rpcdigis->begin(); collectionItr!=rpcdigis->end(); ++collectionItr){
     numberdigis++;
     RPCDigiCollection::const_iterator digiItr; 
     for (digiItr = ((*collectionItr ).second).first;digiItr!=((*collectionItr).second).second; ++digiItr){
       //       cout << "Strip: " << (*digiItr).strip() << "bx: " << (*digiItr).bx() << endl;
       if((*digiItr).bx()==-5){c0++;}
       else 
	 if((*digiItr).bx()==-4){c1++;}
	 else
	   if((*digiItr).bx()==-3){c2++;}
	   else
	     if((*digiItr).bx()==-2){c3++;}
	     else
	       if((*digiItr).bx()==-1){c4++;}
	       else
		 if((*digiItr).bx()==0){c5++;}
		 else
		   if((*digiItr).bx()==1){c6++;}
		   else
		     if((*digiItr).bx()==2){c7++;}
		     else
		       if((*digiItr).bx()==3){c8++;}
		       else
			 if((*digiItr).bx()==4){c9++;}
			 else
			   if((*digiItr).bx()==5){c10++;}
     }   
     if(c0!=0){hbx->Fill(c0);}
     if(c1!=0){hbx->Fill(c1);}
     if(c2!=0){hbx->Fill(c2);}
     if(c3!=0){hbx->Fill(c3);}
     if(c4!=0){hbx->Fill(c4);}
     if(c5!=0){hbx->Fill(c5);}
     if(c6!=0){hbx->Fill(c6);}
     if(c7!=0){hbx->Fill(c7);}
     if(c8!=0){hbx->Fill(c8);}
     if(c9!=0){hbx->Fill(c9);}
     if(c10!=0){hbx->Fill(c10);}
     RPCDetId detId =(*collectionItr).first; 
    
     //    int region=detId.region();
     //    int ring=detId.ring();
     //cout << "Hit description: " << endl;
     //    std::string regionName;
     //    if(detId.region() ==  0) {
     //      regionName="Barrel";
     //cout << "barrel" << endl;
     //    }//else{
     
     //if(detId.region() == -1) {regionName="Encap-"; cout << "Endcap -" << endl;}
     if(detId.region() ==  1) {
       //  regionName="Encap+"; 
       countdi++;
       if(countdi==2){
	 //cout << iEvent.id() << "Endcap +" << endl; 
	 }
     }
     //     cout << iEvent.time().value() << endl;
     //if (detId.region()==0) {cout << "Wheel" << endl;}
     //else {cout << "Disk" << endl;}
     //cout << "The wheel is the number " << detId.ring() << " the sector is " << detId.sector() << endl;
     
   }
   if(numberdigis > 14 ) cout << "This event has a big number of digis:  " << iEvent.id() << " With " << numberdigis << endl;
   
   hdigperev->Fill(numberdigis);
   sumdi = sumdi+numberdigis;
   iter++;
   if(iter==10){
     iter=0;
     bin++;
     digidis->Fill(bin,sumdi);
     if(sumdi>100){
       //  cout << "This event has a big occupancy." << endl;
	 } 
     sumdi=0;
   }
   
   //   cout << "There are " << numberdigis << " number of digis" << endl;
   if (numberdigis>70){
     //     cout << "Giant event with " << numberdigis << " digis " << iEvent.id() << endl;
   }
   if (numberdigis <= 3){
     //     cout << "Event bad number: " << iEvent.id() << endl;
     //     cout << "The bad event has: " << numberdigis << endl;
     numberless++;
     for(collectionItr=rpcdigis->begin(); collectionItr!=rpcdigis->end(); ++collectionItr){
       //cout << "Bx : " << (*collectionItr).bx() << " strip : " << (*collectionItr).strip() << endl;
       RPCDigiCollection::const_iterator digiItr; 
       for (digiItr = ((*collectionItr ).second).first;digiItr!=((*collectionItr).second).second; ++digiItr){
	 //cout << "Strip: " << (*digiItr).strip() << "bx: " << (*digiItr).bx() << endl;
       }     
       if(c0!=0){hbadbx->Fill(c0);}
       if(c1!=0){hbadbx->Fill(c1);}
       if(c2!=0){hbadbx->Fill(c2);}
       if(c3!=0){hbadbx->Fill(c3);}	
       if(c4!=0){hbadbx->Fill(c4);}
       if(c5!=0){hbadbx->Fill(c5);}
       if(c6!=0){hbadbx->Fill(c6);}
       if(c7!=0){hbadbx->Fill(c7);}
       if(c8!=0){hbadbx->Fill(c8);}
       if(c9!=0){hbadbx->Fill(c9);}
       if(c10!=0){hbadbx->Fill(c10);}
       
     }
   }
   numberdigis=0;
   for(collectionItr=rpcdigis->begin(); collectionItr!=rpcdigis->end(); ++collectionItr){
     RPCDetId detId=(*collectionItr).first;
     //get the RecHits associated to the roll
     typedef pair<RPCRecHitCollection::const_iterator, RPCRecHitCollection::const_iterator> rangeRecHits;
     rangeRecHits recHitCollection =  rpcHits->get(detId);
     RPCRecHitCollection::const_iterator it;
     int numberOfHits=0;    
     int numbOfClusters=0;
     //loop RPCRecHits for given roll
     for (it = recHitCollection.first; it != recHitCollection.second ; it++) {
       numbOfClusters++; 
       if(detId.region() ==1 ){
       numclus++;
       RPCDetId detIdRecHits=it->rpcId();
       tamclus = tamclus + it->clusterSize();}
       //       cout << "Cluster Size is " << mult << endl;
       if(detId.region() ==  0) {
	 //	 cout << "Barrel" << endl;
       } else if (detId.region() ==  -1) {
	 //	 cout << "EndCapBack" << endl;
       } else if (detId.region() ==  1) {
	 //	 cout << "EndcapForward" << endl;
       } 
       
     }
     //cout << "The number of clusters was: " << numbOfClusters << endl;
   }
   iter2++;
   if(iter2==10){
     bin2++;
     numclust->Fill(bin2,(float)numclus/(float)10);
     tamclust->Fill(bin2,(float)10*tamclus/(float)numclus);
     numclus=0;
     tamclus=0;
     iter2=0;
   }
   countdi=0;
}


// ------------ method called once each job just before starting event loop  ------------
void 
Digian::beginJob(const edm::EventSetup&)
{
        theFile = new TFile("Bx.root", "RECREATE");
        theFile->cd();
        hbx = new TH1F("bx","Multiplicity bx histogram",100,0,100);
	hbadbx = new TH1F("badbx","Multiplicity bx histogram",100,0,100);
	hdigperev = new TH1F("Digis_per_Event","Digis per event",100,0,100);
	digidis = new TH1F("Digis_vs_time","Digis vs time",1331,0,1331);
	numclust = new TH1F("Num_clust_vs_time","Number  of clusters vs time",1331,0,1331);
	tamclust = new TH1F("Size_clust_vs_time","Size  of clusters vs time",1331,0,1331);
	iter = 0;
	sumdi = 0;
	bin = 0;
	iter2 = 0;
	bin2 = 0;
	numclus = 0;
	tamclus = 0;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
Digian::endJob() {
  using namespace std;
  cout << "There are " << numberless << " digis" << endl; 
  cout << "The efficiency of the triggering rule is " << 100-((float)numberless/(float)2797)*100 << " %" << endl; 
        theFile->cd();
        hbx->Write();
        hbadbx->Write();
	hdigperev->Write();
	digidis->Write();
	numclust->Write();
	tamclust->Write();
	theFile->Close();  

}

//define this as a plug-in
DEFINE_FWK_MODULE(Digian);
