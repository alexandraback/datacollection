#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

const int maxn = 105;

struct node
{
	string s,ya;
	vector<int> v;
	void go()
	{
		ya.clear();v.clear();
		ya += s[0];
		for(int i=1;i<s.size();i++)
		{
			if(s[i]!=s[i-1])
				ya += s[i];
		}
		int pl = 0,pr,cnt;
		for(int i=0;i<ya.size();i++)
		{
			pr = pl,cnt = 1;
			while(pr<s.size()-1&&s[pr+1]==ya[i])
				pr++,cnt++;
			v.push_back(cnt);
			pl = pr + 1;
		}
	}
}ji[maxn];

const int inf = 1<<29;

int n;

int zh(int p)
{
	int res = inf;
	for(int i=1;i<=n;i++)
	{
		int sum  = 0;
		for(int j=1;j<=n;j++)
			sum += abs(ji[j].v[p]-ji[i].v[p]);
		res = min(res,sum);
	}
	return res;
}
void sol()
{
	for(int i=2;i<=n;i++)
	{
		if(ji[i].ya!=ji[1].ya)
		{
			puts("Fegla Won");
			return;
		}
	}
	int cnt = 0;
	int le = ji[1].ya.size();
	for(int i=0;i<le;i++)
	{
		cnt += zh(i);
	}
	printf("%d\n",cnt);
}
int main()
{
	int t,cas=0;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d: ",++cas);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			cin>>ji[i].s,ji[i].go();
		sol();
	}
}
