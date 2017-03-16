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
    int id;
    long long val;
    s(int id = 0, long long val = 0): id(id), val(val) {};
    bool operator<(const s &I) const {
        if(val == I.val) return id > I.id;
        return val > I.val;
    }
};
long long n, m;
long long num[100009];

long long cal(long long tm) {
    long long ret = 0;
    for(int i = 0; i < n; i++) {
        ret += tm / num[i];
    }
    return ret;
}

int MAIN() {
    scanf("%lld%lld", &n, &m);
    for(int i = 0; i < n; i++) scanf("%lld", &num[i]);
    if(m <= n) {
        printf("%lld\n", m);
        return 0;
    }
    long long sar = m;
    sar = max(sar, 0ll);
    long long l = 0, r = 0x3f3f3f3f3f3f3fll;
    long long st = 0;
    while(l <= r) {
        long long mid = (l + r) / 2;
        if(cal(mid) <= sar) {
            st = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    st -= 100000;
    st = max(st, 0ll);
//    printf("st %lld\n", st);
    priority_queue<s> q;
    while(!q.empty()) q.pop();
    for(int i = 0; i < n; i++) {
        q.push(s(i, 0 - st % num[i]));
        m -= st / num[i];
    }
//    printf("%lld   \n", m);
    while(m) {
        s a = q.top();
//        printf("%d %lld\n", a.id + 1, a.val);
        q.pop();
        a.val += num[a.id];
        q.push(a);
        m--;
        if(m == 0) {
            printf("%d\n", a.id + 1);
            return 0;
        }
    }
    return 0;
}

int main() {
    int cases;
    scanf("%d", &cases);
    int cc = 1;
    while(cases--) {
//    while(~scanf("%d", &n)) {
    
        printf("Case #%d: ", cc++);
        MAIN();
    }
    return 0;
}
