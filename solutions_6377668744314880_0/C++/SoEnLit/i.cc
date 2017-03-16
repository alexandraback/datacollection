#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <cassert>
#include <map>
#define INF 0x3f3f3f3f
#define mem(a, b) memset((a), (b), sizeof(a))

using namespace std;

const double eps = 1e-8;
const long long mod = 1000000007ll;
const long long _3 =   333333336ll;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

long long fpow(long long a, long long b) {
    long long ret = 1;
    while(b) {
        if(b % 2 == 1) {
            ret *= a;
            ret %= mod;
        }
        a = a * a;
        a %= mod;
        b /= 2;
    }
    return ret;
}

double sqr(double a) {
    return a * a;
}

const double pi = acos(-1.0);

struct s{
    long long x, y;
    double agl;
    s(long long x = 0, long long y = 0): x(x), y(y){};
    bool operator<(const s &I) const {
        return agl < I.agl;
    }
}num[100009];
int n;
double aa[100009];

double cal(double a) {
    return a;
}

double gao(double a) {
    if(a > pi - eps) return a - 2 * pi;
    return a;
}

int MAIN() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld%lld", &num[i].x, &num[i].y);
    }
    for(int i = 0; i < n; i++) {
        if(i) swap(num[0], num[i]);
        for(int j = 1; j < n; j++) {
            aa[j] = gao(atan2((double)num[j].y - num[0].y, (double)num[j].x - num[0].x));
            aa[j + n - 1] = aa[j] + 2 * pi;
        }
        sort(aa + 1, aa + 2 * n - 1);
//        for(int j = 1; j < n; j++) {
//            printf("%.2f ", aa[j]);
//        }
//        putchar(10);
        int ans = n;
        int p = 1;
        int cc = 0;
        for(int j = 1; j < 2 * n - 1; j++) {
            while(p < 2 * n - 1 && cal(aa[p] - aa[j]) < pi + eps) {
                p++;
                cc++;
            }
            if(p == 2 * n - 1) break;
            ans = min(ans, min(n - 1 - (p - j), p - j));
            cc--;
        }
        printf("%d\n", ans == n ? 0 : ans);
        if(i) swap(num[0], num[i]);
    }
    return 0;
}

int main() {
    int cases;
    scanf("%d", &cases);
    int cc = 1;
    while(cases--) {
//    while(~scanf("%d", &n)) {
    
        printf("Case #%d:\n", cc++);
        MAIN();
    }
    return 0;
}
