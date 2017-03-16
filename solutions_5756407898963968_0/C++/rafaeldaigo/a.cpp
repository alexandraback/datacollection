#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int main()
{
    int t, teste;
    int n;
    int i, j;
    int a;
    int mat[4][4];
    int can[4];
    scanf("%d\n", &teste);
    for (int t = 0; t < teste; t++)
    {
        scanf("%d\n", &a);
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                scanf("%d", &mat[i][j]);
            }
        }
        for (j = 0; j < 4; j++)
        {
            can[j] = mat[a-1][j];
        }

        int ans = 0;
        int found = 0;
        scanf("%d\n", &a);
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                scanf("%d", &mat[i][j]);
            }
        }

        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (can[i] == mat[a-1][j])
                {
                    found++;
                    ans = can[i];
                }
            }
        }

        if (found == 0)
        {
            printf("Case #%d: Volunteer cheated!\n", t + 1);
        }
        else if (found > 1)
        {
            printf("Case #%d: Bad magician!\n", t + 1);
        }
        else
        {
            printf("Case #%d: %d\n", t + 1, ans);
        }
    }
    return 0;
}
