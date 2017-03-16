#pragma comment(linker, "/STACK:640000000")
#include<iostream>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<bitset>
#include<algorithm>

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)

using namespace std;

typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);

int T = 0;
int a[22][22];
int b[1 << 16];

void stupid() {
	int r,c,n; cin >> r >> c >> n;
	int res = (int)1e9;
	for (int mask = 0; mask < (1 << (r * c)); mask++) if (b[mask] == n) {
		T++;
		for (int i = 0; i < r * c; i++) if (mask & (1 << i)) {
			a[i / c][i % c] = T;
		}
		int cur = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) if (a[i][j] == T) {
				if (i + 1 < r && a[i + 1][j] == T) cur++;
				if (j + 1 < c && a[i][j + 1] == T) cur++;
			}
		}
		res = min(res,cur);
	}
	cout << res << endl;
}

int main() {
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	for (int i = 1; i < (1 << 16); i++) {
		if (i & 1) {
			b[i] = b[i >> 1] + 1;
		} else {
			b[i] = b[i >> 1];
		}
	}

	int Cases; cin >> Cases; 

	for (int Case = 1;  Case <= Cases; Case++) {
		printf("Case #%d: ",Case);
		stupid();
	}
	
	return 0;
}
