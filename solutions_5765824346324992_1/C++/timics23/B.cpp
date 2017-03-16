#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int T,N,B,m[1100];
long long P;

long long caut() {
    long long st = 0, dr = 1LL*N*100000, ret = 0;
    while(st <= dr) {
        long long mij = (st + dr)/2;
        long long people = 0;
        for(int i=1;i<=B;++i) {
            people += 1 + (mij/m[i]);
        }
        if(people >= N) {
            P = people;
            ret = mij;
            dr = mij-1;
        } else {
            st = mij+1;
        }
    }
    return ret;
}

int main() {
    freopen("input.in","r",stdin);
    freopen("outputB","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        printf("Case #%d: ",t);
        scanf("%d%d",&B,&N);
        for(int i=1;i<=B;++i) {
            scanf("%d",&m[i]);
        }
        long long tm = caut(); //time I enter, P = people done 
        for(int i=B;i>=1;--i) {
            if(tm%m[i] == 0) {    
                if(P==N) {
                    printf("%d\n",i);
                    break;
                }
                --P;
            }
        }
    }
    return 0;
}
