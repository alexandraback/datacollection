#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std ;

typedef long long LL ;
typedef unsigned long long ULL ;

#define rep( i , a , b ) for ( int i = ( a ) ; i <  ( b ) ; ++ i )
#define For( i , a , b ) for ( int i = ( a ) ; i <= ( b ) ; ++ i )
#define rev( i , a , b ) for ( int i = ( a ) ; i >= ( b ) ; -- i )
#define clr( a , x ) memset ( a , x , sizeof a )
#define ls ( o << 1 )
#define rs ( o << 1 | 1 )
#define lson ls , l , m
#define rson rs , m + 1 , r
#define root 1 , 1 , n
#define rt o , l , r
#define mid ( ( l + r ) >> 1 )

const int MAXN = 100005 ;

int b , n ;
int a[MAXN] ;

LL calc ( LL t ) {
	LL cnt = 0 ;
	For ( i , 1 , b ) cnt += ( t - 1 ) / a[i] + 1 ;
	return cnt ;
}

void solve ( int T ) {
	scanf ( "%d%d" , &b , &n ) ;
	For ( i , 1 , b ) scanf ( "%d" , &a[i] ) ;
	LL l = 0 , r = 1e18 ;
	while ( l < r ) {
		LL m = ( l + r + 1 ) >> 1 ;
		if ( calc ( m ) < n ) l = m ;
		else r = m - 1 ;
	}
	LL cnt = calc ( l ) ;
	For ( i , 1 , b ) if ( l % a[i] == 0 ) {
		++ cnt ;
		if ( cnt == n ) {
			printf ( "Case #%d: %d\n" , T , i ) ;
			return ;
		}
	}
}

int main () {
	int T ;
	freopen ( "B-small-attempt0.in" , "r" , stdin ) ;
	freopen ( "B-small-attempt0.out" , "w" , stdout ) ;
	scanf ( "%d" , &T ) ;
	For ( i , 1 , T ) solve ( i ) ;
	return 0 ;
}