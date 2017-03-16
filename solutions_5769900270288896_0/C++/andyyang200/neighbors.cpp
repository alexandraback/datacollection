//Andrew Yang
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
bool grid[17][17];
int R, C;
int ans = 0;
void f(int r, int c, int n)
{
	if (n == 0)
	{
		int count = 0;
		FOR(i, 0, R)
		{
			FOR(j, 0, C)
			{
				if (grid[i][j])
				{
					if (i + 1 < R && grid[i + 1][j])
					{
						count++;
					}
					if (j + 1 < C && grid[i][j + 1])
					{
						count++;
					}
				}
			}
		}
		ans = min(ans, count);
		return;
	}
	if (r >= R)
	{
		return;
	}
	int nextC = c + 1;
	int nextR = r;
	if (nextC == C)
	{
		nextC = 0;
		nextR++;
	}
	grid[r][c] = false;
	f(nextR, nextC, n);
	grid[r][c] = true;
	f(nextR, nextC, n - 1);
}
int main()
{
	freopen("neighbors.in", "r", stdin);
	freopen("neighbors.out", "w", stdout);
	int sets;
	scanf("%d", &sets);
	FOR(set, 1, sets + 1)
	{
		int n;
		scanf("%d%d%d", &R, &C, &n);
		FOR(i, 0, R)
		{
			FOR(j, 0, C)
			{
				grid[i][j] = false;
			}
		}
		ans = 1000000;
		f(0, 0, n);
		cout << "Case #" << set << ": " << ans << endl;
	}
}