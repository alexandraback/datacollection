#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef long long int64;
//#define double long double
const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const double EPS = 1E-9;
const double EPS_ANG = 1E-16;
const double PI = acos((double)0) * 2;

#define forn(i, n)  for (int i = 0; i < int(n); ++i)
#define ford(i, n)  for (int i=int(n) - 1; i >= 0; --i)
#define fore(i, l, r)  for (int i = int(l); i < int(r); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define mp  make_pair
#define pb  push_back


int ans[2], field[2][4][4];


void read() {
	forn(it, 2) {
		cin >> ans[it];
		--ans[it];
		forn(x, 4)
			forn(y, 4)
				cin >> field[it][x][y];
	}
}


void solve() {
	int cnt[17] = { 0 };
	forn(it, 2)
		forn(y, 4)
			++cnt[field[it][ans[it]][y]];
	int ans_cnt = (int)count(cnt, cnt + 17, 2);
	if (ans_cnt == 0)
		cout << "Volunteer cheated!\n";
	else if (ans_cnt > 1)
		cout << "Bad magician!\n";
	else
		cout << find(cnt, cnt + 17, 2) - cnt << "\n";
}


int main(int argc, char *argv[]) {
	int test_to_execute = (argc == 2) ? atoi(argv[1]) : -1;

	if (test_to_execute == -1) {
		freopen("input.txt", "rt", stdin);
		freopen("output.txt", "wt", stdout);
	}

	int tests;
	cin >> tests;
	
	if (test_to_execute != -1 && !(1 <= test_to_execute && test_to_execute <= tests)) {
		cerr << "Requested test doesn't exist!" << endl;
		throw std::exception("Requested test doesn't exist!");
	}

	for (int test = 1; test <= tests; ++test) {
		time_t start_time = clock();
		read();
		if (!cin)
			throw;
		if (test_to_execute != -1 && test != test_to_execute)
			continue;
		printf("Case #%d: ", test);
		solve();
		cerr << "Test #" << test << " done! [" << (clock() - start_time) / CLOCKS_PER_SEC << " sec]" << endl;
	}
}
