#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <cmath>

using namespace std;

int N;
vector<int>P;
int M;

string Evac(int n);

string Alp="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
	ifstream ifs("A-large (10).in");
    ofstream ofs("answer_A_large");
	int T;
	ifs >> T; cout << "T= " << T <<endl;
   
   for(int t=0;t<T;t++){  // test cases
	
    ifs >> N; cout << "N= " << N << endl; 

	P.clear();
	int dummy;
	M=0;
	for(int i= 0;i<N;i++){ 
      ifs>> dummy; P.push_back(dummy); M+=dummy;
	}

cout << "Case #" <<t+1<<": ";
    ofs << "Case #" <<t+1<<": ";


	string str;

	if(N==2){ // N=2�̏ꍇ
		while(M>0){
		if(P[0]!=P[1]){str=Evac(1); cout<<" "<<str;ofs<<" " <<str; }
		else{str=Evac(2); cout<<" "<<str; ofs<<" " <<str;}
		}
		cout<<endl;ofs<<endl;
	}else{ // N>=3�̏ꍇ
		while(M>0){
			if(M>4){str=Evac(1);cout<<" "<<str; ofs<<" " <<str;
             
			}else if(M==4){   str=Evac(2);cout<<" "<<str;ofs<<" " <<str;

			}else if(M==3){   str=Evac(1);cout<<" "<<str;ofs<<" " <<str;

			}else if(M==2){   str=Evac(2); cout<<" "<<str;ofs<<" " <<str;

			}

		}// while fin
       cout<<endl; ofs<<endl;
	}



   } // end of test cases

 return 0;
}

string Evac(int n)
{
    int I=0;
	string str;

	for(int k=0;k<n;k++){
	for(int i=0;i<N;i++){
		if(P[i]>P[I]){I=i;}
	}
    str+=Alp[I]; P[I]--; M--;
	}
	return str;
}