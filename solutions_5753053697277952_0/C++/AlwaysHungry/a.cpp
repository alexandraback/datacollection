#include <bits/stdc++.h>

#define ALL(v) v.begin(), v.end()
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPD(i, a, b) for (int i = a; i > b; i--)
#define REPLL(i, a, b) for (ll i = a; i < b; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define FORLL(i, a, b) for (ll i = a; i <= b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

typedef vector<int>::iterator vit;
typedef set<int>::iterator sit;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef pair<ld, ld> pld;

#define remax(a, b) a = max(a, b)
#define remin(a, b) a = min(a, b)

#define popcount __builtin_popcount
#define pb push_back
#define mp make_pair
#define st first
#define y first
#define nd second
#define x second

#define eps 1e-9
#define pi acos(-1.0)

//const int inf = 1e9 + 1;

const int N = 100123;

int z, n;
int p[N];

void solve(int tc) {
	cin >> n;
	REP(i, 0, n) cin >> p[i];

	set<pii, greater<pii> > s;
	REP(i, 0, n) s.insert({p[i], i});

	cout << "Case #" << tc << ": ";

	while(s.size()) {
		if(s.size() == 3) {
			pii a = *s.begin(); s.erase(a);
			cout << char(a.nd+'A') << " ";
			a.st--;
			if(a.st) s.insert(a);
		}
		else {
			pii a = *s.begin(); s.erase(a);
			cout << char(a.nd+'A');
			a.st--; 
			if(a.st) s.insert(a);
			if(!s.size()) {
				continue;
			}
			pii b = *s.begin(); s.erase(b);
			cout << char(b.nd+'A') << " ";
			b.st--;
			if(b.st) s.insert(b);
		}
	}
	cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);

  cin >> z;
  FOR(tc, 1, z) solve(tc);
}