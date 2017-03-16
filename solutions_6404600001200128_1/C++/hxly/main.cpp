//
//  main.cpp
//
//  Google Code Jam 2k15 - Round 1A - Problem A
//
//  I regret everything seen here, but maybe I'll (re)learn some things.

#include <iostream>
 #include <vector>

int main(int argc, const char * argv[]) {
    int cases, current;
    int n;
    int t, told; //emp
    std::vector<int> m;
    int minate, conmin, sum;
    
    std::cin >> cases;
    for (current=1; current<=cases; ++current) {
        std::cout << "Case #" << current << ": ";
        m.clear();
        minate = t = conmin = sum = 0;
        
        std::cin >> n;
        
        for (int ms=0; ms<n; ms++) {
            told = t;
            std::cin >> t;
            if (told>t) {
                minate += (told-t);
                if (told-t > conmin) conmin = told-t;
            }
            m.push_back(t);
        }
        
        for (int ms=0; ms<n-1; ms++) {
            if (m[ms] <= conmin) {
                sum += m[ms];
            } else {
                sum+= conmin;
            }
        }

        
        
        std::cout << minate << " " << sum << std::endl;
    }
}

