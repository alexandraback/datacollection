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
int ch[20][20];
int dx[2] = { 1, 0};
int dy[2] = { 0, 1};

int func(void) {
	int ans = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			for (int k = 0; k < 2; k++) {
				int ni = i + dx[k];
				int nj = j + dy[k];

				if (ni >= 0 && ni < R && nj >= 0 && nj < C) {
					if (ch[i][j] && ch[ni][nj]) {
						ans += 1;
					}
				}
			}
		}
	}
	
	return ans;
}
int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> R >> C >> N;

		int L = R * C;
		int ans = 101010000;
		
		for (int x = 0; x < (1 << L); x++) {
			if (__builtin_popcount(x) == N) {
				memset(ch, 0, sizeof(ch));

				int c = 0;
				
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						if (x & (1 << c)) {
							ch[i][j] = 1;
						}
						c++;
					}
				}

				chmin(ans, func());
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
    return 0;
}
