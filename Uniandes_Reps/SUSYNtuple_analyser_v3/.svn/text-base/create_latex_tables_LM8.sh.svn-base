#!/bin/bash -x

./sumtable.py sigtable-alphat-PF-dl-LM8.txt sigtable-alphat-dl-LM8.txt sigtable-alphat-re-PF-dl-LM8.txt sigtable-alphat-re-dl-LM8.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_dl_LM8.pdf

./sumtable.py sigtable-alphat-PF-sl-LM8.txt sigtable-alphat-sl-LM8.txt sigtable-alphat-re-PF-sl-LM8.txt sigtable-alphat-re-sl-LM8.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_sl_LM8.pdf

./sumtable.py sigtable-alphat-2j-PF-dl-LM8.txt sigtable-alphat-2j-dl-LM8.txt 
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_2j_dl_LM8.pdf

./sumtable.py sigtable-alphat-2j-PF-sl-LM8.txt sigtable-alphat-2j-sl-LM8.txt 
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_2j_sl_LM8.pdf

./sumtable.py sigtable-alphat-nj-PF-dl-LM8.txt sigtable-alphat-nj-dl-LM8.txt sigtable-alphat-nj-re-PF-dl-LM8.txt sigtable-alphat-nj-re-dl-LM8.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_nj_dl_LM8.pdf

./sumtable.py sigtable-alphat-nj-PF-sl-LM8.txt sigtable-alphat-nj-sl-LM8.txt sigtable-alphat-nj-re-PF-sl-LM8.txt sigtable-alphat-nj-re-sl-LM8.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_nj_sl_LM8.pdf


./sumtable.py sigtable-SL-*-LM8.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_single_lepton_LM8.pdf

./sumtable.py sigtable-PFSL-*-LM8.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_PFsingle_lepton_LM8.pdf

./sumtable.py sigtable-DLOS*-LM8.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_OS_LM8.pdf

./sumtable.py sigtable-PFDLOS*-LM8.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_PFOS_LM8.pdf

./sumtable.py sigtable-DLSS*-LM8.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_SS_LM8.pdf

./sumtable.py sigtable-PFDLSS*-LM8.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_PFSS_LM8.pdf

#open -a Preview *.pdf