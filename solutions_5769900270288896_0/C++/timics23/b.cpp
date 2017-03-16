#include<stdio.h>
#include<iostream>
using namespace std;
int mi,T,R,C,N,k,a[20],v[20];
bool viz[20];

void backy(int x) {
    if(x==k+1) {
        int rez = 0;
        for(int i=1;i<=N;++i) {
            viz[i] = 0;
        }
        for(int i=1;i<=k;++i) {
            viz[a[i]] = 1;
        }
        for(int i=1;i<R;++i) {
            for(int j=1;j<=C;++j) {
                if(viz[C*(i-1)+j] && viz[C*i+j]) {
                    ++rez;
                }
            }
        }
        for(int i=1;i<=R;++i) {
            for(int j=1;j<C;++j) {
                if(viz[C*(i-1)+j] && viz[C*(i-1)+j+1]) {
                    ++rez;
                }
            }
        };
        if(rez < mi) {
            mi = rez;
        }
    }
    else {
        for(int i=1;i<=N;++i) {
            if((v[i]==0)&&(i>a[x-1])) {
                a[x]=i;
                v[i]=1;
                backy(x+1);
                v[i]=0;
            }
        }
    }
}

int main() {
    freopen("input.in","r",stdin);
    freopen("outB.out","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        printf("Case #%d: ",t);
        scanf("%d%d%d",&R,&C,&k);
        
        N = R*C;
        mi = 2*R*C - R - C;
        backy(1);
        printf("%d\n",mi);
    }
    return 0;
}
