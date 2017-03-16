#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("A-small-attempt0.in","r", stdin);
    //freopen("aout.out", "w", stdout);
    int mat1[4][4], mat2[4][4];
    int ans1,ans2;
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%d", &ans1);
        ans1--;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                scanf("%d", &mat1[i][j]);
        scanf("%d", &ans2);
        ans2--;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                scanf("%d", &mat2[i][j]);
        int cnt = 0, card = -1;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
            {
                if (mat1[ans1][i] == mat2[ans2][j])
                {
                    ++cnt;
                    card = mat1[ans1][i];
                }
            }
        printf("Case #%d: ", cas);
        if (cnt == 0) puts("Volunteer cheated!");
        else if (cnt > 1) puts("Bad magician!");
        else printf("%d\n", card);
    }


    return 0;
}
