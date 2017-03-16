#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int N,M;
int A[1010];
int B[1010];
int main(){
    freopen("inbl.in","r",stdin);
    freopen("outbl.out","w",stdout);
    int T;scanf("%d",&T);int tt = 0;
    while(T--){tt++;
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;i++){
            scanf("%d",&A[i]);
        }
        long long l = 0,r = (1LL<<60)/1000;
        while(l != r){
            long long mid = (l+r)/2;
            long long sum = 0;
            for(int i=0;i<N;i++){
                sum += mid/A[i]+1;
            }
            if(sum < M) l = mid+1;
            else r = mid;
        }
        int s = 0;
        for(int i=0;i<N;i++){
            if((r%A[i]) == 0){
                B[++s] = i+1;
            }
        }
        int t = 0;
        for(int i=0;i<N;i++){
            t += (r-1)/A[i] +1;
        }
        printf("Case #%d: %d\n",tt,B[M-t]);
    }
    return 0;
}
