#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
#define LL long long
int A[10];
int main()
{
	freopen("data.in","r",stdin);
	int T;
	scanf("%d", &T);
	int cas=0;
	while (T--)
	{
		int n, m;
		scanf("%d", &n);
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
			{
				int x;
				scanf("%d", &x);
				if (i == n)
					A[j] = x;
			}
		scanf("%d", &m);
		int ans = 0;
		int pos = 0;
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
			{
				int x;
				scanf("%d", &x);
				if (i == m)
					for (int k = 1; k <= 4; k++)
					{
						if (x == A[k])
						{
							ans++;
							pos = x;
						}
					}

			}
	printf("Case #%d: ",++cas);
	if(ans==1)printf("%d\n",pos);
	if(ans==0)puts("Volunteer cheated!");
	if(ans>1)puts("Bad magician!");

}
return 0;
}
