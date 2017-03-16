#include <stdio.h>

#define MAX 16

int main()
{
    int t;
    scanf("%d",&t);
    for(int ccnt=1; ccnt<=t; ++ccnt)
    {
        int v[MAX];
        for(int i=0; i<MAX; ++i)
            v[i]=0;
        int chosen;
        int tmp;

        for(int rounds=0; rounds<2; ++rounds)
        {
            scanf("%d", &chosen);
            --chosen;

            for(int i=0; i<4; ++i)
                for(int j=0; j<4; ++j)
                {
                    scanf("%d", &tmp);
                    if(i==chosen)
                        v[--tmp]++;
                }
        }
        
        int answer = -1;
        for(int i=0; i<16; ++i)
            if(v[i]>1 && answer>=0)
                answer=17;
            else if(v[i]>1)
                answer=i;

        printf("Case #%d: ",ccnt);
        if(answer<0)
            printf("Volunteer cheated!\n");
        else if(answer>15)
            printf("Bad magician!\n");
        else
            printf("%d\n",answer+1);
    }
    return 0;
}
