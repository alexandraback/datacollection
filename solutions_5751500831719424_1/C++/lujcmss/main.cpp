#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

char a[110][110];
int pos[110];
int p[110];
int n;

int check() {
    sort(p, p + n);
    
    int zero = 0;
    int re = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] == 0) zero++;
        re += abs(p[i] - p[n/2]);
    }
    if (zero == n || zero == 0) {
        return re;
    } else {
        return -1;
    }
}
int main() {
    freopen("/Users/L/Downloads/A-large.in.txt", "r", stdin);
    freopen("/Users/L/Downloads/out.txt", "w", stdout);
    
    int T;
    scanf("%d", &T);
    
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d", &n);
        
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) {
            scanf("%s", a[i]);
        }
        
        bool flag = true;
        int ans = 0;
        memset(pos, 0, sizeof(pos));
        while (a[0][pos[0]] != '\0') {
            char tmp = a[0][pos[0]];
            for (int i = 0; i < n; i++) {
                int j = pos[i];
                while (a[i][j] == tmp) {
                    j++;
                }
                p[i] = j - pos[i];
                pos[i] = j;
            }
            
            int re = check();
            if (re == -1) {
                flag = false;
            } else {
                ans += re;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i][pos[i]] != '\0') {
                flag = false;
            }
        }
        
        printf("Case #%d: ", kase);
        if (flag) {
            printf("%d\n", ans);
        } else {
            printf("Fegla Won\n");
        }
    }
    
    return 0;
}
