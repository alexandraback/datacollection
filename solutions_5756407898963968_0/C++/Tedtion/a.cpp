#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;
#define NN 1000

int main()
{
	int t, i, j;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &t);
	for (int cas=1; cas<=t; cas++)
	{
		int r, tmp, s[5];
		set<int> f;
		scanf("%d",&r);
		for (i=1; i<=4; i++)
		{
			for (j=0; j<4; j++) {
				scanf("%d", &tmp);
				if (i==r) f.insert(tmp);
			}
		}
		scanf("%d",&r);
		for (i=1; i<=4; i++)
		{
			for (j=0; j<4; j++) {
				if (i==r) scanf("%d", s+j);
				else scanf("%d", &tmp);
			}
		}
		int ans=-1;
		for (i=0; i<4; i++) {
			if (f.count(s[i])) {
				if (ans==-1) ans=s[i];
				else ans=-2;
			}
		}
		if (ans==-1) printf("Case #%d: Volunteer cheated!\n", cas);
		else if (ans==-2) printf("Case #%d: Bad magician!\n", cas);
		else printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}

