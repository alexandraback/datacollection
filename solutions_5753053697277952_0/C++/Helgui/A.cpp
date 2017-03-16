#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <utility>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(x) (x)*(x)
#define _with_file
#define TASK ""
#define forn(i, n) for(int i = 0; i < (int)n; ++i)

void quit(); 

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
#ifdef local
typedef double ld;
#else
typedef long double ld;
#endif
typedef pair <int, int> PII;
typedef pair <i64, i64> PII64;
typedef pair <ld, ld> PLL;

const ld PI = acos(-1);
const ld EPS = 1e-10;
double __t;

int p[27];

vector<string> ans;

int main()
{
	#ifdef local
		__t = clock();
		#ifndef _with_files
			freopen("z.in", "rt", stdin);
			freopen("z.out", "wt", stdout);
		#endif
	#endif
	#ifdef _with_files
		freopen(TASK".in", "rt", stdin);
		freopen(TASK".out", "wt", stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _T;
	cin >> _T;
	for(int _test = 1; _test <= _T; ++_test) {
		int n;
		cin >> n;
		ans.clear();
		int s = 0;
		for(int i = 0; i < n; ++i) {
			cin >> p[i];
			s += p[i];
		}
		while(s) {
			for(int i = 0; i < n; ++i) {
				if (2*p[i] > s) {
					cerr << "FAIL "<< _test << ' ' <<s << ' ' << p[i] << endl;
				}
			}
			string cur;
			int mxIdx = 0;
			int mx = p[0];
			for(int i = 1; i < n; ++i) {
				if (p[i] > mx) {
					mx = p[i];
					mxIdx = i;
				}
			}
			cur += ('A' + mxIdx);
			s--;
			p[mxIdx]--;
			mxIdx = 0;
			mx = p[0];
			for(int i = 1; i < n; ++i) {
				if (p[i] > mx) {
					mx = p[i];
					mxIdx = i;
				}
			}
			if (s == 0) {
				ans.pb(cur);
				continue;
			}
			s--;
			p[mxIdx]--;
			bool fail = 0;
			for(int i = 0; i < n; ++i) {
				if (2*p[i] > s) {
					fail = 1;
				}
			}
			if (!fail) {
				cur += ('A' + mxIdx);
				ans.pb(cur);
				continue;
			}
			p[mxIdx]++;
			s++;
			ans.pb(cur);
		}
		cout << "Case #" << _test << ":";
		for(auto &str : ans) {
			cout << ' ' << str;
		}
		cout << endl;
	}
	quit();
}

void quit()
{
	#ifdef local
		cerr << "\nTOTAL TIME: "<< (clock() - __t)/1000.0 << " s\n";
	#endif
	exit(0);		
}