#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

const int maxn = 100100;
int T, n;
int x[maxn], y[maxn];

long long cross (int X1, int Y1, int X2, int Y2)
{
	return 1LL*X1*Y2-1LL*X2*Y1;
}

int main()
{
  freopen("text.in","r",stdin);
  freopen("text.out","w",stdout);
  cin >> T;
  for (int t=1; t<=T; t++)
  	{
  		printf ("Case #%d:\n", t);
  		int tot1, tot2, ans; long long tmp;
			scanf ("%d", &n);
			for (int i=1; i<=n; i++)
				scanf ("%d%d", &x[i], &y[i]), x[i] += 1000000, y[i] += 1000000;
			if (n <= 3)
				{
					for (int i=1; i<=n; i++)
						printf ("0\n");
					continue;
				}
			for (int i=1; i<=n; i++)
				if (ans = n)
					{
						for (int j=1; j<=n; j++)
							if (tot1 = 0, tot2 = 0, j != i)
								{
									for (int k=1; k<=n; k++)
										if (k != i && k != j)
											tmp = cross (x[j]-x[i], y[j]-y[i], x[k]-x[i], y[k]-y[i]),
											tmp < 0 ? tot1++ : 0,
											tmp > 0 ? tot2++ : 0;
									ans = min (min (tot1, tot2), ans);
								}
						printf ("%d\n", ans);
					}
		}
	return 0;
}

