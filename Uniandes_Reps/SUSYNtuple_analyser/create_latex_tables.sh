#!/bin/bash -x

./sumtable.py sigtable_alphat_PF_double_lepton.txt sigtable_alphat_double_lepton.txt sigtable_alphat_re_PF_double_lepton.txt sigtable_alphat_re_double_lepton.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_doublelep.pdf

./sumtable.py sigtable_alphat_PF_single_lepton.txt sigtable_alphat_single_lepton.txt sigtable_alphat_re_PF_single_lepton.txt sigtable_alphat_re_single_lepton.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_singlelep.pdf

./sumtable.py sigtable_SL_*.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_single_lepton.pdf

./sumtable.py sigtable_PFSL_*.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_PFsingle_lepton.pdf

open -a Preview *.pdf