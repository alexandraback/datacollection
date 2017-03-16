#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int64_t Ncase;
	cin >> Ncase;
	ostringstream output;
	for (int64_t i1 = 1; i1 <= Ncase; ++i1){
		output << "Case #" << i1 << ": ";
		int N;
		cin >> N;
		vector<int> P;
		int m = 0;
		int sum = 0;
		int midx = -1;
		for (int i = 0; i < N; ++i) {
			int pi;
			cin >> pi;
			P.push_back(pi);
			if (pi > m) {
				m = pi;
				midx = i;
			}
			sum += pi;
		}
		// Couldn't work out the character arithmetic :|
		string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		int cur = 0;
		while(m < sum/2) {
			for (int i = 0; i < 2; ++i) {
				while (cur == midx || P[cur] == 0) {
					cur++;
				}
				output << alpha[cur];
				P[cur] -= 1;
			}
			output << ' ';
			sum -= 2;
		}
		if (sum % 2 == 1) {
			while (cur == midx || P[cur] == 0) {
				cur++;
			}
			output << alpha[cur] << ' ';
			P[cur] -= 1;
			sum -= 1;
		}
		while(sum > 0) {
			output << alpha[midx];
			while (cur == midx || P[cur] == 0) {
				cur++;
			}
			P[cur] -= 1;
			P[midx] -= 1;
			output << alpha[cur] << ' ';
			sum -= 2;
		}
		output << endl;
	}
	cout << output.str();
	return 0;
}
