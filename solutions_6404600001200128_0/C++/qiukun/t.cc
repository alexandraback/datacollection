#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
#include <complex>
using namespace std;

#define FOR(i, a, b) for(int i = a, __up = b; i < __up; ++i)
#define REP(n) FOR(i, 0, n)
#define CLR(a) memset(a, 0, sizeof a)

typedef complex<double> point;
typedef long long ll;

// S E N W
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

#define N 1000
int a[N];
void solve() {
	int n;
	cin >> n;
	REP(n) cin >> a[i];
	int cnt = 0, rate = 0;
	for (int i = 0; i < n-1; ++i) {
		if (a[i] > a[i+1]) {
			int t = a[i]-a[i+1];
			cnt += t;
			if (t > rate) rate = t;
		}
	}
	int cnt2 = 0;
	for (int i = 0; i < n-1; ++i) {
		cnt2 += min(rate, a[i]);
	}
	printf("%d %d", cnt, cnt2);
}

int T;

int main()
{
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		printf("Case #%d: ", t);
		solve();
		puts("");
	}

	return 0;
}
