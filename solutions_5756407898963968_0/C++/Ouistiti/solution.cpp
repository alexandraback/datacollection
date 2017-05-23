#include <cstdio>

int a[2][4][4];
int poss[17];

int main ()
{
    freopen ("Magic Trick.in","r",stdin);
    freopen ("Magic Trick.out","w",stdout);
    int t;
    scanf ("%d",&t);
    for (int g=1;g<1+t;g++)
    {
        int n1,n2,k=0,ans=0;
        for (int i=1;i<17;i++)
            poss[i] = 0;
        scanf ("%d",&n1);
        for (int i=0;i<4;i++)
            for (int j=0;j<4;j++)
                scanf ("%d",&a[0][i][j]);
        for (int i=0;i<4;i++)
            poss[a[0][n1-1][i]]++;
        scanf ("%d",&n2);
        for (int i=0;i<4;i++)
            for (int j=0;j<4;j++)
                scanf ("%d",&a[1][i][j]);
        for (int i=0;i<4;i++)
            poss[a[1][n2-1][i]]++;
        for (int i=1;i<17;i++)
            if (poss[i]==2)
            {
                k++;
                ans = i;
            }
        printf ("Case #%d: ",g);
        if (k==0) printf ("Volunteer cheated!\n");
        else if (k==1) printf ("%d\n",ans);
        else printf ("Bad magician!\n");   
    }
    scanf (" ");
    return 0;
}
