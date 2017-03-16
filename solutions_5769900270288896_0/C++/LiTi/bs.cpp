//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define sz(x) ((int)(x).size())    
typedef long long ll;    

int a[20][20];
bool inrange( int a , int b ) { 
    return a >= 0 && a < b; 
}
int dx[] = { 0 , -1 , 0 , 1 } ; 
int dy[] = { 1 , 0 , -1 , 0 } ; 

int solve() { 
    int r,c,n;
    cin >> r >> c >> n; 
    int x = r * c ; 
    int ans = r * c * 100;
    for( int k = 0 ;  k < ( 1 << x ) ; k++ ) { 
	if( __builtin_popcount(k) != n ) continue;
	for( int i = 0 ; i < r ; i++ ) 
	    for( int j = 0 ; j < c ; j++ ) { 
		int x = i*c + j;
		a[i][j] = ( ( k >> x ) & 1 );
	    }
	int tmp = 0;
	for( int i = 0 ; i <r ; i++ ) 
	    for( int j = 0 ; j < c ; j++ ) 
		for( int k = 0 ; k < 4 ; k++ ) 
		    if( inrange( i + dx[k] , r ) && inrange( j + dy[k] , c ) &&
			    a[i][j] && a[i+dx[k]][j+dy[k]] ) 
			tmp ++;
	ans = min( ans , tmp / 2 ) ; 
    }
    return ans;
}

int main() { 
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ) 
	cout << "Case #" << i << ": " << solve() << endl;
}
