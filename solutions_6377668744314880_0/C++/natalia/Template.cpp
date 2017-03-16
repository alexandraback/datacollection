#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

const int NMAX = 3005;

struct Point
{
    ll x, y;
    int id;
};

inline bool operator<(const Point& p1, const Point& p2)
{
    if (p1.x != p2.x) return p1.x < p2.x;
    return p1.y < p2.y;
}

inline bool operator==(const Point& p1, const Point& p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

int n, m;
Point p[NMAX], ch[NMAX];

Point p0;

ll det(ll x1, ll y1, ll x2, ll y2)
{
    return ll(x1) * y2 - ll(x2) * y1;
}
ll dist(const Point& p1, const Point& p2)
{
    return ll(p1.x - p2.x) * (p1.x - p2.x) + ll(p1.y - p2.y) * (p1.y - p2.y);
}

bool Cmp(const Point &p1, const Point &p2)
{
    ll d = det(p1.x - p0.x, p1.y - p0.y, p2.x - p0.x, p2.y - p0.y);
    if (d) return d > 0;
    return dist(p1, p0) < dist(p2, p0);
}
bool Cmp1(const Point &p1, const Point &p2)
{
    ll d = det(p1.x - p0.x, p1.y - p0.y, p2.x - p0.x, p2.y - p0.y);
    if (d) return d > 0;
    return dist(p1, p0) > dist(p2, p0);
}

bool moveRight(Point &p0, Point &p1, Point &p2)
{
    return det(p1.x - p0.x, p1.y - p0.y, p2.x - p0.x, p2.y - p0.y) < 0;
}

void convex_hull()
{
	if (n <= 2)
	{
		m = n;
		forn(i, m) ch[i] = p[i];
		return;
	}

	bool flag = true;

	for (int i = 2; i < n; i++)
		if (det(p[i].x - p[0].x, p[i].y - p[0].y, p[i].x - p[1].x, p[i].y - p[1].y)) flag = false;

	if (flag)
	{
		m = n;
		forn(i, m) ch[i] = p[i];
		return;
	}

    sort(p, p + n);
 
    int ind = 0;
    for1(i, n - 1)
    {
        if(p[i].x < p[ind].x || (p[i].x == p[ind].x && p[i].y < p[ind].y))
        {
            ind = i;
        }
    }
    swap(p[0], p[ind]);
    p0 = p[0];
    sort(p + 1, p + n, Cmp);
    int l = n - 1;
    while(l > 1 && det(p[l].x - p0.x, p[l].y - p0.y, p[l - 1].x - p0.x, p[l - 1].y - p0.y) == 0) --l;
    sort(p + l, p + n, Cmp1);

    ch[0] = p[0];
    ch[1] = p[1];
    m = 2;
    for(int i = 2; i < n; i++)
    {
        while(m > 1 && moveRight(ch[m - 2], ch[m - 1], p[i])) --m;
        ch[m++] = p[i];
    }

}


void solve(int test)
{
    printf("Case #%d:\n", test);

    int N; cin >> N;
    vector<Point> q(N);

    forn(i, N)
    {
    	cin >> q[i].x >> q[i].y;
    	q[i].id = i;
    }

    vector<int> ans(N);
    forn(i, N) ans[i] = N;

    for1(mask, (1 << N) - 1)
    {
    	n = 0;
    	int del = 0;
    	forn(i, N)
    	{
    		if (mask & (1 << i))
    		{
    			p[n++] = q[i];
    		}
    		else del++;
    	}
    	convex_hull();

    	forn(i, m)
    	{
    		ans[ch[i].id] = min(ans[ch[i].id], del);
    	}
    }

    forn(i, N)
    {
    	cout << ans[i] << endl;
    }


}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc;
    scanf("%d\n", &tc);
    forn(it, tc) solve(it + 1);
    
    return 0;
}
