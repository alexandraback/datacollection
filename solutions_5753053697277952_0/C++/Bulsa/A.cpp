#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <memory>
#include <bitset>
#include <cassert>

using namespace std;
using ll = long long;
#define FOR(i,a,b) for(ll i=(a); i<(b); ++i)

int main() {
	ll T; cin >> T;
	FOR(t,0,T) {
		cout << "Case #" << t+1 << ":";
		ll N; cin >> N;
		vector<pair<ll,char>> ps(N);
		ll sum = 0;
		FOR(i,0,N) {
			cin >> ps[i].first;
			ps[i].second = 'A' + i;
			sum += ps[i].first;
		}
		while(sum) {
			cout << ' ';
			assert(sum != 1);
			sort(begin(ps),end(ps),greater<decltype(ps[0])>());
			assert(2*ps[0].first <= sum);
			if(ps[1].first*2 > sum-1) {
				cout << ps[0].second << ps[1].second;
				sum -= 2;
				ps[0].first--;
				ps[1].first--;
			} else {
				cout << ps[0].second;
				sum--;
				ps[0].first--;
			}
		}
		cout << endl;
	}
}
