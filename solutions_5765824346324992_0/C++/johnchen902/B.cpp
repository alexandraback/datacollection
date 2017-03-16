#include <cstdio>
#include <cassert>
using namespace std;

int b;
int m[1000];

int cut(long long t) {
    if(t < 0)
        return 0;

    int sum = 0;
    for(int i = 0; i < b; i++)
        sum += t / m[i] + 1;
    return sum;
}

int solve(int n) {
    long long t = 1;
    while(cut(t) < n)
        t *= 2;
    long long l = 0, r = t;
    while(l < r) {
        long long mid = (l + r) / 2;
        if(cut(mid) < n)
            l = mid + 1;
        else
            r = mid;
    }
    int k = n - cut(r - 1);
    for(int i = 0; i < b; i++)
        if(r % m[i] == 0)
            if(--k == 0)
                return i + 1;
    assert(false);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        int n;
        scanf("%d %d", &b, &n);
        for(int j = 0; j < b; j++)
            scanf("%d", m + j);
        printf("Case #%d: %d\n", i, solve(n));
    }
}
