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


int p[26];


void q(){
    DRI(N);
    for(int n=0; n<N; n++)RI(p[n]);
    
    while(true){
        int m = 0;
        int a = -1;
        int b = -1;
        int r = 0;
        for(int n=0; n<N; n++){
            if(m <= p[n]){
                a = b;
                b = n;
                m = p[n];
            }
            if(p[n])r++;
        }
        if(m == 0)break;
        if(a>=0 && b>=0 && p[a] == p[b] && p[a] == 1 && r==3) b = -1; // 1 1 1
        if(a>=0){ p[a]--; printf("%c", a+'A');}
        if(b>=0){ p[b]--; printf("%c", b+'A');}
        printf(" ");
    }
    printf("\n");
}
    

int main(){
    CASET {
        printf("Case #%d: ", case_n++);
        q();
        fflush(stdout);
    }
    return 0;
}

