#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int n;
		cin >> n;
		priority_queue<pair<int, char> > q;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int p;
			cin >> p;
			q.push(make_pair(p, i));
			sum += p;
		}

		cout << "Case #" << test << ":";
		if (n == 2) {
			for (int i = 0; i < sum / 2; ++i) {
				cout << " AB";
			}
		} else {
			while (sum > 2) {
				int p = q.top().first;
				int i = q.top().second;
				cout << " " << (char)('A' + i);
				q.pop();
				q.push(make_pair(p - 1, i));
				--sum;
			}
			int i1 = q.top().second;
			q.pop();
			int i2 = q.top().second;
			cout << " " << (char)('A' + i1) << (char)('A' + i2);
		}
		cout << endl;
	}
}
