#include <cstdio>


int a[5][5], c[20];
int T, r1, r2;

int ans, nAns;

void reset() {
    for (int i = 0; i < 20; i++) {
        c[i] = 0;
    }
    nAns = ans = 0;
    return;
}


int main() {
    freopen ("q1.in", "r", stdin);
    freopen ("q1.out", "w", stdout);
    scanf ("%d", &T);
    for (int _z=0; _z < T; _z++) {
        printf ("Case #%d: ", _z+1);
        reset();
        scanf ("%d", &r1);
        r1--;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                scanf ("%d", &a[i][j]);
            }
        }
        for (int i = 0; i < 4; i++) {
            c[a[r1][i]]++;
        }
        scanf ("%d", &r2);
        r2--;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                scanf ("%d", &a[i][j]);
            }
        }
        for (int i = 0; i < 4; i++) {
            c[a[r2][i]]++;
        }
        for (int i = 1; i <= 16; i++) {
            if (c[i] == 2) {
                nAns++;
                ans = i;
            }
        }
        if (nAns == 0) {
            printf ("Volunteer cheated!\n");
        } else if (nAns == 1) {
            printf ("%d\n", ans);
        } else {
            printf ("Bad magician!\n");
        }
    }
    return 0;
}
