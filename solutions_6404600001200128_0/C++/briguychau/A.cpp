#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int values[1024];

void solve(int kase) {
    int n;
    scanf("%d", &n);

    memset(values, 0, sizeof(values));

    int maxdiff = 0;
    int totaldiff = 0;

    for (int i = 0; i < n; ++i) {
        int curr;
        scanf("%d", &curr);
        values[i] = curr;
        if (values[i-1] - curr > maxdiff) {
            maxdiff = (values[i-1] - curr);
        }
        if (values[i-1] - curr > 0) {
            totaldiff += (values[i-1] - curr);
        }
    }

    int constrate = 0;

    for (int i = 0; i < n-1; ++i) {
        constrate += min(maxdiff, values[i]);
    }

    printf("Case #%d: %d %d\n", kase, totaldiff, constrate);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}
