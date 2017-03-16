#include<stdio.h>
#define LL long long
int M[1005];
LL cal(int n,int x,LL t)
{
    LL res = 0;
    for(int i = 0;i<n;i++){
        if(i==x) continue;
        if(i<x){
            res+=t/M[i]+1;
        }
        else{
            if(t%M[i]==0)
                res+=t/M[i];
            else{
                res+=t/M[i]+1;
            }
        }
        if(res>1000000001)
            return res;
    }
    return res;
}
int solve(int n,int k)
{
    LL L,R,mid,count;
    for(int i =0;i<n;i++){
        //printf("%d\n",i);
        L = 0;
        R = k;
        while(L<R){
            mid = (L+R)/2;
            count = cal(n,i,mid*M[i]);
            //printf("%lld %lld %lld %lld\n",L,R,mid,count+mid);
            if(count+mid>k-1){
                R = mid;
            }else if(count+mid<k-1){
                L = mid+1;
            }else{
                return i;
            }
        }
    }
    return -1;
}
int main ()
{
    int T;
    int n,k;
    scanf("%d",&T);
    for(int _ = 1;_<=T;_++){
        scanf("%d%d",&n,&k);
        for(int i =0;i<n;i++){
            scanf("%d",&M[i]);
        }
        printf("Case #%d: %d\n",_,solve(n,k)+1);
    }
    return 0;
}