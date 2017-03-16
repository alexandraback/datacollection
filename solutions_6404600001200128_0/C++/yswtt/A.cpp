#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

int m[1005];

int main()
{
	int tt;
	
	cin >> tt;
	for (int t = 1; t <= tt; ++t)
	{
		int n;
		cin >> n;
		
		for (int i = 0; i < n; ++i)
		{
			cin >> m[i];
			m[i] = m[i] * 10;
		}
		int r1 = 0;
		for (int i = 1; i < n; ++i)
			r1 += max(0, m[i-1] - m[i]);
		int r2 = 0, d = 0;
		for (int i = 1; i < n; ++i)
			if (m[i-1] > m[i])
				d = max(d, (m[i-1] - m[i] - 1) / 10 + 1);
		for (int i = 1; i < n; ++i)
			r2 += min(m[i-1], d * 10);
		cout << "Case #" << t << ": " << r1 / 10 << " " << r2 / 10 << endl;
	}

    return 0;
}
