#include <iostream>
using namespace std;

int shrooms[1000];

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		int first = 0, rate = 0;
		for (int i = 0; i < N; i++) {
			cin >> shrooms[i];
			if (i > 0 && shrooms[i] < shrooms[i-1]) {
				first += shrooms[i-1]-shrooms[i];
				if (shrooms[i-1]-shrooms[i] > rate) rate = shrooms[i-1]-shrooms[i];
			}
		}

		int second = 0;
		for (int i = 0; i < N-1; i++) {
			second += min(shrooms[i], rate);
		}

		cout << "Case #" << t << ": " << first << ' ' << second << '\n';
	}

	return 0;
}
