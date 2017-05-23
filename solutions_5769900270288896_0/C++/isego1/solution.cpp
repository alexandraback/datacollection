#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#include <cassert>
#include <cmath>
#include <bitset>
#include <ctime>
#include <queue>
#include <fstream>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define pii pair< int, int >
#define GC getchar( )
#define PC putchar
#define x first
#define y second
typedef long long llint;
 
FILE *fin = fopen( "input.txt", "r" );
FILE *fout = fopen( "output.txt", "w" );

const int N = 17;
int M[ N ][ N ];
int n, m, k;
int CNT[ N ][ N ];
int P[ N ];
int cnt;
int global;
pii NES[ N * N ];

const int dx[ ] = { 0, 1 };
const int dy[ ] = { 1, 0 };

void load( ) {
	fscanf( fin, "%d%d%d", &n, &m, &k );
}

void solve( ) {
	cnt = 0;
	for( int i = 0; i < n; i++ ) {
		for( int j = 0; j < m; j++ ) {
			CNT[ i ][ j ] = cnt;
			NES[ cnt++ ] = mp( i, j );
		}
	}
	int sol = ( 1 << 30 );
	for( int i = 0; i < ( 1 << cnt ); i++ ) {
		memset( M, 0, sizeof( M ) );
		int bez = 0;
		for( int j = 0; j < cnt; j++ ) {
			if( i & ( 1 << j ) ) {
				M[ NES[ j ].first ][ NES[ j ].second ] = 1;
				bez++;
			}
		}
		if( bez != k ) continue;
		//printf( "
		int curr = 0;
		for( int ii = 0; ii < n; ii++ ) {
			for( int jj = 0; jj < m; jj++ ) {
				for( int ff = 0; ff < 2; ff++ ) {
					int X = ii + dx[ ff ];
					int Y = jj + dy[ ff ]; 
					if( M[ ii ][ jj ] && M[ X ][ Y ] ) curr++;
				}
			}
		}
		sol = min( sol, curr );
	}
	fprintf( fout, "Case #%d: %d\n", ++global, sol );
}
	
int main( void ) {
	int t;
fscanf( fin, "%d", &t );
	while( t-- ) {
		load( );
		solve( );
	}
    return 0;
}
