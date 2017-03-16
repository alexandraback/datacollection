#include <bits/stdc++.h>
using namespace std;

int G[16][16];

int main(){
	int T,R,C,N;
	cin >> T;
	for(int t = 1;t <= T;t++){
		cin >> R >> C >> N;
		int ans = 100000;
		for(int i = 0;i < (1 << (R*C));i++){
			int ctr = 0,ctr2 = 0;
			for(int j = 0;j < R*C;j++){
				if(i & (1 << j)) G[j/C][j%C] = 1;
				else G[j/C][j%C] = 0;
				ctr2 += G[j/C][j%C];
				int x = j/C,y = j%C;
				if(x) ctr += G[x][y] && G[x - 1][y];
				if(y) ctr += G[x][y] && G[x][y - 1];
			}
			if(ctr2 == N) ans = min(ctr,ans);
		}
		printf("Case #%d: %d\n",t,ans);
	}	
	return 0;
}