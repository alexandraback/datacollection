#include <stdio.h>

int main()
{
    /*
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);*/
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    
    
    int M[1005];
    int P[1005];
    
    int cases;
    scanf("%d", &cases);
    
    for (int c = 1; c <= cases; c++)
    {
        int B, N;
        scanf("%d %d", &B, &N);
        for (int i = 1; i <= B; i++)
        {
            scanf("%d", &M[i]);
        }
        
        if (N <= B)
        {
            printf("Case #%d: %d\n", c, N);
        }
        else {
        long long int min_t = 0;
        long long int max_t = 0;
        for (int i = 1; i <= B; i++)
        {
            if (max_t < M[i])
            {
                max_t = M[i];
            }
        }
        max_t *= ((N / B) + 100);
        
        do
        {
            long long int t = (max_t + min_t) / 2;
            long long int nn = 0;
            for (int i = 1; i <= B; i++)
            {
                nn += t / M[i] + 1;
            }
            
            if (nn >= N)
            {
                max_t = t;
            }
            else
            {
                min_t = t;
            }
        }while(max_t - min_t > 1);
        
        int p_n = 0;
        int nn = 0;
        for (int i = 1; i <= B; i++)
        {
            nn += max_t / M[i] + 1;
            if (max_t % M[i] == 0)
            {
                p_n++;
                P[p_n] = i;
            }
        }
        
        if (p_n == 0) while(1);
        int ans = P[p_n - (nn - N)];
        printf("Case #%d: %d\n", c, ans);}
    }
    
    return 0;
}
