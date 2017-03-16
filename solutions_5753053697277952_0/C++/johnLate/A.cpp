#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (auto i = begin(c); i != end(c); i++)
#define all(c) begin(c), end(c)
#define sz(c) int((c).size())
#define mp make_pair
#define pb push_back
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

template<class C, class I>
bool has(C con, I item) {
	return con.find(item) != con.end();
}

int main() {
	ios::sync_with_stdio(false);

	int TC;
	cin >> TC;
	FOR(tc, 1, TC+1) {
		cout << "Case #" << tc << ":";

		ll N;
		cin >> N;

		assert(N >= 2);

		vector<pii> parties; // count, idx
		int total = 0;

		FOR(i,0,N) {
			int cnt;
			cin >> cnt;
			total += cnt;
			parties.pb(pii(cnt, i));
		}

		sort(all(parties), greater<pii>());

		FOR(ref, 1, N) {
			while (parties[0].first - 1 >= parties[ref].first) {
				FOR(x, 0, ref) {
					assert(parties[x].first * 2 <= total);
					cout << " " << char('A'+parties[x].second);
					parties[x].first--;
					total--;
				}
			}
		}

		while (parties[0].first > 0) {
			int x = 0;
			assert(parties[x].first * 2 <= total);
			if ((N & 1) == 1) {
				cout << " " << char('A' + parties[x].second);
				parties[x].first--;
				x++;
				total--;
			}
			while (x < N) {
				assert(parties[x].first * 2 <= total);
				assert(parties[x+1].first * 2 <= total);
				cout << " " << char('A' + parties[x].second);
				parties[x].first--;
				x++;
				assert(parties[x].first * 2 <= total);
				cout << char('A' + parties[x].second);
				parties[x].first--;
				x++;
				total--;
				total--;
			}
		}

		assert(total == 0);
		cout << endl;
	}
}
