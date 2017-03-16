/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com
	> Created Time: 2015年04月18日 星期六 11时09分20秒
 ************************************************************************/

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <cassert>
// #pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define eps 1e-8
#define x first
#define y second
#define MAXN 3005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
const double PI = acos(-1.0);
int T, N, Cas = 1, ans[MAXN];

PII a[MAXN];

int cal(int x0, int x1, int y0, int y1) {
    int ans0 = 0, ans1 = 0;
    int tx = x1 - x0, ty = y1 - y0;

    for(int i = 1; i <= N; i++) {
        int tx1 = a[i].x - x0, ty1 = a[i].y - y0;
        int tmp = tx1 * ty - ty1 * tx;
        if(tmp < 0) ans0++;
        if(tmp > 0) ans1++;
    }
    return min(ans0, ans1);
}



int gao(int id) {
    int res = 1e9;
    for (int i = 1; i <= N; i ++) {
        if (i != id) {
            res = Min(res, cal(a[i].x, a[id].x, a[i].y, a[id].y));
        }
    }
    return res;
}

void small_task() {
    memset(ans, 0, sizeof(ans));
    if (N > 1) {
        for (int i = 1; i <= N; i ++) {
            ans[i] = gao(i);
        }
    }
}

void work() {
    printf("Case #%d:\n", Cas ++);
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    small_task();
    for (int i = 1; i <= N; i ++) {
        printf("%d\n", ans[i]);
    }
}
int main() {
    scanf("%d", &T);
    while (T --) {
        work();
    }
    return 0;
}
