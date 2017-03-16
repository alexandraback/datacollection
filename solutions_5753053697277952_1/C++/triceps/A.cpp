#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <numeric>

typedef long long ll;

using namespace std;

bool check0(vector<int>& P)
{
	auto S = accumulate(P.begin(), P.end(), 0);
	for (auto p : P) {
		if (1.0*p / S > 0.5) {
			return false;
		}
	}
	return true;
}

bool check(vector<int>& P)
{
	auto S = accumulate(P.begin(), P.end(), 0);
	for (auto p : P) {
		if (1.0*p / S > 0.5) {
			cerr << "NG" << endl;
			return false;
		}
	}
	return true;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		vector<int> P(N);
		int S = 0;
		for (int i = 0; i < N; i++) {
			cin >> P[i];
			S += P[i];
		}

		cout << "Case #" << t + 1 << ": ";
		for (int i = 0; i < S; i++) {
			auto m = max_element(P.begin(), P.end()) - P.begin();
			auto m2 = N - (max_element(P.rbegin(), P.rend()) - P.rbegin()) - 1;
			P[m]--;
			if (check0(P)) {
				cout << char('A' + m) << " ";
			}
			else if (m != m2) {
				cout << char('A' + m) << char('A' + m2) << " ";
				P[m2]--;
				i++;
			}
			else {
				int x = 0;
			}
			check(P);
		}

		cout << endl;
	}

	return 0;
}
