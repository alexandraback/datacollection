#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;
typedef int LL;
LL MX(LL a,LL b){return (a>b)?a:b;}
LL MN(LL a,LL b){return (a<b)?a:b;}
LL ABS(LL a){return (a<0)?-1*a:a;}
#define INF 999999999

char str[102][103],chunk[103],tem[103];
LL seg[103][103],n,range[103],len,memo[103];
LL dp(LL pos)
{
	if(pos==len) return 0;
	LL &ret=memo[pos];
	if(ret!=-1) return ret;
	ret=INF;
	LL i,j,val;
	for(i=1;i<=range[pos];i++)
	{
		val=0;
		for(j=0;j<n;j++)
		{
			val+=ABS(i-seg[j][pos]);
		}
		ret=MN(ret,val+dp(pos+1));
	}
	return ret;
}
int main()
{
	LL t,cas=0,ans,i,j,id,flag,cnt;
	freopen("A-small-attempt1.in","r",stdin);
	freopen("out.in","w",stdout);
//	printf("%d\n",strcmp("AB","Ac"));
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",str[i]);
		}
		memset(seg,0,sizeof(seg));
		memset(range,0,sizeof(range));
		len=strlen(str[0]);
		id=0;
		cnt=1;
		chunk[id++]=str[0][0];
		for(j=1;j<len;j++)
		{
			if(str[0][j-1]!=str[0][j])
			{
				seg[0][id-1]=cnt;
				cnt=1;
				chunk[id++]=str[0][j];
			}
			else cnt++;
		}
		seg[0][id-1]=cnt;
		chunk[id]='\0';
		for(i=1;i<n;i++)
		{
			flag=0;
			len=strlen(str[i]);
			id=0;
			cnt=1;
			tem[id++]=str[i][0];
			for(j=1;j<len;j++)
			{
				if(str[i][j-1]!=str[i][j])
				{
					seg[i][id-1]=cnt;
					tem[id++]=str[i][j];
				}
				else cnt++;
			}
			seg[i][id-1]=cnt;
			tem[id]='\0';
			if(strcmp(chunk,tem)==0) flag=1;
			if(flag==0)break;
		}
		if(flag==0)
		{
			printf("Case #%d: Fegla Won\n",++cas);
			continue;
		}
		ans=0;
		len=id;
		for(i=0;i<n;i++)
		{
			for(j=0;j<id;j++) range[j]=MX(seg[i][j],range[j]);
		}
		memset(memo,-1,sizeof(memo));
		ans=dp(0);
		printf("Case #%d: %d\n",++cas,ans);
	}
	return 0;
}