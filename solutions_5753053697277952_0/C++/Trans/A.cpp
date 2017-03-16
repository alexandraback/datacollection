//This is getting accepted!
#include<bits/stdc++.h>

using namespace std;

#define FI first
#define SE second
#define pb push_back
#define mp make_pair
#define ll long long
#define sz(a) ((int)(a).size())
#define __builtin_popcount __builtin_popcounll

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> ppi;

const double PI = acos(0) * 2;
const double EPS = 1e-8;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int oo = 1e9;
const double foo = 1e30;

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcounll(s);}

int T, tc, a[1010], n;

int main() {
//#ifndef ONLINE_JUDGE
//    freopen("inp.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//#endif

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=1; i<=n; i++) cin >> a[i];
		cout << "Case #" << ++tc << ": ";
		a[0] = 0;
		int p1 = 0, p2 = 0;
		while (1) {
			p1 = 0, p2 = 0;
			for (int i=1; i<=n; i++) {
				if (a[i] > a[p1]) p1 = i;
			}
			for (int i=1; i<=n; i++) if (i != p1) {
				if (a[i] > a[p2]) p2 = i;
			}
			
			if (p1 != 0) a[p1]--;
			if (p2 != 0) a[p2]--;
			int t = 0;
			for (int i=1; i<=n; i++) {
				t += a[i];
			}
			if (t == 1) {
				for (int i=1; i<=n; i++) {
					if (a[i] == 1) {
						cout << (char) (i - 1 + 'A') << " ";
						a[i]--;
						break;
					}
				}
			}
//			cout << a[p1] << " " << a[p2] << endl;
			if (p1 != 0) cout << (char) (p1 - 1 + 'A');
			if (p2 != 0) cout << (char) (p2 - 1 + 'A');
			if (p1 == 0 && p2 == 0) break;
			cout << " ";
		}
		cout << endl;
	}


}

