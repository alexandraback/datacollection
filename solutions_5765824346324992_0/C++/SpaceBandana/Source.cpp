// My solution for Google jam problem Problem A. Prima donna
// https://code.google.com/codejam/contest/2442487/dashboard#s=p1
// Jerome

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
using namespace std;

const char* inFileName = "B-small-attempt1.in";
const char* outFileName = "out.txt";


int main()
{
	std::ifstream infile(inFileName);
	std::ofstream outfile(outFileName);
	if( infile.fail() || outfile.fail() )
	{
		return 0;
	}
	
	string line;
	getline(infile,line);
	int T = stoi(line);
	
	for( int Case = 1; Case <= T; Case++ )
	{
		getline(infile,line);
		istringstream iss(line); 
		int B,N;
		iss >> B >> N;
		
		vector<int> barb;
		getline(infile,line);
		istringstream iss2(line); 

		//map< pair<int, int> >
		int mulB = 1; // multiplicateur commun
		for( int i=0; i< B; i++ )
		{
			int m = 0;
			iss2 >> m;
			mulB *= m;
			barb.push_back(m);
		}
	
		int pass = 0;
		for( int i=0; i< barb.size(); i++ )
		{
			pass += mulB / barb[i];
		}

		while( N > mulB && N > pass)
		{
			N -= pass;
		}

		vector<int> b(B,0);
		int ans = 0;
		int minidx = -1;
		if( N <= B )
		{
			ans = N;
		}
		else
		{ 
			while( N > 0 )
			{
				if( N <= 0 )
					break;

				int min = 10000000;
				minidx = -1;
				bool adv = false;
				for( int i=0; i<B; i++ )
				{
					
					if( N <= 0 )
						break;

					if( b[i] == 0 ) // free
					{
						if( N == 1 )
						{
							ans = i + 1;
						}
						b[i] = barb[i]; // take the next client
						N--;
						adv = true;
					}
					else
					{
						if( min > b[i] )
						{
							min = b[i];
							minidx = i;
						}
					}
				}
				// we didn't take anybody
				if( !adv )
				{
					for( int i=0; i<B; i++ )
					{
						b[i] -= min;
						if( b[i] < 0 ) 
							b[i] = 0;
					}
				}
			}
		}
			
		cout<<"Case #"<<Case<<": "<<ans<<endl;
		outfile <<"Case #"<<Case<<": "<<ans<<endl;
		
	}	
	

    infile.close();
	outfile.close();
	system("pause");
	return 0;
}