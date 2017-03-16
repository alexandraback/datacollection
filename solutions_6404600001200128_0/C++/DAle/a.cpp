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
	ifstream ifs("a.in");
	ofstream ofs("a.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		int n;
		ifs >> n;
		vector<int> v;
		for (int i = 0; i < n; ++i)
		{
			int j;
			ifs >> j;
			v.push_back(j);
		}
		int maxd = 0;
		int res1 = 0, res2 = 0;
		for (int i = 1; i < n; ++i)
		{
			maxd = max(maxd, v[i-1] - v[i]);
			if (v[i] < v[i-1]) res1 += v[i-1] - v[i];
		}
		for (int i = 1; i < n; ++i)
		{
			res2 += min(v[i-1], maxd);
		}
		ofs << "Case #" << test+1 << ": " << res1 << ' ' << res2 << endl;
	}
	return 0;
}
