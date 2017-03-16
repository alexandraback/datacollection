/* base IO */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <fstream>
#include <sstream>

/* data structure */
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <bitset>

/* alrotihm and math */
#include <algorithm>
#include <random>
#include <cmath>

/* run-time */
#include <cstdlib>
#include <ctime>
#include <climits>

/* system dependent */
#include <sys/time.h>

using namespace std;

#define VI vector<int>
#define VD vector<double>
#define PII pair<int, int>
#define PDD pair<double, double>
#define PB push_back
#define MP make_pair
#define len(x) ((x).size())

const int inf = INT_MAX;
const long long inf_ll = 0x7f7f7f7f;
const double eps = 1e-8;

/*
 * 0 1 2
 * 3   4
 * 5 6 7
 */
const int bfs_dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int bfs_dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

/*
 *   3  
 * 2   0
 *   1  
 */
const int dfs_dy[] = {0, 1, 0, -1};
const int dfs_dx[] = {1, 0, -1, 0};

PII dir[] = {make_pair(0,1),make_pair(1,0),make_pair(0,-1),make_pair(-1,0)};
/* TC HEADER END */

#define sqr(x) ((x) * (x))
#define N 3005
using namespace std;
const double pi = acos(-1.0);
int n;
double r;
struct Point
{
	double x,y;
	Point(){}
	Point(double a,double b)
	{
		x = a;
		y = b;
	}
	double operator *(const Point p)
	{
		return x * p.x + y * p.y;
	}
	double operator ^(const Point p)
	{
		return x * p.y - y * p.x;
	}
	double norm() const
	{
		return sqrt(sqr(x) + sqr(y));
	}
	Point operator -(const Point p)
	{
		return Point(x - p.x,y - p.y);
	}
}p[N + 2];

int comp(const double &a)
{
	if(fabs(a) < eps)
		return 0;
	else if(a > eps)
		return 1;
	else
		return -1;
}
bool cmp1(const Point &a,const Point &b)
{
	return (comp(a.x - b.x) < 0) || (comp(a.x - b.x) == 0 && comp(a.y - b.y) < 0);
}
Point c;
bool cmp2(const Point &a,const Point &b)
{
	double theta1 = atan2((a.y - c.y),(a.x - c.x));
	double theta2 = atan2((b.y - c.y),(b.x - c.x));
	return (comp(theta1 - theta2) < 0) || (comp(theta1 - theta2) == 0 && comp(a.norm() - b.norm()) < 0);
}
double cha(Point a,Point b,Point c)
{
	return (b - c) ^ (a - c);
}
int now;
Point stack[N + 2];
void convex()
{
	if(n == 0)
		return ;
	stack[0] = p[0];
	now = 0;
	for(int i = 1;i < n;i++)
	{
		while(now >= 2 && comp(cha(p[i],stack[now],stack[now - 1])) < 0)
		{
			now--;
		}
		now++;
		stack[now] = p[i];
	}
}

int main() {
    int T;
    cin >> T;
    for(int _ = 1; _ <= T; _++) {
        int _n;
        cin >> _n;
        PII points[3005];
        int ans[3005];
        fill(ans, ans + _n, _n - 1);

        for(int i = 0; i < _n; i++) {
            cin >> points[i].first >> points[i].second;
        }
        for(int i = 0; i < _n; i++) {
            for(int j = 0; j < (1 << _n); j++) {
                if(((1 << i) & j) == 0) {
                    continue;
                }
                int mark = 0;
                now = 0;
                int count = 0;
                for(int k = 0; k < _n; k++) {
                    if((1 << k) & j) {
                        p[count].x = points[k].first;
                        p[count].y = points[k].second;
                        if(count > 0)
                        {
                            if(cmp1(p[count],c))
                            {
                                c = p[count];
                                mark = count;
                            }
                        }
                        else
                            c = p[0];
                        count++;
                    }
                }
                n = count;
                p[mark] = p[0];
                p[0] = c;
                sort(p + 1,p + n,cmp2);
                convex();
                bool flag = false;
                /*if(j == (1 << _n) - 1) {
                    cout << "!!!!: " << endl;
                    for(int k = 0; k < count; k++) {
                        cout << p[k].x << ' ' << p[k].y << endl;
                    }
                    cout << i << ": " << ' ' << count << ' ' << now + 1 << endl;
                    for(int k = 0; k <= now; k++) {
                        cout << stack[k].x << ' ' << stack[k].y << endl;
                    }
                }*/
                for(int k = 0; k <= now; k++) {
                    // cout << stack[i].x << ' ' << stack[i].y << endl;
                    /*if(stack[k].x == points[i].first && stack[k].y == points[i].second) {
                        flag = true;
                        break;
                    }*/
                    int next = k + 1;
                    if(next > now) next = 0;
                    if((stack[next].x - stack[k].x) * (stack[k].y - points[i].second) == 
                            (stack[next].y - stack[k].y) * (stack[k].x - points[i].first)) {
                        flag = true;
                    }
                }
                if(flag) {
                    ans[i] = min(ans[i], _n - count);
                }
            }
        }
        printf("Case #%d:\n", _);
        for(int i = 0; i < _n; i++) {
            cout << ans[i] << endl;
        }
    }
}
