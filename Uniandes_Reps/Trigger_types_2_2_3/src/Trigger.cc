// -*- C++ -*-
//
// Package:    Trigger
// Class:      Trigger
// 
/**\class Trigger Trigger.cc UserCode/Trigger/src/Trigger.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Alberto Andres Ocampo Rios
//         Created:  Tue May 12 12:54:07 CEST 2009
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
#include "DataFormats/Provenance/interface/Timestamp.h"
#include <sys/time.h>

//
// class decleration
//

class Trigger : public edm::EDAnalyzer {
public:
  explicit Trigger(const edm::ParameterSet&);
  ~Trigger();


private:
  virtual void beginJob(const edm::EventSetup&) ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  
  TFile *hfile;

  TH1I *hbarrel;

  TH1I *hwm2;
  TH1I *hwm1;
  TH1I *hw0;
  TH1I *hw1;
  TH1I *hw2;

  TH1I *hwm2s1;
  TH1I *hwm2s2;
  TH1I *hwm2s3;
  TH1I *hwm2s4;
  TH1I *hwm2s5;
  TH1I *hwm2s6;
  TH1I *hwm2s7;
  TH1I *hwm2s8;
  TH1I *hwm2s9;
  TH1I *hwm2s10;
  TH1I *hwm2s11;
  TH1I *hwm2s12;

  TH1I *hwm1s1;
  TH1I *hwm1s2;
  TH1I *hwm1s3;
  TH1I *hwm1s4;
  TH1I *hwm1s5;
  TH1I *hwm1s6;
  TH1I *hwm1s7;
  TH1I *hwm1s8;
  TH1I *hwm1s9;
  TH1I *hwm1s10;
  TH1I *hwm1s11;
  TH1I *hwm1s12;

  TH1I *hw0s1;
  TH1I *hw0s2;
  TH1I *hw0s3;
  TH1I *hw0s4;
  TH1I *hw0s5;
  TH1I *hw0s6;
  TH1I *hw0s7;
  TH1I *hw0s8;
  TH1I *hw0s9;
  TH1I *hw0s10;
  TH1I *hw0s11;
  TH1I *hw0s12;

  TH1I *hw1s1;
  TH1I *hw1s2;
  TH1I *hw1s3;
  TH1I *hw1s4;
  TH1I *hw1s5;
  TH1I *hw1s6;
  TH1I *hw1s7;
  TH1I *hw1s8;
  TH1I *hw1s9;
  TH1I *hw1s10;
  TH1I *hw1s11;
  TH1I *hw1s12;

  TH1I *hw2s1;
  TH1I *hw2s2;
  TH1I *hw2s3;
  TH1I *hw2s4;
  TH1I *hw2s5;
  TH1I *hw2s6;
  TH1I *hw2s7;
  TH1I *hw2s8;
  TH1I *hw2s9;
  TH1I *hw2s10;
  TH1I *hw2s11;
  TH1I *hw2s12;

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
Trigger::Trigger(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
  root_file_name = iConfig.getUntrackedParameter<std::string>("histoName");
}


Trigger::~Trigger()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
Trigger::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  using namespace std;
  
  edm::Handle<RPCDigiCollection> rpcdigis;
  iEvent.getByLabel("muonRPCDigis",rpcdigis);
  edm::ESHandle<RPCGeometry> rpcGeo;
  iSetup.get<MuonGeometryRecord>().get(rpcGeo);
  
  std::vector<std::vector < int > > actvec;
  std::vector<int> vec;

   int bx = iEvent.bunchCrossing();
   int thisOrbit = iEvent.orbitNumber();
   double orbitTime = 0.03564*(double)thisOrbit +(double)((double)bx/100000.0);
   double tempo = (orbitTime/10000)*25;
  
  for (TrackingGeometry::DetContainer::const_iterator it=rpcGeo->dets().begin();it<rpcGeo->dets().end();it++){
    if(dynamic_cast< RPCChamber* >( *it ) != 0 ){
      RPCChamber* ch = dynamic_cast< RPCChamber* >( *it );
      std::vector< const RPCRoll*> roles = (ch->rolls());
      
      for(std::vector<const RPCRoll*>::const_iterator r = roles.begin();r != roles.end(); ++r){
	RPCDetId rpcId = (*r)->id();
	RPCDigiCollection::Range rpcRangeDigi=rpcdigis->get(rpcId);
	
	for (RPCDigiCollection::const_iterator digiIt = rpcRangeDigi.first;digiIt!=rpcRangeDigi.second;++digiIt){
	  vec.clear();
	  //	   vec.push_back(id.rawId());
	  vec.push_back(digiIt->strip());
	  vec.push_back(digiIt->bx());
	  vec.push_back(rpcId.ring());
	  vec.push_back(rpcId.sector());
	  vec.push_back(rpcId.station());
	  vec.push_back(rpcId.layer());
	  vec.push_back(rpcId.subsector());
	  bool vectores=false;
	  for (int i = 0; i < actvec.size();i++ ){
	    if(actvec[i]==vec){
	      vectores=true;
	    }
	  }
	  if(!vectores){
	    actvec.push_back(vec);
	    cout << "\t Wheel: " << rpcId.ring() << " sector: " << rpcId.sector() << " station: " << rpcId.station() << " layer: " << rpcId.layer() << endl;
	    cout << "Strip: " << digiIt->strip() << " Bx:  " << digiIt->bx() << endl;
	    
	  }
	}
      }
    }
  }
  //   for(std::vector<std::vector < int > >::const_iterator i =actvec.begin();i!=actvec.end();++i){
  //     for(std::vector < int >::const_iterator j=(*i).begin();j!=(*i).end();++j){
  //     for(int j = 0; j < actvec[i].size();j++){
  //       cout << "prueba: " << (*j) << endl;
  //     cout << "Wheel: " << actvec[i][j] << endl;
  int whem2b0[6][12];
  int whem2b1[6][12];
  int whem1b0[6][12];
  int whem1b1[6][12];
  int whe0b0[6][12];
  int whe0b1[6][12];
  int whe1b0[6][12];
  int whe1b1[6][12];
  int whe2b0[6][12];
  int whe2b1[6][12];
  for (int i=0;i < 6;i++){
    for (int j=0;j<12;j++){
      whem2b0[i][j]=0;
      whem2b1[i][j]=0;
      whem1b0[i][j]=0;
      whem1b1[i][j]=0;
      whe0b0[i][j]=0;
      whe0b1[i][j]=0;
      whe1b0[i][j]=0;
      whe1b1[i][j]=0;
      whe2b0[i][j]=0;
      whe2b1[i][j]=0;
    }
  }
  for(int i = 0; i < actvec.size();i++){
    if(actvec[i][1]==0){
      for(int whe=-2;whe<=2;whe++){ 
	if(actvec[i][2]==whe){
	  for(int sec=1;sec<=12;sec++){
	    if(actvec[i][3]==sec){
	      if(actvec[i][4]==1 and actvec[i][5] == 1){
		if(whe==-2)
		  whem2b0[0][sec-1]++;     
		else
		  if(whe==-1)
		    whem1b0[0][sec-1]++;
		  else
		    if(whe==0)
		      whe0b0[0][sec-1]++;
		    else
		      if(whe==1)
			whe1b0[0][sec-1]++;
		      else
			if(whe==2)
			  whe2b0[0][sec-1]++;
		break;
	      }
	      else
		if(actvec[i][4]==1 and actvec[i][5] == 2){
		  if(whe==-2)
		    whem2b0[1][sec-1]++;     
		  else
		    if(whe==-1)
		      whem1b0[1][sec-1]++;
		    else
		      if(whe==0)
			whe0b0[1][sec-1]++;
		      else
			if(whe==1)
			  whe1b0[1][sec-1]++;
			else
			  if(whe==2)
			    whe2b0[1][sec-1]++;
		  break;
		}
		else
		  if(actvec[i][4]==2 and actvec[i][5] == 1){
		    if(whe==-2)
		      whem2b0[2][sec-1]++;     
		    else
		      if(whe==-1)
			whem1b0[2][sec-1]++;
		      else
			if(whe==0)
			  whe0b0[2][sec-1]++;
			else
			  if(whe==1)
			    whe1b0[2][sec-1]++;
			  else
			    if(whe==2)
			      whe2b0[2][sec-1]++;
		    break;
		  }
		  else
		    if(actvec[i][4]==2 and actvec[i][5] == 2){
		      if(whe==-2)
			whem2b0[3][sec-1]++;     
		      else
			if(whe==-1)
			  whem1b0[3][sec-1]++;
			else
			  if(whe==0)
			    whe0b0[3][sec-1]++;
			  else
			    if(whe==1)
			      whe1b0[3][sec-1]++;
			    else
			      if(whe==2)
				whe2b0[3][sec-1]++;
		      break;
		    }
		    else
		      if(actvec[i][4]==3){
			if(whe==-2)
			  whem2b0[4][sec-1]++;     
			else
			  if(whe==-1)
			    whem1b0[4][sec-1]++;
			  else
			    if(whe==0)
			      whe0b0[4][sec-1]++;
			    else
			      if(whe==1)
				whe1b0[4][sec-1]++;
			      else
				if(whe==2)
				  whe2b0[4][sec-1]++;
			break;
		      }
		      else
			if(actvec[i][4]==4){
			  if(whe==-2)
			    whem2b0[5][sec-1]++;     
			  else
			    if(whe==-1)
			      whem1b0[5][sec-1]++;
			    else
			      if(whe==0)
				whe0b0[5][sec-1]++;
			      else
				if(whe==1)
				  whe1b0[5][sec-1]++;
				else
				  if(whe==2)
				    whe2b0[5][sec-1]++;
			  break;
			}
	    }
	  }
	}
      }
    }
  }
  //  if(tempo >= 105 and tempo <= 107){
  for(int j=0;j<12;j++){
    int cont =0;
    int type = 1;
    int contm1 =0;
    int typem1 = 1;
    int cont0 =0;
    int type0 = 1;
    int cont1 =0;
    int type1 = 1;
    int cont2 =0;
    int type2 = 1;
    for(int i=0;i<6;i++){
      if(whem2b0[i][j]!=0){
	cont++;
	if(whem2b0[i][j]>10)
	  type++; 
      }
      if(cont>=3){
	std::cout << "Event: " << iEvent.id().event()  << " type: " << type << std::endl;
	cout << "There was a trigger in wheel -2 at bx 0 in sector " << j+1 << " of the type " << type << endl;
	cout << "Layers: " << whem2b0[0][j] << " " << whem2b0[1][j] << " " << whem2b0[2][j] << " " << whem2b0[3][j] << " " << whem2b0[4][j] << " " << whem2b0[5][j] << endl;
	hbarrel->Fill(type);
	
	hwm2->Fill(type);
	if(j+1==1)
	  hwm2s1->Fill(type);
	else
	  if(j+1==2)
	    hwm2s2->Fill(type);
	  else
	    if(j+1==3)
	      hwm2s3->Fill(type);
	    else
	      if(j+1==4)
		hwm2s4->Fill(type);
	      else
		if(j+1==5)
		  hwm2s5->Fill(type);
		else
		  if(j+1==6)
		    hwm2s6->Fill(type);
		  else
		    if(j+1==7)
		      hwm2s7->Fill(type);
		    else
		      if(j+1==8)
			hwm2s8->Fill(type);
		      else
			if(j+1==9)
			  hwm2s9->Fill(type);
			else
			  if(j+1==10)
			    hwm2s10->Fill(type);
			  else
			    if(j+1==11)
			      hwm2s11->Fill(type);
			    else
			      if(j+1==12)
				hwm2s12->Fill(type);
      }
      if(whem1b0[i][j]!=0){
	contm1++;
	if(whem1b0[i][j]>10)
	  typem1++; 
      }
      if(contm1>=3){
	std::cout << "Event: " << iEvent.id().event()  << " type: " << typem1 << std::endl;
	cout << "There was a trigger in wheel -1 at bx 0 in sector " << j+1 << " of the type " << typem1 << endl;
	cout << "Layers: " << whem1b0[0][j] << " " << whem1b0[1][j] << " " << whem1b0[2][j] << " " << whem1b0[3][j] << " " << whem1b0[4][j] << " " << whem1b0[5][j] << endl;
	hbarrel->Fill(typem1);
	
	hwm1->Fill(typem1);
	if(j+1==1)
	  hwm1s1->Fill(typem1);
	else
	  if(j+1==2)
	    hwm1s2->Fill(typem1);
	  else
	    if(j+1==3)
	      hwm1s3->Fill(typem1);
	    else
	      if(j+1==4)
		hwm1s4->Fill(typem1);
	      else
		if(j+1==5)
		  hwm1s5->Fill(typem1);
		else
		  if(j+1==6)
		    hwm1s6->Fill(typem1);
		  else
		    if(j+1==7)
		      hwm1s7->Fill(typem1);
		    else
		      if(j+1==8)
			hwm1s8->Fill(typem1);
		      else
			if(j+1==9)
			  hwm1s9->Fill(typem1);
			else
			  if(j+1==10)
			    hwm1s10->Fill(typem1);
			  else
			    if(j+1==11)
			      hwm1s11->Fill(typem1);
			    else
			      if(j+1==12)
				hwm1s12->Fill(typem1);
      }
      if(whe0b0[i][j]!=0){
	cont0++;
	if(whe0b0[i][j]>10)
	  type0++; 
      }
      if(cont0>=3){
	std::cout << "Event: " << iEvent.id().event()  << " type: " << type0 << std::endl;
	cout << "There was a trigger in wheel 0 at bx 0 in sector " << j+1 << " of the type " << type0 << endl;
	cout << "Layers: " << whe0b0[0][j] << " " << whe0b0[1][j] << " " << whe0b0[2][j] << " " << whe0b0[3][j] << " " << whe0b0[4][j] << " " << whe0b0[5][j] << endl;
	hbarrel->Fill(type0);
	
	hw0->Fill(type0);
	if(j+1==1)
	  hw0s1->Fill(type0);
	else
	  if(j+1==2)
	    hw0s2->Fill(type0);
	  else
	    if(j+1==3)
	      hw0s3->Fill(type0);
	    else
	      if(j+1==4)
		hw0s4->Fill(type0);
	      else
		if(j+1==5)
		  hw0s5->Fill(type0);
		else
		  if(j+1==6)
		    hw0s6->Fill(type0);
		  else
		    if(j+1==7)
		      hw0s7->Fill(type0);
		    else
		      if(j+1==8)
			hw0s8->Fill(type0);
		      else
			if(j+1==9)
			  hw0s9->Fill(type0);
			else
			  if(j+1==10)
			    hw0s10->Fill(type0);
			  else
			    if(j+1==11)
			      hw0s11->Fill(type0);
			    else
			      if(j+1==12)
				hw0s12->Fill(type0);
      }
      if(whe1b0[i][j]!=0){
	cont1++;
	if(whe1b0[i][j]>10)
	  type1++; 
      }
      if(cont1>=3){
	std::cout << "Event: " << iEvent.id().event()  << " type: " << type1 << std::endl;
	cout << "There was a trigger in wheel 1 at bx 0 in sector " << j+1 << " of the type " << type1 << endl;
	cout << "Layers: " << whe1b0[0][j] << " " << whe1b0[1][j] << " " << whe1b0[2][j] << " " << whe1b0[3][j] << " " << whe1b0[4][j] << " " << whe1b0[5][j] << endl;
	hbarrel->Fill(type1);
	
	hw1->Fill(type1);
	if(j+1==1)
	  hw1s1->Fill(type1);
	else
	  if(j+1==2)
	    hw1s2->Fill(type1);
	  else
	    if(j+1==3)
	      hw1s3->Fill(type1);
	    else
	      if(j+1==4)
		hw1s4->Fill(type1);
	      else
		if(j+1==5)
		  hw1s5->Fill(type1);
		else
		  if(j+1==6)
		    hw1s6->Fill(type1);
		  else
		    if(j+1==7)
		      hw1s7->Fill(type1);
		    else
		      if(j+1==8)
			hw1s8->Fill(type1);
		      else
			if(j+1==9)
			  hw1s9->Fill(type1);
			else
			  if(j+1==10)
			    hw1s10->Fill(type1);
			  else
			    if(j+1==11)
			      hw1s11->Fill(type1);
			    else
			      if(j+1==12)
				hw1s12->Fill(type1);
      }
      if(whe2b0[i][j]!=0){
	cont2++;
	if(whe2b0[i][j]>10)
	  type2++; 
      }
      if(cont2>=3){
	std::cout << "Event: " << iEvent.id().event()  << " type: " << type2 << std::endl;
	cout << "There was a trigger in wheel 2 at bx 0 in sector " << j+1 << " of the type " << type2 << endl;
	cout << "Layers: " << whe2b0[0][j] << " " << whe2b0[1][j] << " " << whe2b0[2][j] << " " << whe2b0[3][j] << " " << whe2b0[4][j] << " " << whe2b0[5][j] << endl;
	hbarrel->Fill(type2);
	
	hw2->Fill(type2);
	if(j+1==1)
	  hw2s1->Fill(type2);
	else
	  if(j+1==2)
	    hw2s2->Fill(type2);
	  else
	    if(j+1==3)
	      hw2s3->Fill(type2);
	    else
	      if(j+1==4)
		hw2s4->Fill(type2);
	      else
		if(j+1==5)
		  hw2s5->Fill(type2);
		else
		  if(j+1==6)
		    hw2s6->Fill(type2);
		  else
		    if(j+1==7)
		      hw2s7->Fill(type2);
		    else
		      if(j+1==8)
			hw2s8->Fill(type2);
		      else
			if(j+1==9)
			  hw2s9->Fill(type2);
			else
			  if(j+1==10)
			    hw2s10->Fill(type2);
			  else
			    if(j+1==11)
			      hw2s11->Fill(type2);
			    else
			      if(j+1==12)
				hw2s12->Fill(type2);
      }
    }
  }//}
}


// ------------ method called once each job just before starting event loop  ------------
void 
Trigger::beginJob(const edm::EventSetup&)
{
  hfile = new TFile(root_file_name.c_str(),"RECREATE");//"Trigger.root","RECREATE");
  hbarrel = new TH1I("Barrel","Barrel Trigger Type Distribution",7,0,7);

  hwm2 = new TH1I("wm2","Wheel -2 Trigger Type Distribution",7,0,7);
  hwm1 = new TH1I("wm1","Wheel -1 Trigger Type Distribution",7,0,7);
  hw0 = new TH1I("w0","Wheel 0 Trigger Type Distribution",7,0,7);
  hw1 = new TH1I("w1","Wheel 1 Trigger Type Distribution",7,0,7);
  hw2 = new TH1I("w2","Wheel 2 Trigger Type Distribution",7,0,7);

  hwm2s1 = new TH1I("wm2S01","Wheel -2 S01 Trigger Type Distribution",7,0,7);
  hwm2s2 = new TH1I("wm2S02","Wheel -2 S02 Trigger Type Distribution",7,0,7);
  hwm2s3 = new TH1I("wm2S03","Wheel -2 S03 Trigger Type Distribution",7,0,7);
  hwm2s4 = new TH1I("wm2S04","Wheel -2 S04 Trigger Type Distribution",7,0,7);
  hwm2s5 = new TH1I("wm2S05","Wheel -2 S05 Trigger Type Distribution",7,0,7);
  hwm2s6 = new TH1I("wm2S06","Wheel -2 S06 Trigger Type Distribution",7,0,7);
  hwm2s7 = new TH1I("wm2S07","Wheel -2 S07 Trigger Type Distribution",7,0,7);
  hwm2s8 = new TH1I("wm2S08","Wheel -2 S08 Trigger Type Distribution",7,0,7);
  hwm2s9 = new TH1I("wm2S09","Wheel -2 S09 Trigger Type Distribution",7,0,7);
  hwm2s10 = new TH1I("wm2S10","Wheel -2 S10 Trigger Type Distribution",7,0,7);
  hwm2s11 = new TH1I("wm2S11","Wheel -2 S11 Trigger Type Distribution",7,0,7);
  hwm2s12 = new TH1I("wm2S12","Wheel -2 S12 Trigger Type Distribution",7,0,7);

  hwm1s1 = new TH1I("wm1S01","Wheel -1 S01 Trigger Type Distribution",7,0,7);
  hwm1s2 = new TH1I("wm1S02","Wheel -1 S02 Trigger Type Distribution",7,0,7);
  hwm1s3 = new TH1I("wm1S03","Wheel -1 S03 Trigger Type Distribution",7,0,7);
  hwm1s4 = new TH1I("wm1S04","Wheel -1 S04 Trigger Type Distribution",7,0,7);
  hwm1s5 = new TH1I("wm1S05","Wheel -1 S05 Trigger Type Distribution",7,0,7);
  hwm1s6 = new TH1I("wm1S06","Wheel -1 S06 Trigger Type Distribution",7,0,7);
  hwm1s7 = new TH1I("wm1S07","Wheel -1 S07 Trigger Type Distribution",7,0,7);
  hwm1s8 = new TH1I("wm1S08","Wheel -1 S08 Trigger Type Distribution",7,0,7);
  hwm1s9 = new TH1I("wm1S09","Wheel -1 S09 Trigger Type Distribution",7,0,7);
  hwm1s10 = new TH1I("wm1S10","Wheel -1 S10 Trigger Type Distribution",7,0,7);
  hwm1s11 = new TH1I("wm1S11","Wheel -1 S11 Trigger Type Distribution",7,0,7);
  hwm1s12 = new TH1I("wm1S12","Wheel -1 S12 Trigger Type Distribution",7,0,7);

  hw0s1 = new TH1I("w0S01","Wheel 0 S01 Trigger Type Distribution",7,0,7);
  hw0s2 = new TH1I("w0S02","Wheel 0 S02 Trigger Type Distribution",7,0,7);
  hw0s3 = new TH1I("w0S03","Wheel 0 S03 Trigger Type Distribution",7,0,7);
  hw0s4 = new TH1I("w0S04","Wheel 0 S04 Trigger Type Distribution",7,0,7);
  hw0s5 = new TH1I("w0S05","Wheel 0 S05 Trigger Type Distribution",7,0,7);
  hw0s6 = new TH1I("w0S06","Wheel 0 S06 Trigger Type Distribution",7,0,7);
  hw0s7 = new TH1I("w0S07","Wheel 0 S07 Trigger Type Distribution",7,0,7);
  hw0s8 = new TH1I("w0S08","Wheel 0 S08 Trigger Type Distribution",7,0,7);
  hw0s9 = new TH1I("w0S09","Wheel 0 S09 Trigger Type Distribution",7,0,7);
  hw0s10 = new TH1I("w0S10","Wheel 0 S10 Trigger Type Distribution",7,0,7);
  hw0s11 = new TH1I("w0S11","Wheel 0 S11 Trigger Type Distribution",7,0,7);
  hw0s12 = new TH1I("w0S12","Wheel 0 S12 Trigger Type Distribution",7,0,7);

  hw1s1 = new TH1I("w1S01","Wheel 1 S01 Trigger Type Distribution",7,0,7);
  hw1s2 = new TH1I("w1S02","Wheel 1 S02 Trigger Type Distribution",7,0,7);
  hw1s3 = new TH1I("w1S03","Wheel 1 S03 Trigger Type Distribution",7,0,7);
  hw1s4 = new TH1I("w1S04","Wheel 1 S04 Trigger Type Distribution",7,0,7);
  hw1s5 = new TH1I("w1S05","Wheel 1 S05 Trigger Type Distribution",7,0,7);
  hw1s6 = new TH1I("w1S06","Wheel 1 S06 Trigger Type Distribution",7,0,7);
  hw1s7 = new TH1I("w1S07","Wheel 1 S07 Trigger Type Distribution",7,0,7);
  hw1s8 = new TH1I("w1S08","Wheel 1 S08 Trigger Type Distribution",7,0,7);
  hw1s9 = new TH1I("w1S09","Wheel 1 S09 Trigger Type Distribution",7,0,7);
  hw1s10 = new TH1I("w1S10","Wheel 1 S10 Trigger Type Distribution",7,0,7);
  hw1s11 = new TH1I("w1S11","Wheel 1 S11 Trigger Type Distribution",7,0,7);
  hw1s12 = new TH1I("w1S12","Wheel 1 S12 Trigger Type Distribution",7,0,7);

  hw2s1 = new TH1I("w2S01","Wheel 2 S01 Trigger Type Distribution",7,0,7);
  hw2s2 = new TH1I("w2S02","Wheel 2 S02 Trigger Type Distribution",7,0,7);
  hw2s3 = new TH1I("w2S03","Wheel 2 S03 Trigger Type Distribution",7,0,7);
  hw2s4 = new TH1I("w2S04","Wheel 2 S04 Trigger Type Distribution",7,0,7);
  hw2s5 = new TH1I("w2S05","Wheel 2 S05 Trigger Type Distribution",7,0,7);
  hw2s6 = new TH1I("w2S06","Wheel 2 S06 Trigger Type Distribution",7,0,7);
  hw2s7 = new TH1I("w2S07","Wheel 2 S07 Trigger Type Distribution",7,0,7);
  hw2s8 = new TH1I("w2S08","Wheel 2 S08 Trigger Type Distribution",7,0,7);
  hw2s9 = new TH1I("w2S09","Wheel 2 S09 Trigger Type Distribution",7,0,7);
  hw2s10 = new TH1I("w2S10","Wheel 2 S10 Trigger Type Distribution",7,0,7);
  hw2s11 = new TH1I("w2S11","Wheel 2 S11 Trigger Type Distribution",7,0,7);
  hw2s12 = new TH1I("w2S12","Wheel 2 S12 Trigger Type Distribution",7,0,7);

}

// ------------ method called once each job just after ending the event loop  ------------
void 
Trigger::endJob() {

  hbarrel->Write();

  hwm2->Write();
  hwm1->Write();
  hw0->Write();
  hw1->Write();
  hw2->Write();

  hwm2s1->Write();
  hwm2s2->Write();
  hwm2s3->Write();
  hwm2s4->Write();
  hwm2s5->Write();
  hwm2s6->Write();
  hwm2s7->Write();
  hwm2s8->Write();
  hwm2s9->Write();
  hwm2s10->Write();
  hwm2s11->Write();
  hwm2s12->Write();

  hwm1s1->Write();
  hwm1s2->Write();
  hwm1s3->Write();
  hwm1s4->Write();
  hwm1s5->Write();
  hwm1s6->Write();
  hwm1s7->Write();
  hwm1s8->Write();
  hwm1s9->Write();
  hwm1s10->Write();
  hwm1s11->Write();
  hwm1s12->Write();

  hw0s1->Write();
  hw0s2->Write();
  hw0s3->Write();
  hw0s4->Write();
  hw0s5->Write();
  hw0s6->Write();
  hw0s7->Write();
  hw0s8->Write();
  hw0s9->Write();
  hw0s10->Write();
  hw0s11->Write();
  hw0s12->Write();

  hw1s1->Write();
  hw1s2->Write();
  hw1s3->Write();
  hw1s4->Write();
  hw1s5->Write();
  hw1s6->Write();
  hw1s7->Write();
  hw1s8->Write();
  hw1s9->Write();
  hw1s10->Write();
  hw1s11->Write();
  hw1s12->Write();

  hw2s1->Write();
  hw2s2->Write();
  hw2s3->Write();
  hw2s4->Write();
  hw2s5->Write();
  hw2s6->Write();
  hw2s7->Write();
  hw2s8->Write();
  hw2s9->Write();
  hw2s10->Write();
  hw2s11->Write();
  hw2s12->Write();

  hfile->Close();
}

//define this as a plug-in
DEFINE_FWK_MODULE(Trigger);
