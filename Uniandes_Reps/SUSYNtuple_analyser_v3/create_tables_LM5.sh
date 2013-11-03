#!/bin/bash -x
root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_and_DL_cuts","alphat-dl-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_and_PFDL_cuts","alphat-PF-dl-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_and_PFSL_cuts","alphat-PF-sl-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_and_SL_cuts","alphat-sl-LM5");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_re_and_DL_cuts","alphat-re-dl-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_re_and_PFDL_cuts","alphat-re-PF-dl-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_re_and_PFSL_cuts","alphat-re-PF-sl-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_re_and_SL_cuts","alphat-re-sl-LM5");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_2jets_and_DL_cuts","alphat-2j-dl-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_2jets_and_PFDL_cuts","alphat-2j-PF-dl-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_2jets_and_PFSL_cuts","alphat-2j-PF-sl-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_2jets_and_SL_cuts","alphat-2j-sl-LM5");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_njets_and_DL_cuts","alphat-nj-dl-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_njets_and_PFDL_cuts","alphat-nj-PF-dl-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_njets_and_PFSL_cuts","alphat-nj-PF-sl-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_njets_and_SL_cuts","alphat-nj-sl-LM5");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_njets_re_and_DL_cuts","alphat-nj-re-dl-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_njets_re_and_PFDL_cuts","alphat-nj-re-PF-dl-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_njets_re_and_PFSL_cuts","alphat-nj-re-PF-sl-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","Alphat","Events_after_alphat_njets_re_and_SL_cuts","alphat-nj-re-sl-LM5");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","DLOSee","DLOSee-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","DLOSemu","DLOSemu-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","DLOSetau","DLOSetau-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","DLOSmumu","DLOSmumu-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","DLOSmutau","DLOSmutau-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","DLOStautau","DLOStautau-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","DLSSee","DLSSee-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","DLSSemu","DLSSemu-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","DLSSetau","DLSSetau-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","DLSSmumu","DLSSmumu-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","DLSSmutau","DLSSmutau-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","DLSStautau","DLSStautau-LM5");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","PFDLOSee","PFDLOSee-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","PFDLOSemu","PFDLOSemu-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","PFDLOSetau","PFDLOSetau-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","PFDLOSmumu","PFDLOSmumu-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","PFDLOSmutau","PFDLOSmutau-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","PFDLOStautau","PFDLOStautau-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","PFDLSSee","PFDLSSee-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","PFDLSSemu","PFDLSSemu-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","PFDLSSetau","PFDLSSetau-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","PFDLSSmumu","PFDLSSmumu-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","PFDLSSmutau","PFDLSSmutau-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","DoubleLepton","PFDLSStautau","PFDLSStautau-LM5");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","SingleLepton","SLe","SL-e-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","SingleLepton","SLmu","SL-mu-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","SingleLepton","SLtau","SL-tau-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","SingleLepton","PFSLe","PFSL-e-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","SingleLepton","PFSLmu","PFSL-mu-LM5");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM5.txt","SingleLepton","PFSLtau","PFSL-tau-LM5");
.q;
EOF
./create_latex_tables_LM5.sh
