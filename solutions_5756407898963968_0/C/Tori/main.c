#include <stdio.h>

int main()
{
    int testCases,t,i,rows,pos;
    int rowPicked,discard,anwser,bad;
    int possibleCards[4][2];

    scanf("%d",&testCases);

    for(t=1;t<=testCases;t++)
    {
        for(i=0;i<2;i++)
        {
        scanf("%d",&rowPicked);
            for(rows=1; rows<=4;rows++)
            {
                if(rows==rowPicked)
                {
                    scanf("%d %d %d %d",&possibleCards[0][i],&possibleCards[1][i],&possibleCards[2][i],&possibleCards[3][i]);
                }
                else
                {
                    scanf("%d %d %d %d",&discard,&discard,&discard,&discard);
                }
            }
        }

        for(pos=0; pos<4;pos++)
        {
            int check = 3;
            for(;check>=0;check--)
            {
                if(possibleCards[pos][0]==possibleCards[check][1])break;
            }
            if(check==-1)possibleCards[pos][0]=0;
        }

        anwser = 0;
        bad = 0;
        for(pos=0; pos<4;pos++)
        {
            if(possibleCards[pos][0])
            {
                if(anwser)
                {
                    bad = 1;
                    break;
                }
                else
                {
                    anwser = possibleCards[pos][0];
                }
            }
        }

        if(bad)printf("Case #%d: Bad magician!",t);
        else if(!anwser)printf("Case #%d: Volunteer cheated!",t);
        else printf("Case #%d: %d",t,anwser);

        if(testCases!=t)printf("\n");
    }

    return 0;
}
