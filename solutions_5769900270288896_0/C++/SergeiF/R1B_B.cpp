#include "R1B_B.h"

int CR1B_BTaskProcessor::countUnhappiness( int N, int blackInCorner, int blackOnEdge, int blackInside, 
	int whiteInCorner, int whiteOnEdge, int whiteInside )
{
	const int totalBlack = blackInside + blackOnEdge + blackInCorner;

	int extraTenants = N - totalBlack;
	int unhappiness = 0;

	if( extraTenants > 0 ) {
		const int takeCorners = min( whiteInCorner, extraTenants );
		extraTenants -= takeCorners;
		unhappiness += 2 * takeCorners;
	}
	if( extraTenants > 0 ) {
		const int takeEdges = min( whiteOnEdge, extraTenants );
		extraTenants -= takeEdges;
		unhappiness += 3 * takeEdges;
	}
	if( extraTenants > 0 ) {
		const int takeInside = min( whiteInside, extraTenants );
		extraTenants -= takeInside;
		unhappiness += 4 * takeInside;
	}

	assert( extraTenants == 0 );
	return unhappiness;
}

int CR1B_BTaskProcessor::minimizeUnhappiness( int R, int C, int N )
{
	if( N == 0 ) {
		return 0;
	}
	assert( N <= R * C );
	if( R > C ) {
		const int temp = R;
		R = C;
		C = temp;
	}
	assert( R <= C );

	if( R == 1 ) {
		if( C == 1 ) {
			return 0;
		}
		const int black = (C + 1)/ 2;
		if( N <= black ) {
			return 0;
		}
		const int whiteCorner = (C % 2 == 0 ? 1 : 0);
		int extraTenants = N - black;
		int unhappiness = 0;
		if( whiteCorner ) {
			extraTenants--;
			unhappiness++;
		}
		unhappiness += 2 * extraTenants;
		return unhappiness;
	}

	//	paint bw, count different types of cells
	int blackInCorner = 0;
	int blackOnEdge = 0;
	int blackInside = 0;
	int whiteInCorner = 0;
	int whiteOnEdge = 0;
	int whiteInside = 0;

	bool blackFirst = true;
	for( int r = 0; r < R; r++ ) {
		const bool blackLast = (blackFirst ? C : C - 1) % 2 == 1;
		const int numberOfBlacksInsideRow = blackFirst ? ( (C - 2) / 2 ) : ( (C - 1) / 2);
		const int numberOfWhitesInsideRow = blackFirst ? ( (C - 1) / 2 ) : ( (C - 2) / 2);
		assert( numberOfBlacksInsideRow + numberOfWhitesInsideRow == C - 2 );
		if( r == 0 || r == R - 1 ) {
			if( blackFirst ) {
				blackInCorner++;
			} else {
				whiteInCorner++;
			}
			if( blackLast ) {
				blackInCorner++;
			} else {
				whiteInCorner++;
			}
			blackOnEdge += numberOfBlacksInsideRow;
			whiteOnEdge += numberOfWhitesInsideRow;
		} else {
			if( blackFirst ) {
				blackOnEdge++;
			} else {
				whiteOnEdge++;
			}
			if( blackLast ) {
				blackOnEdge++;
			} else {
				whiteOnEdge++;
			}
			blackInside += numberOfBlacksInsideRow;
			whiteInside += numberOfWhitesInsideRow;
		}
		blackFirst = !blackFirst;
	}

	const int totalBlack = blackInside + blackOnEdge + blackInCorner;
	const int totalWhite = whiteInside + whiteOnEdge + whiteInCorner;
	assert( blackInCorner + whiteInCorner == 4 );
	assert( blackOnEdge + whiteOnEdge == 2 * ( R + C - 4 ) );
	assert( totalBlack + totalWhite == R * C );

	if( N <= totalBlack || N <= totalWhite ) {
		return 0;
	}

	return min( countUnhappiness( N, blackInCorner, blackOnEdge, blackInside, whiteInCorner, whiteOnEdge, whiteInside ),
		countUnhappiness( N, whiteInCorner, whiteOnEdge, whiteInside, blackInCorner, blackOnEdge, blackInside ) );

}