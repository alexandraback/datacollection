#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <queue>
#include <stack>
#define zero(x) (((x)>0?(x):-(x))<eps)
//#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof((a)))
#define lld long long
#define INF 0x3f3f3f3f
#define eps 1e-6

using namespace std;

int n;
char str[109][109];
char str2[109][109];
int dp[109][109];

int MAIN() {
    scanf("%d", &n);
    mem(dp, 0);
    for(int i = 0; i < n; i++) scanf("%s", str[i]);
    for(int i = 0; i < n; i++) {
        str2[i][0] = str[i][0];
        int t = 1;
        for(int j = 1; str[i][j]; j++) {
            if(str[i][j] != str2[i][t - 1]) str2[i][t++] = str[i][j], dp[i][t - 1] = 1;
            else dp[i][t - 1]++;
        }
        str2[i][t] = 0;
    }
    for(int i = 1; i < n; i++) {
        if(strcmp(str2[i], str2[0]) != 0) {
            printf("Fegla Won\n");
            return 0;
        }
    }
    int ans = 0;
    int len = strlen(str2[0]);
    for(int i = 0; i < len; i++) {
        vector<int> v ;
        v.clear();
        for(int j = 0; j < n; j++) v.push_back(dp[j][i]);
        sort(v.begin(), v.end());
        int mid = v[v.size() / 2];
        for(int j = 0; j < n; j++) {
            ans += abs(dp[j][i] - mid);
        }
    }
    printf("%d\n", ans);
    return 0;
}

int main() {
#ifdef LOCAL_TEST
    freopen("F:/ACMData.txt","r",stdin);
    freopen("F:/out.txt","w",stdout);
#endif
    int cases;
    scanf("%d", &cases);
    int cc = 1;
    while(cases--) {
        printf("Case #%d: ", cc++);
        MAIN();
    }
    return 0;
}
