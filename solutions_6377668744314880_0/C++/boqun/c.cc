#include <iostream>
#include <stdlib.h>

using namespace std;

int X[1000];
int Y[1000];
int c[1000];
int main()
{
	int T;
	cin >> T;
	for (int n = 1; n <= T; n++) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> X[i] >> Y[i];
		}

		for (int i = 0; i < N; i++) {
			int min_val = N;
			for (int j = 0; j < N; j++) {
				if (i != j) {
					int left = 0;
					int right = 0;
					int vx = X[j] - X[i];
					int vy = Y[j] - Y[i];
					for (int k = 0; k < N; k++) {
						if (k != i && k != j) {
							int dx = X[k] - X[i];
							int dy = Y[k] - Y[i];

							if (dx * vy - dy * vx > 0)
								left++;
							if (dx * vy - dy * vx < 0)
								right++;
/*
							if (dx * vy - dy * vx == 0 && (dx * vx < 0 || dy * vy < 0)) {
								cout << i << " " << j  << " " << k << endl;
								left++;
								right++;
							}
							*/
						}
					}
					min_val = min(min(left, right), min_val);
				}
			}
			c[i] = min_val;

		
		}
		cout << "Case #" << n << ":" << endl;
		for (int i = 0; i < N; i++)
			cout << c[i] << endl;
	}
	return 0;
}
