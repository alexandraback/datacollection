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

const int oo=1000000000;

const int V=120;
char s[V][V];
char x[V][V];
int l[V],cnt[V][V],df[V],_,n;

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&_);
	for(int ca=1;ca<=_;ca++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		scanf("%s",s[i]);
		for(int i=0;i<n;i++)
		l[i]=strlen(s[i]);
		for(int i=0;i<n;i++)
		{
			df[i]=0;
			x[i][0]=s[i][0];
			cnt[i][0]=1;
			for(int j=1;j<l[i];j++)
			{
				if(s[i][j]==s[i][j-1])
				{
					cnt[i][df[i]]++;
				}
				else
				{
					df[i]++;
					x[i][df[i]]=s[i][j];
					cnt[i][df[i]]=1;
				}
			}
			df[i]++;
		}
		bool can=true;
		for(int i=0;i<n;i++)
		if(df[i]!=df[0])can=false;
		if(can)
		{
			for(int i=0;i<df[0];i++)
			for(int j=0;j<n;j++)
			if(x[j][i]!=x[0][i])
			can=false;
		}
		printf("Case #%d: ",ca);
		if(!can)
		{
			puts("Fegla Won");
			continue;
		}
		int ret=0;
		for(int i=0;i<df[0];i++)
		{
			for(int j=0;j<n;j++)l[j]=cnt[j][i];
			sort(l,l+n);
			for(int j=0;j<n/2;j++)
			ret+=l[n/2]-l[j];
			for(int j=n/2;j<n;j++)
			ret+=l[j]-l[n/2];
		}
		printf("%d\n",ret);
	}
	return 0;
}
