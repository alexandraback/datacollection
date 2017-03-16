#include <iostream>
#include <vector>
using namespace std;

long long solve1(vector <int> &a) {
	long long ans = 0;
	for (int i = 1; i < a.size(); i ++)
		if (a[i - 1] > a[i]) ans += (a[i - 1] - a[i]);
	return ans;
}

long long solve2(vector <int> &a) {
	int r = 0;
	long long ans = 0;
	for (int i = 1; i < a.size(); i ++)
		if (a[i - 1] - a[i] > r) r = a[i - 1] - a[i];
	for (int i = 1; i < a.size(); i ++)
		ans += min(a[i - 1], r);
	return ans;
}

int main() {
	int T, t, n;
	cin >> T;
	for (int i = 1; i <= T; i ++) {
		vector <int> a;
		cin >> n;
		while (n --) {
			cin >> t;
			a.push_back(t);
		}
		cout << "Case #" << i << ": " << solve1(a) << " " << solve2(a) << endl;
	}
	return 0;
}
