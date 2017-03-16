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
int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
int lcm(int a,int b)
{
	int x=a*b;
	return x/gcd(a,b);
}
vector<pair<int,int> > vr;
int main()
{
	int t,b,k,ind,i,j;
	ll n;
	getint(t);
	rep(ind,1,t)
	{
		getint(b);
		getlong(n);
		int m[b];
		int res=1;
		rep(i,0,b-1)
		{
			getint(m[i]);
			res=lcm(res,m[i]);
		}
		int val=0;
		rep(i,0,b-1)
		{
			int tos=res/m[i];
			val+=tos;
			rep(j,0,tos-1)
				vr.pb(mp(j*m[i],i+1));
		}
		// cerr<<res<<endl;
		sort(vr.begin(),vr.end());
		// if(ind==2)
		// rep(i,0,vr.size()-1)
		// cerr<<vr[i].first<<" "<<vr[i].second<<endl;
		n=(n)%(val);
		n=n-1;
		if(n<0)
			n=n+val;
		int ans=vr[n].second;
		printf("Case #%d: %d\n",ind,ans);
		vr.clear();
	}
}