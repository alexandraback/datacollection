#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
int a[10000];
int main()
{
	int ii, tt, i, tot, t1,_max,n;
	freopen("111.txt", "r", stdin);
	freopen("222.txt", "w", stdout);
	scanf("%d", &tt);
	for (ii = 1; ii <= tt; ii++)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		tot = 0;
		for (i = 2; i <= n;i++)
		if (a[i - 1] > a[i]) tot = tot + a[i - 1] - a[i];
		_max = 0;
		for (i = 2; i <= n;i++)
		if (a[i-1] - a[i] > _max) _max = a[i-1] - a[i];
		t1 = 0;
		for (i = 1; i <= n-1; i++)
		{
			if (a[i] >= _max) t1 += _max;
			else
				t1 += a[i];
		}
		printf("Case #%d: %d %d\n", ii, tot, t1);
	}
	return 0;
}