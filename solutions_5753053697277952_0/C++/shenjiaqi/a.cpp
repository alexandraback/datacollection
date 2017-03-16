#include <cstdio>
#include <iostream>
using namespace std;

const int N = 27;
const int M = 2000;

int main() {
    int T;
    scanf("%d", &T);
    int p[N];
    int q[N], qi = 0;
    char ans[M], ansI = 0;
    for (int i = 0; i < T; ++i) {
        int n;
        scanf("%d", &n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", p + i);
            sum += p[i];
        }

        qi = 0, ansI = 0;
        while (sum > 0) {
            int maxV = 0;
            for (int i = 0; i < n; ++i) {
                if (p[i] == 0) {
                    continue;
                }
                if (p[i] > maxV) {
                    maxV = p[i];
                    qi = 1;
                    q[0] = i;
                } else if (p[i] == maxV) {
                    q[qi] = i;
                    ++qi;
                }
            }
            if (ansI > 0) {
                ans[ansI] = ' ';
                ++ansI;
            }
            ans[ansI] = ('A' + q[0]);
            --p[q[0]];
            ++ansI;
            --sum;
            if (qi == 2) {
                ans[ansI] = ('A' + q[1]);
                --p[q[1]];
                ++ansI;
                --sum;
            }
        }
        ans[ansI] = '\0';
        printf("Case #%d: %s", i + 1, ans);
        if (i + 1 < T) {
            printf("\n");
        }
    }
    return 0;
}