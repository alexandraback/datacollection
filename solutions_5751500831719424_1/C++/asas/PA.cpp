#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
#define phb push_back
#define ppb pop_back
using namespace std ;
inline int in(int d=0,char q=0,int c=1){while(q!='-'&&q!=EOF&&(q<48||q>57))q=getchar();if(q==EOF)return EOF;if(q=='-')c=-1,q=getchar();do d=d*10+(q^48),q=getchar();while(q<58&&q>47);return c*d;}
int main()
{
	string s[ 100 ] ;
	int t = in() , Case = 1 ;
	while ( t -- )
	{
		int n = in() ;
		for ( int i = 0 ; i < n ; i ++ )
		{
			cin >> s[ i ] ;
		}
		bool ck = true ;
		int j[ 100 ] = {} ;
		int num[ 100 ] , res = 0 ;
		for (  ; j[ 0 ] < s[ 0 ].size() ;  )
		{
			for ( int i = 0 , p ; i < n ; i ++ )
			{
				if ( s[ i ][ j[ i ] ] != s[ n - 1 ][ j[ n - 1 ] ] )
				{
					ck = false ;
				}
				p = j[ i ] ;
				while ( s[ i ][ p ] == s[ i ][ j[ i ] ] ) p ++ ;
				num[ i ] = p - j[ i ] ;
				j[ i ] = p ;
			}
			sort( num , num + n ) ;
			for ( int i = 0 ; i < n ; i ++ )
			{
				res += abs( num[ i ] - num[ n / 2 ] ) ;
			}
		}
		for ( int i = 0 ; i < n ; i ++ )
		{
			if ( j[ i ] < s[ i ].size() )
			{
				ck = false ;
			}
		}
		if ( ck == false )
		{
			printf( "Case #%d: Fegla Won\n" , Case ++ ) ;
		}
		else
		{
			printf( "Case #%d: %d\n" , Case ++ , res ) ;
		}
	}
}


