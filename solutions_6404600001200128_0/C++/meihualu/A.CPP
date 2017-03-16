#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define eps 1e-7
using namespace std;

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int Min(int a,int b) { return a<b?a:b; }

//freopen("A-small-attempt0.in","r",stdin);
//freopen("A-small-attempt0.out","w",stdout);

int a[1005];
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);

	int cas,ccass=1,i,n;
	scanf("%d",&cas);
	while(cas--)
	{
		cin>>n;
		int sum=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		} 
		int res=0;
		for(i=1;i<n;i++)
		{
			if(a[i]>=a[i-1]) ;
			else res+=(a[i-1]-a[i]);
		}
		sum=sum-a[n-1]*2;
		printf("Case #%d: %d %d\n",ccass++,res,sum);
	}
	return 0;
}