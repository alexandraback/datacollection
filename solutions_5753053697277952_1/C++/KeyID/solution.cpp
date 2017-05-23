#include <bits/stdc++.h>
using namespace std;

const int SIGMA=26;

struct par
{
	int id,s;
}p[SIGMA];

vector <string> ans;

bool cmp(const par &a,const par &b)
{
	return a.s>b.s;
}

inline void solve()
{
	int n;
	scanf("%d",&n);
	ans.clear();
	for (int i=0;i<n;i++)
	{
		p[i].id=i;
		scanf("%d",&p[i].s);
	}
	sort(p,p+n,cmp);
	int tail=1;
	for (int i=0;i<n;i++)
		if (p[i].s>0)
		{
			while (tail<=i) tail++;
			for (;tail<n;tail++)
			{
				int t=min(p[i].s,p[tail].s);
				p[i].s-=t;
				p[tail].s-=t;
				for (int j=1;j<=t;j++)
				{
					string s;
					s+='A'+p[i].id;
					s+='A'+p[tail].id;
					ans.push_back(s);
				}
				if (p[i].s==0) break;
			}
			if (p[i].s>0)
			{
				while (p[i].s--)
				{
					string s;
					s+='A'+p[i].id;
					ans.push_back(s);
				}
			}
		}
	for (int i=ans.size()-1;i>=0;i--) cout << ans[i] << ' ';
	puts("");
}

int main()
{
	freopen("read.txt","r",stdin);
	freopen("write.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
