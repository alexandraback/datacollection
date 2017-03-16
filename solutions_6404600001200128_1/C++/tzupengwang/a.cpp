//by tzupengwang™
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll;
typedef pair<int,int> ii;

int n ;
int s[ 10005 ] ;

void init() {
	scanf( "%d" , &n ) ;
	for ( int i = 0 ; i < n ; i ++ ) {
		scanf( "%d" , &s[ i ] ) ;
	}
}

void process() {
	int ans1 = 0 , ans2 = 0 ;
	for ( int i = 1 ; i < n ; i ++ ) {
		if ( s[ i ] < s[ i - 1 ] ) ans1 += s[ i - 1 ] - s[ i ] ;
	}
	int mx = 0 ;
	for ( int i = 1 ; i < n ; i ++ ) {
		if ( s[ i ] < s[ i - 1 ] ) mx = max( mx , s[ i - 1 ] - s[ i ] ) ;
	}
	for ( int i = 0 ; i < n - 1 ; i ++ ) {
		ans2 += min( mx , s[ i ] ) ;
	}
	printf( "%d %d\n" , ans1 , ans2 ) ;
}

int main() {
	int Cases;
	scanf( "%d" , &Cases ) ;
	for ( int cases = 1 ; cases <= Cases ; cases ++ ) {
		init() ;
		printf( "Case #%d: " , cases ) ;
		process() ;
	}
	return 0 ;
}

