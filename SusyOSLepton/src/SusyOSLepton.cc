#include "SusyAnalyzers/SusyOSLepton/interface/SusyOSLepton.h"
#include "DataFormats/Common/interface/OwnVector.h"
//#include "DataFormats/PatCandidates/interface/TriggerPrimitive.h"

#include "DataFormats/Candidate/interface/Particle.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/RecoCandidate/interface/RecoCandidate.h"
#include "DataFormats/Candidate/interface/CandMatchMap.h"
#include "DataFormats/Common/interface/AssociationVector.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/BeamSpot/interface/BeamSpot.h"

#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"

//physics tools

#include "PhysicsTools/UtilAlgos/interface/TFileService.h"

//root 

#include <TROOT.h>
#include "TPaletteAxis.h"
#include "TTimeStamp.h"
#include "TTree.h"
#include "TString.h"
#include "TFolder.h"
#include <TStyle.h>




// ------------ The Constructor --------------

SusyOSLepton::SusyOSLepton(const edm::ParameterSet& iConfig)

{
  
  //... now do what ever initialization is needed
  
  MuonInputTag = iConfig.getParameter<edm::InputTag>("MuonTag");
  ElectronInputTag = iConfig.getParameter<edm::InputTag>("ElectronTag");
  JetInputTag = iConfig.getParameter<edm::InputTag>("JetTag");
  MetInputTag = iConfig.getParameter<edm::InputTag>("MetTag"); 
   
  CutsMask = iConfig.getParameter< std::vector<unsigned> >("CutsMask"); // 1:apply cut. 0:ignore cut

  MuonIsoCut = (float) iConfig.getParameter<double>("MuonIsoCut");
  MuonPtCut = (float) iConfig.getParameter<double>("MuonPtCut");
  MuonEtaCut = (float) iConfig.getParameter<double>("MuonEtaCut");
  MuonChiDoFCut = (float) iConfig.getParameter<double>("MuonChiDoFCut");
  Muond0Cut = (float) iConfig.getParameter<double>("Muond0Cut");
  MuonTrkCut = (int) iConfig.getParameter<int>("MuonTrkCut");
  MuonHCalECut = (float) iConfig.getParameter<double>("MuonHCalECut");
  MuonECalECut = (float) iConfig.getParameter<double>("MuonECalECut");

  ElecPtCut = (float) iConfig.getParameter<double>("ElecPtCut");
  ElecEtaCut = (float) iConfig.getParameter<double>("ElecEtaCut");
  ElecIsoCut = (float) iConfig.getParameter<double>("ElecIsoCut");
  Elecd0Cut = (float) iConfig.getParameter<double>("Elecd0Cut");

  ElectronCut = (int) iConfig.getParameter<int>("ElectronCut");
  METCut = (float) iConfig.getParameter<double>("METCut");
  JetNumCut = (unsigned) iConfig.getParameter<unsigned>("JetNumCut");
  JetPtCut = (float) iConfig.getParameter<double>("JetPtCut");
  JetEtaCut = (float) iConfig.getParameter<double>("JetEtaCut");
  JetEMFCut = (float) iConfig.getParameter<double>("JetEMFCut");

  PF2PAT_var = (int) iConfig.getParameter<int>("PF2PAT");
  //  Printing Job Configuration

  std::cout << "\n\n*****  JOB CONFIGURATION  ******\n\n";

  std::cout << "- Muon Collection Label     :   " << MuonInputTag.label() << "\n";
  std::cout << "- Electron Collection Label :   " << ElectronInputTag.label() << "\n";
  std::cout << "- Jet Collection Label      :   " << JetInputTag.label() << "\n";
  std::cout << "- MET Collection Label      :   " << MetInputTag.label() << "\n\n";

  std::cout << "***  Selection Cuts :\n\n";

  std::cout << "Muon Isolation Cut (MuonIsoCut) ";
  if ( CutsMask[0] > 0 ) 
    std::cout << "                -> ON   =  " << MuonIsoCut << "\n";
  else
    std::cout << "                -> OFF\n";

  std::cout << "Muon Pt Cut (MuonPtCut) ";
  if ( CutsMask[1] > 0 )
    std::cout << "                        -> ON   =  " << MuonPtCut << "\n";
  else
    std::cout << "                        -> OFF\n";

  std::cout << "Muon Eta Cut (MuonEtaCut) ";
  if ( CutsMask[2] > 0 )
    std::cout << "                      -> ON   =  " << MuonEtaCut << "\n";
  else
    std::cout << "                      -> OFF\n";

  std::cout << "Muon Track Chi2/DoF (MuonChiDoFCut) ";
  if ( CutsMask[3] > 0 )
    std::cout << "            -> ON   =  " << MuonChiDoFCut << "\n";
  else
    std::cout << "            -> OFF\n";

  std::cout << "Muon d0 Cut (Muond0Cut) ";
  if ( CutsMask[4] > 0 )
    std::cout << "                        -> ON   =  " << Muond0Cut << "\n";
  else
    std::cout << "                        -> OFF\n";


  std::cout << "Muon number-of-tracks Cut (MuonTrkCut) ";
  if ( CutsMask[5] > 0 )
    std::cout << "         -> ON   =  " << MuonTrkCut << "\n";
  else
    std::cout << "         -> OFF\n";


  std::cout << "Muon HCal-Energy-Deposition Cut (MuonHCalECut) ";
  if ( CutsMask[6] > 0 )
    std::cout << " -> ON   =  " << MuonHCalECut << "\n";
  else
    std::cout << " -> OFF\n";


  std::cout << "Muon ECal-Energy-Deposition Cut (MuonECalECut) ";
  if ( CutsMask[7] > 0 )
    std::cout << " -> ON   =  " << MuonECalECut << "\n";
  else
    std::cout << " -> OFF\n";

  std::cout << "\n";

  std::cout << "Electron Pt Cut (ElecPtCut)                      = " << ElecPtCut << "\n";
  std::cout << "Electron Eta Cut (ElecEtaCut)                    = " << ElecEtaCut << "\n";
  std::cout << "Electron Isolation Cut (ElecIsoCut)              = " << ElecIsoCut << "\n";
  std::cout << "Electron d0 Cut (Elecd0Cut)                      = " << Elecd0Cut << "\n";

  std::cout << "\n";

  std::cout << "Number-of-Electrons Cut (ElectronCut)            =  " << ElectronCut << "\n";
  std::cout << "MET Cut (METCut)                                 =  " << METCut << "\n";
  std::cout << "Number-of-Jets Cut (JetNumCut)                   =  " << JetNumCut << "\n";
  std::cout << "Jet Pt Cut (JetPtCut)                            =  " << JetPtCut << "\n";
  std::cout << "Jet Eta Cut (JetEtaCut)                          =  " << JetEtaCut << "\n";
  std::cout << "Jet ElectroMagnetic-Fraction Cut (JetEMFCut)     =  " << JetEMFCut << "\n";

  std::cout << "\n\n"; 

}


// ---------- The destructor -----------

SusyOSLepton::~SusyOSLepton()

{
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)
}



// ------------ method called to for each event  ------------

void SusyOSLepton::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  std::cout << "Event run : " <<  iEvent.id().run() << "\n";
  std::cout << "Event number : " << iEvent.id().event() << "\n";
  //  std::cout << "Event Lumisection : " << iEvent.id().luminosityBlock() << "\n";
  edm::Handle<std::vector<pat::Muon> > patHandle;
  iEvent.getByLabel(MuonInputTag,patHandle);

  edm::Handle<std::vector<pat::Jet> > patJHandle;
  iEvent.getByLabel(JetInputTag,patJHandle);

  edm::Handle<std::vector<pat::Electron> > patEHandle;
  iEvent.getByLabel(ElectronInputTag,patEHandle);

  edm::Handle<std::vector<pat::MET> > patMETHandle;
  iEvent.getByLabel(MetInputTag,patMETHandle);

  std::vector<pat::Muon>::const_iterator iter1; 
  std::vector<pat::Jet>::const_iterator iter2; 
  std::vector<pat::Electron>::const_iterator iter3; 
  std::vector<pat::MET>::const_iterator iter4; 
  

  reco::BeamSpot beamSpot;
  edm::Handle<reco::BeamSpot> beamSpotHandle;
  double x0 = beamSpot.x0();
  double y0 = beamSpot.y0();


  // Signal Containers

  std::vector<pat::Muon> osMuonVector;
  std::vector<pat::Jet> HighPtJetVector;
  std::vector<pat::MET>::const_iterator MET; 


  // Condition booleans

  bool osMuons = false;
  bool threeJets = false;
  bool highMET = false;
  bool zeroElec = false;

  iEvent.getByLabel("offlineBeamSpot", beamSpotHandle);
  
  if ( beamSpotHandle.isValid() )
  {
    beamSpot = *beamSpotHandle;
    
  } else
  {
    edm::LogInfo("MyAnalyzer")
      << "No beam spot available from EventSetup \n";
  }

  Tot->Fill(1,1);

  iter4 = patMETHandle->begin();

  METEtBC->Fill((*iter4).et());

  //  Loop over Muons

  int num_MuBC = 0;
  std::cout << "Muons: " << std::endl;
  for(iter1 = patHandle->begin(); iter1 != patHandle->end();++iter1){
    ++num_MuBC;
    std::cout << "\t Muon being analysed: " << num_MuBC << std::endl;

    //    if( !(muon::isGoodMuon(*iter1, pat::Muon::GlobalMuonPromptTight)) )
    if( !(muon::isGoodMuon(*iter1, muon::GlobalMuonPromptTight)) )
	continue;

    std::cout << "\t Isolation parameters, Ecal Isolation parameters: " << (*iter1).ecalIso() << " Hcal isolation parameters: " << (*iter1).hcalIso() << " Track Isolation: " << (*iter1).trackIso() << std::endl;
    std::cout << "\t Pt of the muons: " << (*iter1).pt() << " Muon Pt cut >= " << MuonPtCut << std::endl;
    float MuonIso = ((*iter1).ecalIso() + (*iter1).hcalIso() + (*iter1).trackIso())/(*iter1).pt();
    std::cout << "\t Muon Isolation: " << MuonIso << " Muon Iso Cut < " << MuonIsoCut << std::endl;
    float MuonChi2dof = (*iter1).combinedMuon()->chi2()/(*iter1).combinedMuon()->ndof();
    std::cout << "\t Muon Chi 2 dof: " << MuonChi2dof << " MuonChiDoF Cut < " << MuonChiDoFCut<< std::endl;
    float Muond0 =  (*iter1).track()->d0() - x0*sin((*iter1).track()->phi()) - y0*cos((*iter1).track()->phi());
    std::cout << "\t Muon d0: " << Muond0 << " Muon d0 cut < " << Muond0Cut << std::endl;
    std::cout << "\t Muon Eta: " << fabs((*iter1).eta()) << " Muon eta cut <= " << MuonEtaCut << std::endl;
    std::cout << "\t Muon Track Cut: " << (*iter1).track()->found() << " Muon track cut >= " << MuonTrkCut << std::endl;
    //      if( !((*iter1).hcalIsoDeposit()->candEnergy() < MuonHCalECut) )

    if(PF2PAT_var == 1){
      ////////////////////REVISAR!!!!!!!!!!!!!!!!!!!
      std::cout << "\t Muon HCalECut: " << (*iter1).pfCandidateRef().get()->hcalEnergy() << " Muon HCalEcut < " << MuonHCalECut << std::endl;
      std::cout << "\t Muon ECalECut: " << (*iter1).pfCandidateRef().get()->ecalEnergy() << " Muon ECalEcut < " << MuonECalECut << std::endl;
      MuonHCalIsoDepBC->Fill((*iter1).pfCandidateRef().get()->hcalEnergy());
      MuonECalIsoDepBC->Fill((*iter1).pfCandidateRef().get()->ecalEnergy());
    }
    else{
      std::cout << "\t Muon HCalECut: " << (*iter1).hcalIsoDeposit()->candEnergy() << " Muon HCalEcut < " << MuonHCalECut << std::endl;
      std::cout << "\t Muon ECalECut: " << (*iter1).ecalIsoDeposit()->candEnergy() << " Muon ECalEcut < " << MuonECalECut << std::endl;
      MuonECalIsoDepBC->Fill((*iter1).ecalIsoDeposit()->candEnergy());
      MuonHCalIsoDepBC->Fill((*iter1).hcalIsoDeposit()->candEnergy());
    }

    MuonIsoBC->Fill(MuonIso);
    MuonPtBC->Fill((*iter1).pt());
    MuonEtaBC->Fill((*iter1).eta());
    MuonChi2DoFBC->Fill(MuonChi2dof);
    Muond0BC->Fill(Muond0);
    MuonTrkFndBC->Fill((*iter1).track()->found());

    if( CutsMask[0] > 0 ) {
      if( !(MuonIso < MuonIsoCut) )
	continue;
    }
      
    if( CutsMask[1] > 0 ) {
      if( !((*iter1).pt() >= MuonPtCut) )
	continue;
    }
            
    if( CutsMask[2] > 0 ) {
      if( !(fabs((*iter1).eta()) <= MuonEtaCut) )
	continue;
    }
      
    if( CutsMask[3] > 0 ) {
      if( !(MuonChi2dof < MuonChiDoFCut) )
	continue;
    }
      
    if( CutsMask[4] > 0 ) {
      if( !(fabs(Muond0) < Muond0Cut) )
	continue;
    }
      
    if( CutsMask[5] > 0 ) {
      if( !((*iter1).track()->found() >= MuonTrkCut) )
	continue;
    }
            
    if( CutsMask[6] > 0 ) {
      //      if( !((*iter1).hcalIsoDeposit()->candEnergy() < MuonHCalECut) )
      if(PF2PAT_var == 1 && !((*iter1).pfCandidateRef().get()->hcalEnergy() < MuonHCalECut) )
	continue;
      else if(PF2PAT_var == 0 && !((*iter1).hcalIsoDeposit()->candEnergy() < MuonHCalECut) )
	continue;
    }
      
    if( CutsMask[7] > 0 ) {
      //      if( !((*iter1).ecalIsoDeposit()->candEnergy() < MuonECalECut) )
      if(PF2PAT_var == 1 && !((*iter1).pfCandidateRef().get()->ecalEnergy() < MuonECalECut) )
	continue;
      else if (PF2PAT_var == 0 && !((*iter1).hcalIsoDeposit()->candEnergy() < MuonECalECut))
	continue;
    }

    std::cout << "\t This muon passed all cuts.\n"; 
    osMuonVector.push_back((*iter1));


  }

  //  End loop over Muons

  std::cout << "Number of muons before cuts: " << num_MuBC << std::endl;
  std::cout << "Number of muons after cuts: " << osMuonVector.size() << "\n";

  NumberOfMuonsBC->Fill(num_MuBC);
  NumberOfMuonsAC->Fill(osMuonVector.size());

  // Oposite-sign Muons condition

  int charge = 1;

  if ( osMuonVector.size() == 2 ) {
    std::vector<pat::Muon>::const_iterator it;
    for (it = osMuonVector.begin(); it != osMuonVector.end(); ++it)
      charge *= (*it).charge();
    if ( charge == -1) {
      osMuons = true;
      std::cout << "\t\t Two muons passed and they have opposite sign. " << std::endl;
    }
  }
  if(!osMuons)
    std::cout << "\t\t There were not two opposite sign muons." << std::endl;

  // Zero Electrons Condition

  int numElec = 0;
  std::cout << "Electrons: " << std::endl;
  for(iter3 = patEHandle->begin(); iter3 != patEHandle->end(); ++iter3) {

    if ( !((*iter3).electronID("eidRobustTight")) )
      continue;


    float ElecIso = ((*iter3).ecalIso() + (*iter3).hcalIso() + (*iter3).trackIso())/(*iter3).et();
    float Elecd0 =  (*iter3).gsfTrack()->d0() - x0*sin((*iter3).gsfTrack()->phi()) - y0*cos((*iter3).gsfTrack()->phi());

    std::cout << "\t The electron is a eidRobustTight" << std::endl;
    std::cout << "\t The electron ecal Iso: " << (*iter3).ecalIso() << " electron hcal iso " << (*iter3).hcalIso() << " electron track iso= " << (*iter3).trackIso() << " electron transverse energy: " << (*iter3).et() << std::endl;
    std::cout << "\t The electron iso = " << ElecIso << " Electron IsO cut < " << ElecIsoCut << std::endl;
    std::cout << "\t The electron d0 = " << fabs(Elecd0) << " Electron d0 cut < " << Elecd0Cut << std::endl;
    std::cout << "\t The electron pt = " << (*iter3).pt() << " Electron pt cut >= " << ElecPtCut << std::endl;
    std::cout << "\t The electron eta = " << (*iter3).eta() << " Electron eta cut <= " << ElecEtaCut << std::endl;

    if ( !((*iter3).pt() >= ElecPtCut) )
      continue;

    if ( !((*iter3).eta() <= ElecEtaCut) )
      continue;

    if ( !(ElecIso < ElecIsoCut) )
      continue;

    if ( !(fabs(Elecd0) < Elecd0Cut) )
      continue; 

    numElec++;
    std::cout << "\t\t Number of electrons that have passed the cuts " << numElec << std::endl;
  }

  std::cout << "\t\t Number of electrons that should passed the cuts " << ElectronCut << std::endl;

  if ( numElec == ElectronCut ) zeroElec = true; 

  std::cout << "MET:\n";
  // High MET Condition

  iter4 = patMETHandle->begin();
  if ( (*iter4).et() > METCut ) {
    highMET = true;
    MET = iter4;
  }
  std::cout << "\t Missing energy before cuts " << (*iter4).et() << " Metcut > " << METCut<< std::endl;
  if(highMET)
    std::cout << "\t\t MET accepted " << std::endl;
  else
    std::cout << "\t\t Not enough MET\n";

  // More than three high-pt Jets Condition

  int num_jetBC = 0;
  
  std::cout << "Jets: \n ";
  for ( iter2 = patJHandle->begin(); iter2 != patJHandle->end(); ++iter2) {
    ++num_jetBC;
    std::cout << "\t Jet number " << num_jetBC << "\n";
    float emf = 0;
    if(PF2PAT_var == 1){
      std::cout << "\t Jet neutral Em Energy: " << (*iter2).neutralEmEnergy() << " charged em Energy: " << (*iter2).chargedEmEnergy() << " neutral Hadron Energy: " << (*iter2).neutralHadronEnergy() << " charged hadron energy: " << (*iter2).chargedHadronEnergy() << std::endl;
      emf = ((*iter2).neutralEmEnergy()+(*iter2).chargedEmEnergy())/((*iter2).neutralEmEnergy()+(*iter2).chargedEmEnergy()+(*iter2).neutralHadronEnergy()+(*iter2).chargedHadronEnergy());
    }
    else{
      emf = (*iter2).emEnergyFraction(); 
    }

    JetPtBC->Fill((*iter2).pt());
    JetEtaBC->Fill((*iter2).eta());
    JetEMFBC->Fill(emf);

    std::cout << "\t Jet emEFraction: " << emf << " Jet EMEF cut >= "<< JetEMFCut << "\n";
    std::cout << "\t Jet pt: " << (*iter2).pt() << " Jet Pt cut >= "<< JetPtCut << "\n";
    std::cout << "\t Jet eta: " << (*iter2).eta() << " Jet Eta cut <= "<< JetEtaCut << "\n";
    if( (*iter2).pt() >= JetPtCut && fabs((*iter2).eta()) <= JetEtaCut && emf >= JetEMFCut ) {
      HighPtJetVector.push_back((*iter2));

    }
  }
  std::cout << "\t\t Number of jets " << HighPtJetVector.size() << " , jets needed for an event to pass >= " << JetNumCut << "\n";
  if ( HighPtJetVector.size() >= JetNumCut ) threeJets = true;
  
  NumberOfJetsBC->Fill(num_jetBC);
  NumberHighPtJets->Fill(HighPtJetVector.size());


  // Some combinations of cuts ...

  if ( osMuons && zeroElec )
    OSMnoE_Only->Fill(1,1);

  if ( osMuons && zeroElec && threeJets )
    OSMnoE_3J->Fill(1,1);

  
  //... Final decision ... then do physics !

  if ( osMuons && threeJets && highMET && zeroElec ) {

    ++passCount;

    Pass->Fill(1,1);
    NumberOfJetsAC->Fill(HighPtJetVector.size());

    int MuonCount = 0;

    std::vector<pat::Muon>::const_iterator MuVecIt;

    for( MuVecIt = osMuonVector.begin(); ( MuVecIt != osMuonVector.end() && MuonCount < 2 ); ++MuVecIt  ) {

      MuonPt[MuonCount]->Fill((*MuVecIt).pt());
      MuonEta[MuonCount]->Fill(fabs((*MuVecIt).eta()));

      float iso = ((*MuVecIt).ecalIso() + (*MuVecIt).hcalIso() + (*MuVecIt).trackIso())/(*MuVecIt).pt();      
      MuonIso[MuonCount]->Fill(iso);

      float chi2dof = (*MuVecIt).combinedMuon()->chi2()/(*MuVecIt).combinedMuon()->ndof();
      MuonChiDoF[MuonCount]->Fill(chi2dof);

      float d0 =  (*MuVecIt).track()->d0() - x0*sin((*MuVecIt).track()->phi()) - y0*cos((*MuVecIt).track()->phi());
      Muond0[MuonCount]->Fill(d0);

      MuonValidHits[MuonCount]->Fill((*MuVecIt).track()->found());
      MuonHCalE[MuonCount]->Fill((*MuVecIt).hcalIsoDeposit()->candEnergy());
      MuonECalE[MuonCount]->Fill((*MuVecIt).ecalIsoDeposit()->candEnergy());
      
      ++MuonCount;
      
    }
    
    
    unsigned JetCount = 0;
    
    std::vector<pat::Jet> ::const_iterator JetVecIt;
    
    for ( JetVecIt = HighPtJetVector.begin(); (JetVecIt != HighPtJetVector.end() && JetCount < JetNumCut); ++JetVecIt  ) {
      
      JetPt[JetCount]->Fill((*JetVecIt).pt());
      JetEta[JetCount]->Fill(fabs((*JetVecIt).eta()));
      JetEMF[JetCount]->Fill((*JetVecIt).emEnergyFraction());
      
      ++JetCount;
      
    }
    
    METEt->Fill((*MET).et());
    
  }
  
  // End Final decision
  
  
  osMuonVector.clear();
  HighPtJetVector.clear();   
  
  
}       //  End Analize method





// ------------ method called once each job just before starting event loop  ------------


void SusyOSLepton::beginJob(const edm::EventSetup&)

{

  passCount = 0;

  edm::Service<TFileService> fservice;

  Pass = fservice->make<TH1I>("PassEvents","Total number of accepted Events",2,0,2);
  Tot = fservice->make<TH1I>("TotalEvents","Total number of events",2,0,2);
  NumberOfJetsBC = fservice->make<TH1I>("NumberOfJetsBC","Number of jets per event before muon cuts", 50, 0, 50); 
  NumberOfMuonsBC = fservice->make<TH1I>("NumberOfMuonsBC","Number of Muons per event before muon cuts",15, 0, 15);  
  OSMnoE_Only = fservice->make<TH1I>("OSMnoE","Total number of events with OS_Muon pairs",2,0,2);
  OSMnoE_3J = fservice->make<TH1I>("OSMnoE_3J","Total number of events with OS_Muons and 3 Jets",2,0,2);

  MuonIsoBC = fservice->make<TH1F>("MuonIsoBC","Muon Isolation before muon cuts",30,0.0,30.0);
  MuonPtBC = fservice->make<TH1F>("MuonPtBC","Muon Pt before muon cuts",120,0.0,200.0);
  MuonEtaBC = fservice->make<TH1F>("MuonEtaBC","Muon Eta before muon cuts",120,-3.0,3.0);
  MuonChi2DoFBC = fservice->make<TH1F>("MuonChi2DoFBC","Muon Track Chi2/DoF before muon cuts",120,0.0,12.0);
  Muond0BC = fservice->make<TH1F>("Muond0BC","Muon d0 before muon cuts",80,0.0,0.2);
  MuonTrkFndBC = fservice->make<TH1F>("MuonTrkFndBC","Muon Track Found before muon cuts",50,0.0,50.0);
  MuonHCalIsoDepBC = fservice->make<TH1F>("MuonHCalIsoDepBC","Muon HCal Iso Deposit before muon cuts",100,0.0,20.0);
  MuonECalIsoDepBC = fservice->make<TH1F>("MuonECalIsoDepBC","Muon ECal Iso Deposit before muon cuts",100,0.0,10.0);

  JetPtBC = fservice->make<TH1F>("JetPtBC","Jet Pt before cuts",120,0.0,200.0);
  JetEtaBC = fservice->make<TH1F>("JetEtaBC","Jet Eta before cuts",120,-3.0,3.0);
  JetEMFBC = fservice->make<TH1F>("JetEMFBC","Jet EMF before cuts",120,0.0,1.2);

  NumberOfJetsAC = fservice->make<TH1I>("NumberOfJetsAC","Number of jets per event after all cuts", 12, 0, 12); 
  NumberOfMuonsAC = fservice->make<TH1I>("NumberOfMuonsAC","Number of Muons per event after muon cuts",5,0,5);
  NumberHighPtJets = fservice->make<TH1I>("NumberHighPtJets","Number of High Pt Jets per event after muon cuts",15,0,15);

  for (int i = 1; i <= 2; i++) {

    std::ostringstream tag1;
    std::ostringstream name1;
    tag1 << "Muon_" << std::setw(1) << std::setfill('0') << i << "_Pt";
    name1 << "Muon No. " << i << ", Pt";
    MuonPt.push_back(fservice->make<TH1F>(tag1.str().c_str(),name1.str().c_str(),100,0.0,400.0));

    std::ostringstream tag2;
    std::ostringstream name2;
    tag2 << "Muon_" << std::setw(1) << std::setfill('0') << i << "_Eta";
    name2 << "Muon No. " << i << ", Eta";
    MuonEta.push_back(fservice->make<TH1F>(tag2.str().c_str(),name2.str().c_str(),60,0.0,3.0));

    std::ostringstream tag3;
    std::ostringstream name3;
    tag3 << "Muon_" << std::setw(1) << std::setfill('0') << i << "_Isolation";
    name3 << "Muon No. " << i << ", Isolation";
    MuonIso.push_back(fservice->make<TH1F>(tag3.str().c_str(),name3.str().c_str(),80,0.0,0.2));

    std::ostringstream tag5;
    std::ostringstream name5;
    tag5 << "Muon_" << std::setw(1) << std::setfill('0') << i << "_d0";
    name5 << "Muon No. " << i << ", d0";
    Muond0.push_back(fservice->make<TH1F>(tag5.str().c_str(),name5.str().c_str(),100,0.0,0.2));

    std::ostringstream tag6;
    std::ostringstream name6;
    tag6 << "Muon_" << std::setw(1) << std::setfill('0') << i << "_Chi2DoF";
    name6 << "Muon No. " << i << ", Chi2/DoF";
    MuonChiDoF.push_back(fservice->make<TH1F>(tag6.str().c_str(),name6.str().c_str(),100,0.0,10.0));

    std::ostringstream tag7;
    std::ostringstream name7;
    tag7 << "Muon_" << std::setw(1) << std::setfill('0') << i << "_ValidHits";
    name7 << "Muon No. " << i << ", Valid Hits";
    MuonValidHits.push_back(fservice->make<TH1F>(tag7.str().c_str(),name7.str().c_str(),50,0.0,50.0));

    std::ostringstream tag8;
    std::ostringstream name8;
    tag8 << "Muon_" << std::setw(1) << std::setfill('0') << i << "_HCalE";
    name8 << "Muon No. " << i << ", HCal Energy";
    MuonHCalE.push_back(fservice->make<TH1F>(tag8.str().c_str(),name8.str().c_str(),100,0.0,10.0));

    std::ostringstream tag9;
    std::ostringstream name9;
    tag9 << "Muon_" << std::setw(1) << std::setfill('0') << i << "_ECalE";
    name9 << "Muon No. " << i << ", ECal Energy";
    MuonECalE.push_back(fservice->make<TH1F>(tag9.str().c_str(),name9.str().c_str(),180,0.0,3.0));

  }


  for ( int i = 1; i <= 3; i++ ) {

    std::ostringstream tag1;
    std::ostringstream name1;
    tag1 << "Jet_" << std::setw(1) << std::setfill('0') << i << "_Pt";
    name1 << "Jet No. " << i << ", Pt";
    JetPt.push_back(fservice->make<TH1F>(tag1.str().c_str(),name1.str().c_str(),100,0.0,800.0));

    std::ostringstream tag2;
    std::ostringstream name2;
    tag2 << "Jet_" << std::setw(1) << std::setfill('0') << i << "_Eta";
    name2 << "Jet No. " << i << ", Eta";
    JetEta.push_back(fservice->make<TH1F>(tag2.str().c_str(),name2.str().c_str(),60,0.0,3.0));

    std::ostringstream tag3;
    std::ostringstream name3;
    tag3 << "Jet_" << std::setw(1) << std::setfill('0') << i << "_EMF";
    name3 << "Jet No. " << i << ", ElectroMagnetic Fraction";
    JetEMF.push_back(fservice->make<TH1F>(tag3.str().c_str(),name3.str().c_str(),120,0.0,1.2));

  }

  METEtBC = fservice->make<TH1F>("METEtBC","MET Et Before Muon Cuts",100,0.0,1000.0);
  METEt = fservice->make<TH1F>("METEt","MET Muon Et",100,0.0,1000.0);



}



// ------------ method called once each job just after ending the event loop  ------------

void SusyOSLepton::endJob() 

{


}

//define this as a plug-in
DEFINE_FWK_MODULE(SusyOSLepton);
