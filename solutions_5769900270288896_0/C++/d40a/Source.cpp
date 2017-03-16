#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cmath>

using namespace std;
#define LL long long
#define FILES freopen("input.txt" ,"r", stdin); freopen("output.txt", "w", stdout);
#define FASTER ios::sync_with_stdio(0);
#define fr(i, a, b) for(int i = (a); i < (b); ++i)
#define ffr(i, b) fr(i, 0, b)
using namespace std;

LL rev(LL n) {
	LL res = 0;
	while (n > 0) {
		res = res * 10 + n % 10;
		n /= 10;
	}
	return res;
}

bool sameL(LL a, LL b) {
	while (a > 0) {
		if (b == 0) return false;
		a /= 10;
		b /= 10;
	}
	return true;
}

LL dp[12345678];

int bcnt(int x) {
	int res = 0;
	while (x > 0) {
		if (x % 2 == 1) res++;
		x >>= 1;
	}
	return res;
}

int a[25][25];
int b[25][25];

int r, c, n;

int f(int x) {
	memset(b, 0, sizeof(b));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (x & (1 << (a[i][j] - 1)))
				b[i][j] = 1;
		}
	}
	int res = 0;
	for (int i = 0; i < r ; i++) {
		for (int j = 0; j < c ; j++) {
			if (b[i][j] == 1)
			res += ((i + 1 < r) ? b[i + 1][j] : 0) + ((j + 1 < c) ? b[i][j + 1] :  0);
		}
	}

	return res;
}
int main() {
	FILES;
	FASTER;
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		
		cin >> r >> c >> n;
		int k = r * c;
		int g = 1;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				a[i][j] = g++;
			
			}
		}
		int ans = 0;
		if (n != 0) {
			ans = 1234567;
			for (int i = 1; i < (1 << k); i++) {
				if (bcnt(i) == n) {
					ans = min(ans, f(i));
				}
			}
		}

		cout << "Case #" << t << ": " << ans << endl;	
	}
} 
