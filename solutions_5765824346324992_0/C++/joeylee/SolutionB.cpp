#include <iostream>
#include <fstream>
#include <assert.h>
#include <map>
using namespace std;

int main() {
	ifstream fin("E:\\B-small-attempt1.in");
	// ifstream fin("E:\\temp.txt");
	ofstream fout("E:\\B-small.out");
	__int64 T;
	fin >> T;
	for (__int64 i = 1; i <= T; i++) {
		__int64 B;
		__int64 N;
		__int64 Bwait[1001];
		fin >> B;
		fin >> N;
		for (__int64 j = 1; j <= B; j++) {
			fin >> Bwait[j];
		}
		if (B >= N) {
			fout << "Case #" << i << ": " << N << endl;
			continue;
		}
		double coefficient = 0.0;
		for (__int64 j = 1; j <= B; j++) {
			coefficient = coefficient + 1.0 / Bwait[j];
		}
		double approx_time = (double)(N - B) / coefficient;
		__int64 app_i = (__int64)approx_time;
		__int64 accurate_N = 0;
		for (__int64 j = 1; j <= B; j++) {
			accurate_N = accurate_N + app_i / Bwait[j] + 1;
		}
		if (accurate_N < N) {
			while (accurate_N < N) {
				app_i++;
				accurate_N = 0;
				for (__int64 j = 1; j <= B; j++) {
					accurate_N = accurate_N + app_i / Bwait[j] + 1;
				}
			}
			__int64 pre_bar = 0;
			for (__int64 k = 1; k <= B; k++) {
				pre_bar = pre_bar + (app_i - 1) / Bwait[k] + 1;
			}
			__int64 diff = N - pre_bar;
			__int64 match = 0;
			for (__int64 k = 1; k <= B; k++) {
				if (app_i % Bwait[k] == 0) {
					match++;
					if (match == diff) {
						fout << "Case #" << i << ": " << k << endl;
						break;
					}
				}
			}
		}
		else {
			if (accurate_N >= N) {
				while (accurate_N >= N) {
					app_i--;
					accurate_N = 0;
					for (__int64 j = 1; j <= B; j++) {
						accurate_N = accurate_N + app_i / Bwait[j] + 1;
					}
				}
				__int64 pre_bar = 0;
				for (__int64 k = 1; k <= B; k++) {
					pre_bar = pre_bar + app_i / Bwait[k] + 1;
				}
				__int64 diff = N - pre_bar;
				__int64 match = 0;
				for (__int64 k = 1; k <= B; k++) {
					if ((app_i + 1) % Bwait[k] == 0) {
						match++;
						if (match == diff) {
							fout << "Case #" << i << ": " << k << endl;
							break;
						}
					}
				}
			}
		}
	}
	return 0;
}
