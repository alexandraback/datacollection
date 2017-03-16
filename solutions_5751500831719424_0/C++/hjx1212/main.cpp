#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char a[105][105],b[105];
int c[105][105];

int main()
{
	freopen("E:/in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,t,n,m,i,j,k,kk,s,ln,rn;
	char l;
	for(scanf("%d",&T),t=1;t<=T;t++)
	{
		memset(c,0,sizeof(c));
		printf("Case #%d: ",t);
		for(scanf("%d",&n),i=0;i<n;i++)
			scanf("%s",a[i]);
		for(l=m=i=0;a[0][i];i++)
			if(a[0][i]!=l)
				b[m++]=l=a[0][i];
		b[m]=0;
		for(i=0;i<n;i++)
		{
			for(kk=k=j=0;j<m;j++)
			{
				while(a[i][k]==b[j])
					k++;
				if(k==kk)
					break;
				c[j][k-kk]++;
				kk=k;
			}
			if(j<m||a[i][k])
				break;
		}
		if(i<n)
		{
			puts("Fegla Won");
			continue;
		}
		for(s=i=0;i<m;i++)
		{
			for(k=ln=rn=0,j=1;j<=100;j++)
				rn+=c[i][j],k+=c[i][j]*j;
			for(kk=1<<30,j=1;j<=100;j++)
			{
				k-=rn;
				k+=ln;
				rn-=c[i][j];
				ln+=c[i][j];
				kk=min(kk,k);
			}
			s+=kk;
		}
		printf("%d\n",s);
	}
	return 0;
}
