#include <bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define all(v) v.begin(), v.end()
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, b, a) for (int i = b; i > a; i--)
#define Si(a) scanf("%d", &(a))
#define Sl(a) scanf("%lld", &(a))
#define SZ size()
#define F first
#define S second
#define B begin()
#define E end()

#define mod 1000000007

using namespace std;

typedef unsigned long long int ull;
typedef long long int lli;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <typename T>
T power(T a, int n){
	T res = 1;
	while (n) {
		if (n & 1) res = (res * a) % mod;
		n >>= 1; a = (a * a) % mod;
	}
	return res;
}

string fn(string s)
{
	string myvector = s;
	std::string::iterator it;
  it = std::unique (myvector.begin(), myvector.end());   // 10 20 30 20 10 ?  ?  ?  ?
                                                         //                ^

  myvector.resize( std::distance(myvector.begin(),it) );
  return myvector;
}

int main()
{
	int T;
	int n;
	string s[102];
	string s2[102];

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		For (i, 0, n) {
			cin >> s[i];
			s2[i] = fn(s[i]);
		}
		bool flag = 1;
		For (i, 0, n-1) {
			if (s2[i] != s2[i+1]) {
				flag = 0;
				break;
			}
		}
		if (!flag) {
			cout << "Case #" <<  t << ": Fegla Won" << endl;
			continue;
		}

		vector< vector<int> > v(n);

		for (int i = 0; i < n; i++) {
			int j = 0;
			int x = 1;
			s[i] = s[i] + "#";
			//cout << s[i] << ": ";
			while (j < s[i].SZ - 1) {
				if (s[i][j] == s[i][j+1]) {
					x++;
				}
				else {
					v[i].PB(x);
				//	cout << x << " ";
					x = 1;
				}
				j++;
			}
			//cout << endl;
		}
		int cost = 0;
		for (int i = 0; i < v[0].SZ; i++) {
			int l = v[0][i];
			int u = v[0][i];
			for (int j = 0; j < n; j++) {
				l = min(l, v[j][i]);
				u = max(u, v[j][i]);
			}
			int ta = 1000000000;
			for (int k = l; k <= u; k++) {
				int z = 0;
				for (int l = 0; l < n; l++) {
					z += abs(v[l][i] - k);
				}
				ta = min(ta, z);
			}
			cost += ta;
		}

		cout << "Case #" << t << ": " << cost << endl;

	}

	return 0;
}
