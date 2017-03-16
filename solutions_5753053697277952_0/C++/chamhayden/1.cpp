#include <iostream>
#include <cstdio>

#define FOR(i,s,n) for(int i = s; i < n; ++i)

#define ALPHABET 26

using namespace std;

int items[ALPHABET];

char num(int i) {
	return i + 'A';
}

void runOutput(int N, int sum) {
	while (sum > 0) {
		//cout << "Sum: " << sum << endl;
		int mx = -1;
		FOR(i,0,N) {
			mx = max(mx, items[i]);
		}
		//cout << "Max: " << mx << endl;
		int max1 = -1;
		int max2 = -1;
		FOR(i,0,N) {
			if (items[i] == mx) {
				if (max1 == -1) {
					max1 = i;
				} else if (max2 == -1) {
					max2 = i;
				}
			}
		}
		if (max1 != -1 && max2 != -1) {
			if (sum == 3) {
				cout << num(max1) << " ";
				items[max1]--;
				sum--;
			} else {
				cout << num(max1) << num(max2) << " ";
				items[max1]--;
				items[max2]--;
				sum -= 2;
			}
		} else if (max1 != -1) {
			if (items[max1] == 1) {
				cout << num(max1) << " ";
				items[max1]--;
				sum--;
			} else {
				cout << num(max1) << num(max1) << " ";
				items[max1] -= 2;
				sum -= 2;
			}
		}
		FOR(i,0,N) {
			//cout << "items[" << i << "] = " << items[i] << " ";
		}
		//cout << endl;
	}
}

int main() {
	int T, N;
	scanf("%d\n", &T);
	FOR(i,0,T) {
		scanf("%d\n", &N);
		int sum = 0;
		FOR(j,0,N) {
			int item;
			scanf("%d", &item);
			items[j] = item;
			sum += item;
		}
		cout << "Case #" << (i + 1) << ": ";
		runOutput(N, sum);
		cout << endl;
	}
	return 0;
}