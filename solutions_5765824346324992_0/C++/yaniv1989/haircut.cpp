#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>



typedef long long int64;

#define MAXM 100001
#define MAXN (1000000001LL)

using namespace std;

vector<int> M;

pair<int64, int64> get_client(int64 T) {
	int64 min_x = 0, diff = 0;
	for (size_t i = 0; i < M.size(); ++i) {
		min_x += (T+M[i]-1)/M[i];
		if ((T%M[i]) == 0) {
			diff += 1;
		}
	}
	return make_pair(min_x, diff);
}

int main() {
	ios::sync_with_stdio(false);
	int t, T;
	cin >> T;
	for (t = 0; t < T; ++t) {
		int64 B, N;
		cin >> B >> N;		

		M.resize(B);

		for (int i = 0; i < B; ++i) {
			cin >> M[i];
		}

		int64 left = 0, right = MAXM*MAXN;
		int64 T = -1;
		while (left <= right) {
			int64 mid = (left+right)/2;
			pair<int64, int64> x = get_client(mid);
			if ((x.first < N) && (x.first+x.second >= N)) {
				T = mid;
				break;
			} else if ((x.first == N) && (x.second == 0)) {
				T = mid;
				break;
			} if (x.first < N) {
				left = mid+1;
			} else {
				right = mid-1;
			}			
		}

		assert(T != -1);

		pair<int64, int64> x = get_client(T);
		int min_pos = -1;
		if (x.second == 0) {
			int64 min_mod = MAXM;
			for (int i = 0; i < B; ++i) {
				int64 mod = T%M[i];
				if (mod <= min_mod) {
					min_mod = mod;
					min_pos = i;
				}
			}
		} else {
			int64 my_pos = N-x.first-1;
			for (int i = 0; i < B; ++i) {
				if (T%M[i] == 0) {
					if (my_pos == 0) {
						min_pos = i;
					}
					my_pos--;					
				}
			}
		}
				
		cout << "Case #" << (t+1) << ": " << (min_pos+1) << endl;
	}
	return 0;
}