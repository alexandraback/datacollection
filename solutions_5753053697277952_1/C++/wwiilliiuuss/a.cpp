#include <iostream>
#include <fstream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<char, int> ci;

bool comp(ci a, ci b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second > b.second;
}

int main() {
#ifdef _DEBUG
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n;
		cin >> n;
		ci c[27];
		memset(c, 0, 27 * sizeof(int));
		for (int i = 0; i < n; i++) {
			cin >> c[i].second;
			c[i].first = 'A' + i;
		}

		cout << "Case #" << t << ": ";

		sort(c, c + n, comp);
		while (c[0].second > c[1].second) {
			cout << c[0].first << ' ';
			c[0].second--;
		}

		for (int i = 2; i < n; i++) {
			while (c[i].second > 0) {
				cout << c[i].first << ' ';
				c[i].second--;
			}
		}

		while (c[0].second > 0) {
			cout << c[0].first << c[1].first << ' ';
			c[0].second--; 
			c[1].second--;
		}

		cout << endl;
	}
	return 0;
}