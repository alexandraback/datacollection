#include <bits/stdc++.h>

using namespace std;

int r, c, n;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void read() {
	cin >> r >> c >> n;
}

bool in(int i, int j) {
	return 0 <= i && i < r && 0 <= j && j < c;
}

int kill(int one) {
	int half = (r * c + 1) / 2;
	if (n <= half)
		return 0;

	int ans = r * (c - 1) + (r - 1) * c;
	vector<int> a;

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			if ((i + j) % 2 == one) {
				int s = 0;
				for (int k = 0; k < 4; ++k)
					if (in(i + dx[k], j + dy[k]))
						++s;
				a.push_back(s);
			}

	
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for (int i = 0; i < r * c - n; ++i)
		ans -= a[i];
	return ans;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		read();
		cout << "Case #" << i << ": ";
		cout << min(kill(0), kill(1)) << endl;
		cerr << "case #" << i << " done.\n";
	}
	return 0;
}