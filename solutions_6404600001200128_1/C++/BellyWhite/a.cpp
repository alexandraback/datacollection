#include <bits/stdc++.h>
using namespace std;

int main() {
    int caseNum;
    scanf("%d", &caseNum);
    for (int caseId = 1; caseId <= caseNum; caseId++) {
        int n, a[1005];
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", a+i);
        int sum1 = 0, sum2 = 0, rate = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i-1]) {
                sum1 += a[i-1] - a[i];
                rate = max(rate, a[i-1] - a[i]);
            }
        }
        for (int i = 0; i < n - 1; i++) {
            sum2 += min(rate, a[i]);
        }
        printf("Case #%d: %d %d\n", caseId, sum1, sum2);
    }
}
