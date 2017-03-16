#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T, r, c, n, cas, ans;
int m[3000][3000];
void cal(int x, int y, int res){
    //printf("%d %d %d\n", x, y, res);
    if (res == 0){
        int cnt = 0, xx, yy;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (m[i][j] == cas){
                        xx = i + 1, yy = j;
                        if (xx < r && m[xx][yy] == cas){
                                cnt++;
                                //printf("%d %d\n", xx, yy);
                        }
                        xx = i, yy = j+1;
                        if (xx < r && m[xx][yy] == cas){
                                cnt++;
                                //printf("%d %d\n", xx, yy);
                        }
                }
        ans = min(ans, cnt);
        return;
    }
    for (int i = x; i < r; i++)
    for (int j = i==x?y:0; j < c; j++){
            m[i][j] = cas;
            if (j == c-1) cal(i+1, 0, res-1);
            else cal(i, j+1, res-1);
            m[i][j] = 0;
    }
}
int main()
{
    //freopen("B-small-attempt0 (1).in", "r", stdin);
    //freopen("b.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
            ++cas;
            scanf("%d %d %d", &r, &c, &n);
            ans = n * n;
            cal(0, 0, n);
            printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
