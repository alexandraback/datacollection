#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define MAXN 200
#define MAXLEN 200
int main()
{
    int T,N;
    int caseNum=1;
    freopen ("A-large.in","r",stdin);
    freopen ("A-large.out","w",stdout);

    scanf("%d", &T);
    while(caseNum<=T)
    {
        char str[MAXN][MAXLEN]={0};
        char chTable[MAXN][MAXLEN]={0};
        int chTableCnt[MAXN][MAXLEN]={0};

        int maxChNum=0;
        bool flag=true;
        scanf("%d", &N);

        for(int i=0; i<N; i++)
        {
            scanf("%s", str[i]);
            int chCnt=1;
            int chNum=0;
            if(strlen(str[i])==1)
            {
                chTable[i][0] = str[i][0];
                chTableCnt[i][0] = 1;
                //printf("%c %d ",chTable[i][chNum], chTableCnt[i][chNum]);
                chNum++;
            }
            else
            {
                for(int j=1; j<strlen(str[i]); j++)
                {
                    if(str[i][j]==str[i][j-1])
                    {
                        chCnt++;
                    }
                    else
                    {
                        chTable[i][chNum] = str[i][j-1];
                        chTableCnt[i][chNum] = chCnt;
                        //printf("%c %d ",chTable[i][chNum], chTableCnt[i][chNum]);
                        chNum++;
                        chCnt = 1;
                    }
                    if(j==(strlen(str[i])-1))
                    {
                        chTable[i][chNum] = str[i][j];
                        chTableCnt[i][chNum] = chCnt;
                        //printf("%c %d ",chTable[i][chNum], chTableCnt[i][chNum]);
                        chNum++;
                    }
                }
            }
            //printf("\n");
            if(maxChNum==0)
            {
                maxChNum = chNum;
            }
            else
            {
                if(maxChNum!=chNum)
                    flag=false;
            }
        }

        for(int i=0; i<maxChNum; i++)
        {
            for(int j=0; j<N-1; j++)
            {
                if(chTable[j][i]!=chTable[j+1][i])
                {
                    flag=false;
                    break;
                }
            }
            if(flag==false)
                break;
        }
        if(flag==false)
            printf("Case #%d: Fegla Won\n", caseNum);
        else
        {
            int chCntSum[MAXLEN]={0};
            int sumDiff=0;
            /*for(int i=0; i<maxChNum; i++)
            {
                int ave=0;
                for(int j=0; j<N; j++)
                {
                    chCntSum[i] = chCntSum[i] + chTableCnt[j][i];
                    //printf("%c",chTable[j][i]);
                }
                //printf("\n");
                ave = chCntSum[i]/N;
                for(int j=0; j<N; j++)
                {
                    diff = diff + abs(chTableCnt[j][i]-ave);
                }
            }*/
            for(int i=0; i<maxChNum; i++)
            {
                int minDiff=100000;
                for(int j=0; j<N; j++)
                {
                    int diff=0;
                    for(int k=0; k<N; k++)
                    {
                        if(j!=k)
                        {
                            diff = diff + abs(chTableCnt[j][i]-chTableCnt[k][i]);
                        }
                    }
                    if(diff<minDiff)
                    {
                        minDiff = diff;
                    }
                }
                sumDiff = sumDiff + minDiff;
            }
            printf("Case #%d: %d\n", caseNum, sumDiff);
        }
        caseNum++;
    }


    return 0;
}
