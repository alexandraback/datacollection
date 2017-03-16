#include <iostream>
#include <stdio.h>
#define TRACE(x...) 
#define PRINT(x...) TRACE(printf(x))
using namespace std;

int px[100], py[100];

int sign(int u1, int u2, int v1, int v2) {
	PRINT("sign(): %d %d %d %d\n", u1, u2, v1, v2);
	int s = (u1*v2 - u2*v1);
	if (s > 0) return +1;
	if (s < 0) return -1;
	return 0;
}

int main() {
	int T, _42=1;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> px[i] >> py[i];
		}
		if (N <= 3) {
			cout << "Case #" << _42++ << ":" << endl;
			for (int i = 0; i < N; i++) {
				cout << 0 << endl;
			}
		}
		else {
			cout << "Case #" << _42++ << ":" << endl;
			for (int k = 0; k < N; k++) {
				int ans = N;
				for (int i = 0; i < N; i++) if (i != k) {
					for (int j = 0; j < N; j++) if (i != j && j != k) {
						// (i - j) x (k - j)
						//int s = sign(px[i] - px[j], py[i] - py[j], px[k] - px[j], py[k] - py[j]);
						int s = sign(px[k] - px[j], py[k] - py[j], px[i] - px[j], py[i] - py[j]);
						if (k == 4) PRINT("k=4 sign:%d %d %d, %d %d, (%d, %d), (%d, %d)\n", s, i, j, px[k], py[k], px[j], py[j], px[i], py[i]);
						int count = 0;
						if (s == 0) {
							int count1 = 0;
							for (int l = 0; l < N; l++) if (l!=i && l!=j && l !=k){
								if (sign(px[l] - px[j], py[l] - py[j], px[i] - px[j], py[i] - py[j]) > 0) {
									count1++;
								}
							}
							int count2 = 0;
							for (int l = 0; l < N; l++) if (l!=i && l!=j && l !=k){
								if (sign(px[l] - px[j], py[l] - py[j], px[i] - px[j], py[i] - py[j]) < 0) {
									count2++;
								}
							}
							if (k == 4) PRINT("s=0:%d %d\n", count1, count2);
							count = min(count1, count2);
						}
						else if (s > 0) {
							for (int l = 0; l < N; l++) if (l!=i && l!=j && l !=k) {
								// (l - k) x (i - k)
								// (l - k) x (j - k)
								if ((sign(px[l] - px[k], py[l] - py[k], px[i] - px[k], py[i] - py[k]) > 0)
										|| (sign(px[l] - px[k], py[l] - py[k], px[j] - px[k], py[j] - py[k]) < 0)) {
									count++;
								}
							}
						}
						else {
							for (int l = 0; l < N; l++) if (l!=i && l!=j && l !=k){
								// (l - k) x (i - k) < 0
								// (l - k) x (j - k) > 0
								if ((sign(px[l] - px[k], py[l] - py[k], px[i] - px[k], py[i] - py[k]) < 0)
										|| (sign(px[l] - px[k], py[l] - py[k], px[j] - px[k], py[j] - py[k]) > 0)) {
									count++;
								}
							}
						}
						PRINT("count=%d\n", count);
						ans = min(ans, count);
					}
				}
				cout << ans << endl;
			}
		}
	}
	return 0;
}