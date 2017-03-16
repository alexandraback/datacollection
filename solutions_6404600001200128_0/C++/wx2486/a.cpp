#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main()
{
	int cn; cin >> cn;
	for (int cc=1; cc<=cn; cc++)
	{
		int n; cin >> n;
		vector<int> v(n);
		for (int i=0; i<n; i++)
			cin >> v[i];

		int ans1 = 0, maxdec = 0;
		for (int i=1; i<n; i++)
		{
			int t = v[i-1] - v[i];
			if (t > 0)
				ans1 += t;
			if (t > maxdec)
				maxdec = t;
		}

		int ans2 = 0;
		for (int i=0; i<n-1; i++)
			ans2 += min(maxdec, v[i]);		

		cout << "Case #" << cc << ": " << ans1 << ' ' << ans2 << endl;
	}
	return 0;
}
