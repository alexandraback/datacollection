#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;

int M[1009];
int B, N;

long long cal(long long mid){
    if (mid < 0) return 0;
    long long sum = 0;
    for (int i = 0; i < B; i++)
        sum += mid / M[i] + 1;
    return sum;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int ca;
    scanf("%d", &ca);
    for (int T = 1; T <= ca; T++){

        scanf("%d%d", &B,&N);
        for (int i = 0; i < B; i++)
            scanf("%d", M + i);
        if (B >= N){
            printf("Case #%d: %d\n", T, N);
            continue;
        }
        long long l = 0, r = 1e18, ans = 0;
        while(l <= r){
            long long mid = (l + r) >> 1;
            if (cal(mid) < N) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        N -= cal(ans);
        ans +=1;
        for(int i = 0; i < B; i++)
            if(ans % M[i] == 0){
                N --;
                if (N == 0){
                    printf("Case #%d: %d\n", T, i + 1);
                    break;
                }
            }
    }
    return 0;
}
