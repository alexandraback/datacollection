//
//  main.cpp
//
//  Google Code Jam 2k15 - Round 1A - Problem B
//
//  I regret everything seen here, but maybe I'll (re)learn some things.

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    int cases, current;
    std::vector<int> timings;
    std::vector<int> tlefts;
    unsigned long long b;
    int t, tmax;
    unsigned long long n;
    
    std::cin >> cases;
    for (current=1; current<=cases; ++current) {
        std::cout << "Case #" << current << ": ";
        timings.clear();
        tlefts.clear();
        t = tmax = 0;
        std::cin >> b;
        std::cin >> n;
        
        for (int i=0; i<b; i++) {
            std::cin >> t;
            if (tmax < t) tmax = t;
            timings.push_back(t);
            tlefts.push_back(t);
        }
unsigned long long n0 = n;
      

        if (b > n) {
            b = n;
            n = 0;
        } else {
            n -= b;
        }
        
        
        while (n>0) {
            int mintleft = tmax;
            for (int i=0; i<b; i++) if (tlefts[i] < mintleft) mintleft = tlefts[i];
            for (int i=0; i<b; i++) tlefts[i] -= mintleft;
            // check for special all-zero case
            int allzeros = 1;
            for (int i=0; i<b; i++) {
                if (tlefts[i]) {allzeros = 0; break;}
            }
            if (allzeros) {
                unsigned long long mod = n0 - n;
                while (n > mod) n-= mod; // duh
            }
            
            // replace zeros with timings, decrement n
            for (int i=0; i<b; i++) {
                if (tlefts[i] == 0) {
                    n--;
                    if (n==0) {
                        b = i+1;
                        break; // out of for loop, implicitly out of while(n)
                    }
                    tlefts[i] = timings[i];
                }
            }
        }

        std::cout << b << std::endl;
    }
}

