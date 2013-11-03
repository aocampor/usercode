#!/bin/bash -x
root -l  <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/scripts/nonprompt.cxx
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/scripts/nonprompt2.cxx
gStyle->SetFillColor(0);

#nonprompt("../../root/OUT/Salida_QCD_Pt1000toInf.root");
#nonprompt("../../root/OUT/Salida_QCD_Pt100to250.root");
#nonprompt("../../root/OUT/Salida_QCD_Pt250to500.root");
#nonprompt("../../root/OUT/Salida_QCD_Pt500to1000.root");
#nonprompt("../../root/OUT/Salida_QCD_TOT.root");
#nonprompt("../../root/OUT/Salida_QCD_Pt1400.root");
nonprompt2("../../root/OUT/Salida_QCD_Pt1400.root","../../root/OUT/Salida_QCD_Pt15.root","../../root/OUT/Salida_QCD_Pt170.root","../../root/OUT/Salida_QCD_Pt80.root","../../root/OUT/Salida_QCD_Pt800.root","../../root/OUT/Salida_QCD_Pt30.root","../../root/OUT/Salida_QCD_Pt300.root","../../root/OUT/Salida_QCD_Pt470.root");
.q;

EOF