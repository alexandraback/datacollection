#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define pb push_back
#define mp make_pair 

using namespace std;


string a[1000]; 
vector<pair<char, int> > b[1000] ;

vector<pair<char, int> > format(const string & s)
{
	vector<pair<char, int> > cur; 
	cur.pb(mp(s[0], 1)); 
	for (int i = 1; i < s.length() ;i++)
	{
		if (s[i] == s[i - 1]) 
		{
			cur.back().second++; 
		}
		else 
		{
			cur.push_back(mp(s[i], 1)); 
		}
	}
	return cur; 
}

bool eq(vector<pair<char, int> > & a, vector<pair<char, int> > & b)
{
	if (a.size() != b.size()) return 0; 
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i].first != b[i].first) return 0; 
	}
	return 1; 
}

void solve(int tc)
{
	cout << "Case #" << tc << ": "; 

	int num; 
	cin >> num; 
	for (int i = 0; i < num; i++)
	{
		cin >> a[i]; 
		b[i] = format(a[i]); 
		if (!eq(b[i], b[0])) 
		{
			cout << "Fegla Won\n"; 
			return; 
		}
	}

	int allans = 0; 
	for (int i = 0; i < b[0].size(); i++)
	{
		int curmin = 1000000000; 
		for (int x = 1; x < 300; x++)
		{
			int v = 0; 
			for (int j = 0; j < num; j++)
			{
				v += abs(b[j][i].second - x); 
			}
			if (v < curmin) curmin = v; 
		}
		allans += curmin; 
	}

	cout << allans << endl; 

}

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 

	int tst = 0;
	cin >> tst; 
	for (int tc = 0; tc < tst; tc++)
	{
		solve(tc + 1); 
	}


	return 0; 
}