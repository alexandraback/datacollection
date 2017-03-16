#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

pair <int, int> arr[20];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int r, c, n;
		int ans = 1e9;
		cin >> r >> c >> n;
		int m = (1 << (r * c));
		for (int mask = 0; mask < m; mask++) {
			int b = 0;
			for (int i = 0; i < r * c; i++)
				if (mask & (1 << i))
					b++;
			if (b != n)
				continue;
			memset(arr, 0, sizeof(arr));
			int cur = 0;
			for (int i = 0; i < r * c; i++)
				if (mask & (1 << i))
					arr[cur++] = make_pair(i / r, i % r);
			cur = 0;
			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++)
					if ((abs(arr[i].first - arr[j].first) == 1 && arr[i].second == arr[j].second) || (abs(arr[i].second - arr[j].second) == 1 && arr[i].first == arr[j].first))
						cur++;
			ans = min(ans, cur);
		}
		cout << "Case #" << t + 1 << ": " << ans << endl;
	}

	return 0;
}