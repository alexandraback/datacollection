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
#pragma comment(linker, "/STACK:640000000")
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
int a[22],b[22];
void solve() {
	int x; cin >> x;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			int val; cin >> val;
			a[val] = i;
		}
	}
	int y; cin >> y;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			int val; cin >> val;
			b[val] = i;
		}
	}
	vector<int> vals;
	for (int i = 1; i <= 16; i++) {
		if (a[i] == x && b[i] == y) {
			vals.pb(i);
		}
	}
	if (vals.empty()) {
		puts("Volunteer cheated!");
	} else if (sz(vals) > 1) {
		puts("Bad magician!");
	} else {
		printf("%d\n",vals[0]);
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int Cases; cin >> Cases;
	for (int Case = 1; Case <= Cases; Case++) {
		printf("Case #%d: ",Case);
		solve();
	}
	return 0;
}
