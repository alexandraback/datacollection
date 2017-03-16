#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pi 3.14159265
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define MEM(x, y) memset(x, y, sizeof(x))
#define round(x) x + 0.5
using namespace std ;

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ":";
		cin >> n;
		int senate[27] = {0}, m = 100010;
		for (int i = 0; i < n; i++) {
			cin >> senate[i];
			if (senate[i] < m)
				m = senate[i];
		}
		// for (int i = 0; i < n; i++)
			// cout << senate[i] << "  ";
		// cout << endl;

		// bool evac = false;
		// do {
			// evac = false;
			// for (int i = 0; i < n; i++) {
				// if (senate[i] > m) {
					// cout << " " << (char)('A' + i);
					// senate[i]--;
					// evac = true;
				// }
			// }
		// } while(evac);

		set<pii> sen;
		for (int i = 0; i < n; i++) {
			sen.insert(mp(senate[i], i));
		}
		
		set<pii>::reverse_iterator rit;
		bool evac;
		do {
			evac = false;
			rit = sen.rbegin();
			if ((*rit).f > m) {
				evac = true;
				cout << " " << (char)('A' + (*rit).s);
				pii x = (*rit);
				senate[x.s]--;
				sen.erase(x);
				sen.insert(mp(senate[x.s], x.s));
			}
		}while(evac);

		
		for (int k = 0; k < m; k++) {
			for (int i = 0; i < (n - 2); i++) {
				cout << " " << (char)('A' + i);
			}
			cout << " " << (char)('A' + n - 2) << (char)('A' + n - 1);
		}
		cout << endl;
	}
	return 0;
}