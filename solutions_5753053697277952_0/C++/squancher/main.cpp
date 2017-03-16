#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int sen[1000];

int main() {
    freopen("A-small.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    
    int tn = 0;
    
    scanf("%d\n", &tn);
    
    for (int t = 1; t <= tn; t++) {
        int n;
        scanf("%d", &n);
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &sen[i]);
        }
        
        int max1 = -1;
        int max1p = -1;
        int max2 = -1;
        int max2p = -1;
        
        for (int i = 0; i < n; i++) {
            if (max1 < sen[i]) {
                max1 = sen[i];
                max1p = i;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (i == max1p)
                continue;
            
            if (max2 < sen[i]) {
                max2 = sen[i];
                max2p = i;
            }
        }
        
        printf("Case #%d: ", t);
        
        while (sen[max1p] > sen[max2p]) {
            sen[max1p]--;
            putchar('A' + max1p);
            putchar(' ');
        }
        
        for (int i = 0; i < n; i++) {
            if (i == max1p || i == max2p) {
                continue;
            }
            
            for (int j = 0; j < sen[i]; j++) {
                putchar('A' + i);
                putchar(' ');
            }
        }
        
        while (sen[max1p] > 0) {
            sen[max1p]--;
            putchar('A' + max1p);
            putchar('A' + max2p);
            putchar(' ');
        }
        
        putchar('\n');
    }
    
    return 0;
}