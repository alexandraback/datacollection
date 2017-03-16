#include <cstdio>
#include <cstring>
#include <iostream>
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;

int a[1010];

int main(){
    int t;
    scanf("%d", &t);
    for(int di = 1; di <= t; di++){
        int n;
        scanf("%d", &n);
        for(int i  = 0; i < n; i++)
            scanf("%d", &a[i]);
        long long ans = 0;
        long long res = 0;
        int ma = 0;
        for(int i = 1; i < n; i++){
            if(a[i] < a[i - 1]){
                ans += (a[i - 1] - a[i]);
                ma = Max(ma, a[i - 1] - a[i]);
            }
        }
        for(int i = 0; i < n - 1; i++)
            res += Min(a[i], ma);
        printf("Case #%d: %lld %lld\n", di, ans, res);
    }
    return 0;
}
