#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
using namespace std;

int t, n, b, lim;
map<int, bool> mm;

struct B {
	int idx;
	int m;
	int s;
	B(){};
	B(int a, int b, int c) {
		idx = a;
		m = b;
		s = c;
	};
} m[1024];
bool compare(const B &a, const B &b) {
	if (a.s != b.s) {
		return a.s < b.s;
	}
	return a.idx < b.idx;
}
vector<B> v;

int gcd(int a, int b) {
	if (a < b)
		return gcd(b, a);
	return b == 0? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	cin >> t;
	for (int C = 1; C <= t; C++) {
		printf("Case #%d: ", C);

		v.clear();

		cin >> b >> n;
		for (int i = 0; i < b; i++) {
			m[i].idx = i + 1;
			cin >> m[i].m;
		}

		int l = m[0].m, cnt;
		for (int i = 1; i < b; i++) {
			l = lcm(l, m[i].m);
		}

		cnt = 0;
		for (int i = 0; i < b; i++) {
			lim = l / m[i].m;
			cnt += lim;
			for (int j = 0; j < lim; j++) {
				v.push_back(B(m[i].idx, m[i].m, j * m[i].m));
			}
		}

		sort(v.begin(), v.end(), compare);
		n %= cnt;

		if (n == 0) {
			printf("%d\n", v[v.size()-1].idx);
		}
		else {
			printf("%d\n", v[n-1].idx);
		}
	}

	return 0;
}
