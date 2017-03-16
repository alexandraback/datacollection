#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <stack>
#include <set>

using namespace std;

int x[5000], y[5000];

int main()
{
	ifstream ifs("c.in");
	ofstream ofs("c.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		int n;
		ifs >> n;
		for (int i = 0; i < n; ++i)
			ifs >> x[i] >> y[i];

		ofs << "Case #" << test+1 << ":" << endl;
		for (int i = 0; i < n; ++i)
		{
			int res = n;
			if (n < 4) res = 0;
			else 
			{
					for (int j = 0; j < n; ++j)
					if (i != j)
					{
						int pos = 0, neg = 0;
						long long A = y[j] - y[i];
						long long B = x[i] - x[j];
						long long C = -A * x[i] - B * y[i];
						for (int k = 0; k < n; ++k)
						{
							long long d = A*x[k] + B*y[k] + C;
							if (d < 0) ++neg;
							if (d > 0) ++pos;
						}
						res = min(res, min(neg, pos));
					}
			}
			ofs << res << endl;
		}
	}
	return 0;
}
