#include <cstdio>

int n;
int data[1010];

int max(int a,int b) { return a>b?a:b; }
int min(int a,int b) { return a<b?a:b; }

int main()
{
    freopen("D:\\input","r",stdin);
    freopen("D:\\output","w",stdout);
    int t;
    scanf("%d",&t);
    int a;
for(a=1;a<=t;++a){
    scanf("%d",&n);
    int i;
    for(i=0;i<n;++i) scanf("%d",data+i);
    int ca=0, cb=0;
    int tmp=0;
    for(i=1;i<n;++i){
        if(data[i-1]>data[i]) {
            ca+=data[i-1]-data[i];
            tmp=max(tmp,data[i-1]-data[i]);
        }
    }
    for(i=0;i<n-1;++i) cb+=max(0,min(data[i],tmp));
    printf("Case #%d: %d %d\n",a,ca,cb);
}
    return 0;
}
