#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)

typedef pair<int, int> pii;

pii a[30];


void solve() {
	int n;
	cin >> n;
	REP(i, n) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a+n);
	reverse(a, a+n);
	bool work = true;
	while (work) {
		work = false;
		int p = 0;
		while (p < n && (p == 0 || a[p].first > a[p-1].first) && a[p].first > 0) {
			cout << ' ' << (char) ('A' + a[p].second);
			a[p].first--;
			work = true;
			p++;
			if (n == 2 && p == 1 && a[p].first > a[p-1].first || 
				p == n-1 && a[p].first == 1 && a[p-1].first == 0) {
				cout << (char) ('A' + a[p].second);
				p++;
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	REP(i, t) {
		cout << "Case #" << (i+1) << ":";
		solve();
		cout << endl;
	}
}