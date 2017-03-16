#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[2000];

int main(){
        int tt,ca = 0;
        scanf("%d",&tt);
        while (tt--){
                int n;
                scanf("%d",&n);
                for (int i = 0;i < n;i ++) scanf("%d",&a[i]);
                int ans1 = 0, ans2 = 0, rate = 0;
                for (int i = 1;i < n;i ++){
                        if (a[i] < a[i - 1]){
                                ans1 += a[i-1] - a[i];
                                rate = max(rate, a[i-1] - a[i]);
                        }
                }
                for (int i = 0;i < n - 1;i ++){
                        ans2 += min(a[i], rate);
                }
                printf("Case #%d: %d %d\n", ++ca, ans1, ans2);
        }
}

