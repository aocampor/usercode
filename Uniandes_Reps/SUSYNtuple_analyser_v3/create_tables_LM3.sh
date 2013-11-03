#!/bin/bash -x
root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_and_DL_cuts","alphat-dl-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_and_PFDL_cuts","alphat-PF-dl-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_and_PFSL_cuts","alphat-PF-sl-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_and_SL_cuts","alphat-sl-LM3");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_re_and_DL_cuts","alphat-re-dl-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_re_and_PFDL_cuts","alphat-re-PF-dl-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_re_and_PFSL_cuts","alphat-re-PF-sl-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_re_and_SL_cuts","alphat-re-sl-LM3");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_2jets_and_DL_cuts","alphat-2j-dl-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_2jets_and_PFDL_cuts","alphat-2j-PF-dl-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_2jets_and_PFSL_cuts","alphat-2j-PF-sl-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_2jets_and_SL_cuts","alphat-2j-sl-LM3");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_njets_and_DL_cuts","alphat-nj-dl-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_njets_and_PFDL_cuts","alphat-nj-PF-dl-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_njets_and_PFSL_cuts","alphat-nj-PF-sl-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_njets_and_SL_cuts","alphat-nj-sl-LM3");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_njets_re_and_DL_cuts","alphat-nj-re-dl-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_njets_re_and_PFDL_cuts","alphat-nj-re-PF-dl-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_njets_re_and_PFSL_cuts","alphat-nj-re-PF-sl-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","Alphat","Events_after_alphat_njets_re_and_SL_cuts","alphat-nj-re-sl-LM3");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","DLOSee","DLOSee-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","DLOSemu","DLOSemu-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","DLOSetau","DLOSetau-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","DLOSmumu","DLOSmumu-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","DLOSmutau","DLOSmutau-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","DLOStautau","DLOStautau-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","DLSSee","DLSSee-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","DLSSemu","DLSSemu-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","DLSSetau","DLSSetau-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","DLSSmumu","DLSSmumu-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","DLSSmutau","DLSSmutau-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","DLSStautau","DLSStautau-LM3");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","PFDLOSee","PFDLOSee-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","PFDLOSemu","PFDLOSemu-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","PFDLOSetau","PFDLOSetau-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","PFDLOSmumu","PFDLOSmumu-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","PFDLOSmutau","PFDLOSmutau-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","PFDLOStautau","PFDLOStautau-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","PFDLSSee","PFDLSSee-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","PFDLSSemu","PFDLSSemu-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","PFDLSSetau","PFDLSSetau-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","PFDLSSmumu","PFDLSSmumu-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","PFDLSSmutau","PFDLSSmutau-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","DoubleLepton","PFDLSStautau","PFDLSStautau-LM3");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","SingleLepton","SLe","SL-e-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","SingleLepton","SLmu","SL-mu-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","SingleLepton","SLtau","SL-tau-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","SingleLepton","PFSLe","PFSL-e-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","SingleLepton","PFSLmu","PFSL-mu-LM3");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM3.txt","SingleLepton","PFSLtau","PFSL-tau-LM3");
.q;
EOF
./create_latex_tables_LM3.sh
