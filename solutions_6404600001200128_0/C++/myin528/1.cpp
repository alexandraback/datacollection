#include <iostream>
using namespace std;

int arr[100000];
int main() {
    int T;
    scanf("%d", &T);
    for (int tt = 0; tt < T; tt++) {
        int sum1 = 0, rate2 = 0;
        int n, last, now;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", arr + i);
        }
        for (int i = 1; i < n; i++) {
            last = arr[i - 1];
            now = arr[i];
            sum1 += max(0, last - now);
            rate2 = max(rate2, max(0, last - now));
        }
        int sum2 = 0;
        for (int i = 0; i < n - 1; i++) {
            sum2 += min(rate2, arr[i]);
        }
        printf("Case #%d: %d %d\n", tt + 1, sum1, sum2);
    }
    return 0;
}