#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>
using namespace std;

const long long INF = 1000000000LL * 1000000000LL;
const int maxn = 1000 + 10;

int M[maxn];

int main() {
    //freopen("B.in", "r", stdin);
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out", "w", stdout);

    int testCount, N, B;
    scanf("%d", &testCount);
    for (int testId = 1; testId <= testCount; ++testId) {
        scanf("%d%d", &B, &N);
        for (int i = 0; i < B; ++i) {
            scanf("%d", &M[i]);
        }
        long long l = 0, r = INF, cost = INF;
        while (l <= r) {
            long long m = (l + r) / 2;
            long long cnt = 0;
            for (int i = 0; i < B; ++i) {
                cnt += m / M[i] + ((m % M[i] > 0) ? 1 : 0); 
            }
            if (cnt >= (long long)N) {
                cost = min(cost, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        cost -= 1L;
        //fprintf(stderr, "\ncost: %d\n", cost);
        for (int i = 0; i < B; ++i) {
            N -= cost / M[i] + ((cost % M[i] > 0) ? 1 : 0); 
        }
        assert(N >= 1 && N <= B);
        vector<pair<long long, int> > data;
        for (int i = 0; i < B; ++i) {
            long long towait = (cost % M[i] == 0) ? 0 : (M[i] - cost % M[i]);
            data.push_back(make_pair(towait, i + 1));
        }
        sort(data.begin(), data.end());
        printf("Case #%d: %d\n", testId, data[N - 1].second);
    }
}
