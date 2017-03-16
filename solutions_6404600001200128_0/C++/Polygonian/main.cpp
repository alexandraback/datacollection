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

int A[10001];

int main(int argc, const char * argv[]) {
	if (argc == 2) {
		freopen(argv[1], "r", stdin);
	}
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> A[i];

		int totalDecrease = 0;
		int maxDecrease = 0;
		for (int i = 1; i < N; i++) {
			int decrease = A[i - 1] - A[i];
			if (decrease < 0) continue;
			totalDecrease += decrease;
			if (maxDecrease < decrease)
				maxDecrease = decrease;
		}
		int B = 0;
		for (int i = 0; i < N - 1; i++) {
			B += min(maxDecrease, A[i]);
		}
		int A = totalDecrease;
		
		cout << "Case #" << t << ": " << A << " " << B << endl;
	}
    return 0;
}
