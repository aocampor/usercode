#include <fstream>
#include <iostream>
#include <vector>

void CreateHistoEndCap(){

  bool existHisto=false;

  char filename[128];
  std::string name;

  std::cout<<"  "<<std::endl;
  std::cout<<"Wich path has your Merged File? "<<std::endl;
  std::cout<<"If it is into an lxplus directory: type -> ~/path/myFile.root"<<std::endl;
  std::cout<<"  "<<std::endl;

  std::cin>>name;

  sprintf(filename,"%s",name);


  TFile* histoResults = new TFile(name.c_str());
  if(!histoResults)continue;

  std::string p1;
  ifstream* input1 = new ifstream("cruzet/merger/path/path_endcap.dat",ios::in);
  std::vector<std::string> wm1;
  wm1.clear();
  while(getline(*input1,p1,'\n')){
    wm1.push_back(p1);
  }


  //Rolls

  std::string rm1;
  ifstream* inm1 = new ifstream("cruzet/merger/path/name_endcap.dat",ios::in);
  std::vector<std::string> rwm1;
  rwm1.clear();
  while(getline(*inm1,rm1,'\n')){
    rwm1.push_back(rm1);
  }


  sprintf(filename,"%s_EndCap.root",name.c_str());
  TFile* newResults = new TFile(filename,"RECREATE");
  
  TH1F *EffGlob = new TH1F("GlobalEff","Global efficiency",500,0.5,500.5);
  TH1F *RESGlob = new TH1F("GlobalRES","Global residuals",500,0.5,500.5);
  TH1F *DADGlob = new TH1F("GlobalDead","Global dead strips",500,0.5,500.5);
  TH1F *BXSGlob = new TH1F("GlobalBXS","Global bx",500,0.5,500.5);
  TH1F *CLSGlob = new TH1F("GlobalCLS","Global cluster size",500,0.5,500.5);

  
  int ind=0;
  

  for(int a=0;a<rwm1.size();a++){
    TString pathFolder = wm1[a];
    TString nameRoll = rwm1[a];

    TString exp = pathFolder+"/ExpectedOccupancyFromTrack_"+nameRoll;
    TString rpc = pathFolder+"/RPCDataOccupancy_"+nameRoll;
    TString res = pathFolder+"/Residuals_"+nameRoll;
    TString bxs = pathFolder+"/BunchX_"+nameRoll;
    TString cls = pathFolder+"/ClusterSize_"+nameRoll;
    
    TH1F* EXP = (TH1F *) histoResults->Get(exp);
    TH1F* RPC = (TH1F *) histoResults->Get(rpc);
    TH1F* RES = (TH1F *) histoResults->Get(res);
    
 
    if(!EXP)continue;
    
    TString eff = "EfficienyFromTrackExtrapolation_"+nameRoll;
    TString profeff = "EfficienyFromTrackExtrapolation_"+nameRoll;

 
    TH1F *EFF= new TH1F(profeff,profeff,100, 0.5, 100.5);

    float sumEFF=0.;
    float sumEXP=0.;
    float sumRPC=0.;
    int strips=0;
    int dead=0;
    for(unsigned int i=1;i<=EXP->GetXaxis()->GetNbins();++i){
      if(EXP->GetBinContent(i)> 0.){
	float effValue = RPC->GetBinContent(i)/EXP->GetBinContent(i);
	float erreffValue = sqrt(effValue*(1-effValue)/EXP->GetBinContent(i));
	strips++;
	sumEFF+=effValue;
	sumEXP+=EXP->GetBinContent(i);
	sumRPC+=RPC->GetBinContent(i);

	EFF->SetBinContent(i,effValue*100.);
	EFF->SetBinError(i,erreffValue*100.);
      }
      if(EXP->GetBinContent(i)> 0 && RPC->GetBinContent(i)==0){
	dead++;
      }
    }

    if(strips!=0. && sumEXP!=0.){
      float GlobEffValue = sumEFF/strips;
      float GlobErr = sqrt(GlobEffValue*(1-GlobEffValue)/sumEXP);
    }
 
    if(GlobEffValue!=0.){
      std::cout<<"\tEfficiency != 0 For -->\t"<<nameRoll<<std::endl;
      
      ind++;
      
      eff = nameRoll;
	
      EffGlob->SetBinContent(ind,GlobEffValue*100.);
      EffGlob->SetBinError(ind,GlobErr*100.);
      EffGlob->GetXaxis()->SetBinLabel(ind,eff);
      EffGlob->GetXaxis()->LabelsOption("v");

      DADGlob->SetBinContent(ind,dead);
      DADGlob->GetXaxis()->SetBinLabel(ind,eff);
      DADGlob->GetXaxis()->LabelsOption("v");

      double resMean=RES->GetMean();
      double resRMS=RES->GetRMS();


      RESGlob->SetBinContent(ind,resMean);
      RESGlob->SetBinError(ind,resRMS);
      RESGlob->GetXaxis()->SetBinLabel(ind,eff);
      RESGlob->GetXaxis()->LabelsOption("v");


      if(existHisto==true){
	TH1F* BXS = (TH1F *) histoResults->Get(bxs);
	TH1F* CLS = (TH1F *) histoResults->Get(cls);
 
	//Cluster size
	double clsMean=CLS->GetMean();
	double clsRMS=CLS->GetRMS();
	newResults->WriteTObject(CLS);
	
	CLSGlob->SetBinContent(ind,clsMean);
	CLSGlob->SetBinError(ind,clsRMS);
	CLSGlob->GetXaxis()->SetBinLabel(ind,eff);
	CLSGlob->GetXaxis()->LabelsOption("v");

	//Bunch X
	double bxsMean=BXS->GetMean();
	double bxsRMS=BXS->GetRMS();
	newResults->WriteTObject(BXS);
	
	BXSGlob->SetBinContent(ind,bxsMean);
	BXSGlob->SetBinError(ind,bxsRMS);
	BXSGlob->GetXaxis()->SetBinLabel(ind,eff);
	BXSGlob->GetXaxis()->LabelsOption("v");
      }
    }


    newResults->WriteTObject(EFF);
    newResults->WriteTObject(RPC);
    newResults->WriteTObject(EXP);
    newResults->WriteTObject(RES);
  }

  if(existHisto==true){
    newResults->WriteTObject(BXSGlob);
    newResults->WriteTObject(CLSGlob);
  }

  newResults->WriteTObject(EffGlob);
  newResults->WriteTObject(RESGlob);
  newResults->WriteTObject(DADGlob);


  newResults->Close(); 
  delete newResults;
}

