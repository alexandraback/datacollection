#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

int run;
void solve() {
    int num;
    set<int> Set;
    scanf("%d", &num);
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            int x;
            scanf("%d", &x);
            if (i == num) {
                Set.insert(x);
            }
        }
    }
    scanf("%d", &num);
    int res = 0, number;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            int x;
            scanf("%d", &x);
            if (i == num) {
                if (Set.find(x) != Set.end()) {
                    res++;
                    number = x;
                }
            }
        }
    }
    printf("Case #%d: ", run);
    if (res == 1) {
        printf("%d\n", number);
    } else {
        if (res > 1) {
            puts("Bad magician!");
        } else {
            puts("Volunteer cheated!");
        }
    }
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int test;
    scanf("%d", &test);
    for (run = 1; run <= test; run++) {
        solve();
    }
    return 0;
}
