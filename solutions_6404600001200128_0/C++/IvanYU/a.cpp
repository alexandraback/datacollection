#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int T, n, a[1005];
    scanf("%d", &T);

    int ans1, ans2, Max;
    for (int _T = 1; _T <= T; _T++){
        scanf("%d", &n);

        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);

        //
        ans1 = 0;
        for (int i = 1; i < n; ++i)
        {
            if(a[i] < a[i - 1])
                ans1 += a[i - 1] - a[i];
        }

        //
        ans2 = 0;
        Max = 0;
        for (int i = 1; i < n; ++i)
            Max = max(Max, a[i - 1] - a[i]);
        
        for (int i = 0; i < n - 1; ++i){
            ans2 += min(Max, a[i]);
        }

        printf("Case #%d: %d %d\n", _T, ans1, ans2);

    }
}