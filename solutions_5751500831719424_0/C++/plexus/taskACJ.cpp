#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define INF (1<<30)

using namespace std;

const int N = 10;

char buff[300];

string getS(const string &s)
{
	string res;

	for(int i = 0; i < s.size(); i++)
	{
		if (i == 0 || s[i] != s[i-1])
			res += s[i];
	}

	return res;
}

vector<int> getV(const string &s)
{
	int cur = 0;	
	vector<int> res;

	for(int i = 0; i < s.size(); i++)
	{
		if (i > 0 && s[i] != s[i-1])
		{
			res.pb(cur);
			cur = 0;
		}
		cur++;
	}
	res.pb(cur);

	return res;
}

void solve()
{
	int n;
	scanf("%d", &n);
	gets(buff);

	vector<string> v;

	for(int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
		v.pb(s);
	}		

	string s = getS(v[0]);
	vector<vector<int> > k(v.size());

	for(int i = 0; i < v.size(); i++)
	{
		k[i] = getV(v[i]);
		if (s != getS(v[i]))
		{
			printf("Fegla Won");
			return;
		}
	}

	int res = 0;

	for(int i = 0; i<k[0].size(); i++)
	{
		int mn = INF;
		for(int lim = 1; lim <= 100; lim++)
		{
			int sum = 0;
			for(int j = 0; j<k.size(); j++)
			{
				sum += abs(k[j][i] - lim);
			}
			mn = min(mn, sum);
		}
		res += mn;
	}

	printf("%d", res);

}

int main()
{
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t;

	scanf("%d", &t);
	gets(buff);

	for(int test = 1; test <= t; test++)
	{
		printf("Case #%d: ", test);

		solve();

		printf("\n");
	}

	return 0;
}