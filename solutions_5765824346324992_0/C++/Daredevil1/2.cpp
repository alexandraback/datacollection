#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;
#define mod 1000000007
#define ll long long int
#define test int t;scanf("%d", &t);for(int q=1;q<=t;q++)
int chance[10000000]={0};
bool check(int time[5], int b)
{
	int t=time[0];
	for(int i=1;i<b;i++)
	{
		if(time[i]!=t)return 1;
	}
	return 0;
}
int main()
{
	test
	{
		for(int i=0;i<10000000;i++)chance[i]=0;
		int b, n, m[5];
		scanf("%d%d", &b, &n);
		n--;
		for(int i=0;i<b;i++)scanf("%d", &m[i]);
		int time[5]={0}, cur=0, ind=0;
		while(1)
		{
			for(int i=0;i<b;i++)
			{
				if(time[i]==cur)
				{
					chance[ind++]=i;
					time[i]=cur+m[i];
				}
			}
			cur++;
			if(!check(time,b))break;
		}
		n=n%ind;
		printf("Case #%d: %d\n", q, chance[n]+1);
	}
	return 0;
}
