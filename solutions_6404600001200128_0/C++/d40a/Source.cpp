#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stack>

using namespace std;
#define LL long long
#define FILES freopen("input.txt" ,"r", stdin); freopen("output.txt", "w", stdout);
#define FASTER ios::sync_with_stdio(0);

const LL maxn = 2 * 1e5 + 1;

stack <LL> st;
vector <LL> inputData;
int main() {
	FILES;
	FASTER;
	LL T;
	cin >> T;
	for (LL test = 1; test <= T; test++) {
		LL n;
		cin >> n;
		vector <LL> a(n);
		for (LL i = 0; i < n; i++) {
			cin >> a[i];
		}
		LL ans1 = 0;
		LL ans2 = 0;
		for (LL i = 1; i < n; i++)
			ans1 += max(a[i - 1] - a[i], 0LL);

		LL d = 0;
		for (LL i = 1; i < n; i++) {
			d = max(d, max(a[i - 1] - a[i], 0LL));
		}
		for (LL i = 0; i < n - 1; i++) {
			ans2 += min(d, a[i]);
		}
		cout << "Case #" << test << ": ";
		cout << ans1 << ' ' << ans2 << endl;
	}
}