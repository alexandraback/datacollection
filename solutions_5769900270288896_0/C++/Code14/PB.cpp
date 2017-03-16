/**
 * Tittle:	2015 Google Code Jam Round1B - PB Noisy Neighbors
 * Author:	Cheng-Shih, Wong
 * Date:	2015/05/02
 */

// include files
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

// definitions
#define FOR(i,a,b) for( int i=(a),_n=(b); i<=_n; ++i )
#define clr(x,v) memset( x, v, sizeof(x) )
#define N 10005

// declarations
int t;
int r, c;
int p, n;
int cnt[N];
int solve1[N], solve2[N];

// functions
void subs( int arr[], int v, int d )
{
	if( v-c >= 0 ) arr[v-c]+=d;
	if( v+c < n ) arr[v+c]+=d;
	if( (v)%c != 0 ) arr[v-1]+=d;
	if( (v+1)%c != 0 ) arr[v+1]+=d;
}

// main function
int main( void )
{
	int ans1, ans2;
	int maxi;
	int tmp;
	
	// input
	scanf( "%d", &t );

	FOR( ti, 1, t ) {
		scanf( "%d%d%d", &r, &c, &p );

		// init
		n = r*c;	
		clr( cnt, 0 );

		FOR( i, 0, n-1 )
			subs(cnt,i,1);

		
		// sovle
		ans1 = 0;
		FOR( i, 0, n-1 ) ans1 += cnt[i];
		ans2 = ans1;

		tmp = n-p;
		memcpy( solve1, cnt, sizeof(cnt) );
		memcpy( solve2, cnt, sizeof(cnt) );

		if( tmp ) {
			maxi = 0;
			FOR( i, 1, n-1 ) if( solve1[maxi]<solve1[i] ) 
				maxi = i;
			tmp = maxi;
			
			solve1[maxi] = 0;

			maxi = 0;
			FOR( i, 1, n-1 ) if( solve1[maxi]<solve1[i] )
				maxi = 1;
			solve2[maxi] = 0;
			subs(solve2,maxi,-1);
			
			subs(solve1,tmp,-1);

			tmp = n-p-1;
			while( tmp ) {
				maxi = 0;
				FOR( i, 1, n-1 ) if( solve1[maxi]<solve1[i] )
					maxi = i;
				solve1[maxi] = 0;
				subs(solve1,maxi,-1);
				--tmp;
			}

			tmp = n-p-1;
			while( tmp ) {
				maxi = 0;
				FOR( i, 1, n-1 ) if( solve2[maxi]<solve2[i] )
					maxi = i;
				solve2[maxi] = 0;
				subs(solve2,maxi,-1);
				--tmp;
			}
		}

		ans1 = ans2 = 0;
		/*
		puts("map1");
		FOR( i, 0, r-1 ) {
			FOR( j, 0, c-1 ) 
				printf( "%d ", solve1[i*c+j] );
			putchar('\n');
		}
		puts("map2");
		FOR( i, 0, r-1 ) {
			FOR( j, 0, c-1 ) 
				printf( "%d ", solve2[i*c+j] );
			putchar('\n');
		}
		*/

		FOR( i, 0, n-1 ) {
			if( solve1[i] > 0 ) ans1 += solve1[i];
			if( solve2[i] > 0 ) ans2 += solve2[i];
		}

		printf( "Case #%d: %d\n", ti, min(ans1/2,ans2/2) );
	}
	
	return 0;
}
