#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

typedef pair<long long, int> P;


int solve(const vector<int> &m, const int n) {
	int b = m.size();
	long long now = 0; // now - 1 の時点での処理人数を計算
	long long tmp;

	long long customer, customer2 = 0;
	for (int i = 50; i >= 0; i--) {
		tmp = now | (1LL << i);

		customer = 0;
		for (int j = 0; j < b; j++) {
			customer += ceil(1.0 * tmp / m[j]);
		}
// printf("%d %lld %lld %lld %d\n", i, 1LL << i, tmp, customer, n);

		if (customer < n) {
// printf("%d ONNNN\n", i);
			now = tmp;
			customer2 = customer;
		}
	}

	customer = customer2;
// printf("%lld %lld\n", now, customer);
	now--;
	priority_queue<P, vector<P>, greater<P> > que;
	for (int i = 0; i < b; i++) {
		long long next = (now / m[i] + 1) * m[i];
		que.push(make_pair(next , i));
	}

	int idx;
	P barber;
	while (customer != n) {
		barber = que.top();
		que.pop();
		customer++;

		idx = barber.second;
		que.push(make_pair(barber.first + m[idx], idx));
	}

	// 問題は1-base
	return barber.second + 1;
}

int main() {
	int t, n, b;

	cin >> t;
	vector<int> ans(t, 0), m;

	for (int i = 0; i < t; i++) {
		cin >> b >> n;

		m.assign(b, 0);
		for (int j = 0; j < b; j++) {
			cin >> m[j];
		}

// printf("go %2d %d\n", i, n);
		ans[i] = solve(m, n);
	}

	for (int i = 0; i < t; i++) {
		printf("Case #%d: %d\n", i + 1, ans[i]);
	}
	return 0;
}
