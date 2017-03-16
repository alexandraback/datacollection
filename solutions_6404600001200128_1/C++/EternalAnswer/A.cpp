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

int a[1100];

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int ii=0;ii<T;++ii)
	{
		int N;
		scanf("%d", &N);
		int res1 = 0, res2 = 0;
		int maxInt = 0;
		for (int i=0;i<N;++i)
		{
			scanf("%d", &a[i]);
			if (i > 0 && a[i] < a[i - 1]) res1 += a[i - 1] - a[i];
			if (i > 0) maxInt = max(maxInt, a[i - 1] - a[i]);
		}
		for (int i=0;i<N-1;++i)
		{
			res2 += min(a[i], maxInt);
		}
		printf("Case #%d: %d %d\n", ii+1, res1, res2);
	}

	return 0;
}