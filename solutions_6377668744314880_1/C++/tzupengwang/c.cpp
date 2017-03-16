//by tzupengwang™
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll;
typedef pair<int,int> ii;

int n ;
struct POINT {
	ll x , y ;
	POINT() {}
	POINT( ll xx , ll yy ) : x( xx ) , y( yy ) {}
	POINT operator-( POINT &q ) {
		return POINT( x - q.x , y - q.y ) ;
	}
} p[ 10005 ] ;

ll cross( POINT a , POINT b ) {
	return a.x * b.y - a.y * b.x ;
}

void init() {
	scanf( "%d" , &n ) ;
	for ( int i = 0 ; i < n ; i ++ ) scanf( "%lld%lld" , &p[ i ].x , &p[ i ].y ) ;
}

vector< POINT > v ;
int pivot ;
bool cmp( POINT a , POINT b ) {
	POINT A( a.x - p[ pivot ].x , a.y - p[ pivot ].y ) ;
	POINT B( b.x - p[ pivot ].x , b.y - p[ pivot ].y ) ;
	if ( A.y > 0 && B.y < 0 ) return true ;
	else if ( A.y < 0 && B.y > 0 ) return false ;
	return A.x * B.y - A.y * B.x > 0 ;
}

int nowsz ;
int nxt( int i ) {
	return ( i + 1 ) % nowsz ;
}
int sub( int a , int b ) {
	return ( a + nowsz - b ) % nowsz ;
}

int id[ 10005 ] ;
int ans[ 10005 ] ;

void process() {
	for ( int i = 0 ; i < n ; i ++ ) ans[ i ] = 100000 ;
	for ( int i = 0 ; i < n ; i ++ ) { //i : iterate through all points
		pivot = i ;
		v.clear() ;
		for ( int j = 0 ; j < n ; j ++ ) if ( i != j ) v.push_back( p[ j ] ) ;
		sort( v.begin() , v.end() , cmp ) ;
		//puts( "SSS" ) ;
		POINT A( p[ pivot ] ) ;
		nowsz = (int)v.size() ;
		for ( int k = 0 , p1 = 0 , p2 = 1 ; k < (int)v.size() ; k ++ ) {
			//printf( "at point %d: (%lld , %lld)\n" , k , v[ k ].x , v[ k ].y ) ;
			POINT tmp = A - v[ k ] ;
			while ( nxt( p1 ) != k && cross( tmp , v[ nxt( p1 ) ] - A ) < 0 ) p1 = nxt( p1 ) ;
			while ( p2 != k && cross( tmp , v[ p2 ] - A ) <= 0 ) p2 = nxt( p2 ) ;
			ans[ i ] = min( ans[ i ] , sub( p1 , k ) ) ;
			ans[ i ] = min( ans[ i ] , sub( k , p2 ) ) ;
			//printf( "p1 = %d , p2 = %d\n" , p1 , p2 ) ;
			if ( p1 == k ) p1 = nxt( p1 ) ;
		}
	}
	if ( n == 1 ) ans[ 0 ] = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		printf( "%d\n" , ans[ i ] ) ;
	}
}

int main() {
	int Cases;
	scanf( "%d" , &Cases ) ;
	for ( int cases = 1 ; cases <= Cases ; cases ++ ) {
		init() ;
		printf( "Case #%d:\n" , cases ) ;
		process() ;
	}
	return 0 ;
}

