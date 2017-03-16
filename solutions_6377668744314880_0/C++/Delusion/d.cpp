/*
 * Author: Farhad Shahmohammadi
 */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <queue>

using namespace std;

#define int long long

#define FOR(i, s, n) for(int i=s; i<(int)(n); i++)
#define REP(i, n) FOR(i, 0, n)
#define REV(i, n) for(int i=n-1; i>=0; --i)
#define show(x) cerr << #x << '=' << x << endl;
#define sh(x) cerr << #x << '=' << x << ' ';
#define sh2(x, y) {sh(x)show(y)}
#define sh3(x, y, z) {sh(x)sh(y)show(z)}
#define pb push_back
#define CL cerr << "--------------------" << endl;
#define PII pair<int, int>

const int MAX = 3000 + 10;
const int INF = (int) 1e9;

struct Point
{
	int x, y, idx;
	Point(){}
	Point(int x, int y, int idx):x(x), y(y), idx(idx){}
	
	bool operator < (const Point &p) const
	{
		if(x != p.x)
			return x < p.x;
		return y < p.y;
	}

	Point operator - (const Point & p)
	{
		return Point(x - p.x, y - p.y, -1);
	}

	friend ostream &operator << (ostream &cout, const Point &p)
	{
		cout << "(" << p.x << "," << p.y << ")";
		return cout;
	}
}p[MAX], tmp[MAX], c[2*MAX];
bool mark[MAX];
int ans[MAX];
int n;

int Cross(Point a, Point b)
{
	return a.x * b.y - a.y * b.x;
}

//int ConvexHull(Point *p, int n, int idx, int pass)
vector<Point> ConvexHull(Point *p, int n, int idx, int pass)
{
	//cerr << "--------------------------" << endl;
	//sh2(idx, pass);
	int k = 0;
	int sum = 0;
	fill (mark, mark + n, 0);
	REP(i, n)
	{
		bool flag = 0;
		while(k >= 2 && Cross(c[k-1] - c[k-2], p[i] - c[k-2]) < 0)
		{
			if(c[k-1].idx != idx || pass != 0)
				k --;
			else
			{
				flag = 1;
				break;
			}
		}
		if(!flag)
			c[k++] = p[i];
		else
		{
			if(!mark[i])
				sum ++;
			mark[i] = 1;
		}
	}
	int l = k + 1;
	REV(i, n-1)
	{
		bool flag = 0;
		while(k >= l && Cross(c[k-1] - c[k-2], p[i] - c[k-2]) < 0)
		{
			if(c[k-1].idx != idx || pass != 1)
				k --;
			else
			{
				flag = 1;
				break;
			}
		}
		if(!flag)
			c[k++] = p[i];
		else
		{
			if(!mark[i])
				sum ++;
			mark[i] = 1;
		}
	}
/*	show(idx);
	show(sum);
	REP(i, k)
		cerr << c[i].idx << " ";
	cerr << endl;
*/
	vector<Point> ret;
	REP(i, k)
		ret.pb(c[i]);
	return ret;
//	return sum;
}

#undef int
int main()
#define int long long
{
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	REP(Test, T)
	{
		cin >> n;
		REP(i, n)
		{
			int x, y;
			cin >> x >> y;
			p[i] = Point(x, y, i);
		}
		sort(p, p+n);
		fill(ans, ans+n, INF);
		cout << "Case #" << Test + 1 << ":" << endl;
		REP(i, (1<<n))
		{
			int m = 0;
			int rem = 0;
			REP(j, n)
			{
				if(i & (1<<j))
					tmp[m++] = p[j];
				else
					rem ++;
			}
			vector<Point> res = ConvexHull(tmp, m, -1, -1);
			REP(j, res.size())
				ans[res[j].idx] = min(ans[res[j].idx], rem);
		}
		REP(i, n)
			cout << ans[i] << endl;
	}
}


