#include <cstdio>

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    FO(Z,0,T) {
        printf("Case #%d: ", Z+1);
        int x;
        scanf("%d", &x);
        int M0 = 0;
        FO(i,1,5) {
            FO(j,0,4) {
                int y;
                scanf("%d", &y);
                if (i == x) {
                    M0 |= (1<<y);
                }
            }
        }
        scanf("%d", &x);
        int M1 = 0;
        FO(i,1,5) {
            FO(j,0,4) {
                int y;
                scanf("%d", &y);
                if (i == x) {
                    M1 |= (1<<y);
                }
            }
        }

        int m = M0&M1;

        if (__builtin_popcount(m) == 0) {
            printf("Volunteer cheated!\n");
        } else if (__builtin_popcount(m) == 1) {
            FO(i,0,20) if (m & (1<<i)) printf("%d\n", i);
        } else {
            printf("Bad magician!\n");
        }
    }

    return 0;
}

