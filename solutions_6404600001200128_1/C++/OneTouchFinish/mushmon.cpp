#include<bits/stdc++.h>
#define rep(i,s,n) for((i)=(s);(i)<=(n);(i)++)
#define getint(x) scanf("%d",&x)
#define getlong(x) scanf("%lld",&x)
#define putint(x) printf("%d",x)
#define putintln(x) printf("%d\n",x)
#define putlong(x) printf("%lld",x)
#define putlongln(x) printf("%lld\n",x)
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
int main()
{
	int t,n,ind,i;
	getint(t);
	rep(ind,1,t)
	{
		getint(n);
		int a[n];
		ll s1=0,s2=0;
		rep(i,0,n-1)
		{
			getint(a[i]);
			if(i!=0)
			{
				if(a[i]<a[i-1])
					s1=s1+(a[i-1]-a[i]);
			}
		}
		int mindif=0;
		for(i=n-1;i>0;i--)
		{
			mindif=max(mindif,a[i-1]-a[i]);
		}
		rep(i,0,n-2)
		{
			if(a[i]<a[i+1])
			{
				s2=s2+min(a[i],mindif);
			}
			else
			{
				s2=s2+max(min(mindif,a[i]),a[i]-a[i+1]);
			}
			// cout<<mindif<<"\n";
		}
		printf("Case #%d: %lld %lld\n",ind,s1,s2);
	}
}