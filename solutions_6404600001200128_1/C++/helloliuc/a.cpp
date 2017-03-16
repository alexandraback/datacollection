#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++) {
        int n;
        int a[1100];
        int maxa = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            maxa = max(a[i], maxa);
        }
        int ans1 = 0;
        int maxdiff = 0;
        for(int i=2; i<=n;i++) {
            if(a[i] < a[i-1]) {
                ans1 += a[i-1] - a[i];
            }
            if(a[i-1] - a[i] > maxdiff) {
                maxdiff = a[i-1] - a[i];
            }
        }

        int ans2 = 0;
        for(int i=2; i<=n;i++) {
            ans2 += min(a[i-1], maxdiff);
        }

        printf("Case #%d: %d %d\n", cas, ans1, ans2);
    }

    return 0;
}
