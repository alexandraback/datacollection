#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) {
	return (a % b) ? gcd(b, a % b) : b;
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	ll T;
	cin >> T;
	for(int t = 0; t < T; t++) {
		ll B, N;
		cin >> B >> N;
		vector<ll> M;
		M.resize(B);
		ll l = 1;
		for(int i = 0; i < B; i++) {
			cin >> M[i];
			l = lcm(l, M[i]);
		}

		vector<pll> v;
		for(int i = 0; i < M.size(); i++) {
			for(int j = 0; M[i] * j < l; j++) {
				v.push_back(pll(M[i] * j, i+1));
			}
		}

		sort(v.begin(), v.end());
		cout << "Case #" << t+1 << ": " << v[(N-1) % v.size()].second << endl;
	}
}
