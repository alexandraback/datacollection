#include <cstdio>
#include <string>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int P[30];

void solve() {
	int n;
	scanf("%d", &n);
	vector<pair<int, char> > q;

	int tot = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &P[i]);
		tot += P[i];
		q.push_back(make_pair(P[i], static_cast<char>('A' + i)));
	}

	while (!q.empty()) {
		sort(q.begin(), q.end());
		
		if (q.size() < 2) {
			cerr << "SHOULD NEVER HAPPEN" << endl;
			return;
		}

		pair<int, char> &t1 = q.back();
		pair<int, char> &t2 = q[q.size() - 2];

		if (t1.first >= 2 && 2 * max(t2.first, t1.first - 2) <= tot - 2) {
			cout << " " << t1.second << t1.second;
			t1.first -= 2;
			tot -= 2;
			if (t1.first == 0)
				q.pop_back();
		} else if (q.size() == 2 || ((q.size() > 2) && 2 * max(max(q[q.size() - 3].first, t1.first-1), t2.first-1) <= tot - 2))  {
			cout << " " << t1.second << t2.second;
			t1.first--;
			t2.first--;
			tot -= 2;
			if (t1.first == 0)
				q.pop_back();
			if (t2.first == 0)
				q.pop_back();
		} else {
			cout << " " << t1.second;
			t1.first--;
			tot--;
			if (t1.first == 0)
				q.pop_back();
		}
	}
	cout << endl;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		printf("Case #%d:", tt);
		solve();
	}
	return 0;	
}
