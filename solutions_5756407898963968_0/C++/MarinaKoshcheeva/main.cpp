#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>

using namespace std;

const int n = 4;

void solve(int test_id) {
	cout << "Case #" << test_id << ": ";

	int first, second, x;
	bool used[20];

	cin >> first;
	memset(used, 0, sizeof(used));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			cin >> x;
			if (i == first) used[x] = true;
		}

	int res = -1;
	cin >> second;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			cin >> x;
			if (i == second && used[x]) {
				if (res != -1)
					res = 100;
				else
					res = x;
			}
		}
	if (res == 100)
		cout << "Bad magician!" << endl;
	else {
		if (res == -1)
			cout << "Volunteer cheated!" << endl;
		else
			cout << res << endl;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int test_id = 1; test_id <= t; ++test_id)
		solve(test_id);
	return 0;
}
