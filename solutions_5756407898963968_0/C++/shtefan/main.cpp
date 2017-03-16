#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		int a1, vals[17], cr, nc = 0, v;

		for (int k = 1; k <= 16; k++)
			vals[k] = 0;

		printf("Case #%d: ", i);
		for (int q = 0; q < 2; q++)
		{
			scanf("%d", &a1);
			for (int j = 1; j <= 4; j++)
			{
				for (int c = 1; c <= 4; c++)
				{
					scanf("%d", &cr);
					if (j == a1)
						vals[cr]++;
				}
			}
		}
		for (int k = 1; k <= 16; k++)
		{
			if (vals[k] == 2)
				nc++, v = k;
		}
		if (nc == 0)
			printf("Volunteer cheated!\n");
		else if (nc == 1)
			printf("%d\n", v);
		else
			printf("Bad magician!\n");
	}
}