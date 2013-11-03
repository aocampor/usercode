#!/bin/bash -x
root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_and_DL_cuts","alphat-dl-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_and_PFDL_cuts","alphat-PF-dl-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_and_PFSL_cuts","alphat-PF-sl-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_and_SL_cuts","alphat-sl-LM2");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_re_and_DL_cuts","alphat-re-dl-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_re_and_PFDL_cuts","alphat-re-PF-dl-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_re_and_PFSL_cuts","alphat-re-PF-sl-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_re_and_SL_cuts","alphat-re-sl-LM2");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_2jets_and_DL_cuts","alphat-2j-dl-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_2jets_and_PFDL_cuts","alphat-2j-PF-dl-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_2jets_and_PFSL_cuts","alphat-2j-PF-sl-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_2jets_and_SL_cuts","alphat-2j-sl-LM2");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_njets_and_DL_cuts","alphat-nj-dl-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_njets_and_PFDL_cuts","alphat-nj-PF-dl-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_njets_and_PFSL_cuts","alphat-nj-PF-sl-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_njets_and_SL_cuts","alphat-nj-sl-LM2");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_njets_re_and_DL_cuts","alphat-nj-re-dl-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_njets_re_and_PFDL_cuts","alphat-nj-re-PF-dl-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_njets_re_and_PFSL_cuts","alphat-nj-re-PF-sl-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","Alphat","Events_after_alphat_njets_re_and_SL_cuts","alphat-nj-re-sl-LM2");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","DLOSee","DLOSee-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","DLOSemu","DLOSemu-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","DLOSetau","DLOSetau-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","DLOSmumu","DLOSmumu-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","DLOSmutau","DLOSmutau-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","DLOStautau","DLOStautau-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","DLSSee","DLSSee-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","DLSSemu","DLSSemu-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","DLSSetau","DLSSetau-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","DLSSmumu","DLSSmumu-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","DLSSmutau","DLSSmutau-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","DLSStautau","DLSStautau-LM2");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","PFDLOSee","PFDLOSee-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","PFDLOSemu","PFDLOSemu-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","PFDLOSetau","PFDLOSetau-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","PFDLOSmumu","PFDLOSmumu-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","PFDLOSmutau","PFDLOSmutau-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","PFDLOStautau","PFDLOStautau-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","PFDLSSee","PFDLSSee-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","PFDLSSemu","PFDLSSemu-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","PFDLSSetau","PFDLSSetau-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","PFDLSSmumu","PFDLSSmumu-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","PFDLSSmutau","PFDLSSmutau-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","DoubleLepton","PFDLSStautau","PFDLSStautau-LM2");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","SingleLepton","SLe","SL-e-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","SingleLepton","SLmu","SL-mu-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","SingleLepton","SLtau","SL-tau-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","SingleLepton","PFSLe","PFSL-e-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","SingleLepton","PFSLmu","PFSL-mu-LM2");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2.txt","SingleLepton","PFSLtau","PFSL-tau-LM2");
.q;
EOF
./create_latex_tables_LM2.sh
