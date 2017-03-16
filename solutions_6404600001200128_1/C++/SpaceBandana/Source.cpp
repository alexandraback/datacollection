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

const char* inFileName = "A-large.in";
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
		
		int N;
		iss >> N;

		vector<int> mush;
			getline(infile,line);
		istringstream iss2(line); 

		for( int i=0; i< N; i++ )
		{
			int m = 0;
			iss2 >> m;

			mush.push_back(m);
		}
		
	// method 1:
	int prev = mush[0];
	int eaten1 = 0;
	for( int i=1; i < mush.size(); i++ )
	{
		int diff = mush[i] - prev;
		if( diff > 0 ) // we added mushroom
		{
		}
		else
		{
			eaten1 += -diff;
		}

		prev = mush[i];
	}
	
	// method 2:
	// find the bigges difference:
	prev = mush[0];
	int bigdiff = 0;
	for( int i=1; i< mush.size(); i++ )
	{
		int diff = mush[i] - prev;
		if( diff < 0 )
		{
			if( -diff > bigdiff )
			{
				bigdiff = -diff;
			}
		}
		prev = mush[i];
	}
	// bigdiff is the rate at which we eat mushroom, start again :
	prev = mush[0];
	int eaten2 = 0;
	for( int i=1; i < mush.size(); i++ )
	{
		if( prev > bigdiff )
		{
			eaten2 += bigdiff;
		}
		else
		{
			eaten2 += prev;
		}

		prev = mush[i];
	}


	cout<<"Case #"<<Case<<": "<<eaten1<<" "<<eaten2<<endl;
	outfile <<"Case #"<<Case<<": "<<eaten1<<" "<<eaten2<<endl;
		
	}	
	

    infile.close();
	outfile.close();
	system("pause");
	return 0;
}