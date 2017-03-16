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

const int N = 1005;

LL m[N];

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		LL b, n, mx = 0;
		cin >> b >> n;

		for (int j = 0; j < b; j++) {
			cin >> m[j];
			mx = max(mx, m[j]);
		}

		LL l = -1, r = mx * n, mid, sum = 0;
		while (l + 1 < r) {
			mid = (l + r) / 2;
			sum = 0;
			for (int j = 0; j < b; j++) {
				sum += mid / m[j] + 1;				
			}
     		if (sum < n) {
     			l = mid;
     		}
     		else {
     			r = mid;
     		}
		}

		//cerr << r << endl;
		
		sum = 0;
		for (int j = 0; j < b; j++) {
			sum += l / m[j] + 1;				
		}
		LL cnt = n - sum;     		

		for (int j = 0; j < b; j++) {
			if (r % m[j] == 0) {
				if (cnt == 1) {
					printf("Case #%d: %d\n", i + 1, j + 1);
					break;
				}
				else {
					cnt--;
				}
			}
		}
	}

	return 0;
}
