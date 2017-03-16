#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

long long m[1005];
long long n, b, lm;

int main()
{
	int tt;
	
	cin >> tt;
	for (int t = 1; t <= tt; ++t)
	{
		cin >> b >> n;
		
		for (int i = 0; i < b; ++i)
		{
			cin >> m[i];
			lm = max(lm, m[i]);
		}
		
		if (n <= b)
		{
			cout << "Case #" << t << ": " << n << endl;
			continue;
		}
		
		long long l = 0, r = lm * n + 1;
		
		while (l + 1 < r)
		{
//		cout << l << " " << r << endl;
			long long cnt = b;
			long long k = (l + r) / 2;
			for (int i = 0; i < b; ++i)
				cnt += k / m[i];
			if (cnt < n)
				l = k;
			else
				r = k;
		}
		
//		cout << r << endl;
		long long tmp = b;
		for (int i = 0; i < b; ++i)
			tmp += l / m[i];
		int res = 0;
		for (int i = 0; i < b; ++i)
			if (r % m[i] == 0)
			{
				tmp++;
				if (tmp == n)
				{
					res = i + 1;
					break;
				}
			}
		
		cout << "Case #" << t << ": " << res << endl;
	}

    return 0;
}
