#if 1
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int , int> pii;
typedef vector <int> veci;
typedef vector <veci> graph;
const LD eps = 1e-9;
const LD pi = acos(-1.0);
const int inf = 1000 * 1000 * 1000;
const LL inf64 = LL(inf) * inf;

#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define iss istringstream
#define oss ostringstream
#define dbg(x) //{cerr << #x << " = " << x << endl;}
#define dbgv(x) //{cerr << #x << " ={"; for (int _i = 0; _i < x.size(); _i++) {if (_i) cerr << ", "; cerr << x[_i];} cerr << "}" << endl;}
#define NAME "problem"

template<class T> string to_str(const T &a) { oss os; os << a; return os.str(); }
template<> string to_str<LD>(const LD& a) { oss os; os.precision(10); os.setf(ios::fixed); os << a; return os.str(); }
template<class T> T from_str(const string &s) { iss is; T val; is >> val; return val; }
string T(int test) { ostringstream os; os << "Case #" << test << ":"; return os.str(); }
int _test_start = -1, _test_end = -1;
bool need_to_run(int test) { return _test_start == -1 || (_test_start <= test && test <= _test_end); }

static int dx[] = {-1, 1, 0, 0};
static int dy[] = {0, 0, -1, 1};

void solve(int test) {
	// read
	int r, c, n;
	cin >> r >> c >> n;

	if (!need_to_run(test)) return;
	// solve
	vector<string> a(r, string(c, '.'));
	// chess order
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if ((i + j) % 2 == 0) {
				if (n > 0) {
					--n;
					a[i][j] = '#';
				}
			}
		}
	}

	vector<int> cnt(5);
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (a[i][j] == '.') {
				int cur = 0;
				for (int dir = 0; dir < 4; ++dir) {
					int nx = i + dx[dir], ny = j + dy[dir];
					if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
						continue;
					}
					++cur;
				}

				++cnt[cur];
			}
		}
	}
	dbgv(a);
	int res = 0;
	for (int i = 0; i < cnt.size(); ++i) {
		int add = min(cnt[i], n);
		res += add * i;
		n -= add;
	}

	// write
	cout << T(test) << " " << res << endl;
}

pii get(int mask, int r, int c) {
	vector<string> a(r, string(c, '#'));
	int cnt = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if ((mask & (1 << (i * c + j)))) {
				a[i][j] = '.';
				++cnt;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (a[i][j] == '.') {
				int cur = 0;
				for (int dir = 0; dir < 4; ++dir) {
					int nx = i + dx[dir], ny = j + dy[dir];
					if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
						continue;
					}
					if (a[nx][ny] == '#') {
						continue;
					}
					++cur;
				}
				res += cur;
			}
		}
	}
	res /= 2;
	static int e = 1;
	if (res == 8 && cnt == 11 && e) {
		e = 0;
		dbgv(a);
	}
	return mp(cnt, res);
}
int brute(int r, int c, int n) {
	int res = inf;
	int bmask = -1;
	for (int mask = 0; mask < 1 << (r * c); ++mask) {
		pii p = get(mask, r, c);
		if (p.X == n) {
			if (p.Y < res) {
				res = p.Y;
				bmask = mask;
			}
		}
	}
	return res;
}
void solve2(int test) {
	// read
	int r, c, n;
	cin >> r >> c >> n;

	if (!need_to_run(test)) return;
	// solve
	vector<string> a(r, string(c, '.'));
	int rem = r * c - n;
	int first = 0;
	bool retry = false;
	for (int del = 4; del >= 1; --del) {
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (a[i][j] == '.') {
					int cur = 0;
					for (int dir = 0; dir < 4; ++dir) {
						int nx = i + dx[dir], ny = j + dy[dir];
						if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
							continue;
						}
						if (a[nx][ny] == '#') {
							continue;
						}
						++cur;
					}

					if (cur == del && rem > 0) {
						++first;
						if (first == 1 && r % 2 == 1) {
							retry = true;
							continue;
						}
						a[i][j] = '#';
						--rem;
					}
				}
			}
		}
		if (retry) {
			++del;
			retry = false;
		}
	}
	// for (int i = 0; i < r; ++i) {
	// 	dbg(a[i]);
//	}
	dbgv(a);
	int res = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (a[i][j] == '.') {
				int cur = 0;
				for (int dir = 0; dir < 4; ++dir) {
					int nx = i + dx[dir], ny = j + dy[dir];
					if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
						continue;
					}
					if (a[nx][ny] == '#') {
						continue;
					}
					++cur;
				}
				res += cur;
			}
		}
	}
	res /= 2;
	
	// write
	int bt = brute(r, c, n);
	cout << T(test) << " " << bt << endl;
//	cout << T(test) << " " << res << " " << bt << (bt != res ? " xxx" : "") << endl;
}

int main(int argc, char *argv[]) {
	//freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	//freopen(NAME ".in","r",stdin); freopen(NAME ".out","w",stdout);
	if (argc == 2) { _test_start = _test_end = from_str<int>(argv[1]); }
	if (argc == 3) { _test_start = from_str<int>(argv[1]); _test_end = from_str<int>(argv[2]); }

	clock_t tstart = clock();
	
	int tests;
	scanf("%d", &tests);
	for(int test = 1; test <= tests; ++test) {
		clock_t tprev = clock();
		solve2(test);
		if (need_to_run(test)) {
		//	dbg("elapsed for #" << test << ": " << (clock() - tprev) / LD(CLOCKS_PER_SEC));
		}
	}

	dbg("elapsed: " << (clock() - tstart) / LD(CLOCKS_PER_SEC));
	return 0;
}
/*************************
*************************/
#endif
