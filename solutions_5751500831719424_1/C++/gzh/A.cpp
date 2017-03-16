#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std ;
#define rep( i, j, k ) for( i = j ; i <= k ; ++i )
#define Maxn 115
#define MaxL 115
#define Inf ( ~0U >> 1 )

int T, Case, Ans, n ;
int L[Maxn], C[MaxL], tC[MaxL] ;
char S[Maxn][MaxL] ;

struct node {
	int v ;
	char ch ;
	inline void pair( int a, char b ){
		v = a, ch = b ;
	}
} ar[Maxn][MaxL] ;

bool Check()
{
	int i, j ;
	
	rep( i, 2, n ) {
		if( L[i] != L[1] ) return false ;
		rep( j, 1, L[1] ) 
			if( ar[1][j].ch != ar[i][j].ch )
				return false ;
	}
	return true ;
}

int main()
{
	int i, j, k ;
	
	freopen("A-large.in","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	for( scanf("%d", &T) ; T-- ; ) {
		Ans = 0 ;
		memset( C, 0, sizeof( C ) ) ;
		memset( L, 0, sizeof( L ) ) ;
		memset( ar, 0, sizeof( ar ) ) ;
		memset( S, 0, sizeof( S ) ) ;
		
		scanf("%d\n", &n) ;
		rep( i, 1, n ) 
			scanf("%s", S[i]+1) ;
		
		rep( i, 1, n ) 
			for( j = 1 ; j <= strlen( S[i]+1 ) ; ) {
				for( k = j ; S[i][k] == S[i][j] ; ++j ) ;
				ar[i][++L[i]].pair( j-k, S[i][k] ) ;
			}
		
		if( Check() ) {
			rep( i, 1, L[1] ) {
				memset( tC, 0, sizeof( tC ) ) ; 
				rep( j, 1, n ) 
					tC[j] = ar[j][i].v ;
				sort( tC+1, tC+1+n ) ; 
				C[i] = tC[(n>>1)+1] ;
			}
			rep( i, 1, n ) {
				rep( j, 1, L[1] )
					Ans += abs( C[j] - ar[i][j].v ) ;	
			}
			
			printf("Case #%d: %d\n", ++Case, Ans) ;	
			
		} else printf("Case #%d: Fegla Won\n", ++Case ) ;

	}
//	system("pause") ;
	return 0 ; 	
}

