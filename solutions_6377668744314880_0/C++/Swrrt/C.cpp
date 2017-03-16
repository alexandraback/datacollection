#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define cross(x0,y0,x1,y1,x2,y2) (((x2)-(x0))*((y1)-(y0))-((x1)-(x0))*((y2)-(y0)))
using namespace std;
struct point{
    long long x,y;
}A[3005];
int x;
int Ans[3005];
int main(){
    int T,tt,n,m,i,j,k,l;
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    scanf("%d",&T);
    for(tt=1;tt<=T;tt++){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%I64d%I64d",&A[i].x,&A[i].y);
            Ans[i]=10000000;
        }
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++)
                {
                    int f1=0,f2=0;
                    for(k=1;k<=n;k++)
                        if(k!=i&&k!=j){
                            long long x=cross(A[i].x,A[i].y,A[j].x,A[j].y,A[k].x,A[k].y);
                            if(x>0)f1++;
                            if(x<0)f2++;
                        }
                    f1=min(f1,f2);
                    Ans[i]=min(Ans[i],f1);
                    Ans[j]=min(Ans[j],f1);
                }
        }
        printf("Case #%d:\n",tt);
        for(i=1;i<=n;i++){
            if(n<=3)printf("0\n");
            else printf("%d\n",Ans[i]);
        }
    }
    return 0;
}
