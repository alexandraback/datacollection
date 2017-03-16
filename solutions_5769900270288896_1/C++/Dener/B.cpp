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

void solve1(int testnum)
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

void solve2(int testnum)
{
    cin >> r >> c >> n;

    int blackCount = 0;
    int whiteCount = 0;
    int count[2] = {0, 0};
    for (int i = 0; i < r; i++) {
	count[i % 2] += (c + 1) / 2;
	count[1 - i % 2] += c / 2;
    }

    int ans;
    if (n <= count[0] || n <= count[1]) {
	ans = 0;
    } else {
	int countBySos[2][5];
	memset(countBySos, 0, sizeof(countBySos));
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	int init = 0;
	for (int x = 0; x < r; x++) {
	    for (int y = 0; y < c; y++) {
		int sosCount = 0;
		for (int i = 0; i < 4; i++) {
		    int nx = x + dx[i];
		    int ny = y + dy[i];
		    sosCount += good(nx, ny) ? 1 : 0;
		}
		countBySos[(x + y) % 2][sosCount]++;
		init += sosCount;
	    }
	}
	ans = INT_MAX;

	for (int curColor = 0; curColor < 2; curColor++) {
	    int holes = r * c  - n;
	    int curAns = init / 2;

	    int toSub = min(holes, countBySos[curColor][4]);
	    holes -= toSub;
	    curAns -= 4 * toSub;

	    toSub = min(holes, countBySos[curColor][3]);
	    holes -= toSub;
	    curAns -= 3 * toSub;

	    toSub = min(holes,  countBySos[curColor][2]);
	    holes -= toSub;
	    curAns -= 2 * toSub;

	    toSub = min(holes, countBySos[curColor][1]);
	    holes -= toSub;
	    curAns -= 1 * toSub;

	    if (!holes) {
		ans = min(ans, curAns);
	    }
	}
    }

    cout << "Case #" << testnum + 1 << ": " << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
	solve2(q);
    }
}
