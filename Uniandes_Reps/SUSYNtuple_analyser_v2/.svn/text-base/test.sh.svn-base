rm -f out
make
./l1Analyse /Volumes/Untitled/data/SUSYTree/QCD_Pt1400_Spring10-START3X_V26_S09-v1_v1.root /Volumes/Untitled/data/SUSYTree/OUT/Salida_QCD_Pt1400.root 0.01122 > out
emacs -nw out
#root -l <<EOF
#.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
#table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files.txt","Alphat","Events_after_alphat_and_DL_cuts","alphat_double_lepton");
#.q;
#EOF

