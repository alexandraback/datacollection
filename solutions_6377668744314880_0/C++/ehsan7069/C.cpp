/*
 * By ehsan7069
 * ehsan7069@gmail.com
 */

#include <iostream>
#include <iomanip>

#include <algorithm>

#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

// variables

struct Point {
	long long x, y;

	Point (long long _x = 0, long long _y = 0) :
		x(_x), y(_y) { }
	
	int ind;

	void read (int _ind) {
		cin >> x >> y;
		ind = _ind;
	}

	long long operator * (const Point & p) const {
		long long temp = x * p.y - y * p.x;
		if (temp == 0)
			return 0;
		if (temp < 0)
			return -1;
		return 1;
	}

	bool operator < (const Point & p) const {
		if (x != p.x)
			return (x < p.x);
		return (y < p.y);
	}

	Point operator - (const Point & p) const {
		return Point(x - p.x, y - p.y);
	}

};

const int MAX_n = 3000;

int n, ans[MAX_n];

Point data[MAX_n];

// functions

void input () {
	cin >> n;
	for (int i = 0 ; i < n ; i++)
		data[i].read(i);
	return;
}

void init () {
	sort(data, data + n);
	for (int i = 0 ; i < n ; i++)
		ans[data[i].ind] = min (i, n - i - 1);
	return;
}

int my_check (int alpha, int beta, int gamma) {
	return (data[beta] - data[alpha]) * (data[gamma] - data[alpha]);
}

void solve_forward () {
	for (int i = 0 ; i < n ; i++)
		for (int j_a = i - 1 ; j_a >= 0 ; j_a--)
			for (int j_b = i + 1 ; j_b < n ; j_b++) {
				if (my_check(j_a, i, j_b) == -1)
					continue;
				int temp = 0;
				for (int k = 0 ; k < i ; k++)
					if (my_check(j_a, k, i) == 1)
						temp++;
				for (int k = i + 1 ; k < n ; k++)
					if (my_check(j_b, i, k) == 1)
						temp++;
				if (temp < ans[data[i].ind])
					ans[data[i].ind] = temp;
			}
	return;
}

void solve_backward () {
	for (int i = n - 1 ; i >= 0 ; i--)
		for (int j_a = i + 1 ; j_a < n ; j_a++)
			for (int j_b = i - 1 ; j_b >= 0 ; j_b --) {
				if (my_check(j_a, i, j_b) == -1)
					continue;
				int temp = 0;
				for (int k = n - 1 ; k > i ; k--)
					if (my_check(j_a, k, i) == 1)
						temp++;
				for (int k = i - 1 ; k >= 0 ; k--)
					if (my_check(j_b, i, k) == 1)
						temp++;
				if (temp < ans[data[i].ind])
					ans[data[i].ind] = temp;
			}
	return;
}

void solve () {
	solve_forward();
	solve_backward();
	return;
}

void output (int t) {
	cout << "Case #" << t + 1 << ":" << endl;
	for (int i = 0 ; i < n ; i++)
		cout << ans[i] << endl;
	return;
}

// main

int main () {
	int T;
	cin >> T;
	for (int t = 0 ; t < T ; t++) {
		input();
		init();
		solve();
		output(t);
	}
	return 0;
}

