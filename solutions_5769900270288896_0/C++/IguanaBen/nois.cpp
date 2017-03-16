/*
	Michał Gańczorz
	code jam 2015
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <string>
#include <queue>
#include <list>
#include <sstream>
 // #include <unistd.h>
// #include <unordered_map>

#define ll long long

using namespace std;

bool occ[30][30];

int pw(int x)
{
	int res = 1;
	while(x)
	{
		res*=2;
	 	x--;
	}
	return res;
}

int r,c;
int check(int ten)
{
	int mn = 100000;
	// cout<<pw(r*c)<<"\n";
	for(unsigned int i=0; i< pw(r*c); ++i)
	{
		if(__builtin_popcount(i) == ten)
		{
			unsigned int mask = 1;
			for(int j=0; j<r*c; ++j)
			{
				int x = j/r;
				int y = j % r;
				occ[x][y] = 0;
			}
			// cout<<i<<"|\n";
			// cout<<r*c<<"\n";
			for(int j=0; j<r*c; ++j)
			{
				int x = j/r;
				int y = j % r;
				// cout<<mask<<"\n";
				if(mask & i)
				{
					occ[x][y] = 1;
					// cout<<x<<" "<<y<<"\n";
				}
				mask*=2;
			}
			mask = 1;
			int mm = 0;
			for(int j=0; j<c-1; ++j)
				for(int k=0; k<r; ++k)
					if(occ[j][k] && occ[j+1][k])
					{
						// cout<<j<<" "<<j+1<<"\n";
						mm++;
					}

			for(int j=0; j<c; ++j)
				for(int k=0; k<r-1; ++k)
					if(occ[j][k+1] && occ[j][k])
						mm++;
			// cout<<"aa\n";
			mn = min(mm, mn);

		}

	}
	return mn;
}

void solve(int z)
{
	int n;
	// string str;
	cin>>r>>c>>n;
	// cout<<"| "<<r*c<<"\n";
	// int res = 0;
	int res = check(n);
	cout<<"Case #"<<z<<": "<<res<<"\n";
}

int main()
{
	int t;
	cin>>t;
	for(int i=1; i<=t; i++)
		solve(i);

	return 0;
}