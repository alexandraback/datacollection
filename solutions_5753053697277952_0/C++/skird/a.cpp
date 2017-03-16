#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb emplace_back

using namespace std;

typedef long long ll;

void solve() {
	int n;
	set< pair<int, int>, greater< pair<int, int> > > heap;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		heap.emplace(x, i);
	}
	while (!heap.empty()) {
		if (heap.size() == 2 && heap.begin()->first == heap.rbegin()->first) {
			auto x = *heap.begin();
			auto y = *heap.rbegin();
			heap.erase(x);
			heap.erase(y);
			cout << " " << char(x.second + 'A') << char(y.second + 'A');
			x.first--, y.first--;
			heap.insert(x);
			heap.insert(y);
		} else {
			auto x = *heap.begin();
			heap.erase(x);
			cout << " " << char(x.second + 'A');
			x.first--;
			heap.insert(x);
		}
		while (heap.size() && heap.rbegin()->first == 0) {
			heap.erase(*heap.rbegin());
		}
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cout << "Case #" << i + 1 << ":";
		solve();
	}
  return 0;
}
