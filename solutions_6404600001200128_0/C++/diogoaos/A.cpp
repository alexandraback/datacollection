#include <cstdio>
#include <algorithm>

using namespace std;

int inp[101000];

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        
        for (int j = 0; j < n; j++) {
            scanf("%d", &inp[j]);
        }
        
        int dif = 0, aa = 0, ab = 0;
        for (int j = 0; j < n - 1; j++) {
            dif = max(dif, inp[j] - inp[j + 1]);
            aa += max(0, inp[j] - inp[j + 1]);
        }
        
        for (int j = 0; j < n - 1; j++) {
            ab += min(dif, inp[j]);
        }
        
        printf("Case #%d: %d %d\n", i, aa, ab);
    }
    
    
    return 0;
}