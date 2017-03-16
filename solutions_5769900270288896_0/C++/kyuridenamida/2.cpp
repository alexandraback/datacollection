#include <bits/stdc++.h>
using namespace std;
int putCase(){
	static int t = 1;
	cout << "Case #"<< t++ << ": ";
}
signed main(){
	int T;
	cin >> T;
	while(T--){

		int R,C,N;
		cin >> R >> C >> N;
		int M = (R*C);
		int res = 1e9;
		for(int i = 0 ; i < (1<<M) ; i++){
			if( __builtin_popcount(i) != N ) continue;
			vector<vector<int>> f(R,vector<int>(C));
			for(int j = 0 ; j < M ; j++)
				if( i >> j & 1 ){
					f[j/C][j%C]=true;
				}
			int ans = 0;
			for(int j = 0 ; j < R ; j++){
				for(int k = 0 ; k < C ; k++){
					if( !f[j][k] ) continue;
					if(j && f[j-1][k]) ans++;
					if(k && f[j][k-1]) ans++;
				}
			}
			res = min(res,ans);
		}
		putCase();
		cout << res << endl;
		
	}
}