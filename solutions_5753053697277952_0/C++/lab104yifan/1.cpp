#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 30;
int T, n, p[N];

struct SB {
    int cnt, id;
    SB() {}
    SB(int cnt, int id) : cnt(cnt), id(id) {}
    bool operator < (const SB& c) const {
        return cnt < c.cnt;
    }
} u;

priority_queue<SB> Q;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int cas = 0;
    scanf("%d", &T);
    while (T--) {
        int tot = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            Q.push(SB(p[i], i));
            tot += p[i];
        }
        printf("Case #%d:", ++cas);
        while (!Q.empty()) {
            if (tot % 2) {
                u = Q.top(); Q.pop();
                printf(" %c", u.id + 'A');
                u.cnt--;
                if (u.cnt) Q.push(u);
                tot--;
            } else {
                u = Q.top(); Q.pop();
                printf(" %c", u.id + 'A');
                u.cnt--;
                if (u.cnt) Q.push(u);
                u = Q.top(); Q.pop();
                printf("%c", u.id + 'A');
                u.cnt--;
                if (u.cnt) Q.push(u);
            }
        }
        printf("\n");
    }
    return 0;
}
