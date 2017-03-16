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

int lol[17];

int main()
{
	int tc;
	scanf("%d",&tc);
	FOR(t,1,tc)
	{
		RESET(lol,0);
		int k;
		scanf("%d",&k);
		FOR(a,1,4)
		{
			FOR(b,1,4)
			{
				int p;
				scanf("%d",&p);
				if (a == k)
				{
					lol[p]++;
				}
			}
		}
		scanf("%d",&k);
		FOR(a,1,4)
		{
			FOR(b,1,4)
			{
				int p;
				scanf("%d",&p);
				if (a == k)
				{
					lol[p]++;
				}
			}
		}
		vector<int> ans;
		FOR(a,1,16)
		{
			if (lol[a] == 2) ans.pb(a);
		}
		printf("Case #%d: ",t);
		if (SIZE(ans) == 1) printf("%d\n",ans.back());
		else if (SIZE(ans) == 0) printf("Volunteer cheated!\n");
		else printf("Bad magician!\n");
	}
}
