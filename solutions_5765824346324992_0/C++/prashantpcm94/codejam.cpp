#include <iostream>
using namespace std;
long long gcd (long a,long b)
{
	if(a%b==0)
	return b;
	else
	return gcd(b,a%b);
}
long long LCM(long long a,long long b)
{
	return a*b/gcd(a,b);
}
int main()
{
	int t;
	cin>>t;
	int l=1;
	while(t--)
	{
		long long n,m;
		cin>>n>>m;
		long long a[n],lcm=1,x=0,b[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			b[i]=0;
			lcm=LCM(lcm,a[i]);
		}
		for(int i=0;i<n;i++)
		{
			x+=(lcm/a[i]);
		}
		if(m>x)
		{
			m=m%x;
			if(m==0)
			m=x;
		}
		long long ans;
		for(int i=0;i<n;i++)
		{
			b[i]+=a[i];
		}
		for(int i=n;i<m;i++)
		{
			long long min=1000000000,z;
			for(int j=0;j<n;j++)
			{
				if(b[j]<min)
				{
					min=b[j];
					z=j;
				}
			}
			b[z]+=a[z];
			ans=z+1;
		}
		if(m<=n)
		ans=m;
		cout<<"Case #"<<l<<": "<<ans<<endl;
		l++;
	}
}
