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
    int b,n,m[1100], mul;
    for(int cas=1;cas<=T;cas++) {
        scanf("%d%d",&b,&n);
        mul = 1;
        for(int i=1;i<=b;i++) {
            scanf("%d", &m[i]);
            mul = mul * m[i];
        }
        int sum = 0;
        for(int i=1;i<=b;i++) {
            sum += mul / m[i];
        }
        n = n % sum + sum;
        int v[1100];
        for(int i=1;i<=b;i++) {
            v[i] = 0;
        }
        int ans= -1;
        for(int i=1;i<=n;i++) {
            int minval = 110000;
            int minpos = -1;
            for(int j=1;j<=b;j++) {
                if(v[j] < minval) {
                    minval = v[j];
                    minpos = j;
                }
            }
            for(int j=1;j<=b;j++) {
                v[j] -= minval;
                ans = minpos;
            }
            v[minpos] = m[minpos];
        }
        printf("Case #%d: %d\n", cas, ans);
    }

    return 0;
}
