#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define FI first
#define SE second
using namespace std;
typedef long long LL;
const int N = 3005;

struct Vector {
    LL x,y;
    inline void read() { scanf("%I64d%I64d", &x, &y); }
    Vector(LL _x = 0, LL _y = 0) { x = _x; y = _y; }
    Vector operator +(Vector a) const { return Vector(x + a.x, y + a.y); }
    Vector operator +=(Vector a) { return *this = *this + a; }
    Vector operator -(Vector a) const { return Vector(x - a.x, y - a.y); }
    Vector operator -=(Vector a) { return *this = *this - a; }
    bool operator <(const Vector a) const { if(x == a.x) return y < a.y; return x < a.x; }
    double len() const{ return sqrt(x * x + y * y); }
    double angle() const { return atan2(y, x); }
} p[N];
int n;
inline LL cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

inline int get_convex(Vector *p,Vector *convex,int n)
{
    sort(p,p+n);
    int cnt=0;
    for(int i=0;i<n;++i)
    {
        while(cnt>=2&&cross(convex[cnt-1]-p[i],convex[cnt-2]-p[i])<=0) --cnt;
        convex[cnt++]=p[i];
    }
    int half=cnt;
    for(int i=n-2;i>=0;--i)
    {
        while(cnt-half>=1&&cross(convex[cnt-1]-p[i],convex[cnt-2]-p[i])<=0) --cnt;
        convex[cnt++]=p[i];
    }
    return cnt-1;
}

int bit_count(int x) {
    int res = 0;
    for(; x; x ^= x & -x) ++res;
    return res;
}

Vector tmp[N], con[N];
bool check(int st, int x) {
    int cc = 0;
    for(int i = 0; i < n; ++i) {
        if(!((st >> i) & 1)) tmp[cc++] = p[i];
    }
    int nn = get_convex(tmp, con, cc);
    if(nn <= 2) return 1;
    for(int i = 0; i < nn; ++i) {
        int a = i, b = (i + 1) % nn;
        if(cross(p[x] - con[a], p[x] - con[b]) == 0) return 1;
    }
    return 0;
}

int solve(int x) {
    int res = INF;
    for(int i = 0; i < (1 << n); ++i) {
        if((i >> x) & 1) continue;
        if(bit_count(i) >= res) continue;
        if(check(i, x)) res = bit_count(i);
    }
    return res;
}

int main() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) p[i].read();
        printf("Case #%d:\n", ca);
        for(int i = 0; i < n; ++i) printf("%d\n", solve(i));
    }
    return 0;
}
