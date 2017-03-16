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
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int mushrooms[1005];
int n;
int a()
{
	int total = 0;
	FOR(i, 1, n)
	{
		if (mushrooms[i] < mushrooms[i - 1])
		{
			total += mushrooms[i - 1] - mushrooms[i];
		}
	}
	return total;
}
int b()
{
	int total = 0;
	int maxDifference = 0;
	FOR(i, 1, n)
	{
		maxDifference = max(maxDifference, mushrooms[i - 1] - mushrooms[i]);
	}
	FOR(i, 0, n - 1)
	{
		total += min(mushrooms[i], maxDifference);
	}
	return total;
}

int main()
{
	freopen("monster.in", "r", stdin);
	freopen("monster.out", "w", stdout);
	int sets;
	scanf("%d", &sets);
	FOR(set, 0, sets)
	{
		scanf("%d", &n);
		FOR(i, 0, n)
		{
			scanf("%d", &mushrooms[i]);
		}
		cout << "Case #" << set + 1 << ": " << a() << " " << b() << endl;
	}
}