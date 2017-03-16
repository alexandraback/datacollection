#include <iostream>
#include <queue>
using namespace std;

inline int gcd(int a, int b) {
	int t;
	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t++ < T;) {
		int B, N, m[1001], lcm = 1, cyc = 0;
		cin >> B >> N;
		for (int i = 0; i < B; i++) {
			cin >> m[i];
			lcm = lcm / gcd(lcm, m[i]) * m[i];
		}
		for (int i = 0; i < B; i++) {
			cyc += lcm / m[i];
		}
		N %= cyc;
		if (!N) N = cyc;
		//cerr << "new: " << N << endl;

		// now simulate N...
		priority_queue<pair<int, int> > pq;
		for (int i = 0; i < B; i++) {
			pq.push(make_pair(0, -i));
		}

		while (N > 1) {
			pair<int, int> b = pq.top();
			pq.pop();
			N--;

			//cerr << "   Serve by " << -b.second + 1 << ", now " << N << " in line\n";

			b.first -= m[-b.second];
			pq.push(b);
		}

		// find lcm of barbers
		cout << "Case #" << t << ": " << -pq.top().second + 1 << endl;
	}
	return 0;
}