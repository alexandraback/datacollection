#include <iostream>
#include <algorithm>
#include <assert.h>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <time.h>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
#define mp make_pair
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin >> k;
	for (int k1 = 0; k1 < k; ++k1) {
		cout << "Case #" << k1 + 1 << ": ";
		int n;
		cin >> n;
		vector<pair<int, char>> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i].first;
			v[i].second = 'A' + i;
		}
		ll sum = 0;
		for (auto a : v) {
			sum += a.first;
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		while (sum > 0) {
			if (sum == 3) {
				cout << v[0].second << " ";
				--v[0].first;
			}
			else {
				if (v[0].first <= v[1].first + 1) {
					cout << v[0].second << v[1].second << " ";
					--v[0].first, --v[1].first;
				}
				else {
					cout << v[0].second << v[0].second << " ";
					v[0].first -= 2;
				}
			}
			sum = 0;
			for (auto a : v) {
				sum += a.first;
			}
			sort(v.begin(), v.end());
			reverse(v.begin(), v.end());
		}
		cout << endl;
	}
}