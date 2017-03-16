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
	int T, N, Ns[1005];
	cin >> T;
	for(int caso=1; caso<=T; ++caso){
		cin >> N;
		int res1 = 0, res2 = 0;
		for(int i=0; i<N; ++i){
			cin >> Ns[i];
		}
		
		for(int i=1; i<N; ++i){
			res1 += max(0,Ns[i-1]-Ns[i]);
		}
		
		int maxdiff = 0;
		for(int i=1; i<N; ++i){
			maxdiff = max(maxdiff,(Ns[i-1]-Ns[i])); 
		}
		
		
		
		for(int i=0; i<N-1; ++i){
			res2 += min(maxdiff,Ns[i]);
		}
		
		
		cout << "Case #" << caso << ": " << res1 << " " << res2 <<  endl;
	}
	return 0;
}
