#include <iostream>
#include <vector>
#include <complex>
#include <cassert>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;
typedef long long int Z;

int B;
Z N;
vector<Z> M;

Z montax(Z time) {
	Z ret = 0;
	for(Z m : M) {
		ret += (time + m - 1) / m;
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(false);
	
	int tests;
	cin >> tests;
	for(int test = 0; test < tests; ++test) {
		cin >> B >> N;
		
		M.resize(B);
		for(int i = 0; i < B; ++i) {
			cin >> M[i];
		}
		
		Z a = 0;
		Z b = M[0] * N + 5;
		
		while(a != b) {
			Z m = (a + b + 1) / 2;
			
			if(montax(m) >= N) {
				b = m - 1;
			} else {
				a = m;
			}
		}
		
		assert(montax(a) < N && montax(a + 1) >= N);
		Z servd = montax(a);
		priority_queue<pair<Z, int>> Q;
		for(Z i = 0; i < B; ++i) {
			Q.emplace(-((a + M[i] - 1) / M[i]) * M[i], -i);
		}
		
		
		int res = -1;
		while(servd != N) {
			assert(!Q.empty());
			pair<Z, int> e = Q.top();
			Q.pop();
			res = -e.second;
			Q.emplace(e.first - M[res], e.second);
			++servd;
		}
		
		assert(res != -1);
		cout << "Case #" << test + 1 << ": " << res + 1 << "\n";
	}
	
	return 0;
}
