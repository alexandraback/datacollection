#include <iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[10010];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.txt","w",stdout);
	
	int t,n,total,MAX,ans,rate,st;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		total=0;MAX = 0;ans=0;rate=0;
		cin >> n;
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}
		for(int j=1;j<n;j++) if(a[j]<a[j-1]) total+=-a[j]+a[j-1];
		for(int j=1;j<n;j++) rate = max(rate, a[j-1]-a[j]);
		st = a[0];
		for(int j=1;j<n;j++)
		{
			if(st < rate)
			{
				ans+=st;
				st=0;
			}
			else
			{
				st-=rate;
				ans+=rate;
			}
			st = a[j];
		}
		cout << "Case #" << i+1 << ": " << total << " " << ans << endl; 
	}
}