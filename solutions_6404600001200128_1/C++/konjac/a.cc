#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using std::max;

int data[10010];

int main(){
    int T;
    scanf("%d", &T);
    for(int _ = 1 ; _ <= T; ++_){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", data+i);
        int ans1 = 0, ans2 = 0;
        for(int i = 1; i < n; ++i){
            if(data[i] < data[i-1])
                ans1 += data[i-1] - data[i];
        }
        int maxSpeed = 0;
        for(int i = 1; i < n; ++i){
            if(data[i] < data[i-1])
                maxSpeed = max(maxSpeed, data[i-1] - data[i]);
        }
        for(int i = 1; i < n; ++i){
            if(data[i-1] - maxSpeed < 0)
                ans2 += data[i-1];
            else
                ans2 += maxSpeed;
        }
        printf("Case #%d: %d %d\n", _, ans1, ans2);
    }
}
