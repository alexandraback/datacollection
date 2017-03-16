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

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tn;
    cin >> tn;
    for (int tc = 0; tc < tn; tc++)
    {
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	int mx = 0;
    	for (int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		if (i)
    			mx = max(mx, a[i - 1] - a[i]);
    	}
    	int sum1 = 0, sum2 = 0;
    	for (int i = 1; i < n; i++)
    	{
    		sum1 += max(0, a[i - 1] - a[i]);
    		sum2 += min(a[i - 1], mx);
    	}
    	cout << "Case #" << tc + 1 << ": " << sum1 << " " << sum2 << endl;
    }
    return 0;
}