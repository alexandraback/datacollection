#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdexcept>
#include <string>
#include <assert.h>
#include <set>
#include <time.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main() {

	freopen("miA2.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	for (int k = 1; k <= tests; k++) {
		set<pair<int, int>> s;
		int n;
		cin >> n;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			sum += x;
			s.insert(make_pair(x, i));
		}
		cout << "Case #" << k << ": ";
		if (sum % 2 != 0) {
			pair<int, int> r = *s.rbegin();
			s.erase(r);
			r.first--;
			cout << char('A' + r.second) << " ";
			if (r.first > 0)
				s.insert(r);
		}
		while (!s.empty()) {
			assert(s.size() >= 2);
			pair<int, int> r1 = *s.rbegin();
			s.erase(r1);
			r1.first--;

			pair<int, int> r2 = *s.rbegin();
			s.erase(r2);
			r2.first--;

			cout << char('A' + r1.second);
			cout << char('A' + r2.second);
			cout << " ";

			if (r1.first > 0)
				s.insert(r1);
			if (r2.first > 0)
				s.insert(r2);
		}
		cout << endl;
	}

}