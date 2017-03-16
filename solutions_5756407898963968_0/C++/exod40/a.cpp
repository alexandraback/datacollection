#include <cstdio>

int a[32];

void solve() {
    for (int i = 0; i < 32; i++) a[i] = 0;
    
    for (int i = 0; i < 2; i++) {
        int x, y;
        scanf("%d", &x);
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                scanf("%d", &y);
                
                if (j + 1 == x) {
                    a[y] ++;
                }
            }
        }
    }
    
    int cnt = 0;
    int res = 0;
    
    for (int i = 1; i <= 16; i++) {
        if (a[i] == 2) {
            ++ cnt;
            res = i;
        }
    }
    
    if (cnt == 1) {
        printf ("%d\n", res);
    } else {
        if (cnt == 0) {
            printf ("Volunteer cheated!\n");
        } else {
            printf ("Bad magician!\n");
        }
    }
}

int main() {
    int cases;
    
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++) {
        printf ("Case #%d: ", i);
        solve();
    }
    
    return 0;
}
