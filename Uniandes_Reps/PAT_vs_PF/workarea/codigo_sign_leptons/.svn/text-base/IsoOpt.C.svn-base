////Root includes
#include "Riostream.h"
#include <math.h>
#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TFolder.h"
#include "TGraph.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH2.h"
#include "TStyle.h"
#include "TMath.h"
#include "TCanvas.h"

///Class Definition
class IsolOpt {
public :
  TTree  *fChain;   //!pointer to the analyzed TTree or TChain 
  Int_t  fCurrent; //!current Tree number in a TChain

  // Declaration of leaf types
  UInt_t          pfNel;
  UInt_t          Npfmu;

  Double_t        pfelPt[30];   //[Nel]
  Double_t        pfelPhi[30];   //[Nel]
  Double_t        pfelEta[30];   //[Nel]
  Double_t        pfelhoe[30];   //[Nel]

  Double_t        elIsoGamma[30];   //[Nel]
  Double_t        elIsoNHad[30];   //[Nel]
  Double_t        elIsoChHad[30];   //[Nel]

  Double_t        pfelDrMuon[30];   //[Nel]
  Double_t        pfelIdLoose[30];   //[Nel]
  Double_t        pfelIdTight[30];   //[Nel]
  Double_t        pfelIdRobLoose[30];   //[Nel]
  Double_t        pfelIdRobTight[30];   //[Nel]
  Double_t        pfelIdPfpi[30];   //[Nel]
  Double_t        pfelGsfCharge[30];   //[Nel]
  Double_t        pfelKfCharge[30];   //[Nel]
  Double_t        pfelD0[30];   //[Nel]
  //  Double_t        pfeldd0[30];   //[Nel]
  Double_t        pfeldd0x[30];   //[Nel]
  Double_t        pfeldd0y[30];   //[Nel]
  Double_t        pfelz0[30];   //[Nel]

  Double_t        pfelMC[30];   //[Nel]

  Double_t        pfmuPt[30];   //[Nmu]
  Double_t        pfmuPhi[30];   //[Nmu]
  Double_t        pfmuEta[30];   //[Nmu]

  Double_t        muIsoGamma[30];   //[Nmu]
  Double_t        muIsoNHad[30];   //[Nmu]
  Double_t        muIsoChHad[30];   //[Nmu]
  
  Double_t        pfmuDrElec[30];   //[Nmu]
  Double_t        pfmuIdGlobalTight[30];   //[Nmu]
  Double_t        pfmuIsGlobal[30];   //[Nmu]
  Double_t        pfmuCharge[30];   //[Nmu]
  Double_t        pfmuD0[30];   //[Nmu]
  //  Double_t        pfmudd0[30];   //[Nel]
  Double_t        pfmudd0x[30];   //[Nel]
  Double_t        pfmudd0y[30];   //[Nel]
  Double_t        pfmuz0[30];   //[Nel]
  Double_t        pfmuTkHits[30];   //[Nmu]
  Double_t        pfmuGlobChi2[30];   //[Nmu]
  Double_t        pfmuMC[30];   //[Nmu]

  int          pfNchhad;
  UInt_t          pfNnehad;
  UInt_t          pfNpho;

  //  Double_t       pfchhadD0[300];
  Double_t       pfchhadD0x[300];
  Double_t       pfchhadD0y[300];
  Double_t       pfchhadZ0[300];
  Double_t       pfchhadeta[300];
  Double_t       pfchhadphi[300];
  Double_t       pfchhadpt[300];

  //  Double_t       pfnehadD0[250];
  Double_t       pfnehadD0x[250];
  Double_t       pfnehadD0y[250];
  Double_t       pfnehadZ0[250];
  Double_t       pfnehadeta[250];
  Double_t       pfnehadphi[250];
  Double_t       pfnehadpt[250];

  //  Double_t       pfphoD0[400];
  Double_t       pfphoD0x[400];  
  Double_t       pfphoD0y[400];
  Double_t       pfphoZ0[400];
  Double_t       pfphoeta[400];
  Double_t       pfphophi[400];
  Double_t       pfphopt[400];

  // Pointers to the Branches
  TBranch  *b_pfNel;
  TBranch  *b_Npfmu;

  TBranch        *b_pfelPt;   //!
  TBranch        *b_pfelPhi;   //!
  TBranch        *b_pfelEta;   //!
  TBranch        *b_pfelhoe;   //!

  TBranch        *b_elIsoGamma;   //!
  TBranch        *b_elIsoNHad;   //!
  TBranch        *b_elIsoChHad;   //!
  
  TBranch        *b_pfelDrMuon;   //!
  TBranch        *b_pfelIdLoose;   //!
  TBranch        *b_pfelIdTight;   //!
  TBranch        *b_pfelIdRobLoose;   //!
  TBranch        *b_pfelIdRobTight;   //!
  TBranch        *b_pfelIdPfpi;   //!
  TBranch        *b_pfelGsfCharge;   //!
  TBranch        *b_pfelKfCharge;   //!
  TBranch        *b_pfelD0;   //!
  //  TBranch        *b_pfeldd0;   //!
  TBranch        *b_pfeldd0x;   //!
  TBranch        *b_pfeldd0y;   //!
  TBranch        *b_pfelz0;   //!

  TBranch        *b_pfelMC;   //!

  TBranch        *b_pfmuPt;   //!
  TBranch        *b_pfmuPhi;   //!
  TBranch        *b_pfmuEta;   //!
  
  TBranch        *b_muIsoGamma;   //!
  TBranch        *b_muIsoNHad;   //!
  TBranch        *b_muIsoChHad;   //!
  
  TBranch        *b_pfmuDrElec;   //!
  TBranch        *b_pfmuIdGlobalTight;   //!
  TBranch        *b_pfmuIsGlobal;   //!
  TBranch        *b_pfmuCharge;   //!
  TBranch        *b_pfmuD0;   //!
  //  TBranch        *b_pfmudd0;   //!
  TBranch        *b_pfmudd0x;   //!
  TBranch        *b_pfmudd0y;   //!
  TBranch        *b_pfmuz0;   //!
  TBranch        *b_pfmuTkHits;   //!
  TBranch        *b_pfmuGlobChi2;   //!

  TBranch        *b_pfmuMC;   //!

  TBranch       *b_pfNchhad;
  TBranch       *b_pfNnehad;
  TBranch       *b_pfNpho;

  //  TBranch       *b_pfchhadD0;
  TBranch       *b_pfchhadD0x;
  TBranch       *b_pfchhadD0y;
  TBranch       *b_pfchhadZ0;
  TBranch       *b_pfchhadeta;
  TBranch       *b_pfchhadphi;
  TBranch       *b_pfchhadpt;

  //  TBranch       *b_pfnehadD0;
  TBranch       *b_pfnehadD0x;
  TBranch       *b_pfnehadD0y;
  TBranch       *b_pfnehadZ0;
  TBranch       *b_pfnehadeta;
  TBranch       *b_pfnehadphi;
  TBranch       *b_pfnehadpt;

  //  TBranch       *b_pfphoD0;
  TBranch       *b_pfphoD0x;
  TBranch       *b_pfphoD0y;
  TBranch       *b_pfphoZ0;
  TBranch       *b_pfphoeta;
  TBranch       *b_pfphophi;
  TBranch       *b_pfphopt;
  
//functions, constructors and destructors
  
  IsolOpt(TTree *tree=0);

  virtual ~IsolOpt();

  virtual Int_t    GetEntry(Long64_t entry);
  virtual Long64_t LoadTree(Long64_t entry);
  virtual void     Init(TTree *tree);
  virtual void     Loop();
  //  virtual void     PFLoop();
  virtual Bool_t   Notify();
  virtual void     Show(Long64_t entry = -1);

  float dzero(float, float);

  //output file
  TFile *f2;


};

int main(int argc, char *argv[]){
  std::cout << "Begining!!!!" << std::endl;
  std::cout << "input : " << argv[1] <<  std::endl;
  TFile * f1 = new TFile(argv[1]);
  f1->cd("demo");
  TTree * g1 = (TTree*)gDirectory->FindObjectAny("allData");
  IsolOpt * iso = new IsolOpt(g1);
  iso->Loop();
  return 0;
}

void IsolOpt::Loop(){

  ///Histograms for muons and electrons

  TH1F* pfnmu = new TH1F("pfnmu","pfnmu",20, 0,20);
  TH1F* pfnel = new TH1F("pfnel","pfnel",20, 0,20);

  TH1F* recmvapfEl[3][10]; 
  TH1F* recmvapfEls[3]; 

  TH1F* rechoepfEl[3][10]; 
  TH1F* rechoepfEls[3]; 

  TH1F* elIsoDR[4][10];

  TH2F* recDRpfEl[3][4][10];
  TH2F* recDRpfMu[3][4][10];

  TH2F* recDRpfEls[3][4]; 
  TH2F* recDRpfMus[3][4]; 

  TH2F* sigDRpfEl[4][10];
  TH2F* sigDRpfMu[4][10];

  TH2F* sigDRpfEls[4]; 
  TH2F* sigDRpfMus[4]; 

  TH1F* effmvaEl[3][10]; 
  TH1F* effmvaEls[3];

  TH1F* sigmvapfel[10];
  TH1F* sigmvapfels; 

  TH1F* sighoepfel[10];
  TH1F* sighoepfels; 

  TH1F* intsigmvapfel[10];
  TH1F* intsigmvapfels; 

  TH1F* optmvaEffEls;
  TH1F* optDRMu;
  TH1F* optDREl;

  string mc[3] ={"prompt","fake","HF"};
  string pfisol[4] ={"_ChHad_","_NeHad_","_Gam_","_tot_"}; 
  char opt[20];

  ///creating histograms

  //  for (int i2=0; i2<4; i2++){

  optmvaEffEls = new TH1F("optMVAcut","optimal MVA cut for electrons id",10,0,30);
  optDRMu = new TH1F("optDRMucut","optimal DR cut for muons isolation",10,0,30);
  optDREl = new TH1F("optDRElcut","optimal DR cut for electrons isolation",10,0,30);

  sigmvapfels = new TH1F("sigmvapfel","ratio s/b mva for pf electrons",28,-0.2,1);
  sighoepfels = new TH1F("sighoepfel","ratio s/b hoe for pf electrons",500,0,0.1);
  intsigmvapfels = new TH1F("intsigmvapfel","integrated ratio s/b mva for pf electrons",28,-0.2,1.2);

  int isop = 100;
  float step = (float)1/isop;
  for(int i1 = 0; i1 < 3; i1++){
    for (int i2=0; i2<4; i2++){
      for (int i3=0; i3<10; i3++){
	if(i1 == 0 && i2 == 0){
	  sprintf(opt,"%s%d","Signelemva_",i3);
	  sigmvapfel[i3] = new TH1F(opt,opt,28,-0.2,1);
	  sprintf(opt,"%s%d","Signelehoe_",i3);
	  sighoepfel[i3] = new TH1F(opt,opt,500,0,0.1);
	  sprintf(opt,"%s%d","IntSignelemva_",i3);
	  intsigmvapfel[i3] = new TH1F(opt,opt,28,-0.2,1.2);
	}
	if(i2==0){
	  sprintf(opt,"%s%s%d","numberelemva_",mc[i1].c_str(),i3);
	  recmvapfEl[i1][i3] = new TH1F(opt,opt,28,-0.2,1);
	  sprintf(opt,"%s%s%d","mvaeffel_",mc[i1].c_str(),i3);
	  effmvaEl[i1][i3] = new TH1F(opt,opt,28,-0.2,1); 
	  sprintf(opt,"%s%s%d","numberelehoe_",mc[i1].c_str(),i3);
	  rechoepfEl[i1][i3] = new TH1F(opt,opt,500,0,0.1);
	}
	if(i1==0){
	  sprintf(opt,"%s%s%d","sigeleDR_",pfisol[i2].c_str(),i3);
	  sigDRpfEl[i2][i3] = new TH2F(opt,opt,isop+1,0,1,500,0,500);
	  sprintf(opt,"%s%s%d","sigmuonDR_",pfisol[i2].c_str(),i3);
	  sigDRpfMu[i2][i3] = new TH2F(opt,opt,isop+1,0,1,500,0,500);
	  sprintf(opt,"%s%s%d","ElectronIsolationDR_",pfisol[i2].c_str(),i3);
	  elIsoDR[i2][i3] = new TH1F(opt,opt,isop+1,0,1);
	}
	sprintf(opt,"%s%s%s%d","numbereleDR_",mc[i1].c_str(),pfisol[i2].c_str(),i3);
	recDRpfEl[i1][i2][i3] = new TH2F(opt,opt,isop+1,0,1,500,0,500);
	sprintf(opt,"%s%s%s%d","numbermuonDR_",mc[i1].c_str(),pfisol[i2].c_str(),i3);
	recDRpfMu[i1][i2][i3] = new TH2F(opt,opt,isop+1,0,1,500,0,500);
      }
      if(i2 == 0){
	sprintf(opt,"%s%s","numberelemva_",mc[i1].c_str());
	recmvapfEls[i1] = new TH1F(opt,opt,28,-0.2,1); 
	sprintf(opt,"%s%s","mvaeffel_",mc[i1].c_str());
	effmvaEls[i1] = new TH1F(opt,opt,28,-0.2,1); 
	sprintf(opt,"%s%s","numberelehoe_",mc[i1].c_str());
	rechoepfEls[i1] = new TH1F(opt,opt,500,0,0.1); 
      }
      if(i1==0){
	sprintf(opt,"%s%s","sigeleDR_",pfisol[i2].c_str());
	sigDRpfEls[i2] = new TH2F(opt,opt,isop+1,0,1,500,0,500);
	sprintf(opt,"%s%s","sigmuonDR_",pfisol[i2].c_str());
	sigDRpfMus[i2] = new TH2F(opt,opt,isop+1,0,1,500,0,500);
      }
      sprintf(opt,"%s%s%s","numbereleDR_",mc[i1].c_str(),pfisol[i2].c_str());
      recDRpfEls[i1][i2] = new TH2F(opt,opt,isop+1,0,1,500,0,500); 
      sprintf(opt,"%s%s%s","numbermuonDR_",mc[i1].c_str(),pfisol[i2].c_str());
      recDRpfMus[i1][i2] = new TH2F(opt,opt,isop+1,0,1,500,0,500); 
    }
  }

  ///getting the entries
  if (fChain == 0) return; 
  Long64_t nentries = fChain->GetEntriesFast();   
  cout<<"EVENTS "<< nentries<<endl; 
  Long64_t nbytes = 0, nb = 0; 
  //  int srfel = 0;
  int pffel = 0;
  ////Loop over the tree
  for (Long64_t jentry=0; jentry<nentries; jentry++) {
    if (jentry%1000 ==0) cout<<jentry<<" EVENTS ANALYZED"<<endl; 
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;      
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    
    //number of lepton histograms 

    pfnmu->Fill(Npfmu);  
    pfnel->Fill(pfNel);           
    //// loop over electrons
    for (int ie=0; ie< (int)pfNel; ie++){
      unsigned int imc = 4;
      if (pfelMC[ie]==0){
	imc=1; 
	pffel++;
      }
      else if (fabs(pfelMC[ie])==2) imc=0;   
      else if (fabs(pfelMC[ie])==3) imc=2;
      else if (imc==4) continue;
      if (pfelPt[ie]>30) continue; //PT cut
      if (fabs(pfelEta[ie])>2.4) continue; //eta cut 
      if (fabs(dzero(pfelD0[ie],pfelPhi[ie]))>0.2) continue;
      //if (pfelIdRobTight[ie]<0.1) continue;
      if (pfelGsfCharge[ie]*pfelKfCharge[ie]<1) continue;
      if(pfelhoe[ie] > 0.006) continue;
      //if(pfelIdPfpi[ie] < 0.6 || pfelIdPfpi[ie] > 1) continue;
      int ptb=int(pfelPt[ie]/3);
      if (ptb>9) continue;
      recmvapfEl[imc][ptb]->Fill(pfelIdPfpi[ie]);
      rechoepfEl[imc][ptb]->Fill(pfelhoe[ie]);
      if(pfelPt[ie]>2 && pfelPt[ie]<30){
      	recmvapfEls[imc]->Fill(pfelIdPfpi[ie]);
      	rechoepfEls[imc]->Fill(pfelhoe[ie]);
      }
      //      if(imc == 0){
      int pfch = pfNchhad;
      int pfne = pfNchhad;
      int pfpho = pfNchhad;
      double dz0;
      double dd0;
      double dphi;
      double delr;
      double pi=3.1415926536;
      double isodep1[isop+1], isodep2[isop+1], isodep3[isop+1];

      for(int k=0;k<isop+1;k++){
	isodep1[k]=0;
	isodep2[k]=0;
	isodep3[k]=0;
      }

      for(int cch=0; cch<pfch; cch++){
	dz0=fabs(pfchhadZ0[cch]-pfelz0[ie]);
	dd0 = sqrt( (pfeldd0x[ie]-pfchhadD0x[cch])*(pfeldd0x[ie]-pfchhadD0x[cch]) + (pfeldd0y[ie]-pfchhadD0y[cch])*(pfeldd0y[ie]-pfchhadD0y[cch]) );
	dphi = pfelPhi[ie]-pfchhadphi[cch];
	if (dphi > pi)
	  dphi=2*pi-dphi;
	delr = sqrt( (pfelEta[ie]-pfchhadeta[cch])*(pfelEta[ie]-pfchhadeta[cch]) + dphi*dphi );
	if(dz0 < 0.2 && dd0 < 0.1 && pfchhadpt[cch] > 0 && delr > 1e-05){
	  for(int k=0;k<isop+1;k++){
	    if(delr < step*(k+1)){	    
	      isodep1[k] = isodep1[k] + pfchhadpt[cch];
	    }
	  }
	}
      }

      for(int k=0;k<isop+1;k++){
	//	cout << "accepted!!! isolation value until that cone: "  <<  isodep1[k] << " k: " << k << " step: " << step*((double)k+1.0) << endl;
	if(pfelPt[ie]>2 && pfelPt[ie]<30)
	  recDRpfEls[imc][0]->Fill(step*(k+1),isodep1[k]);
	recDRpfEl[imc][0][ptb]->Fill(step*(k+1),isodep1[k]);
	elIsoDR[0][ptb]->Fill(step*(k+1),isodep1[k]);
      }
      for(int cch=0; cch<pfne; cch++){
	dz0=fabs(pfnehadZ0[cch]-pfelz0[ie]);
	dd0 = sqrt( (pfeldd0x[ie]-pfnehadD0x[cch])*(pfeldd0x[ie]-pfnehadD0x[cch]) + (pfeldd0y[ie]-pfnehadD0y[cch])*(pfeldd0y[ie]-pfnehadD0y[cch]) );
	dphi = pfelPhi[ie]-pfnehadphi[cch];
	if (dphi > pi)
	  dphi=2*pi-dphi;
	delr = sqrt( (pfelEta[ie]-pfnehadeta[cch])*(pfelEta[ie]-pfnehadeta[cch]) + dphi*dphi );
	if(dz0 < 0.2 && dd0 < 0.1 && pfnehadpt[cch] > 0 && delr > 1e-05){
	  for(int k=0;k<isop+1;k++){
	    if(delr < step*(k+1)){	    
	      isodep2[k] = isodep2[k] + pfnehadpt[cch];
	    }
	  }
	}
      }
      //      cout << "Normal neutral Had Isolation: " << elIsoNHad[ie] << " calculated neutral Had deposits: " << isodep[9] << endl;
      for(int k=0;k<isop+1;k++){
	if(pfelPt[ie]>2 && pfelPt[ie]<30)
	  recDRpfEls[imc][1]->Fill(step*((double)k+1.),isodep2[k]);
	recDRpfEl[imc][1][ptb]->Fill(step*((double)k+1.),isodep2[k]);
	elIsoDR[1][ptb]->Fill(step*((double)k+1.),isodep2[k]);
      }
      for(int cch=0; cch<pfpho; cch++){
	dz0=fabs(pfphoZ0[cch]-pfelz0[ie]);
	dd0 = sqrt( (pfeldd0x[ie]-pfphoD0x[cch])*(pfeldd0x[ie]-pfphoD0x[cch]) + (pfeldd0y[ie]-pfphoD0y[cch])*(pfeldd0y[ie]-pfphoD0y[cch]) );
	dphi = pfelPhi[ie]-pfphophi[cch];
	if (dphi > pi)
	  dphi=2*pi-dphi;
	delr = sqrt( (pfelEta[ie]-pfphoeta[cch])*(pfelEta[ie]-pfphoeta[cch]) + dphi*dphi );
	if(dz0 < 0.2 && dd0 < 0.1 && pfphopt[cch] > 0 && delr > 1e-05){
	  for(int k=0;k<isop+1;k++){
	    if(delr < step*(k+1)){	    
	      isodep3[k] = isodep3[k] + pfphopt[cch];
	    }
	  }
	}
      }
      //      cout << "Normal Ch Had Isolation: " << elIsoChHad[ie] << " calculated Ch Had deposits: " << isodep[9] << endl;
      for(int k=0;k<isop+1;k++){
	if(pfelPt[ie]>2 && pfelPt[ie]<30){
	  recDRpfEls[imc][2]->Fill(step*(k+1),isodep3[k]);
	  recDRpfEls[imc][3]->Fill(step*(k+1),isodep1[k]+isodep2[k]+isodep3[k]);
	}
	recDRpfEl[imc][2][ptb]->Fill(step*(k+1),isodep3[k]);
	elIsoDR[2][ptb]->Fill(step*(k+1),isodep3[k]);
	recDRpfEl[imc][3][ptb]->Fill(step*(k+1),isodep1[k]+isodep2[k]+isodep3[k]);
	elIsoDR[3][ptb]->Fill(step*(k+1),isodep1[k]+isodep2[k]+isodep3[k]);
      }
      //      }
    }

    for (int im=0; im< (int)Npfmu; im++){
      unsigned int imcm = 4;
      if (pfmuMC[im]==0) imcm=1; 
      else if (fabs(pfmuMC[im])==2) imcm=0;   
      else if (fabs(pfmuMC[im])==3) imcm=2;
      else if (imcm==4) continue;
      if (pfmuPt[im]>30) continue; //PT cut
      if (fabs(pfmuEta[im])>2.4) continue; //eta cut 
      if (fabs(dzero(pfmuD0[im],pfmuPhi[im]))>0.2) continue;
      //if (pfmuIdGlobalTight[im]<0.1) continue;
      if (pfmuGlobChi2[im]>=10) continue;
      if (pfmuTkHits[im]<=11) continue;
      int ptbm=int(pfmuPt[im]/3);
      if (ptbm>9) continue;

      int pfch = pfNchhad;
      int pfne = pfNchhad;
      int pfpho = pfNchhad;

      double dz0;
      double dd0;
      double dphi;
      double delr;
      double pi=3.1415926536;
      double isodep1[isop+1], isodep2[isop+1], isodep3[isop+1];
      for(int k=0;k<isop+1;k++){
	isodep1[k]=0;
	isodep2[k]=0;
	isodep3[k]=0;
      }
      for(int cch=0; cch<pfch; cch++){
	dz0=fabs(pfchhadZ0[cch]-pfmuz0[im]);
	dd0 = sqrt( (pfmudd0x[im]-pfchhadD0x[cch])*(pfmudd0x[im]-pfchhadD0x[cch]) + (pfmudd0y[im]-pfchhadD0y[cch])*(pfmudd0y[im]-pfchhadD0y[cch]) );
	dphi = pfmuPhi[im]-pfchhadphi[cch];
	if (dphi > pi)
	  dphi=2*pi-dphi;
	delr = sqrt( (pfmuEta[im]-pfchhadeta[cch])*(pfmuEta[im]-pfchhadeta[cch]) + dphi*dphi );
	if(dz0 < 0.2 && dd0 < 0.1 && pfchhadpt[cch] > 0 && delr > 1e-05){
	  for(int k=0;k<isop+1;k++){
	    if(delr < step*(k+1)){	    
	      isodep1[k] = isodep1[k] + pfchhadpt[cch];
	    }
	  }
	}
      }
      //      cout << "Normal Ch Had Isolation: " << muIsoChHad[im] << " calculated Ch Had deposits: " << isodep[9] << endl;
      for(int k=0;k<isop+1;k++){
	if(pfmuPt[im]>2 && pfmuPt[im]<30)
	  recDRpfMus[imcm][0]->Fill(step*(k+1),isodep1[k]);
	recDRpfMu[imcm][0][ptbm]->Fill(step*(k+1),isodep1[k]);
      }
      for(int cch=0; cch<pfne; cch++){
	dz0=fabs(pfnehadZ0[cch]-pfmuz0[im]);
	dd0 = sqrt( (pfmudd0x[im]-pfnehadD0x[cch])*(pfmudd0x[im]-pfnehadD0x[cch]) + (pfmudd0y[im]-pfnehadD0y[cch])*(pfmudd0y[im]-pfnehadD0y[cch]) );
	dphi = pfmuPhi[im]-pfnehadphi[cch];
	if (dphi > pi)
	  dphi=2*pi-dphi;
	delr = sqrt( (pfmuEta[im]-pfnehadeta[cch])*(pfmuEta[im]-pfnehadeta[cch]) + dphi*dphi );
	if(dz0 < 0.2 && dd0 < 0.1 && pfnehadpt[cch] > 0 && delr > 1e-05){
	  for(int k=0;k<isop+1;k++){
	    if(delr < step*(k+1)){	    
	      isodep2[k] = isodep2[k] + pfnehadpt[cch];
	    }
	  }
	}
      }
      //      cout << "Normal neutral Had Isolation: " << muIsoNHad[im] << " calculated neutral Had deposits: " << isodep[9] << endl;
      for(int k=0;k<isop+1;k++){
	if(pfmuPt[im]>2 && pfmuPt[im]<30)
	  recDRpfMus[imcm][1]->Fill(step*(k+1),isodep2[k]);
	recDRpfMu[imcm][1][ptbm]->Fill(step*(k+1),isodep2[k]);
      }
      for(int cch=0; cch<pfpho; cch++){
	dz0=fabs(pfphoZ0[cch]-pfmuz0[im]);
	dd0 = sqrt( (pfmudd0x[im]-pfphoD0x[cch])*(pfmudd0x[im]-pfphoD0x[cch]) + (pfmudd0y[im]-pfphoD0y[cch])*(pfmudd0y[im]-pfphoD0y[cch]) );
	dphi = pfmuPhi[im]-pfphophi[cch];
	if (dphi > pi)
	  dphi=2*pi-dphi;
	delr = sqrt( (pfmuEta[im]-pfphoeta[cch])*(pfmuEta[im]-pfphoeta[cch]) + dphi*dphi );
	if(dz0 < 0.2 && dd0 < 0.1 && pfphopt[cch] > 0 && delr > 1e-05){
	  for(int k=0;k<isop+1;k++){
	    if(delr < step*(k+1)){	    
	      isodep3[k] = isodep3[k] + pfphopt[cch];
	    }
	  }
	}
      }
      //      cout << "Normal Ch Had Isolation: " << muIsoChHad[im] << " calculated Ch Had deposits: " << isodep[9] << endl;
      for(int k=0;k<isop+1;k++){
	if(pfmuPt[im]>2 && pfmuPt[im]<30){
	  recDRpfMus[imcm][2]->Fill(step*(k+1),isodep3[k]);
	  recDRpfMus[imcm][3]->Fill(step*(k+1),isodep1[k]+isodep2[k]+isodep3[k]);
	}
	recDRpfMu[imcm][2][ptbm]->Fill(step*(k+1),isodep3[k]);
	recDRpfMu[imcm][3][ptbm]->Fill(step*(k+1),isodep1[k]+isodep2[k]+isodep3[k]);
      }
    }
  }
  ///fillling efficiency histograms
  
  for (int i1=0; i1<3; i1++){
    for (int i3=0; i3<10; i3++){
      double Integ=recmvapfEl[i1][i3]->Integral(0,recmvapfEl[i1][i3]->GetNbinsX()+1);   
      for (int i4=0; i4<recmvapfEl[i1][i3]->GetNbinsX(); i4++){
	double Part=recmvapfEl[i1][i3]->Integral(0,i4);
	double eff=Part/Integ;
	effmvaEl[i1][i3]->SetBinContent(i4+1,eff);
	double err=sqrt((eff*(1-eff))/Integ);
	effmvaEl[i1][i3]->SetBinError(i4+1,err);
      }
      if(i1==0){
	for(int i4=0;i4<recmvapfEl[0][i3]->GetNbinsX();i4++){
	  int n=recmvapfEl[0][i3]->Integral(0,recmvapfEl[0][i3]->GetNbinsX())+
	    recmvapfEl[1][i3]->Integral(0,recmvapfEl[1][i3]->GetNbinsX())+
	    recmvapfEl[2][i3]->Integral(0,recmvapfEl[2][i3]->GetNbinsX());
	  float p=(float)recmvapfEl[0][i3]->Integral(0,recmvapfEl[0][i3]->GetNbinsX())/(float)n;
	  float q=(float)(recmvapfEl[1][i3]->Integral(0,recmvapfEl[1][i3]->GetNbinsX())+
			  recmvapfEl[2][i3]->Integral(0,recmvapfEl[2][i3]->GetNbinsX()))/(float)n;
	  float err=sqrt(n*p*q);
	  if(recmvapfEl[1][i3]->GetBinContent(i4+1) + recmvapfEl[2][i3]->GetBinContent(i4+1)){
	    sigmvapfel[i3]->SetBinContent(i4+1,recmvapfEl[0][i3]->GetBinContent(i4+1)/
					  sqrt(recmvapfEl[1][i3]->GetBinContent(i4+1) + 
					   recmvapfEl[2][i3]->GetBinContent(i4+1)));
	    err=sqrt((recmvapfEl[0][i3]->GetBinContent(i4+1)+recmvapfEl[1][i3]->GetBinContent(i4+1)+
		      recmvapfEl[2][i3]->GetBinContent(i4+1))*p*q);
	  }
	  n=rechoepfEl[0][i3]->Integral(0,rechoepfEl[0][i3]->GetNbinsX())+
	    rechoepfEl[1][i3]->Integral(0,rechoepfEl[1][i3]->GetNbinsX())+
	    rechoepfEl[2][i3]->Integral(0,rechoepfEl[2][i3]->GetNbinsX());
	  p=(float)rechoepfEl[0][i3]->Integral(0,rechoepfEl[0][i3]->GetNbinsX())/(float)n;
	  q=(float)(rechoepfEl[1][i3]->Integral(0,rechoepfEl[1][i3]->GetNbinsX())+
			  rechoepfEl[2][i3]->Integral(0,rechoepfEl[2][i3]->GetNbinsX()))/(float)n;
	  err=sqrt(n*p*q);
	  if(rechoepfEl[1][i3]->GetBinContent(i4+1) + rechoepfEl[2][i3]->GetBinContent(i4+1)){
	    sighoepfel[i3]->SetBinContent(i4+1,rechoepfEl[0][i3]->GetBinContent(i4+1)/
					  sqrt(rechoepfEl[1][i3]->GetBinContent(i4+1) + 
					   rechoepfEl[2][i3]->GetBinContent(i4+1)));
	    err=sqrt((rechoepfEl[0][i3]->GetBinContent(i4+1)+rechoepfEl[1][i3]->GetBinContent(i4+1)+
		      rechoepfEl[2][i3]->GetBinContent(i4+1))*p*q);
	  }
	  /*
	  if(recmvapfEl[1][i3]->Integral(0,recmvapfEl[1][i3]->GetBinContent(i4+1)) 
	     + recmvapfEl[2][i3]->Integral(0,recmvapfEl[2][i3]->GetBinContent(i4+1)))
	    intsigmvapfel[i3]->SetBinContent(i4+1,recmvapfEl[0][i3]->Integral(0,recmvapfEl[0][i3]->GetBinContent(i4+1))/
					     (recmvapfEl[1][i3]->Integral(0,recmvapfEl[1][i3]->GetBinContent(i4+1)) + 
					      recmvapfEl[2][i3]->Integral(0,recmvapfEl[2][i3]->GetBinContent(i4+1))));
	  */
	}
	for(int j = 0; j<4; j++){
	  for(int k=0;k<sigDRpfEl[j][i3]->GetXaxis()->GetNbins();k++){
	    for(int l=0;l<sigDRpfEl[j][i3]->GetYaxis()->GetNbins();l++){
	      if( recDRpfEl[1][j][i3]->GetBinContent(k+1,l+1) + recDRpfEl[2][j][i3]->GetBinContent(k+1,l+1) > 0){
		sigDRpfEl[j][i3]->SetBinContent(k+1,l+1,recDRpfEl[0][j][i3]->GetBinContent(k+1,l+1)/
					       sqrt(recDRpfEl[1][j][i3]->GetBinContent(k+1,l+1) + 
						    recDRpfEl[2][j][i3]->GetBinContent(k+1,l+1)));
	      }
	    }
	  }
	  for(int k=0;k<sigDRpfMu[j][i3]->GetXaxis()->GetNbins();k++){
	    for(int l=0;l<sigDRpfMu[j][i3]->GetYaxis()->GetNbins();l++){
	      if( recDRpfMu[1][j][i3]->GetBinContent(k+1,l+1) + recDRpfMu[2][j][i3]->GetBinContent(k+1,l+1) > 0){
		sigDRpfMu[j][i3]->SetBinContent(k+1,l+1,recDRpfMu[0][j][i3]->GetBinContent(k+1,l+1)/
					       sqrt(recDRpfMu[1][j][i3]->GetBinContent(k+1,l+1) + 
						    recDRpfMu[2][j][i3]->GetBinContent(k+1,l+1)));
	      }
	    }
	  }
	  if(i3 == 0){
	    for(int k=0;k<sigDRpfEls[j]->GetXaxis()->GetNbins();k++){
	      for(int l=0;l<sigDRpfEls[j]->GetYaxis()->GetNbins();l++){
		if( recDRpfEls[1][j]->GetBinContent(k+1,l+1) + recDRpfEls[2][j]->GetBinContent(k+1,l+1) > 0){
		  sigDRpfEls[j]->SetBinContent(k+1,l+1,recDRpfEls[0][j]->GetBinContent(k+1,l+1)/
					       sqrt(recDRpfEls[1][j]->GetBinContent(k+1,l+1) + 
						    recDRpfEls[2][j]->GetBinContent(k+1,l+1)));
		}
	      }
	    }
	    for(int k=0;k<sigDRpfMus[j]->GetXaxis()->GetNbins();k++){
	      for(int l=0;l<sigDRpfMus[j]->GetYaxis()->GetNbins();l++){
		if( recDRpfMus[1][j]->GetBinContent(k+1,l+1) + recDRpfMus[2][j]->GetBinContent(k+1,l+1) > 0){
		  sigDRpfMus[j]->SetBinContent(k+1,l+1,recDRpfMus[0][j]->GetBinContent(k+1,l+1)/
					       sqrt(recDRpfMus[1][j]->GetBinContent(k+1,l+1) + 
						    recDRpfMus[2][j]->GetBinContent(k+1,l+1)));
		}
	      }
	    }
	  }
	}
      }
    }
    double Integ=recmvapfEls[i1]->Integral(0,recmvapfEls[i1]->GetNbinsX()+1);   
    for (int i4=0; i4<recmvapfEls[i1]->GetNbinsX(); i4++){
      double Part=recmvapfEls[i1]->Integral(0,i4);
      double eff=Part/Integ;
      effmvaEls[i1]->SetBinContent(i4+1,eff);
      double err=sqrt((eff*(1-eff))/Integ);
      effmvaEls[i1]->SetBinError(i4+1,err);
    }
  }

  for(int i1=0;i1<recmvapfEls[0]->GetNbinsX();i1++){
    if(recmvapfEls[1]->GetBinContent(i1+1) + recmvapfEls[2]->GetBinContent(i1+1))
      sigmvapfels->SetBinContent(i1+1,recmvapfEls[0]->GetBinContent(i1+1)/
				 sqrt(recmvapfEls[1]->GetBinContent(i1+1) + 
				      recmvapfEls[2]->GetBinContent(i1+1)));
    if(rechoepfEls[1]->GetBinContent(i1+1) + rechoepfEls[2]->GetBinContent(i1+1))
      sighoepfels->SetBinContent(i1+1,rechoepfEls[0]->GetBinContent(i1+1)/
				 sqrt(rechoepfEls[1]->GetBinContent(i1+1) + 
				  rechoepfEls[2]->GetBinContent(i1+1)));
    /*
    if(recmvapfEls[1]->Integral(0,recmvapfEls[1]->GetBinContent(i1+1)) + recmvapfEls[2]->Integral(0,recmvapfEls[2]->GetBinContent(i1+1)))
      intsigmvapfels->SetBinContent(i1+1,recmvapfEls[0]->Integral(0,recmvapfEls[0]->GetBinContent(i1+1))/sqrt(recmvapfEls[1]->Integral(0,recmvapfEls[1]->GetBinContent(i1+1)) + recmvapfEls[2]->Integral(0,recmvapfEls[2]->GetBinContent(i1+1))));
    */
  }

  ////writing the outputs
  f2->cd();
  TFolder *folmva = gROOT->GetRootFolder()->AddFolder("MVA","MVA");
  TFolder *folhoe = gROOT->GetRootFolder()->AddFolder("HoverE","HoverE");
  TFolder *folDRele = gROOT->GetRootFolder()->AddFolder("IsoElec","Electrons Isolation");
  TFolder *folDRmuo = gROOT->GetRootFolder()->AddFolder("IsoMuons","Muons Isolation");
  TFolder *folOCmu = folDRmuo->AddFolder("OccupancyPt","Occupancy in Pt Bins");
  TFolder *folSigmu = folDRmuo->AddFolder("SignificancePt","Significance in Pt Bins");
  TFolder *folOCel = folDRele->AddFolder("OccupancyPt","Occupancy in Pt Bins");
  TFolder *folSigel = folDRele->AddFolder("SignificancePt","Significance in Pt Bins");

  folDRmuo->Add(pfnmu);
  folDRele->Add(pfnel);

  folmva->Add(optmvaEffEls);

  folDRmuo->Add(optDRMu);
  folDRele->Add(optDREl);
  folmva->Add(sigmvapfels);
  folhoe->Add(sighoepfels);
  for (int i3=0; i3<10; i3++){
    folmva->Add(sigmvapfel[i3]);
    folhoe->Add(sighoepfel[i3]);
  }
  for(int i1 = 0; i1 < 3; i1++){
    folmva->Add(effmvaEls[i1]);
    folmva->Add(recmvapfEls[i1]);
    folhoe->Add(rechoepfEls[i1]);
    for (int i2=0; i2<4; i2++){
      if(i1==0){
	folSigel->Add(sigDRpfEls[i2]);
	folSigmu->Add(sigDRpfMus[i2]);
      }
      folOCel->Add(recDRpfEls[i1][i2]);
      folOCmu->Add(recDRpfMus[i1][i2]);
      for (int i3=0; i3<10; i3++){
	if(i2==0){
	  folmva->Add(recmvapfEl[i1][i3]);
	  folhoe->Add(rechoepfEl[i1][i3]);
	  folmva->Add(effmvaEl[i1][i3]);
	}
	if(i1==0){
	  folSigel->Add(sigDRpfEl[i2][i3]);
	  folDRele->Add(elIsoDR[i2][i3]);
	  folSigmu->Add(sigDRpfMu[i2][i3]);
	}
	folOCel->Add(recDRpfEl[i1][i2][i3]);
	folOCmu->Add(recDRpfMu[i1][i2][i3]);
      }
    }
  }
  folmva->Write();
  folhoe->Write();
  folDRele->Write();
  folDRmuo->Write();
  f2->Close();
}

float IsolOpt::dzero(float d0, float phi){
  return d0+0.0322* cos(phi);
}

IsolOpt::IsolOpt(TTree *tree)
{
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.
  if (tree == 0) {
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../prov1a.root");
    if (!f) {
      f = new TFile("/Users/aocampor/Desktop/PAT_vs_PF/root_files/nutples/LM0_pfandpat_ntuple.root");
      f->cd("/Users/aocampor/Desktop/PAT_vs_PF/root_files/nutples/LM0_pfandpat_ntuple.root:/demo");
    }
    tree = (TTree*)gDirectory->Get("allData");

  }
  Init(tree);
  f2=new TFile("bbb.root","recreate");
}

IsolOpt::~IsolOpt()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

Int_t IsolOpt::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}
Long64_t IsolOpt::LoadTree(Long64_t entry)
{
  // Set the environment to read one entry 
  if (!fChain) return -5;
  Long64_t centry = fChain->LoadTree(entry);
  if (centry < 0) return centry;
  if (!fChain->InheritsFrom(TChain::Class()))  return centry;
  TChain *chain = (TChain*)fChain;
  if (chain->GetTreeNumber() != fCurrent) {
    fCurrent = chain->GetTreeNumber();
    Notify();
  }
  return centry;
}

void IsolOpt::Init(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated                                                                        
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF  
  // (once per file to be processed).
  // Set branch addresses and branch pointers 
  if (!tree) return;
  fChain = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);

  fChain->SetBranchAddress("pfNel", &pfNel, &b_pfNel);
  fChain->SetBranchAddress("Npfmu", &Npfmu, &b_Npfmu);
  
  fChain->SetBranchAddress("pfelPt", pfelPt, &b_pfelPt);
  fChain->SetBranchAddress("pfelPhi", pfelPhi, &b_pfelPhi);
  fChain->SetBranchAddress("pfelEta", pfelEta, &b_pfelEta);
  fChain->SetBranchAddress("pfelhoe", pfelhoe, &b_pfelhoe);
  
  fChain->SetBranchAddress("elIsoGamma", elIsoGamma, &b_elIsoGamma);
  fChain->SetBranchAddress("elIsoNHad", elIsoNHad, &b_elIsoNHad);
  fChain->SetBranchAddress("elIsoChHad", elIsoChHad, &b_elIsoChHad);
  
  fChain->SetBranchAddress("pfelDrMuon", pfelDrMuon, &b_pfelDrMuon);
 
  fChain->SetBranchAddress("pfelIdLoose", pfelIdLoose, &b_pfelIdLoose);
  fChain->SetBranchAddress("pfelIdTight", pfelIdTight, &b_pfelIdTight);
  fChain->SetBranchAddress("pfelIdRobLoose", pfelIdRobLoose, &b_pfelIdRobLoose);
  fChain->SetBranchAddress("pfelIdRobTight", pfelIdRobTight, &b_pfelIdRobTight);
  fChain->SetBranchAddress("elIdPfpi",pfelIdPfpi,&b_pfelIdPfpi);   

  fChain->SetBranchAddress("pfelGsfCharge", pfelGsfCharge, &b_pfelGsfCharge);
  fChain->SetBranchAddress("pfelKfCharge", pfelKfCharge, &b_pfelKfCharge);
  
  fChain->SetBranchAddress("pfelD0", pfelD0, &b_pfelD0);
  //  fChain->SetBranchAddress("pfeldd0", pfeldd0, &b_pfeldd0);
  fChain->SetBranchAddress("pfeldd0x", pfeldd0x, &b_pfeldd0x);
  fChain->SetBranchAddress("pfeldd0y", pfeldd0y, &b_pfeldd0y);
  fChain->SetBranchAddress("pfelz0", pfelz0, &b_pfelz0);
  fChain->SetBranchAddress("pfelMC", pfelMC, &b_pfelMC);

  fChain->SetBranchAddress("pfmuPt", pfmuPt, &b_pfmuPt);
  fChain->SetBranchAddress("pfmuPhi", pfmuPhi, &b_pfmuPhi);
  fChain->SetBranchAddress("pfmuEta", pfmuEta, &b_pfmuEta);
  
  fChain->SetBranchAddress("muIsoGamma", muIsoGamma, &b_muIsoGamma);
  fChain->SetBranchAddress("muIsoNHad", muIsoNHad, &b_muIsoNHad);
  fChain->SetBranchAddress("muIsoChHad", muIsoChHad, &b_muIsoChHad);

  fChain->SetBranchAddress("pfmuDrElec", pfmuDrElec, &b_pfmuDrElec);
  
  fChain->SetBranchAddress("pfmuIdGlobalTight", pfmuIdGlobalTight, &b_pfmuIdGlobalTight);
  fChain->SetBranchAddress("pfmuIsGlobal", pfmuIsGlobal, &b_pfmuIsGlobal);
  
  fChain->SetBranchAddress("pfmuCharge", pfmuCharge, &b_pfmuCharge);
  fChain->SetBranchAddress("pfmuD0", pfmuD0, &b_pfmuD0);
  //  fChain->SetBranchAddress("pfmudd0", pfmudd0, &b_pfmudd0);
  fChain->SetBranchAddress("pfmudd0x", pfmudd0x, &b_pfmudd0x);
  fChain->SetBranchAddress("pfmudd0y", pfmudd0y, &b_pfmudd0y);
  fChain->SetBranchAddress("pfmuz0", pfmuz0, &b_pfmuz0);
  fChain->SetBranchAddress("pfmuTkHits", pfmuTkHits, &b_pfmuTkHits);
  fChain->SetBranchAddress("pfmuGlobChi2", pfmuGlobChi2, &b_pfmuGlobChi2);

  fChain->SetBranchAddress("pfmuMC", pfmuMC, &b_pfmuMC);

  fChain->SetBranchAddress("pfNchhad", &pfNchhad,&b_pfNchhad);
  fChain->SetBranchAddress("pfNnehad", &pfNnehad,&b_pfNnehad);
  fChain->SetBranchAddress("pfNpho", &pfNpho,&b_pfNpho);

  //  fChain->SetBranchAddress("pfchhadD0",pfchhadD0,&b_pfchhadD0);
  fChain->SetBranchAddress("pfchhadD0x",pfchhadD0x,&b_pfchhadD0x);
  fChain->SetBranchAddress("pfchhadD0y",pfchhadD0y,&b_pfchhadD0y);
  fChain->SetBranchAddress("pfchhadZ0",pfchhadZ0,&b_pfchhadZ0);
  fChain->SetBranchAddress("pfchhadeta",pfchhadeta,&b_pfchhadeta);
  fChain->SetBranchAddress("pfchhadphi",pfchhadphi,&b_pfchhadphi);
  fChain->SetBranchAddress("pfchhadpt",pfchhadpt,&b_pfchhadpt);

  //  fChain->SetBranchAddress("pfnehadD0",pfnehadD0,&b_pfnehadD0);
  fChain->SetBranchAddress("pfnehadD0x",pfnehadD0x,&b_pfnehadD0x);
  fChain->SetBranchAddress("pfnehadD0y",pfnehadD0y,&b_pfnehadD0y);
  fChain->SetBranchAddress("pfnehadZ0",pfnehadZ0,&b_pfnehadZ0);
  fChain->SetBranchAddress("pfnehadeta",pfnehadeta,&b_pfnehadeta);
  fChain->SetBranchAddress("pfnehadphi",pfnehadphi,&b_pfnehadphi);
  fChain->SetBranchAddress("pfnehadpt",pfnehadpt,&b_pfnehadpt);

  //  fChain->SetBranchAddress("pfphoD0",pfphoD0,&b_pfphoD0);
  fChain->SetBranchAddress("pfphoD0x",pfphoD0x,&b_pfphoD0x);
  fChain->SetBranchAddress("pfphoD0y",pfphoD0y,&b_pfphoD0y);
  fChain->SetBranchAddress("pfphoZ0",pfphoZ0,&b_pfphoZ0);
  fChain->SetBranchAddress("pfphoeta",pfphoeta,&b_pfphoeta);
  fChain->SetBranchAddress("pfphophi",pfphophi,&b_pfphophi);
  fChain->SetBranchAddress("pfphopt",pfphopt,&b_pfphopt);
  Notify();
}

Bool_t IsolOpt::Notify()
{
  // The Notify() function is called when a new file is opened. This 
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.
  return kTRUE;
}

void IsolOpt::Show(Long64_t entry)
{
  // Print contents of entry.                               
  // If entry is not specified, print current entry 
  if (!fChain) return;
  fChain->Show(entry);
}
/*
Int_t IsolOpt::Cut(Long64_t entry)
{
  // This function may be called from Loop.                                                                                                                                                                        
  // returns  1 if entry is accepted.                                                                                                                                                                              
  // returns -1 otherwise.                                                                                                                                                                                         
  return 1;
}
*/
