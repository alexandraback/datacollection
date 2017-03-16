#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int t;
	ll x[3000], y[3000];

	cin >> t;
	for(int tt=1; tt<=t; ++tt)
	{
		int res = 0;
		int n;
		cin >> n;
		for(int i=0; i<n; ++i)
			cin >> x[i] >> y[i];

		cout << "Case #" << tt << ":\n";

		for(int i=0; i<n; ++i)
		{
			res = n-1;
			for(int j=0; j<n; ++j) if(i != j)
			{
				int n1=0, n2=0;
				for(int k=0; k<n; ++k) if(i != k && j != k)
				{
					ll x1 = x[j]-x[i];
					ll y1 = y[j]-y[i];
					ll x2 = x[k]-x[i];
					ll y2 = y[k]-y[i];
					ll z = x1*y2 - y1*x2;
					if(z < 0)
						++n1;
					if(0 < z)
						++n2;
				}
				//print4(i, j, n1, n2);
				res = min(res, min(n1, n2));
			}
			cout << res << "\n";
		}
	}

	return 0;
}
