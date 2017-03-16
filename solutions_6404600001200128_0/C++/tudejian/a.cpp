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

const int kMaxN = 1000 + 10;

int N;
int m[kMaxN];

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 0; cas < T; ++cas) {
        scanf("%d", &N);
        int maxM = 0;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &m[i]);
            maxM = max(maxM, m[i]);
        }
        int sum = 0;
        int last = m[0];
        for (int i = 1; i < N; ++i) {
            if (last > m[i]) {
                sum += last - m[i];
            }
            last = m[i];
        }
        int ansA = sum;
        int ansB = -1;
        for (int j = 0; j <= maxM; ++j) {
            int last = 0;
            int sum = 0;
            for (int i = 0; i < N; ++i) {
                if (last > m[i]) {
                    sum = -1;
                    break;
                }
                if (i == N - 1) {
                    break;
                }
                if (m[i] > j) {
                    last = m[i] - j;
                    sum += j;
                } else {
                    last = 0;
                    sum += m[i];
                }
            }
            if (sum >= 0) {
                if (ansB < 0 || ansB > sum) {
                    ansB = sum;
                }
            }
        }
        printf("Case #%d: %d %d\n", cas + 1, ansA, ansB);
    }
    return 0;
}

