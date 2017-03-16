#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

int TC;
int R, C, RC, N;

bool foo(int r, int c, int i) {
	return i & (1<<(r*C + c));
}


int main() {
	ios::sync_with_stdio(false);

	cin >> TC;
	FOR(tc, 1, TC+1) {
		int res = oo;
		cin >> R >> C >> N;;
		RC = R * C;
		assert(RC <= 16);

		FOR(i,0,(1<<RC)) {
			if (__builtin_popcount(i) != N) continue;
			int x = 0;
			FOR(r,1,R) FOR(c,0,C) if (foo(r,c,i) && foo(r-1,c,i)) x++;
			FOR(c,1,C) FOR(r,0,R) if (foo(r,c,i) && foo(r,c-1,i)) x++;
			res = min(res, x);
		}

		printf("Case #%d: %d\n", tc, res);
	}
}
