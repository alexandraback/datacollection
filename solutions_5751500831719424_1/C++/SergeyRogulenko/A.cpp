#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXTHUI
#define prev PREVHUI
#define y1 Y1HUI

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n;
string s[200];
int d[200];
vector<char> A;

void solve() {
	cin >> n;
	forn(i, n)
		cin >> s[i];
	A.clear();
	forn(i, s[0].length())
		if (i == 0 || s[0][i] != s[0][i-1])
			A.pb(s[0][i]);
	int res = 0;
	while (A.size() > 0) {
		char c = A.back();
		A.pop_back();
		int D = 0;
		forn(i, n) {
			d[i] = 0;
			while (s[i].length() > 0 && s[i][s[i].length() - 1] == c) {
				d[i]++;
				s[i].erase(s[i].length() - 1);
			}
			if (d[i] == 0) {
				cout << "Fegla Won" << endl;
				return;
			}
			D = max(D, d[i]);
		}
		int best = inf;
		for (int j = 1; j <= D; j++) {
			int w = 0;
			forn(i, n)
				w += abs(j - d[i]);
			best = min(best, w);
		}
		res += best;
	}	
	forn(i, n)
		if (s[i].length() > 0) {
			cout << "Fegla Won" << endl;
			return;
		}
	cout << res << endl;
	
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int tt;
	cin >> tt;
	forn(ii, tt) {
		printf("Case #%d: ", ii + 1);
		solve();
	}	
	return 0;
}
