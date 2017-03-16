/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;

int can[20],_,x,y;

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&_);
	for(int ca=1;ca<=_;ca++)
	{
		memset(can,0,sizeof(can));
		scanf("%d",&x);
		for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{
			scanf("%d",&y);
			if(i==x)
			can[y]+=1;
		}
		scanf("%d",&x);
		for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{
			scanf("%d",&y);
			if(i==x)
			can[y]+=2;
		}
		int ans=-1,cnt=0;
		for(int i=1;i<=16;i++)
		if(can[i]==3)ans=i,cnt++;
		printf("Case #%d: ",ca);
		if(cnt==1)printf("%d\n",ans);
		else if(cnt>1)printf("Bad magician!\n");
		else printf("Volunteer cheated!\n");
	}
	return 0;
}
