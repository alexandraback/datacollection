#include <cstdio>
int n,p[70],t,max1,max2,p1,p2;
void findmaximums()
{
    for(int i=1;i<=n;i++)
    {
        if(max1<p[i])
        {
            max1=p[i];
            p1=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i==p1) continue;
        if(max2<p[i])
        {
            max2=p[i];
            p2=i;
        }
    }
}
int main()
{
    freopen ("in.in","r",stdin);
    freopen ("out.out","w",stdout);
    scanf("%d",&t);
    for(int xyz=1;xyz<=t;xyz++)
    {

        scanf("%d",&n);
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&p[i]);
            sum+=p[i];
        }
        printf("Case #%d: ",xyz);
        while(1)
        {
            max1=0;
            max2=0;
            p1=0;
            p2=0;
            findmaximums();
            if(max2>(sum-1)/2)
            {
                p[p1]--;
                p[p2]--;
                sum-=2;
                printf("%c%c ",'A'+p1-1,'A'+p2-1);
            }
            else
            {
                p[p1]--;
                sum--;
                printf("%c ",'A'+p1-1);
            }
            if(sum==0) break;
        }
        printf("\n");
    }
}
