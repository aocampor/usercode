#!/bin/bash -x

./sumtable.py sigtable-alphat-PF-dl-LM7.txt sigtable-alphat-dl-LM7.txt sigtable-alphat-re-PF-dl-LM7.txt sigtable-alphat-re-dl-LM7.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_dl_LM7.pdf

./sumtable.py sigtable-alphat-PF-sl-LM7.txt sigtable-alphat-sl-LM7.txt sigtable-alphat-re-PF-sl-LM7.txt sigtable-alphat-re-sl-LM7.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_sl_LM7.pdf

./sumtable.py sigtable-alphat-2j-PF-dl-LM7.txt sigtable-alphat-2j-dl-LM7.txt 
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_2j_dl_LM7.pdf

./sumtable.py sigtable-alphat-2j-PF-sl-LM7.txt sigtable-alphat-2j-sl-LM7.txt 
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_2j_sl_LM7.pdf

./sumtable.py sigtable-alphat-nj-PF-dl-LM7.txt sigtable-alphat-nj-dl-LM7.txt sigtable-alphat-nj-re-PF-dl-LM7.txt sigtable-alphat-nj-re-dl-LM7.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_nj_dl_LM7.pdf

./sumtable.py sigtable-alphat-nj-PF-sl-LM7.txt sigtable-alphat-nj-sl-LM7.txt sigtable-alphat-nj-re-PF-sl-LM7.txt sigtable-alphat-nj-re-sl-LM7.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_nj_sl_LM7.pdf


./sumtable.py sigtable-SL-*-LM7.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_single_lepton_LM7.pdf

./sumtable.py sigtable-PFSL-*-LM7.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_PFsingle_lepton_LM7.pdf

./sumtable.py sigtable-DLOS*-LM7.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_OS_LM7.pdf

./sumtable.py sigtable-PFDLOS*-LM7.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_PFOS_LM7.pdf

./sumtable.py sigtable-DLSS*-LM7.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_SS_LM7.pdf

./sumtable.py sigtable-PFDLSS*-LM7.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_PFSS_LM7.pdf

#open -a Preview *.pdf