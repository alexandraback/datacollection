#include <iostream>
using namespace std;

int M[1010];

int main() {
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		int B;
		long long N;
		cin >> B >> N;
		for (int i = 0; i < B; i++) {
			cin >> M[i];
		}
		long long left = 0, right = N * 100000LL;
		while (left < right) {
			long long mid = (left + right) >> 1;
			long long number = 0;
			for (int i = 0; i < B; i++) {
				number += mid / M[i] + 1;
			}
			if (number >= N) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		long long number = 0;
		for (int i = 0; i < B; i++) {
			number += left / M[i] + 1;
		}
		long long order = number - N + 1;
		for (int i = B - 1; i >= 0; i--) {
			if (left % M[i] == 0) {
				order--;
				if (order == 0) {
					number = i + 1;
					break;
				}
			}
		}
		cout << "Case #" << cas << ": " << number << endl;
	}
}