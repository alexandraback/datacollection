#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 30;

int a[N];

int main()
{
	freopen("a1.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t ++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i ++)
			scanf("%d", &a[i]);
		//solve
		printf("Case #%d:", t);
		while (1)
		{
			int s = 0;
			int	x = -1, y = -1, z = -1;
			for (int i = 0; i < n; i ++)
			{
				s += a[i];
				if (x == -1 || a[i] > a[x])
				{
					z = y; y = x; x = i;
				}
				else if (y == -1 || a[i] > a[y])
				{
					z = y; y = i;
				}
				else if (z == -1 || a[i] > a[z])
				{
					z = i;
				}
			}
			if (x == -1 || a[x] == 0){//end
				puts("");
				break;
			}
			if (z == -1 || a[z] == 0)//only two
			{
				if (a[x] >= a[y]+2){
					a[x] -= 2;
					printf(" %c%c", 'A' + x, 'A' + x);
				} else if (a[x] > a[y]){
					a[x] --;
					printf(" %c", 'A' + x);
				} else {
					a[x] --; a[y] --;
					printf(" %c%c", 'A' + x, 'A' + y);
				}
			} else {//three
				if (a[y] > a[z])//two more
				{
					a[x] --; a[y] --;
					printf(" %c%c", 'A' + x, 'A' + y);
				}
				else if (a[x] >= a[y]+2){
					a[x] -= 2;
					printf(" %c%c", 'A' + x, 'A' + x);
				} else {
					a[x] --;
					printf(" %c", 'A' + x);
				}
			}
		}
	}
	return 0;
}
