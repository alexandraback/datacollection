#include <iostream>
#include <algorithm>

using namespace std;

bool mp[16][16];
bool used[16][16];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void buildMap(int r, int c, int bitNum) {	
	memset(mp, 0, sizeof (used));
	int pos = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (bitNum%2 == 1) mp[i][j] = true;
			else mp[i][j] = false;
			pos++;
			bitNum/= 2;
		}
	}
}

int dfs(int r, int c, int rPos, int cPos) {
	if (mp[rPos][cPos] == false || used[rPos][cPos] == true) return 0;
	used[rPos][cPos] = true;
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int rp = rPos+dir[i][0];
		int cp = cPos+dir[i][1];
		if (rp < 0 || rp >= c || cp < 0 || cp >= c) continue;
		if (mp[rp][cp] == false) continue;
		cnt++;
		cnt += dfs(r, c, rp, cp);
	}
	return cnt;
}

int countBits(int bitNum) {
	int cnt = 0;
	for (int i = bitNum; i; i/= 2) {
		if (i%2) cnt++;
	}
	return cnt;
}

int main() {
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-small-attempt2.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		int r, c, n;
		scanf("%d%d%d", &r, &c, &n);
		if (r > c) swap(r, c);
		int hfL = (r*c+1)/2;
		if (n <= hfL) {
			printf("Case #%d: 0\n", cas);
			continue;
		}
		memset(mp, 0, sizeof (mp));
		int minn = 0x3fffffff;
		int sum = r*c;
		for (int bitNum = 0; bitNum < (1<<sum); bitNum++) {
			buildMap(r, c, bitNum);
			int cnt = countBits(bitNum);
			if (cnt != n) continue;
			memset(used, 0, sizeof(used));
			int res = 0;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					res += dfs(r, c, i, j);
				}
			}
			minn = min(res/2, minn);
		}
		printf("Case #%d: %d\n", cas, minn);
	}
	return 0;
}