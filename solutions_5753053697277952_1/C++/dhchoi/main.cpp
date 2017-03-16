#include <iostream>
#include <string>

using namespace std;


void main() {
	int t, n;	
	string str;
	cin >> t;  // read t. cin knows that t is an int, so it reads it as such.	
	for (int i = 1; i <= t; ++i) {
		cin >> n;
		int* arrVal = new int[n];
		int iTotalNum = 0;
		for( int j = 0; j < n; j++ )
		{
			cin >> arrVal[j];
			iTotalNum	+= arrVal[j];
		}

		cout << "Case #" << i << ": ";

		while( iTotalNum > 2 )
		{
			int iMaxIndex		= -1;
			int iMaxSecondIndex = -1;
			int iMaxVal			= -1;
			int iMaxValSecond	= -1;

			// 1. Find cur max, cur max second.
			for( int j = 0; j < n; j++ )
			{
				if( iMaxVal <= arrVal[j] )
				{
					iMaxSecondIndex	= iMaxIndex;
					iMaxValSecond	= iMaxVal;
					iMaxIndex		= j;
					iMaxVal			= arrVal[j];
				}
			}

			cout << (char) (iMaxIndex + 65) ;
			arrVal[iMaxIndex]--;
			iTotalNum--;

			if( arrVal[iMaxIndex] >= arrVal[iMaxSecondIndex] && iTotalNum > 2 )
			{
				cout << (char) (iMaxIndex + 65) ;
				arrVal[iMaxIndex]--;
				iTotalNum--;
			}
			else if( iMaxSecondIndex != -1 && iTotalNum > 2 )
			{
				cout << (char) (iMaxSecondIndex + 65) ;
				arrVal[iMaxSecondIndex]--;
				iTotalNum--;
			}

			cout << " ";
					
		}

		for( int j = 0; j < n; j++ )
		{
			if( arrVal[j] == 2 )
			{
				cout << (char) (j + 65) ;
				cout << (char) (j + 65) ;
			}
			else if( arrVal[j] == 1 )

			{
				cout << (char) (j + 65) ;
			}

		}

		cout << endl;


		//cout << "Case #" << i << ": " << iCnt << endl;
	
    }

}