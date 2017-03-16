#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 1000000009;
const int maxn = 1000000009;

int main() {
	int t; cin >> t;
	for (int a0 = 1; a0 <= t; ++a0) {
		int n, cnt = 0; cin >> n;
		vector<int> a(n);
		vector<string> s;
		for (int i = 0; i < n; ++i) {
			int tmp; cin >> tmp;
			cnt += tmp;
			a[i] = tmp;
		}

		while (cnt) {
			string t = "";
			for (int j = 0; j < 2; ++j) {
				
				int mx = 0, p = 0;
				for (int i = 0; i < n; ++i) {									
					if (a[i] > mx) {
						mx = a[i];
						p = i;
					}				
				}
				t += p + 'A';
				a[p]--;
				cnt--;		
				if (cnt == 2) break;
			}		
			s.push_back(t);
		}
		
		cout << "Case #" << a0 << ":";
		for (auto x : s) {
			cout << " " << x;
		}
		cout << endl;
	}

	return 0;
}