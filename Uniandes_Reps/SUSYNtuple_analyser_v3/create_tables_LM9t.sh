#!/bin/bash -x
root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_and_DL_cuts","alphat-dl-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_and_PFDL_cuts","alphat-PF-dl-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_and_PFSL_cuts","alphat-PF-sl-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_and_SL_cuts","alphat-sl-LM9t");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_re_and_DL_cuts","alphat-re-dl-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_re_and_PFDL_cuts","alphat-re-PF-dl-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_re_and_PFSL_cuts","alphat-re-PF-sl-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_re_and_SL_cuts","alphat-re-sl-LM9t");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_2jets_and_DL_cuts","alphat-2j-dl-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_2jets_and_PFDL_cuts","alphat-2j-PF-dl-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_2jets_and_PFSL_cuts","alphat-2j-PF-sl-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_2jets_and_SL_cuts","alphat-2j-sl-LM9t");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_njets_and_DL_cuts","alphat-nj-dl-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_njets_and_PFDL_cuts","alphat-nj-PF-dl-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_njets_and_PFSL_cuts","alphat-nj-PF-sl-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_njets_and_SL_cuts","alphat-nj-sl-LM9t");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_njets_re_and_DL_cuts","alphat-nj-re-dl-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_njets_re_and_PFDL_cuts","alphat-nj-re-PF-dl-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_njets_re_and_PFSL_cuts","alphat-nj-re-PF-sl-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","Alphat","Events_after_alphat_njets_re_and_SL_cuts","alphat-nj-re-sl-LM9t");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","DLOSee","DLOSee-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","DLOSemu","DLOSemu-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","DLOSetau","DLOSetau-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","DLOSmumu","DLOSmumu-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","DLOSmutau","DLOSmutau-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","DLOStautau","DLOStautau-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","DLSSee","DLSSee-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","DLSSemu","DLSSemu-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","DLSSetau","DLSSetau-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","DLSSmumu","DLSSmumu-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","DLSSmutau","DLSSmutau-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","DLSStautau","DLSStautau-LM9t");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","PFDLOSee","PFDLOSee-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","PFDLOSemu","PFDLOSemu-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","PFDLOSetau","PFDLOSetau-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","PFDLOSmumu","PFDLOSmumu-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","PFDLOSmutau","PFDLOSmutau-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","PFDLOStautau","PFDLOStautau-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","PFDLSSee","PFDLSSee-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","PFDLSSemu","PFDLSSemu-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","PFDLSSetau","PFDLSSetau-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","PFDLSSmumu","PFDLSSmumu-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","PFDLSSmutau","PFDLSSmutau-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","DoubleLepton","PFDLSStautau","PFDLSStautau-LM9t");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","SingleLepton","SLe","SL-e-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","SingleLepton","SLmu","SL-mu-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","SingleLepton","SLtau","SL-tau-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","SingleLepton","PFSLe","PFSL-e-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","SingleLepton","PFSLmu","PFSL-mu-LM9t");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM9t.txt","SingleLepton","PFSLtau","PFSL-tau-LM9t");
.q;
EOF
./create_latex_tables_LM9t.sh
