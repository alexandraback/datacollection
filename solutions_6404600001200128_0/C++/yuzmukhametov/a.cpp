// -Wl,--stack,9001 
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)((x).size()))
#define rep(i, N) for (int i = 0; i < N; ++i)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
typedef long long lint;
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;
int N;
int A[1 << 20];
void solve(int num) {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int x1 = 0, x2 = 0;
	int mx = 0;
	for (int i = 1; i < N; ++i) {
		if (A[i] < A[i - 1]) {
			x1 += A[i - 1] - A[i];
			mx = max(mx, A[i - 1] - A[i]);
		}
	}
	for (int i = 1; i < N; ++i) {
		int t = min(A[i - 1], mx);
		x2 += t;
	}
	int ans = 0;
	printf("Case #%d: %d %d\n", num, x1, x2);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tst;
	cin >> tst;
	for (int i = 1; i <= tst; ++i) {
		solve(i);
	}
    return 0;
}
