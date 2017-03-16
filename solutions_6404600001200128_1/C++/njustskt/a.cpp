/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com
	> Created Time: 2015年04月18日 星期六 09时01分43秒
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
#define MAXN 10005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
const double PI = acos(-1.0);
int T, Cas = 1, N, a[MAXN], b[MAXN];

LL res1, res2, cnt;

bool check(LL x) {
    for (int i = 2; i <= N; i ++) {
        if (a[i - 1] - x > a[i]) {
            return false;
        }
    }
    return true;
}

void gao() {
    LL l = 0, r = 100000000;
    while (r - l > 1) {
        LL mid = (r + l) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (check(l)) {
        cnt = l;
    } else {
        cnt = r;
    }
}

void small_task() {
    cnt = 10000000;
    for (int i = 2; i <= N; i ++) {
        if (a[i] < a[i - 1]) {
            int value = a[i - 1] - a[i];
            value = value / 10;

        }
    }
}

void work() {
    printf("Case #%d: ", Cas ++);
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &a[i]);
    }
    res1 = 0, res2 = 0;
    for (int i = 2; i <= N; i ++) {
        if (a[i] < a[i - 1]) {
            res1 = res1 + a[i - 1] - a[i];
        }
    }
    gao();
  //  small_task();
    for (int i = 1; i <= N; i ++) {
        b[i] = a[i];
    }
    for (int i = 1; i < N; i ++) {
        res2 = res2 + Min(cnt, (LL)b[i]);
    }
    cout << res1 << " " <<  res2 << endl;
}
int main() {
    scanf("%d", &T);
    while (T --) {
        work();
    }
    return 0;
}
