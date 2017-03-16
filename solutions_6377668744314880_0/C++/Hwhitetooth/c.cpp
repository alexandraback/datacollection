/*
 * Problem : 
 * Author : Hwhitetooth
 * Date : 
 * Result :
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

const int N = 3000 + 10;
const double EPS = 1e-10;

struct Point {
	double x, y;
	int id;
	
	int operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
} a[N], st[N];
vector<Point> b, hull;
int top;
int ans[N];
int n;
int testCases;

double cross(const Point &o, const Point &p, const Point &q) {
	double dx1 = p.x - o.x, dy1 = p.y - o.y;
	double dx2 = q.x - o.x, dy2 = q.y - o.y;
	return dx1 * dy2 - dx2 * dy1;
}

void graham(vector<Point> &a) {
	int m = a.size();
	vector<Point> hull;
//	sort(a.begin(), a.end());
	top = 0;
	for (int i = 0; i < m; ++i) {
		while (top > 1 && cross(st[top - 1], st[top], a[i]) > EPS) {
			--top;
		}
		st[++top] = a[i];
	}
	for (int i = 1; i < top; ++i) {
		hull.push_back(st[i]);
	}
	top = 0;
	for (int i = m - 1; i >= 0; --i) {
		while (top > 1 && cross(st[top - 1], st[top], a[i]) > EPS) {
			--top;
		}
		st[++top] = a[i];
	}
	for (int i = 1; i < top; ++i) {
		hull.push_back(st[i]);
	}
	for (int i = 0; i < (int)hull.size(); ++i) {
		ans[hull[i].id] = min(ans[hull[i].id], n - m);
	}
}

void dfs(int x) {
	if (x == n) {
		graham(b);
		return;
	}
	dfs(x + 1);
	b.push_back(a[x]);
	dfs(x + 1);
	b.pop_back();
}

int main() {
	scanf("%d", &testCases);
	for (int _ = 1; _ <= testCases; ++_) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf", &a[i].x, &a[i].y);
			a[i].id = i;
			ans[i] = n - 1;
		}
		sort(a, a + n);
		dfs(0);
		printf("Case #%d:\n", _);
		for (int i = 0; i < n; ++i) {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}