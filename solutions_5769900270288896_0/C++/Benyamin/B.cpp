#include <bits/stdc++.h>
#include <fstream>
#define X first
#define Y second
#define pb push_back
#define popb pop_back
#define mp make_pair
#define cin fin
#define cout fout
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> point;

ifstream fin("B-small-attempt0.in");
ofstream fout("B-small-attempt0.out");

ll t, r, c, n, ans;
ll poz[20][20];


void output(ll level) {
	cout << "Case #" << level << ": " << ans << endl;
	return;
}

void BT(ll i, ll j, ll count) {
	if(count > n)
		return;
	if(count == n) {
		ll tmp = 0;
		for(ll i = 0; i < r; ++i)
			for(ll j = 0; j < c - 1; ++j)
				if(poz[i][j] && poz[i][j + 1])
					tmp++;
		for(ll j = 0; j < c; ++j)
			for(ll i = 0; i < r - 1; ++i)
				if(poz[i][j] && poz[i + 1][j])
					tmp++;
		if(ans > tmp)
			ans = tmp;
		return;
	}
	if(i >= r)
		return;
	//cerr << count << endl;
	poz[i][j] = 1;
	count++;
	if(j < c - 1)
		BT(i, j + 1, count);
	if(j == c - 1)
		BT(i + 1, 0, count);
	count--;
	poz[i][j] = 0;
	if(j < c - 1)
		BT(i, j + 1, count);
	if(j == c - 1)
		BT(i + 1, 0, count);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	for(ll index = 1; index <= t; ++index) {
		cin >> r >> c >> n;
		ans = 1000 * 1000 * 1000;
		for(ll i = 0; i < 20; ++i)
			for(ll j = 0; j < 20; ++j)
				poz[i][j] = 0;
		BT(0, 0, 0);
		output(index);


	}
	return 0;
}