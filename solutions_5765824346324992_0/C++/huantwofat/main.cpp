#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a[50];
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int c[50];
int main()
{
    int i,j,t,n,m,b,N=0;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(i=1;i<=n;i++) scanf("%d",&a[i]);
        int p=a[1];
        for(i=2;i<=n;i++){
            int q=gcd(p,a[i]);
            p=p/q;
            p=p*a[i];
        }
        b=0;
        for(i=1;i<=n;i++){
            b+=p/a[i];
        }
        m=m%b;
        if(m==0) m=b;
        for(i=1;i<=n;i++) c[i]=0;
        int w;
        for(i=1;i<=m;i++){
            int q=10000000;
            for(j=1;j<=n;j++){
                if(q>c[j]){
                    q=c[j];
                    w=j;
                }
            }
            int qq=c[w];
            for(j=1;j<=n;j++){
                c[j]-=qq;
            }
            c[w]=a[w];
        }
        printf("Case #%d: %d\n",++N,w);
    }
}