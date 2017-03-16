#include "R1A_C.h"

CLine GetLineThroughTwoPoints( const CPoint& pt1, const CPoint& pt2 )
{
	CLine res;
	res.A = pt1.Y - pt2.Y;
	res.B = pt2.X - pt1.X;
	res.C = -res.A * pt1.X - res.B * pt1.Y;
	return res;
}

__int64 GetSignedDistanceToLine( const CPoint& pt, const CLine& line )
{
	const __int64 d = line.A * pt.X + line.B * pt.Y + line.C;
	return d;
}

void CR1A_CTaskProcessor::checkTrees( const std::vector<CPoint>& trees, std::vector<int>& logs )
{
	logs.clear();
	logs.assign( trees.size(), 0 );

	for( int i = 0; i < (int)trees.size(); i++ ) {

		//	quadratic algorithm :(
		int minCutsCount = INT_MAX;
		for( int j = 0; j < (int)trees.size(); j++ ) {
			if( j == i ) {
				continue;
			}
			//	line [i - j]
			CLine line = GetLineThroughTwoPoints( trees[i], trees[j] );
			int treesCountPlus = 0;
			int treesCountMinus = 0;
			for( int k = 0; k < (int)trees.size(); k++ ) {
				if( k == i || k == j ) {
					continue;
				}
				const __int64 d = GetSignedDistanceToLine( trees[k], line );
				if( d > 0 ) { 
					treesCountPlus++;
				} else if( d < 0 ) {
					treesCountMinus++;
				}
			}
			minCutsCount = min( minCutsCount, min( treesCountPlus, treesCountMinus ) );
		}

		logs[i] = minCutsCount;
	}
}
