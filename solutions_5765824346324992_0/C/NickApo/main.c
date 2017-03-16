#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    FILE * fpin, *fpout;

    fpin=fopen ("B-small-attempt2.in", "r");
    fpout=fopen ("out.txt", "w");

    fscanf (fpin, "%d", &n);

    for (k=1 ; k<=n; k++)
    {
        int barbers, i, position, servedby=0;
        int prod=1;
        int step=0;
        fscanf (fpin, "%d", &barbers);
        fscanf(fpin, "%d", &position);
        int minutes[barbers], current[barbers];
        for ( i=0; i<barbers; i++)
        {
            fscanf (fpin, "%d", &minutes[i]);
            current[i]=0;
            prod *= minutes[i];
        }

        for ( i=0; i<barbers; i++)
        {
            step += (prod/minutes[i]);
        }

        position = position%step;
        if (position==0)
            position=step;

        while (servedby == 0)
        {
            for ( i=0; i<barbers; i++)
            {
                if (current[i]==0)
                {
                    current[i] = minutes[i];
                    position--;
                    if (position == 0)
                    {
                        servedby = i+1;
                        break;
                    }
                }
            }

            for ( i=0; i<barbers; i++)
            {
                current[i]--;
            }

        }

        fprintf (fpout,"Case #%d: %d\n", k, servedby);
    }

    fclose(fpin);
    fclose(fpout);

    return 0;
}



