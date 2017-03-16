#include <iostream>
#include <fstream>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#include <thread>

using namespace std;


vector<long long> m[100];
long long b[100];
long long n[100];
long long ans[100];

void compute(long long l, long long r) {
	for (long long i = l; i <= r; i++) {

		long long r = 1000 * 1000 * 1000;
		r *= 1000 * 1000;
		long long l = 0;

		while (l < r) {
			long long med = (l + r) / 2;

			long long count = 0;
			long long first = -1;
			vector<long long> now;
			for (long long j = 0; j < b[i]; j++) {
				count += med / m[i][j];
				if (med % m[i][j] == 0) {
					now.push_back(j);
					if (first == -1)
						first = j;
				}
			}

			if (count + b[i] - now.size() < n[i] && count + b[i] >= n[i] && first != -1) {
				ans[i] = now[n[i] - (count + b[i] - now.size()) - 1] + 1;
				break;
			}
			else if (count + b[i] - now.size() < n[i]) {
				l = med + 1;
			}
			else {
				r = med;
			}
		}
	}
}

int main() {
	//ios_base::sync_with_stdio(false);

	ifstream cin("input.txt");
	

	long long tests;
	cin >> tests;
	for (long long test = 0; test < tests; test++) {
		cin >> b[test] >> n[test];
		m[test].resize(b[test]);
		for (long long i = 0; i < b[test]; i++)
			cin >> m[test][i];
	}

	long long numTh = 1;
	long long numPerTh = 100 / numTh;
	vector<thread> threads(numTh);
	for (long long i = 0; i < numTh; i++) {
		long long l = i * numPerTh;
		long long r = l + numPerTh - 1;
		if (i == numTh - 1)
			r = 99;

		threads[i] = thread(compute, l, r);
	}

	for (long long i = 0; i < numTh; i++) {
		threads[i].join();
	}

	ofstream cout("output.txt");
	for (long long test = 0; test < tests; test++) {
		cout << "Case #" << test + 1 << ": " << ans[test] << endl;
	}


	//system("pause");
	return 0;
}