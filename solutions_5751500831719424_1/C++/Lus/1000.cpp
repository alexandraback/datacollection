#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#define maxn 200
using namespace std;
int n,t;
char ch[maxn][maxn];
vector<int> ans;
vector<pair<char,int> > vec[maxn];
void init()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%s",ch[i]);
}

int iabs(int x){return x>0? x: -x;}
int solve()
{

	for(int i=0;i<n;++i)
	{
		vec[i].clear();
		char c=ch[i][0];int ct=1;
		for(int j=1;ch[i][j];++j)
		{
			if(ch[i][j]==ch[i][j-1]) ++ct;
			else 
			{
				vec[i].push_back(make_pair(c,ct));
				ct=1;
				c=ch[i][j];
			}
		}
		vec[i].push_back(make_pair(c,ct));
	}
	int siz=vec[0].size(),ret=0;
	for(int i=0;i<n;++i) if(vec[i].size()!=siz) return -1;
	for(int i=0;i<siz;++i)
	{
		ans.clear();
		ans.push_back(vec[0][i].second);
		for(int j=1;j<n;++j)
		{
			if(vec[j][i].first!=vec[j-1][i].first) return -1;
			ans.push_back(vec[j][i].second);
		}
		sort(ans.begin(),ans.end());
		int mid=ans[ans.size()/2];
		for(int j=0;j<ans.size();++j) ret+=iabs(ans[j]-mid);
	}
	return ret;
}
int ca=1;
int main()
{
	freopen("1000L.in","r",stdin);
	freopen("1000L.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		init();
		int ret=solve();
		printf("Case #%d: ",ca++);
		if(ret==-1) puts("Fegla Won");
		else printf("%d\n",ret);
	}
	return 0;
}
