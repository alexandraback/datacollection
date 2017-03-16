#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;
long long n, m, a[1010], ti;

bool cmp(long long x, long long y){return x > y;}

int main(){
    FILE* FIN;
    FILE* FOUT;
    FIN = fopen("/Users/Djy/Documents/4test/B-small-attempt2.in", "r");
    FOUT = fopen("/Users/Djy/Documents/4test/B-small-attempt2.out", "w");

    int T;
    fscanf(FIN, "%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        
        int ans1, ans2, cn[10], r, c, n, f[10010];
        fscanf(FIN, "%d%d%d", &r, &c, &n);
        ans1 = ans2 = 0;
        
        memset(cn, 0, sizeof(cn));
        memset(f, 0, sizeof(f));
        
        if (r > c) swap(r, c);
        for (int i = 1; i <= r; i++)
            for (int j = (i & 1) + 1; j <= c; j += 2)
                f[(i - 1) * c + j] = 1;
        
        for (int i = 1; i <= r * c; i++){
            if (f[i]) cn[0]++;
            else{
                int tmp = 0;
                if (i > c && f[i - c]) tmp++;
                if (i % c != 1 && f[i - 1]) tmp++;
                if (i + c <= r * c && f[i + c]) tmp++;
                if (i % c != 0 && f[i + 1]) tmp++;
                cn[tmp]++;
            }
        }
        printf("%d %d %d %d %d\n", cn[0], cn[1], cn[2], cn[3], cn[4]);
        int now = max(n - cn[0], 0);
        ans1 += min(now, cn[1]);
        now -= min(now, cn[1]);
        ans1 += min(now, cn[2]) * 2;
        now -= min(now, cn[2]);
        ans1 += min(now, cn[3]) * 3;
        now -= min(now, cn[3]);
        ans1 += min(now, cn[4]) * 4;
        now -= min(now, cn[4]);
        
        memset(cn, 0, sizeof(cn));
        memset(f, 0, sizeof(f));
        
        for (int i = 1; i <= r; i++)
            for (int j = ((i & 1) ^ 1) + 1; j <= c; j += 2)
                f[(i - 1) * c + j] = 1;
        
        
        for (int i = 1; i <= r * c; i++){
            if (f[i]) cn[0]++;
            else{
                int tmp = 0;
                if (i > c && f[i - c]) tmp++;
                if (i % c != 1 && f[i - 1]) tmp++;
                if (i + c <= r * c && f[i + c]) tmp++;
                if (i % c != 0 && f[i + 1]) tmp++;
                cn[tmp]++;
            }
        }
        //printf("%d %d %d %d %d\n", cn[0], cn[1], cn[2], cn[3], cn[4]);
        now = max(n - cn[0], 0);
        ans2 += min(now, cn[1]);
        now -= min(now, cn[1]);
        ans2 += min(now, cn[2]) * 2;
        now -= min(now, cn[2]);
        ans2 += min(now, cn[3]) * 3;
        now -= min(now, cn[3]);
        ans2 += min(now, cn[4]) * 4;
        now -= min(now, cn[4]);
        
        //printf("%d %d\n", ans1, ans2);
        fprintf(FOUT, "Case #%d: %d\n", cas, min(ans1, ans2));
        
    }
    return 0;
}