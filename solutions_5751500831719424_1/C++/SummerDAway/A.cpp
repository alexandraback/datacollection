//------------------------------------------------------------------------------
//  Problem : 
//  User    : 
//  Date    : 
//------------------------------------------------------------------------------


#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

char A[111][111] ;
int ct[111][111] ;
int M ;

bool calc( int x , int y ) {
	int len1 = strlen( A[x] ) , len2 = strlen( A[y] ) ;
//	printf( "%d %d\n" , len1 , len2 ) ;
	int i = 0 , j = 0 ;
	int ret = 0 ;
	M = 0 ;
	for( i = 0 ; i < len1 ; ) {
		int k = i , l = j ;
		while( i < len1 && A[x][i] == A[x][k] ) i++ ;
		while( j < len2 && A[y][j] == A[x][k] ) j++ ;
		if( j == l ) {
			return false ;
		}
		ct[M][y] = j - l ;
		M++ ;
	}
	if( i == len1 && j == len2 ) {
		return true ;
	} else {
		return false ;
	}
}
		

int main( int argc , char *argv[] )
{
	freopen( "A.in" , "r" , stdin ) ;
	freopen( "A.out" , "w" , stdout ) ;
	int TestCase ;
	scanf( "%d" , &TestCase ) ;
	for( int TC = 1 ; TC <= TestCase ; TC++ ) {
		int N ;
		scanf( "%d" , &N ) ;
		for( int i = 0 ; i < N ; i++ ) {
			scanf( "%s" , A[i] ) ;
//			printf( "%s\n" , A[i] ) ;
		}
		bool flag = true ;
		for( int i = 0 ; i < N && flag ; i++ ) {
			if( !calc( 0 , i ) ) {
				flag = false ;
				break ;
			}
		}
		printf( "Case #%d: " , TC ) ;
		if( !flag ) {
			printf( "Fegla Won\n" ) ;
			continue ;
		}
		int ans = 0 ;
		for( int i = 0 ; i < M ; i++ ) {
			int ans1 = 10000000 ;
			for( int j = 0 ; j < N ; j++ ) {
				int sum = 0 ;
				for( int k = 0 ; k < N ; k++ ) {
					sum += abs( ct[i][j] - ct[i][k] ) ;
				}
				ans1 = min( ans1 , sum ) ;
			}
			ans += ans1 ;
		}
		printf( "%d\n" , ans ) ;
	}
	return 0;
}
