#include <algorithm>
#include <cstdio>
using namespace std;
int T,i,j,k,R,C,N;
int getUnhappiness1(int,int,int);
int getUnhappiness2(int,int,int);
int main()
{
    freopen("ProblemB.in","r",stdin);

    freopen("ProblemB.out","w",stdout);

    scanf("%d",&T);

    for(i=1;i<=T;i++)
    {
        scanf("%d %d %d",&R,&C,&N);

        if(N<=(R*C+1)/2)
        {
            printf("Case #%d: 0\n",i);
        }
        else
        {
            printf("Case #%d: %d\n",i,min(getUnhappiness1(R,C,N),getUnhappiness2(R,C,N)));
        }
    }

    return 0;
}
int getUnhappiness1(int r,int c,int n)
{
    int total,unhappiness,elim,elimMax,jMax,kMax;

    total=r*c;;

    unhappiness=2*r*c-r-c;

    int A[r+2][c+2];

    for(j=0;j<=r+1;j++)
    {
        for(k=0;k<=c+1;k++)
        {
            if(j!=0 && j!=R+1 && k!=0 && k!=C+1)
            {
                A[j][k]=1;
            }
            else
            {
                A[j][k]=0;
            }
        }
    }

    while(total!=n)
    {
        total--;

        elimMax=0;

        jMax=0;

        kMax=0;

        for(j=1;j<=R;j++)
        {
            for(k=1;k<=C;k++)
            {
                if(A[j][k]==1)
                {
                    elim=A[j-1][k]+A[j+1][k]+A[j][k-1]+A[j][k+1];

                    if(elim>elimMax)
                    {
                        elimMax=elim;

                        jMax=j;

                        kMax=k;
                    }
                }
            }
        }

        A[jMax][kMax]=0;

        unhappiness-=elimMax;
    }

    return unhappiness;
}
int getUnhappiness2(int r,int c,int n)
{
    int total,unhappiness,add,addMin,jMin,kMin;

    total=0;

    unhappiness=0;

    int A[r+2][c+2];

    for(j=0;j<=r+1;j++)
    {
        for(k=0;k<=c+1;k++)
        {
            A[j][k]=0;
        }
    }

    while(total!=n)
    {
        total++;

        addMin=0;

        jMin=0;

        kMin=0;

        for(j=1;j<=R;j++)
        {
            for(k=1;k<=C;k++)
            {
                if(A[j][k]==0)
                {
                    add=A[j-1][k]+A[j+1][k]+A[j][k-1]+A[j][k+1];

                    if(add<addMin || addMin==0)
                    {
                        addMin=add;

                        jMin=j;

                        kMin=k;
                    }
                }
            }
        }

        A[jMin][kMin]=1;

        unhappiness+=addMin;;
    }

    return unhappiness;
}
