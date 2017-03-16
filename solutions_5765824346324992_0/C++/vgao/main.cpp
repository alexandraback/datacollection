#include <iostream>
#include <cstddef>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstdio>

#pragma warning(disable : 4996)

using namespace std;

typedef unsigned long long ull;

int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	size_t cases; cin >> cases;
	for (size_t _ = 0; _ < cases; ++_) {
		size_t n; ull m;
		cin >> n >> m;
		vector<ull> v(n);
		for (auto & x : v)
			cin >> x;
		ull left = 0, right = 0xffffffffffffull, count = right - left;
		while (0 < count) {
			ull count2 = count / 2;
			ull mid = left + count2;
			ull s = 0;
			for (auto & x : v)
				s += (mid % x == 0 ? 0 : 1) + mid / x;
			if (s < m) {
				left = ++mid;
				count -= count2 + 1;
			}
			else
				count = count2;
		}
		ull left2 = left - 1;
		for (auto & x : v)
			m -= left2 / x;
		vector<size_t> rank(n);
		for (size_t i = 0; i < n; ++i)
			rank[i] = i;
		sort(rank.begin(), rank.end(), [&](size_t i, size_t j)->bool {
			ull a = left2 - left2%v[i], b = left2 - left2%v[j];
			if (a != b)
				return a < b;
			return i < j;
		});
		cout << "Case #" << (_ + 1) << ": " << rank[m - 1] + 1 << endl;
	}
	return 0;
}