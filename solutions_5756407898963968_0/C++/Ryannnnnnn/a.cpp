#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define foreach(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair

int a[2][4][4], r[2];

int main() {
    int caseN;
    scanf("%d", &caseN);
    for (int caseI = 1; caseI <= caseN; caseI++)
    {
        printf("Case #%d: ", caseI);

        rep(k, 2) {
            scanf("%d", &r[k]); r[k]--;
            rep(i, 4) rep(j, 4) {
                scanf("%d", &a[k][i][j]);
            }
        }
        int good_k = -1;
        rep(k, 17) {
            bool flag = false;
            for (int i = 0; i < 4; i++)
                if (a[0][r[0]][i] == k) flag = true;
            if (!flag) continue;
            flag = false;
            for (int i = 0; i < 4; i++)
                if (a[1][r[1]][i] == k) flag = true;
            if (!flag) continue;
            if (good_k != -1) {
                good_k = -2;
                break;
            }
            good_k = k;
        }
        if (good_k == -1) {
            printf("Volunteer cheated!\n");
        } else
        if (good_k == -2) {
            printf("Bad magician!\n");
        } else {
            printf("%d\n", good_k);
        }
    }

    return 0;
}
