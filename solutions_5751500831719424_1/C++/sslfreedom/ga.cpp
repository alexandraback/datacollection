#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std; 

const int N=200;

int n;
int c[N][N], s[N][N];
int tot[N];
int ans;

void init()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
	{
		char tmp[N];
		scanf("%s", tmp);
		int len=strlen(tmp);
		tot[i]=1;
		c[i][1]=tmp[0]; s[i][1]=1;
		for (int j=1; j<len; ++j)
			if (tmp[j]==tmp[j-1]) ++s[i][tot[i]];
			else 
			{
				++tot[i];
				c[i][tot[i]]=tmp[j]; s[i][tot[i]]=1;
			}
	}
}

bool check()
{
	int tmp=tot[1];
	for (int i=2; i<=n; ++i)
		if (tmp!=tot[i]) return 0;
	for (int i=1; i<=tot[1]; ++i)
	{
		int tmp2=c[1][i];
		for (int j=2; j<=n; ++j)
			if (tmp2!=c[j][i]) return 0;
	}
	return 1;
}

int abs(int x)
{
	if (x<0) return -x; else return x;
}

void print()
{
	ans=0;
	int tmp[N];
	for (int i=1; i<=tot[1]; ++i)
	{
		for (int j=1; j<=n; ++j)
			tmp[j]=s[j][i];
		sort(tmp+1, tmp+1+n);
		int mid=tmp[(n+1)/2];
		for (int j=1; j<=n; ++j)
			ans+=abs(tmp[j]-mid);
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int cas;
	scanf("%d", &cas);
	for (int k=1; k<=cas; ++k)
	{
		printf("Case #%d: ", k);
		init();
		if (check())
			print();
		else printf("Fegla Won\n");
	}
}
