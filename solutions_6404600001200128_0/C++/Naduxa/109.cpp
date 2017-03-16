#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int q = 0; q < t; q++)
	{
		int n;
		scanf("%d", &n);
		vector <int> a(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		int ans1 = 0;
		for (int i = 1; i < n; i++)
		{
			if (a[i] < a[i - 1]) ans1 += a[i - 1] - a[i];
		}

		int v = 0;
		for (int i = 1; i < n; i++)
		{
			v = max(a[i - 1] - a[i], v);
		}

		int ans2 = 0;
		for (int i = 0; i < n - 1; i++)
		{
			ans2 += min(a[i], v);
		}

		cout << "Case #" << q + 1 << ": " << ans1 << " " << ans2 << endl;
	}
	return 0;
}