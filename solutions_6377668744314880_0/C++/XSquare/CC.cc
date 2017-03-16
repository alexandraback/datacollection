#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> PI;

ll cp (PI a, PI b){
	return a.first*b.second - a.second*b.first;
}

PI operator- (PI a, PI b){
	return PI(a.first - b.first, a.second - b.second);
}

int main(){
	ll T;
	cin >> T;
	for (ll t = 1; t <= T; ++t){
		cout << "Case #" << t << ":" << endl;
		ll N;
		cin >> N;
		vector <PI> v(N);
		for (ll i = 0; i < N; ++i){
			cin >> v[i].first >> v[i].second;
		}
		if (N == 1){
			cout << 0 << endl;
			continue;
		}
		for (ll i = 0; i < N; ++i){
			ll mini = N;
			for (ll j = 0; j < N; ++j){
				if (j != i){
					ll N1 = 0, N2 = 0;
					for (ll k = 0; k < N; ++k){
						if (cp(v[k] - v[i], v[j] - v[i]) > 0) ++N1;
						else if (cp(v[k] - v[i], v[j] - v[i]) < 0) ++N2;
					}
					mini = min(mini, min(N1, N2));
				}
			}
			cout << mini << endl;
		}
	}
}
