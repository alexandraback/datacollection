#include <cstdio>
#include <iostream>
using namespace std;

int a[4][4],b[4][4];
int x,y,z;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int c,t,i,j;
    scanf("%d",&t);
    for(c=0;c<t;c++)
    {
        scanf("%d",&x);
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        scanf("%d",&y);
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                scanf("%d",&b[i][j]);
            }
        }
        z=-1;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(a[x-1][i]==b[y-1][j])
                {
                    if(z==-1)
                    {
                        z=a[x-1][i];
                    }
                    else
                    {
                        z=-2;
                    }
                    break;
                }
            }
            if(z==-2)
            {
                break;
            }
        }
        printf("Case #%d: ",c+1);
        if(z==-2)
        {
            printf("Bad magician!\n");
        }
        else if(z==-1)
        {
            printf("Volunteer cheated!\n");
        }
        else
        {
            printf("%d\n",z);
        }
    }
    return 0;
}
