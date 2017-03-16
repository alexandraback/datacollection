#include <iostream>
#include <string.h>
using namespace std;

bool wall[20][20];

int find(int r, int c) {
	int x, y, minn = 0x3f3f3f3f;
	for (int i = 1; i <= r; i ++)
		for (int j = 1; j <= c; j ++) 
			if (!wall[i][j]) {
				int sum = wall[i - 1][j] + wall[i + 1][j] + wall[i][j - 1] + wall[i][j + 1];
				if (sum < minn) minn = sum, x = i, y = j;
			}
	wall[x][y] = 1;
	return minn;
	for (int i = 1; i <= r; i ++) {
		for (int j = 1; j <= c; j ++)
			cout << wall[i][j];
		cout << endl;
	}
}


int greedy() {
	int r, c, n;
	cin >> r >> c >> n;
	if (r > c) swap(r, c);
	int cnt1 = 0, cnt2 = 0;
	memset(wall, 0, sizeof(wall));
	wall[1][1] = 1;
	for (int i = 1; i < n; i ++)
		cnt1 += find(r, c);	
	memset(wall, 0, sizeof(wall));
	wall[1][2] = 1;
	for (int i = 1; i < n; i ++)
		cnt2 += find(r, c);
	return min(cnt1, cnt2);
}

long long solve1(long long r, long long c, long long n) {
	long long conf[5];
	conf[0] = (r * c) / 2;
	conf[1] = 0;
	if ((r & c) % 2) conf[2] = 4;
	else conf[2] = 2;
	conf[4] = ((r - 2) * (c - 2) + 1) / 2;
	conf[3] = 0;
	for (int i = 1; i < r - 1; i ++) {
		if (i % 2 == 0) conf[3] ++;
		if ((i + c - 1) % 2 == 0) conf[3] ++;
	}
	for (int i = 1; i < c - 1; i ++) {
		if (i % 2 == 0) conf[3] ++;
		if ((i + r - 1) % 2 == 0) conf[3] ++;
	}
	if (conf[0] + conf[2] + conf[3] + conf[4] != r * c) cout << "!!" << endl;
	long long cnt = 0;
	for (int i = 0; i < 4; i ++) 
		if (i != 1) {
			if (n <= conf[i]) return i * n + cnt;
			n -= conf[i];
			cnt += conf[i] * i;
		}
	return cnt + 4 * n;
}
long long solve2(long long r, long long c, long long n) {
	long long conf[5];
	conf[0] = (r * c + 1) / 2;
	conf[1] = 0;
	if ((r & c) % 2) conf[2] = 0;
	else conf[2] = 2;
	conf[4] = ((r - 2) * (c - 2)) / 2;
	conf[3] = 0;
	for (int i = 1; i < r - 1; i ++) { 
		if (i % 2 == 1) conf[3] ++;
		if ((i + c - 1) % 2 == 1) conf[3] ++;
	}
	for (int i = 1; i < c - 1; i ++) {
		if (i % 2 == 1) conf[3] ++;
		if ((i + r - 1) % 2 == 1) conf[3] ++;
	}
	if (conf[0] + conf[2] + conf[3] + conf[4] != r * c) cout << "??" << endl;
	long long cnt = 0;
	for (int i = 0; i < 4; i ++) 
		if (i != 1) {
			if (n <= conf[i]) return i * n + cnt;
			n -= conf[i];
			cnt += conf[i] * i;
		}
	return cnt + 4 * n;
}

long long solve0(long long r, long long n) {
	n -= (r + 1) >> 1;
	if (n > 0) {
		if (r % 2) return n * 2;
		else return n * 2 - 1;
	}
	return 0;
}

long long solve() {
	long long r, c, n;
	cin >> r >> c >> n;
	if (c == 1) return solve0(r, n);
	if (r == 1) return solve0(c, n);
	return min(solve1(r, c, n), solve2(r, c, n));
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i ++)
		cout << "Case #" << i << ": " << solve() << endl;
	return 0;
}
