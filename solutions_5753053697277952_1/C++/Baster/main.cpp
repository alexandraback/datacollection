#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <algorithm>
#include <iomanip>

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

const ld EPS = 1e-9;
const int INF = int(1e9);
const li INF64 = li(1e18);

int n;
int cnt[30];

                      
inline bool read() {
	cin >> n;
	forn (i, n)
		cin >> cnt[i];
	return true;
}         

void solve() {
	set<pair<int, int> > temp;
	int m1 = -1, m2 = -1;	
	forn (i, n) {
		if (m1 == -1 || cnt[i] > cnt[m1]) {
			m2 = m1;
			m1 = i;
		} else
			if (m2 == -1 || cnt[i] > cnt[m2])
				m2 = i;	
	}

	int d = cnt[m1] - cnt[m2];
	forn (i, d) {
		cnt[m1]--;
		cout << char('A' + m1) << ' ';
	}

	m1 = -1, m2 = -1;        

	forn (i, n) {
		if (m1 == -1 || cnt[i] > cnt[m1]) {
			m2 = m1;
			m1 = i;
		} else
			if (m2 == -1 || cnt[i] > cnt[m2])
				m2 = i;	
		temp.insert(mp(cnt[i], i));
	}
	assert(cnt[m1] == cnt[m2]);
	assert(m1 != m2);
	while(sz(temp) > 2) {
		pt x = *temp.begin();
		cout << char(x.sc + 'A') << ' ';
		x.ft--;
		temp.erase(temp.begin());
		if (x.ft) 
			temp.insert(x);
	}
	pt l = *temp.begin();
	pt r = *temp.rbegin();
	forn (i, l.ft)
		cout << char(r.sc + 'A') << char(l.sc + 'A') << ' ';
	cout << endl;
}         

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
   	cerr << setprecision(10) << fixed;
	cout << setprecision(15) << fixed;

	srand(time(NULL));
	
	int t;
	cin >> t;

	forn (i, t) {
	    cout << "Case #" << i + 1 << ": ";
		read();
		solve();
	}
	
#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}