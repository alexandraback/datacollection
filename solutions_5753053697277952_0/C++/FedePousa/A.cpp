#define Federico using
#define Javier namespace
#define Pousa std;
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>


Federico Javier Pousa

int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

int main(){
	int T;
	cin >> T;
	for(int caso=1; caso<=T; ++caso){
		int N;
		int Ps[30];
		cin >> N;
		int cant = 0;
		for(int i=0; i<N; ++i){
			cin >> Ps[i];
			cant += Ps[i];
		}
		cout << "Case #" << caso << ":";
		
		if(N==2){
			for(int i=0; i<cant/2; ++i){
				cout << " AB";
			}
			cout << endl;
			continue;
		}
		
		
		while(cant>2){
			int maxi = 0;
			for(int i=0; i<N; ++i){
				if(Ps[i]>Ps[maxi])maxi=i;
			}
			char c = 'A' + maxi;
			cout << " " << c;
			Ps[maxi]--;
			cant--;
		}
		string ult = "";
		for(int i=0; i<N; ++i){
			if(Ps[i])ult+=('A'+i);
		}
		cout << " " << ult << endl;
	}
	
	return 0;
}
