#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n;
vector< pair< char, int > > v[ 111 ];

void solve()
{
	cin >> n;
	for ( int i = 1; i <= n; i++ )
	{
		string s; cin >> s;
		v[i].clear();
		for ( int j = 0; j < s.size(); j++ )
		{
			if ( j == 0 || v[i].back().first != s[j] )
			{
				v[i].push_back( make_pair( s[j], 1 ) );
			} else v[i].back().second++;
		}
	}
	for ( int i = 2; i <= n; i++ )
	{
		if ( v[i].size() != v[1].size() ) 
		{
			cout << "Fegla Won\n";
			return;
		}
		for ( int j = 0; j < v[i].size(); j++ ) 
			if ( v[1][j].first != v[i][j].first )
			{
				cout << "Fegla Won\n";
				return;
			}
	}
	int answer = 0;
	for ( int i = 0; i < v[1].size(); i++ )
	{
		vector< int > f;
		for ( int j = 1; j <= n; j++ ) f.push_back( v[j][i].second );
		sort( f.begin(), f.end() );
		int best = 1000000000;
		for ( int i = 0; i < f.size(); i++ ) 
		{
			int cur = 0;
			for ( int j = 0; j < f.size(); j++ ) cur += max( f[i] - f[j], f[j] - f[i] );
			best = min( best, cur );
		}
		answer += best;
	}
	cout << answer << "\n";
}

int main (int argc, const char * argv[])
{
	int t; cin >> t;
	for ( int i = 1; i <= t; i++ )
	{
		cout << "Case #" << i << ": ";
		solve();
	}
    return 0;
}