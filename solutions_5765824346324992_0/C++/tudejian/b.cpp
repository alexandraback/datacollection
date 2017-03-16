#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <cstdlib>
#include <functional>
#include <climits>
#include <utility>
using namespace std;

typedef pair<long long, int> Pair;

Pair pairs[1000 + 10];
long long M[1000 + 10];

long long getSum(long long t, int B) {
    long long sum = 0;
    for (int i = 0; i < B; ++i) {
        sum += t / M[i] + 1;
    }
    return sum;
}

int main() {
    int T, B, N;
    scanf("%d", &T);
    greater<Pair> compare;

    for (int cas = 0; cas < T; ++cas) {
        scanf("%d%d", &B, &N);
        for (int i = 0; i < B; ++i) {
            scanf("%lld", &M[i]);
        }
        long long low = 0;
        long long high = (long long) 1 << 60;
        long long t = 0;
        while (low <= high) {
            long long mid = (low + high) >> 1;
            long long sum = getSum(mid, B);
            if (sum >= N) {
                t = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        long long cur = 0;
        for (int i = 0; i < B; ++i) {
            if (t % M[i] == 0) {
                cur += t / M[i];
            } else {
                cur += t / M[i] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < B; ++i) {
            if (t % M[i] == 0) {
                ++cur;
            }
            if (cur == N) {
                ans = i + 1;
                break;
            }
        }
        printf("Case #%d: %d\n", cas + 1, ans);
    }
    return 0;
}

