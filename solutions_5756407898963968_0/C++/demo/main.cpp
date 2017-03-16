#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[2][4][4];
bool choosen[2][17];
int r[2];

int com(int &ans)
{
    memset(choosen,false,sizeof(choosen));
    for(int k=0;k<=1;k++)
    {
        for(int j=0;j<4;j++)
        {
            int x=a[k][r[k]-1][j];
            choosen[k][x]=true;
        }
    }
    int cnt=0;
    for(int i=1;i<=16;i++) if(choosen[0][i]&&choosen[1][i]){ans=i; cnt++;}
    return cnt;
}


int main()
{
    freopen("1.in","r",stdin);
    freopen("A.out","w",stdout);
    int t;
    scanf("%d",&t);
    int c=0;
    while(t--)
    {
        for(int k=0;k<=1;k++)
        {
        scanf("%d",&r[k]);
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++) scanf("%d",&a[k][i][j]);
        }
        printf("Case #%d: ",++c);
        int ans;
        int cnt=com(ans);
        if(cnt==1) printf("%d\n",ans);
        if(cnt==0) printf("Volunteer cheated!\n");
        if(cnt>1) printf("Bad magician!\n");
    }
    return 0;
}












