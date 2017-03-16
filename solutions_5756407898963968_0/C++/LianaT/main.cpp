#include<stdio.h>
int ii, t, j, rez, prez, i, x ,a;
int nr[20];

void citire()
{
    scanf("%ld",&x);
    for (i=1;i<=4;i++)
        for (j=1;j<=4;j++)
        {
            scanf("%ld",&a);
            if (i==x)
                nr[a]++;
        }
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%ld",&t);
    for (ii=1;ii<=t;ii++)
    {
        for (i=1;i<=16;i++)
            nr[i]=0;
        citire();
        citire();
        rez=0;
        for (i=1;i<=16;i++)
            if (nr[i]==2)
            {   rez++;  prez=i; }
        printf("Case #%ld: ",ii);
        if (rez==0)
            printf("Volunteer cheated!\n");
        if (rez==1)
            printf("%ld\n",prez);
        if (rez>1)
            printf("Bad magician!\n");
    }
    return 0;
}
