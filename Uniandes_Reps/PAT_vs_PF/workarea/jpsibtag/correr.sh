make
#./l1Analyse ../../root_files/nutples/LM0/LM0_leptonsNtuple_with_hoe.root
#./l1Analyse ../../root_files/nutples/LM0/LM0_leptonsNtuple_with_hoe.root
#./l1Analyse ../../root_files/nutples/jpsi/hist_notriggernoht.root
#./l1Analyse ../../root_files/nutples/jpsi/jetmet_trigger.root
#./l1Analyse ../../root_files/nutples/jpsi/JET_notrig.root
#./l1Analyse ../../root_files/nutples/jpsi/PR_notrig.root
#./l1Analyse ../../root_files/nutples/jpsi/PromptReco_trig_ht30.root
#./l1Analyse ../../root_files/nutples/jpsi/totJetMETnotrig.root
#./l1Analyse ../../root_files/nutples/jpsi/totJETMETtrig.root
#./l1Analyse ../../root_files/nutples/jpsi/Tot_Minbias.root
#./l1Analyse tot_newconv.root
#./l1Analyse ../../root_files/nutples/jpsi/HLT_jpsitrack_Mu_370/MU_HLT_jpsi_HT10_noinv.root
#./l1Analyse ../../root_files/nutples/jpsi/HLT_jpsitrack_Mu_370/MU_HLT_jpsi_HT100_noinv.root
#./l1Analyse ../../root_files/nutples/jpsi/HLT_jpsitrack_Mu_370/MU_HLT_jpsi_HT30_noinv.root
#./l1Analyse ../../root_files/nutples/jpsi/HLT_jpsitrack_Mu_370/MU_HLT_jpsi_HT50_noinv.root
#./l1Analyse ../../root_files/nutples/jpsi/HLT_jpsitrack_Mu_370/MU_HLT_jpsi_HT70_noinv.root
#./l1Analyse ../../root_files/nutples/jpsi/HLT_jpsitrack_Mu_370/MU_HLT_jpsi_noinv.root
#./l1Analyse ../../root_files/nutples/jpsi/El_37X_HT0_jpsi.root
#./l1Analyse ../../root_files/nutples/jpsi/JetMET_HT0_362_HLT_jet15U_jet30U.root
#./l1Analyse ../../root_files/nutples/jpsi/38X_Muon_HT0.root 
#./l1Analyse ../../root_files/nutples/jpsi/HLT_HT100U/JetMET_HT_Jet50U_Tot.root
#./l1Analyse ../../root_files/nutples/jpsi/HLT_HT100U/JetMET_HT100_Jpsi_tot.root
./l1Analyse ../../root_files/nutples/jpsi/MuOnia_Sep17_JpsiHLT.root
root -l -b analysis_macro_ntuple.CC <<EOF 
.q

EOF
open -a Safari Tables.txt
open -a Preview *.gif