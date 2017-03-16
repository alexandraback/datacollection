#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int n,ans[200],fans,nn,last[200];
char s[200][200],fs[200];

bool check()
{
	int len=strlen(s[1]+1),l=0;
	for (int i=1;i<=len;i++)
		if (s[1][i]!=s[1][i-1])
			fs[++l]=s[1][i];
	nn=l;
	for (int j=1;j<=n;j++)
	{
		len=strlen(s[j]+1);
		l=0;
		for (int i=1;i<=len;i++)
			if (s[j][i]!=s[j][i-1])
				if (s[j][i]!=fs[++l]) return true;
		if (l!=nn) return true;
	}
	return false;
}

int main()
{
	//freopen("1.in","r",stdin);
	int t,cs=0;
	scanf("%d",&t);
	while (t--)
	{
		printf("Case #%d: ",++cs);
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		if (check()) 
		{
			puts("Fegla Won");
			continue;
		}
		fans=0;
		//puts(fs+1);
		//printf("%d\n",nn);
		for (int i=1;i<=n;i++) last[i]=1;
		for (int i=1;i<=nn;i++)
		{
			for (int j=1;j<=n;j++)
			{
				int len=strlen(s[j]+1);
				ans[j]=0;
				for (int k=last[j];k<=len;k++)
					if (s[j][k]==fs[i]) ans[j]++;else {last[j]=k;break;}
			}
			sort(ans+1,ans+n+1);
			for (int j=1;j<=n;j++)
				fans+=abs(ans[j]-ans[(n+1)/2]);
		}
		printf("%d\n",fans);
	}
	return 0;
}