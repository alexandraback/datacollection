#include <stdio.h>

int T;
int n;
int num[1100];
int ans1;
int ans2;
int max;

int main()
{
    scanf("%d", &T);
    for (int z = 1; z <= T; z++) {
        ans1 = 0;
        ans2 = 0;
        max = 0;

        scanf("%d%d", &n, num);
        for(int i = 1; i < n; i++) {
            scanf("%d", num + i);
            if (num[i] < num[i-1]) {
                int temp = num[i-1] - num[i];
                if (temp > max) {
                    max = temp;
                }
                ans1 += temp;
            }
        }

        for(int i = 1; i < n; i++) {
            if (num[i-1] < max) {
                ans2 += num[i-1];
                num[i-1] = 0;
            } else {
                ans2 += max;
                num[i-1] -= max;
            }

            if (num[i] < num[i-1]) {
                ans2 += num[i-1] - num[i];
            }
        }

        printf("Case #%d: %d %d\n", z, ans1, ans2);
    }
    return 0;
}
