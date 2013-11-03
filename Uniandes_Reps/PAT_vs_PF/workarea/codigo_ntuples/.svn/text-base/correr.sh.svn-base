make
#./l1Analyse ../../root_files/nutples/LM0/LM0_leptonsNtuple_with_hoe.root
./l1Analyse ../../root_files/nutples/TOT/TOT_7TeV_rereco.root
#./l1Analyse ../../root_files/nutples/TOT/TOT_ntuple_hoe.root
root -l -b analysis_macro_ntuple.CC <<EOF 
.q

EOF
open -a Safari Tables.txt
open -a Preview *.gif