#include <stdio.h>
#define MIN(a, b) (((a)<(b))?(a):(b))
#define LL long long
LL M[1001];
LL B, N;
LL gcd(LL a, LL b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

int solve(){
    LL lcm = 1;
    for(int i=0;i<B;++i){
        LL g = gcd(lcm, M[i]);
        lcm = (lcm * M[i])/g;
    }
    int round = 0;
    for(int i=0;i<B;++i){
        round += lcm/M[i];
    }
    int n = N%round;
    if(n==0){
        n=round;
    }
    LL t=0;
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
        int sol = solve();
        printf("Case #%d: %d\n", c, sol);
    }
    return 0;
}
