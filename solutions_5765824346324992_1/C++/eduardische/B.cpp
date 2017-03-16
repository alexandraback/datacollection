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
	static long long a[MAXN];
	for (iT = 0; iT < T; iT++)
	{
		long long N, what;
		scanf("%lli %lli",&N,&what);
		long long i;
		for (i = 0; i < N; i++)
		{
			scanf("%lli",&(a[i]));
		}
		long long L, R, C;
		L = 0; R = 1000000000000000LL;
		while (R > L)
		{
			C = (L+R+1) / 2LL;
			long long began = 0;
			for (i = 0; i < N; i++) began += (C + a[i] - 1) / a[i];
			if (began >= what) R = C-1;
			else L = C;
		}
		for (i = 0; i < N; i++) what -= (L + a[i] - 1) / a[i];
		long long res = 0;
		while (1)
		{
			if (!(L % a[res]))
			{
				what--;
				if (what == 0) break;
			}
			res++;
		}
		printf("Case #%d: %lli\n",iT+1,res+1);
	}
	return 0;
}
