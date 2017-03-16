#include <cstdio>

int m[1005], n;
int t;

int main()
{
	scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		scanf("%d", &n);
		for (int i = 0;i < n;i++)
			scanf("%d", m+i);
		int x, y, b, o;
		x = y = b = o = 0;
		for (int i = 1;i < n;i++)
		{
			if (m[i] < m[i-1])
				x += (m[i-1]-m[i]);
			if (m[i-1]-m[i] > b)
				b = m[i-1]-m[i];
		}
		o = m[0];
		for (int i = 1;i < n;i++)
		{
			if (o >= b)
			{
				y += b;
				o -= b;
			} else
			{
				y += o;
				o = 0;
			}
			o = m[i];
		}
		printf("Case #%d: %d %d\n", _, x, y);
	}
	return 0;
}
