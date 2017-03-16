#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
	ll casses;
	ll caseNum;
	ll counter;
	ll temp;
	ll answer1;
	ll biggestInterval;
	ll answer2;
	cin >> casses;
	vector<ll> mushRoom;
	
	for( caseNum = 0; caseNum < casses; caseNum++ )
	{
		ll totalInterVal;
		cin >> totalInterVal;
		mushRoom.clear();
		for( counter = 0; counter < totalInterVal; counter++ )
		{
			cin >> temp;
			mushRoom.push_back( temp );
		}
		
		answer1 = 0;
		biggestInterval = 0;
		//firstMethod reveseCount
		//Also set the biggest interval
		
		for( counter = totalInterVal - 2; counter >= 0; counter-- )
		{
			//cerr << "I run " << endl;
			if( mushRoom[counter] > mushRoom[counter + 1] )
				answer1 += mushRoom[counter] - mushRoom[counter + 1];
			if( mushRoom[counter] - mushRoom[counter + 1] > biggestInterval )
				biggestInterval = mushRoom[counter] - mushRoom[counter + 1];
		}
		
		//Set the second senarrio
		answer2 = 0;
		
		for( counter = 0; counter < totalInterVal - 1; counter++ )
		{
			//cerr << "I run " << endl;
			if( biggestInterval > mushRoom[counter] )
				answer2 += mushRoom[counter];
			else
				answer2 += biggestInterval;
		}
		
		
		
		cout << "Case #" << caseNum + 1 << ": " << answer1 << " " << answer2 << endl;
	}
	

	return 0;
}
