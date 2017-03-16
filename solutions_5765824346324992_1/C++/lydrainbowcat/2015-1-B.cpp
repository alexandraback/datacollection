#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>

using namespace std;

const int N = 1010;
long long m[N];
long long b,n,nt,cnt;
int T;

long long check(long long pos)
{
	long long ret=0;
	for (int i=1;i<=b;i++) 
		ret+=pos/m[i];
	return ret;
}

long long bs(int n)
{
	long long l=0, r=0x7fffffffffffffLL, ret=0;
	while (l<=r)
	{
		long long mid=(l+r)>>1;
		if (check(mid)>=n) r=mid-1, ret=mid;
		else l=mid+1;
	}
	return ret;
}

int main()
{
	scanf("%d",&T);
	for (int test=1;test<=T;test++)
	{
		printf("Case #%d: ",test);
		cin>>b>>n;
		for (int i=1;i<=b;i++) cin>>m[i];
		if (n<=b) 
		{
			printf("%d\n", n);
			continue;
		}
		n-=b;
		cnt=1;
		nt=bs(n);
		while (bs(n-cnt)==nt) cnt++;
		for (int i=1;i<=b;i++)
			if (nt%m[i]==0)
			{
				cnt--;
				if (!cnt) 
				{
					printf("%d\n",i);
					break;
				}
			}
	}
	return 0;
}