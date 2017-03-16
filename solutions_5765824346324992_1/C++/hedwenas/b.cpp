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
int b;
long long n;
long long M[20100];

long long attended(long long time)
{
	long long ret = 0;
	for (int i = 0; i < b; i ++)
	{
		ret += (time + M[i] - 1) / M[i];
	}
	return ret;
}

long long Time()
{
	long long l = 0, r = 100ll * 100000ll * 1000000000l, m;
	while (l < r)
	{
		m = l + (r - l + 1) / 2;
		if (attended(m) > n-1)
			r = m - 1;
		else
			l = m;
	}
	return l;
}

int main()
{
	cin >> t;
	int caze = 0;
	while (t --)
	{
		caze ++;
		cin >> b >> n;
		scan(M, 0, b);
		
		long long time = Time();
		long long ans = -1;
		long long att = attended(time);
		for (int i = 0; i < b; i ++)
		{
			if ((time % M[i]) == 0) 
			{
				ans = i+1;
				att ++;
				if (att == n)
					break;
			}
		}
		
		cout << "Case #" << caze << ": " << ans << endl;
	}
		
	return 0;
}
