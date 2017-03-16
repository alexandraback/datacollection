#include <bits/stdc++.h>
using namespace std;

int N,a[1005];

void init()
{
	scanf("%d",&N);
	for (int i=1; i<=N; i++) scanf("%d",&a[i]);
}

int calc(int v)
{
	int s=0;
	for (int i=1; i<N; i++)
	{
		if (a[i]-v>a[i+1]) return 1e9;
		s+=min(a[i],v);
	}
	return s;
}

void doit()
{
	int ans1=0,ans2=1e9;
	for (int i=1; i<N; i++) if (a[i]>a[i+1]) ans1+=a[i]-a[i+1];
	for (int v=0; v<=10000; v++) ans2=min(ans2,calc(v));
	printf("%d %d\n",ans1,ans2);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=1; i<=T; i++)
	{
		init();
		printf("Case #%d: ",i);
		doit();
	}
	return 0;
}

