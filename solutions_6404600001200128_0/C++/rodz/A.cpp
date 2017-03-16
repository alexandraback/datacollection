#include <bits/stdc++.h>
#define N 10000
using namespace std;

int n, v[N];

int main()
{
	int T;
	int count = 1;
	int ans1, ans2;
	int maxdiff;
	
	scanf("%d", &T);
	while(count <= T)
	{
		scanf("%d", &n);
		ans1 = ans2 = maxdiff = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &(v[i]));
		}
		for (int i = 1; i < n; i++)
		{
			if (v[i] < v[i-1])
			{
				ans1+=v[i-1]-v[i];
				maxdiff = max(maxdiff, v[i-1]-v[i]);
			}
		}
		for (int i = 0; i < n-1; i++)
		{
			ans2 += min(v[i], maxdiff);
		}
		
		printf("Case #%d: ", count++);
		printf("%d %d\n", ans1, ans2);
		
	}
	return 0;
}
