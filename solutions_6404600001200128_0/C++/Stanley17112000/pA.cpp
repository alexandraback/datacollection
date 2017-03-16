#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int T , N , arr[ 10001 ];
int main(){
    freopen("A-small-attempt0.in.txt" , "r" , stdin);
    freopen("output.out" , "w" , stdout);
    int casen = 1;
    scanf("%d",&T);
    while ( T-- ){
        int f = 0 , s = 0 , maxgap = 0;
        scanf("%d",&N);
        for ( int i = 1 ; i <= N ; i++ )
            scanf("%d",&arr[i]);
        
        for ( int i = 2 ; i <= N ; i++ )
            if ( arr[i] < arr[i-1] ){
                f += arr[i-1] - arr[i];
                if ( arr[i-1] - arr[i] > maxgap )
                    maxgap = arr[i-1] - arr[i];
            }
        
        
        for ( int i = 1 ; i < N ; i++ )
            s += min( maxgap , arr[i] );

        printf("Case #%d: %d %d\n",casen++ , f , s);

    }
    return 0;
}
