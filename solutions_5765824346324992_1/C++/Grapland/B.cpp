// B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdint>
#include <numeric>

using namespace std;
typedef uint64_t u64;

int main(){
	int T;
	cin >> T;
	for (int tt = 0; tt < T; tt++){
		int N, B;
		cin >> B >> N;
		vector<u64> ipt(B);
		uint64_t low = 0, high = 0;
		for (int i = 0; i < B; i++){
			cin >> ipt[i];
			high = max(high, ipt[i]);
		}
		high *= N;

		u64 mid, proc;
		while (low < high){
			mid = (low + high) / 2;
			proc = 0;
			for (int i = 0; i < B; i++){
				proc += (mid / ipt[i]);
				if (mid%ipt[i] != 0)
					proc++;
			}
			if (mid == low)break;
			if (proc>=N)high = mid;
			else if (proc < N) low = mid;
		}
		for (int i = 0; i < B; i++){
			if (mid%ipt[i] == 0){
				proc++;
				if (proc == N){
					cout << "Case #" << tt + 1 << ": " << i + 1 << endl;
					break;
				}
			}
		}
	}
	return 0;
}