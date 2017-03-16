#include <bits/stdc++.h>

#define MAX 30

using namespace std;

typedef long long int ll;

const ll INF = 1LL<<60;

int T;
int R,C,N;
int tab[MAX][MAX];

int isValid(int i,int j){
    if(i<0) return 0;
    if(i>=R) return 0;
    if(j<0) return 0;
    if(j>=C) return 0;
    return 1;
}

void trans(int mask){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            tab[i][j]= (mask & (1<<(i*C+j)))?1:0;
        }
    }
}

int calc(){
    int cont=0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(!tab[i][j]) continue;
            if( isValid(i-1,j) && tab[i-1][j] == 1 ) cont++;
            if( isValid(i+1,j) && tab[i+1][j] == 1 ) cont++;
            if( isValid(i,j-1) && tab[i][j-1] == 1 ) cont++;
            if( isValid(i,j+1) && tab[i][j+1] == 1 ) cont++;
        }
    }
    return cont/2;
}




int main(void){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B3.out","w",stdout);
    scanf("%d",&T);
    for(int caso=1;caso<=T;caso++){
        scanf("%d %d %d",&R,&C,&N);

        int resp=1<<29;
        //int aux=R*C/2;
        //if( (R*C) % 2 == 0) aux++;
        //if(N<=aux){
         //   resp=0;
        //}else{
            for(int mask=0;mask<= (1<<(R*C));mask++){
                if(__builtin_popcount(mask) != N) continue;
                trans(mask);
                resp=min(resp,calc());
            }
        //}

        printf("Case #%d: %d\n",caso,resp);
    }
}
