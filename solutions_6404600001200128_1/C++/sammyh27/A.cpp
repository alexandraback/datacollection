#include <stdio.h>

int n, i, tc, cases, res1, res2, temp, maxi;
int a[1005];

int main() {
    scanf("%d\n", &tc);
    cases = 1;
    while(tc--) {
        scanf("%d\n", &n);
        for(i=0; i<n; i++) {
            scanf("%d \n", &a[i]);
        }
        res1 = 0;
        for(i=1; i<n; i++) {
            if(a[i]<a[i-1]) {
                res1 += a[i-1]-a[i];
            }
        }
        maxi = 0;
        for(i=1; i<n; i++) {
            if(a[i-1]-a[i] > maxi) maxi = a[i-1]-a[i];
        }
        res2 = 0;
        for(i=0; i<n-1; i++) {
            if(a[i]<maxi) res2 += a[i];
            else res2 += maxi;
        }
        printf("Case #%d: %d %d\n", cases++, res1, res2);
    }
    return 0;
}
