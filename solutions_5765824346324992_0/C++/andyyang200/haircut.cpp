#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <climits>
#include <numeric>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;


ll barbers[1005];
int times[1005];
int b, n;

ll gcd(ll a, ll b)
{
	while (true)
	{
		if (a == 0) return b;
		b %= a;
		if (b == 0) return a;
		a %= b;
	}
}

ll getLCM(ll a, ll b)
{
	ll temp = gcd(a, b);
	return temp ? (a / temp * b) : 0;
}

int main()
{
	freopen("haircut.in", "r", stdin);
	freopen("haircut.out", "w", stdout);
	int sets;
	scanf("%d", &sets);
	FOR(set, 0, sets)
	{
		scanf("%d%d", &b, &n);
		FOR(i, 0, b)
		{
			scanf("%d", &barbers[i]);
		}
		if (n <= b)
		{
			cout << "Case #" << set + 1 << ": " << n << endl;
			continue;
		}
		ll lcm = 1;
		FOR(i, 0, b)
		{
			lcm = getLCM(lcm, barbers[i]);
		}
		int sum = 0;
		FOR(i, 0, b)
		{
			sum += lcm / (ll)barbers[i];
			times[i] = 0;
		}
		n %= sum;
		if (n == 0)
		{
			cout << "Case #" << set + 1 << ": " << 1 << endl;
		}
		FOR(i, 0, n)
		{
			int minTime = 1000000000;
			int bestIndex = -1;
			FOR(j, 0, b)
			{
				if (times[j] < minTime)
				{
					minTime = times[j];
					bestIndex = j;
				}
			}
			FOR(j, 0, b)
			{
				times[j] -= minTime;
			}
			times[bestIndex] += barbers[bestIndex];
			if (i == n - 1)
			{
				cout << "Case #" << set + 1 << ": " << bestIndex + 1 << endl;
			}
		}
	}
}