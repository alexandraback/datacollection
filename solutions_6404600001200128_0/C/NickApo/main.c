#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, i;
    FILE * fpin, *fpout;

    fpin=fopen ("A-small-attempt0.in", "r");
    fpout=fopen ("out.txt", "w");

    fscanf (fpin, "%d", &n);

    for (k=1 ; k<=n; k++)
    {
        int intervals, previous, current, diff;
        int sum1=0, sum2=0, maxdiff=0;
        fscanf (fpin, "%d", &intervals);
        int a[intervals];
        fscanf (fpin, "%d", &previous);
        a[0] = previous;
        for ( i=2; i<=intervals; i++)
        {
            fscanf (fpin, "%d", &current);
            a[i-1] = current;
            diff = previous-current;
            if ( diff>0 )
            {
                sum1 += diff;
            }
            if ( diff > maxdiff )
                maxdiff = diff;
            previous = current;
        }

        for ( i=0; i< (intervals-1); i++)
        {
            if ( a[i] < maxdiff )
                sum2 += a[i];
            else
                sum2 += maxdiff;
        }
        fprintf(fpout, "Case #%d: %d %d\n",k, sum1, sum2);

    }

    fclose(fpin);
    fclose(fpout);

    return 0;
}


