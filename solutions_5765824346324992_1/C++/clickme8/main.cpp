#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
long long b,m;
long long int a[1005];

long long f(long long t){
long long sum=0;
for(int i=0;i<b;i++)
    sum+=t/a[i];
return sum;
}

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int t,tt=0;
    cin>>t;
    while(t--){
        tt++;
        cin>>b>>m;
        for(int i=0;i<b;i++)
            cin>>a[i];
        if(m<=b){
            printf("Case #%d: %lld\n",tt,m);
            continue;
        }
        m-=b;
        long long s,d;
        s=1;d=1e16;
        while(d-s>1){
            long long t1;
            t1=f((s+d)/2);
            if(t1>=m)
                d=(s+d)/2;
            else
                s=(s+d)/2;
        }
        m-=f(s);
        int ans=0,cnt=0;
        for(int i=0;i<b;i++)
            if(d%a[i]==0){
                cnt++;
            if(cnt==m)
                ans=i+1;
        }
        printf("Case #%d: %I64d\n",tt,ans);
    }

    return 0;
}
