#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;

const int maxn = 1000 + 10;

int a[maxn];
int N;

int solve1() {
    int ans = 0;
    for (int i = 1; i < N; ++i) {
        if (a[i] < a[i - 1]) {
            ans += a[i - 1] - a[i];
        }
    }
    return ans;
}

int solve2() {
    int speed = 0;
    for (int i = 1; i < N; ++i) {
        if (a[i - 1] > a[i]) {
            speed = max(speed, a[i - 1] - a[i]);
        }
    }
    int cnt = 0;
    int left = 0;
    int ok = 1;
    for (int i = 0; i < N; ++i) {
        if (left > a[i]) {
            ok = 0;
            break;
        }
        if (i == N - 1) {
            break;
        }
        if (a[i] >= speed) {
            cnt += speed;
            left = a[i] - speed;
        } else {
            cnt += a[i];
            left = 0;
        }
    }
    assert(ok == 1);
    return cnt;
}

int main() {
    //freopen("A.in", "r", stdin);
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int testCount;
    scanf("%d", &testCount);
    for (int testId = 1; testId <= testCount; ++testId) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &a[i]);
        }
        printf("Case #%d: %d %d\n", testId, solve1(), solve2());
    }
}
