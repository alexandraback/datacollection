#include <iostream>
using namespace std;

long long cuttime[1000];

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int B;
		long long N;
		cin >> B >> N;
		
		for (int i = 0; i < B; i++) {
			cin >> cuttime[i];
		}

		long long min = 0, max = 1000000000000000LL;
		while (min < max) {
			long long pivot = (min+max)/2;
			long long started = 0;
			for (int i = 0; i < B; i++) {
				started += 1+pivot/cuttime[i];
			}
			if (started < N) min = pivot+1;
			else max = pivot;
		}
		int done = 0;
		for (int i = 0; i < B; i++) {
			done += (min+cuttime[i]-1)/cuttime[i];
		}
		for (int i = 0; i < B; i++) {
			if (min%cuttime[i] == 0) {
				done++;
				if (done == N) cout << "Case #" << t << ": " << i+1 << '\n';
			}
		}
	}

	return 0;
}
