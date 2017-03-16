#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define X first
#define Y second
#define Sz size()
#define mp make_pair
#define foreach(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define Say(x) cerr << #x << " = " << x << endl
#define For(i, n) for(int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector <int> vint;
typedef pair <int,int> pii;

const int M = 100 + 4, Inf = 1e9 + 10;

/////////////////////////////////////////////////////////////////////////

int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t ++) {
		int n;
		cin >> n;
		vector<pii> v;
		for (int i = 0; i < n; i ++) {
			int x;
			cin >> x;
			v.pb(mp(x, i));
		}
		cout << "Case #" << t << ": ";
		while (v.size()) {
			sort(ALL(v));
			int back = v.size() - 1;
			if (back == 1 && v[back].X == v[back - 1].X) {
				cout << char(v[back].Y + 'A') << char(v[back - 1].Y + 'A') << " ";
				v[back].X --;
				v[back - 1].X --;
				if (!v[back].X) {
					v.pop_back();
					v.pop_back();
				}
			}
			else {
				cout << char(v[back].Y + 'A') << " ";
				v[back].X --;
				if (!v[back].X)
					v.pop_back();
			}
		}
		cout << endl;
	}
	return 0;
}
