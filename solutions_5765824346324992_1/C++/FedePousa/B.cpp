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

long long T, B, N, Ms[1005];

bool puedo(long long med){
	long long aten = 0;
	for(int i=0; i<B; ++i){
		aten += 1+(med/Ms[i]); 
	}
	return aten>=N;
}

int main(){
	cin >> T;
	for(int caso=1; caso<=T; ++caso){
		cin >> B >> N;
		int res;
		long long maxi = 0;
		for(int i=0; i<B; ++i){
			cin >> Ms[i];
			maxi = max(maxi,(long long)Ms[i]);
		}
		
		if(B>=N){
			cout << "Case #" << caso << ": " << N << endl;
			continue;
		}
		
		long long inf, med, sup;
		inf = 0LL;
		sup = maxi*(N+1);
		
		while(inf+1!=sup){
			med = (inf+sup)>>1;
			if(puedo(med)){
				sup = med;
			}else{
				inf = med;
			}
			
		}
		
		long long yaaten = 0;
		vector<int> libres;
		
		for(int i=0; i<B; ++i){
			if(sup%Ms[i]==0)libres.push_back(i+1);
			yaaten += 1+((sup-1)/Ms[i]);
		}
		
		res = libres[N-yaaten-1];
		
		cout << "Case #" << caso << ": " << res << endl;
	}
	return 0;
}
