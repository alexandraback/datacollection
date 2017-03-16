/*
* @problem:  Senate Evacuation
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <limits.h>
#include <vector>
#include <map>
#include <bitset>
#include <string>
#include <iterator>
#include <set>
#include <utility>
#include <queue>
#include <numeric>
#include <functional>
#include <ctype.h>
#include <stack>
#include <algorithm>
#include <cstdlib>
#define MAX 100100
#define mod 1000000007LL
#define bitcnt(x) __builtin_popcountll(x)
#define MS0(x) memset(x, 0, sizeof(x))
#define MS1(x) memset(x, -1, sizeof(x))
#define ll long long int
#define mp(x, y) make_pair(x, y)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define in(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define ins(x) scanf("%s", x)
#define pr(x) printf("%lld\n", x)
#define prd(x) printf("%d\n", x)
#define prs(x) printf("%s\n", x)
#define pi acos(-1.0)
#define ff first
#define ss second

using namespace std;

int main()
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("../input.txt", "r", stdin);
	// 	freopen("../output.txt", "w", stdout);
	// #endif
	// ios_base::sync_with_stdio(0);
    // cin.tie(0);
	int t, n, sum;
	pair<int, char> x[30];
	ind(t);
	for(int i = 1; i <= t; i++)
	{
		ind(n);
		sum = 0;
		for(int j = 0; j < n; j++)
		{
			ind(x[j].ff);
			x[j].ss = 'A' + j;
			sum += x[j].ff;
		}
		x[n].ff = x[n + 1].ff = 0;
		cout << "Case #" << i << ": ";
		//sort(x, x + n, greater<pair<int, char> >());
		int j = 0, tmp;
		while(sum > 0)
		{
			sort(x, x + n, greater<pair<int, char> >());
			tmp = sum / 2;
			if(sum % 2 != 0)
				tmp++;
			if(x[0].ff == x[1].ff && x[0].ff > x[2].ff)
			{
				cout << x[0].ss << x[1].ss;
				x[0].ff--;
				x[1].ff--;
				sum -= 2;
			}
			else
			{
				x[0].ff--;
				cout << x[0].ss;
				sum--;
			}
			// else
			// {
			// 	if(sum == x[0].ff)
			// 	{
			// 		cout << x[0].ss;
			// 		x[0].ff--;
			// 		sum--;
			// 	}
			// 	else
			// 	{
			// 		if(x[0].ff == x[1].ff)
			// 		{
			// 			x[0].ff--;
			// 			x[1].ff--;
			// 			cout << x[0].ss << x[1].ss;
			// 		}
			// 		else
			// 		{
			// 			x[0].ff -= 2;
			// 			cout << x[0].ss << x[0].ss;
			// 		}
			// 		sum -= 2;
			// 	}
			// }
			cout << " ";
		}
		cout << endl;
	}
	return 0;
}