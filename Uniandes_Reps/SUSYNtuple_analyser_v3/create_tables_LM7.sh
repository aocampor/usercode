#!/bin/bash -x
root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_and_DL_cuts","alphat-dl-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_and_PFDL_cuts","alphat-PF-dl-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_and_PFSL_cuts","alphat-PF-sl-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_and_SL_cuts","alphat-sl-LM7");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_re_and_DL_cuts","alphat-re-dl-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_re_and_PFDL_cuts","alphat-re-PF-dl-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_re_and_PFSL_cuts","alphat-re-PF-sl-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_re_and_SL_cuts","alphat-re-sl-LM7");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_2jets_and_DL_cuts","alphat-2j-dl-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_2jets_and_PFDL_cuts","alphat-2j-PF-dl-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_2jets_and_PFSL_cuts","alphat-2j-PF-sl-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_2jets_and_SL_cuts","alphat-2j-sl-LM7");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_njets_and_DL_cuts","alphat-nj-dl-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_njets_and_PFDL_cuts","alphat-nj-PF-dl-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_njets_and_PFSL_cuts","alphat-nj-PF-sl-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_njets_and_SL_cuts","alphat-nj-sl-LM7");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_njets_re_and_DL_cuts","alphat-nj-re-dl-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_njets_re_and_PFDL_cuts","alphat-nj-re-PF-dl-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_njets_re_and_PFSL_cuts","alphat-nj-re-PF-sl-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","Alphat","Events_after_alphat_njets_re_and_SL_cuts","alphat-nj-re-sl-LM7");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","DLOSee","DLOSee-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","DLOSemu","DLOSemu-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","DLOSetau","DLOSetau-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","DLOSmumu","DLOSmumu-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","DLOSmutau","DLOSmutau-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","DLOStautau","DLOStautau-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","DLSSee","DLSSee-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","DLSSemu","DLSSemu-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","DLSSetau","DLSSetau-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","DLSSmumu","DLSSmumu-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","DLSSmutau","DLSSmutau-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","DLSStautau","DLSStautau-LM7");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","PFDLOSee","PFDLOSee-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","PFDLOSemu","PFDLOSemu-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","PFDLOSetau","PFDLOSetau-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","PFDLOSmumu","PFDLOSmumu-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","PFDLOSmutau","PFDLOSmutau-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","PFDLOStautau","PFDLOStautau-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","PFDLSSee","PFDLSSee-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","PFDLSSemu","PFDLSSemu-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","PFDLSSetau","PFDLSSetau-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","PFDLSSmumu","PFDLSSmumu-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","PFDLSSmutau","PFDLSSmutau-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","DoubleLepton","PFDLSStautau","PFDLSStautau-LM7");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","SingleLepton","SLe","SL-e-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","SingleLepton","SLmu","SL-mu-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","SingleLepton","SLtau","SL-tau-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","SingleLepton","PFSLe","PFSL-e-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","SingleLepton","PFSLmu","PFSL-mu-LM7");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM7.txt","SingleLepton","PFSLtau","PFSL-tau-LM7");
.q;
EOF
./create_latex_tables_LM7.sh
