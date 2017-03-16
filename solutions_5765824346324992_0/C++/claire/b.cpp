#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
struct A {
    int t, id;
    A(int a = 0, int b = 0): t(a), id(b) {}
    bool operator < (const A &a) const{
        if (t != a.t) return t > a.t;
        return id > a.id;
    }
};
const int N = 1100;
int a[N];
priority_queue<A> q;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int o, n, m, cas = 0;
    scanf("%d", &o);
    while (o--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int k = 1;
        for (int i = 1; i <= n; i++) {
            k = k * a[i] / gcd(k , a[i]);
        }
        int p = 0;
        for (int i = 1; i <= n; i++) {
            p += k / a[i];
        }
        m %= p;
        if (m == 0) m = p;
        //cout<<m<<endl;
        while (!q.empty())
            q.pop();
        A tmp;
        for (int i = 1; i <= n; i++) {
            tmp.t = 0;
            tmp.id = i;
            q.push(tmp);
        }
        int res;
        for (int i = 1; i <= m; i++) {
            tmp = q.top();
            q.pop();
            if (i == m) res = tmp.id;
            tmp.t += a[tmp.id];
            q.push(tmp);
        }
        printf("Case #%d: %d\n", ++cas, res);
    }
    return 0;
}