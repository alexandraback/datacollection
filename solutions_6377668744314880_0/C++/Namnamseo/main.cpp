#include <cstdio>

int px[3010];
int py[3010];
int t,tc;

int min(int a,int b){ return a>b?b:a; }
int max(int a,int b){ return a>b?a:b; }

int main()
{
    freopen("D:\\gcj\\input.txt","r",stdin);
    freopen("D:\\gcj\\output.txt","w",stdout);
scanf("%d",&t);
for(tc=1;tc<=t;++tc){
    int n;
    scanf("%d",&n);
    int i,j,k;
    for(i=0;i<n;++i) scanf("%d%d",px+i,py+i);
    int cur,lc,rc;
    printf("Case #%d:\n",tc);
    for(i=0;i<n;++i){
        cur=max(0,n-3);
        int x1=px[i], y1=py[i];
        for(j=0;j<n;++j){
            if(i==j) continue;
            lc=rc=0;
            int x2=px[j], y2=py[j];
            for(k=0;k<n;++k){
                int x=px[k], y=py[k];
                lc+=(1LL*(y-y1)*(x2-x1)>1LL*(x-x1)*(y2-y1));
                rc+=(1LL*(y-y1)*(x2-x1)<1LL*(x-x1)*(y2-y1));
            }
            cur=min(cur,min(lc,rc));
        }
        printf("%d\n",cur);
    }
}
    return 0;
}
