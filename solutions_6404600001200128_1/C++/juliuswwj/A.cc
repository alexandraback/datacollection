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

int N;
int m[1010];

int q(){
    RI(N);
    int a = 0;
    int bm = 0;
    for(int i=0; i<N; i++){
        RI(m[i]);
        if(i> 0 && m[i] < m[i-1]){
            a += m[i-1] - m[i];
            bm = max(bm, m[i-1] - m[i]);
        }
    }
    int b = 0;
    for(int i=0; i<N-1; i++){
        if(m[i]>=bm)b+=bm; else b+=m[i];
    }
    printf("%d %d\n", a, b);
}

int main(){
    CASET {
        printf("Case #%d: ", case_n++);
        q();
    }
    return 0;
}