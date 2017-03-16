#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[100000];

int main()
{
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas)
	{
		int delta = 0, n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &arr[i]);
		for(int i = 1; i < n; ++i)
			delta = max(delta, arr[i] - arr[i + 1]);
		int ans1 = 0, ans2 = 0;
		for(int i = 1; i < n; ++i)
		{
			if(arr[i + 1] < arr[i])
				ans1 += arr[i] - arr[i + 1];
			if(arr[i] <= delta)
				ans2 += arr[i];
			else
				ans2 += delta;
		}
		printf("Case #%d: %d %d\n", cas, ans1, ans2);
	}
	return 0;
}