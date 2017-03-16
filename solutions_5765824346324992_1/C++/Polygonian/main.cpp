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

long long M[10001];

class compare {
public:
	bool operator() (const pair<long, long> &a, const pair<long, long> &b) {
		if (a.first != b.first) {
			return a.first < b.first;
		} else if (a.second != b.second) {
			return a.second < b.second;
		} else {
			return false;
		}
	}

};

int main(int argc, const char * argv[]) {
	if (argc == 2) {
		freopen(argv[1], "r", stdin);
	}
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		long long B, N;
		cin >> B;
		cin >> N;
		for (int i = 0; i < B; i++)
			cin >> M[i];

		long long tLB = -1;
		long long tUB = 100000 * (N + 1);
		long long answer = -1;
		while (true) {
			long long t = (tLB + tUB) / 2;
			long long completedOrServing = 0;
			for (long long i = 0; i < B; i++) {
				completedOrServing += t / M[i] + 1;
			}
			if (completedOrServing < N) {  // not enough;
				tLB = t;
			} else {
				tUB = t;
			}
			if (tLB == tUB) {
				answer = tUB;
				break;
			} else if (tLB == tUB - 1) {
				answer = tUB;
				break;
			}
		}
		long long completed = 0;
		for (long long i = 0; i < B; i++) {
			completed += answer / M[i];
		}
		vector<pair<long, long> > sortable;
		for (long long i = 0; i < B; i++) {
			long long x = answer % M[i];
			sortable.push_back(make_pair(-x, i));
		}
		compare c;
		sort(sortable.begin(), sortable.end(), c);
//		for (int i = 0; i < B; i++)
//			cout << "SORT: " << sortable[i].first << ", " << sortable[i].second << endl;
		
		long long ready = completed;
		long long realAnswer = -1;
		for (long long i = 0; i < B; i++) {
			long long j = sortable[i].second;
			ready++;  // if ((answer % M[j]) == 0) ready++;
			if (ready == N) {
				assert((answer % M[j]) == 0);
				realAnswer = j + 1;
				break;
			}
		}
		// cout << "Case #" << t << " time = " << answer << ", completed = "
		 // << completed << ", N = " << N << endl;
		cout << "Case #" << t << ": " << realAnswer << endl;
	}
    return 0;
}
