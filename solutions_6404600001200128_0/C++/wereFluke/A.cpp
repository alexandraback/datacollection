#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;

const int MaxN = 1000;

int test_case, n, m[MaxN], ans1, ans2, v;

int main() {
	cin >> test_case;
	//cout << test_case << endl;
	for(int cur_case = 1; cur_case <= test_case; ++cur_case) {
		//cout << n << endl;
		cin >> n;
		v = ans1 = ans2 = 0;
		for (int i = 0; i < n; ++i) {
			cin >> m[i];
			if (i) ans1 += max(0, m[i - 1] - m[i]);
			if (i) v = max(v, m[i - 1] - m[i]);
			//if (i) cout << m[i - 1] - m[i] << endl;
		}
		//cout << v << endl;
		for (int i = 0; i < n - 1; ++i) {
			ans2 += min(v, m[i]);
			//cout << i << " " << min(v, m[i]) << endl;
		}
		cout << "Case #" << cur_case << ": " << ans1 << " " << ans2 << endl;
	}
	return 0;
}
