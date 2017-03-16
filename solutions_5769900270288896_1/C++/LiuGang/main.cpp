#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int R , C , N;

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("large.txt", "w", stdout) ;

    int T, cas = 1;
    scanf("%d", &T) ;
    while(T--) {
        scanf("%d%d%d", &R, &C, &N) ;

        int ans = 0 ;

        if(N <= 1) {
            printf("Case #%d: %d\n", cas++ , 0) ;
            continue ;
        }

        if(R < C) swap(R , C) ;
        if(C == 1) {
            int cnt =  0;
            for(int i=1; i<=R; i+=2) cnt ++ ;
            ans = 0 ;
            int ii = R%2==0 ? R : R-1 ;
            while(cnt < N) {
                if(ii == R) ans ++ ;
                else ans += 2 ;
                cnt ++ ;
                ii -= 2 ;
            }
            printf("Case #%d: %d\n", cas++ , ans) ;
            continue ;
        }


        int n0 = 0 , n2 = 0 , n3 = 0 , n4 = 0 ;
        for(int i=1; i<=R; i++) {
            for(int j=1; j<=C; j++) {
                if(i%2 == j%2) n0 ++ ;
                else  if((i==1 && j==1) || (i==1 && j==C) || (i==R && j==1) ||(i==R && j==C)) n2 ++ ;
                else if(i==1 || i==R || j==1 || j==C) n3 ++ ;
                else n4 ++ ;
            }
        }

        if(N > n0 + n2 + n3) ans = 2 * n2 + 3*n3 + 4*(N-n0-n2-n3) ;
        else if(N > n0 + n2) ans = 2 * n2 + 3*(N-n0-n2) ;
        else if(N > n0) ans = 2 * (N-n0) ;


        n0 = 0 , n2 = 0 , n3 = 0 , n4 = 0 ;
        for(int i=1; i<=R; i++) {
            for(int j=1; j<=C; j++) {
                if(i%2 != j%2) n0 ++ ;
                else  if((i==1 && j==1) || (i==1 && j==C) || (i==R && j==1) ||(i==R && j==C)) n2 ++ ;
                else if(i==1 || i==R || j==1 || j==C) n3 ++ ;
                else n4 ++ ;
            }
        }

        int ans2 = 0;
        if(N > n0 + n2 + n3) ans2 = 2 * n2 + 3*n3 + 4*(N-n0-n2-n3) ;
        else if(N > n0 + n2) ans2 = 2 * n2 + 3*(N-n0-n2) ;
        else if(N > n0) ans2 = 2 * (N-n0) ;

        ans = min(ans , ans2) ;

        printf("Case #%d: %d\n", cas++ , ans) ;

    }
    return 0;
}
