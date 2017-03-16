#include <bits/stdc++.h>

using namespace std;

const int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

int dp[25][25][25];
int m,n,p;

bool a[25][25];

int check(int st, int x, int y) {
    memset(a, false, sizeof(a));
    for (int i = 0; i < x; i++) {
	for (int j = 0; j < y; j++) {
	    if (st & (1 << ((y*i)+j))) a[i][j] = true;
	}
    }
    int cnt = 0;
    for (int i = 0; i < x; i++) {
	for (int j = 0; j < y; j++) {
	    if (!a[i][j]) continue;
	    for (int k = 0; k < 4; k++) {
		int tx = i + dir[k][0];
		int ty = j + dir[k][1];
		if (tx >= 0 && tx < x && ty >= 0 && ty < y && a[tx][ty]) cnt++;
	    }
	}
    }
    return cnt >> 1;
}

int f(int i, int j, int k) {
    int ans = 0x3f3f3f3f;
    for (int st = 0; st < (1<<(i*j)) ; st++) {
	int cnt = 0;
	while(st) {
	    if (st & 1) cnt++;
	    st >>= 1;
	}
	if (cnt != k) continue;
	ans = min(ans, check(st, i, j));
    }
    cout << "!" << endl;
    return ans;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int t;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= 16; i++) {
	for (int j = i; j<= 16; j++) {
	    if (i*j > 16) continue;
	    for (int k = 0; k <= i*j; k++) {
		dp[i][j][k] = f(i,j,k);
	    }
	    cout << j << endl;
	}
	cout << i << endl;
    }
    for (int cas = 1 ; cas <= t; cas++) {
	cin >> m >> n >> p;
	cout << "Case #" << cas << ": " << dp[min(m,n)][max(m,n)][p] << endl;
    }
    return 0;
}
