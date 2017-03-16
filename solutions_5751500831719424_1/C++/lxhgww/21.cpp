#include<stdio.h>
#include<string.h>

char s[101][101];
int f[101];
int l[101];
int g[101];
int n;

int solve()
{
	int i,j;
	int cur;
	int ret=0;
	while (1)
	{
		cur=f[1];
		while (cur<l[1]&&s[1][cur]==s[1][f[1]]) cur++;
		char cc=s[1][cur-1];
		g[1]=cur-f[1];
		f[1]=cur;
		for (i=2;i<=n;i++)
		{
			cur=f[i];
			while (cur<l[i]&&s[i][cur]==s[i][f[i]]) cur++;
			if (s[i][cur-1]!=cc) return -1;
			g[i]=cur-f[i];
			f[i]=cur;
		}
		int mm=10000;
		for (j=1;j<=100;j++)
		{
			cur=0;
			for (i=1;i<=n;i++)
				if (g[i]>=j) cur=cur+g[i]-j;
				else cur=cur+j-g[i];
			if (cur<mm) mm=cur;
		}
		ret=ret+mm;
		for (i=1;i<=n;i++)
			if (f[i]==l[i]) break;
		if (i<=n) break;
	}
	for (i=1;i<=n;i++)
		if (f[i]!=l[i]) return -1;
	return ret;
}

int main()
{
	int t,p;
	int i;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%s",s[i]);
			l[i]=strlen(s[i]);
			f[i]=0;
		}
		i=solve();
		if (i==-1) printf("Case #%d: Fegla Won\n",p);
		else printf("Case #%d: %d\n",p,i);
	}
	return 0;
}

		
