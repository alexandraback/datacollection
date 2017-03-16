#include<bits/stdc++.h>
using namespace std;

long long ck(int m[],int b,long long x){
    long long r=0;
    for(int i=0;i<b;i++){
        r+=x/m[i];
        if(x%m[i])
            r++;
    }
    return r;
}


int main(){
    int t,tk=1;
    scanf("%d",&t);
    while(t--){
        int b,m[1024];
        long long n;
        scanf("%d%lld",&b,&n);
        for(int i=0;i<b;i++)
            scanf("%d",m+i);
        long long l=0,r=100000000000001ll,md;
        while(r-l>1){
            md=(l+r)/2;
            if(ck(m,b,md)>=n)
                r=md;
            else
                l=md;
        }
        int ans=-1;
        long long prio = n-ck(m,b,l);
        for(int i=0;i<b;i++){
            if(l%m[i]==0){
                prio--;
                if(prio==0){
                    ans=i+1;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n",tk++,ans);
    }
}

