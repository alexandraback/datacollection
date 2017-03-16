#include <stdio.h>
#include <algorithm>

int nums[2000];
int main()
{
	int T;
	scanf("%d", &T);
	for(int ca = 1; ca <= T; ++ca)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", nums + i);
		// case 1
		int ret1 = 0;
		for(int i = 1; i < n; ++i)
			ret1 += std::max(0, nums[i - 1] - nums[i]);
		// case 2
		int rat = 0;
		for(int i = 1; i < n; ++i)
			rat = std::max(rat, nums[i - 1] - nums[i]);
		int ret2 = 0;
		for(int i = 0; i < n - 1; ++i)
			ret2 += std::min(rat, nums[i]);
		printf("Case #%d: %d %d\n", ca, ret1, ret2);
	}
}
