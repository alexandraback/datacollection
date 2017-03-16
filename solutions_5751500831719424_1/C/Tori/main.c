#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int main()
{

    int t,i,j,k,ci,strings,flag;
    int convLen,stepCount,stepSum,base,l,temp;
    char cc;
    char tab[101][100];
    int converted[101][100];

    scanf("%d",&t);
    getchar();

    for(j=0;j<t;j++)
    {
        scanf("%d",&strings);
        for(i=0;i<strings;i++)
        {
            scanf("%s",tab[i]);

            converted[i][0]=1;
            for(k=1,ci=0,cc=tab[i][0];tab[i][k]!=0;k++)
            {
                if(tab[i][k]==cc)converted[i][ci]++;
                else
                {
                    cc=tab[i][k];
                    ci++;
                    converted[i][ci]=1;
                    tab[i][ci]=cc;
                }
            }
            tab[i][++ci]=0;
        }

        flag=0;
        for(i=0;i<strings-1;i++)
        {
            if(strcmp(tab[i],tab[i+1]))flag=1;
        }
        if(flag)printf("Case #%d: Fegla Won",j+1);
        else
        {
            stepSum = 0;
            convLen = strlen(tab[0]);
            for(i=0;i<convLen;i++)
            {
                stepCount=9999;
                for(k=0;k<strings;k++)
                {
                    base = converted[k][i];
                    temp=0;
                    for(l=0;l<strings;l++)
                    {
                        temp+= abs(base-converted[l][i]);
                    }
                    if(temp<=stepCount)stepCount=temp;
                }
                stepSum += stepCount;
            }
            printf("Case #%d: %d",j+1,stepSum);
        }

        if(j!=t-1)printf("\n");
    }
    return 0;
}
