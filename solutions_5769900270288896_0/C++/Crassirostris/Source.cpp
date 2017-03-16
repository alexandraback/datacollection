#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <bitset>


using namespace std;

int solve() {
	int r, c, n;
	cin >> r >> c >> n;
	int min_value = 1000;
	for (int mask = 0; mask <= 1 << (r * c); ++mask) {
		bitset<16> bs(mask);
		int count = 0;
		for (int i = 0; i < r * c; ++i)
			count += bs[i];
		if (count != n)
			continue;
		int uh = 0;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j) {
				uh += bs[i * c + j] * (
					(i == 0 ? 0 : bs[(i - 1) * c + j])
					+ (j == 0 ? 0 : bs[i * c + j - 1]));
			}
		if (uh < min_value)
			min_value = uh;
	}
	return min_value;
}

int main()
{
	FILE *file;
	freopen_s(&file, "in.txt", "rt", stdin);
	freopen_s(&file, "out.txt", "wt", stdout);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		int ans = solve();
		cout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}