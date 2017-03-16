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
long long a[1111];
int main()
{
	int t,T;
	int i,n,x;
	int re;
	int temp;
	long long num,num2;
	long long ll,rr,mm;
	freopen("B-small-attempt1.in","rt",stdin);
	freopen("B.out","wt",stdout);
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>n>>x;
		for(i=0;i<n;i++)
			cin>>a[i];
		ll=0;rr=2e14;
		while(ll<rr)
		{
			mm=(ll+rr)/2;
			num=num2=n;
			for(i=0;i<n;i++)
			{
				num+=mm/a[i];
				num2+=mm/a[i];
				if(mm%a[i]==0)
					num--;
			}
			if(num2<x)
				ll=mm+1;
			else
			{
				rr=mm;
			}
		}
		if(num2<x&&ll==rr)
		{
			mm=(ll+rr)/2;
			num=num2=n;
			for(i=0;i<n;i++)
			{
				num+=mm/a[i];
				num2+=mm/a[i];
				if(mm%a[i]==0)
					num--;
			}
		}
		temp=x-num;
		for(i=0;i<n;i++)
		{
			if(mm%a[i]==0)
			{
				temp--;
				if(temp==0)
				{
					re=i+1;
					break;
				}
			}
		}
		cout<<"Case #"<<t<<": "<<re<<endl;
	}
    return 0;
}