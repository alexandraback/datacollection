#include <cstdio>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REPE(i,x,y) for (ll i=(x);i<(y);i++)
#define REP(i,x,y) for (ll i=(x);i<=(y);i++)
#define DREP(i,x,y) for (ll i=(x);i>=(y);i--)
#define mp make_pair
#define pb push_back
#define MAXN 100100

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

pii P[MAXN];
ll S[MAXN];

ll ccw(pii A,pii B,pii C) {
	ll x = (B.first - A.first)*(C.second - A.second) - (B.second - A.second)*(C.first - A.first);
	if (x==0) return 0;
	return (x < 0) ? -1 : 1;
}

bool CH(vector<pii> A,pii X) {
	ll n = A.size()-1;
	REP(i,0,n) {
		if (A[i]==X) continue;
		bool ok = true;
		REP(j,0,n) {
			if (ccw(A[i],X,A[j]) < 0) {
				//cout<<P[i].first<<" "<<P[i].second<<" ; "<<P[j].first<<" "<<P[j].second<<endl;
				ok = false; break;
			}
		}
		if (ok) return true;
	}
	return false;
}


void solve(ll tc) {
	ll n; cin>>n;
	REP(i,0,n-1) {
		cin>>P[i].first>>P[i].second;
	}
	cout<<"Case #"<<tc<<":"<<endl;
	REPE(i,0,n) {
		ll ans = n-1;
		REPE(msk,0,1<<n) {
			vector<pii> V;
			ll del = n;
			if ((msk & (1<<i)) <= 0) {
				continue;
			}
			//cout<<"****"<<endl;
			REPE(j,0,n) { 
				if ((msk & (1<<j)) > 0) {
					del--;
					V.pb(P[j]);
					//cout<<P[j].first<<" "<<P[j].second<<endl;
				}
			}
			if (CH(V,P[i])) {
				ans = MIN(ans, del);
				//cout<<del<<" "<<"Ok"<<endl;
			}
			//cout<<" ---- "<<endl;
		}
		cout<<ans<<endl;
	}
	
}		

int main() {
	ios::sync_with_stdio(false);
	ll t; cin>>t;
	REP(i,1,t) solve(i);
}
