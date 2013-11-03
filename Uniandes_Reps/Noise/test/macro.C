#include <string>

void macro(){
  using namespace std;
  TFile *file = TFile::Open("noise.root");
  TTree *T = (TTree*)file->Get("RPCNoise");
  Int_t nen = T->GetEntries();
  Int_t neven;
  T->SetBranchAddress("neven",&neven);
  char nomchamb[50];
  T->SetBranchAddress("nomchamb",&nomchamb);
  Int_t nrun;
  T->SetBranchAddress("nrun",&nrun);
  Int_t tempo;
  T->SetBranchAddress("tempo",&tempo);
  Int_t ndigi;
  T->SetBranchAddress("ndigi",&ndigi);
  long long min = (long long)T->GetMinimum("tempo");
  long long max = (long long)T->GetMaximum("tempo");
  Int_t binnum =(Int_t)(max-min);
  cout << binnum << endl;
  //  Int_t lm =(const int)binnum;
  TH1F *occtot = new TH1F("Occtot","Occupancy for all detector",binnum,0,binnum);
  TH1F *occbarrel = new TH1F("Occbarrel","Occupancy for Barrel",binnum,0,binnum);
  TH1F *occEnd = new TH1F("OccEndForw","Occupancy for Endcap Forward",binnum,0,binnum);
  //  Int_t occtoty[104];
  //  Int_t occtotx[104];

  //  for (Int_t j=0;j<binnum;j++){
  //    occtoty[j]=0;
  //    occtotx[j]= min + j;
  //  }
  //  for (Int_t j=0;j<binnum;j++){
  for (Int_t i=0;i<nen;i++){
    cout << T->GetEntry(i) << endl;
    cout << neven << endl;
    cout << nrun << endl;
    cout << tempo << endl;
    cout << nomchamb << endl;
    cout << ndigi << endl;
    occtot->SetBinContent(tempo-min+1,ndigi);
    
    if(nomchamb[0]=='W'){
      occbarrel->SetBinContent(tempo-min+1,ndigi);
    }
    else{
      if(nomchamb[0]=='D' & nomchamb[1]=='+'){
	occEnd->SetBinContent(tempo-min+1,ndigi);
      }
    }
    //    occtoty[j] += ndigi;
    //    }    

  }
  for(Int_t i=0;i<binnum;i++){
    if( i%2 == 0){
      char nombre[15];
      int n;
      n = sprintf(nombre,"%i",min+i);
      occtot->GetXaxis()->SetBinLabel(i+1,nombre);
      occbarrel->GetXaxis()->SetBinLabel(i+1,nombre);
      occEnd->GetXaxis()->SetBinLabel(i+1,nombre);
    }
  }
  cout << "Coronamos" << endl;
  //  TGraph *occtotg = new TGraph(104,occtotx,occtoty);  
  TCanvas *c1 =new TCanvas("c1","Occtot",200,10,600,400);
  occtot->Draw();
  TFile file1("RPCNoiseresults.root","RECREATE");
  occtot->Write();
  occbarrel->Write();
  occEnd->Write();
  file1.Write();
  file1.Close();
}
