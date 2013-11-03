#!/bin/bash -x
root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_and_DL_cuts","alphat-dl-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_and_PFDL_cuts","alphat-PF-dl-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_and_PFSL_cuts","alphat-PF-sl-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_and_SL_cuts","alphat-sl-LM11");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_re_and_DL_cuts","alphat-re-dl-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_re_and_PFDL_cuts","alphat-re-PF-dl-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_re_and_PFSL_cuts","alphat-re-PF-sl-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_re_and_SL_cuts","alphat-re-sl-LM11");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_2jets_and_DL_cuts","alphat-2j-dl-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_2jets_and_PFDL_cuts","alphat-2j-PF-dl-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_2jets_and_PFSL_cuts","alphat-2j-PF-sl-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_2jets_and_SL_cuts","alphat-2j-sl-LM11");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_njets_and_DL_cuts","alphat-nj-dl-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_njets_and_PFDL_cuts","alphat-nj-PF-dl-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_njets_and_PFSL_cuts","alphat-nj-PF-sl-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_njets_and_SL_cuts","alphat-nj-sl-LM11");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_njets_re_and_DL_cuts","alphat-nj-re-dl-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_njets_re_and_PFDL_cuts","alphat-nj-re-PF-dl-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_njets_re_and_PFSL_cuts","alphat-nj-re-PF-sl-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","Alphat","Events_after_alphat_njets_re_and_SL_cuts","alphat-nj-re-sl-LM11");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","DLOSee","DLOSee-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","DLOSemu","DLOSemu-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","DLOSetau","DLOSetau-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","DLOSmumu","DLOSmumu-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","DLOSmutau","DLOSmutau-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","DLOStautau","DLOStautau-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","DLSSee","DLSSee-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","DLSSemu","DLSSemu-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","DLSSetau","DLSSetau-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","DLSSmumu","DLSSmumu-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","DLSSmutau","DLSSmutau-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","DLSStautau","DLSStautau-LM11");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","PFDLOSee","PFDLOSee-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","PFDLOSemu","PFDLOSemu-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","PFDLOSetau","PFDLOSetau-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","PFDLOSmumu","PFDLOSmumu-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","PFDLOSmutau","PFDLOSmutau-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","PFDLOStautau","PFDLOStautau-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","PFDLSSee","PFDLSSee-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","PFDLSSemu","PFDLSSemu-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","PFDLSSetau","PFDLSSetau-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","PFDLSSmumu","PFDLSSmumu-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","PFDLSSmutau","PFDLSSmutau-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","DoubleLepton","PFDLSStautau","PFDLSStautau-LM11");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","SingleLepton","SLe","SL-e-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","SingleLepton","SLmu","SL-mu-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","SingleLepton","SLtau","SL-tau-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","SingleLepton","PFSLe","PFSL-e-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","SingleLepton","PFSLmu","PFSL-mu-LM11");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM11.txt","SingleLepton","PFSLtau","PFSL-tau-LM11");
.q;
EOF
./create_latex_tables_LM11.sh
