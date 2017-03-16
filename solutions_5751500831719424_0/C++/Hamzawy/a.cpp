/*
 * a.cpp
 *
 *  Created on: May 3, 2014
 *      Author: AhmedSamir
 */

#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <complex>

#ifdef _MSC_VER
#include<hash_set>
#include<hash_map>
using namespace stdext;
#else
#if __GNUC__ >2
#include<ext/hash_set>
#include<ext/hash_map>
using namespace __gnu_cxx;
#else
#include<hash_set>
#include<hash_map>
#endif
#endif

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#ifdef _MSC_VER
#define rep(i,m) for(decltype(m) i=0;i<m;i++)
#define repI(i,m) for(decltype(m.begin()) i = m.begin();i!=m.end();++i)
#define repRI(i,m) for(decltype(m.rbegin()) i = m.rbegin();i!=m.rend();++i)
#else
#define rep(i,m) for(__typeof(m) i=0;i<m;i++)
#define repI(i,m) for(__typeof(m.begin()) i = m.begin();i!=m.end();++i)
#define repRI(i,m) for(__typeof(m.rbegin()) i = m.rbegin();i!=m.rend();++i)
#endif
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define EPS (1e-9)
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;

#define SMALL_INPUT
//#define LARGE_INPUT

string a, b;

int mem[110][110];
int calc(int i, int j)
{
	if (i >= a.size() && j >= b.size()) return 0;
	if (i >= a.size() || j >= b.size()) return 1e9;
	if (a[i] != b[j]) return 1e9;
	int& res = mem[i][j];
	if (res != -1) return res;
	res = 1e9;
	res = min(res, calc(i + 1, j) + 1);
	res = min(res, calc(i, j + 1) + 1);
	res = min(res, calc(i + 1, j + 1));
	return res;
}

int main()
{
	freopen("a.in", "rt", stdin);
#ifdef SMALL_INPUT
	freopen("a-small-attempt1.in", "rt", stdin);
	freopen("a-small1.txt", "wt", stdout);
#endif
#ifdef LARGE_INPUT
	freopen("a-large.in", "rt", stdin);
	freopen("a-large.txt", "wt", stdout);
#endif
	int tc;
	cin >> tc;
	rep(T,tc)
	{
		int nn;
		cin >> nn;
		cin >> a >> b;

		memset(mem, -1, sizeof mem);
		int res = calc(0, 0);
		if (res >= 1e9) printf("Case #%d: Fegla Won\n", T + 1);
		else printf("Case #%d: %d\n", T + 1, res);

		continue;
		int n;
		string s;
		cin >> n;
		vector<vector<pair<char, int> > > v(n);
		//		vector<int> cnt(100, 1e9);
		set<int> siz;
		for (int i = 0; i < n; ++i)
		{
			cin >> s;
			v[i].push_back(make_pair(s[0], 1));
			//			cnt[v[i].size() - 1] = min(cnt[v[i].size() - 1], v[i].back().second);
			for (int j = 1; j < (int) s.size(); ++j)
			{
				if (v[i].back().first != s[j]) v[i].push_back(make_pair(s[j], 0));
				v[i].back().second++;
				//				cnt[v[i].size() - 1] = min(cnt[v[i].size() - 1], v[i].back().second);
			}
			siz.insert(v[i].size());
		}

		//		for (int i = 0; i < v.size(); ++i)
		//		{
		//			for (int j = 0; j < v[i].size(); ++j)
		//			{
		//				cout << "(" << v[i][j].first << ", " << v[i][j].second << "), ";
		//			}
		//			cout << endl;
		//		}
		//		for (int i = 0; i < v[0].size(); ++i)
		//			cout << cnt[i] << ", ";
		//		cout << endl;

		if (siz.size() != 1)
		{
			printf("Case #%d: Fegla Won\n", T + 1);
			continue;
		}
		int ret = 0;
		for (int i = 0; i < (int) v[0].size(); ++i)
		{
			int r1 = 1e9;
			for (int j = 0; j <= 100; ++j)
			{
				int r2 = 0;
				for (int k = 0; k < n; ++k)
				{
					r2 += abs(j - v[k][i].second);
				}
				r1 = min(r1, r2);
				//				ret += (v[j][i].second - cnt[i]);
			}
			ret += r1;
		}
		printf("Case #%d: %d\n", T + 1, ret);

#ifdef SMALL_INPUT
		cerr << T + 1 << " of " << tc << " is done." << endl;
#endif
#ifdef LARGE_INPUT
		cerr << T + 1 << " of " << tc << " is done." << endl;
#endif
	}
	return 0;
}
