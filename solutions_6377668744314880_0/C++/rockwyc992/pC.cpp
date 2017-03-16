#include <stdio.h>

int T;
int n;
int x[3100];
int y[3100];
int no[3100];

double corss(int a, int b, int c) {
    int dx1 = x[a] - x[b];
    int dx2 = x[a] - x[c];
    int dy1 = y[a] - x[b];
    int dy2 = y[a] - y[c];
    return dx1*dy2 - dx2*dy1;
}

int test(int a, int b) {
    int left = 0;
    int right = 0;
    int now_a = a;
    int now_b = b;

    for (int i = 0; i < n; i++) {
        if (i == a || i == b) {
            continue;
        }
        int C = corss(a, b, i);
        if (C > 0) {
            left ++;
        }
        if (C < 0) {
            right++;
        }
    }
    return left > right ? right : left;
}

void ans(int x) {
    int min = n-3;
    for (int i = 0; i < n ; i++) {
        if (i == x) {
            continue;
        }
        int temp = test(i, x);
        if (temp < min) {
            min = temp;
        }
    }
    if (min < 0) {
        min = 0;
    }
    printf("%d\n", min);
}

int main()
{
    scanf("%d", &T);
    for (int z = 1; z <= T; z++) {
        printf("Case #%d:\n", z);

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", x+i, y+i);
        }


        for (int i = 0; i < n; i++) {
            ans(i);
        }
    }
    return 0;
}
