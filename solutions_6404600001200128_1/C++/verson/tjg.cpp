#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <string>
#pragma warning(disable:4996)

#define ll long long
#define rep(i,n) for (int i=0; i<n; i++)
using namespace std;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int a[1000];

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int n, ans1 = 0, ans2 = 0, m = 0;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 1; i < n; i++) 
			if (a[i - 1] > a[i])
			{
				ans1 += a[i - 1] - a[i];
				m = max(m, a[i - 1] - a[i]);
			}
		for (int i = 0; i < n - 1; i++) ans2 += min(a[i], m);
		cout << "Case #" << t << ": " << ans1 << " " << ans2 << endl;
	}
}