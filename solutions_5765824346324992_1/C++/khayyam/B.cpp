#include <stdio.h>
#define MIN(a, b) (((a)<(b))?(a):(b))
#define LL long long
LL M[1001];
LL B, N;

int solve_large(){
    if(N<=B){
        return N;
        
    }
    LL a=0, b=1000000000000000000LL;
    while(a+1<b){
        LL t = (b+a+1)/2;
        LL z = B;
        for(int i=0;i<B;++i){
            z+=t/M[i];
        }
        if(z >= N){
            b=t;
        }else{
            a=t;
        }
    }
    
    LL n = N - B;
    for(int i=0;i<B;++i){
        n -= a/M[i];
    }
    LL t = b;
    int sel=0;
    while(n>0){
        for(int j=0;(j<B) && (n>0);++j){
            if(t%M[j] == 0){
                --n;
                sel = j;
            }
        }
        ++t;
    }
    return 1+sel;
    
    
}

int main(){
    int T;
    scanf("%d", &T);
    for(int c=1;c<=T;++c){
        scanf("%lld %lld", &B, &N);
        for(int i=0;i<B;++i){
            scanf("%lld",&M[i]);
        }
        int sol = solve_large();
        printf("Case #%d: %d\n", c, sol);
    }
    return 0;
}
