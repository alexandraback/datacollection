/**
 * Tittle:	Google Code Jam 2015: Problem A Mushroom Monster
 * Author:	Cheng-Shih, Wong
 * Date:	2015/04/18
 */

// include files
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

// definitions
#define FOR(i,a,b) for( int i=(a),_n=(b); i<=_n; ++i )
#define clr(x,v) memset( x, v, sizeof(x) )
#define N 1005

// declarations
int t;
int n;
int m[N];
int cnt1, cnt2;

// functions


// main function
int main( void )
{
	int maxe, mush;
	
	// input
	scanf( "%d", &t );

	FOR( ti, 1, t ) {
		scanf( "%d", &n );
		FOR( i, 1, n ) scanf( "%d", &m[i] );

		// solve
		cnt1 = cnt2 = 0;

		FOR( i, 1, n-1 ) if( m[i+1]<m[i] )
			cnt1 += m[i]-m[i+1];

		maxe = 0;
		FOR( i, 1, n-1 ) if( m[i+1]<m[i] )
			maxe = max( maxe, m[i]-m[i+1] );

		FOR( i, 1, n-1 ) {
			if( maxe > m[i] ) cnt2 += m[i];
			else cnt2 += maxe;
		}

		// output
		printf( "Case #%d: %d %d\n", ti, cnt1, cnt2 );
	}
	
	return 0;
}
