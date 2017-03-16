#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m[100100];
bool psbl(ll t, ll b, ll n)
{
	ll w = 0;
	for(int i=1;i<=b;i++)
	{
		w+=(t+m[i])/m[i];
	}
	return w>=n;
}
int main()
{
	int test;
	cin>>test;
	for(int z=1;z<=test;z++)
	{
		ll b,n;
		cin>>b>>n;
		for(int i=1;i<=b;i++)
			cin>>m[i];
		ll l=0,r=100000*n;
		while(l<r)
		{
			ll mid = (l+r)/2;
			if(psbl(mid,b,n))
			{
				r=mid;
			}
			else l=mid+1;
		}
		ll t = l;
		//cout<<t<<endl;
		ll done =0 ;
		for(int i=1;i<=b;i++)
		{
			done+=(t+m[i])/m[i];
			if(t%m[i]==0)done--;
		}
		//cout<<n<<" "<<done<<endl;
		ll k = n-done;
		ll ans = -1;
		for(int i=1;i<=b;i++)
		{
			if(t%m[i]==0)k--;
			{
				if(k==0){ans=i;break;	}
			}
		}
		//if(ans<0)cout<<z<<endl;
		cout<<"Case #"<<z<<": "<<ans<<endl;
	}
}
