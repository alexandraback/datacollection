#include<stdio.h>
using namespace std;
int t,n,x,y;
int ar[10][10],ar2[10][10];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);

    scanf("%d",&t);
    for (int i=1;i<=t;i++){
        scanf("%d",&x);
        for (int j=1;j<=4;j++)
            for (int k=1;k<=4;k++)
                scanf("%d",&ar[j][k]);

        scanf("%d",&y);
        for (int j=1;j<=4;j++)
            for (int k=1;k<=4;k++)
                scanf("%d",&ar2[j][k]);

        int coun,ans;
        coun=0;
        ans=-1;
        for (int j=1;j<=4;j++)
            for (int k=1;k<=4;k++)
                if (ar[x][j]==ar2[y][k])
                {
                    coun++;
                    ans=ar[x][j];
                }

        printf("Case #%d: ",i);
        if (ans==-1)
            printf("Volunteer cheated!\n");
        else if (coun>1)
            printf("Bad magician!\n");
        else printf("%d\n",ans);
    }

    return 0;
}
