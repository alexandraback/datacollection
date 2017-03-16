#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define pb push_back
#define sz(a) ((int)(a).size())
#define mp make_pair
#define fi first
#define se second

typedef pair<int,int> pint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;


char s[105][105];
int l[105];
int n;
vector<pair<char,int> > g[105]; 

int absv(int a)
{
	if (a<0) return -a;
	return a;
}

int check(vi &a, int v)
{
	int ans=0;
	for (int i=0; i<sz(a); i++)
		ans+=absv(a[i]-v);
	return ans;
}

int main()
{
	int tc,ans;
	scanf("%d",&tc);
	for (int x=1; x<=tc; x++)
	{
		scanf("%d",&n);
		for (int i=0; i<n; i++)
		{
			scanf("%s",s[i]),l[i]=strlen(s[i]);
			char p='A',cnt=0;
			g[i].clear();
			for (int j=0; j<l[i]; j++)
			{
				if (s[i][j]!=p)
				{
					if (p!='A')
						g[i].pb(mp(p,cnt));
					cnt=0;
					p=s[i][j];
				}
				cnt++;
			}
			g[i].pb(mp(p,cnt));
		}
		bool work=true;
		for (int i=0; i<n; i++)
			for (int j=i+1; j<n; j++)
				work&=sz(g[i])==sz(g[j]);
		if (work)
		{
			ans=0;
			for (int i=0; i<n; i++)
				for (int j=i+1; j<n; j++)
					for (int k=0; k<sz(g[i]); k++)
						work&=g[i][k].fi==g[j][k].fi;
			if (work)
			{
				for (int i=0; i<sz(g[0]); i++)
				{
					vi v;
					for (int j=0; j<n; j++)
						v.pb(g[j][i].se);
					sort(all(v));
					int best=10000000;
					for (int i=v[0]; i<=v[sz(v)-1]; i++)
						best=min(best,check(v,i));
					ans+=best;
				}
			}
		}
		if (work)
			printf("Case #%d: %d\n",x,ans);
		else
			printf("Case #%d: Fegla Won\n",x);
	}
	return 0;
}
