#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:640000000")

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <bitset>
#ifdef _DEBUG
#include <unordered_set>
#include <unordered_map>
#endif

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define forn1(i, n) for(int i = 1; i <= (int)(n); i++)
#define forr(i, l, r) for(int i = int(l); i <= int(r); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)((a).size())
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define y1 __y1
#define sqr(x) ((x) * (x))

typedef long long li;
typedef double ld;
typedef unsigned int uint;
typedef unsigned long long uli;
typedef pair<int, int> pt;

inline void read(int&);
inline void read(li&);
inline void read(ld&);
inline void read(char&);
inline void read(string&);
template <typename T1, typename T2> inline void read(T1&, T2&);
template <typename T1, typename T2, typename T3> inline void read(T1&, T2&, T3&);
template <typename T1, typename T2, typename T3, typename T4> inline void read(T1&, T2&, T3&, T4&);

inline void read(string &s) {
	static char buf[int(1e6) + 10];
	assert(scanf("%s", buf) == 1);
	s = string(buf);
	return;
}

const int INF = (int)(1e9);
const li INF64 = (li)(INF)* (li)(INF);
const ld eps = 1e-9;
const ld pi = ld(3.1415926535897932384626433832795);

inline bool in(int i, int j, int n, int m) {
	return i >= 1 && i <= n && j >= 1 && j <= m;
}

inline int myrand() {
	return (rand() ^ (rand() << 15));
}

inline li randL() {
	return myrand() * 1LL * myrand() + myrand();
}

const int dx[] = { 0, -1, 1, 0 };
const int dy[] = { -1, 0, 0, 1 };

const int N = 111;

int n, a[N];

inline void gen() {
	return;
}

inline bool read() {
	if (!(cin >> n)) return false;
	forn(i, n) assert(cin >> a[i]);
	return true;
}

inline void solve() {
	while (1) {
		//forn(i, n) cerr << a[i] << ' '; cerr << endl;
		int mx = 0;
		int idx = -1;
		int sum = 0;
		forn(i, n) sum += a[i];
		forn(i, n) if (a[i] > mx) {
			mx = a[i];
			idx = i;
		}

		if (mx == 0) break;
		assert(mx * 2 <= sum);
		if (sum & 1) {
			a[idx]--;
			printf("%c ", char(idx + 'A'));
			continue;
		}

		a[idx]--;

		int mx2 = 0, idx2 = -1;
		forn(i, n) {
			if (a[i] > mx2) {
				mx2 = a[i];
				idx2 = i;
			}
		}

		if (mx2 == 0) {
			printf("%c ", char(idx + 'A'));
			continue;
		}

		//cerr << "mx1 mx2 == " << mx << ' ' << mx2 << endl;
		//cerr << "idxs == " << idx << ' ' << idx2 << endl;
		a[idx2]--;
		printf("%c%c ", char(idx + 'A'), char(idx2 + 'A'));
	}

	puts("");
	//cerr << "END" << endl;
	return;
}

int main() {
#ifdef _DEBUG
	assert(freopen("input.txt", "rt", stdin));
	assert(freopen("output.txt", "wt", stdout));
#endif

	cout << setprecision(10) << fixed;
	cerr << setprecision(10) << fixed;

	//srand(int(time(NULL)));

	int T = 1;
	assert(scanf("%d", &T) == 1);

	forn(i, T) {
		cerr << "TEST == " << i + 1 << endl;
		cout << "Case #" << i + 1 << ": ";
		assert(read());
		solve();
	}

#ifdef _DEBUG
	cerr << "TIME == " << clock() << " ms" << endl;
#endif
	return 0;
}