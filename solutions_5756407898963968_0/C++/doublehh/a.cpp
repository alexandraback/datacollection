/*
*   Copyright (C) 2014 All rights reserved.
*   
*   filename: a.cpp
*   author: doublehh
*   e-mail: sserdoublehh@foxmail.com
*   create time: 2014-04-12
*   last modified: 2014-04-12 07:02:59
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define FOR(i,n) for (int i = 0; i < (n); i++)
#define FOR1(i,n) for (int i = 1; i <= (n); i++)

int n1, n2;
int cnt[16];
int ans, nAns;

int main()
{
	freopen("out", "w", stdout);
	int T;
	scanf("%d", &T);
	FOR1 (Case, T)
	{
		ans = -1, nAns = 0;
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n1);
		FOR (i, 4) FOR (j, 4)
		{
			int x;
			scanf("%d", &x);
			if (i == n1-1)
				cnt[x-1]++;
		}
		scanf("%d", &n2);
		FOR (i, 4) FOR (j, 4)
		{
			int x;
			scanf("%d", &x);
			if (i == n2-1 && cnt[x-1])
			{
				ans = x;
				nAns++;
			}
		}
		printf("Case #%d: ", Case);
		if (nAns > 1)
			puts("Bad magician!");
		else if (nAns == 1)
			printf("%d\n", ans);
		else
			puts("Volunteer cheated!");
	}
}
