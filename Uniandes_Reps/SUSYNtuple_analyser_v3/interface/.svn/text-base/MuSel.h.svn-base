bool MuSel(float pt, float eta, float chi, int nhits, float mud0, int glob){
  if(pt < Mu_Pt_Cut )
    return false;
  if(eta > Mu_Eta_Cut )
    return false;
  if(chi > Mu_Chi2dof_Cut)
    return false;
  if(nhits < Mu_NHits_Cut)
    return false;
  if(mud0 > Mu_D0_Cut)
    return false;
  if(glob == 0 )
    return false;
  return true;
}
