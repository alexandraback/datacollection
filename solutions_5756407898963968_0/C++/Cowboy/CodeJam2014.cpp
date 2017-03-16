/*
 *ID:   Cowboy
 *TASK:
 *Judge:
 */
#include <bits/stdc++.h>
#define INF 0x7fffffff
#define PI 2*acos(0.0)
using namespace std;

#define PB(t) push_back(t)
#define ALL(t) t.begin(),t.end()
#define MP(x, y) make_pair((x), (y))
#define Fill(a,c) memset(&a, c, sizeof(a))

int lectura(int idx){
    int bit = 0, aux;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin>>aux;
            if( i==idx-1 ){
                bit |=1<<aux-1;
            }
        }
    }
    return bit;
}

int idxBit( int bit ){
    int i;
    for(i = 0; i<16; i++){
        if( bit&1<<i )
            break;
    }
    return i;
}

int main( ){
    freopen("A-small.in","r",stdin);
    freopen("solution.out","w",stdout);
    int T, k = 0;
    for( cin>>T; k<T; k++){
        int res1, res2, idx;

        cin>>idx;
        res1 = lectura( idx );

        cin>>idx;
        res2 = lectura( idx );

        res1 = res1&res2;

        res2 = __builtin_popcount(res1);

        printf("Case #%d: ", k+1);
        if( res2==1 ){
            res1 = idxBit(res1);//idxBit( res1 );
            printf("%d\n", res1+1);
        }else if( res2==0 ){
            printf("Volunteer cheated!\n");
        }else{
            printf("Bad magician!\n");
        }
    }

return 0;
}
