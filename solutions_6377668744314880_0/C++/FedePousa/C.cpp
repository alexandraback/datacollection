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

#define PI 3.14159265359

int main(){
	int T, N, Xs[3005], Ys[3005];
	cin >> T;
	for(int caso=1; caso<=T; ++caso){
		cin >> N;
		vector<int> res;
		for(int i=0; i<N; ++i){
			cin >> Xs[i] >> Ys[i];
			res.push_back(N-3);
			if(N<=3)res[i] = 0;
		}
		
		if(N>3){
			for(int i=0; i<(1<<N); ++i){
				if(__builtin_popcount(i)<4)continue;
				for(int j=0; j<N; ++j){
					if(!(i&(1<<j)))continue;
					vector<double> angs;
					for(int k=0; k<N; ++k){
						if(j==k)continue;
						if(!(i&(1<<k)))continue;
						angs.push_back(atan2(Ys[k]-Ys[j],Xs[k]-Xs[j]));
					}
					sort(angs.begin(),angs.end());
					bool sirve = false;
					for(int a=0; a<(int)angs.size()-1; ++a){
						if(angs[a+1]-angs[a]>=3.1415925)sirve = true;
					}
					sirve = sirve || (angs[0]+2*PI-angs[angs.size()-1]>=3.1415925);
					if(sirve){
						res[j] = min(res[j],N-__builtin_popcount(i));
					}
					
				}
			}
		}
			
		
		cout << "Case #" << caso << ":" << endl;
		for(int i=0; i<N; ++i){
			cout << res[i] << endl;
		}
	}
	
	return 0;
}
