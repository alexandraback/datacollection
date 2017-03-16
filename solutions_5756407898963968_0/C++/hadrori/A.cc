#include <iostream>
#include <cstring>

using namespace std;

bool cand[4][32];
int table[2][4][4], row[2];

void init(){
    memset(cand, 0, sizeof(cand));
}

void input(){
    for(int k = 0; k < 2; k++){
        cin >> row[k];
        row[k]--;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                cin >> table[k][i][j];
    }
}

void solve(){
    for(int k = 0; k < 2; k++)
        for(int j = 0; j < 4; j++)
            cand[k][table[k][row[k]][j]] = 1;
    for(int i = 1; i < 17; i++)
        cand[2][i] = cand[0][i] & cand[1][i];
    
    int ans = 0;
    for(int i = 1; i < 17; i++)
        if(cand[2][i] and ans == 0) ans = i;
        else if(cand[2][i] and ans > 0){
            puts("Bad magician!");
            return;
        }
    if(ans == 0) puts("Volunteer cheated!");
    else cout << ans << endl;
    return;
}

int main(){
    int T; cin >> T;
    for(int t = 1; t <= T; t++){
        init(); input();
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}
