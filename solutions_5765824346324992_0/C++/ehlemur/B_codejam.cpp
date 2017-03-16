#include <bits/stdc++.h>

const int MAX_B = 1e3 + 3;


int B;
long long m[MAX_B];


long long count ( long long t ) {
    // at begin of time t, how many clients are not waiting
    // For 3, 4, 7, 8, 2:
    //  0 -> 5  (all 5 busy)
    //  1 -> 5  (all 5 busy)
    //  2 -> 6  (5th barber finished and started)
    //  3 -> 7  (1st barber finished and started)
    //  4 -> 9  (2nd and 5th barber finished and started)
    //  5 -> 9 
    //  6 -> 11 (1st and 5th barber ...)
    //  7 -> 12 (3rd barber ...)
    //  8 -> 15 (2nd, 4th and 5th barber ...)
    long long answer, b;

    answer = B;
    for ( b = 0 ; b < B ; ++ b ) {
        answer += t / (long long) m[b];   
    }
    return answer;
}


int solve ( long long N , long long lo , long long hi ) {
    long long mi, b;
    
    while ( lo != hi ) {
        mi = (lo + hi) >> 1;
        if ( count(mi) < N ) {
            lo = mi + 1;
        }
        else {
            hi = mi;
        }
    }

    if ( lo == 0 ) {
        return N;
    }
    
    mi = (lo + hi) >> 1;
    lo = count(mi-1) + 1;
    for ( b = 0 ; b < B ; ++ b ) {
        if ( mi % m[b] == 0 ) {
            if ( lo == N ) {
                break;
            }
            ++ lo;
        }
    }

    return b + 1;
}


int main ( void ) {

    long long T, N, hi, t, b;

    std::cin >> T;
    
    for ( t = 1 ; t <= T ; ++ t ) {
        std::cin >> B >> N;

        hi = -INT_MAX;
        for ( b = 0 ; b < B ; ++ b ) {
            std::cin >> m[b];
            hi = std::max(hi, m[b]);
        }    
        
        std::cout << "Case #" << t << ": " << solve(N, 0, hi * N) << "\n";
    }

    return 0;
}
