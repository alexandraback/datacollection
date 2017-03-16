#include <cstdio>
#include <set>

using namespace std;

#define for_each(s, v) for (__typeof((v).begin()) s = (v).begin(); s != (v).end(); ++s)

int ans[2], table[2][4][4];

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        for (int r = 0; r < 2; ++r) {
            scanf("%d", &ans[r]);
            --ans[r];
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    scanf("%d", &table[r][i][j]);
        }
        
        set <int> st[2];
        for (int k = 0; k < 2; ++k)
            for (int i = 0; i < 4; ++i)
                st[k].insert(table[k][ans[k]][i]);

        int siz = 0, lst = -1;
        for_each(it, st[0]) if (st[1].count(*it)) ++siz, lst = *it;

        printf("Case #%d: ", kase);
        if (siz == 0) {
            printf("Volunteer cheated!");
        }
        if (siz == 1) {
            printf("%d", lst);
        }
        if (siz > 1) {
            printf("Bad magician!");
        }
        printf("\n");
    }
}
