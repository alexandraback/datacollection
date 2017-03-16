#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int A[1005];
struct data{
    int x,zx;
}B[1005];
bool operator < (data a,data b){
    return a.x<b.x||(a.x==b.x&&a.zx<b.zx);
}
int main(){
    int T,tt,n,m,i,j,k,l;
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&T);
    for(tt=1;tt<=T;tt++){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)scanf("%d",&A[i]);
        long long L=0,R=10000000000000000ll;
        while(L<=R){
            long long mid=(L+R)>>1;
            long long t=0;
            for(i=1;i<=n;i++)t+=(mid/A[i])+1;
            if(t>=m)R=mid-1;
            else L=mid+1;
        }
        long long t=0;
        for(i=1;i<=n;i++){
            t+=(R/A[i])+1;
            B[i].x=A[i]-R%A[i];
            B[i].zx=i;
        }
        sort(B+1,B+1+n);
        printf("Case #%d: ",tt);
        if(m<=n)printf("%d\n",m);
        else printf("%d\n",B[m-t].zx);
    }
    return 0;
}
