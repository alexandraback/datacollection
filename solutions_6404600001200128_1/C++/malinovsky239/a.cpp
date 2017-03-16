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

int res1 = 0, res2 = 0, sec10[N];

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> sec10[j];
		}

		res1 = res2 = 0;

		for (int j = 1; j < n; j++) {
			if (sec10[j] < sec10[j - 1]) {
				res1 += sec10[j - 1] - sec10[j];				
			}
		}
		int pace = 0;
		for (int j = 1; j < n; j++) {
			if (sec10[j] < sec10[j - 1]) {
				pace = max(pace, (sec10[j - 1] - sec10[j]));
			}
		}
		
		int cur = sec10[0];
		for (int j = 1; j < n; j++) {
			res2 += min(pace, cur);
			cur = sec10[j];			
		}

		printf("Case #%d: %d %d\n", i + 1, res1, res2);
	}


	return 0;
}
