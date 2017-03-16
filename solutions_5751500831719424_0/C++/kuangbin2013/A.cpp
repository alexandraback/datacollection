/* ***********************************************
Author        :kuangbin
Created Time  :2014/5/4 0:03:25
File Name     :E:\2014ACM\±ÈÈü\2014_GCJ_R1B\A.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
char str[110][110];
char ss[110][110];
int num[110][110];
int cnt[110];
int b[110];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
	int n;
	int iCase = 0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		for(int i = 0;i < n;i++)
		{
			scanf("%s",str[i]);
			int m = strlen(str[i]);
			for(int j = 0;j < m;j++)
			{
				if(j == 0 || str[i][j] != str[i][j-1])
				{
					ss[i][cnt[i]] = str[i][j];
					num[i][cnt[i]] = 1;
					cnt[i]++;
				}
				else if(j > 0 && str[i][j] == str[i][j-1])
					num[i][cnt[i]-1]++;
			}
		}
		iCase++;
		bool flag = true;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				if(cnt[i] != cnt[j])
				{
					flag = false;
					break;
				}
		if(!flag)
		{
			printf("Case #%d: Fegla Won\n",iCase);
			continue;
		}
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				for(int k = 0;k < cnt[i];k++)
					if(ss[i][k] != ss[j][k])
					{
						flag = false;
						break;
					}
		if(!flag)
		{
			printf("Case #%d: Fegla Won\n",iCase);
			continue;
		}
		int ans = 0;
		for(int k = 0;k < cnt[0];k++)
		{
			for(int i = 0;i < n;i++)
				b[i] = num[i][k];
			sort(b,b+n);
			for(int i = 0;i < n;i++)
				ans += abs(b[i] - b[n/2]);
		}
		printf("Case #%d: %d\n",iCase,ans);
	}
	return 0;
}
