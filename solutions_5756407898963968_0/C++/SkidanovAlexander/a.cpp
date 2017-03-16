#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    int t = 1, tt;
    for (scanf("%d", &tt); t <= tt; ++ t) {
        int a, b;
        scanf("%d", &a);
        vector<int> va, vb;
        for (int i = 0; i < 4; ++ i) {
            for (int j = 0; j < 4; ++ j) {
                int x;
                scanf("%d", &x);
                if (i + 1 == a) {
                    va.push_back(x);
                }
            }
        }
        scanf("%d", &b);
        for (int i = 0; i < 4; ++ i) {
            for (int j = 0; j < 4; ++ j) {
                int x;
                scanf("%d", &x);
                if (i + 1 == b) {
                    vb.push_back(x);
                }
            }
        }

        vector<int> c;
        for (int i = 0; i < 4; ++ i) {
            for (int j  =0; j < 4; ++ j) {
                if (va[i] == vb[j]) c.push_back(va[i]);
            }
        }
        printf("Case #%d: ", t);
        if (c.size() == 0) printf("Volunteer cheated!");
        else if (c.size() > 1) printf("Bad magician!");
        else printf("%d", c[0]);
        printf("\n");
    }
    return 0;
}
