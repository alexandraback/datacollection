#include <iostream>
#include <cstdio>

using namespace std;
const int Maxn = 1010;
int n;
int a[Maxn];
int main() 
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		scanf("%d", &n);
		int ans1 = 0, ans2 = 0;
		int minRate = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			if (i > 0 && a[i] < a[i - 1]) {
				int diff = a[i - 1] - a[i];
				ans1 += diff;
				minRate = max(minRate, diff);
			}
		}
		if (minRate != 0)
		{
			
			for (int i = 0; i < n - 1; ++i) {
				ans2 += min(minRate, a[i]);
				
			}
		}
		printf("Case #%d: %d %d\n", cas, ans1, ans2);
		
	}
	return 0;
}