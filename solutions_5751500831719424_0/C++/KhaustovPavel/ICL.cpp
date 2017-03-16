#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <algorithm>
#include <cstdio>
#include <ctime>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <iostream>
#include <cmath>
#include <sstream>
#include <complex>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:128000000")

typedef long long int64;
typedef unsigned long long uint64;

#define y1 _dsfkjdsfksdj
#define y0 _sfsdkfdop

typedef unsigned uint;
typedef vector<int64> vi64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int64,int64> pii64;
typedef pair<int,pii> piii;
typedef pair<pii,pii> piiii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef pair<int,string> pis;

int nt;
int n;
vector <string> a;
vector <string> b;
vector < vector<int> > f;

inline string sclear(string s)
{
	int l = (int)s.length();
	string res = "";
	res += s[0];
	for (int i = 1; i < l; ++i)
	{
		if (s[i] != s[i - 1])
			res += s[i];
	}
	return res;
}

inline void init()
{
	a.clear();
	b.clear();
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		b[i] = sclear(a[i]);
	}
}

inline int precheck()
{
	for (int i = 1; i < n; ++i)
		if (b[i] != b[0]) return 0;
	return 1;
}

inline int solve()
{
	f.clear();
	string T = b[0];
	f.resize((int)T.length());
	for (int j = 0; j < n; ++j)
	{
		int t = 0;
		int l = (int)a[j].length();	
		for (int i = 0; i < (int)T.length(); ++i)
		{
			int cur = 0;
			while (t < l && a[j][t] == T[i])
			{
				++cur;
				++t;
			}
			f[i].push_back(cur);
		}
	}
	int res = 0;
	for (int i = 0; i < (int)T.length(); ++i)
	{
		sort(f[i].begin(), f[i].end());
		int now = 123456789;
		for (int t = 1; t <= f[i][n - 1]; ++t)
		{
			int cur = 0;
			for (int j = 0; j < n; ++j)
				cur += abs(t - f[i][j]);
			now = min(now, cur);
		}
		res += now;
	}
	return res;
}

int main()
{	
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	cin >> nt;
	for (int tn = 1; tn <= nt; ++tn)
	{
		init();
		cout << "Case #" << tn << ": ";
		if (!precheck())
		{
			cout << "Fegla Won" << endl;
			continue;
		}
		int res = solve();
		cout << res << endl;
	}

    return 0;
}