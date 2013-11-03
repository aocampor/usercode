#!/bin/bash -x
root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_and_DL_cuts","alphat-dl-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_and_PFDL_cuts","alphat-PF-dl-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_and_PFSL_cuts","alphat-PF-sl-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_and_SL_cuts","alphat-sl-LM8");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_re_and_DL_cuts","alphat-re-dl-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_re_and_PFDL_cuts","alphat-re-PF-dl-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_re_and_PFSL_cuts","alphat-re-PF-sl-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_re_and_SL_cuts","alphat-re-sl-LM8");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_2jets_and_DL_cuts","alphat-2j-dl-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_2jets_and_PFDL_cuts","alphat-2j-PF-dl-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_2jets_and_PFSL_cuts","alphat-2j-PF-sl-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_2jets_and_SL_cuts","alphat-2j-sl-LM8");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_njets_and_DL_cuts","alphat-nj-dl-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_njets_and_PFDL_cuts","alphat-nj-PF-dl-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_njets_and_PFSL_cuts","alphat-nj-PF-sl-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_njets_and_SL_cuts","alphat-nj-sl-LM8");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_njets_re_and_DL_cuts","alphat-nj-re-dl-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_njets_re_and_PFDL_cuts","alphat-nj-re-PF-dl-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_njets_re_and_PFSL_cuts","alphat-nj-re-PF-sl-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","Alphat","Events_after_alphat_njets_re_and_SL_cuts","alphat-nj-re-sl-LM8");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","DLOSee","DLOSee-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","DLOSemu","DLOSemu-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","DLOSetau","DLOSetau-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","DLOSmumu","DLOSmumu-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","DLOSmutau","DLOSmutau-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","DLOStautau","DLOStautau-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","DLSSee","DLSSee-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","DLSSemu","DLSSemu-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","DLSSetau","DLSSetau-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","DLSSmumu","DLSSmumu-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","DLSSmutau","DLSSmutau-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","DLSStautau","DLSStautau-LM8");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","PFDLOSee","PFDLOSee-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","PFDLOSemu","PFDLOSemu-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","PFDLOSetau","PFDLOSetau-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","PFDLOSmumu","PFDLOSmumu-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","PFDLOSmutau","PFDLOSmutau-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","PFDLOStautau","PFDLOStautau-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","PFDLSSee","PFDLSSee-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","PFDLSSemu","PFDLSSemu-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","PFDLSSetau","PFDLSSetau-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","PFDLSSmumu","PFDLSSmumu-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","PFDLSSmutau","PFDLSSmutau-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","DoubleLepton","PFDLSStautau","PFDLSStautau-LM8");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","SingleLepton","SLe","SL-e-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","SingleLepton","SLmu","SL-mu-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","SingleLepton","SLtau","SL-tau-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","SingleLepton","PFSLe","PFSL-e-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","SingleLepton","PFSLmu","PFSL-mu-LM8");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM8.txt","SingleLepton","PFSLtau","PFSL-tau-LM8");
.q;
EOF
./create_latex_tables_LM8.sh
