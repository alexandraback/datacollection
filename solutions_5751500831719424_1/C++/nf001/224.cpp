#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <string>
using namespace std;

#define ll long long
#define eps 1e-8
#define inf 0x3f3f3f3f

char s[10001];
string s0,hehe;
int p[110][1100];
int main()
{
 	freopen("a.in","r",stdin);
 	freopen("a.out","w",stdout);
	int T,cas=0,n,t;
	cin>>T;
	while (T--)
	{
		scanf("%d",&n);
		int no=0;
		hehe="";
		for (int i=1;i<=n;i++)
		{
			scanf("%s",s);
			int len=strlen(s);
			s0="";
			s0+=s[0];
			int cnt=1;
			t=0;
			for (int j=1;j<len;j++)
				if (s[j]!=s[j-1])
				{
					s0+=s[j];
	//				cout<<cnt<<endl;
					p[i][++t]=cnt;
					cnt=1;
				}
				else
				{
					cnt++;
				}
			p[i][++t]=cnt;
			if (s0!=hehe&&hehe!="")
				no=1;
			hehe=s0;
//			cout<<s0<<endl;
		}
		int ans=0;
		printf("Case #%d: ",++cas);
		if (no)
		{
			printf("Fegla Won\n");
		}
		else
		{
			for (int i=1;i<=t;i++)
			{
				int ans0=inf;
				for (int j=1;j<=n;j++)
				{
					int mid=p[j][i];
					int tmp=0;
					for (int k=1;k<=n;k++)
					{
						tmp+=abs(p[k][i]-mid);
					}
					ans0=min(ans0,tmp);
				}
				ans+=ans0;
			}
			cout<<ans<<endl;
		}
	}
}