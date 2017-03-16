#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int re = 1; re <= T; ++re) {
		int N;
		cin >> N;
		vector<pair<int, int> > p;
		int sum = 0;
		for (int i = 0; i < N; ++i) {
			int x;
			cin >> x;
			p.push_back(make_pair(x, i));
			sum += x;
		}

		cout << "Case #" << re << ":";

		while (sum > 0) {
			sort(p.rbegin(), p.rend());
			if (p[1].first * 2 > sum - 1) {
				cout << ' ' << char('A' + p[0].second) << char('A' + p[1].second);
				p[0].first--; p[1].first--; sum -= 2;
			} else {
				cout << ' ' << char('A' + p[0].second);
				p[0].first--; sum -= 1;				
			}
		}
		cout << endl;
	}
}