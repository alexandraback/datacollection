/**
 * Tittle:	Google Code Jam 2015: Problem B Haircut
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

typedef long long ll;

// declarations
int t;
ll b, n;
ll m[N];

// functions
ll calc( ll tm )
{
	static ll cnt;

	cnt = 0LL;
	FOR( i, 1, b )
		cnt += (tm/m[i])+1LL;
	
	return cnt;
}

// main function
int main( void )
{
	ll l, r, mid;
	int who;
	ll cnt;
	
	// input
	scanf( "%d", &t );

	FOR( ti, 1, t ) {
		scanf( "%lld%lld", &b, &n );
		FOR( i, 1, b ) scanf( "%lld", &m[i] );

		// solve
		l = 0LL;
		r = 100000000000000LL;

		while( l<=r ) {
			mid = (l+r)>>1;

			if( calc(mid)>=n ) r = mid-1;
			else l = mid+1;
		}

		cnt = calc(l);
		// printf( "@ %lld\n", cnt );
		for( who = b; who >= 1; --who ) if( (l%m[who]) == 0 ) {
			if( cnt>n ) --cnt;
			else break;
		}
		
		// output
		printf( "Case #%d: %d\n", ti, who );
	}
	
	return 0;
}
