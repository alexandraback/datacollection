#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <limits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef vector<vector<int> > graph;

const double pi = acos(-1.0);

#define oned(a, x1, x2) { cout << #a << ":"; for(int _i = (x1); _i < (x2); _i++){ cout << " " << a[_i]; } cout << endl; }
#define twod(a, x1, x2, y1, y2) { cout << #a << ":" << endl; for(int _i = (x1); _i < (x2); _i++){ for(int _j = (y1); _j < (y2); _j++){ cout << (_j > y1 ? " " : "") << a[_i][_j]; } cout << endl; } }

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

int n, m, k;

int brute() {
	int ans = 1e9;
	for(int msk = 0; msk < (1<<(n*m)); msk++) {
		if(__builtin_popcount(msk)==k) {
			int a[20][20];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					a[i][j] = msk&(1<<(i*m+j));
				}
			}
			int cnt = 0;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j+1 < m; j++) {
					cnt += a[i][j]&&a[i][j+1];
				}
			}
			for(int j = 0; j < m; j++) {
				for(int i = 0; i+1 < n; i++) {
					cnt += a[i][j]&&a[i+1][j];
				}
			}
			ans = min(ans, cnt);
		}
	}
	return ans;
}

int main() {
	freopen("B-input.in", "r", stdin);
	freopen("B-output.out", "w", stdout);
	int t; scanf("%d", &t);
	for(int c = 1; c <= t; c++) {
		scanf("%d %d %d", &n, &m, &k);
		printf("Case #%d: %d\n", c, brute());
	}
}
