#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const LL MaxT=1000000000LL*100000LL;

int n, b, m[1001];
vector< pair<LL,int> > queue;

LL cnt(LL time)
{
	LL s=0;
	for (int i=1; i<=b; ++i) s+=time/m[i];
	return s;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tt=1; tt<=T; ++tt)
	{
		scanf("%d%d", &b, &n);
		for (int i=1; i<=b; ++i) scanf("%d", m+i);
		if (n<=b)
		{
			printf("Case #%d: %d\n", tt, n);
			continue;
		}
		LL low=0, mid, high=MaxT;
		while (low<high)
		{
			mid=(low+high)>>1;
			if (cnt(mid)>=n-1) high=mid; else low=mid+1;
		}
		int nn=0;
		queue.clear();
		for (int i=1; i<=b; ++i)
		{
			nn+=low/m[i];
			if (low%m[i]==0) queue.push_back(make_pair(low-m[i], i));
		}
		int k;
		sort(queue.begin(), queue.end());
		if (nn==n-1)
		{
			for (k=1; k<=b && low%m[k]>0; ++k);
		}
		else k=queue[n-1-(nn-queue.size())].second;
		printf("Case #%d: %d\n", tt, k);
	}
	return 0;
}

