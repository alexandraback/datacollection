//
//  main.cpp
//  MagicTric
//
//  Created by Satoru Ogura on 2014/04/12.
//
//

#include			<iostream>
#include			<string>
using	namespace	std;

#include			<JpMooParaiso/Exceptions.h>
#include			<JpMooParaiso/Arithmetics.h>
using	namespace	JpMooParaiso;

void
Body()
{
//	Reading
	int					w1stAnswer;
	Matrix<int, 4, 4>	w1stCards;
	int					w2ndAnswer;
	Matrix<int, 4, 4>	w2ndCards;

	cin >> w1stAnswer;
	for ( size_t r = 0; r < 4; r++ )
	{	for ( size_t c = 0; c < 4; c++ ) cin >> w1stCards.u[ r ][ c ];
	}
	cin >> w2ndAnswer;
	for ( size_t r = 0; r < 4; r++ )
	{	for ( size_t c = 0; c < 4; c++ ) cin >> w2ndCards.u[ r ][ c ];
	}
//	Solving
	int*	w1stCandidates = w1stCards.u[ w1stAnswer - 1 ];
	int*	w2ndCandidates = w2ndCards.u[ w2ndAnswer - 1 ];
	
	size_t	wCount = 0;
	int		wFound = 0;
	for ( size_t i = 0; i < 4; i++ )
	{	for ( size_t j = 0; j < 4; j++ )
		{	if ( w1stCandidates[ i ] == w2ndCandidates[ j ] )
			{	wCount++;
				wFound = w1stCandidates[ i ];
			}
		}
	}
	switch ( wCount )
	{
	case  0:	cout << "Volunteer cheated!";	break;
	case  1:	cout << wFound;					break;
	default:	cout << "Bad magician!";		break;
	}
	cout << endl;
}
//	Dumping
//	cerr << endl;
//	cerr << wCase.uAnswers[ 0 ] << endl;
//	for ( size_t r = 0; r < 4; r++ )
//	{	for ( size_t c = 0; c < 4; c++ ) cerr << '\t' << wCase.uCards[ 0 ].u[ r ][ c ];
//		cerr << endl;
//	}
//	cerr << wCase.uAnswers[ 1 ] << endl;
//	for ( size_t r = 0; r < 4; r++ )
//	{	for ( size_t c = 0; c < 4; c++ ) cerr << '\t' << wCase.uCards[ 1 ].u[ r ][ c ];
//		cerr << endl;
//	}


void
Main()
{	size_t	wNumCases;	cin >> wNumCases;		cerr << "NumCases:" << wNumCases << endl;
	for ( size_t i = 1; i <= wNumCases; i++ )
	{	cout << "Case #" << i << ": ";
		Body();
	}
}

int
main( int argc, const char * argv[] )
{
	cout << argv[ 1 ] << endl;
	
	N( freopen( argv[ 1 ], "r", stdin ) );
//	N( freopen( argv[ 1 ], "r", stdin ) );
	Main();
	return 0;
}

