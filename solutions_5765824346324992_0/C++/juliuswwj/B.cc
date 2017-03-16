#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
#include<list>
#include<queue>
#include<stack>
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
using namespace std;

long long gcd(long long x,long long y) {
    long long temp;
    while(y!=0) {
        temp=x%y;
        x=y;
        y=temp;
    }
  
    return x;
}

long long lcm(long long x,long long y){
   return (x*y)/gcd(x,y);
}
    
int B, N, M[1010];
int t[1010];
void q(){
    RII(B, N);
    long long mm = 1;
    for(int i=1; i<=B; i++){
        RI(M[i]);
        t[i] = M[i];
        mm = lcm(mm, M[i]);
    }
    
    int cycle = 0;
    for(int i=1; i<=B; i++){
        cycle += mm / M[i];
    }
    N = (N-1) % cycle + 1;
    //fprintf(stderr, "mm=%ld cycle=%d N=%d\n", mm, cycle, N);

    if(B >= N){
        printf("%d\n", N);
        return;
    }
    
    int n = B;
    int Mi = 0;
    while(n < N){
        int MT = 100000000;
        for(int i=1; i<=B; i++){
            if(MT > t[i]){
                MT = t[i];
                Mi = i;
            }
        }
        t[Mi] += M[Mi];
        n++;
    }
    printf("%d\n", Mi);
}

int main(){
    CASET {
        printf("Case #%d: ", case_n++);
        q();
    }
    return 0;
}