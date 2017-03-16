#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long lint;
int inp[10100];

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int b;
        lint n;
        scanf("%d %lld", &b, &n);
        
        for (int j = 0; j < b; j++) {
            scanf("%d", &inp[j]);
        }
        
        if (b > n) {
            printf("Case #%d: %lld\n", i, n);
            continue;
        }
        
        lint bot = 1;
        lint top = 100000LL * (n + 1);
        
        while (true) {
            lint mid = (bot + top) / 2LL;
            //printf("mid = %lld\n", mid);
            lint total = 0;
            for (int j = 0; j < b; j++) {
                total += ((mid - 1) / inp[j]) + 1;
            }
            
            if (total >= n) {
                top = mid - 1;
                continue;
            }
            
            lint cnt = 0;
            int ans = 0;
            for (int j = 0; j < b; j++) {
                if ( (mid % inp[j]) == 0) {
                    cnt++;
                }
                
                if (total + cnt == n) {
                    ans = j + 1;
                    break;
                }
            }
            
            if (ans) {
                printf("Case #%d: %d\n", i, ans);
                //printf("time: %d\n", mid);
                break;
            }
            
            bot = mid + 1;
        }
        
    }
    
    
    return 0;
}