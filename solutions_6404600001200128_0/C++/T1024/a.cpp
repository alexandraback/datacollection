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
	int a[1000];

	cin >> t;
	for(int tt=1; tt<=t; ++tt)
	{
		int res1 = 0, res2 = 0;
		int n;
		cin >> n;
		for(int i=0; i<n; ++i)
			cin >> a[i];

		int rate = 0;
		for(int i=1; i<n; ++i)
		{
			if(a[i] < a[i-1])
				res1 += a[i-1] - a[i];
			rate = max(rate, a[i-1] - a[i]);
		}

		for(int i=0; i<n-1; ++i)
		{
			res2 += min(a[i], rate);
		}

		cout << "Case #" << tt << ": " << res1 << " " << res2 << "\n";
	}

	return 0;
}
