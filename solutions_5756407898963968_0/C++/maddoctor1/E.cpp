#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define LL long long
#define MAXN 222
#define MAXM 55555
#define INF 11111111
using namespace std;
int a[22];
int num1[6][6];
int num2[6][6];
int main()
{
    int T, x, y;
    int cas = 0;
    freopen("C:/A-small-attempt0.in", "r", stdin);
    freopen("C:/a.out", "w", stdout);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &x);
        for(int i = 1; i <= 4; i ++)
            for(int j = 1; j <= 4; j++)
                scanf("%d", &num1[i][j]);
         scanf("%d", &y);
         for(int i = 1; i <= 4; i ++)
            for(int j = 1; j <= 4; j++)
                scanf("%d", &num2[i][j]);
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= 4; i++) a[num1[x][i]]++, a[num2[y][i]]++;
        int cnt = 0;
        int ans = 0;
        for(int i = 1; i <= 16; i++)
            if(a[i] == 2) cnt++, ans = i;
        printf("Case #%d: ", ++cas);
        if(cnt == 1) printf("%d\n", ans);
        else if(cnt == 0) printf("Volunteer cheated!\n");
        else printf("Bad magician!\n");
    }
    return 0;
}
