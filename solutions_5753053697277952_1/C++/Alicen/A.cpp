#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<ll, ll> pll;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;

#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = ll(b)-1; i >= (a); i--)
#define MAPIT(i,c,k) for (auto i = (c).equal_range((k)).first; i!= (c).equal_range((k)).second; i++)

#define sz(c) ll((c).size())
#define all(c) (c).begin(), (c).end() 
#define mp make_pair
#define pb push_back
#define xx first
#define yy second
#define has(c, i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr); 

	int T;
	cin >> T;
	for (int count = 0; count < T; ++count) {
		int N;
		cin >> N;

		priority_queue<pair<int, char>> q;

		for (int i = 0; i < N; ++i) {
			int x;
			cin >> x;
			q.push(mp(x, char(i+'A')));
		}

		string erg = "";
		while(!q.empty()){
			pair<int, char> h = q.top(); q.pop();
			pair<int, char> sh;
			pair<int, char> th;
			if(sz(q) == 0){
				sh = {0, ' '};	
			} else {
				sh  = q.top(); q.pop();
			}
			if(sz(q) == 0){
				th = {0, ' '};
			} else {
				th = q.top();
			}

			if(h.xx == sh.xx && h.xx != th.xx){
				erg += h.yy;
				erg += sh.yy;
				h.xx--;
				sh.xx--;
			} else {
				erg += h.yy;
				if(h.xx > 1){
					erg += h.yy;
					}
				h.xx -= 2;
			}
			erg += " ";
			if(h.xx > 0) q.push(h);
			if(sh.xx > 0) q.push(sh);
		}
		cout << "Case #" << count+1 << ": " << erg << endl;
	}

	return 0;
}
