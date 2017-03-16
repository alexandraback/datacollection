#include<cstdio>
#include<cstring>
using namespace std;

int s[10][10], t[10][10];

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif // LOCAL
    int tcase, tmp=1;
    scanf("%d", &tcase);
    while(tcase--)
    {
        int x, y;
        scanf("%d", &x);
        for(int i=1; i<=4; i++)
            for(int j=1; j<=4; j++)
                scanf("%d", &s[i][j]);
        scanf("%d", &y);
        for(int i=1; i<=4; i++)
            for(int j=1; j<=4; j++)
                scanf("%d", &t[i][j]);
        int cnt=0, ans;
        for(int i=1; i<=4; i++)
            for(int j=1; j<=4; j++)
                if(t[y][j] == s[x][i])
                {
                    cnt++;
                    ans=s[x][i];
                    break;
                }
        if(cnt == 0)
            printf("Case #%d: Volunteer cheated!\n", tmp++);
        else if(cnt == 1)
            printf("Case #%d: %d\n", tmp++, ans);
        else printf("Case #%d: Bad magician!\n", tmp++);
    }
    return 0;
}
