//*
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, m;
ll a[3000];

int isgood(ll t)
{
	int i;
	ll sum=0;
	for(i=0;i<n;i++)
	{
		sum+=t/a[i];
		sum+=1;
	}
	if(sum >= m) return 1;
	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, TT;
	scanf("%d", &TT);
	for(T=0;T<TT;T++)
	{
		int i, j, k;
		scanf("%d%d", &n, &m);
		for(i=0;i<n;i++) scanf("%I64d", &a[i]);
		ll low=0, high=1e15, mid;
		while(low <= high)
		{
			mid=(low+high)/2;
			if(isgood(mid))
			{
				high=mid-1;
			}
			else
			{
				low=mid+1;
			}
		}
		int dab=0, cnt=0;
		for(i=0;i<n;i++)
		{
			cnt+=low/a[i];
			if(low%a[i] != 0) cnt++;
		}
		for(i=0;i<n;i++)
		{
			if(low%a[i] == 0) cnt++;
			if(cnt == m)
			{
				break;
			}
		}
		printf("Case #%d: %d\n", T+1, i+1);
	}
	return 0;
}

//*/