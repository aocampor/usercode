#include "DQM/RPCMonitorDigi/interface/RPCLocalMonitor.h"

#include "DataFormats/RPCDigi/interface/RPCDigi.h"
#include "DataFormats/RPCDigi/interface/RPCDigiCollection.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "Geometry/CommonTopologies/interface/RectangularStripTopology.h"
#include "Geometry/CommonTopologies/interface/TrapezoidalStripTopology.h"
#include <DataFormats/RPCRecHit/interface/RPCRecHit.h>
#include "DataFormats/RPCRecHit/interface/RPCRecHitCollection.h"

#include <DataFormats/MuonDetId/interface/RPCDetId.h>
#include <Geometry/RPCGeometry/interface/RPCGeometry.h>
#include "Geometry/RPCGeometry/interface/RPCGeomServ.h"
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include <Geometry/Records/interface/MuonGeometryRecord.h>
#include "Geometry/Records/interface/GlobalTrackingGeometryRecord.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"
#include <DataFormats/GeometrySurface/interface/LocalError.h>
#include <DataFormats/GeometryVector/interface/LocalPoint.h>
#include "DataFormats/GeometrySurface/interface/Surface.h"
#include "DataFormats/DetId/interface/DetId.h"


#include <memory>
#include <cmath>
#include "TFile.h"
#include "TF1.h"
#include "TH1F.h"
#include "TROOT.h"
#include "TMath.h"



using namespace edm;
using namespace std;

RPCLocalMonitor::RPCLocalMonitor(const edm::ParameterSet& iConfig){

  std::map<RPCDetId, int> buff;
  counter.clear();
  counter.reserve(5);
  counter.push_back(buff);
  counter.push_back(buff);
  counter.push_back(buff);
  counter.push_back(buff);
  counter.push_back(buff);
  totalcounter.clear();
  totalcounter.reserve(5);
  totalcounter[0]=0;
  totalcounter[1]=0;
  totalcounter[2]=0;
  totalcounter[3]=0;
  totalcounter[4]=0;
}


RPCLocalMonitor::~RPCLocalMonitor(){
}

void RPCLocalMonitor::beginJob(const edm::EventSetup&){

  theFile = new TFile("BXandSTRIPS.root", "RECREATE");
  theFile->cd();
  bx = new TH1F("BX","Digis with this number of Bx",5,-3,3);
  strips = new TH1F("Strips","Strip Multiplicity",20,0,20);
  Numstrips = new TH1F("Strips","Number of digis with the same BX",100,0,100);
}

void RPCLocalMonitor::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup){

  std::map<RPCDetId, int> buff;
  std::map<int, int> countBX;
  std::map<int, int> countSTRIPS;

  int vectorbx[5];
  for(int i=0;i<5;i++)vectorbx[i]=0;
  
  edm::Handle<RPCRecHitCollection> rpcHits;
  iEvent.getByLabel("rpcRecHits",rpcHits);

  edm::Handle<RPCDigiCollection> rpcDigis;
  iEvent.getByLabel("rpcunpacker", rpcDigis);

  edm::ESHandle<RPCGeometry> rpcGeo;
  iSetup.get<MuonGeometryRecord>().get(rpcGeo);

  edm::ESHandle<MagneticField> field;
  iSetup.get<IdealMagneticFieldRecord>().get(field);


  for (TrackingGeometry::DetContainer::const_iterator it=rpcGeo->dets().begin();it<rpcGeo->dets().end();it++){
    if( dynamic_cast<RPCChamber*>(*it)!= 0){
      RPCChamber* ch = dynamic_cast< RPCChamber* >( *it );
      std::vector< const RPCRoll*> rolhit = (ch->rolls());
      for(std::vector<const RPCRoll*>::const_iterator itRoll = rolhit.begin();itRoll != rolhit.end(); ++itRoll){
	RPCDetId rollId=(*itRoll)->id();
	RPCGeomServ RPCname(rollId);
	std::string nameRoll = RPCname.name();
	RPCDigiCollection::Range rpcRangeDigi=rpcDigis->get(rollId);
		
	
	//counting digis
	
	int countdigis=0;

	for (RPCDigiCollection::const_iterator digiIt = rpcRangeDigi.first;digiIt!=rpcRangeDigi.second;++digiIt){
	 countdigis++;
	}

	if(countdigis!=0){
	  std::cout<<"# of digis"<<countdigis<<std::endl;
	  strips->Fill(countdigis);
	}
	
	for(int i=0;i<5;i++)vectorbx[i]=0;
	


	for (RPCDigiCollection::const_iterator digiIt = rpcRangeDigi.first;digiIt!=rpcRangeDigi.second;++digiIt){
	  int stripDetected=digiIt->strip();
	  int bxs=digiIt->bx();
	  std::cout<<"Strip Detected # "<<stripDetected<<" In roll "<<nameRoll<<"BX"<<bxs<<std::endl;
	  
	  //counting # of digis per BX
	
	  if(bxs==-2)vectorbx[0]++;
	  if(bxs==-1)vectorbx[1]++;
	  if(bxs==0)vectorbx[2]++;
	  if(bxs==1)vectorbx[3]++;
	  if(bxs==2)vectorbx[4]++;
	  bx->Fill(bxs);
	  
	  	  
	  //counting hits per roll
	  totalcounter[0]++;
	  buff=counter[0];
	  buff[rollId]++;
	  counter[0]=buff;
	}

	Numstrips->Fill(vectorbx[0]);
	Numstrips->Fill(vectorbx[1]);
	Numstrips->Fill(vectorbx[2]);
	Numstrips->Fill(vectorbx[3]);
	Numstrips->Fill(vectorbx[4]);


	

	//RECHITS
	
	
	RPCRecHitCollection::range rpcRecHitRange = rpcHits->get(rollId);
	RPCRecHitCollection::const_iterator recIt;
	  
	const RPCRoll* rollasociated = dynamic_cast<const RPCRoll*>(rpcGeo->roll(rollId));
	const BoundSurface& bSurface = rollasociated->surface();	
	int Fired=0;
	for (recIt = rpcRecHitRange.first; recIt!=rpcRecHitRange.second; ++recIt){
	  LocalPoint rhitlocal = (*recIt).localPosition();
	  const GlobalPoint rhitglob = bSurface.toGlobal(rhitlocal);

	  float globalX = rhitglob.x();
	  float globalY = rhitglob.y();
	  float globalZ = rhitglob.z();
	  std::cout<<"Rec Hit "<<rhitglob<<std::endl;
	}
      }
    }
  }
}

void RPCLocalMonitor::endJob(){

  std::map<RPCDetId, int> pred = counter[0];
  std::map<RPCDetId, int>::iterator irpc;
  int total=0;
  
  for (irpc=pred.begin(); irpc!=pred.end();irpc++){
    RPCDetId id=irpc->first;
    std::cout<<id<<" was hitted "<<pred[id]<<std::endl;
    total=total+pred[id];
  }

  std::cout<<" ---- RATIO ---- "<<std::endl;

  for (irpc=pred.begin(); irpc!=pred.end();irpc++){
    RPCDetId id=irpc->first;
    std::cout<<id<<" Ratio = "<<(float)pred[id]/(float)total*100<<"%"<<std::endl;
  }

  
  theFile->cd();
  bx->Write();
  strips->Write();
  Numstrips->Write();
  theFile->Close();

}




DEFINE_FWK_MODULE(RPCLocalMonitor);
