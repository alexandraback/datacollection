#include <bits/stdc++.h>

using namespace std;

int r, c, n;

inline int get(int m, int i)
{
    return (m >> i) & 1;
}

inline bool good(int x, int y)
{
    return x >= 0 && y >= 0 && x < r && y < c;
}

void solve(int testnum)
{
    cin >> r >> c >> n;

    int bestans = INT_MAX;
    int maxmask = 1 << (r * c);
    for (int mask = 0; mask < maxmask; mask++) {
	int bitCount = 0;
	int unhappiness = 0;

	for (int x = 0; x < r; x++) {
	    for (int y = 0; y < c; y++) {
		if (get(mask, x * c + y)) {
		    bitCount++;

		    int dx[] = {-1, 1, 0, 0};
		    int dy[] = {0, 0, -1, 1};
		    for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!good(nx, ny)) {
			    continue;
			}
			if (get(mask, nx * c + ny)) {
			    unhappiness++;
			}
		    }
		}
	    }
	}

	if (bitCount == n) {
	    bestans = min(bestans, unhappiness / 2);
	}
    }

    cout << "Case #" << testnum + 1 << ": " << bestans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
	solve(q);
    }
}
