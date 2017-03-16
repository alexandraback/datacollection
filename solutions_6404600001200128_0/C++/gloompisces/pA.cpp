#include <stdio.h>

int main()
{
    
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    /*freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    */
    
    int num[1005];
    int cases, N;
    
    scanf("%d", &cases);
    for (int c = 1; c <= cases; c++)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &num[i]);
        }
        
        int ans1 = 0;
        int ans2 = 0;
        
        for (int i = 2; i <= N; i++)
        {
            if (num[i] < num[i - 1])
            {
                ans1 += num[i - 1] - num[i];
            }
        }
        
        int speed = 0;
        for (int i = 2; i <= N; i++)
        {
            if (num[i - 1] - num[i] > speed)
            {
                speed = num[i - 1] - num[i];
            }
        }
        for (int i = 1; i < N; i++)
        {
            if (num[i] > speed)
            {
                ans2 += speed;
            }
            else
            {
                ans2 += num[i];
            }
        }
        
        printf("Case #%d: %d %d\n", c, ans1, ans2);
    }
    
    return 0;
}
