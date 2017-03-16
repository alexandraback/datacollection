#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

ull gcd(ull a, ull b) {
	return (b==0? a: gcd(b, a % b));
}
ull lcm(ull a, ull b) {
	return a / gcd(a, b) * b;
}

void solve_case(int casen) {
	ll n, b;
	ull g = 1, ans1 = 0;
	cin >> b >> n;
	vector<ll> barbs(b);
	for(int i=0;i<b;i++) {
		cin >> barbs[i];
		g = lcm(g, barbs[i]);
	}
	ll ones = 0;
	for(int i=0;i<b;i++) {
		ones += g / barbs[i];
	}
	ull m = n % ones;
	n = (m == 0? ones: m);
	if (n<=b) {
		ans1 = n;
	}
	else {
		priority_queue<pair<ll, int> > pq;
		for(int i=0;i<b;i++) {
			pq.push(make_pair(-barbs[i], -i));
		}
		n -= b;
		pair<ll, int> tmp;
		while(n) {
			tmp = pq.top();
			// cout << tmp.first << ' ' << tmp.second << endl;
			if (n==1) {ans1 = (-tmp.second) + 1; break;}
			pq.pop();
			tmp.first -= barbs[-tmp.second];
			pq.push(tmp);
			n--;
		}
	}
	cout << "Case #" << casen << ": " << ans1 << endl;
}

int main() {
	int cases;
	cin >> cases;
	for(int i=1;i<=cases;i++) solve_case(i);

	return 0;
}