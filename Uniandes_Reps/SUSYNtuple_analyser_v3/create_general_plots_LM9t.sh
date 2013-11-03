#!/bin/bash -x
root -l -b <<EOF
.L ../../../../Users/aocampor/Desktop/New_Alphat/SUSYNtuple_analyser/general_plots.cxx
gStyle->SetFillColor(0);

string prue = "/Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ww_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_zz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_wz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TTbar_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_WJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ZJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt1400.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt800.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt470.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt300.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt170.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt80.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt30.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt15.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_LM9t_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TOT_Data.root Alphat Alphat_nPFjets_case_as_reclustered";
genplots(prue,0.,20.,0.01,1e9,0,1);
.!mv stack.gif plots/LM9t_Alphat_nPFjets_case_as_reclustered.gif
.!mv significance.gif plots/LM9t_Alphat_nPFjets_case_as_reclustered_signi.gif

string prue = "/Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ww_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_zz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_wz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TTbar_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_WJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ZJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt1400.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt800.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt470.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt300.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt170.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt80.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt30.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt15.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_LM9t_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TOT_Data.root Alphat Alphat_njets_case_as_reclustered";
genplots(prue,0.,20.,0.01,1e9,0,1);
.!mv stack.gif plots/LM9t_Alphat_njets_case_as_reclustered.gif
.!mv significance.gif plots/LM9t_Alphat_njets_case_as_reclustered_signi.gif

string prue = "/Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ww_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_zz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_wz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TTbar_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_WJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ZJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt1400.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt800.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt470.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt300.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt170.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt80.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt30.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt15.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_LM9t_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TOT_Data.root Alphat Alphat_nPFjets_case_minimum_deltaht";
genplots(prue,0.,20.,0.01,1e9,0,1);
.!mv stack.gif plots/LM9t_Alphat_nPFjets_case_minimum_deltaht.gif
.!mv significance.gif plots/LM9t_Alphat_nPFjets_case_minimum_deltaht_signi.gif

string prue = "/Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ww_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_zz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_wz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TTbar_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_WJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ZJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt1400.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt800.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt470.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt300.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt170.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt80.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt30.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt15.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_LM9t_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TOT_Data.root Alphat Alphat_njets_case_minimum_deltaht";
genplots(prue,0.,20.,0.01,1e9,0,1);
.!mv stack.gif plots/LM9t_Alphat_njets_case_minimum_deltaht.gif
.!mv significance.gif plots/LM9t_Alphat_njets_case_minimum_deltaht_signi.gif

string prue = "/Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ww_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_zz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_wz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TTbar_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_WJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ZJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt1400.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt800.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt470.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt300.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt170.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt80.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt30.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt15.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_LM9t_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TOT_Data.root Alphat AlphaT_2Jets_case_SL";
genplots(prue,0.,20.,0.01,1e6,0,1);
.!mv stack.gif plots/LM9t_AlphaT_2Jets_case_SL.gif
.!mv significance.gif plots/LM9t_AlphaT_2Jets_case_SL_signi.gif

string prue = "/Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ww_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_zz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_wz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TTbar_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_WJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ZJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt1400.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt800.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt470.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt300.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt170.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt80.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt30.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt15.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_LM9t_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TOT_Data.root Alphat AlphaT_2PFJets_case_SL";
genplots(prue,0.,20.,0.01,1e6,0,1);
.!mv stack.gif plots/LM9t_AlphaT_2PFJets_case_SL.gif
.!mv significance.gif plots/LM9t_AlphaT_2PFJets_case_SL_signi.gif

string prue = "/Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ww_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_zz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_wz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TTbar_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_WJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ZJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt1400.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt800.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt470.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt300.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt170.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt80.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt30.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt15.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_LM9t_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TOT_Data.root Alphat AlphaT_2Jets_case_DL";
genplots(prue,0.,20.,0.01,1e6,0,1);
.!mv stack.gif plots/LM9t_AlphaT_2Jets_case_DL.gif
.!mv significance.gif plots/LM9t_AlphaT_2Jets_case_DL_signi.gif

string prue = "/Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ww_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_zz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_wz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TTbar_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_WJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ZJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt1400.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt800.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt470.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt300.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt170.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt80.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt30.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt15.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_LM9t_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TOT_Data.root Alphat AlphaT_2PFJets_case_DL";
genplots(prue,0.,20.,0.01,1e6,0,1);
.!mv stack.gif plots/LM9t_AlphaT_2PFJets_case_DL.gif
.!mv significance.gif plots/LM9t_AlphaT_2PFJets_case_DL_signi.gif

string prue = "/Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ww_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_zz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_wz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TTbar_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_WJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ZJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt1400.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt800.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt470.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt300.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt170.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt80.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt30.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt15.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_LM9t_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TOT_Data.root Alphat Alphat_nPFjets_case_as_reclustered_SL";
genplots(prue,0.,20.,0.01,1e6,0,1);
.!mv stack.gif plots/LM9t_AlphaT_nPFjets_case_as_reclustered_SL.gif
.!mv significance.gif plots/LM9t_AlphaT_nPFjets_case_as_reclustered_SL_signi.gif

string prue = "/Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ww_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_zz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_wz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TTbar_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_WJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ZJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt1400.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt800.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt470.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt300.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt170.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt80.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt30.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt15.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_LM9t_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TOT_Data.root Alphat Alphat_njets_case_as_reclustered_SL";
genplots(prue,0.,20.,0.01,1e6,0,1);
.!mv stack.gif plots/LM9t_AlphaT_njets_case_as_reclustered_SL.gif
.!mv significance.gif plots/LM9t_AlphaT_njets_case_as_reclustered_SL_signi.gif

string prue = "/Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ww_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_zz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_wz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TTbar_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_WJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ZJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt1400.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt800.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt470.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt300.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt170.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt80.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt30.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt15.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_LM9t_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TOT_Data.root Alphat Alphat_nPFjets_case_as_reclustered_DL";
genplots(prue,0.,20.,0.01,1e6,0,1);
.!mv stack.gif plots/LM9t_AlphaT_nPFjets_case_as_reclustered_DL.gif
.!mv significance.gif plots/LM9t_AlphaT_nPFjets_case_as_reclustered_DL_signi.gif

string prue = "/Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ww_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_zz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_wz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TTbar_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_WJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ZJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt1400.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt800.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt470.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt300.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt170.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt80.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt30.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt15.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_LM9t_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TOT_Data.root Alphat Alphat_njets_case_as_reclustered_DL";
genplots(prue,0.,20.,0.01,1e6,0,1);
.!mv stack.gif plots/LM9t_AlphaT_njets_case_as_reclustered_DL.gif
.!mv significance.gif plots/LM9t_AlphaT_njets_case_as_reclustered_DL_signi.gif

string prue = "/Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ww_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_zz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_wz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TTbar_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_WJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ZJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt1400.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt800.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt470.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt300.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt170.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt80.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt30.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt15.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_LM9t_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TOT_Data.root Alphat Alphat_nPFjets_case_minimum_deltaht_SL";
genplots(prue,0.,20.,0.01,1e6,0,1);
.!mv stack.gif plots/LM9t_AlphaT_nPFjets_case_minimum_deltaht_SL.gif
.!mv significance.gif plots/LM9t_AlphaT_nPFjets_case_minimum_deltaht_SL_signi.gif

string prue = "/Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ww_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_zz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_wz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TTbar_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_WJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ZJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt1400.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt800.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt470.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt300.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt170.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt80.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt30.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt15.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_LM9t_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TOT_Data.root Alphat Alphat_njets_case_minimum_deltaht_SL";
genplots(prue,0.,20.,0.01,1e6,0,1);
.!mv stack.gif plots/LM9t_AlphaT_njets_case_minimum_deltaht_SL.gif
.!mv significance.gif plots/LM9t_AlphaT_njets_case_minimum_deltaht_SL_signi.gif

string prue = "/Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ww_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_zz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_wz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TTbar_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_WJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ZJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt1400.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt800.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt470.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt300.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt170.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt80.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt30.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt15.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_LM9t_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TOT_Data.root Alphat Alphat_nPFjets_case_minimum_deltaht_DL";
genplots(prue,0.,20.,0.01,1e6,0,1);
.!mv stack.gif plots/LM9t_AlphaT_nPFjets_case_minimum_deltaht_DL.gif
.!mv significance.gif plots/LM9t_AlphaT_nPFjets_case_minimum_deltaht_DL_signi.gif

string prue = "/Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ww_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_zz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_wz_pat_1.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TTbar_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_WJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_ZJets_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt1400.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt800.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt470.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt300.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt170.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt80.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt30.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_QCD_Pt15.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_LM9t_temp.root /Users/aocampor/Desktop/New_Alphat/root/OUT/Salida_TOT_Data.root Alphat Alphat_njets_case_minimum_deltaht_DL";
genplots(prue,0.,20.,0.01,1e6,0,1);
.!mv stack.gif plots/LM9t_AlphaT_njets_case_minimum_deltaht_DL.gif
.!mv significance.gif plots/LM9t_AlphaT_njets_case_minimum_deltaht_DL_signi.gif

.q;
EOF