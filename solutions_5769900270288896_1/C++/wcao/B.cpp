#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int T, N, R, C;

int calc(int N, int a, int b, int c) {
	if (N <= a) {
		return 0;
	}	else if (N <= a + b) {
		return (N - a) * 2;
	}	else if (N <= a + b + c) {
		return b * 2 + (N - a - b) * 3;
	}	else {
		return b * 2 + c * 3 + (N - a - b - c) * 4;
	}
}

int main() {
	cin >> T;
	for(int t = 1 ; t <= T ; t++) {
		cin >> R >> C >> N;
		int ans = 0;
		if (R > C) {
			swap(R, C);
		}
		if (R == 1) {
			if ((C % 2) == 0) {
				if (N > (C / 2)) {
					ans = 2 * N - C - 1;
				}
			}	else {
				if (N > (C + 1) / 2) {
					ans = N * 2 - C - 1;
				}
			}
		}	else if (((R * C) % 2) == 0) {
			ans = calc(N, R * C / 2, 2, R + C - 4);
		}	else {
			ans = min(calc(N, (R * C + 1) / 2, 0, R + C - 2), calc(N, (R * C - 1) / 2, 4, R + C - 6));
		}
		printf("Case #%d: %d\n", t, ans);
	}	
	return 0;
}
