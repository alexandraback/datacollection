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

const int MAX_k = 1000, MAX_TIME = 100 * 1000;

int k, ans;

long long n, b[MAX_k];

// functions

void clear () {
	return;
}

void input () {
	cin >> k >> n;
	for (int i = 0 ; i < k ; i++)
		cin >> b[i];
	return;
}

void init () {
	return;
}

long long find_opt_time (long long begin, long long end) {
	if (end - begin == 1)
		return begin;
	long long mid = (begin + end) / 2;
	long long counter = 0;
	for (int i = 0 ; i < k ; i++)
		counter += (mid - 1) / b[i] + 1;
	if (counter >= n)
		return find_opt_time(begin, mid);
	return find_opt_time(mid, end);
}

void my_check (long long opt_time) {
	long long copy_n = n;
	for (int i = 0 ; i < k ; i++)
		copy_n -= (opt_time + b[i] - 1) / b[i];
	for (int i = 0 ; i < k ; i++)
		if (opt_time % b[i] == 0) {
			ans = i;
			copy_n--;
			if (copy_n == 0)
				return;
		}
	ans = -7069;
	return;
}

void solve () {
	long long opt_time = find_opt_time(0, n * MAX_TIME);
	my_check(opt_time);
	return;
}

void output (int t) {
	cout << "Case #" << t + 1 << ": " << ans + 1 << endl;
	return;
}

// main

int main () {
	int T;
	cin >> T;
	for (int t = 0 ; t < T ; t++) {
		clear();
		input();
		init();
		solve();
		output(t);
	}
	return 0;
}

