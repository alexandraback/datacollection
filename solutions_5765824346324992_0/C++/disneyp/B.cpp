#include <iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
long long a[1010];
long long v[1010];
long long b,n;
long long x,c;
long long f(long long r)
{
	
	
	x=0,c=0;
	for(int i=0;i<b;i++)
	{
		x+=(r-1)/a[i]+1;
		//cout << "Aaaaaa" << x << endl;
		
		if(r%a[i]==0)
		{
			c++;v[i]=1;
		}
		else v[i]=0;
	}
	//cout << "====" << r << " " <<  x << " " << n  << " " << c << endl;
	if(x<n&&n<=x+c) return 1;
	if(x+c < n) return 0;
	return 2;
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.txt","w",stdout);
	long long t,MIN=0, MAX= 1000000000000ll,p,q,r,z,ans;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> b >> n;
		for(int j=0;j<b;j++) scanf("%lld",&a[j]);
		p=MIN;q=MAX;
		while(p<=q)
		{
			r=(p+q)/2;
			z=f(r);
			if(z==1)
			{
				//cout << "---"<<p<<" "<< q<<" " << r << endl;
				long long aa=0;
				//cout << v[0] << " " << v[1] << " " << v[2] << " " << c << endl;
				while(n-x>0)
				{
					if(v[aa]==1) n--;
					if(n-x==0)
					{
						ans = aa+1;
						break;
					}
					aa++;
				}
				break;
			}
			else if(z==0)
			{
				p=r+1;
			}
			else q=r-1;
		}
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
}