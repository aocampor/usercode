#!/bin/bash -x

./sumtable.py sigtable-alphat-PF-dl-LM5.txt sigtable-alphat-dl-LM5.txt sigtable-alphat-re-PF-dl-LM5.txt sigtable-alphat-re-dl-LM5.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_dl_LM5.pdf

./sumtable.py sigtable-alphat-PF-sl-LM5.txt sigtable-alphat-sl-LM5.txt sigtable-alphat-re-PF-sl-LM5.txt sigtable-alphat-re-sl-LM5.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_sl_LM5.pdf

./sumtable.py sigtable-alphat-2j-PF-dl-LM5.txt sigtable-alphat-2j-dl-LM5.txt 
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_2j_dl_LM5.pdf

./sumtable.py sigtable-alphat-2j-PF-sl-LM5.txt sigtable-alphat-2j-sl-LM5.txt 
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_2j_sl_LM5.pdf

./sumtable.py sigtable-alphat-nj-PF-dl-LM5.txt sigtable-alphat-nj-dl-LM5.txt sigtable-alphat-nj-re-PF-dl-LM5.txt sigtable-alphat-nj-re-dl-LM5.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_nj_dl_LM5.pdf

./sumtable.py sigtable-alphat-nj-PF-sl-LM5.txt sigtable-alphat-nj-sl-LM5.txt sigtable-alphat-nj-re-PF-sl-LM5.txt sigtable-alphat-nj-re-sl-LM5.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_nj_sl_LM5.pdf


./sumtable.py sigtable-SL-*-LM5.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_single_lepton_LM5.pdf

./sumtable.py sigtable-PFSL-*-LM5.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_PFsingle_lepton_LM5.pdf

./sumtable.py sigtable-DLOS*-LM5.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_OS_LM5.pdf

./sumtable.py sigtable-PFDLOS*-LM5.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_PFOS_LM5.pdf

./sumtable.py sigtable-DLSS*-LM5.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_SS_LM5.pdf

./sumtable.py sigtable-PFDLSS*-LM5.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_PFSS_LM5.pdf

#open -a Preview *.pdf