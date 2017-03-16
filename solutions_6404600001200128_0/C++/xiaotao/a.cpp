#include <cstdio>
#include <algorithm>
using namespace std;

int a[1001];

int main()
{
	int T;
	scanf("%d", &T);
	for (int tt=1; tt<=T; ++tt)
	{
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%d", a+i);
		int ans1=0, ans2=0, k=0;
		for (int i=1; i<n; ++i)
			if (a[i-1]>a[i])
			{
				ans1+=a[i-1]-a[i];
				k=max(k, a[i-1]-a[i]);
			}
		for (int i=0; i<n-1; ++i)
			ans2+=min(k, a[i]);
		printf("Case #%d: %d %d\n", tt, ans1, ans2);
	}
	return 0;
}

