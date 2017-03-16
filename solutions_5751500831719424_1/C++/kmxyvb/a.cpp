#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define MAXN 110
#define MAXS 110

int _[MAXN],L[MAXN],Ans,c[MAXN],TestCase,Case,n;

char s[MAXN][MAXS],Chr;

int main()
{
	int i,k;
//	freopen("a.in","rb",stdin);
//	freopen("a.out","wb",stdout);
	scanf("%d",&TestCase);
	for(Case=1;Case<=TestCase;Case++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		memset(_,0,sizeof _);
		for(i=0;i<n;i++)
			L[i]=strlen(s[i]);
		for(Ans=0;;)
		{
			for(i=0;i<n;i++)
				if(_[i]<L[i])
					break;
			if(i==n)
			{
				printf("Case #%d: %d\n",Case,Ans);
				break;
			}
			if(i)
			{
				printf("Case #%d: Fegla Won\n",Case);
				break;
			}
			Chr=s[i][_[i]];
			for(i=0;i<n;i++)
			{
				for(c[i]=0;_[i]<L[i]&&s[i][_[i]]==Chr;_[i]++,c[i]++);
				if(!c[i])break;
			}
			if(i<n)
			{
				printf("Case #%d: Fegla Won\n",Case);
				break;
			}
			std::sort(c,c+n);
			for(i=0,k=n/2;i<n;i++)
				Ans+=abs(c[k]-c[i]);
		}
	}
	return 0;
}
