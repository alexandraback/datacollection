#include <bits/stdc++.h>


const int MAX_N = 1e4 + 4;

int m[MAX_N];

int main ( void ) {
    
    int T, N, max_variation, second, first, t, n;

    std::cin >> T;

    for ( t = 1 ; t <= T ; ++ t ) {
        std::cin >> N;

        first = 0;
        second = 0;
        max_variation = -INT_MAX;
        for ( n = 0 ; n < N ; ++ n ) {
            std::cin >> m[n];
            if ( n > 0 && m[n] < m[n-1] ) {
                first += m[n-1] - m[n];
                max_variation = std::max(max_variation, m[n-1] - m[n]);
            }
        }

        if ( max_variation != -INT_MAX ) {
            for ( n = 1 ; n < N ; ++ n ) {
                second += std::min(max_variation, m[n-1]);
            }
        }

        std::cout << "Case #" << t << ": " << first << " " << second << "\n";
    }

    return 0;
}
