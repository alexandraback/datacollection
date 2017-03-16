//
//  main.cpp
//  Magic Trick
//

#include <iostream>

int main(int argc, const char * argv[])
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int ncases;
    scanf("%d", &ncases);
    
    for (int i = 0; i < ncases; ++i)
    {
        int ans1, ans2;
        int c[4];
        int d[4];
        int tmp[4];
        
        scanf("%d", &ans1);
        for (int j = 0; j < 4; ++j)
        {
            if (j == ans1-1)
            {
                scanf("%d %d %d %d", &c[0], &c[1], &c[2], &c[3]);
            }
            else
            {
                scanf("%d %d %d %d", &tmp[0], &tmp[1], &tmp[2], &tmp[3]);
            }
        }
        scanf("%d", &ans2);
        for (int j = 0; j < 4; ++j)
        {
            if (j == ans2-1)
            {
                scanf("%d %d %d %d", &d[0], &d[1], &d[2], &d[3]);
            }
            else
            {
                scanf("%d %d %d %d", &tmp[0], &tmp[1], &tmp[2], &tmp[3]);
            }
        }
        
        int cnt = 0;
        int card;
        
        for (int k = 0; k < 4; ++k)
            for (int l = 0; l < 4; ++l)
                if (c[k] == d[l])
                {
                    cnt++;
                    card = c[k];
                }
        
        if (cnt == 1)
            printf("Case #%d: %d\n", i+1, card);
        else if (cnt > 1)
            printf("Case #%d: Bad magician!\n", i+1);
        else if (cnt < 1)
            printf("Case #%d: Volunteer cheated!\n", i+1);
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}

