#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<climits>
#include<complex>
#include<cassert>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)((x).size())
#define all(x) x.begin(),x.end()
#define clr(x) memset((x),0,sizeof(x))
#define cdp(x) memset((x),-1,sizeof(x))
#define rep(i,n) for (i=0;i<n;i++)
#define Rep(i,a,b) for (i=a;i<=b;i++)
#define ff(i,x) for (i=start[x];i!=-1;i=a[i].next)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
int dblcmp(double d){if (fabs(d)<eps)return 0;return d>eps?1:-1;}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
vi a[4],b[4];
int main()
{
	int i,j,k,cas,cc=0;
	freopen("C:\\competition\\gcj\\A-small-attempt0.in","r",stdin);
	freopen("C:\\competition\\gcj\\A.out","w",stdout);
	scanf("%d",&cas);
	while (cas--)
	{
		int x,y;
		scanf("%d",&x);x--;
		map<int,int>p;
		for (i=0;i<4;i++)
		{
			a[i].clear();
			for (j=0;j<4;j++)
			{
				scanf("%d",&k);
				a[i].pb(k);
				if (i==x)p[k]++;
			}
		}
		scanf("%d",&y);y--;
		for (i=0;i<4;i++)
		{
			b[i].clear();
			for (j=0;j<4;j++)
			{
				scanf("%d",&k);
				b[i].pb(k);
				if (i==y)p[k]++;
			}
		}
		printf("Case #%d: ",++cc);
		if (sz(p)==8)puts("Volunteer cheated!");
		else if (sz(p)<7)puts("Bad magician!");
		else 
		{
			foreach(e,p)
			{
				if (e->se==2)
				{
					printf("%d\n",e->fi);
					break;
				}
			}
		}
	}
	return 0;
}
		