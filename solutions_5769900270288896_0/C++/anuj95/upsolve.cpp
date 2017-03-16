#include <bits/stdc++.h>
using namespace std; 

int dp[1 << 18];
int R, C, N;

int DP(int mask)
{
    int ret = 0;
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            if (c > 0){
                if((mask & (1 << (r * C + c)))){
                    if(mask & (1 << (r * C + c - 1))){
                        ret++;
                    }
                }
            }
            if (r > 0){
                if(mask & (1 << (r * C + c))){
                    if(mask & (1 << (r * C + c - C))){
                        ret++;
                    }
                }
            }
        }
    }
    return ret;
}
int ANS[17][17][17];
int main() 
{
    freopen("input.txt","r",stdin) ; 
    freopen("output.txt","w",stdout) ; 
    int tc,ans=0;
    cin >> tc;
    for(int i = 0 ; i <= 16; ++i){
        for(int j = 0 ; j <= 16 ; ++j){
            for(int k = 0 ; k <= 16 ; ++k){
                ANS[i][j][k] = -1 ; 
            }
        }
    }
    for (int t = 1; t <= tc; t++){
        cin >> R >> C >> N;
        cout << "Case #"<<t<<": ";
        if(ANS[N][R][C] != -1){
            cout << ANS[N][R][C] << "\n" ; 
            continue ; 
        }
        int ans = R * C * N * 100;
        for (int mask = 1; mask < (1 << (R * C)); mask++){
            dp[mask] = dp[mask - (mask & -mask)] + 1;
            if (dp[mask] == N){ 
                ans = min(ans, DP(mask));
            }
        }
        cout << ans << "\n" ; 
        ANS[N][R][C] = ans ; 
    }
}