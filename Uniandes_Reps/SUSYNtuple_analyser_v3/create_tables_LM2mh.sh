#!/bin/bash -x
root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_and_DL_cuts","alphat-dl-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_and_PFDL_cuts","alphat-PF-dl-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_and_PFSL_cuts","alphat-PF-sl-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_and_SL_cuts","alphat-sl-LM2mh");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_re_and_DL_cuts","alphat-re-dl-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_re_and_PFDL_cuts","alphat-re-PF-dl-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_re_and_PFSL_cuts","alphat-re-PF-sl-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_re_and_SL_cuts","alphat-re-sl-LM2mh");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_2jets_and_DL_cuts","alphat-2j-dl-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_2jets_and_PFDL_cuts","alphat-2j-PF-dl-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_2jets_and_PFSL_cuts","alphat-2j-PF-sl-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_2jets_and_SL_cuts","alphat-2j-sl-LM2mh");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_njets_and_DL_cuts","alphat-nj-dl-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_njets_and_PFDL_cuts","alphat-nj-PF-dl-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_njets_and_PFSL_cuts","alphat-nj-PF-sl-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_njets_and_SL_cuts","alphat-nj-sl-LM2mh");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_njets_re_and_DL_cuts","alphat-nj-re-dl-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_njets_re_and_PFDL_cuts","alphat-nj-re-PF-dl-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_njets_re_and_PFSL_cuts","alphat-nj-re-PF-sl-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","Alphat","Events_after_alphat_njets_re_and_SL_cuts","alphat-nj-re-sl-LM2mh");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","DLOSee","DLOSee-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","DLOSemu","DLOSemu-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","DLOSetau","DLOSetau-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","DLOSmumu","DLOSmumu-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","DLOSmutau","DLOSmutau-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","DLOStautau","DLOStautau-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","DLSSee","DLSSee-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","DLSSemu","DLSSemu-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","DLSSetau","DLSSetau-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","DLSSmumu","DLSSmumu-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","DLSSmutau","DLSSmutau-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","DLSStautau","DLSStautau-LM2mh");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","PFDLOSee","PFDLOSee-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","PFDLOSemu","PFDLOSemu-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","PFDLOSetau","PFDLOSetau-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","PFDLOSmumu","PFDLOSmumu-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","PFDLOSmutau","PFDLOSmutau-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","PFDLOStautau","PFDLOStautau-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","PFDLSSee","PFDLSSee-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","PFDLSSemu","PFDLSSemu-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","PFDLSSetau","PFDLSSetau-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","PFDLSSmumu","PFDLSSmumu-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","PFDLSSmutau","PFDLSSmutau-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","DoubleLepton","PFDLSStautau","PFDLSStautau-LM2mh");
.q;
EOF

root -l <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/table.cxx
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","SingleLepton","SLe","SL-e-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","SingleLepton","SLmu","SL-mu-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","SingleLepton","SLtau","SL-tau-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","SingleLepton","PFSLe","PFSL-e-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","SingleLepton","PFSLmu","PFSL-mu-LM2mh");
table("/Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/input_files_LM2mh.txt","SingleLepton","PFSLtau","PFSL-tau-LM2mh");
.q;
EOF
./create_latex_tables_LM2mh.sh
