//#pragma comment(linker, "/STACK:10000000")

#pragma once
#pragma warning(disable:4996)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<int> v(1234);

int main () {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	int test = 1;
	while (t --> 0) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		int sum = 0;
		for (int i = 1; i < n; ++i) {
			if (v[i - 1] > v[i]) {
				sum += v[i - 1] - v[i];
			}
		}
		cout << "Case #" << test++ << ": ";
		cout << sum;
		cout << " ";
		sum = 0;
		for (int i = 1; i < n; ++i) {
			if (v[i - 1] > v[i]) {
				sum = max(sum, v[i-1]-v[i]);
			}
		}
		int ans = 0;
		for (int i = 0; i + 1 < n; ++i) {
			if (v[i] < sum) {
				ans += v[i];
			} else {
				ans += sum;
			}
		}
		cout << ans;
		cout << "\n";
	}

	return 0;
}
