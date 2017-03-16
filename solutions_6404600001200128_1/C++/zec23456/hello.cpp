#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include <iomanip>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<stack>
#include<cstring>
#include<map>
#include<set>
using namespace std;
#define MOD 1000000007
int a[11111];
int main()
{
	int t,T;
	int i,n;
	int themax;
	int x,y;
	freopen("A-large.in","rt",stdin);
	freopen("A.out","wt",stdout);
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>n;
		cin>>a[0];
		x=y=0;
		themax=0;
		for(i=1;i<n;i++)
		{
			cin>>a[i];
			if(a[i]<a[i-1])
			{
				x+=a[i-1]-a[i];
				themax=max(themax,a[i-1]-a[i]);
			}
		}
		for(i=0;i<n-1;i++)
		{
			y+=min(a[i],themax);
		}
		cout<<"Case #"<<t<<": "<<x<<" "<<y<<endl;
	}
    return 0;
}