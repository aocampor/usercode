#!/bin/bash -x

./sumtable.py sigtable-alphat-PF-dl-LM9p.txt sigtable-alphat-dl-LM9p.txt sigtable-alphat-re-PF-dl-LM9p.txt sigtable-alphat-re-dl-LM9p.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_dl_LM9p.pdf

./sumtable.py sigtable-alphat-PF-sl-LM9p.txt sigtable-alphat-sl-LM9p.txt sigtable-alphat-re-PF-sl-LM9p.txt sigtable-alphat-re-sl-LM9p.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_sl_LM9p.pdf

./sumtable.py sigtable-alphat-2j-PF-dl-LM9p.txt sigtable-alphat-2j-dl-LM9p.txt 
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_2j_dl_LM9p.pdf

./sumtable.py sigtable-alphat-2j-PF-sl-LM9p.txt sigtable-alphat-2j-sl-LM9p.txt 
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_2j_sl_LM9p.pdf

./sumtable.py sigtable-alphat-nj-PF-dl-LM9p.txt sigtable-alphat-nj-dl-LM9p.txt sigtable-alphat-nj-re-PF-dl-LM9p.txt sigtable-alphat-nj-re-dl-LM9p.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_nj_dl_LM9p.pdf

./sumtable.py sigtable-alphat-nj-PF-sl-LM9p.txt sigtable-alphat-nj-sl-LM9p.txt sigtable-alphat-nj-re-PF-sl-LM9p.txt sigtable-alphat-nj-re-sl-LM9p.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_alphat_nj_sl_LM9p.pdf


./sumtable.py sigtable-SL-*-LM9p.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_single_lepton_LM9p.pdf

./sumtable.py sigtable-PFSL-*-LM9p.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_PFsingle_lepton_LM9p.pdf

./sumtable.py sigtable-DLOS*-LM9p.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_OS_LM9p.pdf

./sumtable.py sigtable-PFDLOS*-LM9p.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_PFOS_LM9p.pdf

./sumtable.py sigtable-DLSS*-LM9p.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_SS_LM9p.pdf

./sumtable.py sigtable-PFDLSS*-LM9p.txt
latex table_2v.tex <<EOF
s
EOF
dvipdf table_2v.dvi  
mv table_2v.pdf sigtable_doble_lepton_PFSS_LM9p.pdf

#open -a Preview *.pdf