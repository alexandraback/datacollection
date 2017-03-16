#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <algorithm>
using namespace std ;

typedef long long LL ;
typedef unsigned long long ULL ;

#define rep( i , a , b ) for ( int i = ( a ) ; i <  ( b ) ; ++ i )
#define For( i , a , b ) for ( int i = ( a ) ; i <= ( b ) ; ++ i )
#define rev( i , a , b ) for ( int i = ( a ) ; i >= ( b ) ; -- i )
#define clr( a , x ) memset ( a , x , sizeof a )

const int MAXN = 6005 ;
const double eps = 1e-8 ;
const double pi = acos ( -1.0 ) ;

struct Point {
	int x , y ;
	Point () {}
	Point ( int x , int y ) : x ( x ) , y ( y ) {}
	Point operator - ( const Point& p ) const {
		return Point ( x - p.x , y - p.y ) ;
	}
} ;

Point p[MAXN] ;
double a[MAXN] ;
int n ;

int dcmp ( double x ) {
	return ( x > eps ) - ( x < -eps ) ;
}

void solve ( int T ) {
	printf ( "Case #%d:\n" , T ) ;
	scanf ( "%d" , &n ) ;
	rep ( i , 0 , n ) scanf ( "%d%d" , &p[i].x , &p[i].y ) ;
	rep ( i , 0 , n ) {
		rep ( j , 0 , n ) {
			Point tmp = p[j] - p[i] ;
			a[j] = atan2 ( tmp.y , tmp.x ) ;
			if ( dcmp ( a[j] ) < 0 ) a[j] = pi * 2 + a[j] ;
		}
		a[i] = 100000 ;
		sort ( a , a + n ) ;
		int m = n - 1 ;
		map < double , int > mp ;
		rep ( j , 0 , m ) {
			a[j + m] = a[j] + 2 * pi ;
			mp[a[j]] ++ ;
		}
		//rep ( j , 0 , 2 * m ) printf ( "%.5f " , a[j] ) ;
		//printf ( "\n" ) ;
		int ans = 10000 ;
		int r = 0 ;
		rep ( j , 0 , m ) {
			while ( r < m * 2 && dcmp ( a[r] - a[j] - pi ) < 0 ) ++ r ;
			int x = 0 ;
			For ( k , j , m ) {
				if ( dcmp ( a[k] - a[j] ) == 0 ) ++ x ;
				else break ;
			}
			//printf ( "%d %d %d\n" , j , r , x ) ;
			int t = r - j - x ;
			//printf ( "-------%d %d\n" , t , m - x - t ) ;
			ans = min ( ans , min ( t , m - x - t ) ) ;
		}
		printf ( "%d\n" , ans ) ;
	}
}

int main () {
	int T ;
	freopen ( "C-small-attempt2.in" , "r" , stdin ) ;
	freopen ( "C-small-attempt2.out" , "w" , stdout ) ;
	scanf ( "%d" , &T ) ;
	For ( i , 1 , T ) solve ( i ) ;
	return 0 ;
}