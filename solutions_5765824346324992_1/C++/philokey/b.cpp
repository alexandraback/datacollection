#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 105;
char num[10][8] = {"1111110", "0110000","1101101","1111001","0110011","1011011","1011111","1110000","1111111","1111011"};
int n;
char clo[MAXN][8];
int lit[8];
 int alit[8];
bool check(int t) {
    memset(lit,0,sizeof(lit));
    int st = t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (num[t][j] == '0' && clo[i][j] == '1') return 0;
            if (lit[j] == 1) {
                if (num[t][j] == '1' && clo[i][j] == '0') return 0;
            } else if (lit[j] == -1) {
                if (clo[i][j] == '1') return 0;
            } else {
                if (num[t][j] == '1' && clo[i][j] == '0') lit[j] = -1;
                if (num[t][j] == '1' && clo[i][j] == '1') lit[j] = 1;
            }
        }
        t -= 1;
        if (t == -1) t = 9;
    }
    return 1;
}
bool check2(int t) {
    for (int i = 0; i < 7; ++i) {
        if (num[t][i] == '1'&&alit[i] == 0) return 0;
    }
    return 1;
}
int main()
{

    //freopen("/home/qitaishui/practice/retired/in.txt","r",stdin);
    freopen("/home/qitaishui/practice/retired/A-large.in","r",stdin);
    freopen("/home/qitaishui/practice/retired/out.txt","w",stdout);
    int cas;
    scanf("%d",&cas);
    for (int ca = 1; ca <= cas; ++ca) {
        scanf("%d",&n);
        for (int i = 0; i < n; ++i) {
            scanf("%s",clo[i]);
        }
        int ans = -1;

        for (int i = 0; i < 10; ++i) {
            if (check(i)) {

                if (ans != -1) {ans = -1;break;}
                memcpy(alit,lit,sizeof(lit));
                ans = (i - n % 10 + 10) % 10;
            }
        }
        //printf ("%d\n",ans);
        printf("Case #%d: ",ca);
        if (ans != -1 && check2(ans) == 0) ans = -1;
        if (ans == -1) {
            printf("ERROR!\n");
        } else {
            for (int i = 0; i < 7; ++i) {
                if (num[ans][i] == '1' && alit[i] == 1) {
                    printf("1");
                } else {
                    printf("0");
                }
            }
            printf("\n");
        }
    }
    return 0;
}

