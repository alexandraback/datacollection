#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct A{
    long long tim;
    int id;
}AA;
AA b[1003];
long long M;
int a[1003];

bool cmp(AA c,AA d){
    if(c.tim!=d.tim)    return c.tim < d.tim;
    return c.id < d.id;
}

int main(){
    int T;
    scanf(" %d",&T);
    for(int t=0,N;t<T && scanf(" %d %lld",&N,&M)==2;t++){
        for(int i=0;i<N;i++)
            scanf(" %d",&a[i]);
        long long low = 0, up = 1000000000000000ll, mid, now;
        while(up>low+1){
            mid = (up+low)/2;
            long long get = 0;
            for(int i=0;i<N;i++){
                if(mid % a[i]!=0)   get++;
                get += mid/a[i];
            }
            if(get>=M)  up = mid;
            else low = mid;
        }
        now = low;
        long long ok = 0;
        for(int i=0;i<N;i++)
            ok += now/a[i];
//        printf("%lld %lld\n",now,ok);
        for(int i=0;i<N;i++){
            long long get = now/a[i];
            b[i].tim = get*a[i];
            b[i].id = i;
        }
        sort(b,b+N,cmp);
        int gap = (int)(M-ok);
        if(gap>N)   while(1);
        printf("Case #%d: %d\n",t+1,b[gap-1].id+1);
    }
    
    return 0;
}
