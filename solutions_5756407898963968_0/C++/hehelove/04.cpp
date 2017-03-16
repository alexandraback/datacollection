#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int f1[5][5],f2[5][5];
int main()
{
    int T,i,j,n,m,cas=0;
    freopen("A-small-attempt1.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=1;i<5;i++)
        for(j=1;j<5;j++)
        scanf("%d",&f1[i][j]);
        scanf("%d",&m);
        for(i=1;i<5;i++)
        for(j=1;j<5;j++)
        scanf("%d",&f2[i][j]);
        int sum=0,ii=-1;
        for(i=1;i<5;i++)
        {
            for(j=1;j<5;j++)
            if(f1[n][i]==f2[m][j])
            {
                sum++;
                ii=f1[n][i];
            }
        }
        printf("Case #%d: ",++cas);
        if(sum==0)
        puts("Volunteer cheated!");
        else if(sum>1)
        puts("Bad magician!");
        else printf("%d\n",ii);
    }
    return 0;
}
