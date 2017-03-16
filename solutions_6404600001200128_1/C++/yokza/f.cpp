#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

void solve_case(int casen) {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++) {
		cin >> v[i];
	}
	ll ans1 = 0, ans2 = 0;
	int pr = v[0], mdiff=0;
	for(int i=1;i<n;i++) {
		if (pr > v[i]) {
			ans1 += (pr - v[i]);
			mdiff = max(mdiff, pr - v[i]);
		}
		pr = v[i];
	}
	for(int i=0;i<n-1;i++) {
		ans2 += min(mdiff, v[i]);
	}
	cout << "Case #" << casen << ": " << ans1 << ' ' << ans2 << endl;
}

int main() {
	int cases;
	cin >> cases;
	for(int i=1;i<=cases;i++) solve_case(i);

	return 0;
}