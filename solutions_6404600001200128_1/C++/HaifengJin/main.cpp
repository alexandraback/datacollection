#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = (int)(1e3) + 10;

int n;
int f[MAX_N];

int main()
{
	int t;
	scanf("%d", &t);
	int case_num = 0;
	while (t--)
	{
		case_num++;
		printf("Case #%d: ", case_num);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &f[i]);
		}
		int ans = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (f[i + 1] < f[i])
				ans += f[i] - f[i + 1];
		}
		printf("%d ", ans);
		ans = 0;
		int temp = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (f[i + 1] < f[i])
				temp = max(temp, f[i] - f[i + 1]);
		}
		for (int i = 0; i < n - 1; i++)
		{
			ans += min(f[i], temp);
		}
		printf("%d\n", ans);
	}
	return 0;
}
