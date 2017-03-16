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

vll A;
ll f( ll t ){
	if( t == -1 ) return 0;
	ll ans = 0;
	REP( i , SZ( A ) ) ans += t / A[ i ] + 1LL;
	return ans;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n , K;
		sc( n ) , sc( K );
		A.clear();
		REP( i , n ){
			int x;
			sc( x );
			A.pb( x );
		}
		ll lo = -1 , hi = 1000000000000LL;
		while( hi - lo > 1 ){
			ll med = (lo + hi) >> 1LL;
			//cout << med << " " << f( med ) << endl;
			if( f( med ) >= K ) hi = med;
			else lo = med;
		}
		ll t = hi;
		ll cnt = f( hi ) - K;
		vi vec;
		REP( i , n ) if( t % A[ i ] == 0 ) vec.pb( i );
		reverse( all( vec ) );
		//cout << t << " " << cnt << endl;
		//REP( i , SZ( vec ) ) cout << vec[ i ] << " "; cout << endl;
		printf( "Case #%d: %d\n" , tc + 1 , vec[ cnt ] + 1 );
	}	
}
