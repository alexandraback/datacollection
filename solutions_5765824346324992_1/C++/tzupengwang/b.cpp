//by tzupengwang™
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll;
typedef pair<int,int> ii;

int n ;
ll N , s[ 10005 ] ;

void init() {
	scanf( "%d%lld" , &n , &N ) ;
	for ( int i = 0 ; i < n ; i ++ ) {
		scanf( "%lld" , &s[ i ] ) ;
	}
}

int process() {
	ll L = 0 , R = 1LL << 60 ;
	while ( L < R ) {
		ll M = ( L + R ) / 2 ;
		ll cnt = 0 , av = 0 ;
		for ( int i = 0 ; i < n ; i ++ ) {
			cnt += ( ( M - 1 ) / s[ i ] + 1 ) ;
			if ( M % s[ i ] == 0 ) av ++ ;
		}
		if ( cnt < N && N <= cnt + av ) {
			ll ss = N - cnt ;
			for ( int i = 0 ; i < n ; i ++ ) {
				if ( M % s[ i ] == 0 ) {
					if ( -- ss == 0 ) {
						return i + 1 ;
					}
				}
			}
		} else if ( cnt >= N ) {
			R = M ;
		} else {
			L = M + 1 ;
		}
	}
	return -1 ;
}

int main() {
	int Cases;
	scanf( "%d" , &Cases ) ;
	for ( int cases = 1 ; cases <= Cases ; cases ++ ) {
		init() ;
		printf( "Case #%d: %d\n" , cases , process() ) ;
	}
	return 0 ;
}

