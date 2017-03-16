#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<ll, ll> pll;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define xx first
#define yy second
#define DB(X) { if(1) cerr << "DB: " << (#X) << " = " << (X) << endl; }

vector<string> plan;

bool no_maj(vl &p, ll N, ll num){
	FOR(i,0,N){
		if(p[i] > (num)/2){
			return false;
		}
	}
	return true;
}

bool brute_force(vl &p, ll N, ll num){
	if(num == 0) return true;
	FOR(i,0,N){
		if(p[i]){
			p[i]--;
			FOR(j,0,N){
				if(p[j]){
					p[j]--;
					if(no_maj(p, N, num-2) && brute_force(p, N, num-2)){
						char c1 = 'A' + i, c2 = 'A' + j;
						string s = "";
						s += c1; s +=c2;
						plan.pb(s);
						return true;
					}
					p[j]++;
				}
			}
			p[i]++;
		}
	}
	FOR(i,0,N){
		if(p[i]){
			p[i]--;
			if(no_maj(p, N, num-1) && brute_force(p, N, num-1)){
				string s;
				s += (char)('A' + i);
				plan.pb(s);
				return true;
			}
			p[i]++;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll TC;
	cin >> TC;
	FOR(tc,0,TC){
		plan = vector<string>();
		ll N;
		cin >> N;
		vector<pair<ll, char>> p(N);
		ll num = 0;
		FOR(i,0,N){
			ll k;
			cin >> k;
			num += k;
			p[i] = mp(k, 'A'+i);
		}
		cout << "Case #" << tc+1 << ": ";
		while(num){
			sort(p.rbegin(), p.rend());
			p[0].xx--; num--;
			cout << p[0].yy;
			if(p[1].xx > num/2){
				p[1].xx--; num--;
				cout << p[1].yy;
			}
			cout << " ";
		}
		cout << endl;
	}
}
