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
#define EPS (1e-8)
#define PI acos(-1.0)

typedef long long ll;
typedef vector< int > vi;
typedef vector< ll > vll;
typedef long double ld;

struct Point{
	ll x , y;
	Point(){ x = y = 0;}
	Point( ll x , ll y ) : x( x ) , y( y ) {}	
	ld getAngle(){
		return atan2( y , x );
	}
};
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }

ll cross( const Point &A , const Point &B ){ return A.x * B.y - A.y * B.x; }
ll area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }

int NEXT( int p , int n ){
	return (p + 1)%n;
}
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
		REP( it , n ){
			int ans = INT_MAX;
			vector< pair< ld , int > > vec;
			REP( j , n ){
				if( it == j ) continue;
				Point W = (P[ j ] - P[ it ]);
				vec.pb( mp( W.getAngle() , j ) );
			}
			sort( all( vec ) );
			vector< Point > V;
			REP( i , SZ( vec ) ) V.pb( P[ vec[ i ].se ] - P[ it ] );
			//cout << "point i " << it << endl;
			//REP( i , SZ( V ) ) cout << V[ i ].x << " " << V[ i ].y << endl;
			for( int i = 0 , j = 0 ; i < SZ( V ) ; ++i ){
				while( 1 ){
					int next = NEXT( j , SZ( V ) );
					if( next == i ) break;
					if( cross( V[ i ] , V[ next ] ) < 0 ) break;
					j = next;
				}
				
				int len = (i <= j) ? (j - i + 1) : (j + 1 + (SZ( V )- 1 - i + 1) );
				len ++;
				//cout << i << " " << j << " " << len << endl;
				ans = min( ans , n - len );
			}
			printf( "%d\n" , ans );
		}
	}
}
