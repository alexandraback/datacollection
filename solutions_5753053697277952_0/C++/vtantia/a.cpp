#include <iostream>
#include <stdio.h>
#include <algorithm>
#define s(n) scanf("%d", &n)

using namespace std;

bool decr(pair<int, char> i, pair<int, char> j) { return i.first > j.first; }

int main() {
    int n, t;
    pair<int, char> P[27];
    s(t);
    for (int i = 1; i <= t; i++) {
        s(n);
        int ctr = 0;
        for (int j = 1; j <= n; j++) {
            s(P[j].first);
            P[j].second = 'A' - 1 + j;
            // if(P[j]!=0)
        }
        printf("Case #%d: ", i);
        do {
            sort(P + 1, P + n + 1, decr);
            if (P[1].first == 0)
                break;
            if (P[1].first == P[2].first) {
                if (P[4].first != 0 || P[3].first != 1 || P[1].first != 1) {
                    P[1].first -= 1;
                    P[2].first -= 1;
                    printf("%c%c ", P[1].second, P[2].second);
                } else {
                    P[1].first -= 1;
                    printf("%c ", P[1].second);
                }
            } else {
                P[1].first -= 1;
                printf("%c ", P[1].second);
            }

        } while (1);
        printf("\n");
    }

    return 0;
}
