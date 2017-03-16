#include <iostream>
#include <cstddef>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstdio>

#pragma warning(disable : 4996)

using namespace std;

size_t solve_a(vector<size_t> & v)
{
	size_t s = 0;
	for (size_t i = 1; i < v.size(); ++i) {
		if (v[i] < v[i - 1])
			s += v[i - 1] - v[i];
	}
	return s;
}

size_t solve_b(vector<size_t> & v)
{
	size_t m = 0;
	for (size_t i = 1; i < v.size(); ++i) {
		if (v[i] < v[i - 1])
			m = max(m, v[i - 1] - v[i]);
	}
	size_t s = 0;
	for (size_t i = 0; i < v.size() - 1; ++i)
		s += min(v[i], m);
	return s;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	size_t n; cin >> n;
	for (size_t i = 0; i < n; ++i) {
		size_t m; cin >> m;
		vector<size_t> v(m);
		for (auto & x : v)
			cin >> x;
		cout << "Case #" << (i + 1) << ": " << solve_a(v) << " " << solve_b(v) << endl;
	}
	return 0;
}