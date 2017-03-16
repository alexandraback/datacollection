#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>

using namespace std;
typedef long long ll;


int main()
{
	int t;
	cin >> t;
	for (int cs = 1; cs <= t; cs++)
	{
		printf("Case #%d: ", cs);
		int n;
		cin >> n;
		vector<int> a;
		while (n--)
		{
			int t;
			scanf("%d", &t);
			a.push_back(t);
		}
		n = a.size();
		ll ans1=0;
		ll ans2=0;

		int spd = 0;
		for (int i = 1; i < n; i++) 
			if (a[i] < a[i - 1])
			{
				ans1 += a[i - 1] - a[i];
				spd = max(  a[i - 1] - a[i], spd);
			}
		for (int i = 0; i < n - 1; i++)
			ans2 += min(a[i], spd );

		cout << ans1 << " " << ans2<<endl;
	}


	return 0;
}