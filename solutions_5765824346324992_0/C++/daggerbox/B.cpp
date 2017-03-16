

#if 1

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;
typedef int64_t int64;

typedef pair<int,int> pii;
typedef pair<double,double> pdd;
#define mp make_pair
#define X first
#define Y second

static void solve();

int main() {
	freopen("B.in.txt","r",stdin);
	freopen("B.out.txt","w",stdout);
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; ++t) {
		cout << "Case #" << t << ": ";
		solve();
		cout << '\n';
	}
	return 0;
}

static int64 gcd(int64 a, int64 b) {
	if (a < 0 || b < 0)
		return -1;
	while (b != 0) {
		int64 x = a % b;
		a = b;
		b = x;
	}
	return a;
}

static int64 lcm(int64 a, int64 b) {
	if (a < 0 || b < 0)
		return -1;  // bad input
	if (a == 0 || b == 0)
		return 0;
	int64 k = a / gcd(a, b) * b;
	if (k < 0 || a < 0 || b < 0 || k % a != 0 || k % b != 0)
		k = -1;  // overflow
	return k;
}


static void solve() {
	int b, n;
	cin >> b >> n;
	deque<int> m;
	generate_n(back_inserter(m), b, []() { int pi; cin >> pi; return pi; });
	
	int64 sync = 1;
	for (int i = 0; i < b; i++) {
		sync = lcm(sync, m[i]);
	}
	int64 cycle = 0;
	for (int i = 0; i < b; i++) {
		cycle += sync / m[i];
	}
	
	if (cycle < n) {
		n = n % cycle;
		if (n == 0)
			n = int(cycle);
	}

	priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
	for (int i = 0; i < b; i++) {
		pq.push(mp(0, i));
	}
	
	for (int i = 1; i < n; i++) {
		pii a = pq.top();
		pq.pop();
		a.X += m[a.Y];
		//cout << endl << a.Y << " @ " << a.X << "; ";
		pq.push(a);
	}
	
	cout << (pq.top().Y + 1);
}

#endif

