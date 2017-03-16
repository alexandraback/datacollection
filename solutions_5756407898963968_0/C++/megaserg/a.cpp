#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long int64;
#define PB(a) push_back(a)
#define MP(a, b) make_pair(a, b)
#define PROBLEM "A"

int main() {
    freopen(PROBLEM ".in", "rt", stdin);
    freopen(PROBLEM ".out", "wt", stdout);

    int T;
    scanf("%d\n", &T);

    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);

        int row1;
        scanf("%d", &row1);

        bool mark1[32];
        memset(mark1, 0, sizeof(mark1));
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                int x;
                scanf("%d", &x);
                if (i == row1) {
                    mark1[x] = true;
                }
            }
        }

        int row2;
        scanf("%d", &row2);

        bool mark2[32];
        memset(mark2, 0, sizeof(mark2));
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                int x;
                scanf("%d", &x);
                if (i == row2) {
                    mark2[x] = true;
                }
            }
        }

        int count = 0;
        int ans = 0;
        for (int p = 1; p <= 16; p++) {
            if (mark1[p] && mark2[p]) {
                count++;
                ans = p;
            }
        }

        if (count == 1) {
            printf("%d", ans);
        } else if (count == 0) {
            printf("Volunteer cheated!");
        } else {
            printf("Bad magician!");
        }

        printf("\n");
    }

    return 0;
}
