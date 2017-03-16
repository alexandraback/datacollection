#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
char map[110][110];
int k[110][110];
char ch[110][110];
int s[110],ans,top[110];
bool check()
{
	int i,j;
	for(i=2;i<=n;++i)
	{
		if(top[i]!=top[1])
			return 1;
		for(j=1;j<=top[1];++j)
			if(ch[i][j]!=ch[1][j])
				return 1;
	}
	return 0;
}
int main()
{
	int t,tt,i,j;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&t);
	for(tt=1;tt<=t;++tt)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			top[i]=0;
		for(i=1;i<=n;++i)
		{
			scanf("%s",map[i]+1);
			for(j=1;map[i][j];++j)
				if(map[i][j]==map[i][j-1])
					++k[i][top[i]];
				else
				{
					ch[i][++top[i]]=map[i][j];
					k[i][top[i]]=1;
				}
		}
		if(check())
			printf("Case #%d: Fegla Won\n",tt);
		else
		{
			ans=0;
			for(i=1;i<=top[1];++i)
			{
				for(j=1;j<=n;++j)
					s[j]=k[j][i];
				sort(s+1,s+n+1);
				for(j=1;j<=n;++j)
					if(s[j]>s[n/2+1])
						ans+=s[j]-s[n/2+1];
					else
						ans+=s[n/2+1]-s[j];
			}
			printf("Case #%d: %d\n",tt,ans);
		}
	}
	//while(1);
	return 0;
}
