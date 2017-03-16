#include <bits/stdc++.h>
using namespace std;
#define int long long
int putCase(){
	static int t = 1;
	cout << "Case #"<< t++ << ": ";
}

int naive(int R,int C,int N){
	int res = 1e9;
	int M = R*C;
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
	return res;
}

int greedy(int R,int C,int N,int p){
	if( R > C ) return greedy(C,R,N,p);
	vector<vector<int>> f(R,vector<int>(C));
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			if( (i+j)%2 == p && N){
				N--;
				f[i][j] = true;
			}
		}
	}
	int ans = 0;
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			if( min(R-1-i,i) == 0 && min(C-1-j,j) == 0 ){
				if( N && !f[i][j]){
					N--;
					f[i][j] = true;
					ans += 2 - (R==1);
				}
			}
		}
	}
	
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			if( min(R-1-i,i) == 0 || min(C-1-j,j) == 0 ){
				if( N && !f[i][j]){
					N--;
					f[i][j] = true;
					ans += 3 - (R==1);
				}
			}
		}
	}
	
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			if( N && !f[i][j]){
				N--;
				f[i][j] = true;
				ans += 4;
			}
		}
	}
	return ans;
}

int g(int R,int C,int N){
	return  min(greedy(R,C,N,0),greedy(R,C,N,1));
}
signed main(){
	/*while(true){
			int w = rand() % 8 + 1;
			int h = rand() % 8 + 1;
			if( w * h > 20 ) continue;
			int n = rand() % (w*h);
			if( g(w,h,n) != naive(w,h,n) ){
				cout << w << " " << h << " " << n << endl;
			}
			
		}
	*/
	int T;
	cin >> T;
	while(T--){

		int R,C,N;
		cin >> R >> C >> N;
		putCase();
		cout << g(R,C,N) << endl;
		
		
	}
}