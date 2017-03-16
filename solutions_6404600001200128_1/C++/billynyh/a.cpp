#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }

int main(){
    int tt; scanf("%d",&tt);
    for (int ti=1;ti<=tt;ti++){
        int n; scanf("%d", &n);
        int a[n];
        for (int i=0;i<n;i++) {
            scanf("%d", &a[i]);
        }

        int ans1 = 0, ans2 = 0;
        for (int i=1;i<n;i++) {
            if (a[i] < a[i-1]) {
                ans1 += a[i-1]-a[i];
            }
        }
        int rate = 0;
        for (int i=1;i<n;i++) {
            if (a[i-1] - a[i] > rate) {
                rate = a[i-1] - a[i];
            }
        }
        for (int i=0;i<n-1;i++) {
            ans2 += min(a[i], rate);
            //printf("~%d\n", ans2);
        }
        printf("Case #%d: %d %d\n",ti,ans1, ans2);
    }
    return 0;
}
