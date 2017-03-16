#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T, n;
	int m[1005];
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		int y = 0, z = 0;
		cin >> n;
		for(int i = 0; i < n; ++i)
			cin >> m[i];
		
		int mx = 0;
		for(int i = 1; i < n; ++i)
		{
			if(m[i] < m[i - 1])
			{
				y += (m[i - 1] - m[i]);
				mx = max(mx, m[i - 1] - m[i]);
			}
		}
		int j;
		for(j = 1; j < n; ++j)
		{
			z += min(mx, m[j - 1]);
		}
		printf("Case #%d: %d %d\n", t, y, z);
	}
	return 0;
}
