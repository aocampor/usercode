std::vector<std::vector<double> > AlphaTReClus(std::vector<std::vector< double > > Jetsp){
  float rmin = 10;
  std::vector<std::vector <double> > Jets1;
  std::vector<std::vector <double> > Jets2;
  std::vector <double> temp;
 
  /*
  for(unsigned int i = 0 ; i<Jetsp.size() ; i++){
    cout << "Jet " << i << endl;
    for(int j = 0 ; j < Jetsp[i].size() ; j++){
      cout << Jetsp[i][j] << " ";
    }
    cout << endl;
  }
  */
  Jets1.clear();
  Jets1 = Jetsp;
  int js = 0;
  std::vector<double> ht;
  for (unsigned int i=0;i<4;i++){
    ht.push_back(0.);
  }
  for(unsigned int i=0; i<Jets1.size(); i++){
    if(Jets1[i][1] > Jet_Pt_Cut){
      js++;
      ht[0]+=Jets1[i][1];
      ht[2]+=Jets1[i][2];
      ht[3]+=Jets1[i][3];
    }
  }
  ht[1]=sqrt(ht[2]*ht[2]+ht[3]*ht[3]);
  while( js > 2 ){
    //    Jets1.clear();
    Jets2.clear();
    int sel1 = 0;
    int sel2 = 0;
    double dimin = 1e09;
    double dijmin = 1e09;
    for (unsigned int i=0;i<Jets1.size();i++){
      double di = pow(Jets1[i][0],2);
      if(di < dimin){
	dimin = di;
	sel1 = i;
      }
    }
    for (unsigned int j=0;j<Jets1.size();j++){
      if((int)j != sel1){
	float etmin = 0;
	if(pow(Jets1[sel1][0],2) > pow(Jets1[j][0],2)) etmin = pow(Jets1[j][0],2);
	else etmin = pow(Jets1[sel1][0],2);
	float deltaeta = Jets1[sel1][5]-Jets1[j][5];
	float deltaphi = Jets1[sel1][6]-Jets1[j][6];
	float dr = deltaeta*deltaeta+deltaphi*deltaphi;
	double dij = etmin*dr/(rmin*rmin);
	if( dij < dijmin){
	  dijmin = dij;
	  sel2 = j;
	}
      }
    }
    rmin = sqrt(dijmin*rmin*rmin/dimin);
    for(unsigned int i= 0; i< Jets1.size(); i++ ){
      if((int)i == sel1){
	temp.clear();
	temp.push_back(Jets1[i][0]+Jets1[sel2][0]);
	temp.push_back(Jets1[i][1]+Jets1[sel2][1]);
	temp.push_back(Jets1[i][2]+Jets1[sel2][2]);
	temp.push_back(Jets1[i][2]+Jets1[sel2][3]);
	temp.push_back(Jets1[i][2]+Jets1[sel2][4]);
	temp.push_back((Jets1[i][0]*Jets1[i][5]+Jets1[sel2][0]*Jets1[sel2][5])/(Jets1[i][0]+Jets1[sel2][0]));
	temp.push_back((Jets1[i][0]*Jets1[i][6]+Jets1[sel2][0]*Jets1[sel2][6])/(Jets1[i][0]+Jets1[sel2][0]));
	Jets2.push_back(temp);
      }
      if((int)i != sel1 && (int)i != sel2)
	Jets2.push_back(Jets1[i]);
    }
    Jets1.clear();
    Jets1 = Jets2;
    js = 0;
    for(unsigned int i=0;i<Jets1.size();i++){
      double pt = sqrt(pow(Jets1[i][2],2)+pow(Jets1[i][3],2));
      if( pt > Jet_Pt_Cut && fabs(Jets1[i][5]) < 2.5){
	js++;
      }
    }
  }
  Jets2.clear();
  for(unsigned int j=0;j < Jets1.size();j++ ){
    double pt = sqrt(pow(Jets1[j][2],2)+pow(Jets1[j][3],2));
    if( pt > Jet_Pt_Cut &&  fabs(Jets1[j][5]) < 2.5)
      Jets2.push_back(Jets1[j]);
  }
  Jets1.clear();
  Jets1 = Jets2;
  Jets2.clear();
  float alphat2 = -1;
  float alphat3 = -1;
  float alphat4 = -1;
  if( Jets1.size() == 2){
    double pt1 = sqrt(pow(Jets1[0][2],2)+pow(Jets1[0][3],2));
    double pt2 = sqrt(pow(Jets1[1][2],2)+pow(Jets1[1][3],2));
    int may=0;
    int men=0;
    if(pt1<pt2)
      may = 1;
    else
      men =1;
    alphat2 = sqrt((Jets1[may][0])/(2*Jets1[men][0]*(1-cos(Jets1[may][6]-Jets1[men][6]))));
    double difht =  sqrt(pow(Jets1[may][2],2)+pow(Jets1[may][3],2)) -  sqrt(pow(Jets1[men][2],2)+pow(Jets1[men][3],2));
    alphat3 = 0.5*(ht[0]-difht)/(sqrt(ht[0]*ht[0]-ht[1]*ht[1]));
    float htp = sqrt(Jets1[0][2]*Jets1[0][2]+Jets1[0][3]*Jets1[0][3]) + sqrt(Jets1[1][2]*Jets1[1][2]+Jets1[1][3]*Jets1[1][3]);
    float njet_deltaht = fabs(sqrt(Jets1[may][3]*Jets1[may][3]+Jets1[may][2]*Jets1[may][2])-sqrt(Jets1[men][3]*Jets1[men][3]+Jets1[men][2]*Jets1[men][2]));
    float njet_mht = sqrt(pow(Jets1[may][3] + Jets1[men][3],2) + pow(Jets1[may][2] + Jets1[men][2],2));
    float num = htp - njet_deltaht;
    float den = sqrt(htp*htp-njet_mht*njet_mht);
    alphat4 = 0.5*num/den;
  }
  if(alphat2 == -1){
    temp.push_back(0.);
    temp.push_back(0.);
    Jets1.push_back(temp);
  }
  temp.clear();
  temp.push_back(alphat2);
  temp.push_back(alphat3);
  temp.push_back(alphat4);
  Jets1.push_back(temp);
  if(Jets1.size() == 3)
    if(Jets1[0][5] == Jets1[1][5])
      cout << "Pathology " << Jets1[0][5] << " " << Jets1[1][5] << endl;
  return Jets1;
}
