std::vector<std::vector<double> > AlphaT(std::vector<std::vector< double > > Jetsp){
  std::vector<double> njet_htvec;
  for(int i=0;i<5;i++){
    njet_htvec.push_back(0.);
  }
  std::vector<std::vector<double> > Jets;
  std::vector<double> pseudojet1;
  std::vector<double> pseudojet2;
  std::vector<std::vector<double> > pseudo;

  int jet_index_copy[50];
  int jet2_index_copy[50];

  for(int i=0;i<4;i++){
    pseudojet1.push_back(0.);
    pseudojet2.push_back(0.);
  }
  std::vector<double> temp;
  for(unsigned int i = 0; i<Jetsp.size(); i++ ){
    if(Jetsp[i][1] > Jet_Pt_Cut && fabs(Jetsp[i][5]) < Jet_Eta_Cut){
      temp.push_back(Jetsp[i][0]);
      temp.push_back(Jetsp[i][1]);
      temp.push_back(Jetsp[i][2]);
      temp.push_back(Jetsp[i][3]);
      temp.push_back(Jetsp[i][4]);
      temp.push_back(Jetsp[i][5]);
      temp.push_back(Jetsp[i][6]);
      Jets.push_back(temp);
      njet_htvec[0] = njet_htvec[0] + temp[0];
      njet_htvec[1] = njet_htvec[1] + temp[1];
      njet_htvec[2] = njet_htvec[2] + temp[2];
      njet_htvec[3] = njet_htvec[3] + temp[3];
      njet_htvec[4] = njet_htvec[4] + temp[4];
      temp.clear();
    }
  }
  float temp_deltaht;
  //  float pt1,pt2,eta1,eta2,phi1,phi2;
  float njet_deltaht = 1e8;
  for(unsigned int n1=1;n1<=Jets.size()/2;n1++){
    int end_flag = 0;
    int jet_index[50];
    int jet2_index[50];
    for( int a=0; a<50; a++) jet_index[a] = -1;
    for(unsigned int a=0; a<n1; a++){
      jet_index[a] = n1-1-a;
    }
    jet_index[0] -= 1;
    while(end_flag==0){ //search all combinations for lowest deltaHT value
      jet_index[0]++;
      if((int)jet_index[0] == (int)Jets.size()){
	int carry=0;
	for(unsigned int a=1; a<n1; a++) {
	  if((int)jet_index[a] < (int)(Jets.size()-1-a)) { //find closest digit than can be incremented 
	    carry = a;
	    jet_index[a]++;
	  }
	}
	if(carry==0) {end_flag=1; continue;} //no more combinations
	for(int a=0; a<carry; a++) { //reset all previous digits; avoid double counting
	  jet_index[a] = jet_index[carry]+(carry-a);
	}
      }
      for(int k1 = 0; k1 < 50; k1++){
	jet2_index[k1]=-1;
      }
      for(unsigned int k1 = 0; k1 < Jets.size(); k1++){
	bool match=false;
	for(unsigned int k2 = 0; k2 < n1; k2++){
	  if((int)k1==jet_index[k2])
	    match = true;
	}
	if(!match)
	  jet2_index[k1]=k1;
      }
      //Compute deltaHT for given combination
      //	  float jet1_ht[5] = {0,0,0,0,0};
      std::vector<double> jet1_ht;
      std::vector<double> jet2_ht;
      for(int a=0;a<7;a++){
	jet1_ht.push_back(0.);
	jet2_ht.push_back(0.);
      }
      for(unsigned int a=0; a<n1; a++) {
	jet1_ht[0] += Jets[jet_index[a]][0];
	jet1_ht[1] += Jets[jet_index[a]][1];
	jet1_ht[2] += Jets[jet_index[a]][2];
	jet1_ht[3] += Jets[jet_index[a]][3];
	jet1_ht[4] += Jets[jet_index[a]][4];
	jet1_ht[5] += Jets[jet_index[a]][5]*Jets[jet_index[a]][0];
	jet1_ht[6] += Jets[jet_index[a]][6]*Jets[jet_index[a]][0];
      }
      jet1_ht[5]=jet1_ht[5]/jet1_ht[0];
      jet1_ht[6]=jet1_ht[6]/jet1_ht[0];
      //	  float jet2_ht[5] = {0,0,0,0,0};
      for(int k1=0; k1 < 50; k1++){
	if(jet2_index[k1]!=-1){
	  jet2_ht[5] += Jets[jet2_index[k1]][5]*Jets[jet2_index[k1]][0];
	  jet2_ht[6] += Jets[jet2_index[k1]][6]*Jets[jet2_index[k1]][0];
	  jet2_ht[0] += Jets[jet2_index[k1]][0];
	}
      }
      jet2_ht[5]=jet2_ht[5]/jet2_ht[0];
      jet2_ht[6]=jet2_ht[6]/jet2_ht[0];
      jet2_ht[0] = njet_htvec[0] - jet1_ht[0];
      jet2_ht[1] = njet_htvec[1] - jet1_ht[1];
      jet2_ht[2] = njet_htvec[2] - jet1_ht[2];
      jet2_ht[3] = njet_htvec[3] - jet1_ht[3];
      jet2_ht[4] = njet_htvec[4] - jet1_ht[4];
      //      temp_deltaht = fabs(sqrt(pow(jet1_ht[2],2)+pow(jet1_ht[3],2)) - sqrt(pow(jet2_ht[2],2)+pow(jet2_ht[3],2)));
      temp_deltaht = fabs(jet1_ht[1] - jet2_ht[1]);
      //save new deltaHT if it is smaller than previous smallest value                                                                       
      float temp1 = 0;
      float temp2 = 0;
      if(temp_deltaht < njet_deltaht) { 
	for(int l=0;l<50;l++){
	  jet_index_copy[l] =jet_index[l];
	  jet2_index_copy[l]=jet2_index[l];
	}
	njet_deltaht = temp_deltaht;
	//	temp1 = sqrt(pow(jet1_ht[0],2)+pow(jet1_ht[1],2));
	//	temp2 = sqrt(pow(jet2_ht[0],2)+pow(jet2_ht[1],2));
	temp1 = jet1_ht[1];
	temp2 = jet2_ht[1];
	if(temp1 > temp2){
	  //pseudojet1[1] = sqrt(pow(jet1_ht[2],2)+pow(jet1_ht[3],2));
	  //pseudojet2[1] = sqrt(pow(jet2_ht[2],2)+pow(jet2_ht[3],2));
	  pseudojet1[1] = jet1_ht[1];
	  pseudojet2[1] = jet2_ht[1];
	  pseudojet1[2] = jet1_ht[5];
	  pseudojet1[3] = jet1_ht[6];
	  pseudojet2[2] = jet2_ht[5];
	  pseudojet2[3] = jet2_ht[6];
	}
	else{
	  //pseudojet2[1] = sqrt(pow(jet1_ht[2],2)+pow(jet1_ht[3],2));
	  //pseudojet1[1] = sqrt(pow(jet2_ht[2],2)+pow(jet2_ht[3],2));
	  pseudojet1[1] = jet2_ht[1];
	  pseudojet2[1] = jet1_ht[1];
	  pseudojet2[2] = jet1_ht[5];
	  pseudojet2[3] = jet1_ht[6];
	  pseudojet1[2] = jet2_ht[5];
	  pseudojet1[3] = jet2_ht[6];
	}
      }
    } //end search all combinations for lowest deltaHT value 
  }
  //  std::cout << "the jets for the first pseudojet are: ";
  //  for(int k=0;k<50;k++){
  //    if(jet_index_copy[k] != -1)
  //      std::cout << " " << jet_index_copy[k]+1;
  //  }
  //  std::cout << std::endl;
  //  std::cout << "the jets for the second pseudojet are: ";
  //  for(int k=0;k<50;k++){
  //    if(jet2_index_copy[k] != -1)
  //      std::cout << " " << jet2_index_copy[k]+1;
  //  }
  //  std::cout << std::endl;

  //  std::cout << "Jet1: " << std::endl;
  //  std::cout << "\tpt " << pseudojet1[1] << std::endl;
  //  std::cout << "\teta " << pseudojet1[2] << std::endl;
  //  std::cout << "\tphi " << pseudojet1[3] << std::endl;
  //  std::cout << "Jet2: " << std::endl;
  //  std::cout << "\tpt " << pseudojet2[1] << std::endl;
  //  std::cout << "\teta " << pseudojet2[2] << std::endl;
  //  std::cout << "\tphi " << pseudojet2[3] << std::endl;
  //  std::cout << "Delta HT: " << temp_deltaht << std::endl;
  
  float num = njet_htvec[1] - njet_deltaht;
  float njet_mht = njet_htvec[2]*njet_htvec[2]+njet_htvec[3]*njet_htvec[3];
  float den = sqrt(njet_htvec[1]*njet_htvec[1]-njet_mht);
  float alphat = 0.5*num/den;
  pseudojet1[0] = alphat;
  pseudojet2[0] = alphat;
  pseudo.push_back(pseudojet1);
  pseudo.push_back(pseudojet2);
  return pseudo;
}
