#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
#include<map>
using namespace std;
#define gc getchar_unlocked
#define sd(a) scanf("%lld",&a)
#define pd(a) prlong longf("%d\n",(a))
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	long long n,t,i,j,k,maxdiff;
	long long a[10010],ans,ans1;
	
	sd(t);
	for(k=1;k<=t;++k)
	{
		ans=0;
		ans1=0;
		sd(n);
		for(i=0;i<n;++i)
		{
			sd(a[i]);
		}
		maxdiff=-1;
		for(i=1;i<n;++i)
			maxdiff=max(maxdiff,a[i-1]-a[i]);
		if(maxdiff<0)
			maxdiff=0;
		for(i=0;i<n-1;++i)
		{
			ans=ans+min(a[i],maxdiff);
			if(a[i+1]<a[i])
				ans1=ans1+a[i]-a[i+1];
		}
		printf("Case #%lld: %lld %lld\n",k,ans1,ans);
	}
	
}