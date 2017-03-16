#include <stdio.h>
#include <algorithm>
using namespace std;

int v[1005];

int main(void) {
    int t;
    int n;
    int y, z;
    int delta;

    scanf(" %d", &t);

    for (int caso = 1; caso <= t; caso++) {
        y = z = 0;
        delta = 0;
        scanf(" %d", &n);

        for (int i = 0; i < n; i++) {
            scanf(" %d", &v[i]);
        }

        for (int i = 0; i < n - 1; i++) {
            y += max(0, v[i] - v[i + 1]);
            delta = max(delta, v[i] - v[i + 1]);
        }
        for (int i = 0; i < n - 1; i++) {
            z += min(v[i], delta);
        }

        printf("Case #%d: %d %d\n", caso, y, z);
    }
    return 0;
}
