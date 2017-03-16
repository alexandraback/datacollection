#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

char intToChar( int InputInt );

//Code jam 1C problem a
int main( int argc, char * argv[] )
{
	//Find out how many test cases there are
	unsigned int nInputs = 0;
	cin >> nInputs;
	//cout << nInputs << " tests" << endl;

	//Loop over all inputs
	for ( unsigned int inputIndex = 0; inputIndex < nInputs; ++inputIndex )
	{
		//Read input
		int partyNumber, oneParty;
		vector< int > partyComposition;
		cin >> partyNumber;
		//cout << "partyNumber: " << partyNumber << endl;
		int totalSenators = 0;
		for ( unsigned int partyIndex = 0; partyIndex < partyNumber; ++partyIndex )
		{
			cin >> oneParty;
			partyComposition.push_back( oneParty );
			totalSenators += oneParty;
			//cout << oneParty << endl;
		}

		//Start evacuating
		cout << "Case #" << inputIndex + 1 << ": ";
		while ( totalSenators > 0 )
		{
			//debug
			/*cout << endl;
			for ( int count : partyComposition )
			{
				cout << count << " ";
			}
			cout << endl;*/

			//Find biggest party
			int maxSenatorNumber = 0;
			int maxSenatorIndex = 0;
			for ( unsigned int partyIndex = 0; partyIndex < partyNumber; ++partyIndex )
			{
				if ( partyComposition[ partyIndex ] > maxSenatorNumber )
				{
					maxSenatorNumber = partyComposition[ partyIndex ];
					maxSenatorIndex = partyIndex;
				}
			}

			//Check for fail
			if ( maxSenatorNumber > totalSenators / 2 )
			{
				cerr << "Majority found: whoops" << endl;
				return 1;
			}

			//Evacuate one from biggest party
			cout << intToChar( maxSenatorIndex );
			partyComposition[ maxSenatorIndex ]--;
			totalSenators--;

			//If there's an odd number of senators in the room now, try to evacuate another to avoid majority
			if ( totalSenators % 2 )
			{
				for ( unsigned int partyIndex = maxSenatorIndex; partyIndex < partyNumber; ++partyIndex )
				{
					if ( partyComposition[ partyIndex ] == maxSenatorNumber )
					{
						cout << intToChar( partyIndex );
						partyComposition[ partyIndex ]--;
						totalSenators--;
						break;
					}
				}
			}
			cout << " ";
		}
		cout << endl;
	}

	return 0;
}

char intToChar( int InputInt )
{
	return ( char )( InputInt + 65 );
}
