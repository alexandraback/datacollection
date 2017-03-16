#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>

#define LL long long 
using namespace std;
const int maxn = 1005;
const LL inf = (LL)1e18;

int b,n;
int bar[maxn];
LL test(LL x){
    LL res = 0;
    for(int i=1;i<=b;i++){
        LL v = x/(LL)bar[i];
        while ( v*bar[i]<x ) v++;
        res += v;
    }
    return res;
}

LL a[maxn];

int main(){

    int t; scanf("%d",&t);
    for(int it=1;it<=t;it++){
        scanf("%d%d" , &b,&n);
        for(int i=1;i<=b;i++)
            scanf("%d",&bar[i]);

        LL l = 0 , r = inf , mid;
        while ( l<r-1 ){
            mid = (l+r)>>1;
            if( test(mid)<=(LL)n ) l = mid;
            else r = mid;
        }
        if( test(l)<=(LL)n ) mid = l;
        else mid = r;

        while ( test(mid)==(LL)n ) mid--;
        int m = (int)test(mid);
        for(int i=1;i<=b;i++){
            LL v = mid/bar[i];
            if (  v*bar[i]<mid ) v++;
            a[i] = v*bar[i];
        }

        int k = -1; LL v;
        while ( m<n ){
            k = -1;  v = inf;
            for(int i=1;i<=b;i++){
                if ( v>a[i] ){
                    k = i ; v = a[i];
                }
            }
            a[k] += bar[k];
            m++;
        }
        printf("Case #%d: %d\n" , it,k);
    }

    return 0;
}