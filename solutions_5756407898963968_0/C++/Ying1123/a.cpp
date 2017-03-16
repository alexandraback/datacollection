#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int T;
int x1, x2, a[10], b[10], ans;

void work()
{
	scanf("%d", &x1);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			scanf("%d", &b[j]);
		if (i + 1 == x1)
			for (int j = 0; j < 4; ++j)
				a[j] = b[j];
	}
	scanf("%d", &x2);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			scanf("%d", &b[j]);
		if (i + 1 == x2)
		{
			ans = 0;
			for (int j = 0; j < 4; ++j)
				for (int k = 0; k < 4; ++k)
					if (b[j] == a[k])
					{
						if (ans == 0) ans = a[k]; else ans = -1;
					}
		}
	}
	if (ans > 0) printf("%d\n", ans); else
	if (ans == -1) printf("Bad magician!\n"); else
		printf("Volunteer cheated!\n");
}

int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d: ", i + 1);
		work();
	}
	return 0;
}
