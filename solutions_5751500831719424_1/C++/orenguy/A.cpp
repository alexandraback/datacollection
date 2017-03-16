#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <deque>
#include <ctime>
#include <list>
#include <set>
#include <map>
//zlb//

using namespace std;

typedef long long     LL;
typedef pair<int,int> pii;

double PI  = acos(-1);
double EPS = 1e-7;
int INF    = 1000000000;
int MOD    = 1000000007;
int MAXINT = 2147483647;
LL INFLL   = 1000000000000000000LL;
LL MAXLL   = 9223372036854775807LL;

#define fi            first
#define se            second
#define mp            make_pair
#define pb            push_back
#define SIZE(a)       (int)a.size()
#define MIN(a, b)     (a) = min((a), (b))
#define MAX(a, b)     (a) = max((a), (b))
#define input(in)     freopen(in,"r",stdin)
#define output(out)   freopen(out,"w",stdout)
#define RESET(a, b)   memset(a,b,sizeof(a))
#define FOR(a, b, c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a, b, c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a, b)   for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); a++)

int mx[8] = {-1,1,0,0,-1,-1,1,1};
int my[8] = {0,0,-1,1,-1,1,-1,1};

// ------------ //

vector<int> oc[105];
vector<char> c[105];
char s[10000];

int main()
{
	int t,tc=0;
	scanf("%d",&t);
	while(t--)
	{
		tc++;
		int n;
		scanf("%d",&n);
		FOR(a,1,n)
		{
			oc[a].clear();
			c[a].clear();
		}
		FOR(a,1,n)
		{
			scanf("%s",s);
			int len = strlen(s);
			FOR(b,0,len-1)
			{
				if (b == 0 || s[b] != s[b-1])
				{
					oc[a].pb(1);
					c[a].pb(s[b]);
				}
				else oc[a].back()++;
			}
		}
		bool fail = 0;
		FOR(a,2,n)
		{
			if (SIZE(oc[a]) != SIZE(oc[1]))
			{
				fail = 1;
			}
			else
			{
				FOR(b,0,SIZE(oc[a])-1)
				{
					if (c[a][b] != c[1][b])
					{
						fail = 1;
						break;
					}
				}
			}
		}
		printf("Case #%d: ",tc);
		if (fail) puts("Fegla Won");
		else
		{
			int ans = 0;
			FOR(a,0,SIZE(oc[1])-1)
			{
				vector<int> v;
				FOR(b,1,n)
				{
					v.pb(oc[b][a]);
				}
				sort(v.begin(),v.end());
				int mid = v[(SIZE(v)-1)/2];
				FOR(b,1,n)
				{
					ans += abs(oc[b][a]-mid);
				}
			}
			printf("%d\n",ans);
		}
	}
}
