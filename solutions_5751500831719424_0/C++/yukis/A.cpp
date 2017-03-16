#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 100 ;
const int MAXL = 100 + 10 ;

char data[ MAXN ] [ MAXL ] ;
int now[ MAXN ] , cnt[ MAXN ] ;
int n ;

int abs( int x ) {
	if ( x < 0 ) return -x ;
	return x ;
}

int DFS() {
	int finished = 0 ;
	for ( int i = 0 ; i < n ; i ++ )
		if ( now[ i ] > strlen( data[ i ] ) )
			finished ++ ;
	if ( finished > 0 ) {
		if ( finished != n ) return -1 ;
		return 0 ;
	}

	for ( int i = 1 ; i < n ; i ++ )
		if ( data[ i ] [ now[ i ] ] != data[ i - 1 ] [ now[ i - 1 ] ] )
			return -1 ;

	char c = data[ 0 ] [ now[ 0 ] ] ;
	for ( int i = 0 ; i < n ; i ++ ) {
		cnt[ i ] = 0 ;
		while ( now[ i ] <= strlen( data[ i ] ) && data[ i ] [ now[ i ] ] == c ) {
			cnt[ i ] ++ ;
			now[ i ] ++ ;
		}
	}
	int cici = -1 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		int vivi = 0 ;
		for ( int j = 0 ; j < n ; j ++ )
			vivi += abs( cnt[ j ] - cnt[ i ] ) ;
		if ( cici == -1 || vivi < cici )
			cici = vivi ;
	}

	int ans = DFS() ;
	if ( ans == -1 ) return -1 ;
	return ans + cici ;
}

int main() {
	freopen( "A-small-attempt0.in" , "r" , stdin ) ;
	freopen( "A-small-attempt0.out" , "w" , stdout ) ;
	int test_case ;
	scanf( "%d" , &test_case ) ;
	for ( int t = 1 ; t <= test_case ; t ++ ) {
		scanf( "%d" , &n ) ;
		for ( int i = 0 ; i < n ; i ++ )
			scanf( "%s" , data[ i ] ) ;

		memset( now , 0 , sizeof( now ) ) ;
		int ans = DFS() ;

		printf( "Case #%d: " , t ) ;
		if ( ans == -1 ) printf( "Fegla Won\n" ) ; else printf( "%d\n" , ans ) ;
	}
}