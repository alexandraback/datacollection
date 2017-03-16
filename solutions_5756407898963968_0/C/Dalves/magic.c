#include <stdio.h>
#include <string.h>

void do_magic(int t)
{
    int ans;
    int row[20];
    int i, k, w, m;

    memset(row, 0, sizeof(row));
    printf("Case #%d: ", t);

    for (i = 0; i < 2; ++i)
    {
        scanf("%d", &ans);
        ans--;
        for (k = 0; k < 4; ++k)
        {
            for (w = 0; w < 4; ++w)
            {
                if (k == ans)
                {
                    scanf("%d", &m);
                    row[m]++;
                }
                else
                    scanf("%*d");
            }
        }
    }
    ans = 0;
    for (i = 0; i < 20; ++i)
    {
        if (row[i] > 1)
        {
            if (ans)
            {
                printf("Bad magician!\n");
                return;
            }
            ans = i;
        }
    }
    if (ans)
        printf("%d", ans);
    else
        printf("Volunteer cheated!");
    printf("\n");
}

int main(int argc, char *argv[])
{
    int total, t;

    scanf("%d", &total);
    for (t = 0; t < total; ++t)
    {
        do_magic(t+1);
    }
    return 0;
}
