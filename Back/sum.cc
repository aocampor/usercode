#include <iostream>
#include <fstream>

using namespace std;

int  main(){
  ifstream mfile;
  mfile.open ("calomuons.dat");
  double sum=0;
  double aux=0;
  for (int i=0;i<444;i++){
    mfile >> aux;
    sum=sum+aux;
  }
  cout << "There are: " << sum << " generated Z" << endl;
  return 0;
}
