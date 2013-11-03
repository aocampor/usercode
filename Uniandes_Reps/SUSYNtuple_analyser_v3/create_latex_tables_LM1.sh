#!/bin/bash -x

./sumtable.py sigtable-alphat-PF-dl-LM1.txt sigtable-alphat-dl-LM1.txt sigtable-alphat-re-PF-dl-LM1.txt sigtable-alphat-re-dl-LM1.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_dl_LM1.pdf

./sumtable.py sigtable-alphat-PF-sl-LM1.txt sigtable-alphat-sl-LM1.txt sigtable-alphat-re-PF-sl-LM1.txt sigtable-alphat-re-sl-LM1.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_sl_LM1.pdf

./sumtable.py sigtable-alphat-2j-PF-dl-LM1.txt sigtable-alphat-2j-dl-LM1.txt 
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_2j_dl_LM1.pdf

./sumtable.py sigtable-alphat-2j-PF-sl-LM1.txt sigtable-alphat-2j-sl-LM1.txt 
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_2j_sl_LM1.pdf

./sumtable.py sigtable-alphat-nj-PF-dl-LM1.txt sigtable-alphat-nj-dl-LM1.txt sigtable-alphat-nj-re-PF-dl-LM1.txt sigtable-alphat-nj-re-dl-LM1.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_nj_dl_LM1.pdf

./sumtable.py sigtable-alphat-nj-PF-sl-LM1.txt sigtable-alphat-nj-sl-LM1.txt sigtable-alphat-nj-re-PF-sl-LM1.txt sigtable-alphat-nj-re-sl-LM1.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_nj_sl_LM1.pdf


./sumtable.py sigtable-SL-*-LM1.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_single_lepton_LM1.pdf

./sumtable.py sigtable-PFSL-*-LM1.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_PFsingle_lepton_LM1.pdf

./sumtable.py sigtable-DLOS*-LM1.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_OS_LM1.pdf

./sumtable.py sigtable-PFDLOS*-LM1.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_PFOS_LM1.pdf

./sumtable.py sigtable-DLSS*-LM1.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_SS_LM1.pdf

./sumtable.py sigtable-PFDLSS*-LM1.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_PFSS_LM1.pdf

#open -a Preview *.pdf