#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	int t;
	int N;
	int total;
	int max;
	int party[26];

	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	cin >> T;
	for (t = 1; t <= T; ++t) {
		cin >> N;
		max = total = 0;

		for (int i = 0; i < N; ++i) {
			cin >> party[i];
			total += party[i];
			if (max < party[i])
				max = party[i];
		}

		cout << "Case #" << t << ": ";

		while (total) {
			for (int i = 0; i < N; ++i) {
				if (party[i] >= max) {
					cout << (char)(i + 'A');
					party[i]--;
					total--;
					break;
				}
			}
			for (int i = 0; i < N; ++i) {
				if (party[i] > total / 2) {
					cout << (char)(i + 'A');
					party[i]--;
					total--;
					break;
				}
			}
			// update max
			max = party[0];
			for (int i = 0; i < N; ++i) {
				if (max < party[i])
					max = party[i];
			}
			cout << ' ';
		}
		cout << endl;
	}
	return 0;
}