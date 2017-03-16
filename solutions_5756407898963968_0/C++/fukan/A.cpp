#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

long long mp1[10][10],mp2[10][10];

int main()
{
    int T,cas,r1,r2;
    long long c;
    freopen("1.txt","r",stdin);
    freopen("11.out","w",stdout);
    scanf("%d",&T);
    for(cas=1;cas<=T;cas++)
    {
        scanf("%d",&r1);
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
                scanf("%lld",&mp1[i][j]);
        }
        scanf("%d",&r2);
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
                scanf("%lld",&mp2[i][j]);
        }
        int flag=0;
        c=0;
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                if(mp1[r1][i]==mp2[r2][j])
                {
                    if(!c)
                    {
                        flag = 2;  //yes
                        c = mp1[r1][i];
                    }
                    else flag = 1; //bad
                }
            }
        }
        if(flag==0)
            printf("Case #%d: Volunteer cheated!\n",cas);
        else if(flag==2)
            printf("Case #%d: %lld\n",cas,c);
        else printf("Case #%d: Bad magician!\n",cas);
    }
    return 0;
}
