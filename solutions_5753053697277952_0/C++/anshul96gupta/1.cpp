#include<stdio.h>
using namespace std;
int c[30];
int main()
{
   // freopen("inputa1.in","r",stdin);
 //   freopen("outputa1.txt","w",stdout);
    int t=0;
    scanf("%d",&t);
    int l=0;
    while(l<t)
    {
        l++;
        int n;
        scanf("%d",&n);
        int i,j,total=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&c[i]);
            total+=c[i];
        }
        printf("Case #%d: ",l);
        while(total!=0&&total!=3)
        {
            int m1=0,i1;
            for(j=0;j<2;j++)
            {
                m1=0;
                for(i=0;i<n;i++)
                {
                    if(m1<c[i])
                    {
                        m1=c[i];
                        i1=i;
                    }
                }
                c[i1]--;
                total--;
                printf("%c",i1+'A');
            }
            printf(" ");
        }
        if(total)
        {
            for(i=0;i<n;i++)
            {
                if(c[i])
                {
                    printf("%c ",i+'A');
                    c[i]--;
                    break;
                }
            }
            int p1=0;
            for(i=0;i<n;i++)
            {
                if(c[i])
                {
                    printf("%c",i+'A');
                }
            }
        }
        printf("\n");
    }
    return 0;
}
