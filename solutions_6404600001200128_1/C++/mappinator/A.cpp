#include <cstdio>
#include <iostream>
using namespace std;
int a[1001];
int main()
{
	int t, s=0;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i=1; i<=n; i++)
		{
			scanf("%d", &a[i]);
		}
		int y=0, z=0;
		for (int i=2; i<=n; i++)
		{
			y+=max(0, a[i-1]-a[i]);
		}
		int rate=0;
		for (int i=2; i<=n; i++)
		{
			rate=max(rate, a[i-1]-a[i]);
		}
		for (int i=2; i<=n; i++)
		{
			z+=min(rate, a[i-1]);
		}
		printf("Case #%d: %d %d\n", ++s, y, z);
	}
	return 0;
}