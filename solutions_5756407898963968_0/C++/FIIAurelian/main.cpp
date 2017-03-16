#include<cstdio>
#include<cstring>
#define max(a,b) a>b?a:b
int Visited[20],numberOfTests,value,row,i,j;
void ComputeAnswer()
{
    int answer = 0;
    for(int i=1;i<=16;i++)
    {
        if(Visited[i] == 2)
        {
            if(answer)
            {
                printf("Bad Magician!\n");
                return;
            }
            answer = i;
        }
    }
    if(answer)
    {
        printf("%d\n",answer);
        return;
    }
    printf("Volunteer cheated!\n");
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&numberOfTests);
    for(int testNo=1;testNo<=numberOfTests;testNo++)
    {
        memset(Visited,0,sizeof(Visited));
        scanf("%d",&row);
        for(i=1;i<=4;i++)
            for(j=1;j<=4;j++)
            {
                scanf("%d",&value);
                if(i == row)Visited[value]++;
            }
        scanf("%d",&row);
        for(i=1;i<=4;i++)
            for(j=1;j<=4;j++)
            {
                scanf("%d",&value);
                if(i == row)Visited[value]++;
            }
        printf("Case #%d: ",testNo);
        ComputeAnswer();
    }
    return 0;
}
