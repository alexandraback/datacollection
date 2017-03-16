#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

int main() {
    int arr[100000];
    vector<int> possibles;
    int T;
    scanf("%d", &T);
    for (int tt = 0; tt < T; tt++) {
        int sum1 = 0, rate2 = 0;
        int n, b;
        scanf("%d %d", &b, &n);
        for (int i = 0; i < b; i++) {
            scanf("%d", arr+i);
        }
        long long left = 0, right = 100000000;
        right *= 100000000;
        while (left < right) {
            long long mid = (left + right) / 2;
            long long s = 0;
            for (int i = 0; i < b; i++) {
                s += mid / arr[i] + 1;
            }
            if (s >= n) {
                right = mid;
                // printf("-%lld %lld,", mid, s);
            } else {
                left = mid + 1;
                // printf("+%lld %lld,", right, s);
            }
        }
        long long x = 0;
        possibles.clear();
        for (int i = 0; i < b; i++) {
            if (left % arr[i] == 0) {
                possibles.push_back(i + 1);
            }
            if (left > 0)
                x += (left - 1) / arr[i] + 1;
        }
        // printf("%lld %d %d %d\n", left, possibles.size(), n, x);
        assert (n - x - 1 < possibles.size());
        assert (n - x - 1 >= 0);
        printf("Case #%d: %d\n", tt + 1, possibles[n - x - 1]);
    }
    return 0;
}