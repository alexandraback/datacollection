#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

li calc(li n, li m, li arr[17][17])
{
    //cout << "yes";
    li i, j, cnt = 0;
    for(i = 1;i < n; ++i){
        for(j = 1;j < m; ++j){
            if(arr[i][j] && arr[i - 1][j]) ++cnt;
            if(arr[i][j] && arr[i][j - 1]) ++cnt;
        }
    }
    for(i = 1;i < n; ++i){
        if(arr[i][0] && arr[i - 1][0]) ++cnt;
    }
    for(j = 1;j < m; ++j){
        if(arr[0][j] && arr[0][j - 1]) ++cnt;
    }
    return cnt;
}

li rec(li ind, li arr[17][17], li cnt, li i, li j, li k){
    if(ind == i * j){
        //cout << "yes2";
        if(cnt == k)
            return calc(i, j, arr);
        else
                return 100000;
    }
    //cout << "yes1";
    if(cnt > k) return 10000000;
    //cout << ind / j << " " << ind % j << "\n";
    arr[ind / j][ind % j] = 1;
    li ans = rec(ind + 1, arr, cnt + 1, i, j, k);
    arr[ind / j][ind % j] = 0;
    ans = min(ans, rec(ind + 1, arr, cnt, i, j, k));
    //cout << ind << " " << cnt << " " << ans << "\n";
    return ans;
}

li dp[17][17][17];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    li i, j, k, t;
    for(i = 1;i <= 16; ++i){
        for(j = 1;j <= 16; ++j){
            if(i * j <= 16){
                for(k = 1;k <= 16; ++k){
                    li arr[17][17];
                    memset(arr, 0, sizeof arr);
                    dp[i][j][k] = rec(0, arr, 0, i, j, k);
                    //cout << "yes";
                }
            }
        }
    }

    li cnt = 0;
    cin >> t;
    while(t--){
        li t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        printf("Case #%lld: %lld\n", ++cnt, dp[t1][t2][t3]);
    }

    return 0;
}
