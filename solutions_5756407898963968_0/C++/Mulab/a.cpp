#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

bool cnt[19];
int data[7][7];

void solve(){
    int choice;
    memset(cnt, 0, sizeof(cnt));
    scanf("%d", &choice);
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 4; j++)
            scanf("%d", &data[i][j]);
    for(int i = 1; i <= 4; i++)
        cnt[data[choice][i]] = true;
    scanf("%d", &choice);
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 4; j++)
            scanf("%d", &data[i][j]);
    int res = 0, ans = 0;
    for(int i = 1; i <= 4; i++)
        if(cnt[data[choice][i]]){
            ans = data[choice][i];
            res++;
        }
    if(!res)
        printf("Volunteer cheated!\n");
    else if(res > 1)
        printf("Bad magician!\n");
    else
        printf("%d\n", ans);
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

