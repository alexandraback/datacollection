#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <utility>
#include <functional>
#include <numeric>
#include <iostream>
using namespace std;

long long cut_number(long long time, const vector<int>& M) {
	long long sum = 0;
	for (int m : M) {
		sum += time / m + 1;
	}
	return sum;
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int T;
	in >> T;
	for (int test = 1; test <= T; test++) {
		long long B, N;
		in >> B >> N;
		vector<int> M(B);
		copy_n(istream_iterator<int>(in), B, M.begin());

		long long a = 0, b = 100000000000000LL;
		while (b - a > 1) {
			long long c = (a + b) / 2 - 1;
			if (cut_number(c,M) < N) {
				a = c + 1;
			}
			else {
				b = c + 1;
			}
		}

		int elottem = N - cut_number(a - 1, M) -1;
		for (int i = 0; i < B; i++) {
			if (a % M[i] == 0) {
				if (elottem > 0) {
					elottem--;
				}
				else {
					out << "Case #" << test << ": " << i + 1 << endl;
					break;
				}		
			}
		}
		
	}
	return 0;
}