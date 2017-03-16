#include <bits/stdc++.h>

int A[3],n;
std::vector<std::pair<int,int>> answer;

bool search() {
    bool empty = true;
    for (int i = 0; i < n; ++ i) empty &= A[i] == 0;
    if (empty) return true;

    for (int a = 0; a < n; ++ a) {
        if (A[a] == 0) continue;
        A[a] --;

        for (int b = a; b < n; ++ b) {
            if (A[b] == 0) continue;
            A[b] --;

            int sum = std::accumulate(A,A + n,0);
            bool flag = true;
            for (int i = 0; i < n; ++ i) {
                flag &= A[i] * 2 <= sum;
            }

            if (flag && search()) {
                answer.emplace_back(a,b);
                return true;
            }

            A[b] ++;
        }

        int sum = std::accumulate(A,A + n,0);
        bool flag = true;
        for (int i = 0; i < n; ++ i) {
            flag &= A[i] * 2 <= sum;
        }
        if (flag && search()) {
            answer.emplace_back(a,-1);
            return true;
        }

        A[a] ++;
    }
    return false;
}

void work() {
    answer.clear();
    search();
    for (int i = (int)answer.size() - 1; i >= 0; -- i) {
        printf(" %c",answer[i].first + 'A');
        if (answer[i].second != -1) {
            printf("%c",answer[i].second + 'A');
        }
    }
    puts("");
}

int main() {
    freopen("small.in","r",stdin);
    freopen("small.out","w",stdout);
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
