#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
int n, m;
long long a[10000];
int pig(int index, long long num)
{
	long long tim, tot;
	int i;
	tim = num*a[index];
	tot = 0;
	for (i = 1; i <= m; i++)
	{
		if (tim%a[i] == 0)
		{
			if (i <= index) tot += tim / a[i] + 1;
			else
				tot += tim / a[i];
		}
		else
			tot += tim / a[i] + 1;
	}
	if (tot == n) return 0;
	if (tot < n) return -1;
	return 1;
}
bool dog(int index)
{
	long long left, right,mid;
	int ret;
	left = 1;
	right = n;
	while (left <= right)
	{
		mid = (left + right) / 2;
		ret = pig(index, mid - 1);
		if (ret < 0)
			left = mid+1;
		else
		if (ret>0) right = mid - 1;
		else
			return true;
	}
	return false;
}
int main()
{
	int i, ii, tt;
	freopen("111.txt", "r", stdin);
	freopen("222.txt", "w", stdout);
	scanf("%d", &tt);
	for (ii = 1; ii <= tt; ii++)
	{
		scanf("%d%d", &m,&n);
		for (i = 1; i <= m; i++)
			scanf("%lld", &a[i]);
		for (i = 1; i <= m; i++)
		{
			if (dog(i))
			{
				printf("Case #%d: %d\n", ii, i);
				break;
			}
		}
	}
	return 0;
}