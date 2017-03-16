#include <iostream>
#include <vector>

using namespace std;
typedef long long int Z;

int main() {
	cin.sync_with_stdio(false);
	
	int tests;
	cin >> tests;
	for(int test = 0; test < tests; ++test) {
		int n;
		cin >> n;
		
		vector<Z> m(n);
		for(int i = 0; i < n; ++i) {
			cin >> m[i];
		}
		
		Z ret1 = 0;
		Z maxdiff = 0;
		for(int i = 1; i < n; ++i) {
			Z diff = m[i - 1] - m[i];
			ret1 += max(diff, 0LL);
			maxdiff = max(maxdiff, diff);
		}
		
		Z ret2 = 0;
		for(int i = 0; i < n - 1; ++i) {
			ret2 += min(m[i], maxdiff);
		}
		
		cout << "Case #" << test + 1 << ": " << ret1 << ' ' << ret2 << '\n';
	}
	
	return 0;
}
