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

int a[1005],b[1005];
map<int,int> mp;
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int cas,n,k,i,ccass=1,j;
	cin>>cas;
	
	while(cas--)
	{
		int lcm=1;
		scanf("%d %d",&n,&k);
		mp.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]); b[i]=a[i];
			mp[i]=i;
			lcm=lcm*a[i] / gcd(lcm,a[i]) ;
		}
	//	printf("%d\n",lcm);
		int res=0;
		for(i=1;i<=n;i++)
		{
			res+=lcm/a[i];
		}
		
		k=k%res; if(k==0) k=res;
		int next=n+1;
	//	printf("Case #%d: %d %d\n",ccass++,k,res);
		
		while(mp[k]==0)
		{
			int m=100005,flag;
			for(i=1;i<=n;i++) 
			{
				if(b[i]<m) { m=b[i]; flag=i; }
			}
			for(j=1;j<=n;j++)
			{
				b[j]-=m;	
			}
			mp[next++]=flag;
			b[flag]=a[flag];


		}
		printf("Case #%d: %d\n",ccass++,mp[k]);
	}
	
	return 0;
}