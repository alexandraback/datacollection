#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>

using namespace std ;

int N , TestCase , V[20] ;

int main( int argc , char* argv[] ) {
	freopen( "A.in" , "r" , stdin ) ;
	freopen( "A.out" , "w" , stdout ) ;
	scanf( "%d" , &TestCase ) ;
	for( int TC = 1 ; TC <= TestCase ; TC++ ) {
		memset( V , 0 , sizeof( V ) ) ;
		scanf( "%d" , &N ) ;
		N-- ;
		for( int i = 0 ; i < 4 ; i++ )
		for( int j = 0 ; j < 4 ; j++ ) {
			int x ;
			scanf( "%d" , &x ) ;
			if( N == i ) {
				V[x]++ ;
			}
		}
		scanf( "%d" , &N ) ;
		N-- ;
		for( int i = 0 ; i < 4 ; i++ )
		for( int j = 0 ; j < 4 ; j++ ) {
			int x ;
			scanf( "%d" , &x ) ;
			if( N == i ) {
				V[x]++ ;
			}
		}
		int ans = -1 ;
		for( int i = 1 ; i <= 16 ; i++ )
		if( V[i] == 2 ) {
			if( ans == -1 ) {
				ans = i ;
			} else {
				ans = -2 ;
				break ;
			}
		}
		printf( "Case #%d: " , TC ) ;
		if( ans == -1 ) {
			printf( "Volunteer cheated!\n" ) ;
		} else if( ans == -2 ) {
			printf( "Bad magician!\n" ) ;
		} else {
			printf( "%d\n" , ans ) ;
		}
	}
	return 0 ;
}	

