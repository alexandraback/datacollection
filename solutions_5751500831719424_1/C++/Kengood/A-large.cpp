#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>

#include<unordered_map>
#include<unordered_set>
using namespace std;

int cases , Case = 1;
////////////




char check(vector<string> in)
{
	for(int i = 0 ; i < in.size(); ++i)
	{

		for(int j = 0; j < in[i].size(); ++j)
		{
			if( j+1 < in[i].size() && in[i][j] == in[i][j+1])
			{
				in[i].erase( in[i].begin()+j );
				--j;
			}
		}
		
	}

	for(int i = 1 ; i < in.size(); ++i)
		if( in[i] != in[i-1] )
			return 0;
	return 1;
}


vector< pair<char,int> > cntIt( string& a)
{
	vector< pair<char,int> > cnt;
	pair<char,int> ca; 
	ca.first = a[0];
	ca.second = 0;
	for(int j = 0; j < a.size(); ++j)
	{
		if( ca.first != a[j] )
		{
			cnt.push_back(ca);
			ca.second = 1;
		}
		else
			++ca.second;
		ca.first = a[j];
	}
	cnt.push_back(ca);
	return cnt;
}

int trydo(vector<string>& in)
{
	int ans = 0;
	int n = in.size();

	vector< vector<int>  > cntt;
	vector< vector< pair<char,int> > > all;
	
	for(int i = 0 ; i < n; ++i)
	{
		auto cur = cntIt(in[i]);
		if( cntt.empty() )
			cntt.resize( cur.size() );

		for(int j = 0; j < cur.size(); ++j)
		{
			cntt[j].push_back( cur[j].second ) ;
		}
		all.push_back( cur );

	}


	for(int i = 0 ; i < cntt.size() ; ++i)
	{
		int tt = 0 , real;
		sort( cntt[i].begin() , cntt[i].end() );

		if( cntt[i].size()&1 )
		{

			real = cntt[i][ cntt[i].size()/2 ] ;
			for(int j = 0; j < n; ++j)
			{
				ans += abs( real - all[j][i].second ) ;
			}
		}
		else
		{
			int a = 0 , b = 0;
			real = cntt[i][ cntt[i].size()/2 ] ;
			for(int j = 0; j < n; ++j)
				a += abs( real - all[j][i].second ) ;
			

			real = cntt[i][ cntt[i].size()/2 -1 ] ;
			for(int j = 0; j < n; ++j)
				b += abs( real - all[j][i].second ) ;

			ans += min( a,b);

		}
	}

	

	return ans;
}

int main()
{	


	scanf("%d" , &cases);	
	while( cases-- )
	{			
		printf("Case #%d: " , Case++ );

		int n;

		cin >> n;
		vector<string> in(n);
		for(int i = 0 ; i < n; ++i)
		{
			cin >> in[i];
		}

		if(check(in) )
		{
			cout << trydo(in) << endl;
		}
		else
			puts("Fegla Won");
		
	}

	

	return 0;
}

