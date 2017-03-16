#include<bits/stdc++.h>
using namespace std;
int m[10005];
#define lcm(a,b) (a/__gcd(a,b)*b)
int main()
{
	int tc;
	scanf("%d",&tc);
	for(int t = 1;t<=tc;t++)
	{
		int b,n,alllcm;
		scanf("%d%d",&b,&n);
		for(int i = 0;i<b;i++)
		{
			scanf("%d",&m[i]);
		}
		alllcm = m[0];
		for(int i = 1;i<b;i++)
		{
			alllcm = lcm(alllcm,m[i]);
		}
		int total = 0;
		for(int i = 0;i<b;i++)
		{
			total += alllcm/m[i];
		}
		n--;
		n%=total;
		vector<pair<int, int> > stuff;
		for(int i = 0;i<b;i++)
		{
			for(int j = 0;j<alllcm/m[i];j++)
			{
				stuff.emplace_back(pair<int, int>(j*m[i],i));
			}
		}
		sort(stuff.begin(),stuff.end());
		printf("Case #%d: %d\n",t,stuff[n].second+1);
	}
	return 0;
}
