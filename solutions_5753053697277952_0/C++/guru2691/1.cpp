#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tt = 1; tt <=  T; ++tt) {
		cout << "Case #" << tt << ": ";
		int N;
		cin >> N;
		vector<pair<int, char> > V(N);
		int tot = 0;
		for (int i = 0; i < N; i++) {
			cin >> V[i].first;
			V[i].second = char('A' + i);
			tot += V[i].first;
		}

		while (tot) {
			sort(V.begin(), V.end());
			if (V.size() == 2 and (V[N - 2].first == V[N - 1].first)) {
				cout << V[N - 2].second << V[N - 1].second << ' ';
				tot -= 2;
				V[N - 2].first -= 1;
				V[N - 1].first -= 1;	
			} else if (V.size() != 2 and (V[N - 2].first == V[N - 1].first)) {
				if (V[N - 1].first != 1) {
					cout << V[N - 2].second << V[N - 1].second << ' ';
					tot -= 2;
					V[N - 2].first -= 1;
					V[N - 1].first -= 1;
				} else {
					if (V[N - 3].first == V[N - 2].first) {
						cout << V[N - 1].second << ' ';
						V[N - 1].first -= 1;
						tot -= 1;
					} else {
						cout << V[N - 2].second << V[N - 1].second << ' ';
						tot -= 2;
						V[N - 2].first -= 1;
						V[N - 1].first -= 1;
					}
				}
			} else if (V[N - 2].first == V[N - 1].first) {
				cout << V[N - 2].second << V[N - 1].second << ' ';
				tot -= 2;
				V[N - 2].first -= 1;
				V[N - 1].first -= 1;
			} else {
				cout << V[N - 1].second << ' ';
				V[N - 1].first -= 1;
				tot -= 1;
			}
		}

		cout << '\n';
	}

	return 0;
}