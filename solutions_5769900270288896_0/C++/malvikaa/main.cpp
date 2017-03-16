#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdio>
#include <map>
#include <cstring>

#include <queue>
using namespace std;

int N,M;

int adj[2][2] = { {0,1}, {1,0} };

int count(int grid){
	int i,j,k,i1,j1;

	int ct = 0;
	for(i =0 ; i < M; ++i){
		for(j = 0; j < N; ++j){
			if(!(grid&(1<<(i*N+j)))) continue;
			for(k = 0; k < 2; ++k){
				i1 = i+adj[k][0];
				j1 = j+adj[k][1];
				if(i1 >= M || j1 >= N) continue;
				if(grid&(1<<(i1*N+j1))) ++ct;
			}

		}
	}

	return ct;
}


int main(){

	int t,t1,k,grid;

	cin >> t1;

	for(t = 1; t <= t1; ++t){
		cin >> M >> N >> k;

		int sol = (1e9);
		for(grid = 1; grid < (1<<(M*N)); ++grid){
			if(__builtin_popcount(grid) != k) continue;
			sol = min(sol,count(grid));
		}

		if(!k) sol = 0;
		cout << "Case #" << t << ": " << sol << "\n";
	}

	return 0;
}
