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

int m[100000];

ll doneat(int n, ll t)
{
	--t;
	if(t < 0)
		return 0;
	ll res = n;
	for(int i=0; i<n; ++i)
		res += t/m[i];
	return res;
}

int main() {
	int t;

	cin >> t;
	for(int tt=1; tt<=t; ++tt)
	{
		int sum = 0;
		//int res = 0;
		int b, n;
		cin >> b >> n;
		for(int i=0; i<b; ++i) {
			cin >> m[i];
			sum += m[i];
		}

		ll l=0, r=100000000000001LL;
		while(l+1<r)
		{
			ll c = (l+r)/2;
			ll x = doneat(b, c);
			if(x < n)
				l = c;
			else
				r = c;
		}

		int o = n - doneat(b, l);
		//print3(l, o, doneat(b, l));
		int i=0;
		for(i=0; i<b && o; ++i)
		{
			if(l%m[i] == 0)
				--o;
		}

		cout << "Case #" << tt << ": " << i << "\n";
	}

	return 0;
}
