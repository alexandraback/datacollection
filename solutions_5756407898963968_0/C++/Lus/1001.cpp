#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define N 21
using namespace std;

int ca=1;
int a[N][N],b[N][N],r1,r2,t;
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&r1);
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
                scanf("%d",&a[i][j]);
        scanf("%d",&r2);
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
                scanf("%d",&b[i][j]);
        int ct=0,num;
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j) if(a[r1-1][i]==b[r2-1][j]) num=a[r1-1][i],++ct;
        printf("Case #%d: ",ca++);
        if(ct==0) printf("Volunteer cheated!\n");
        else if(ct==1) printf("%d\n",num);
        else printf("Bad magician!\n");
    }
    return 0;
}

