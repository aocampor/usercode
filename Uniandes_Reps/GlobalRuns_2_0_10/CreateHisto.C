#include <fstream>
#include <iostream>
#include <vector>

void CreateHisto(){

  bool existHisto=false;

  char filename[128];
  std::string name;

  std::cout<<"  "<<std::endl;
  std::cout<<"Wich path has your Merged File? "<<std::endl;
  std::cout<<"If it is into an lxplus directory: type -> ~/path/myFile.root"<<std::endl;
  std::cout<<"  "<<std::endl;

  std::cin>>name;

  sprintf(filename,"%s",name);
  std::cout << name << std::endl;

  TFile* histoResults = new TFile(name.c_str());
  if(!histoResults)continue;

  std::string p1;
  ifstream* input1 = new ifstream("merger/path/path_w-2.dat",ios::in);
  std::vector<std::string> wm2;
  wm2.clear();
  while(getline(*input1,p1,'\n')){
    wm2.push_back(p1);
  }

  std::string p2;
  ifstream* input2 = new ifstream("merger/path/path_w-1.dat",ios::in);
  std::vector<std::string> wm1;
  wm1.clear();
  while(getline(*input2,p2,'\n')){
    wm1.push_back(p2);
  }

  std::string p3;
  ifstream* input3 = new ifstream("merger/path/path_w+0.dat",ios::in);
  std::vector<std::string> wp0;
  wp0.clear();
  while(getline(*input3,p3,'\n')){
    wp0.push_back(p3);
  }

  std::string p5;
  ifstream* input5 = new ifstream("merger/path/path_w+2.dat",ios::in);
  std::vector<std::string> wp2;
  wp2.clear();
  while(getline(*input5,p5,'\n')){
    wp2.push_back(p5);
  }

  std::string p4;
  ifstream* input4 = new ifstream("merger/path/path_w+1.dat",ios::in);
  std::vector<std::string> wp1;
  wp1.clear();
  while(getline(*input4,p4,'\n')){
    wp1.push_back(p4);
  }



  //Rolls

  std::string rm2;
  ifstream* inm2 = new ifstream("merger/path/roll_w-2.dat",ios::in);
  std::vector<std::string> rwm2;
  rwm2.clear();
  while(getline(*inm2,rm2,'\n')){
    rwm2.push_back(rm2);
  }
  std::string rm1;
  ifstream* inm1 = new ifstream("merger/path/roll_w-1.dat",ios::in);
  std::vector<std::string> rwm1;
  rwm1.clear();
  while(getline(*inm1,rm1,'\n')){
    rwm1.push_back(rm1);
  }

  std::string rp0;
  ifstream* inp0 = new ifstream("merger/path/roll_w+0.dat",ios::in);
  std::vector<std::string> rwp0;
  rwp0.clear();
  while(getline(*inp0,rp0,'\n')){
    rwp0.push_back(rp0);
  }

  std::string rp2;
  ifstream* inp2 = new ifstream("merger/path/roll_w+2.dat",ios::in);
  std::vector<std::string> rwp2;
  rwp2.clear();
  while(getline(*inp2,rp2,'\n')){
    rwp2.push_back(rp2);
  }


  std::string rp1;
  ifstream* inp1 = new ifstream("merger/path/roll_w+1.dat",ios::in);
  std::vector<std::string> rwp1;
  rwp1.clear();
  while(getline(*inp1,rp1,'\n')){
    rwp1.push_back(rp1);
  }



  std::vector<std::string> copy;  
  std::vector<std::string> roll;
  int wheel=0;

  for(int g=0;g<5;g++){
    copy.clear();
    roll.clear();
    wheel=0;

    if(g==0){
      for(int z=0;z<wm2.size();z++){
	copy.push_back(wm2[z]);
	roll.push_back(rwm2[z]);
      }
      wheel=-2;
    }
    if(g==1){
      for(int z=0;z<wm1.size();z++){
	copy.push_back(wm1[z]);
	roll.push_back(rwm1[z]);
      }
      wheel=-1;
    }
    if(g==2){
      for(int z=0;z<wp0.size();z++){
	copy.push_back(wp0[z]);
	roll.push_back(rwp0[z]);
      }
      wheel=0;
    }
    if(g==4){
      for(int z=0;z<wp2.size();z++){
	copy.push_back(wp2[z]);
	roll.push_back(rwp2[z]);
      }
      wheel=2;
    }
    if(g==3){
      for(int z=0;z<wp1.size();z++){
	copy.push_back(wp1[z]);
	roll.push_back(rwp1[z]);
      }
      wheel=1;
    }


    sprintf(filename,"%s_w%i.root",name.c_str(),wheel);
    TFile* newResults = new TFile(filename,"RECREATE");
  
    TH1F *EffGlob = new TH1F("GlobalEff","Global efficiency",200,0.5,200.5);
    TH1F *RESGlob = new TH1F("GlobalRES","Global residuals",200,0.5,200.5);
    TH1F *DADGlob = new TH1F("GlobalDead","Global dead strips",200,0.5,200.5);
    TH1F *BXSGlob = new TH1F("GlobalBXS","Global bx",200,0.5,200.5);
    TH1F *CLSGlob = new TH1F("GlobalCLS","Global cluster size",200,0.5,200.5);


    int ind=0;
    std::cout<<"Searching chambers with Efficiency in Wheel "<<wheel<<"................."<<std::endl;

    for(int a=0;a<copy.size();a++){
      TString pathFolder = copy[a];
      TString nameRoll = roll[a];

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
	if(EXP->GetBinContent(i)> 0){
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


      float GlobEffValue = sumEFF/strips;
      float GlobErr = sqrt(GlobEffValue*(1-GlobEffValue)/sumEXP);
     
 
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
}
