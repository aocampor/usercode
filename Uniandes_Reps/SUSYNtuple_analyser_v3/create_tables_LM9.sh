#!/bin/bash -x
root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_and_DL_cuts","alphat-dl-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_and_PFDL_cuts","alphat-PF-dl-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_and_PFSL_cuts","alphat-PF-sl-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_and_SL_cuts","alphat-sl-LM9");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_re_and_DL_cuts","alphat-re-dl-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_re_and_PFDL_cuts","alphat-re-PF-dl-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_re_and_PFSL_cuts","alphat-re-PF-sl-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_re_and_SL_cuts","alphat-re-sl-LM9");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_2jets_and_DL_cuts","alphat-2j-dl-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_2jets_and_PFDL_cuts","alphat-2j-PF-dl-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_2jets_and_PFSL_cuts","alphat-2j-PF-sl-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_2jets_and_SL_cuts","alphat-2j-sl-LM9");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_njets_and_DL_cuts","alphat-nj-dl-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_njets_and_PFDL_cuts","alphat-nj-PF-dl-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_njets_and_PFSL_cuts","alphat-nj-PF-sl-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_njets_and_SL_cuts","alphat-nj-sl-LM9");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_njets_re_and_DL_cuts","alphat-nj-re-dl-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_njets_re_and_PFDL_cuts","alphat-nj-re-PF-dl-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_njets_re_and_PFSL_cuts","alphat-nj-re-PF-sl-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","Alphat","Events_after_alphat_njets_re_and_SL_cuts","alphat-nj-re-sl-LM9");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","DLOSee","DLOSee-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","DLOSemu","DLOSemu-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","DLOSetau","DLOSetau-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","DLOSmumu","DLOSmumu-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","DLOSmutau","DLOSmutau-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","DLOStautau","DLOStautau-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","DLSSee","DLSSee-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","DLSSemu","DLSSemu-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","DLSSetau","DLSSetau-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","DLSSmumu","DLSSmumu-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","DLSSmutau","DLSSmutau-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","DLSStautau","DLSStautau-LM9");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","PFDLOSee","PFDLOSee-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","PFDLOSemu","PFDLOSemu-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","PFDLOSetau","PFDLOSetau-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","PFDLOSmumu","PFDLOSmumu-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","PFDLOSmutau","PFDLOSmutau-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","PFDLOStautau","PFDLOStautau-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","PFDLSSee","PFDLSSee-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","PFDLSSemu","PFDLSSemu-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","PFDLSSetau","PFDLSSetau-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","PFDLSSmumu","PFDLSSmumu-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","PFDLSSmutau","PFDLSSmutau-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","DoubleLepton","PFDLSStautau","PFDLSStautau-LM9");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","SingleLepton","SLe","SL-e-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","SingleLepton","SLmu","SL-mu-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","SingleLepton","SLtau","SL-tau-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","SingleLepton","PFSLe","PFSL-e-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","SingleLepton","PFSLmu","PFSL-mu-LM9");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9.txt","SingleLepton","PFSLtau","PFSL-tau-LM9");
.q;
EOF
./create_latex_tables_LM9.sh
