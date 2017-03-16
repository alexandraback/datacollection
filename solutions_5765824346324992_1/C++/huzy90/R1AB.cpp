#include <cstdio>

int a[1000];

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		int b, n;
		scanf("%d %d", &b, &n);
		for (int i = 0; i < b; ++i)
		{
			scanf("%d", &a[i]);
		}
	
		bool flag = false;
		for (int i = 0; i < b; ++i)
		{
			int start = 1, end = n;
			while (start <= end)
			{
				int mid = start + (end - start) / 2;
				long long time = (long long)(mid - 1) * a[i];

				long long sum = 0;
				for (int j = 0; j < b; ++j)
				{
					long long num = (time - 1) / a[j] + 1;
					sum += num;
					if (j < i && time / a[j] == num)
					{
						++sum;
					}
				}

				if (sum == n - 1)
				{
					flag = true;
					break;
				}
				else if (sum > n - 1)
				{
					end = mid - 1;
				}
				else
				{
					start = mid + 1;
				}
			}

			if (flag)
			{
				printf("Case #%d: %d\n", t, i + 1);
				break;
			}
		}
	}

	return 0;
}
