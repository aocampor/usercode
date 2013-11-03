bool PFElSel(float pt, float eta, float mva, float d0, int conv, int lost, float charge){
  if(pt < El_Pt_Cut)
    return false;
  if(eta > El_Eta_Cut)
    return false;
  if(mva < El_MVA_Cut)
    return false;
  if(d0 > El_D0_Cut )
    return false;
  return true;
}
