#include <iostream>
#include <boost/math/common_factor_rt.hpp>

using namespace std;

int M[1000];
int M2[1000];
int main()
{
	int T;
	cin >> T;
	for (int n = 1; n <= T; n++) {
		int B;
		long N;
		int bb = 0;
		cin >> B >> N;
		int lcm = 1;
		int group = 0;
		for (int i = 0; i < B; i++) {
			cin >> M[i];
			M2[i] = 0;
			lcm = boost::math::lcm(lcm, M[i]);
		}

		for (int j = 0; j < B; j++) {
			group += lcm / M[j];
		}

		N = N % group;
		if (N == 0)
			N = group;

		for (int i = 1 ; i <= N; i++) {
			int index = 0;
			int min_val = M2[0];
			for (int j = 0; j < B; j++) {
				if (min_val > M2[j]) {
					index = j;
					min_val = M2[j];
				}
			}

			for (int j = 0; j < B; j++) {
				M2[j] -= min_val;
			}

			M2[index] = M[index];

			bb = index + 1;
		}
		cout << "Case #" << n << ": "<< bb << endl;
	}
	return 0;
}
