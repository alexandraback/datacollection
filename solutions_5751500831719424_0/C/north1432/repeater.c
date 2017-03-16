#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("Aout.out","w",stdout);
    int t,test;
    scanf("%d",&test);
    for (t=1;t<=test;t++)
    {
        printf("Case #%d: ",t);
        int n;
        scanf("%d",&n);
        char c[n][101];
        int i,j,k,count=0;
        for (i=0;i<n;i++)
        {
            scanf("%s",c[i]);
        }
        char base[101];
        int len = strlen(c[0]);
        char pick = c[0][0];
        base[0] = pick;
        int ptr = 1;
        for (i=1;i<len;i++)
        {
            if (c[0][i] != pick)
            {
                pick = c[0][i];
                base[ptr] = pick;
                ptr++;
            }
        }
        int dat[n][ptr];
        // check if fegla won
        for (i=1;i<n;i++)
        {
            int ptr2 = 0;
            for (j=0;j<ptr;j++)
            {
                if(base[j] != c[i][ptr2])
                {
                    printf("Fegla Won\n");
                    goto end;
                }
                while (c[i][ptr2] == c[i][ptr2+1]) ptr2++;
                ptr2++;
            }
            if (c[i][ptr2] != '\0')
            {
                printf("Fegla Won\n");
                goto end;
            }
        }
        // check for least move possible
        for (i=0;i<n;i++)
        {
            for (j=0;j<ptr;j++)
            {
                dat[i][j] = 0;
            }
        }
        for (i=0;i<n;i++)
        {
            len = strlen(c[i]);
            pick = c[i][0];
            dat[i][0] = 1;
            int ptr2=0;
            for (j=1;j<len;j++)
            {
                if(pick == c[i][j]) dat[i][ptr2]++;
                else
                {
                    pick = c[i][j];
                    ptr2++;
                    dat[i][ptr2]++;
                }
            }
        }

        // find median for each character
        for (j=0;j<ptr;j++)
        {
            // sort
            for (i=0;i<n-1;i++)
            {
                for (k=i+1;k<n;k++)
                {
                    if(dat[i][j] > dat[k][j])
                    {
                        int temp = dat[i][j];
                        dat[i][j] = dat[k][j];
                        dat[k][j] = temp;
                    }
                }
            }
            // median
            int median;
            if (n%2 == 0)
            {
                median = (dat[n/2-1][j]+dat[n/2][j])/2;
            }
            else
            {
                median = dat[n/2][j];
            }
            // count number of move
            for (i=0;i<n;i++)
            {
                count += abs(dat[i][j]-median);
            }
        }
        printf("%d\n",count);
        end:;
    }
}
