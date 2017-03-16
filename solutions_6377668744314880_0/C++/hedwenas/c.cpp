#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <list>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) (1ll << (_z))
#define rep(__z,__Z) for(int __z = 0; __z < __Z ; __z++ )
#define all(__z) __z.begin(),__z.end()

#define par pair<int, int>
#define p1 first
#define p2 second

#define eps = 1e-6

using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int t;
int n;
long long x[200100], y[200100];

long long cross(long long x1, long long y1, long long x2, long long y2)
{
	return x1 * y2 - y1 * x2;
}

long long ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
	return cross(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
}

int ans(int idx)
{
	int ret = n;
	for (int j = 0; j < n; j ++)
	{
		if (x[idx] == x[j] and y[idx] == y[j])
		{
			while(idx != j);
			continue;
		}
			
		int opt1 = 0, opt2 = 0;
		for (int i = 0; i < n; i ++)
		{
		
			if (x[idx] == x[i] and y[idx] == y[i])
				continue;
			if (x[j] == x[i] and y[j] == y[i])
				continue;
				
			long long cc = ccw(x[idx], y[idx], x[j], y[j], x[i], y[i]);
			if (cc > 0)
				opt1 ++;
			else if (cc < 0)
				opt2 ++;
		}
		ret = min(ret, min(opt1, opt2));
	}
	return ret;
}

int main()
{
	cin >> t;
	int caze = 0;
	while (t --)
	{
		caze ++;
		
		cin >> n;
		for (int i = 0; i < n; i ++)
		{
			cin >> x[i] >> y[i];
		}
		
		cout << "Case #" << caze << ":" << endl;
		
		for (int i = 0; i < n; i ++)
		{
			if (n <= 3)
				cout << 0 << endl;
			else
				cout << ans(i) << endl;
		}
	}
		
	return 0;
}
