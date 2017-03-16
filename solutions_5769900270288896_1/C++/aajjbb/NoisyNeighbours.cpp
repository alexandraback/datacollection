#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

int T, R, C, N;
int s[11111][11111];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dsx[2] = { 1, 0};
int dsy[2] = { 0, 1};

int func(void) {
	int ans = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			for (int k = 0; k < 2; k++) {
				int ni = i + dsx[k];
				int nj = j + dsy[k];

				if (ni >= 0 && ni < R && nj >= 0 && nj < C) {
					if (s[i][j] && s[ni][nj]) {
						ans += 1;
					}
				}
			}
		}
	}
	return ans;
}

int try1(int used) {
	int c = 0;
	
	memset(s, 0, sizeof(s));
	
	for (int i = 0; used > 0 && i < R; i++) {
		for (int j = 0; used > 0 && j < C; j++) {
			if (used > 0 && c % 2 == 0) {
				if (i == 0 or s[i - 1][j] == 0) {
					used -= 1;
					s[i][j] = 1;
				}
			}
			c++;
		}
	}
	
	for (int x = 0; x < used; x++) {
		int bi = -1, bj = -1;
		int bst = 10000000;
		c = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (!s[i][j]) {
					int ds = 0;

					for (int k = 0; k < 4; k++) {
						int di = i + dx[k];
						int dj = j + dy[k];

						if (di >= 0 && dj >= 0 && di < R && dj < C) {
							if (s[di][dj]) {
								ds += 1;
							}
						}
					}
					
					if (ds < bst) {
						bst = ds;
						bi = i;
						bj = j;
					}
				}
				c++;
			}
		}
		s[bi][bj] = 1;
	}
	return func();
}

int try2(int used) {
	int c = 0;
	
	memset(s, 0, sizeof(s));
	
	for (int i = 0; used > 0 && i < R; i++) {
		for (int j = 0; used > 0 && j < C; j++) {
			if (used > 0 && c % 2 == 1) {
				if (i == 0 or s[i - 1][j] == 0) {
					used -= 1;
					s[i][j] = 1;
				}
			}
			c++;
		}
	}
	
	for (int x = 0; x < used; x++) {
		int bi = -1, bj = -1;
		int bst = 10000000;
		c = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (!s[i][j]) {
					int ds = 0;
										
					for (int k = 0; k < 4; k++) {
						int di = i + dx[k];
						int dj = j + dy[k];

						if (di >= 0 && dj >= 0 && di < R && dj < C) {
							if (s[di][dj]) {
								ds += 1;
							}
						}
					}
					if (ds < bst) {
						bst = ds;
						bi = i;
						bj = j;
					}
				}
				c++;
			}
		}
		s[bi][bj] = 1;
	}
	
	return func();
}


int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> R >> C >> N;
		int ans = min(try1(N), try2(N));
		cout << "Case #" << t << ": " << ans << endl;
	}
    return 0;
}


