#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
int N;
int ma;
int cost(int c[100],int v)
	{
		int i;
	int cnt=0;
	for(i=0;i<N;i++)
		{
		cnt+=abs(c[i]-v);
		}
	return cnt;
	}
int TS(int c[100],int s,int e)
	{
	int mid1;
	int mid2;
	while(e-s>3)
		{
//		printf("%d %d\n",s,e);
		mid1=(2*s+e)/3;
		mid2=(2+e*2)/3;
		if(cost(c,mid1)>cost(c,mid2))
			{
			s=mid1+1;
			}
		else
			{
			e=mid2-1;
			}
		}
	s=min(s,e);
	return s-1;
	}
int solve(int c[100])
	{
	int i;
	if(false)
		{
		int i=TS(c,1,ma);
//		printf("i%d\n",i);
		int minc=cost(c,i);
		minc=min(cost(c,i+1),minc);
		minc=min(cost(c,i+2),minc);
		minc=min(cost(c,i+3),minc);
		minc=min(cost(c,i+4),minc);
		return minc;
		}
	else
		{
		int minc1=cost(c,1);
		for(i=2;i<=ma;i++)
			minc1=min(cost(c,i),minc1);
			return minc1;
		}
//	if(minc1!=minc)
//		printf("fucked! %d\n",minc1);
//	return minc1;
	}
int main()
{
int T;
freopen("i.txt","r",stdin);
freopen("o.txt","w",stdout);
scanf("%d",&T);
char s[100][200];
int i,h,j,k;

for(int t=0;t<T;t++)
	{
	int p[200]={0};
	
	int ans=0;
	scanf("%d\n",&N);
	for(i=0;i<N;i++)
		{
		gets(s[i]);
		}
	int f=0;
	for(p[0]=0;s[0][p[0]];)
		{
		ma=-1;
//		printf("f%c%df\n",s[0][p[0]],p[0]);
		char x=s[0][p[0]];
		int c[200]={0};
		for(;s[0][p[0]]==x;p[0]++)c[0]++;
		for(j=1;j<N;j++)
			{
			for(;s[j][p[j]]==x;p[j]++)
				c[j]++;	
			if(c[j]==0)
				{
				s[0][p[0]]=0;
				f=1;
				break;
				}
			ma=max(c[j],ma);
			}
		ans+=solve(c);
		}
	
	for(i=0;i<N;i++)
		{
		if(s[i][p[i]]!=0)
			f=1;
		}
	printf("Case #%d: ",t+1);

	if(f==1)
		{
		printf("Fegla Won\n");
		}
	else
		{
		printf("%d\n",ans);
		}
	//printf("%d",)
	}	
return 0;
}
