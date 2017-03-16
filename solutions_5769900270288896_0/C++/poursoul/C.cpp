#include <stdio.h>
#include <string.h>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std ;

typedef long long LL ;

#define clr( a , x ) memset ( a , x , sizeof a )
#define cpy( a , x ) memcpy ( a , x , sizeof a )

const int MAXN = 20 ;

int idx[MAXN * MAXN] ;
int G[MAXN][MAXN] ;
int r , c , n , rc ;
int ans ;

void dfs ( int cur , int sum ) {
	if ( rc - cur + sum < n ) return ;
	if ( sum > n ) return ;
	if ( cur == rc ) {
		int cost = 0 ;
		for ( int i = 0 ; i < r ; ++ i ) {
			for ( int j = 0 ; j < c ; ++ j ) {
				if ( j < c - 1 ) {
					if ( G[i][j] && G[i][j + 1] ) ++ cost ;
				}
				if ( i < r - 1 ) {
					if ( G[i][j] && G[i + 1][j] ) ++ cost ;
				}
			}
		}
		ans = min ( ans , cost ) ;
		return ;
	}
	int x = idx[cur] / c ;
	int y = idx[cur] % c ;
	G[x][y] = 1 ;
	dfs ( cur + 1 , sum + 1 ) ;
	G[x][y] = 0 ;
	dfs ( cur + 1 , sum ) ;
}

void solve ( int T ) {
	int cnt = 0 ;
	ans = 0x3f3f3f3f ;
	clr ( G , 0 ) ;
	scanf ( "%d%d%d" , &r , &c , &n ) ;
	rc = r * c ;
	for ( int i = 0 ; i < r ; ++ i ) {
		for ( int j = 0 ; j < c ; ++ j ) {
			idx[cnt ++] = i * c + j ;
		}
	}
	dfs ( 0 , 0 ) ;
	printf ( "Case #%d: %d\n" , T , ans ) ;
}


int main () {
	int T ;
	freopen ( "B-small-attempt0.in" , "r" , stdin ) ;
	freopen ( "B-small-attempt0.out" , "w" , stdout ) ;
	scanf ( "%d" , &T ) ;
	for ( int i = 1 ; i <= T ; ++ i ) {
		solve ( i ) ;
	}
	return 0 ;
}