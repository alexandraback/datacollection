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

struct Point{
	ll x , y;
	Point(){ x = y = 0;}
	Point( ll x , ll y ) : x( x ) , y( y ) {}
};
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }

ll cross( const Point &A , const Point &B ){ return A.x * B.y - A.y * B.x; }
ll area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		vector< Point >P;
		REP( i , n ){
			int x , y;
			sc( x ) , sc( y );
			P.pb( Point( x , y ) );
		}
		printf( "Case #%d:\n" , tc + 1 );
		if( n == 1 ){
			puts( "0" );
			continue;
		}
		REP( i , n ){
			int ans = INT_MAX;
			REP( j , n ){
				if( i == j ) continue;
				int cnt = 0;
				REP( k , n ) if( area( P[ i ] , P[ j ] , P[ k ] ) >= 0 ) cnt ++;
				ans = min( ans , n - cnt );
				
				cnt = 0;
				REP( k , n ) if( area( P[ i ] , P[ j ] , P[ k ] ) <= 0 ) cnt ++;
				ans = min( ans , n - cnt );
			}
			printf( "%d\n" , ans );
		}
	}
}
