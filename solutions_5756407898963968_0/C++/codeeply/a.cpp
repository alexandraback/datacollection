#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

#define type_assign(a, b) \
    typeof(b) a = b
#define iterate(a, b) \
    for (type_assign(a, b.begin()); a != b.end(); ++a)

const int N = 4;
int a[N][N], b[N][N];
int na, nb;

int main() {
    int t, i, j, k, nc = 0;
    scanf("%d", &t);
    while (t--) {
        map<int, int> my;

        scanf("%d", &na);
        for (i = 0; i < 4; ++i) {
            for (j = 0; j < 4; ++j) {
                scanf("%d", &a[i][j]);
                if (i == na - 1) {
                    my[a[i][j]]++;
                }
            }
        }
        scanf("%d", &nb);
        for (i = 0; i < 4; ++i) {
            for (j = 0; j < 4; ++j) {
                scanf("%d", &b[i][j]);
                if (i == nb - 1) {
                    my[b[i][j]]++;
                }
            }
        }
        if (my.size() == 8) {
            printf("Case #%d: Volunteer cheated!\n", ++nc);
        } else if (my.size() == 7) {
            iterate(itr, my) {
                if (itr->second == 2) {
                    printf("Case #%d: %d\n", ++nc, itr->first);
                }
            }
        } else {
            printf("Case #%d: Bad magician!\n", ++nc);
        }
    }
    return 0;
}
