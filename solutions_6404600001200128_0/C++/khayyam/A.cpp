#include <stdio.h>
#define MIN(a, b) (((a)<(b))?(a):(b))
int M[1001];
int N;

void solve(int &a, int &b){
    a = 0;
    for(int i=1;i<N;++i){
        if(M[i]<M[i-1]){
            a+=M[i-1]-M[i];
        }
    }
    
    for(int rate=0;rate<=10000;++rate){
        b = 0;
        bool consistent = true;
        for(int i=1;i<N;++i){
            if(M[i-1] - rate > M[i]){
                consistent=false;
                break;
            }
            b += MIN(M[i-1], rate);
        }
        if(consistent){
            return;
        }
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int c=1;c<=T;++c){
        scanf("%d", &N);
        for(int i=0;i<N;++i){
            scanf("%d",&M[i]);
        }
        int a, b;
        solve(a, b);
        printf("Case #%d: %d %d\n", c, a, b);
    }
    return 0;
}
