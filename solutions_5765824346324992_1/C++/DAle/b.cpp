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

int main()
{
	ifstream ifs("b.in");
	ofstream ofs("b.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		long long b, n;
		ifs >> b >> n;
		vector<int> v(b);
		for (int i = 0; i < b; ++i)
			ifs >> v[i];

		long long sum = accumulate(v.begin(), v.end(), 0ll);
		long long maxt = sum * (n + b) / b;
		long long l = 0, r = maxt;
		bool found = false;
		int res = 0;
		while (!found)
		{
			long long m = (l+r) / 2;
			long long s = 0;
			for (int i = 0; i < b; ++i)
			{
				s += (m + v[i] - 1) / v[i];
			}
			if (s >= n)
				r = m-1;
			else 
			{
				for (int i = 0; i < b; ++i)
					if (m % v[i] == 0)
					{
						++s;
						if (s == n)
						{
							found = true;
							res = i+1;
							break;
						}
					}
				l = m+1;
			}
		}
		ofs << "Case #" << test+1 << ": " << res << endl;
	}
	return 0;
}
