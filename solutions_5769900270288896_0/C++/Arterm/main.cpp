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

int fee(int mask) {
	vector<bool> row(c, false);
	vector<vector<bool>> field(r, row);

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) {
			int num = i + r * j;
			if ((mask >> num) & 1)
				field[i][j] = true;
		}

	int ans = 0;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			if (field[i][j])
				for (int k = 0; k < 4; ++k)
					if (in(i + dx[k], j + dy[k]) && field[i + dx[k]][j + dy[k]])
						++ans;
	return ans / 2;
}

int kill() {
	int ans = 4 * r * c;
	for (int mask = 0; mask < (1 << (r * c)); ++mask)
		if (__builtin_popcount(mask) == n)
			ans = min(ans, fee(mask));
	return ans;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		read();
		cout << "Case #" << i << ": ";
		cout << kill() << endl;
		cerr << "case #" << i << " done.\n";
	}
	return 0;
}