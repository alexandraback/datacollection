#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define test int t;scanf("%d", &t);for(int q=1;q<=t;q++)
int main()
{
	test
	{
		int n, a[11];
		scanf("%d", &n);
		for(int i=0;i<n;i++)scanf("%d", &a[i]);
		int y=0, z=0;
		float rate=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]<a[i-1])
			{
				y+=a[i-1]-a[i];
				float dif = a[i-1]-a[i];
				dif/=10;
				//dif=ceil(dif);
				if(dif>rate)rate=dif;
			}
		}
		float cur=a[0];
		for(int i=1;i<n;i++)
		{
			z+=min(rate*10,cur);
			cur=a[i];
		}
		printf("Case #%d: %d %d\n", q, y, z);
	}
	return 0;
}
