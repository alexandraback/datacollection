#include<iostream>
#include<cstdio>
using namespace std;
int a[5][5], b[5][5];
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T;  cin>>T;
    for(int cas=1; cas<=T; ++cas){
        int n; cin>>n;
        for(int i=1; i<=4; ++i)
            for(int j=1; j<=4; ++j) cin>>a[i][j];
        int m; cin>>m;
        for(int i=1; i<=4; ++i)
            for(int j=1; j<=4; ++j) cin>>b[i][j];
        int k = 0, ans;
        for(int i=1; i<=4; ++i)
            for(int j=1; j<=4; ++j)
                if(a[n][i] == b[m][j]) ++k, ans = a[n][i];
        if(k == 0) printf("Case #%d: Volunteer cheated!\n", cas);
        else if(k == 1 ) printf("Case #%d: %d\n", cas, ans);
        else printf("Case #%d: Bad magician!\n", cas);
    }
    return 0;
}





