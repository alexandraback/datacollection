#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int a[5][5], b[5][5], x, y, T, n=4, cas;

int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d",&x);
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                scanf("%d", &a[i][j]);
            }
        }
        scanf("%d",&y);
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                scanf("%d", &b[i][j]);
            }
        }
        int ans=0, last = -1;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                if (a[x][i] == b[y][j]){
                    ans++;
                    last = a[x][i];
                }
            }
        }
        printf("Case #%d: ", ++cas);
        if (ans==1){
            printf("%d\n", last);
        }
        else if (ans==0) printf("Volunteer cheated!\n");
        else printf("Bad magician!\n");
    }
}
