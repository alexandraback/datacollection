#include <stdlib.h>
#include <stdio.h>

int v1[4], v2[4];
int x,y,z,xx;
int cont, rez, t, row;

void main()
{
    FILE *f, *g;
    f = fopen("Ain.txt","r");
    g = fopen("Aout.txt","w");
    fscanf(f,"%d",&t);
    for (int test=0;test<t;test++)
    {
        fscanf(f,"%d",&row);
        for (int j=0;j<4;j++)
        {
            if (j==row-1)
            {
                fscanf(f,"%d %d %d %d",&v1[0],&v1[1],&v1[2],&v1[3]);
            }
            else
            {
                fscanf(f,"%d %d %d %d",&x,&y,&z,&xx);
            }
        }

        fscanf(f,"%d",&row);
        for (int j=0;j<4;j++)
        {
            if (j==row-1)
            {
                fscanf(f,"%d %d %d %d",&v2[0],&v2[1],&v2[2],&v2[3]);
            }
            else
            {
                fscanf(f,"%d %d %d %d",&x,&y,&z,&xx);
            }
        }

        cont = 0;
        for (int i=0;i<4;i++)
        {
            for (int j=0;j<4;j++)
            {
                if (v1[i]==v2[j])
                {
                    cont++;
                    rez=v1[i];
                }
            }
        }

        if (cont==1) fprintf(g,"Case #%d: %d\n",test+1,rez);
        if (cont==0) fprintf(g,"Case #%d: Volunteer cheated!\n",test+1);
        if (cont>1) fprintf(g,"Case #%d: Bad magician!\n",test+1);
    }

    fclose(f);
    fclose(g);
}
