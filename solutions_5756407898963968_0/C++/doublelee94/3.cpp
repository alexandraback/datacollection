#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include <stdio.h>
using namespace std;
#define N 2000005
#define INF 1000000009
typedef long long LL;
int ans, x0, x1;
int a[5][5];
int d[5];
int main(){
    int t;
    freopen("A-small-attempt7.in","r",stdin);
    freopen("ans.out","w",stdout);
    scanf("%d", &t);
    int num = 1;
    while(t--){
        scanf("%d", &x0);
        for(int i = 1; i <= 4; i++){
            for(int j = 1; j <= 4; j++){
                scanf("%d", &a[i][j]);
            }
        }
        for(int i = 1; i <= 4; i++)
            d[i] = a[x0][i];
        scanf("%d", &x1);
        for(int i = 1; i <= 4; i++){
            for(int j = 1; j <= 4; j++){
                scanf("%d", &a[i][j]);
            }
        }
        ans = 0;
        int v = 0;
        for(int i = 1; i <= 4; i++){
            for(int j = 1; j <= 4; j++){
                if(a[x1][i] == d[j]){
                    ans ++;
                    v = a[x1][i];
                }
            }
        }
        printf("Case #%d: ", num++);
        if(ans == 1)printf("%d\n", v);
        else if(ans == 0)printf("Volunteer cheated!\n");
        else if(ans > 1)printf("Bad magician!\n");
    }
    return 0;
}
