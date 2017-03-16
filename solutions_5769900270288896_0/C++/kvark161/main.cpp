// Smile please :)

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//#undef KVARK_DEBUG

#ifdef KVARK_DEBUG
	#include "../h/debug.h"
#else
#define dbg(...) (void(1));
#define dbg2(...) (void(1));
#define dbg3(...) (void(1));
#define dbg4(...) (void(1));
#define dbg5(...) (void(1));
#define dbgp(...) (void(1));
#define dbg_arr(...) (void(1));
#define dbg_vec(...) (void(1));
#endif
#define endl "\n"

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vector<int> > vvi;
typedef vector<vector<pii> > vvpii;
typedef vector<vector<long long> > vvll;
typedef vector<long long> vll;
typedef long long int llint;

#define all(v) (v.begin()), (v.end())

template <typename T>
inline T sqr(const T& a) {
	return a * a;
}

template <typename T>
inline int sign(const T& a) {
	return a < 0 ? -1 : a > 0;
}

void task();

int main() {
#ifdef KVARK
	freopen("src/input.txt", "r", stdin);
	//freopen("src/debug.txt", "w", stderr);
	freopen("src/output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);

	int tests;
	cin >> tests;
	for (int test = 0; test < tests; ++test) {

		cout << "Case #" << test + 1 << ": ";
		task();
		cout << endl;
	}

#ifdef KVARK_DEBUG
//	my_debug::printProcessInfo();
#endif
	return 0;
}

int ans = 100;
int _ans = 0;
int r, c, n;
int board[20][20];
int sad[20][20];

const int shift[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void go(int i, int j, int k) {
	if (i == r+1 || k == n) {
		if (k != n)
			return;
		int _ans = 0;
		for (int i = 1; i <= r; ++i)
			for (int j = 1; j <= c; ++j)
				for (int h = 0; h < 4; ++h) {
					int ii = i + shift[h][0];
					int jj = j + shift[h][1];
					if (board[ii][jj] && board[i][j])
						++_ans;
				}
		ans = min(ans, _ans / 2);
		return;
	}

	if (k != n){
		int h = k + 1;
		board[i][j] = h;
		go(j == c ? i + 1 : i, j == c ? 1 : j + 1, k + 1);
		board[i][j] = 0;
	}

	go(j == c ? i + 1 : i, j == c ? 1 : j + 1, k);
}

void task(){
	cin >> r >> c >> n;
	ans = 100;
	go(1, 1, 0);
	cout << ans;
}
