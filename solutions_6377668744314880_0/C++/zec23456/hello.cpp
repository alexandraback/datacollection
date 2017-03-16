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
long long x[3333];
long long y[3333];
int main()
{
	int t,T;
	int i,n,j,k;
	int re,a,b,c,themin;
	long long x1,x2,y1,y2,tt;
	freopen("C-small-attempt0.in","rt",stdin);
	freopen("C.out","wt",stdout);
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cout<<"Case #"<<t<<":"<<endl;
		cin>>n;
		for(i=0;i<n;i++)
			cin>>x[i]>>y[i];
		for(k=0;k<n;k++)
		{
			if(n>3)
				re=9999;
			else
				re=0;
			for(i=0;i<n;i++)
			{
				if(i==k)
					continue;
				a=b=c=0;
				for(j=0;j<n;j++)
				{
					if(j==i||j==k)
						continue;
					x1=x[i]-x[k];
					x2=x[j]-x[k];
					y1=y[i]-y[k];
					y2=y[j]-y[k];
					tt=x1*y2-x2*y1;
					if(tt>0)
						a++;
					else if(tt==0)
						b++;
					else
						c++;
				}
				themin=min(a,c);
				re=min(re,themin);
			}
			cout<<re<<endl;
		}
	}
    return 0;
}