#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <iostream>


using namespace std;

int main(){
	ifstream fi;
	fi.open("tbReadouts_08_02_26__23_26_LTC24.xml");
	string s;
	fi >> s;
//	cout << "String " << s << endl;
	int ter;
	char ta;
//	cin >> ter;
	long event;
	int numol1;
	int numol2=-1;
	int numlb1,numlb2=-1;
	int countlb=0;
	bool flag=false;
	while(s.compare("</rpctDataStream>")!=0){
//		cout << s << " prueba" << endl;
		if(s.compare("<event")==0){
			fi >> ta;
			fi >> ta;
			fi >> ta;
			fi >> ta;
			fi >> ta;
			fi >> event;
//			cout << "any event " << event << endl;
			}
		if(s.compare("<ol")==0){
			fi >> s;
//			cout << "Cadena " << s << endl;
//			cin >> ter;
			fi >> s;
			
			while(s.compare("</ol>")!=0){
				if(s.compare("<lmd")==0){
					fi >> s;
					fi >> s;
					fi >> s;
					fi >> s;
//					cout << s << endl;
					fi >> ta;
					fi >> ta;
					fi >> ta;
					fi >> ta;
					fi >> numlb1;
				//	cout << "lb " << numlb1 << endl;
					if(numlb1!=numlb2){
						countlb++;
				//		cout << event << " " << countlb << endl;
						numlb2=numlb1;
						}
					}
				fi >> s;
//				cout << "final ciclo " << s << endl;
				}
			numlb2=-1;
			}
		if(s.compare("</event>")==0){
			numlb1=-1;
			numlb2=-1;
			if(countlb < 5){
				cout << "The Event: " << event << endl;
				countlb=0;
				}
			else{
				countlb=0;
				}
			}		
		fi >> s;
//		cout << "Stirng " << s << endl;
//		cin >> ter;
		}
	fi.close();
	}
