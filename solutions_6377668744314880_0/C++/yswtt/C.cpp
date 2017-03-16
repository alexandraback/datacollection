#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

long long x[3005], y[3005];
int f[3005];

int main()
{
	int tt;
	
	cin >> tt;
	for (int t = 1; t <= tt; ++t)
	{
		int n;
		cin >> n;
		
		for (int i = 0; i < n; ++i)
			cin >> x[i] >> y[i];
		
		for (int i = 0; i < n; ++i)
			f[i] = 5000;
		
		if (n < 4)
			for (int i = 0; i < n; ++i)
				f[i] = 0;
		
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
			{
				int c1 = 0, c2 = 0;
				if (x[i] == x[j])
				{
					for (int k = 0; k < n; ++k)
						if ((i != k) && (j != k))
						{
							if (x[k] < x[i])
								c1++;
							else if (x[k] > x[i])
								c2++;
						}
				}
				else
				{
					long long x1, y1, x2, y2;
					if (x[i] < x[j])
					{
						x1 = x[i];
						x2 = x[j];
						y1 = y[i];
						y2 = y[j];
					}
					else
					{
						x1 = x[j];
						x2 = x[i];
						y1 = y[j];
						y2 = y[i];
					}
					for (int k = 0; k < n; ++k)
						if ((x2 - x1) * (y[k] - y1) < (y2 - y1) * (x[k] - x1))
							c1++;
						else if ((x2 - x1) * (y[k] - y1) > (y2 - y1) * (x[k] - x1))
							c2++;
				}
				c1 = min(c1, c2);
				f[i] = min(f[i], c1);
				f[j] = min(f[j], c1);
			}
		
		cout << "Case #" << t << ":" << endl;
		for (int i = 0; i < n; ++i)
			cout << f[i] << endl;
	}

    return 0;
}
