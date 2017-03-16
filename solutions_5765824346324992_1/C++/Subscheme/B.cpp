#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#define range(i,a,b) for(int i = (a), _n = (b); i < _n; ++i)
#define fo(i,n) range(i,0,n)

typedef long long ll;
typedef pair<ll,ll> pr;
const int B = 1100, N = 1100100100;
ll m[B], n, b;

ll doneIn(ll t) {
	ll tot = 0;
	fo(i,b) tot += t / m[i] + 1;
	return tot;
}

int main() {
	int T;
	cin >> T;
	range(testCase, 1, T+1) {
		cin >> b >> n;
		fo(i,b) cin >> m[i];
		ll low = 0, high = m[0] * n;
		while (high > low) {
			ll mid = (high + low) / 2;
			ll d = doneIn(mid);
			//cout << mid << ' ' << d << endl;
			if (d >= n) {
				high = mid;
			} else if (d < n) {
				low = mid + 1;
			}
		}
		
		ll t = low - 1;
		n -= doneIn(t);
		
		vector<int> v;
		v.push_back(0);
		fo(i,b) if((t+1) % m[i] == 0) v.push_back(i+1);
		//cout << t << ' ' << v.size() << ' ' << n << endl;
		cout << "Case #" << testCase << ": " << v[n] << endl;
	}
}