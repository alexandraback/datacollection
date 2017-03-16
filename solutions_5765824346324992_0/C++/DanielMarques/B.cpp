#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

long long m[100010];
int B, N;

int main() {
	int T, _42=1;
	cin >> T;
	while (T--) {
		cin >> B >> N;
		long long g = 0;
		for (int i = 0; i < B; i++) {
			cin >> m[i];
			g = max(g, m[i]);
		}
		int ans = -1;
		long long begin = 0;
		long long end = g * N;
		while (begin <= end) {
			
			long long t = begin + (end - begin)/2;
			//cout << t << " " << begin << " " << end << endl;
			long long tot = 0;
			long long totSame = 0;
			for (int i = 0; i < B; i++) {
				tot += t/m[i] + 1;
				if (t%m[i] == 0) totSame++;
			}
			//cout << "a" << tot << " " << totSame << endl;
			if (N > tot - totSame && N <= tot) {
				//cout << "1" << endl;
				int count = 0;
				for (int i = 0; i < B; i++) {
					if (t % m[i] == 0) count++;
					if (count == N - (tot - totSame)) {
						ans = i;
						break;
					}
				}
				break;
			}
			else if (N > tot) {
				//cout << "2" << endl;
				begin = t + 1;
			}
			else {
				//cout << "3" << endl;
				end = t - 1;
			}
		}
		cout << "Case #" << _42++ << ": " << ans+1 << endl;
	}
	return 0;
}
