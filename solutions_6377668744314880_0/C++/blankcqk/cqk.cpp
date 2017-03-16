#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <time.h>
#define maxn 2005
#define maxm 1000005
#define eps 1e-7
#define mod 998244353
#define INF 0x3f3f3f3f
#define PI (acos(-1.0))
#define lowbit(x) (x&(-x))
#define mp make_pair
//#define ls o<<1
//#define rs o<<1 | 1
//#define lson o<<1, L, mid 
//#define rson o<<1 | 1, mid+1, R
#define pii pair<int, int>
#pragma comment(linker, "/STACK:16777216")
typedef long long LL;
typedef unsigned long long ULL;
//typedef int LL;
using namespace std;
LL qpow(LL a, LL b){LL res=1,base=a;while(b){if(b%2)res=res*base;base=base*base;b/=2;}return res;}
LL powmod(LL a, LL b){LL res=1,base=a;while(b){if(b%2)res=res*base%mod;base=base*base%mod;b/=2;}return res;}
// head

struct Point  
{  
    double x, y;  
    Point(double x = 0, double y = 0) : x(x), y(y) { }  
    bool operator < (const Point &a) const {    
        return a.x < x || (a.x == x && a.y < y);    
    }    
};  
typedef Point Vector;  
  
Vector operator + (Vector A, Vector B)     
{    
    return Vector(A.x + B.x, A.y + B.y);    
}    
Vector operator - (Vector A, Vector B)    
{    
    return Vector(A.x - B.x, A.y - B.y);    
}    
Vector operator * (Vector A, double p)    
{    
    return Vector(A.x * p, A.y * p);    
}    
Vector operator / (Vector A, double p)    
{    
    return Vector(A.x / p, A.y / p);    
}    
int dcmp(double x)    
{    
    if(fabs(x) < eps) return 0;    
    else return x < 0 ? -1 : 1;    
}    
double Dot(Vector A, Vector B)    
{    
    return A.x * B.x + A.y * B.y;    
}    
double Length(Vector A)    
{    
    return sqrt(Dot(A, A));    
}    
double Angle(Vector A, Vector B)    
{    
    return acos(Dot(A, B) / Length(A) / Length(B));    
}    
double Cross(Vector A, Vector B)    
{    
    return A.x * B.y - A.y * B.x;    
}   
int ConvexHull(Point *p, int n, Point *ch)    
{    
    sort(p, p+n);    
    int m = 0;    
    for(int i = 0; i < n; i++) {    
        while(m > 1 && Cross(ch[m-1] - ch[m-2], p[i] - ch[m-2]) < 0) m--;    
        ch[m++] = p[i];    
    }    
    int k = m;    
    for(int i = n-2; i >= 0; i--) {    
        while(m > k && Cross(ch[m-1] - ch[m-2], p[i] - ch[m-2]) < 0) m--;    
        ch[m++] = p[i];    
    }    
    if(n > 1) m--;    
    return m;    
} 

Point p[100], pp[100], res[100];
int n;

bool check(int i, int j)
{
	int cnt = 0;
	for(int k = 0; k < n; k++) {
		if((j >> k) & 1) continue;
		pp[cnt++] = p[k];
	}
	int m = ConvexHull(pp, cnt, res);
//	for(int k = 0; k < m; k++) printf("%d\n", dcmp(res[k].y - p[i].y));
	for(int k = 0; k < m; k++) if(dcmp(res[k].x - p[i].x) == 0 && dcmp(res[k].y - p[i].y) == 0) return true;
	return false;
}

void work(int _)
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
//	printf("PPPPPP %d\n", check(0, 0));
	printf("Case #%d:\n", _);
	for(int i = 0; i < n; i++) {
		int ans = 100;
		for(int j = 0; j < (1 << n); j++) {
			if((j >> i) & 1) continue;
			if(check(i, j)) {
				int t = 0;
				for(int k = 0; k < n; k++) t += ((j >> k) & 1);
				ans = min(ans, t);
			}
		}
		printf("%d\n", ans);
	}
}

int main()
{
//	freopen("input", "r", stdin);
//	freopen("output", "w", stdout);
	int _;
	scanf("%d", &_);
	for(int i = 1; i <= _; i++) work(i);

	return 0;
}
