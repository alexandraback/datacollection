#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)

using namespace std;
int m[1000+20];
int r1, r2;
void solve() {
	int n;
	cin >> n;
	REP(i, n) {
		cin >> m[i];
	}
	r1 = 0;
	r2 = 0;
	int diff = 0;
	FOR(i,1,n-1){
		if (m[i] < m[i-1]) {
			r1 += m[i-1] - m[i];
			diff = max(diff, m[i-1] - m[i]);
		}
	}
	int rate = diff;// / 10 + (diff % 10 == 0 ? 0 : 1);
	FOR(i,0,n-2){
		r2 += min(m[i], rate);
	}
}

int main() {
	int t;
	scanf(" %d", &t);
	REP(i, t) {
		solve();
		printf("Case #%d: %d %d\n", i+1, r1, r2);
	}
}