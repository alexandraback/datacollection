//#define CUTE_PLATFORM
//#define CUTE_MAIN_RUNNER

#ifdef CUTE_PLATFORM
#include "cute_algostudy.h"
#endif

#include <string>
#include <vector>
#include <iostream>

#include <map>
#include <set>
#include <algorithm>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <numeric>

#ifdef CUTE_PLATFORM
namespace code_2015_1a_b {
#endif

using namespace std;

int gcd(int a, int b){
    while(true){
        if (a == 0){
            return b;
        }
        b %= a;
        if (b == 0){
            return a;
        }
        a %= b;
    }
    return 0;
}

int lcm(int a, int b) {
    int temp = gcd(a, b);
    return temp ? (a / temp * b) : 0;
}

int solve(){
    int B, me;
    cin >> B >> me;
    vector<int> barbers;
    vector<int> barbersRemain;
    for(int i = 0; i < B; ++i){
        int m;
        cin >> m;
        barbers.push_back(m);
        barbersRemain.push_back(m);
    }

    int turnLcm = std::accumulate(barbers.begin(), barbers.end(), 1, lcm);
    int turnCnt = 0;
    for(int i = 0; i < B; ++i){
        turnCnt += (turnLcm/barbers[i]);
    }

    int turnMe = me % turnCnt;
    if(turnMe != 0){
        me =  turnMe;
    }

    if(barbers.size() >= me){
        return me;
    }

    int nextTurn = barbers.size();;
    while(true){
        int minRemain = *std::min_element(barbersRemain.begin(), barbersRemain.end());
        for(int i = 0; i < B; ++i){
            barbersRemain[i] -= minRemain;
            if(barbersRemain[i] == 0){
                nextTurn++;
                barbersRemain[i] = barbers[i];
                if(nextTurn == me){
                    return i+1;
                }
            }
        }
    }
    return 1;
}

int main(){
	int T;
	cin >> T;

	for(int testCaseNo = 1; testCaseNo <= T; ++testCaseNo){
	    int ret = solve();
	    cout << "Case #" << testCaseNo << ": " << ret << endl;
	}
	return 0;
}

#ifdef CUTE_PLATFORM
#ifdef CUTE_MAIN_RUNNER
CUTE_MAIN(__FILE__, main);
#endif
}
#endif
