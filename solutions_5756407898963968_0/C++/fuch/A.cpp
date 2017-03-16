#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <functional>

#define rep(i,n) for(int i=0;i<(n);++i)
#define foreach(i,v) for(__typeof(v.begin()) i=v.begin();i!=v.end();++i)
#define ass(v) (v)||++*(int*)0;

using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<double> VD;
typedef long long LL;

int main()
{
	int t;
	scanf("%d", &t);
	for (int cs = 1; cs <= t; ++cs)
	{
		bool u[16] = { };
		int r1, r2;
		scanf("%d", &r1);
		for (int r = 1; r <= 4; ++r)
		{
			for (int c = 1; c <= 4; ++c)
			{
				int a;
				scanf("%d", &a);
				if (r == r1) u[a - 1] = true;
			}
		}

		int cnt = 0, ans = -1;

		scanf("%d", &r2);
		for (int r = 1; r <= 4; ++r)
		{
			for (int c = 1; c <= 4; ++c)
			{
				int a;
				scanf("%d", &a);
				if (r == r2 && u[a - 1])
				{
					++cnt;
					ans = a;
				}
			}
		}

		printf("Case #%d: ", cs);
		if (cnt == 0) puts("Volunteer cheated!");
		else if (cnt == 1) printf("%d\n", ans);
		else puts("Bad magician!");
	}
	return 0;
}
