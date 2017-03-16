#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define MAXN 1010

int mush[MAXN];

int main()
{
	int T;
	int n;
	int res1, res2;
	int ca = 0;
	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &mush[i]);
		}
		res1 = 0;
		for (int i = 1; i < n; ++i)
		{
			if(mush[i] < mush[i - 1])
				res1 += (mush[i - 1] - mush[i]);
		}
		int rate = 0;
		for (int i = 0; i < n; ++i)
		{
			rate = max(rate, mush[i - 1] - mush[i]);
		}
		res2 = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			res2 += min(mush[i], rate);
		}
		
		printf("Case #%d: %d %d\n", ++ca, res1, res2);
	}
	return 0;
}