#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#define LL long long
using namespace std;

int dp[111][111];
char a[111][111];

void update(int & a, int b){
    if(a == -1 || a > b) a = b;
}

int main (){
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int t, tt = 0;
    int n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%s", a[i]+1);
        int aa = strlen(a[0]+1);
        int bb = strlen(a[1]+1);
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for(int i = 0; i <= aa; ++i){
            for(int j = 0; j <= bb; ++j){
                if(dp[i][j] == -1) continue;
                if(a[0][i+1] == a[1][j+1])
                    update(dp[i+1][j+1], dp[i][j]);
                if(a[0][i] == a[0][i+1])
                    update(dp[i+1][j], dp[i][j] + 1);
                if(a[1][j] == a[1][j+1])
                    update(dp[i][j+1], dp[i][j] + 1);
            }
        }
        printf("Case #%d: ", ++tt);
        if(dp[aa][bb] == -1) puts("Fegla Won");
        else printf("%d\n", dp[aa][bb]);
    }
    return 0;
}
