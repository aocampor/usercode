// -*- C++ -*-
//
// Package:    Beam
// Class:      Beam
// 
/**\class Beam Beam.cc UserCode/Beam/src/Beam.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Alberto Andres Ocampo Rios
//         Created:  Tue Sep 16 18:05:48 CEST 2008
// $Id$
//
//


// system include files
#include <memory>
#include <TRandom.h> 
#include <string>
#include "TMath.h"
#include "TROOT.h"

#include "TFile.h"
#include "TH1F.h"
#include <iostream>
#include <fstream>

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



//
// class decleration
//

class Beam : public edm::EDAnalyzer {
public:
  explicit Beam(const edm::ParameterSet&);
  ~Beam();


private:
  virtual void beginJob(const edm::EventSetup&) ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  TFile* theFile;
//  TH1F *hnumclus;
//  TH1F *hnumclus_bar;
//  TH1F *hnumclus_end;
//  TH1F *hclusize;
//  TH1F *hclusize_bar;
//  TH1F *hclusize_end;
//  TH1F *hcountdi;
//  TH1F *hcountdi_bar;
//  TH1F *hcountdi_end;
//  TH1F *hnumclus_e;
//  TH1F *hnumclus_bar_e;
//  TH1F *hnumclus_end_e;
//  TH1F *hclusize_e;
//  TH1F *hclusize_bar_e;
//  TH1F *hclusize_end_e;
//  TH1F *hcountdi_e;
//  TH1F *hcountdi_bar_e;
//  TH1F *hcountdi_end_e;
  TH1F *hcham1;
  TH1F *hcham2;
  double long  time_z;
  bool timebo;
  int clusize;
  int clusize_bar;
  int clusize_end;
  int countdi;
  int countdi_end;
  int countdi_bar;
  int numclus;
  int numclus_bar;
  int numclus_end;
  int min;
  int bins;
  int max;
  int min_e;
  int bins_e;
  int max_e;
  int ccham1;
  int ccham2;
  std::string file_name;
  std::ofstream *text_file;

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
Beam::Beam(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
  file_name = iConfig.getUntrackedParameter<std::string>("Root_file","Time_analysis.root");
  bins = iConfig.getUntrackedParameter<int>("hist_bin", 4000);
  min = iConfig.getUntrackedParameter<int>("hist_min",0);
  max = iConfig.getUntrackedParameter<int>("hist_max",200);
  bins_e =iConfig.getUntrackedParameter<int>("hist_bin_e", 4000);
  min_e = iConfig.getUntrackedParameter<int>("hist_min_e",0);
  max_e = iConfig.getUntrackedParameter<int>("hist_max_e",200);
}


Beam::~Beam()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
Beam::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  using namespace edm;
  using namespace std;
  
  edm::Handle<RPCRecHitCollection> rpcHits;
  iEvent.getByType(rpcHits);
  
  edm::Handle<RPCDigiCollection> rpcdigis;
  iEvent.getByType(rpcdigis);

  if(!timebo){
    timebo=true;
    time_z=iEvent.time().value();
    cout << "Prima volta: " << time_z << endl;
  }
  
  countdi=0;
  countdi_end=0;
  countdi_bar=0;
  numclus=0;
  numclus_bar=0;
  numclus_end=0;
  clusize=0;
  clusize_bar=0;
  clusize_end=0;
  ccham1=0;
  ccham2=0;
  RPCDigiCollection::DigiRangeIterator collectionItr;
  cout << "Ref " << time_z << endl;
  double long time = (iEvent.time().value()-time_z)/10E10;
  cout << "Tiempo " << time << endl;
  for(collectionItr=rpcdigis->begin(); collectionItr!=rpcdigis->end(); ++collectionItr){
    RPCDetId detId=(*collectionItr).first;
    if(detId.region() == 0){
      countdi_bar++;
    }
    if(detId.region() == 1){
      countdi_end++;
    }
    if(detId.region() == 0 and detId.ring() == -2 and detId.sector()== 9 and detId.station() == 1 and detId.layer() == 1 ){
      ccham1++;
    }
    if(detId.region() == 0 and detId.ring() == -2 and detId.sector()== 9 and detId.station() == 1 and detId.layer() == 1){
      ccham2++;
    }
    countdi++;
    //get the RecHits associated to the roll
    typedef pair<RPCRecHitCollection::const_iterator, RPCRecHitCollection::const_iterator> rangeRecHits;
    rangeRecHits recHitCollection =  rpcHits->get(detId);
    RPCRecHitCollection::const_iterator it;
    for (it = recHitCollection.first; it != recHitCollection.second ; it++) {
      numclus++;
      clusize=clusize+it->clusterSize();
      if(detId.region()==0){
	numclus_bar++;
	clusize_bar=clusize_bar+it->clusterSize();
      }
      if(detId.region()==1){
	numclus_end++;
	clusize_end=clusize_end+it->clusterSize();
      }
    }
  }
  (*text_file) << iEvent.id().event() << "\t" << iEvent.time().value() << "\t";
  (*text_file) << countdi << "\t" << countdi_bar << "\t" << countdi_end << "\t";
  (*text_file) << numclus << "\t" << numclus_bar << "\t" << numclus_end << std::endl;
  hcham1->Fill(iEvent.id().event(),ccham1);
  hcham2->Fill(iEvent.id().event(),ccham2);
//  hclusize->Fill(time,(float)clusize/(float)numclus);
//  hclusize_e->Fill(iEvent.id().event(),(float)clusize/(float)numclus);
//  hclusize_bar->Fill(time,(float)clusize_bar/(float)numclus_bar);
//  hclusize_bar_e->Fill(iEvent.id().event(),(float)clusize_bar/(float)numclus_bar);
//  hclusize_end->Fill(time,(float)clusize_end/(float)numclus_end);
//  hclusize_end_e->Fill(iEvent.id().event(),(float)clusize_end/(float)numclus_end);
//  hnumclus->Fill(time,numclus);
//  hnumclus_e->Fill(iEvent.id().event(),numclus);
//  hnumclus_bar->Fill(time,numclus_bar);
//  hnumclus_bar_e->Fill(iEvent.id().event(),numclus_bar);
//  hnumclus_end->Fill(time,numclus_end);
//  hnumclus_end_e->Fill(iEvent.id().event(),numclus_end);
////  hcountdi_bar->Fill(time,countdi_bar);
////  hcountdi_bar_e->Fill(iEvent.id().event(),countdi_bar);
////  hcountdi_end->Fill(time,countdi_end);
////  hcountdi_end_e->Fill(iEvent.id().event(),countdi_end);
////  hcountdi->Fill(time,countdi);
////  hcountdi_e->Fill(iEvent.id().event(),countdi);
  cout << "digis bar , end, tutti: " << countdi_bar << " " << countdi_end << " " << countdi << endl;
}


// ------------ method called once each job just before starting event loop  ------------
void 
Beam::beginJob(const edm::EventSetup&)
{
  timebo=false;
  text_file = new std::ofstream(file_name.c_str(),std::ofstream::out);
  //  theFile = new TFile(file_name.c_str(),"RECREATE");
  //  theFile->cd();
////  hcountdi = new TH1F("Barrel_Endcap_digis_vs_time","# Digis Barrel and Endcap vs time",bins,min,max);
////  hcountdi_e = new TH1F("Barrel_Endcap_digis_vs_event","# Digis Barrel and Endcap vs Event",bins_e,min_e,max_e);
////  hcountdi_bar = new TH1F("Barrel_digis_vs_time","# Digis Barrel vs time",bins,min,max);
////  hcountdi_bar_e = new TH1F("Barrel_digis_vs_event","# Digis Barrel vs Event",bins_e,min_e,max_e);
////  hcountdi_end = new TH1F("Endcap_digis_vs_time","# Digis Endcap vs time",bins,min,max);
////  hcountdi_end_e = new TH1F("Endcap_digis_vs_event","# Digis Endcap vs event",bins_e,min_e,max_e);
//  hnumclus = new TH1F("digis_Barrel_Endcap_clusters_vs_time","# Clusters Barrel and Endcap vs time",bins,min,max);
//  hnumclus_e = new TH1F("digis_Barrel_Endcap_clusters_vs_event","# Clusters Barrel and Endcap vs event",bins_e,min_e,max_e);
//  hnumclus_bar = new TH1F("Barrel_clus_vs_time","# Clusters Barrel vs time",bins,min,max);
//  hnumclus_bar_e = new TH1F("Barrel_clus_vs_event","# Clusters Barrel vs event ",bins_e,min_e,max_e);
//  hnumclus_end = new TH1F("Endcap_clus_vs_time","# Clusters Endcap vs time",bins,min,max);
//  hnumclus_end_e = new TH1F("Endcap_clus_vs_event","# Clusters Endcap vs event",bins_e,min_e,max_e);
//  hclusize = new TH1F("Barrel_Endcap_clusters_size_vs_time","# Clusters_size Barrel and Endcap vs time",bins,min,max);
//  hclusize_e = new TH1F("Barrel_Endcap_clusters_size_vs_event","# Clusters_size Barrel and Endcap vs event",bins_e,min_e,max_e);
//  hclusize_bar = new TH1F("Barrel_clus_size_vs_time","# Cluster size Barrel vs time",bins,min,max);
//  hclusize_bar_e = new TH1F("Barrel_clus_size_vs_event","# Cluster size Barrel vs event",bins_e,min_e,max_e);
//  hclusize_end = new TH1F("Endcap_clus_size_vs_time","# Cluster size Endcap vs time",bins,min,max);
//  hclusize_end_e = new TH1F("Endcap_clus_size_vs_event","# Cluster size Endcap vs event",bins_e,min_e,max_e);
  hcham1 = new TH1F("RB1_in_w2","# digis RB1in w2 vs time",bins,min,max);
  hcham2 = new TH1F("RB1_inwm2","# digis RB1in w-2 vs time",bins,min,max);
}


// ------------ method called once each job just after ending the event loop  ------------
void Beam::endJob() {
  text_file->close();
  delete text_file;
  theFile->cd();
  hcham1->Write();
  hcham2->Write();
////  hcountdi->Write();
////  hcountdi_e->Write();
////  hcountdi_bar->Write();
////  hcountdi_bar_e->Write();
////  hcountdi_end->Write();
////  hcountdi_end_e->Write();
//  hnumclus->Write();
//  hnumclus_e->Write();
//  hnumclus_bar->Write();
//  hnumclus_bar_e->Write();
//  hnumclus_end->Write();
//  hnumclus_end_e->Write();
//  hclusize->Write();
//  hclusize_e->Write();
//  hclusize_bar->Write();
//  hclusize_bar_e->Write();
//  hclusize_end->Write();
//  hclusize_end_e->Write();
  theFile->Close(); 
}

//define this as a plug-in
DEFINE_FWK_MODULE(Beam);
