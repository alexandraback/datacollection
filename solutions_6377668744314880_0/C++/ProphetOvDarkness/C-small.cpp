/*
*Sourav Sen Tonmoy
*University of Dhaka
*/

#include <bits/stdc++.h>

#define rep(i,n) for(i=0; i<n; i++)
#define repl(i,n) for(i=1; i<=n; i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin(); i!=(n).end(); i++)

#define sz(x) (int) x.size()
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define uu first
#define vv second
#define mem(x, y) memset(x, y, sizeof(x));

#define sdi(x) scanf("%d", &x)
#define sdii(x, y) scanf("%d %d", &x, &y)
#define sdiii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sdl(x) scanf("%lld", &x)
#define sdll(x, y) scanf("%lld %lld", &x, &y)
#define sdlll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define sds(x) scanf("%s", x)
#define pfi(x) printf("%d\n", x)
#define pfii(x, y) printf("%d %d\n", x, y)
#define pfiii(x, y, z) printf("%d %d %d\n", x, y, z)
#define pfl(x) printf("%lld\n", x)
#define pfll(x, y) printf("%lld %lld\n", x, y)
#define pflll(x, y, z) printf("%lld %lld %lld\n", x, y, z)

#define OK printf("ok\n")
#define DB(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> pii;

int setBit(int N, int pos) { return N=N | (1<<pos); }
int resetBit(int N, int pos) { return N= N & ~(1<<pos); }
bool checkBit(int N, int pos) { return (bool)(N & (1<<pos)); }

//int kx[] = {+2, +1, -1, -2, -2, -1, +1, +2};
//int ky[] = {+1, +2, +2, +1, -1, -2, -2, -1}; //Knight Direction
//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction


struct point {
    LL x, y;
    int idx;
};

const double pi = acos(-1);
const int maxn = 15;
point arr[maxn+5], ch[maxn+5], lowPoint, Copy[maxn+5];
int n, key;

inline int orientation(point p, point q, point r) {
    ///returns the orientation of point r in respect to line segment pq
    ///clockwise = 1, anticlockwise = -1, colinear = 0
    double val = (q.y - p.y) * (r.x - q.x) -
                 (q.x - p.x) * (r.y - q.y);

    if(fabs(val) == 0) return 0;
    else if(val < 0) return -1;
    else return 1;
}

inline LL sqDis(point a, point b) {
    return ((LL)(a.x-b.x))*((LL)(a.x-b.x)) + ((LL)(a.y-b.y))*((LL)(a.y-b.y));
}

bool comp(point a, point b) {
    int o = orientation(lowPoint, a, b);
    if(o == -1) return true;
    else if(o == 0 && sqDis(lowPoint, a) < sqDis(lowPoint, b)) return true;
    else return false;
}

inline bool isSame(point a, point b) {
    if(a.x == b.x && a.y == b.y) return true;
    else return false;
}

inline void compress() {
    ///removes consequetive colinear points and same points from the convex hull
    int i, j;
    for(i=1, j=1; i<key; i++) {
        int o = orientation(ch[j-1], ch[i], ch[(i+1)%key]);
        if(o || (!o && isSame(ch[j-1], ch[(i+1)%key]))) ch[j++] = ch[i];
    }
    key = j;
}

inline void grahamScan(unsigned int mask, bool dbg) {
    int i, j, lowIdx;
    int nn;
    point newArr[n];

    nn = n - __builtin_popcount(mask);
    j = 0;
    rep(i, n) if(checkBit(mask, arr[i].idx) == 0) newArr[j++] = arr[i];

//    if(dbg) {
//        rep(i, nn) cout << newArr[i].x << " " << newArr[i].y << endl;
//        puts("------------");
//    }

    if(nn<=3) {
        rep(i, nn) ch[i] = newArr[i];
        key = nn;
        compress();
        return;
    }

    ///finding the bottom-most point, taking the left-most in case of a tie
    ///and moving this point to the first position
    lowPoint = {INT_MAX, INT_MAX};
    rep(i, nn) {
        if(newArr[i].y < lowPoint.y || (newArr[i].y == lowPoint.y && newArr[i].x < lowPoint.x)) {
            lowPoint = newArr[i];
            lowIdx = i;
        }
    }
    swap(newArr[lowIdx], newArr[0]);

    ///sorting the other n-1 points in anticlockwise direction with respect to lowPoint
    ///if two points are colinear with lowPoint, then the closest one is chosen
    sort(newArr+1, newArr+nn, comp);

    ///first three points are inserted into ch[], which works like a stack
    rep(i, 3) ch[i] = newArr[i];
    j = 3;

    for(i=3; i<nn; i++) {
        ///j is decremented while the new point makes
        ///a clockwise turn or is colinear with respect to the last two points
        ///otherwise the new point is added to ch[]
        while(j>=2 && orientation(ch[j-2], ch[j-1], newArr[i]) != -1) j--;
        ch[j++] = newArr[i];
    }
    key = j;

    compress();
}

inline bool isOnSegment(point p, point q, point r) {
    ///checks whether point q is on the line segment pr
    if( (q.x >= min(p.x, r.x) && q.x <= max(p.x, r.x)) &&
        (q.y >= min(p.y, r.y) && q.y <= max(p.y, r.y)) ) return true;
    else return false;
}

inline bool check(unsigned int mask, int idx) {
    int i;
    grahamScan(mask, false);
    if(key < 3) return false;
//    rep(i, key) cout << ch[i].x << " " << ch[i].y << endl; puts("-------");
    rep(i, key) {
        if(isSame(ch[i], Copy[idx])) return true;
        if(orientation(ch[i], ch[(i+1)%key], Copy[idx]) == 0 && isOnSegment(ch[i], Copy[idx], ch[(i+1)%key])) return true;
    }
    return false;
}

bool checkCorner() {
    grahamScan(0, false);
    if(key < 3) return false;
    else return true;
}

int solve(int idx) {
    if(n <= 3) return n;
    if(!checkCorner()) return n;
    unsigned int i, loop = 1 << n;
    rep(i, loop) {
        if(check(i, idx)) return __builtin_popcount(i);
    }
}

int main() {
    freopen("C-small.in","r",stdin);
    freopen("C-small-out.out","w",stdout);

    int test, kase=1, i;

    sdi(test);
    while(test--) {
        sdi(n);
        rep(i, n) {
            sdll(arr[i].x, arr[i].y);
            arr[i].idx = i;
        }
        rep(i, n) Copy[i] = arr[i];
        printf("Case #%d:\n", kase++);
        rep(i, n) pfi(solve(i));
    }

    return 0;
}

/*
1
8
3 9
0 0
10 0
10 10
0 10
2 3
6 2
4 5
*/
