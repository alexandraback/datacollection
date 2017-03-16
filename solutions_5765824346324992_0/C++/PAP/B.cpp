#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int MAXN = 1005;
int mark[MAXN], a[MAXN];
int n, k;

int check(int x, int i)
{
	int sum = 0;
	for(int j = 0; j < n; j++)
	{
		sum += x * a[i] / a[j];
		if(j > i && x * a[i] % a[j] == 0)
			sum--;
	}
	if(k > sum)
		return 1;
	if(k == sum)
		return 2;
	return 0;
}

main()
{
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++)
	{
		fill(mark, mark + MAXN, 0);
		cin >> n >> k;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << "Case #" << tt << ": ";
		if(k <= n)
		{
			cout << k << endl;
			continue;
		}
		k -= n;
		for(int i = 0; i < n; i++)
		{
			int lo = 0, hi = k + 1;
			while(hi - lo > 1)
			{
				int mid = (lo + hi) / 2;
				if(check(mid, i))
					lo = mid;
				else
					hi = mid;
			}
			if(check(lo, i) == 2)
				cout << i + 1 << endl;
		}
	}
	return 0;
}
