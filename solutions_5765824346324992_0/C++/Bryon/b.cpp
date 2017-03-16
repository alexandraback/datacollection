#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

typedef long long ll;


//Check is the time to see how many peoeple have been processed
ll period( vector<ll> backup, ll check )
{
	ll total = 0;
	for( ll i = 0; i < backup.size(); i++ )
	{
		total += check / backup.at(i);
	}
	return total;
}

int main()
{
	ll casses;
	ll caseNum;
	ll b, m;
	ll counter;
	ll yourBarbor;
	ll yourPos;
	ll currPos;
	ll max;//smallest time all numbers divide into
	vector<ll> line;
	vector<ll> backup;
	cin >> casses;
	
	for( caseNum = 0; caseNum < casses; caseNum++ )
	{
		cin >> b >> yourPos;
		line.clear();
		backup.clear();
		for( counter = 0; counter < b; counter++ )
		{
			cin >> m;
			line.push_back( m );
			backup.push_back( m );
		}
		currPos = 0;
		currPos += b;
		if( currPos >= yourPos )
		{
			yourBarbor = yourPos;
			cout << "Case #" << caseNum + 1 << ": " << yourBarbor << endl;
			continue;
		}
		ll counter;
		for( counter = 100001; true; counter += 100000 )
		{
			if( period( backup, counter ) > yourPos - currPos )
				break;
		}
		counter -= 100000;
		for( ; true; counter++ )
		{
			if( period( backup, counter ) >= yourPos - currPos )
				break;
		}
		cerr << "Time " << counter << endl;
		ll countDown = period( backup, counter ) - yourPos + currPos;
		
		cerr << "countDown " << countDown << endl; 
		for( ll i = backup.size() - 1; i >= 0; i-- )
		{
			if( countDown == 0 && counter % backup.at(i) == 0 )
			{
				yourBarbor = i + 1;
				break;
			}else if( counter % backup.at(i) == 0 )
			{
				countDown--;
			}
		}
		/*
		yourBarbor = 0;
		while( currPos != yourPos )
		{
			
			for( counter = 0; counter < b; counter++ )
			{
				if( line.at( counter ) == 0 )
				{
					currPos++;
					yourBarbor = counter + 1;
					line.at( counter ) = backup.at( counter );
					if( currPos == yourPos )
						break;
				}
				//cerr << line.at( counter ) << " ";
				line.at( counter )--;
			}
			//cerr << endl;
		}*/
		
		cout << "Case #" << caseNum + 1 << ": " << yourBarbor << endl;
	}
	

	return 0;
}
