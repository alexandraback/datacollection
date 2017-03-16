#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 1002

typedef long long ll;
typedef vector< int > vi;
typedef vector< ll > vll;

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		vi a;
		REP( i , n ){
			int x;
			sc( x );
			a.pb( x );
		}
		int ans0 = 0 , r = 0;
		REP( i , n - 1 )
			if( a[ i ] > a[ i + 1 ] ){
				ans0 += a[ i ] - a[ i + 1 ];
				r = max( r , a[ i ] - a[ i + 1 ] );
			}
		int ans1 = 0;
		REP( i , n - 1 ){
			if( a[ i ] < r ) ans1 += a[ i ];
			else ans1 += r;
		}
		printf( "Case #%d: %d %d\n" , tc + 1 , ans0 , ans1 );
	}
}


