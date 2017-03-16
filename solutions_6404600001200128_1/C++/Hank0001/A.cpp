#include<stdio.h>
#include<cstdlib>
int dat[1002];
int main()
{
    freopen("a.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,n;
    int x,y;
    int tmp;
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&dat[i]);
        x=y=0;
        tmp=0;
        for(int i=1;i<n;i++){
            if(dat[i-1]-dat[i]>0) x+=dat[i-1]-dat[i];
            if(dat[i-1]-dat[i]>tmp) tmp=dat[i-1]-dat[i];
        }
        
        for(int i=1;i<n;i++){
            if(dat[i-1]<tmp) y+=dat[i-1];
            else             y+=tmp;
        }
        printf("Case #%d: %d %d\n",kase,x,y);
    }
}
