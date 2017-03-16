// Problem : gcj r1 B
// Author : Leo Yu

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

using namespace std;
typedef long long LL;

#define link Link
#define next Next
#define elif else if

inline int read()
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}

int a[1000006];

int main()
{
	
	int T;
	cin >> T;
	for (int _ = 1; _ <= T; ++ _)
	{
		int B = read(), N = read();
		for (int i = 1; i <= B; ++ i)
			a[i] = read();
		LL l = -1, r = LL(N) * LL(100000) + 1;

		while (l + 1 < r)
		{
			LL mid = l + r >> 1;
			LL tot = 0;
			for (int i = 1; i <= B; ++ i)
			{
				tot += (mid + a[i] - 1) / a[i];
				if (tot > N)	break;
			}
			if (tot < N)	l = mid;
			else	r = mid;
		}
		LL tot = 0;
		for (int i = 1; i <= B; ++ i)
		{
			tot += (l + a[i] - 1) / a[i];
		}
		for (int i = 1; i <= B; ++ i)	if (l % a[i] == 0)
		{
			tot ++;
			if (tot == N)
			{
				printf("Case #%d: %d\n", _, i);
				break;
			}
		}
	}

	return 0;
}