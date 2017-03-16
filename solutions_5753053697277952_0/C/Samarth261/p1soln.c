#include<stdio.h>

FILE *qf;
FILE *af;

int sets[26];
int total;

int main()
{
    int ntc;
    int i;
    int p;
    int j;
    int max1,max2;
    int nmax;
    int max;

    qf=fopen("question1.txt","r");
    af=fopen("answer1.txt","w");
    fscanf(qf,"%d",&ntc);

    for(i=1;i<=ntc;i++)
    {
        total=0;
        max1=-1;
        max2=-1;
        nmax=0;
        max=0;
        fscanf(qf,"%d",&p);
        for(j=0;j<p;j++)
        {
            fscanf(qf,"%d",&sets[j]);
            total+=sets[j];
        }

        fprintf(af,"Case #%d:",i);

        while(total>0)
        {

            max=sets[0];
            nmax=1;
            max2=-1;
            max1=0;
            for(j=1;j<p;j++)
            {
                if(sets[j]>max)
                {
                    nmax=1;
                    max2=-1;
                    max=sets[j];
                    max1=j;
                }
                else if(sets[j]==max)
                {
                    nmax++;
                    max2=j;
                }

            }

            if(nmax==1||nmax>2)
            {
                fprintf(af," %c",(65+max1));
                total--;
                sets[max1]--;
            }
            else if(nmax==2)
            {
                fprintf(af," %c%c",(65+max1),(65+max2));
                total--;
                total--;
                sets[max1]--;
                sets[max2]--;
            }
        }

        fprintf(af,"\n");
    }
}
