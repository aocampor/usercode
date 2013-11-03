#!/bin/bash -x
root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_and_DL_cuts","alphat-dl-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_and_PFDL_cuts","alphat-PF-dl-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_and_PFSL_cuts","alphat-PF-sl-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_and_SL_cuts","alphat-sl-LM13");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_re_and_DL_cuts","alphat-re-dl-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_re_and_PFDL_cuts","alphat-re-PF-dl-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_re_and_PFSL_cuts","alphat-re-PF-sl-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_re_and_SL_cuts","alphat-re-sl-LM13");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_2jets_and_DL_cuts","alphat-2j-dl-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_2jets_and_PFDL_cuts","alphat-2j-PF-dl-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_2jets_and_PFSL_cuts","alphat-2j-PF-sl-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_2jets_and_SL_cuts","alphat-2j-sl-LM13");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_njets_and_DL_cuts","alphat-nj-dl-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_njets_and_PFDL_cuts","alphat-nj-PF-dl-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_njets_and_PFSL_cuts","alphat-nj-PF-sl-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_njets_and_SL_cuts","alphat-nj-sl-LM13");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_njets_re_and_DL_cuts","alphat-nj-re-dl-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_njets_re_and_PFDL_cuts","alphat-nj-re-PF-dl-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_njets_re_and_PFSL_cuts","alphat-nj-re-PF-sl-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","Alphat","Events_after_alphat_njets_re_and_SL_cuts","alphat-nj-re-sl-LM13");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","DLOSee","DLOSee-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","DLOSemu","DLOSemu-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","DLOSetau","DLOSetau-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","DLOSmumu","DLOSmumu-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","DLOSmutau","DLOSmutau-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","DLOStautau","DLOStautau-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","DLSSee","DLSSee-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","DLSSemu","DLSSemu-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","DLSSetau","DLSSetau-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","DLSSmumu","DLSSmumu-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","DLSSmutau","DLSSmutau-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","DLSStautau","DLSStautau-LM13");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","PFDLOSee","PFDLOSee-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","PFDLOSemu","PFDLOSemu-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","PFDLOSetau","PFDLOSetau-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","PFDLOSmumu","PFDLOSmumu-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","PFDLOSmutau","PFDLOSmutau-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","PFDLOStautau","PFDLOStautau-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","PFDLSSee","PFDLSSee-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","PFDLSSemu","PFDLSSemu-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","PFDLSSetau","PFDLSSetau-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","PFDLSSmumu","PFDLSSmumu-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","PFDLSSmutau","PFDLSSmutau-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","DoubleLepton","PFDLSStautau","PFDLSStautau-LM13");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","SingleLepton","SLe","SL-e-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","SingleLepton","SLmu","SL-mu-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","SingleLepton","SLtau","SL-tau-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","SingleLepton","PFSLe","PFSL-e-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","SingleLepton","PFSLmu","PFSL-mu-LM13");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM13.txt","SingleLepton","PFSLtau","PFSL-tau-LM13");
.q;
EOF
./create_latex_tables_LM13.sh
