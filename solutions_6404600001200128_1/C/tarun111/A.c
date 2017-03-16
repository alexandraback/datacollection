#include<stdio.h>
int arr[1000];
int main() {
    int cases, i, j, p = 1, n, min1, min2, max;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d", &n);
        for(i=0;i<n;i++) {
            scanf("%d", &arr[i]);
        }

        max = 0;
        min1 = min2 = 0;

        for(i=0;i<n-1;i++) {
            if(arr[i] - arr[i+1] > max) {
                max = arr[i] - arr[i+1];
            }
        }

        for(i=0;i<n-1;i++) {
            if(arr[i+1] < arr[i]) {
                min1 += arr[i] - arr[i+1];
            }
            min2 += (arr[i] > max) ? max : arr[i];
        }

        printf("Case #%d: %d %d\n", p++, min1, min2);
    }
    return 0;
}
