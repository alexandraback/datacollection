#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAXVAL 16

using namespace std;

int cnt[MAXVAL+1];
int tests, val, row1, row2, ans;
bool bad_magician, found;

int main( ) {

	scanf( "%d", &tests );

	for ( int T = 1; T <= tests; ++T ) {

		found = bad_magician = false;

		for ( int i = 1; i <= 16; ++i )
			cnt[i] = 0;

		scanf( "%d", &row1 );

		for ( int i = 1; i <= 4; ++i )
			for ( int j = 1; j <= 4; ++j ) {
				scanf( "%d", &val );
				if ( i == row1 ) {
					++cnt[ val ];
				}
			}

		scanf( "%d", &row2 );

		for ( int i = 1; i <= 4; ++i )
			for ( int j = 1; j <= 4; ++j ) {
				scanf( "%d", &val );
				if ( i == row2 ) {
					++cnt[ val ];
					if ( cnt[val] == 2 ) {
						if ( !found ) {
							ans = val;
							found = true;
						}else {
							bad_magician = true;
						}
					}
				}
			}

		if ( !found ) {
			printf( "Case #%d: Volunteer cheated!\n", T );
		}else if ( bad_magician ) {
			printf( "Case #%d: Bad magician!\n", T );
		}else {
			printf( "Case #%d: %d\n", T, ans );
		}


	}

	return 0;

}
