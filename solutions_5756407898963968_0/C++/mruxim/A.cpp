// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int get_valids() {
	int ret = 0;
	int row; cin >> row; row--;
	rep(i, 16) {
		int x; cin >> x; x--;
		if(i / 4 == row) ret |= 1 << x;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int testn; cin >> testn;
	for(int testc = 1; testc <= testn; testc++) {
		int mask = (1 << 16) - 1;
		mask &= get_valids();
		mask &= get_valids();

		cout << "Case #" << testc << ": ";
		if(mask == 0) cout << "Volunteer cheated!" << endl;
		else if(mask & (mask-1)) cout << "Bad magician!" << endl;
		else cout << __builtin_ctz(mask) + 1 << endl;
	}

	{ return 0; }
}

