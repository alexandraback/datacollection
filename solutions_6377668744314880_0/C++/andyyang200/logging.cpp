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

double slope(pii& a, pii& b) // returns slope of the line between two points
{
	if (a.first == b.first)
	{
		return INF;
	}
	return (double)(a.second - b.second) / (a.first - b.first);
}

ll getDistance(pii& a, pii& b) // return distance between two points
{
	return (ll)(b.first - a.first) * (b.first - a.first) + (ll)(b.second - a.second) * (b.second - a.second);
}

ll orientation(pii& a, pii& b, pii& c) // > 0 CCW, == 0 collinear, < 0 CW
{
	return (ll)(b.first - a.first) * (c.second - a.second) - (ll)(b.second - a.second) * (c.first - a.first);
}
bool counterClockwise(pii& a, pii& b, pii& c)
{
	return orientation(a, b, c) > 0;
}
bool clockwise(pii& a, pii& b, pii& c)
{
	return orientation(a, b, c) < 0;
}

vector<pii> hull;
bool pointCompare(pii a, pii b)
{
	double m1 = slope(hull[0], a);
	double m2 = slope(hull[0], b);
	if (fabs(m1 - m2) <= 1e-9)
	{
		return getDistance(hull[0], a) < getDistance(hull[0], b);
	}
	return m1 < m2;
}
vector<pii> getConvexHull(vector<pii> points, int n) // return convex hull of array of n points
{
	hull.clear();
	pii start(INF, INF);
	FOR(i, 0, n)
	{
		if (points[i] < start)
		{
			start = points[i];
		}
	}
	hull.push_back(start);
	sort(points.begin(), points.end(), pointCompare);
	FOR(i, 0, n)
	{
		if (points[i] == hull[0])
		{
			continue;
		}
		while (hull.size() > 1 && !counterClockwise(hull[hull.size() - 2], hull[hull.size() - 1], points[i]))
		{
			hull.pop_back();
		}
		hull.push_back(points[i]);
	}
	hull.push_back(hull[0]);
	return hull;
}

bool onLine(pii& a, pii& b, pii& c) // return a on line bc
{
	if (orientation(a, b, c) == 0)
	{
		if (min(b.first, c.first) <= a.first && max(b.first, c.first) >= a.first)
		{
			if (min(b.second, c.second) <= a.second && max(b.second, c.second) >= a.second)
			{
				return true;
			}
		}
	}
	return false;
}
vector<pii> points;
int main()
{
	freopen("logging.in", "r", stdin);
	freopen("logging.out", "w", stdout);
	int sets;
	scanf("%d", &sets);
	FOR(set, 0, sets)
	{
		cout << "Case #" << set + 1 << ": " << endl;
		int n;
		scanf("%d", &n);
		FOR(i, 0, n)
		{
			points.push_back({ 0, 0 });
			scanf("%d%d", &points[i].first, &points[i].second);
		}
		FOR(k, 0, n)
		{
			int ans = 5000;
			FOR(i, 1, 1 << n)
			{
				vector<pii> p;
				int cut = n;
				FOR(j, 0, n)
				{
					if (i & (1 << j))
					{
						cut--;
						p.push_back(points[j]);
					}
				}
				vector<pii> h = getConvexHull(p, p.size());
				bool found = false;
				FOR(j, 0, h.size())
				{
					if (h[j] == points[k])
					{
						found = true;
						break;
					}
				}
				FOR(j, 0, h.size() - 1)
				{
					if (onLine(points[k], h[j], h[j + 1]))
					{
						found = true;
						break;
					}
				}
				if (found)
				{
					ans = min(ans, cut);
				}
			}
			cout << ans << endl;
		}
	}
}