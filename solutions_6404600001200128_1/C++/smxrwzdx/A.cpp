#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int N;
int A[1010];
int main(){
    freopen("inal.in","r",stdin);
    freopen("outal.out","w",stdout);
    int T;scanf("%d",&T);int tt = 0;
    while(T--){tt++;
        scanf("%d",&N);
        A[0] = 0;
        int sum = 0;
        int ma = 0;
        for(int i=1;i<=N;i++){
            scanf("%d",&A[i]);
            if(A[i] < A[i-1]) sum += A[i-1] - A[i];
            ma = max(ma,A[i-1] - A[i]);
        }
        int sum2 = 0;
        for(int i=1;i<=N;i++){
            sum2 += min(A[i-1],ma);
        }
        printf("Case #%d: %d %d\n",tt,sum,sum2);
    }
    return 0;
}
