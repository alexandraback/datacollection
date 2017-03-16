#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int R , C , N , A , B , D , Ans , I , J , K ;

int main() {
    freopen("B-large.in" , "r" , stdin) ;
    freopen("B-large.out", "w" , stdout) ;
    
    int Test ; cin >> Test ;
    for ( int i = 1 ; i <= Test ; i ++ ) {
        cin >> R >> C >> N ;
        if ( C < R ) swap(C,R) ;
        //cout << R << " " << C << " " << N << "\n" ;
        
        if ( R == 1 ) {
            if ( N == C ) Ans = C-1 ;
            else if ( N <= C - (C/2) ) Ans = 0 ;
            else Ans = 2*(N-(C - (C/2))) - (1-C%2) ;
            cout << "Case #" << i << ": " << Ans << "\n" ;
            continue ;
        }
        if ( (R*C) % 2 == 1 ) {
            I = (R*C)/2 + 1 ;
            J = 0 ;
            K = (R/2)*2 + (C/2)*2 ;
            
            B = (R+C-2)*2 - (R/2)*2 - (C/2)*2 - 4 ;
            D = 4 ;
            A = (R*C)/2 + 1 - B - D ;
        } else {
            I = (R*C)/2 ;
            J = 2 ;
            K = (R+C-2) - 2 ;
            
            B = (R+C-2) - 2 ;
            D = 2 ;
            A = (R*C)/2 - B - D ;
        }
        
        //cout << A << " " << B << " " << D << "\n" ;
        
        Ans = -10000 ;
        if ( N <= I ) Ans = 0 ;
        else if ( R*C - N <= A ) Ans = R*(C-1) + C*(R-1) - 4*(R*C-N) ;
        else {
            if ( (R*C-N-A) <= B ) Ans = (R*(C-1)+C*(R-1)) - 4*A - (R*C-N-A)*3 ;
            else if ( (N-I) <= J ) Ans = (N-I)*2 ;
            else {
                N -= I ;
                Ans = min(J,N)*2 ;
                if ( N > J ) {
                    N -= J ;
                    Ans += N*3 ;
                }
            }
        }
        cout << "Case #" << i << ": " << Ans << "\n" ;
    }
}
