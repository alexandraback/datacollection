#include <cstdio>
#include <algorithm>
using namespace std;

int m[1000];

int solve1(int n) {
    int sum = 0;
    for(int i = 0; i + 1 < n; i++)
        if(m[i] > m[i + 1])
            sum += m[i] - m[i + 1];
    return sum;
}

int solve2(int n) {
    int max_diff = 0;
    for(int i = 0; i + 1 < n; i++)
        if(m[i] > m[i + 1])
            max_diff = max(max_diff, m[i] - m[i + 1]);
    int sum = 0;
    for(int i = 0; i + 1 < n; i++)
        sum += min(m[i], max_diff);
    return sum;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        for(int j = 0; j < n; j++)
            scanf("%d", m + j);
        printf("Case #%d: %d %d\n", i, solve1(n), solve2(n));
    }
}
