#include <bits/stdc++.h>
using namespace std;

pair<int,int> a[30];
int N;

void init()
{
	scanf("%d",&N);
	for (int i=1; i<=N; i++) scanf("%d",&a[i].first),a[i].second=i;
}

void doit()
{
	for (;;)
	{
		sort(a+1,a+N+1);
		int m1=0,m2=0,p1,p2,s=0;
		for (int j=1; j<=N; j++) if (a[j].first)
		{
			if (a[j].first>m1) m2=m1,p2=p1,m1=a[j].first,p1=j;
			else if (a[j].first>m2) m2=a[j].first,p2=j;
			s++;
		}
		if (!s) break;
		if (m1==m2&&s==2) printf("%c%c ",a[p1].second+64,a[p2].second+64),a[p1].first--,a[p2].first--;
		else printf("%c ",a[p1].second+64),a[p1].first--;
	}
	puts("");
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
