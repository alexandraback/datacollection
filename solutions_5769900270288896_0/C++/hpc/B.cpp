#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <queue>
#define MAXN 5
#define INF 1000000000
using namespace std;
int N,R,C;
int process()
{
    if(N<=(R*C+1)/2)
        return 0;
    int sum=(R-1)*C+(C-1)*R;
    if(R>2&&C>2)
    {
        int T=((R-2)*(C-2)+1)/2;
        if(N >=R*C-T) return sum-(R*C-N)*4;
    }
    if(R*C==2&&N==2)
    {
        return 1;
    }
    else if(R==1)
    {
        if(C%2==0) return (N-(R*C+1)/2)*2-1;
        else return (N-(R*C+1)/2)*2;
    }
    else if(C==1)
    {
        if(R%2==0) return (N-(R*C+1)/2)*2-1;
        return (N-(R*C+1)/2)*2;
    }
    else if( (R*C)%2==1)
    {
        if(N>(R*C+1)/2+2) return (N-(R*C+1)/2)*3-1;
        else return (N-(R*C+1)/2)*3;
    }
    else if(R%2==0 && C%2==0)
    {
        if(N-(R*C+1)/2<=2) return (N-(R*C+1)/2)*2;
        else return (N-(R*C+1)/2-2)*3+4;
    }
    else
    {
        if(N-(R*C+1)/2<=2) return (N-(R*C+1)/2)*2;
        else return (N-(R*C+1)/2-2)*3+4;
    }
}
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int Case=1,T;
    scanf("%d",&T);
    //ini();
    while(T--)
    {
        scanf("%d%d%d",&R,&C,&N);
        printf("Case #%d: %d\n",Case++,process());
    }
    return 0;
}
