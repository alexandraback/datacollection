#include<stdio.h>
#include<algorithm>
using namespace std;
struct party
{
    int num;
    char name;
    bool operator<(const party x)const
    {
        return num>x.num;
    }
}par[100];
int n;
main()
{
    int sum,nq,q,i,j,k;
    scanf("%d",&nq);
    for(q=1;q<=nq;q++)
    {
        scanf("%d",&n);
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&par[i].num);
            par[i].name='A'+i;
            sum+=par[i].num;
        }
        sort(par,par+n);
//        for(i=0;i<n;i++)
//            printf("%c: %d\n",par[i].name,par[i].num);
        printf("Case #%d: ",q);
        i=0;
        j=1;
        while(j<n&&par[j].num==par[i].num)
            j++;
        while(sum>0)
        {
            for(i=0;i<j;)
            {
                if(i+1>=j||(sum==3&&j-i==3))
                {
                    printf("%c ",par[i].name);
                    par[i].num--;
                    i++;
                    sum--;
                }
                else if(par[i].num==par[i+1].num)
                {
                    printf("%c%c ",par[i].name,par[i+1].name);
                    par[i].num--;
                    par[i+1].num--;
                    i+=2;
                    sum-=2;
                }
            }
            while(j<n&&par[j].num==par[j-1].num)
                j++;
//            printf("\n");
//            for(i=0;i<n;i++)
//                printf("%c: %d\n",par[i].name,par[i].num);
        }
        printf("\n");
    }
}
