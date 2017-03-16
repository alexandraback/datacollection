#include <bits\stdc++.h>
using namespace std;

int findMax(int p[], int n) {
    int ma = 0, ptr = -1;
    for (int i = 0; i < n; i++)
        if (p[i] > ma)
            ma = p[i], ptr = i;
    return ptr;
}

bool isLegal(int p[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += p[i];
    for (int i = 0; i < n; i++)
        if (p[i] > sum / 2)
            return false;
    return true;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, c = 1;
    scanf("%d", &t);
    while (t--) {
        int n, p[26];
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", p + i);
        printf("Case #%d:", c++);

        do {
            int ptr1 = findMax(p, n), ptr2;
            p[ptr1]--;
            if (isLegal(p, n)) {
                printf(" %c", 'A' + ptr1);
                continue;
            }
            ptr2 = findMax(p, n);
            p[ptr2]--;
            printf(" %c%c", 'A' + ptr1, 'A' + ptr2);
        } while (findMax(p, n) != -1);
        putchar('\n');
    }
    return 0;
}