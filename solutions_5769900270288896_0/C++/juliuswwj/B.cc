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

int R, C, N;
char m[10010][10010];
char mc[10010][10010];
    
int q(){
    RIII(R, C, N);
    fprintf(stderr, "%d %d %d\n", R, C, N);
    
    int n = 0;
    if(R%2 == 0 || C%2==0) n = R/2*C;
    else n = R/2*(C/2)*2 + 1;
    if(N <= n)return 0;
    int cnt = 0;
    if(R == 1 || C == 1){
        if(R % 2 == 0 || C %2 == 0){ n++; cnt++; }
        return cnt + (N-n)*2;
    }
    
    cnt = (R-1)*C + (C-1)*R;
    n = R*C;
    for(int r=0; r<R; r++)for(int c=0; c<C; c++){
        m[r][c]=1;
        mc[r][c]=4;
        if((r==0 || r==R-1) && (c>0 && c<C-1))mc[r][c]=3;
        if((c==0 || c==C-1) && (r>0 && r<R-1))mc[r][c]=3;
    }
    mc[0][0]=2;
    mc[0][C-1]=2;
    mc[R-1][0]=2;
    mc[R-1][C-1]=2;
    
    while(n>N){
        n--;
        int mm = -1;
        int pr = -1;
        int pc = -1;
        for(int r=0; r<R; r++)for(int c=0; c<C; c++)if(mm<mc[r][c] && m[r][c]){
            mm = mc[r][c];
            pr = r;
            pc = c;
        }
        /*fprintf(stderr, "- %d %d\n", pr, pc);
        for(int r=0; r<R; r++){
            for(int c=0; c<C; c++)fprintf(stderr, "%d ", mc[r][c]);
            fprintf(stderr, "\n");
        }*/
        m[pr][pc] = 0;
        mc[pr][pc] = 0;
        if(pr>0 && m[pr-1][pc]){ mc[pr-1][pc]--; cnt--; }
        if(pr<R-1 && m[pr+1][pc]){ mc[pr+1][pc]--; cnt--; }
        if(pc>0 && m[pr][pc-1]){ mc[pr][pc-1]--; cnt--; }
        if(pc<C-1 && m[pr][pc+1]){ mc[pr][pc+1]--; cnt--; }
    }
    int k=0;
    for(int r=0; r<R; r++)for(int c=0; c<C; c++)k+=mc[r][c];
    if(k!=cnt)fprintf(stderr, "k!=cnt\n");
    return k;    
}    


int main(){
    CASET {
        printf("Case #%d: %d\n", case_n++, q());
    }
    return 0;
}