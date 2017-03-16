
#include <bits/stdc++.h>
using namespace std;

int T;


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);

    for (int cas = 1; cas<=T; cas++){
        printf("Case #%d: ", cas);
        int n;
        int cnt[100] = {0};

        int sum = 0;

        scanf("%d", &n);
        for(int i = 0; i<n; i++){
            scanf("%d", &cnt[i]);
            sum += cnt[i];
        }

        while (sum > 0){
            if (sum%2 == 1){ // odd
                int hi = 0;
                int hi2 = 0;
                int idx = 0;
                int idx2 = -1;
                for(int i = 0; i<n; i++){
                    if (cnt[i] > hi){
                        idx2 = idx;
                        idx = i;
                        hi2 = hi;
                        hi = cnt[i];
                    }
                    else if (cnt[i] > hi2){
                        hi2 = cnt[i];
                        idx2 = i;
                    }
                }
                printf("%c ", idx+'A');
                sum--;
                cnt[idx]--;
            }
            else if (sum%2 == 0){
                int hi = 0;
                int hi2 = 0;
                int idx = 0;
                int idx2 = -1;
                for(int i = 0; i<n; i++){
                    if (cnt[i] > hi){
                        idx2 = idx;
                        idx = i;
                        hi2 = hi;
                        hi = cnt[i];
                    }
                    else if (cnt[i] > hi2){
                        hi2 = cnt[i];
                        idx2 = i;
                    }
                }
                printf("%c%c ", idx+'A', idx2+'A');
                sum-=2;
                cnt[idx]--;
                cnt[idx2]--;
            }
        }
        printf("\n");
    }
}
