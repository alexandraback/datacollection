using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "iostream"
#include "stdio.h"
#include "algorithm"
#include "math.h"
#include "vector"
#include "string"

vector< vector< pair< char, int > > > S;

vector< pair< char, int > > split(string &s)
{
	vector< pair< char, int > > ret;

	for (int le = 0, ri = 0; le < s.length(); le = ri)
	{
		while ( ri < s.length() && s[le] == s[ri] ) ri++;

		ret.push_back( make_pair( s[ le ], ri - le ) );
	}

	return ret;
}

bool check()
{
	for (int i = 1; i < S.size(); i++)
	{
		if ( S[i].size() != S[0].size() ) return false;

		for (int k = 0; k < S[0].size(); k++)
		{
			if ( S[0][k].first != S[i][k].first ) return false;
		}
	}

	return true;
}

int main()
{
	int ntc;

	cin >> ntc;
	for (int tc = 1; tc <= ntc; tc++)
	{
		S.clear();

		int N;
		cin >> N;

		string str;
		for (int i = 0; i < N; i++)
		{
			cin >> str;
			S.push_back( split( str ) );
		}

		if ( check() )
		{
			int ans = 0;

			for (int k = 0; k < S[0].size(); k++)
			{
				vector< int > a;
				for (int i = 0; i < N; i++) a.push_back( S[i][k].second );

				int le = 1, ri = *max_element( a.begin(), a.end() );

				int best = 1000000000;
				for (int h = le; h <= ri; h++)
				{
					int Count = 0;

					for (int i = 0; i < N; i++) Count += abs(h - a[i]);

					best = min( best, Count );
				}

				//cout << S[0][k].first << ": " << best << endl;

				ans += best;
			}

			printf("Case #%d: %d\n", tc, ans);
		}
		else printf("Case #%d: Fegla Won\n", tc);
	}
	
    return 0;
}