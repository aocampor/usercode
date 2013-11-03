#!/bin/bash -x
root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_and_DL_cuts","alphat-dl-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_and_PFDL_cuts","alphat-PF-dl-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_and_PFSL_cuts","alphat-PF-sl-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_and_SL_cuts","alphat-sl-LM10");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_re_and_DL_cuts","alphat-re-dl-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_re_and_PFDL_cuts","alphat-re-PF-dl-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_re_and_PFSL_cuts","alphat-re-PF-sl-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_re_and_SL_cuts","alphat-re-sl-LM10");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_2jets_and_DL_cuts","alphat-2j-dl-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_2jets_and_PFDL_cuts","alphat-2j-PF-dl-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_2jets_and_PFSL_cuts","alphat-2j-PF-sl-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_2jets_and_SL_cuts","alphat-2j-sl-LM10");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_njets_and_DL_cuts","alphat-nj-dl-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_njets_and_PFDL_cuts","alphat-nj-PF-dl-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_njets_and_PFSL_cuts","alphat-nj-PF-sl-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_njets_and_SL_cuts","alphat-nj-sl-LM10");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_njets_re_and_DL_cuts","alphat-nj-re-dl-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_njets_re_and_PFDL_cuts","alphat-nj-re-PF-dl-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_njets_re_and_PFSL_cuts","alphat-nj-re-PF-sl-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","Alphat","Events_after_alphat_njets_re_and_SL_cuts","alphat-nj-re-sl-LM10");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","DLOSee","DLOSee-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","DLOSemu","DLOSemu-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","DLOSetau","DLOSetau-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","DLOSmumu","DLOSmumu-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","DLOSmutau","DLOSmutau-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","DLOStautau","DLOStautau-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","DLSSee","DLSSee-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","DLSSemu","DLSSemu-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","DLSSetau","DLSSetau-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","DLSSmumu","DLSSmumu-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","DLSSmutau","DLSSmutau-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","DLSStautau","DLSStautau-LM10");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","PFDLOSee","PFDLOSee-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","PFDLOSemu","PFDLOSemu-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","PFDLOSetau","PFDLOSetau-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","PFDLOSmumu","PFDLOSmumu-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","PFDLOSmutau","PFDLOSmutau-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","PFDLOStautau","PFDLOStautau-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","PFDLSSee","PFDLSSee-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","PFDLSSemu","PFDLSSemu-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","PFDLSSetau","PFDLSSetau-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","PFDLSSmumu","PFDLSSmumu-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","PFDLSSmutau","PFDLSSmutau-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","DoubleLepton","PFDLSStautau","PFDLSStautau-LM10");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","SingleLepton","SLe","SL-e-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","SingleLepton","SLmu","SL-mu-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","SingleLepton","SLtau","SL-tau-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","SingleLepton","PFSLe","PFSL-e-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","SingleLepton","PFSLmu","PFSL-mu-LM10");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM10.txt","SingleLepton","PFSLtau","PFSL-tau-LM10");
.q;
EOF
./create_latex_tables_LM10.sh
