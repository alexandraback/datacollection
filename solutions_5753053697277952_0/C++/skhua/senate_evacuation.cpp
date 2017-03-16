#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int N, cnt;
int P[26];

void output_max(void) {
	int max = -1, second = -1;
    for (int i = 0; i < N; i++) {
		if (max == -1 || P[i] >= P[max]) {
			if (second == -1 || P[max] >= P[second])
				second = max;
			max = i;
	    } else if (second == -1 || P[i] >= P[second]) {
			second = i;
		}
	}
	P[max]--;
	cnt--;
	if (second != -1 && P[second] * 2 > cnt) {
		P[second]--;
		cnt--;
		cout << ' ';
		cout << (char)('A' + max);
		cout << (char)('A' + second);
	} else {
		cout << ' ';
		cout << (char)('A' + max);
	}
}

void run_case(int tc) {
    cin >> N;
	cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		cnt += P[i];
	}
	
	cout << "Case #" << tc << ":";
	while (cnt > 0) {
		output_max();
	}
	cout << endl;
}

int main() {
	int num = 0;
	cin >> num;
	for (int i = 1; i <= num; ++i) {
		run_case(i);
	}
	return 0;
}