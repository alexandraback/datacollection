#include <bits/stdc++.h>

using namespace std;

int n, c;

int getVal( int mask ){
	int k = 0;
	int mat[20][20];
	memset(mat,0,sizeof(mat));
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < c; j++ ){
			if( mask & (1 << k) ) mat[i][j] = 1;
			k++;
		}
	}
	int ans = 0;
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < c; j++ ){
			if( !mat[i][j] ) continue;
			int xx = i+1;
			int yy = j;
			if( xx >= 0 && xx < n && yy >= 0 && yy < c && mat[xx][yy] ) ans++;
			xx = i;
			yy = j+1;
			if( xx >= 0 && xx < n && yy >= 0 && yy < c && mat[xx][yy] ) ans++;
		}
	}
	return ans;
}

int solve( int pos, int k, int mask ){
	if( k == 0 ) return getVal(mask);
	if( pos >= n*c ) return 1e9;
	return min(solve(pos+1,k,mask),solve(pos+1,k-1,mask|(1<<pos)));
}

int main(){
	ios::sync_with_stdio(false);
	int t, z = 1, k;
	cin >> t;
	while( t-- ){
		cin >> n >> c >> k;
		cout << "Case #" << z++ << ": " << solve(0,k,0) << '\n';
	}
	return 0;
}