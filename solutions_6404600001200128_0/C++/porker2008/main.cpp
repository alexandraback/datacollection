#include <iostream>
using namespace std;

int mushrooms[1010];

int main() {
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		int N;
		cin >> N;
		long long res1 = 0, res2 = 0;
		int last = 0;
		int leasteat = 0;
		for (int i = 0; i < N; i++) {
			cin >> mushrooms[i];
			int temp = mushrooms[i];
			if (temp < last) {
				res1 += last - temp;
			}
			last = temp;
			if (i && mushrooms[i - 1] - mushrooms[i] > leasteat) {
				leasteat = mushrooms[i - 1] - mushrooms[i];
			}
		}
		for (int i = 1; i < N; i++) {
			if (mushrooms[i] == 0) res2 += mushrooms[i - 1];
			else if (mushrooms[i - 1] < leasteat) res2 += mushrooms[i - 1];
			else res2 += leasteat;
		}
		cout << "Case #" << cas << ": " << res1 << " " << res2 << endl;
	}
}
