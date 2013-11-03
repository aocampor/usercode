float LTprob(int flav, int pf, float pt, float eta){
  int i=10,j=10;
  float result = 0;
  if(pt <= 5)
    i = 0;
  else if( pt <= 10)
    i = 1;
  else if( pt <= 20)
    i = 2;
  else if( pt <= 50)
    i = 3;
  else if( pt <= 100)
    i = 4;
  else
    i = 5;
  if(eta <= -1.75)
    j=0;
  else if(eta <= -1.25)
    j =1;
  else if(eta <= 1.25)
    j =2;
  else if(eta <= 1.75)
    j =3;
  else if(eta <= 3)
    j=4;
  if(flav == 1){
    if(pf == 0){
      if( i == 0 && j == 0)
	result = 0.024;
      else if( i == 0 && j == 1)
	result = 0.072;
      else if( i == 0 && j == 2)
	result = 0.026;
      else if( i == 0 && j == 3)
	result = 0.098;
      else if( i == 0 && j == 4)
	result = 0.019;
      else if( i == 1 && j == 0)
	result = 0.058;
      else if( i == 1 && j == 1)
	result = 0.096;
      else if( i == 1 && j == 2)
	result = 0.039;
      else if( i == 1 && j == 3)
	result = 0.11;
      else if( i == 1 && j == 4)
	result = 0.07;
      else if( i == 2 && j == 0)
	result = 0.17;
      else if( i == 2 && j == 1)
	result = 0.11;
      else if( i == 2 && j == 2)
	result = 0.079;
      else if( i == 2 && j == 3)
	result = 0.13;
      else if( i == 2 && j == 4)
	result = 0.18;
      else if( i == 3 && j == 0)
	result = 0.17;
      else if( i == 3 && j == 1)
	result = 0.14;
      else if( i == 3 && j == 2)
	result = 0.11;
      else if( i == 3 && j == 3)
	result = 0.16;
      else if( i == 3 && j == 4)
	result = 0.21;
      else if( i == 4 && j == 0)
	result = 0.22;
      else if( i == 4 && j == 1)
	result = 0.2;
      else if( i == 4 && j == 2)
	result = 0.12;
      else if( i == 4 && j == 3)
	result = 0.19;
      else if( i == 4 && j == 4)
	result = 0.23;
      else if( i == 5 && j == 0)
	result = 0.33;
      else if( i == 5 && j == 1)
	result = 0.13;
      else if( i == 5 && j == 2)
	result = 0.10;
      else if( i == 5 && j == 3)
	result = 0.05;
      else if( i == 5 && j == 4)
	result = 0.052;
    }
    else{
      if( i == 0 && j == 0)
	result = 0.034;
      else if( i == 0 && j == 1)
	result = 0.044;
      else if( i == 0 && j == 2)
	result = 0.025;
      else if( i == 0 && j == 3)
	result = 0.074;
      else if( i == 0 && j == 4)
	result = 0.08;
      else if( i == 1 && j == 0)
	result = 0.089;
      else if( i == 1 && j == 1)
	result = 0.046;
      else if( i == 1 && j == 2)
	result = 0.059;
      else if( i == 1 && j == 3)
	result = 0.061;
      else if( i == 1 && j == 4)
	result = 0.12;
      else if( i == 2 && j == 0)
	result = 0.17;
      else if( i == 2 && j == 1)
	result = 0.07;
      else if( i == 2 && j == 2)
	result = 0.056;
      else if( i == 2 && j == 3)
	result = 0.077;
      else if( i == 2 && j == 4)
	result = 0.2;
      else if( i == 3 && j == 0)
	result = 0.22;
      else if( i == 3 && j == 1)
	result = 0.089;
      else if( i == 3 && j == 2)
	result = 0.107;
      else if( i == 3 && j == 3)
	result = 0.085;
      else if( i == 3 && j == 4)
	result = 0.209;
      else if( i == 4 && j == 0)
	result = 0.28;
      else if( i == 4 && j == 1)
	result = 0.16;
      else if( i == 4 && j == 2)
	result = 0.10;
      else if( i == 4 && j == 3)
	result = 0.14;
      else if( i == 4 && j == 4)
	result = 0.31;
      else if( i == 5 && j == 0)
	result = 0.19;
      else if( i == 5 && j == 1)
	result = 0.072;
      else if( i == 5 && j == 2)
	result = 0.086;
      else if( i == 5 && j == 3)
	result = 0.056;
      else if( i == 5 && j == 4)
	result = 0.19;
    }
  }
  else if(flav == 2){
    if(pf == 0){
      if( i == 0 && j == 0)
	result = 0.12;
      else if( i == 0 && j == 1)
	result = 0.35;
      else if( i == 0 && j == 2)
	result = 0.068;
      else if( i == 0 && j == 3)
	result = 0.35;
      else if( i == 0 && j == 4)
	result = 0.13;
      else if( i == 1 && j == 0)
	result = 0.049;
      else if( i == 1 && j == 1)
	result = 0.29;
      else if( i == 1 && j == 2)
	result = 0.041;
      else if( i == 1 && j == 3)
	result = 0.29;
      else if( i == 1 && j == 4)
	result = 0.05;
      else if( i == 2 && j == 0)
	result = 0.029;
      else if( i == 2 && j == 1)
	result = 0.31;
      else if( i == 2 && j == 2)
	result = 0.024;
      else if( i == 2 && j == 3)
	result = 0.29;
      else if( i == 2 && j == 4)
	result = 0.032;
      else if( i == 3 && j == 0)
	result = 0.025;
      else if( i == 3 && j == 1)
	result = 0.32;
      else if( i == 3 && j == 2)
	result = 0.036;
      else if( i == 3 && j == 3)
	result = 0.33;
      else if( i == 3 && j == 4)
	result = 0.05;
      else if( i == 4 && j == 0)
	result = 0.12;
      else if( i == 4 && j == 1)
	result = 0.28;
      else if( i == 4 && j == 2)
	result = 0.11;
      else if( i == 4 && j == 3)
	result = 0.2;
      else if( i == 4 && j == 4)
	result = 0.008;
      else if( i == 5 && j == 0)
	result = 0.026;
      else if( i == 5 && j == 1)
	result = 0.28;
      else if( i == 5 && j == 2)
	result = 0.03;
      else if( i == 5 && j == 3)
	result = 0.33;
      else if( i == 5 && j == 4)
	result = 0.076;
    }
    else{
      if( i == 0 && j == 0)
	result = 0.0;
      else if( i == 0 && j == 1)
	result = 0.0;
      else if( i == 0 && j == 2)
	result = 0.0;
      else if( i == 0 && j == 3)
	result = 0.0;
      else if( i == 0 && j == 4)
	result = 0.0;
      else if( i == 1 && j == 0)
	result = 0.03;
      else if( i == 1 && j == 1)
	result = 0.27;
      else if( i == 1 && j == 2)
	result = 0.021;
      else if( i == 1 && j == 3)
	result = 0.27;
      else if( i == 1 && j == 4)
	result = 0.035;
      else if( i == 2 && j == 0)
	result = 0.014;
      else if( i == 2 && j == 1)
	result = 0.28;
      else if( i == 2 && j == 2)
	result = 0.011;
      else if( i == 2 && j == 3)
	result = 0.27;
      else if( i == 2 && j == 4)
	result = 0.016;
      else if( i == 3 && j == 0)
	result = 0.016;
      else if( i == 3 && j == 1)
	result = 0.26;
      else if( i == 3 && j == 2)
	result = 0.008;
      else if( i == 3 && j == 3)
	result = 0.23;
      else if( i == 3 && j == 3)
	result = 0.02;
      else if( i == 4 && j == 0)
	result = 0.018;
      else if( i == 4 && j == 1)
	result = 0.31;
      else if( i == 4 && j == 2)
	result = 0.028;
      else if( i == 4 && j == 3)
	result = 0.23;
      else if( i == 4 && j == 4)
	result = 0.0;
      else if( i == 5 && j == 0)
	result = 0.004;
      else if( i == 5 && j == 1)
	result = 0.2;
      else if( i == 5 && j == 2)
	result = 0.02;
      else if( i == 5 && j == 3)
	result = 0.26;
      else if( i == 5 && j == 4)
	result = 0.08;
    }
  }
  else{
    if(pf == 0){
      if( i == 0 && j == 0)
	result = 0.0;
      else if( i == 0 && j == 1)
	result = 0.0;
      else if( i == 0 && j == 2)
	result = 0.0;
      else if( i == 0 && j == 3)
	result = 0.0;
      else if( i == 0 && j == 4)
	result = 0.0;
      else if( i == 1 && j == 0)
	result = 0.00008;
      else if( i == 1 && j == 1)
	result = 0.0009;
      else if( i == 1 && j == 2)
	result = 0.0022;
      else if( i == 1 && j == 3)
	result = 0.0012;
      else if( i == 1 && j == 4)
	result = 0.00008;
      else if( i == 2 && j == 0)
	result = 0.089;
      else if( i == 2 && j == 1)
	result = 0.1;
      else if( i == 2 && j == 2)
	result = 0.096;
      else if( i == 2 && j == 3)
	result = 0.096;
      else if( i == 2 && j == 4)
	result = 0.086;
      else if( i == 3 && j == 0)
	result = 0.25;
      else if( i == 3 && j == 1)
	result = 0.16;
      else if( i == 3 && j == 2)
	result = 0.17;
      else if( i == 3 && j == 3)
	result = 0.17;
      else if( i == 3 && j == 4)
	result = 0.23;
      else if( i == 4 && j == 0)
	result = 0.35;
      else if( i == 4 && j == 1)
	result = 0.25;
      else if( i == 4 && j == 2)
	result = 0.28;
      else if( i == 4 && j == 3)
	result = 0.23;
      else if( i == 4 && j == 4)
	result = 0.32;
      else if( i == 5 && j == 0)
	result = 0.35;
      else if( i == 5 && j == 1)
	result = 0.30;
      else if( i == 5 && j == 2)
	result = 0.40;
      else if( i == 5 && j == 3)
	result = 0.28;
      else if( i == 5 && j == 4)
	result = 0.34;
    }
    else{
      if( i == 0 && j == 0)
	result = 0.0;
      else if( i == 0 && j == 1)
	result = 0.00;
      else if( i == 0 && j == 2)
	result = 0.0;
      else if( i == 0 && j == 3)
	result = 0.0;
      else if( i == 0 && j == 4)
	result = 0.0;
      else if( i == 1 && j == 0)
	result = 0.0001;
      else if( i == 1 && j == 1)
	result = 0.0013;
      else if( i == 1 && j == 2)
	result = 0.0015;
      else if( i == 1 && j == 3)
	result = 0.0011;
      else if( i == 1 && j == 4)
	result = 0.00028;
      else if( i == 2 && j == 0)
	result = 0.045;
      else if( i == 2 && j == 1)
	result = 0.05;
      else if( i == 2 && j == 2)
	result = 0.051;
      else if( i == 2 && j == 3)
	result = 0.051;
      else if( i == 2 && j == 4)
	result = 0.051;
      else if( i == 3 && j == 0)
	result = 0.095;
      else if( i == 3 && j == 1)
	result = 0.072;
      else if( i == 3 && j == 2)
	result = 0.080;
      else if( i == 3 && j == 3)
	result = 0.074;
      else if( i == 3 && j == 4)
	result = 0.092;
      else if( i == 4 && j == 0)
	result = 0.12;
      else if( i == 4 && j == 1)
	result = 0.10;
      else if( i == 4 && j == 2)
	result = 0.11;
      else if( i == 4 && j == 3)
	result = 0.09;
      else if( i == 4 && j == 4)
	result = 0.12;
      else if( i == 5 && j == 0)
	result = 0.09;
      else if( i == 5 && j == 1)
	result = 0.091;
      else if( i == 5 && j == 2)
	result = 0.11;
      else if( i == 5 && j == 3)
	result = 0.081;
      else if( i == 5 && j == 4)
	result = 0.11;
    }
  }
  return result/(1-result);
}
