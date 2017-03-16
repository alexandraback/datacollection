#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define int64 long long
#define Sort sort

using namespace std;

const double pi = 3.14159265359;
const double eps = 1e-7;

int x[3100], y[3100];
double angle[6100];
int N;

int main()
{
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.out", "w", stdout);
	//freopen("x.in","r",stdin);
	int T;
	scanf("%d", &T);
	for (int ii=0;ii<T;++ii)
	{
		printf("Case #%d: \n", ii + 1);
		scanf("%d", &N);
		for (int i=0;i<N;++i)
			scanf("%d%d", &x[i], &y[i]);
		for (int i=0;i<N;++i)
		{
			int tot = 0;
			for (int j=0;j<N;++j)
				if (i != j)
				{
					angle[tot ++] = atan2(y[j] - y[i], x[j] - x[i]);
				}
			sort(angle, angle + tot);
			for (int j=0;j<tot;++j)
				angle[j + tot] = angle[j] + pi * 2.0;
			int ans = 999999999;
			if (tot == 0) ans = 0;
			for (int l=0,r=0;l<tot;++l)
			{
				for (;r < l + tot && angle[r] < angle[l] + pi - eps;++r);
				ans = min(ans, r - l - 1);
			}
			printf("%d\n", ans);
		}
	}

	return 0;
}