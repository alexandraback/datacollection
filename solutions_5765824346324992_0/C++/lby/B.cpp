/**
 * Copyright (c) 2015 Authors. All rights reserved.
 * 
 * FileName: B.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-04-18
 */
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

typedef long long LL;
typedef pair<int, int> Pii;

const int inf = 0x3f3f3f3f;
const LL infLL = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 1000 + 5;

int n, k;
int a[maxn];

int solve()
{
        LL l = 0, r = infLL;
        while (l < r) {
                LL mid = (l + r) >> 1, t = 0;
                rep(i,n) if ((t += (mid + a[i] - 1) / a[i]) >= k) break;
                if (t >= k) {
                        r = mid;
                        continue;
                }
                rep(i,n) if (mid % a[i] == 0 && ++t == k) return i;
                l = mid + 1;
        }
        return -1;
}

int main()
{
        int T, cas = 0;
        scanf("%d", &T);

        while (T--) {
                scanf("%d%d", &n, &k);
                rep(i,n) scanf("%d", &a[i]);
                printf("Case #%d: %d\n", ++cas, solve() + 1);
        }

        return 0;
}
