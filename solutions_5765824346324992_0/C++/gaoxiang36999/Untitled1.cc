#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <limits.h>
#include <iostream>
#include <queue>
#define MAXN 1010
using namespace std;
typedef long long LL;
struct Node {
    int mm, id;
    bool operator < (const Node &a) const {
        if(mm != a.mm) return mm > a.mm;
        else
            return id > a.id;
    }
};
LL a[MAXN];
int main() {
    freopen("in.in", "r", stdin);
    freopen("Bout.out", "w", stdout);
    int t;
    scanf("%d", &t);
    int m, n;
    int numCase = 1;
    while(t--) {
        LL sum = 1;
        scanf("%d%d", &m, &n);
        for(int i = 0; i < m; i++) {
            cin >> a[i];
            sum *= a[i];
        }
        LL G = a[0];
        for(int i = 1; i < m; i++) {
            G = __gcd(a[i], G);
        }
        int lcm = sum / G;
        printf("Case #%d: ",numCase++);
        if(m == 1) {
            printf("1\n");
            continue;
        } else {
            int s = 0;
            for(int i = 0; i < m; i++) s += (lcm / a[i]);
            int num = n % s;
            if(num == 0) num = s;
            priority_queue<Node> Q;
            while(!Q.empty()) Q.pop();
            LL ans = -1;
            for(int i = 0; i < m; i++) {
                Node now;
                now.id = i;
                now.mm = 0;
                Q.push(now);
            }
            for(int i = 0; i < num; i++) {
                Node now = Q.top(); Q.pop();
                ans = now.id + 1;
                now.mm += (a[now.id]);
                Q.push(now);
            }
            cout << ans << endl;
        }
    }
    return 0;
}
