#include <cstdio>

bool is_done;
int p[2000];

inline bool valid(int n) {
    if (is_done) return false;
    int count = 0;
    for(int i = 0; i < n; i++)
        count += p[i];

    for(int i = 0; i < n; i++) {
        if (p[i] * 2 > count) {
            return false;
        }
    }
    return true;
}

inline void solve(int test) {
    printf("Case #%d:", test);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &p[i]);
    int count = 0;
    for(int i = 0; i < n; i++) count += p[i];

    while (count > 0) {
        int p1 = 0;
        for(int i = 1; i < n; i++) {
            if (p[p1] < p[i]) {
                p1 = i;
            }
        }
        int p2 = -1;

        for(int i = 0; i < n; i++) {
            if (i == p1) continue;
            if (p2 == -1 || p[p2] < p[i]) p2 = i;
        }
        
        is_done = false;
        {
            p[p1] -= 1;
            if (valid(n)) {
                printf(" %c", char(p1 + 'A'));
                count -= 1;
                continue;
            }
            else
                p[p1] += 1;
        }
        
        {
            p[p1] -= 1;
            p[p2] -= 1;

            if (valid(n)) {
                printf(" %c%c", char(p1 + 'A'), char(p2 + 'A'));
                count -= 2;
                continue;
            }
            else {
                p[p1] += 1;
                p[p2] += 1;
            }
        }
        throw;
    }

    puts("");
}

int main() {
    int testcount;
    scanf("%d", &testcount);
    for(int test = 0; test < testcount; test++) {
        solve(test + 1);
    }
}
