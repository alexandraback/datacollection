#include <stdio.h>
#include <string.h>

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    
    int cases;
    int map[20];
    
    scanf("%d", &cases);
    for (int case_index = 1; case_index <= cases; case_index++)
    {
        memset(map, 0, sizeof(map));
        int row;
        
        scanf("%d", &row);
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                int k;
                scanf("%d", &k);
                if (i == row) map[k]++;
            }
        }
        
        scanf("%d", &row);
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                int k;
                scanf("%d", &k);
                if (i == row) map[k]++;
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= 16; i++)
        {
            if (map[i] == 2)
            {
                if (ans == 0)
                {
                    ans = i;
                }
                else
                {
                    ans = -1;
                }
            }
        }
        
        if (ans == 0)
        {
            printf("Case #%d: Volunteer cheated!\n", case_index);
        }
        else if (ans == -1)
        {
            printf("Case #%d: Bad magician!\n", case_index);
        }
        else
        {
            printf("Case #%d: %d\n", case_index, ans);
        }
    }
    
    return 0;
}
