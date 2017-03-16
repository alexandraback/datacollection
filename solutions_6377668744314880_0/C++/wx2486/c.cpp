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
		vector<long long> x(n), y(n);
		for (int i=0; i<n; i++)
			cin >> x[i] >> y[i];

		cout << "Case #" << cc << ":" << endl;
		for (int i=0; i<n; i++)
		{
			int mincut = 3000;
			for (int j=0; j<n; j++)
				if (j != i)
				{
					int left = 0, right = 0;
					for (int k=0; k<n; k++)
						if (k != i && k != j)
						{
							long long dir = (x[k] - x[i]) * (y[j] - y[i]) - (y[k] - y[i]) * (x[j] - x[i]);
							// cerr << i << j << k << dir << endl;
							if (dir < 0) left++;
							else if (dir > 0) right++;
						}
					mincut = min(mincut, min(left, right));
				}
			if (mincut == 3000)
				mincut = 0;
			cout << mincut << endl;
		}
	}
	return 0;
}
