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

const int Maxn = 1100;

int M[Maxn];
int64 B, N;

bool check(int64 mid)
{
	int64 res = 0;
	for (int i=0;i<B;++i)
	{
		res += mid/M[i];
		if (mid % M[i] > 0) ++ res;
	}
	return res <= N-1;
}

int findAns(int64 _time, int64 kth)
{
	for (int i=0;i<B;++i)
		if (_time % M[i] == 0)
		{
			-- kth;
			if (kth == 0) return i + 1;
		}
	return -1;
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int ii=0;ii<T;++ii)
	{
		scanf("%lld%lld", &B, &N);
		for (int i=0;i<B;++i)
			scanf("%d",&M[i]);

		int64 l=0, r=1000000000000000LL;
		for (;l<r;)
		{
			int64 mid = (l+r)/2+1;
			if (check(mid))
			{
				l = mid;
			}
			else
			{
				r = mid - 1;
			}
		}

		int64 cnt = 0;
		for (int i=0;i<B;++i)
		{
			cnt += l / M[i];
			if (l % M[i] > 0) ++ cnt;
		}
		printf("Case #%d: %d\n", ii+1, findAns(l, N - cnt));
	}
	return 0;
}