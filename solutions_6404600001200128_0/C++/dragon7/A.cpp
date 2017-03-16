#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[1010];
int main()
{
	int test;
	cin>>test;
	for(int z=1;z<=test;z++)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		ll sum1 = 0;
		ll maxi = 0;
		for(int i=1;i<n;i++)
		{
			if(a[i]>a[i+1])sum1+=(a[i]-a[i+1]);
			maxi = max(maxi, a[i]-a[i+1]);
		}
		ll sum2 = 0;
		for(int i=1;i<n;i++)
		{
			sum2+=min(maxi, a[i]);
		}
		cout<<"Case #"<<z<<": "<<sum1<<" "<<sum2<<endl;
	}
}
