#include "JetMul.C"
#include "MuonMulBC.C"
#include "JetEMEFBC.C"
#include "JetPtBC.C"
#include "JetEtaBC.C"
#include "METEtBC.C"
#include "JetEMFSevBC.C"
void main(){
  JetMul();
  MuonMulBC();
  JetEMEFBC();
  JetPtBC();
  //JetEtaBC();
  METEtBC();
  JetEMFSevBC();

}
