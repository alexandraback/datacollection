#include <bits/stdc++.h>

using namespace std;

int grid[4][4];
int grid2[4][4];

pair<int, int> findcard(int g[4][4], int n)
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            if(g[i][j]==n)
                return make_pair(i, j);
    __builtin_unreachable();
}

void solve()
{
    int ans1, ans2;
    scanf("%d", &ans1);
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            scanf("%d", grid[i]+j);
    scanf("%d", &ans2);
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            scanf("%d", grid2[i]+j);
    int ans=-1;
    for(int i=1; i<=16; i++)
    {
        pair<int, int> a=findcard(grid, i);
        pair<int, int> b=findcard(grid2, i);
        if(a.first==ans1-1 && b.first==ans2-1)
        {
            if(ans==-1)
                ans=i;
            else
            {
                printf("Bad magician!\n");
                return;
            }
        }
    }
    if(ans==-1)
        printf("Volunteer cheated!\n");
    else
        printf("%d\n", ans);
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}
