#include <cstring>
#include <cstdio>
#include <cstdlib>

int t,x,y,id;
int a[5][5],b[5][5],i,j,n,m;
int main()
{
    freopen("A-small-attempt0.in","r",stdin);freopen("a.out","w",stdout);
    scanf("%d",&t);
    for (id=1;id<=t;id++)
    {
        scanf("%d",&x);
        for (i=1;i<=4;i++)
            for (j=1;j<=4;j++)
                scanf("%d",&a[i][j]);
        scanf("%d",&y);
        for (i=1;i<=4;i++)
            for (j=1;j<=4;j++)
                scanf("%d",&b[i][j]);
        n=0;
        for (i=1;i<=4;i++)
            for (j=1;j<=4;j++)
            if (a[x][i]==b[y][j])
            {
                m=a[x][i];
                n++;
                break;
            }
        printf("Case #%d: ",id);
        if (n==1)printf("%d\n",m);
        else if(n==0)printf("Volunteer cheated!\n");
        else printf("Bad magician!\n");
    }
    return 0;
}
