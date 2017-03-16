/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com
	> Created Time: 2015年04月18日 星期六 09时40分02秒
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
#define MAXN 1005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
const double PI = acos(-1.0);
int T, Cas = 1, B, N;

int a[MAXN];

bool vis[MAXN];

LL check(LL x) {
    LL cnt = 0;
    for (int i = 1; i <= B; i ++) {
        cnt = cnt + x / a[i]; 
        if (x % a[i] != 0) {
            cnt ++;
        }
    }
    return cnt;
}

LL gao() {
    LL l = 1, r = 1e18;
    while (r - l > 1) {
        LL mid = (l + r) >> 1;
        LL ans = check(mid);
        if (ans < N) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (check(l) == N) {
        return l;
    } else {
        return r;
    }
}

bool solve(int x, LL q) {
    LL cnt = 0;
    for (int i = 1; i <= x; i ++) {
        if (q % a[i]) {
            cnt = cnt + q / a[i] + 1;
        } else {
            cnt = cnt + q / a[i];
        }
    }
    for (int i = x + 1; i <= B; i ++) {
        if ((q - 1) % a[i]) {
            cnt = cnt + (q - 1) / a[i] + 1;
        } else {
            cnt = cnt + (q - 1) / a[i];
        }
    }
    if (cnt == N) {
        return true;
    } else {
        return false;
    }
}

void work() {
    printf("Case #%d: ", Cas ++);
    scanf("%d %d", &B, &N);
    for (int i = 1; i <= B; i ++) {
        scanf("%d", &a[i]);
    }
    LL c2 = gao();
    for (int i = 1; i <= B; i ++) {
        if (solve(i, c2)) {
            printf("%d\n", i); return ;
        }
    }
}
int main() {
    scanf("%d", &T);
    while (T --) {
        work();
    }
    return 0;
}
