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


char s[2][105];
int l[2];
int n;
vector<pair<char,int> > g[2]; 

int absv(int a)
{
	if (a<0) return -a;
	return a;
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
		bool work=sz(g[0])==sz(g[1]);
		ans=0;
		if (work)
		{
			for (int i=0; work&&i<sz(g[0]); i++)
				work&=g[0][i].fi==g[1][i].fi;
			if (work)
			{
				for (int i=0; i<sz(g[0]); i++)
					ans+=absv(g[0][i].se-g[1][i].se);
			}
		}
		if (work)
			printf("Case #%d: %d\n",x,ans);
		else
			printf("Case #%d: Fegla Won\n",x);
	}
	return 0;
}
