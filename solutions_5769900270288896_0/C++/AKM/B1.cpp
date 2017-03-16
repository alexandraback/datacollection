#include <iostream>
#include <memory.h>

using namespace std;

const int MAXN = 20;

int a[MAXN][MAXN];

int main()
{
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; tc++)
	{
		int r, c, n;
		cin >> r >> c >> n;
		cout << "Case #" << tc << ": ";
		int mxmsk = 1 << (r * c);
		memset(a, 0, sizeof a);
		int ans = 2 * r * c;
		for (int i = 0; i < mxmsk; i++)
			if (__builtin_popcount(i) == n)
			{
				for (int j = 0; j < r; j++)
					for (int k = 0; k < c; k++)
						a[j][k] = (i >> (j * c + k)) & 1;
				int tmp = 0;
				for (int j = 0; j < r; j++)
					for (int k = 0; k < c; k++)
						if (a[j][k])
						{
							if (a[j + 1][k])
								tmp++;
							if (a[j][k + 1])
								tmp++;
						}
				ans = min(ans, tmp);

			}
		cout << ans << endl;
	}
}
