
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <assert.h>

void largest2(const std::vector<int>& sizes, int& max, int& max2)
{
    if ( sizes[0] < sizes[1] ) {
        max = 1;
        max2 = 0;
    } else {
        max = 0;
        max2 = 1;
    }

    for ( int i = 2 ; i < sizes.size() ; ++i ) {
        if ( sizes[i] > sizes[max2] ) {
            // need to do some work.
            if ( sizes[i] > sizes[max] ) {
                max2 = max;
                max = i;
            } else {
                max2 = i;
            }
        }
    }
    assert( max != max2 );
}

int main()
{
    int T;
    std::cin >> T;

    for ( int testnum = 1 ; testnum <= T ; ++testnum ) {
        std::cout<<"Case #"<<testnum<<":";

        int N;
        std::cin >> N;
        std::vector<int> dat( N );
        int total = 0;
        for ( int i = 0 ; i < N ; ++i ) {
            std::cin >> dat[ i ];
            total += dat[ i ];
        }

//        std::string result = "";
//        result.reserve( total*3 );
        while ( total > 0 ) {
            std::cout<<' ';
            // find the two largest slots.
            int max;
            int max2;
            largest2( dat , max , max2 );

            if ( total == 3 ) {
                char party = max + 'A';
                std::cout<<party;
                --dat[max];
                --total;
                continue;
            }

            char party1 = std::min( max , max2 ) + 'A';
            char party2 = std::max( max , max2 ) + 'A';
//            std::cerr<<"party1 = "<<party1<<" party2 = "<<party2<<std::endl;
//            result += " " + party1 + party2;
            std::cout<<party1<<party2;
            --dat[max];
            --dat[max2];
            total -= 2;
        }
        std::cout<<'\n';
    }

    return 0;
}
