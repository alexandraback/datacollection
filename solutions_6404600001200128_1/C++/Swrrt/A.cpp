#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int A[1005];
int main(){
    int T,tt,n,i,j,k,l;
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&T);
    for(tt=1;tt<=T;tt++){
        int s1=0,s2=0,s3;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&A[i]);
        }
        for(i=2;i<=n;i++){
            if(A[i]<A[i-1]){
                s1+=A[i-1]-A[i];
                s2=max(s2,A[i-1]-A[i]);
            }
        }
        s3=0;
        for(i=1;i<n;i++){
            if(A[i]>=s2){
                s3+=s2;
            }else s3+=A[i];
        }
        printf("Case #%d: %d %d\n",tt,s1,s3);
    }
    return 0;
}
