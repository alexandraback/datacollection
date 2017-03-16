#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAXN 101

using namespace std;

vector<int> a[MAXN];
string s[MAXN];
int cnt[MAXN];

int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			cin>>s[i];
			a[i].clear();
		}
		string std="";
		for (int j=0;j<s[0].length();j++)
			if (j==0 || s[0][j]!=s[0][j-1]) std+=s[0][j];
		int flag=1;
		for (int i=0;i<n;i++)
		{	
			int pos=0;
			for (int j=0;j<std.length();j++)
			{
				if (s[i][pos]!=std[j]) flag=0;
				int tmp=0;
				while (pos<s[i].length() && std[j]==s[i][pos]) tmp++,pos++;
				a[i].push_back(tmp);
			}
		}
		if (flag)
		{
			int ans=0;
			for (int j=0;j<std.length();j++)
			{
				for (int i=0;i<n;i++)
					cnt[i]=a[i][j];
				sort(cnt,cnt+n);
				for (int i=0;i<n;i++)
					ans+=abs(cnt[i]-cnt[n/2]);
			}
			printf("Case #%d: %d\n",t,ans);
		}
		else printf("Case #%d: Fegla Won\n",t);
	}
	return 0;
}
