#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <map>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 1005;
const int INF = 1111111111;
struct REP{
    char ch;
    int re;
}info[MAXN][MAXN];
int num[MAXN];
int main() {
    freopen("F:\\retired\\A-large.in","r",stdin);
    freopen("F:\\retired\\out.txt","w",stdout);
    int cas;
    int n;
    char str[MAXN],pre;
    int pcnt;
    scanf("%d",&cas);
    for (int ca = 1; ca <= cas; ++ca) {
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        for (int i = 0; i < n; ++i) {
            scanf("%s",str);
            pre = str[0];
            pcnt = 1;
            for (int j = 1; str[j]; ++j) {
                if (str[j] == pre) {
                    ++pcnt;
                } else {
                    info[i][num[i]].ch = pre;
                    info[i][num[i]].re = pcnt;
                    pre = str[j];
                    pcnt = 1;
                    ++num[i];
                }
            }
            info[i][num[i]].ch = pre;
            info[i][num[i]++].re = pcnt;
        }
        bool flag = 1;
        int tmp = num[0];
        for (int i = 0; i < n; ++i) {
            if (num[i]!=num[0]){
                flag = 0;
                break;
            }
        }
        for (int i = 0; i < num[0]&&flag; ++i) {
            for (int j = 0; j < n&&flag; ++j) {
                if (info[j][i].ch!=info[0][i].ch) {
                    flag = 0;
                    break;
                }
            }
        }
        int tans,ans = 0,cnt;
        for (int i = 0; i < num[0]&&flag; ++i) {
            cnt = INF;
            for (int j = 1; j <= 100; ++j) {
                tans = 0;
                for (int k = 0; k < n; ++k) {
                    if (info[k][i].re < j) tans += j - info[k][i].re;
                    else {
                        tans += info[k][i].re - j;
                    }
                }
                cnt = min(cnt,tans);
            }
            ans += cnt;
        }
        printf("Case #%d: ",ca);
        if (flag) {
            printf("%d\n",ans);
        } else {
            printf("Fegla Won\n");
        }
    }
    return 0;
}
