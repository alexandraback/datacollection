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
    	int b;
    	long long n;
    	cin >> b >> n;
    	vector<long long> a(b);
    	set<pair<long long, int> > s;
    	for (int i = 0; i < b; i++)
    		cin >> a[i];
    	long long l = 0;
    	if (n > 3 * b)
    	{
    		long long r = 10000000000000000LL;
    		while (l < r)
    		{
    			long long m = (l + r) / 2;
    			long long cnt = 0;
    			for (int i = 0; i < b; i++)
    				cnt += (m - 1) / a[i] + 1;
    			if (n - cnt > 2 * b)
    				l = m + 1;
    			else
    				r = m;
    		}

			for (int i = 0; i < b; i++)
				n -= (l - 1) / a[i] + 1;
    	}

    	for (int i = 0; i < b; i++)
    	{
    		long long cur = l ? ((l - 1) / a[i] + 1) * a[i] : 0;
    		s.insert(make_pair(cur, i));
    		//cout << cur << " ";
    	}
		//cout << l << " " << n << " " << sh << endl;

    	for (int i = 0; i < n - 1; i++)
    	{
    		long long t = s.begin()->first;
    		int id = s.begin()->second;
    		s.erase(s.begin());
    		s.insert(make_pair(t + a[id], id));
    	}
    	cout << "Case #" << tc + 1 << ": " << s.begin()->second + 1 << endl;
    }
    return 0;
}