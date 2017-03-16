#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define N 4

int a[N][N], b[N][N], c[17] = {0};

inline void solve(){
    int i, j, k, ar, br;
    cin>>ar; ar--;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            cin>>a[i][j];
        }
    }
    cin>>br; br--;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            cin>>b[i][j];
        }
    }
    j = 0;
    for(i = 0; i < 4; i++){
        c[a[ar][i]] += 2;
        c[b[br][i]] += 1;
    }
    for(i = 1; i < 17; i++){
        if(c[i] == 3){
            j++;
            k = i;
        }
    }
    if(j == 1){
        printf("%d\n", k);
    }
    else if(j > 0){
        printf("Bad magician!\n");
    }
    else{
        printf("Volunteer cheated!\n");
    }
    for(i = 0; i < 4; i++){
        c[a[ar][i]] -= 2;
        c[b[br][i]] -= 1;
    }
    return;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    cin>>t;
    for(int i = 0; i < t; i++){
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
