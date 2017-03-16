#include<iostream>
#include<cstdio>
#include<algorithm>
#include<time.h>
#include<cmath>
#include<set>
#include<vector>
#include<cstring>
#include<string>
#define bug puts("here!")
#define maxn 150
using namespace std;
#define ll long long
#define inf 1e17
int mod;
#define vec vector<int>
#define mat vector<vec>
int T,n;
string str[maxn*2];
int len[maxn];
vec res[maxn];
int main()
{
	freopen("C:\\Users\\Administrator\\Desktop\\A-small-attempt0.in","r",stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\D.txt","w",stdout);
	scanf("%d",&T);
	int kase=1;
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			cin>>str[i];
		for(int i=1;i<=n;++i)
			len[i]=str[i].length();
		for(int i=1;i<=n;++i)
		{
			str[i+n]="";
			str[i+n]+=str[i][0];
			for(int j=1;j<len[i];++j)
				if(str[i][j]!=str[i][j-1])
					str[i+n]+=str[i][j];
		}
		bool flag=1;
		for(int i=2;i<=n;++i)
			if(str[n+1]!=str[i+n])
				flag=0;
		printf("Case #%d: ",kase++);
		if(!flag)
		{
			printf("Fegla Won\n");
			continue;
		}
		int l=str[1+n].length();
		for(int i=0;i<l;++i)
			res[i].clear();
		for(int i=1;i<=n;++i)
		{
			int cnt=1;
			int now=0;
			for(int j=1;j<len[i];++j)
				if(str[i][j]!=str[i][j-1])
					res[now].push_back(cnt),cnt=1,now++;
				else cnt++;
			res[now].push_back(cnt);
		}
		int ans=0;
		int mid=n/2;
		//printf("%d\n",l);
		for(int i=0;i<l;++i)
		{
			sort(res[i].begin(),res[i].end());
			for(int j=0;j<n;++j)
			{
				//printf("%d ",res[i][j]);
				ans+=abs(res[i][mid]-res[i][j]);
			}
			//printf("\n");
		}
		printf("%d\n",ans);
	}
}