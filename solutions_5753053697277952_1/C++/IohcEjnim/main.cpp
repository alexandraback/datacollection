#include <stdio.h>

int t, n;
int pn[26], sum;

int main()
{
    freopen("/Users/IohcEjnim/Downloads/A-large.in.txt", "r", stdin);
    freopen("/Users/IohcEjnim/Downloads/result.txt", "w", stdout);
    
    int tn, i, out, max;
    scanf("%d", &t);
    for (tn = 1; tn <= t; tn++)
    {
        sum = 0;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &pn[i]);
            sum += pn[i];
        }
        
        printf("Case #%d: ", tn);

        if (sum%2 == 1)
        {
            out = -1;
            max = 0;
            for (i = 0; i < n; i++)
            {
                if (pn[i] > max)
                {
                    out = i;
                    max = pn[i];
                }
            }
            printf("%c ", out+'A');
            pn[out]--;
        }
        
        while (1)
        {
            out = -1;
            max = 0;
            for (i = 0; i < n; i++)
            {
                if (pn[i] > max)
                {
                    out = i;
                    max = pn[i];
                }
            }
            if (out == -1) break;
            printf("%c", out+'A');
            pn[out]--;
            
            out = -1;
            max = 0;
            for (i = 0; i < n; i++)
            {
                if (pn[i] > max)
                {
                    out = i;
                    max = pn[i];
                }
            }
            printf("%c ", out+'A');
            pn[out]--;
        }
        printf("\n");
    }
}