#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define MAXN 1005

using namespace std;

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static int a[MAXN];
	for (iT = 0; iT < T; iT++)
	{
		int N;
		scanf("%d",&N);
		int i;
		for (i = 0; i < N; i++) scanf("%d",&(a[i]));
		int max = 0;
		int sum = 0;
		for (i = 0; i+1 < N; i++)
		{
			int cur = a[i] - a[i+1];
			if (cur < 0) cur = 0;
			if (cur > max) max = cur;
			sum += cur;
		}
		int res = 0;
		for (i = 0; i+1 < N; i++)
		{
			res += min(a[i], max);
		}
		printf("Case #%d: %d %d\n",iT+1,sum,res);
	}
	return 0;
}
