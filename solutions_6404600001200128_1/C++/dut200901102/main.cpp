#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

const int N = 1010;
const int mod = 100007;

int n, a[N];

int main(){    
    int _, cas = 1;
    for(scanf("%d", &_); _--; ){
        printf("Case #%d: ", cas++);
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d", a + i);
        
        int ans_1 = 0, rate = 0;
        for(int i = 1; i < n; ++i){
            ans_1 += max(0, a[i - 1] - a[i]);
            rate = max(rate, a[i - 1] - a[i]);
        }
        printf("%d ", ans_1);
        
        int ans_2 = 0;
        for(int i = 0; i < n - 1; ++i){
            ans_2 += min(a[i], rate);
        }
        printf("%d\n", ans_2);
    }
    return 0;
}