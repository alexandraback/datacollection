#include <bits/stdc++.h>

const int N = 26;
int n,A[N];

void work() {
    while (true) {
        int sum = std::accumulate(A,A + n,0);
        if (sum == 0) break;
        std::vector<int> must;
        for (int i = 0; i < n; ++ i) {
            if (A[i] * 2 > sum - 1) {
                must.push_back(i);
                A[i] --;
            }
            if (A[i] * 2 > sum - 1) {
                must.push_back(i);
                A[i] --;
            }
        }
        if (must.empty()) {
            for (int i = 0; i < n; ++ i) {
                if (A[i] != 0) {
                    must.push_back(i);
                    A[i] --;
                    break;
                }
            }
        }
        putchar(' ');
        for (auto t : must) {
            printf("%c",t + 'A');
        }
    }
    puts("");
}

int main() {
    freopen("big.in","r",stdin);
    freopen("big.out","w",stdout);
    int cas,ca = 0;
    scanf("%d",&cas);

    while (cas--) {
        scanf("%d",&n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d",A + i);
        }
        printf("Case #%d:",++ca);
        work();
    }
}
