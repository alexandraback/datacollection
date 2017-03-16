#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
typedef long long ll;

const int MAXN = 1005;
int B[MAXN];
ll X[MAXN], Y[MAXN];

void work()
{
    int b, n;
    scanf("%d%d", &b, &n);
    int i;
    REP(i, b)   scanf("%d", &B[i]);
    if (n <= b) {
        printf("%d\n", n);
    } else {
        ll t, sum;
        for (int k = 1; ; ++ k) {
            ll l = 0, r = 1000000000000000000;
            t = 0;
            while (l <= r) {
                ll mid = (l + r) >> 1;
                ll sum = 0;
                REP(i, b) {
                    sum += mid % B[i] == 0 ? mid / B[i] : mid / B[i] + 1;
                }
                if (sum >= n - k) {
                    t = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            sum = 0;
            REP(i, b) {
                sum += t % B[i] == 0 ? t / B[i] : t / B[i] + 1;
            }
            if (sum < n)    break;
        }
        vector<pair<ll, int> > res;
        REP(i, b) {
            ll val = t % B[i] == 0 ? 0 : B[i] - t % B[i];
            res.push_back(make_pair(val, i));
        }
        sort(res.begin(), res.end());
        int need = n - (int)sum;
        printf("%d\n", res[need - 1].second + 1);
    }
}

int main()
{
    ios :: sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    int kase = 1;
    while (T --) {
        printf("Case #%d: ", kase ++);
        work();
    }
    return 0;
}