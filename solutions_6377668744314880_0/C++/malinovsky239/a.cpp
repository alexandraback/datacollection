#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

typedef long double LD;
typedef long long LL;

using namespace std;

#define sz(A) (int)(A).size()
#define mp make_pair
#define pb push_back

const int N = 3005;

int x[N], y[N];
vector<int> vals[N];

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;		

		printf("Case #%d:\n", i + 1);

		for (int j = 0; j < n; j++) {
			cin >> x[j] >> y[j];
		}

		if (n <= 2) {
			for (int j = 0; j < n; j++) {
				cout << 0 << endl;
			}
			continue;			
		}

		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
			    LL A = y[k] - y[j], B = x[j] - x[k];
			    LL C = -A * x[j] - B * y[j];

			    int cnt1 = 0, cnt2 = 0;
				for (int l = 0; l < n; l++) {
					if (A * x[l] + B * y[l] + C > 0) {
						cnt1++;
					}
					if (A * x[l] + B * y[l] + C < 0) {					
						cnt2++;
					}
				}

				if (cnt2 < cnt1) cnt1 = cnt2;
				
				vals[j].pb(cnt1);
				vals[k].pb(cnt1);
			}			
		}	

		for (int j = 0; j < n; j++) {
			sort(vals[j].begin(), vals[j].end());
			cout << vals[j][1] << endl;
			vals[j].clear();			
		}
	}

	return 0;
}
