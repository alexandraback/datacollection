#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 1000 + 10;
int A[MAXN];

int main () {
	int cases;
	cin >> cases;

	for (int tc = 1; tc <= cases; tc ++) {
		int N;
		cin >> N;
		int first = 0;
		int maxs = 0;
		for (int i = 0; i < N; i ++) {
			cin >> A[i];
			if (i > 0) {
				first += max(0, A[i - 1] - A[i]);
				if (A[i] < A[i - 1]) {
					int d = A[i - 1] - A[i];
					maxs = max(maxs, d);
				}
			}
		}
		int second = 0;
		for (int i = 0; i < N - 1; i ++) {
			second += min(maxs, A[i]);
		}

		cout << "Case #" << tc << ": " << first << " " << second << endl;
	}
}