/**
 * Copyright (c) 2015 Authors. All rights reserved.
 * 
 * FileName: A.cpp
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

int n;
int a[maxn];

LL first()
{
        LL res = 0;
        rep(i,n-1) if (a[i] > a[i+1]) res += a[i] - a[i+1];
        return res;
}

LL second()
{
        LL res = 0, rate = 0;
        rep(i,n-1) if (a[i] > a[i+1]) rate = max(rate, (LL)a[i] - a[i+1]);
        rep(i,n-1) res += min((LL)a[i], rate);
        return res;
}

int main()
{
        int T, cas = 0;
        scanf("%d", &T);

        while (T--) {
                scanf("%d", &n);
                rep(i,n) scanf("%d", &a[i]);
                printf("Case #%d: %lld %lld\n", ++cas, first(), second());
        }

        return 0;
}
