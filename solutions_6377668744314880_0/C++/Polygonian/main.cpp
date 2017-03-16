//
//  main.cpp
//  Jam
//
//  Created by friendlies on 4/17/15.
//  Copyright (c) 2015 Tagxedo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

using namespace std;

int X[4000];
int Y[4000];

int main(int argc, const char * argv[]) {
	if (argc == 2) {
		freopen(argv[1], "r", stdin);
	}
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> X[i];
			cin >> Y[i];
		}
		// cout << "--------------" << endl;
		cout << "Case #" << t << ":" << endl;
		// cout << "Case #" << t << ": (" << N << ")" << endl;
		for (int i = 0; i < N; i++) {
			// cout << "------------" << endl;
			// cout << "i = (" << X[i] << ", " << Y[i] << ")" << endl;
			int best = INT_MAX;
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				const long long dx = X[j] - X[i];
				const long long dy = Y[j] - Y[i];
				int plus = 0, minus = 0;
				for (int k = 0; k < N; k++) {
					if (k == j || k == i) continue;
					const long long ddx = X[j] - X[k];
					const long long ddy = Y[j] - Y[k];
					const long long cross = dx * ddy - dy * ddx;
					if (cross < 0) {
						minus++;
					} else if (cross > 0) {
						plus++;
					}	
				}
				// cout << "  j = (" << X[j] << ", " << Y[j] << ")" << endl;
				// cout << "     plus = " << plus << ", minus = " << minus << endl;
				if (best > minus) best = minus;
				if (best > plus) best = plus;
			}
			if (best == INT_MAX) {
				assert(N == 1);
				best = 0;
			}
			cout << best << endl;
		}
	}
    return 0;
}
