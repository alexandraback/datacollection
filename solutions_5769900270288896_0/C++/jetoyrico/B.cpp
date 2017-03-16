#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define rep(i,m) for(int i=0;i<(int)(m);++i)
#define sz(c) (int((c).size()))
#define fill(a,b) memset(a,b,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define two(x) (1<<(x))
#define twoll(x) ((long long)1<<(x))
#define contain(m,x) (((m)&two(x))!=0)
#define containll(m,x) (((m)&twoll(x))!=0)

const int dr[] = { -1, 0, 1, 0 }; // N,E,S,W
const int dc[] = { 0, 1, 0, -1 };

template<class T>
int popcount(T n) {
	int cnt = 0;
	for (ll i = 0; i < 8 * sizeof(T); ++i)
		if ((1LL << i) & n) cnt++;
	return cnt;
}

int R, C, N;

bool valid(int nr, int nc) {
	return nr >= 0 && nr < R && nc >= 0 && nc < C;
}

void solve(int cur_case) {
	cin >> R >> C >> N;
	int ans = 1e9;
	for (int mask = 0; mask < two(R * C); ++mask) {
		if (popcount(mask) != N) continue;
		vvi g(R, vi(C, 0));
		rep(i, R) rep(j, C) if (contain(mask, i * C + j)) g[i][j] = 1;
		set<pii> st;
		rep(i, R) rep(j, C) {
			if (!g[i][j]) continue;
			rep(d, 4) {
				int ni = i + dr[d];
				int nj = j + dc[d];
				if (valid(ni, nj) && g[ni][nj]) {
					int a = i * C + j;
					int b = ni * C + nj;
					st.insert(pii(min(a, b), max(a, b)));
				}
			}
		}
		ans = min(ans, sz(st));
	}
	cout << "Case #" << cur_case << ": " << ans << endl;
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;
	freopen("B-small-attempt1.in", "rt", stdin);
	//freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	clock_t start_time = clock(), check_time;
	int total_cases;
	cin >> total_cases;
	for (int cur_case = 1; cur_case <= total_cases; ++cur_case) {
		solve(cur_case);
		check_time = clock(); cerr << "Case #" << cur_case << " elapsed time: " << check_time - start_time << "ms" << endl; start_time = clock();
	}
	return 0;
}
