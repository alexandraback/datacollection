#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
struct LIST
{
	int L;
	char A[101];
}list[101];
int N,M;
int X[101];
int Y[101];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,T;
	char c;
	int flag;
	int Ans;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		Ans=0;
		scanf("%d",&N);
		int i,j;
		for(i=1;i<=N;i++)
		{
			scanf("%s",&list[i].A[1]);
			list[i].L=strlen(&list[i].A[1]);
			X[i]=1;
		}
		flag=0;
		while(X[1]<=list[1].L)
		{
			c=list[1].A[X[1]];
			for(i=1;i<=N;i++)
			{
				Y[i]=0;
				for(;X[i]<=list[i].L;X[i]++)
				{
					if(list[i].A[X[i]]!=c) break;
					Y[i]++;
				}
				if(Y[i]==0) flag=1;
			}
			std::sort(Y+1,Y+1+N);
			for(i=1;i<=N;i++) Ans+=abs(Y[i]-Y[N/2+1]);
		}
		for(i=1;i<=N;i++) if(X[i]!=list[i].L+1) flag=1;
		printf("Case #%d: ",t);
		if(flag) printf("Fegla Won\n");
		else printf("%d\n",Ans);
	}
}