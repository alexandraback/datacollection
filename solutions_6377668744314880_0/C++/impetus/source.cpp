#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>
#include <queue>
#include <complex>
#include <functional>
#include <sstream>
#include <tuple>

using namespace std;

struct point
{
	long long x, y;

	point operator-(point p)
	{
		point result;
		result.x = x - p.x;
		result.y = y - p.y;
		return result;
	}

	long long operator*(point p)
	{
		return x * p.y - y * p.x;
	}
};

point pts[100];
int n;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tn;
    cin >> tn;
    for (int tc = 0; tc < tn; tc++)
    {
    	cin >> n;
    	for (int i = 0; i < n; i++)
    		cin >> pts[i].x >> pts[i].y;
    	vector<int> best(n, max(n - 2, 0));
    	for (int z = 1; z < (1 << n); z++)
    	{
    		int sum = 0;
    		for (int i = 0; i < n; i++) if ((z >> i) % 2)
    			sum++;
    		for (int i = 0; i < n; i++) if ((z >> i) % 2)
    			for (int j = 0; j < n; j++) if (j != i && (z >> j) % 2)
    			{
    				int pos = 0, neg = 0;
    				for (int k = 0; k < n; k++) if (k != i && k != j && (z >> k) % 2)
    				{
    					long long m = (pts[j] - pts[i]) * (pts[k] - pts[i]);
    					if (m > 0)
    						pos = 1;
    					else if (m < 0)
    						neg = 1;
    				}
    				if (!pos || !neg)
    				{
    					best[i] = min(best[i], n - sum);
    					best[j] = min(best[j], n - sum);
    				}
    			}
    	}
    	cout << "Case #" << tc + 1 << ":" << endl;
    	for (int i = 0; i < n; i++)
    		cout << best[i] << endl;
    }
    return 0;
}