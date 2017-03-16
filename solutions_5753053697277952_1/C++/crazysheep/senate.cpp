#include <cstdio>
#include <cstdlib>

int senators[30];

int main() {
    int T;
    scanf("%d", &T);
    for (int c = 1; c <= T; ++c) {
        int n;
        scanf("%d", &n);
        
        int total = 0;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &senators[i]);
            total += senators[i];
        }

        printf("Case #%d:", c);

        while (total) {
            int max = 0;
            for (int i = 0; i < n; ++i) {
                if (senators[i] > senators[max]) {
                    max = i;
                }
            }
            senators[max]--;
            total--;

            int second = -1;
            for (int i = 0; i < n; ++i) {
                if (senators[i] * 2 > total) {
                    second = i;
                    senators[second]--;
                    total--;
                    break;
                }
            }

            for (int i = 0; i < n; ++i) {
                if (senators[i] * 2 > total) {
                    printf("ah shit\n");
                }
            }

            if (second == -1) {
                printf(" %c", 'A' + max);
            } else {
                printf(" %c%c", 'A' + max, 'A' + second);
            }
        }
        
        printf("\n");
    }
}


