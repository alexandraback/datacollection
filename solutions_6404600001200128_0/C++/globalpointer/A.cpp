#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
typedef long long ll;

int N, a[1005];

int main()
{
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", &a[i]);
        int maxdelta = std::max(0, a[0]-a[1]);
        for (int i = 1; i+1 < N; i++) maxdelta = std::max(maxdelta, a[i]-a[i+1]);
        int ansa = 0, ansb = 0;
        for (int i = 0; i+1 < N; i++) {
            ansb += std::min(a[i], maxdelta);
            if (a[i] > a[i+1]) ansa += a[i]-a[i+1];
        }
        printf("Case #%d: %d %d\n", t, ansa, ansb);
    }
}

