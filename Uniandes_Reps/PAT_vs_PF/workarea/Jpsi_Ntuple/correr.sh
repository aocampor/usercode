make
./l1Analyse ../../root_files/nutples/jpsi/ntuple.root
#root -l -b analysis_macro_ntuple.CC <<EOF 
#.q

#EOF
#open -a Safari Tables.txt
#open -a Preview *.gif