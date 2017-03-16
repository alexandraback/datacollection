#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<LL, int> P;

LL m[10005];

LL gcd(const LL& a, const LL& b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

LL calclcm(const LL& a, const LL& b) {
	return (a * b / gcd(max(a, b), min(a, b)));
}

int main () {
	int t, b;
	LL n, lcm;

	cin >> t;
	for (int cs = 1; cs <= t; ++cs) {
		cin >> b >> n;
		for (int i = 0; i < b; ++i) {
			cin >> m[i];
			if (i == 0) {
				lcm = m[i];
			}
			else {
				lcm = calclcm(lcm, m[i]);
			}
		}

		
		LL mod = 0;
		for (int i = 0; i < b; ++i) {
			mod += (lcm / m[i]); 
		}
		n = n % mod;
		//cout << "n: " << n << " mod: " << mod << endl;
		
		if (n == 0)
			n += mod;
		
		priority_queue<P, vector<P>, greater<P> > q;
		for (int i = 0; i < b; ++i) {
			q.push(make_pair(0, i));
		}

		for (int i = 1; i < n; ++i) {
			P st = q.top();
			//cout << "b: " << st.first << " t: " << st.second << endl;
			q.pop();
			q.push(make_pair(st.first + m[st.second], st.second));
		}
		cout << "Case #" << cs << ": " << q.top().second+1 << endl;
	}


	return 0;
}