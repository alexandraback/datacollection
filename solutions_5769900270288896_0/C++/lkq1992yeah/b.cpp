#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int r, c, n;

int solve() {
	cin >> r >> c >> n;
	if (r > c) { int tmp = r; r = c; c = tmp; }
	int full = r * (c - 1) + (r - 1) * c;
	int space = r * c - n;
	int half = r * c / 2;
	if (r == 1) {
		if (c % 2 == 0) {		//even
			if (n <= half) return 0;
			else if (n <= half + 1) return 1;
			else return full - 2 * space;
		} else {				//odd
			if (n <= half + 1) return 0;
			else return full - 2 * space;
		}
	} else if (r == 2) {
		if (n <= half) return 0;
		else if (n <= half + 2) return 2 * (n - half);
		else return full - 3 * space;
	} else if (r == 3 && c == 3) {
		if (n <= 5) return 0;
		else if (n == 6) return 3;
		else if (n == 7) return 6;
		else if (n == 8) return 8;
		else if (n == 9) return 12;
	} else if (r == 3 && c == 4) {
		if (n <= 6) return 0;
		else if (n == 7) return 2;
		else if (n == 8) return 4;
		else if (n == 9) return 7;
		else if (n == 10) return 10;
		else if (n == 11) return 13;
		else if (n == 12) return 17;
	} else if (r == 3 && c == 5) {
		if (n <= 8) return 0;
		else if (n == 9) return 3;
		else if (n == 10) return 6;
		else if (n == 11) return 8;
		else if (n == 12) return 11;
		else if (n == 13) return 14;
		else if (n == 14) return 18;
		else if (n == 15) return 22;
	} else if (r == 4 && c == 4) {
		if (n <= 8) return 0;
		else if (n == 9) return 2;
		else if (n == 10) return 4;
		else if (n == 11) return 7;
		else if (n == 12) return 10;
		else if (n == 13) return 13;
		else if (n == 14) return 16;
		else if (n == 15) return 20;
		else if (n == 16) return 24;
	} else
		return 0;
}

int main() {
	int t, cas;
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++) {
		int ret = solve();
		printf("Case #%d: %d\n", cas, ret);
	}
	return 0;
}