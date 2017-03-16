#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 2333
int num[MAX], n;

int solve1() {
    int ret = 0;
    for (int i = 1; i < n; i++) {
        if (num[i] < num[i - 1]) ret += (num[i - 1] - num[i]);
    }
    return ret;
}

int solve2() {
    int m = 0;
    for (int i = 1; i < n; i++) {
        if (num[i] < num[i - 1]) m = max(m, num[i - 1] - num[i]);
    }
    int ret = 0;
    for (int i = 0; i < n - 1; i++) {
        ret += min(num[i], m);
    }
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++) scanf("%d", &num[j]);
        printf("Case #%d: %d %d\n", i, solve1(), solve2());
    }
    return 0;
}
