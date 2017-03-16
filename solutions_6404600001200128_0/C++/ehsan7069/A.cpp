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

const int MAX_n = 1000;

int n, a[MAX_n], first, second;

// functions

void clear () {
	return;
}

void input () {
	cin >> n;
	for (int i = 0 ; i < n ; i++)
		cin >> a[i];
	return;
}

void init () {
	return;
}

void solve () {
	first = 0;
	for (int i = 1 ; i < n ; i++)
		if (a[i] < a[i - 1])
			first += a[i - 1] - a[i];
	int temp = 0;
	for (int i = 1 ; i < n ; i++)
		if (temp < a[i - 1] - a[i])
			temp = a[i - 1] - a[i];
	second = 0;
	for (int i = 1 ; i < n ; i++)
		second += min(temp, a[i - 1]);
	return;
}

void output (int t) {
	cout << "Case #" << t + 1 << ": " << first << " " << second << endl;
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

