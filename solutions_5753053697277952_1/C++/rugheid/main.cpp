//
//  main.cpp
//  Senate Evacuation
//
//  Created by Rugen Heidbuchel on 08/05/16.
//  Copyright © 2016 Rugen Heidbuchel. All rights reserved.
//

#include <iostream>
#include "codingmacros.h"

size_t T, N;

int main(int argc, const char * argv[]) {

    #ifdef USE_INPUT_FILE
    freopen("example_input.txt", "r", stdin);
    #endif
    
    std::cin >> T;
    for (size_t caseNumber = 0; caseNumber < T; caseNumber++) {
        
        std::cout << "Case #" << caseNumber + 1 << ": ";
        
        std::cin >> N;
        vi P(N);
        std::string plan = "";
        
        for (size_t i = 0; i < N; i++) {
            std::cin >> P[i];
        }
        
        while (true) {
            
            int m = 0, mi = 0;
            for (int i = 0; i < N; i++) {
                if (P[i] > m) {
                    m = P[i];
                    mi = i;
                }
            }
            
            if (m == 0) {
                break;
            }
            
            P[mi]--;
            plan.push_back(' ');
            plan.push_back('A' + mi);
            
            m = 0, mi = 0;
            int sum = 0;
            for (int i = 0; i < N; i++) {
                sum += P[i];
                if (P[i] > m) {
                    m = P[i];
                    mi = i;
                }
            }
            
            if (m == 0) {
                break;
            }
            
            if (sum / m < 2) {
                P[mi]--;
                plan.push_back('A' + mi);
            }
        }
        
        std::cout << plan << "\n";
    }
    
    return 0;
}