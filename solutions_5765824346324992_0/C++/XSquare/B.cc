#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll can(vector <ll> &v, ll m, ll p){
	ll n = v.size();
	ll pos = 0;
	ll N = 0;
	vector <ll> w(0);
	for (ll i = 0; i < n; ++i){
		if (m%v[i] == 0){
			w.push_back(i+1);
			N += m/v[i];
			if (pos <= 0) pos = i+1;
		}
		else N += m/v[i] + 1;
	}
	if (N + w.size() > p and N <= p) return w[p-N];
	else if (N+w.size() > p) return 90;
	return 0;
}

int main(){
	ll T;
	cin >> T;
	for (ll t = 1; t <= T; ++t){
		cout << "Case #" << t << ": ";
		ll N, m;
		cin >> N >> m;
		vector <ll> v(N);
		for (ll i = 0; i < N ; ++i) cin >> v[i];
		ll ini = 0, end = 1e16;
		ll x = can(v, 0, m-1);
		if (x > 0){
			cout << x << endl;
			continue;
		}
		while (end - ini > 1){
			//cout << "hello ";
			ll mid = (ini + end)/2;
			ll d = can(v, mid, m-1);
			if (d > 0) end = mid;
			else ini = mid;
		}
		//cout << end << endl;
		cout << can(v, end, m-1) << endl; 
	}
}
