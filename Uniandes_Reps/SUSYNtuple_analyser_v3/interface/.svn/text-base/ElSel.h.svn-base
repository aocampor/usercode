bool ElSel(float pt, float eta, float d0, int conv, int lost, float charge){
  if(pt < El_Pt_Cut)
    return false;
  if(eta > El_Eta_Cut)
    return false;
  if(d0 > El_D0_Cut )
    return false;
  if(conv == 1)
    return false;
  if(lost >= 1)
    return false;
  if(charge == 0)
    return false;
  return true;
}
