#include <cstdio>
#include <algorithm>
#define forn(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int main()
{
    freopen("B-small-attempt4.in","r",stdin);
    freopen("B-small-attempt4.out","w",stdout);
    int T,R,C,N;
    scanf("%d",&T);
    for(int tc=1;tc<=T;tc++)
    {
        scanf("%d%d%d",&R,&C,&N);
        if(R<C) std::swap(R,C);
        int ret=0,lim,flg,two,thr,fou,one;
        flg=(R*C)%2; //even:0, odd:1
        lim=(flg==0) ? R*C/2:R*C/2+1;
        one=(R%2==0&&C==1) ? 1:0;
        two=(R==1||C==1) ? R/C-one:(flg==0 ? 2:0);
        thr=(R==1||C==1) ? 0:R+C-2-two;
        fou=R*C-lim-two-thr;
        if(N<=lim) ret=0;
        else if(flg==1 && N>=R*C-R/2*C/2+(R/2-1)*(C/2-1)) ret=R*(C-1)+C*(R-1)-R/2*C/2+(R/2-1)*(C/2-1)*4;
        else
        {
            int t=N-lim;
            ret=max(0,min(one,t))+2*max(0,min(two,t-one))+3*max(0,min(thr,t-two-one))+4*max(0,min(fou,t-two-thr-one));
        }
        printf("Case #%d: %d\n",tc,ret);
    }
    return 0;
}
