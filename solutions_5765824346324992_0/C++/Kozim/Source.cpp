//#pragma comment(linker, "/STACK:10000000")

#pragma once
#pragma warning(disable:4996)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
	return a / gcd(a,b) * b;
}

int b;
int n;
vector<int> v(10);

int getamt(int g) {
	int ret = 0;
	for (int t = 0; t < g; ++t) {
		for (int i = 0; i < b; ++i) {
			if (t % v[i] == 0) {
				++ret;
			}
		}
	}
	return ret;
}

int solve(int g, int pos) {
	for (int t = 0; t < g; ++t) {
		for (int i = 0; i < b; ++i) {
			if (t % v[i] == 0) {
				--pos;
				if (pos == 0) {
					return i + 1;
				}
			}
		}
	}
	return -1; //!!
}

int solve() {
	int g = v[0];
	for (int i = 1; i < b; ++i) {
		g = lcm(g, v[i]);
	}
	int amt = getamt(g);
	if (n % amt == 0){ 
		return solve(g, amt);
	} else {
		return solve(g, n % amt);
	}
}

int main () {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int test;
	cin >> test;
	for (int t = 1; t <= test; ++t) {
		cin >> b >> n;
		for (int i = 0; i < b; ++i) {
			cin >> v[i];
		}
		int ans = solve();
		cout << "Case #" << t << ": ";
		cout << ans;
		cout << "\n";
	}


	return 0;
}
