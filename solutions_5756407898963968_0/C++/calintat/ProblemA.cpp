#include <cstdio>
using namespace std;
int i,j,k,T,M,x,ok,answer,useless,v1[5],v2[5];
int main()
{
    freopen("ProblemA.in","r",stdin);
    freopen("ProblemA.out","w",stdout);
    scanf("%d",&T);
    for(k=1;k<=T;k++)
    {
        scanf("%d",&answer);
        for(i=1;i<=4;i++)
        {
            if(i==answer)
            {
                for(j=1;j<=4;j++)
                scanf("%d",&v1[j]);
            }
            else
            {
                for(j=1;j<=4;j++)
                scanf("%d",&useless);
            }
        }
        scanf("%d",&answer);
        for(i=1;i<=4;i++)
        {
            if(i==answer)
            {
                for(j=1;j<=4;j++)
                scanf("%d",&v2[j]);
            }
            else
            {
                for(j=1;j<=4;j++)
                scanf("%d",&useless);
            }
        }
        M=0;
        for(i=1;i<=4;i++)
        {
            ok=1;
            for(j=1;j<=4 && ok;j++)
            {
                if(v1[i]==v2[j])
                {
                    ok=0;
                    if(M==0)
                    {
                        M++;
                        x=v1[i];
                    }
                    else
                    M++;
                }
            }
        }
        if(M==0)
        printf("Case #%d: Volunteer cheated!\n",k);
        else if(M==1)
        printf("Case #%d: %d\n",k,x);
        else
        printf("Case #%d: Bad magician!\n",k);
    }
}
