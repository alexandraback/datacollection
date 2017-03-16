#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
typedef long long ll;
int b,n;
int a[1010];
//int fin;
bool lft[1010];
ll calc(ll t)
{
	ll ans=0;
	for(int i=0;i<b;i++)
	{
		ans+=(t+a[i]-1)/a[i];
		lft[i]=(t%a[i]==0);
//		if(fin==-1 && t%a[i]==0)
//			fin=i;
	}
	return ans;
}
int main()
{
	int T,no=1;
	cin>>T;
	while(no<=T)
	{
		cin>>b>>n;
		for(int i=0;i<b;i++)
			cin>>a[i];
		ll l=0,r=ll(a[0])*n;
		while(l<r)
		{
			ll mid=(l+r+1)/2;
			ll c=calc(mid);
			//cout<<l<<' '<<r<<' '<<mid<<' '<<c<<endl;
			//system("pause");
//			cout<<mid<<'/'<<c<<' ';
			if(c<n)
			{
				l=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		int ans=-1;
		ll t=calc(l);
//		cout<<t<<' '<<l<<endl;
		for(int i=0;i<b;i++)
			if(lft[i])
			{
				t++;
				if(t==n){ans=i+1; break;}
			}
		printf("Case #%d: %d\n",no++,ans);
	}
}
