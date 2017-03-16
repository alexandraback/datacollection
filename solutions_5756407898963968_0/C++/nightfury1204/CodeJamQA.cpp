//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
int main()
{
    int i,j,k,l,m,t,r,vis[50],a,b;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("Output.txt","w",stdout);
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d",&a);
        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                scanf("%d",&m);
              if(i==a)
                vis[m]++;
            }
        }
        scanf("%d",&b);
        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                scanf("%d",&m);
              if(i==b)
                vis[m]++;
            }
        }
        b=0;
        for(i=1;i<=16;i++)
        {
            if(vis[i]==2)
            {
               b++;
               a=i;
            }
        }
        if(b==1)
            printf("Case #%d: %d\n",r,a);
       else if(b>1)
            printf("Case #%d: Bad magician!\n",r,a);
        else
            printf("Case #%d: Volunteer cheated!\n",r,a);


    }
    fclose(stdout);
    fclose(stdin);
        return 0;
}
