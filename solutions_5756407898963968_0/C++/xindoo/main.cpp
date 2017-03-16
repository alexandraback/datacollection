#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    int a[5];
    int b[5];
    int n;
    int tmp;
    freopen("out", "w", stdout);
    for (int kase = 1; kase <= t; kase++)
    {
        for (int k = 1; k <= 2; k++)
        {
            scanf("%d", &n);
            for (int i = 1; i <= 4; i++)
            {
                for (int j = 1; j <= 4; j++)
                {
                    if (n == i)
                    {
                        if (k == 1)
                            scanf("%d", &a[j]);
                        else
                            scanf("%d", &b[j]);
                    }
                    else
                        scanf("%d", &tmp);
                }
            }
        }
        int cnt = 0, s = 1;
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                if(a[i] == b[j])
                {
                    cnt++;
                    s = a[i];
                }
            }
        }
        printf("Case #%d: ", kase);
        if (cnt == 1)
            printf("%d\n", s);
        else if (cnt == 0)
            puts("Volunteer cheated!");
        else
            puts("Bad magician!");
    }
    return 0;
}
