#include <cstdio>

using namespace std;

int t;
int fcv[10];

int main()
{
    freopen("magictrick.in", "r", stdin);
    freopen("magictrick.out", "w", stdout);

    int i, j, k, cnt, lin, x, aux;

    scanf("%d", &t);
    for (k = 1; k <= t; k++)
    {
        for (i = 1; i <= 16; i++)
            fcv[i] = 0;
        cnt = 0;
        aux = 0;

        scanf("%d", &lin);

        for (i = 1; i <= 4; i++)
            for (j = 1; j <= 4; j++)
            {
                scanf("%d", &x);
                if (i == lin)
                    fcv[x]++;
            }

        scanf("%d", &lin);

        for (i = 1; i <= 4; i++)
            for (j = 1; j <= 4; j++)
            {
                scanf("%d", &x);
                if (i == lin)
                {
                    cnt += fcv[x];
                    if (fcv[x])
                        aux = x;
                }
            }

        printf("Case #%d: ", k);

        if (cnt == 1)
            printf("%d", aux);
        else if (cnt > 1)
            printf("Bad magician!");
        else if (cnt == 0)
            printf("Volunteer cheated!");

        printf("\n");

    }
    return 0;
}
