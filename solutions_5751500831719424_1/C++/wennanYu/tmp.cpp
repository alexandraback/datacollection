#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int T, n;
char ipt[105][105];
char data[105][105];
int num[105][105];
int cas, sd[105], slot[105], ns;
char last;

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);getchar();
    while (T--){
        memset(num, 0, sizeof num);
        scanf("%d", &n);
        getchar();
        for (int i=1;i<=n;++i){
            gets(ipt[i]);
            last = -1;
            for (int j=0;j<strlen(ipt[i]);++j){
                if (ipt[i][j] != last){
                    data[i][++num[i][0]] = last = ipt[i][j];
                    ++num[i][num[i][0]];
                }
                else{
                    ++num[i][num[i][0]];
                }
            }
        }
        bool flag = true;
        for (int i=2;i<=n;++i){
            if (num[i][0] != num[i-1][0]){
                flag = false;
                break;
            }
            for (int j=1;j<=num[i][0];++j){
                if (data[i][j]!=data[i-1][j]){
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        printf("Case #%d: ", ++cas);
        if (!flag){
            puts("Fegla Won");
            continue;
        }
        int ans = 0, cs;
        for (int i=1;i<=num[1][0];++i){
            for (int j=1;j<=n;++j) slot[j] = num[j][i];
            sort(slot + 1, slot + 1 + n);
            cs = slot[(n+1)/2];
            for (int j=1;j<=n;++j) ans += abs(slot[j] - cs);
        }
        printf("%d\n", ans);
    }
}
