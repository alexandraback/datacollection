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

#ifdef CUTE_PLATFORM
namespace code_jam_2015_1a_a {
#endif

using namespace std;

int firstCompute(vector<int>& mushes){
    int decreaseDiff = 0;
    for(int i = 0; i < mushes.size()-1; ++i){
        int diff = mushes[i+1] - mushes[i];
        if(diff < 0){
            decreaseDiff -= diff;
        }
    }
    return decreaseDiff;
}

int secondCompute(vector<int>& mushes){
    int maxDiff = 0;
    for(int i = 0; i < mushes.size()-1; ++i){
        int diff = mushes[i+1] - mushes[i];
        if(diff < maxDiff){
            maxDiff = diff;
        }
    }

    maxDiff = -1 * maxDiff;
    int ret = 0;
    for(int i = 0; i < mushes.size()-1; ++i){
        if(maxDiff > mushes[i]){
            ret += mushes[i];
        }else{
            ret += maxDiff;
        }
    }

    return ret;
}

pair<int, int> solve(){
    int mushCnt;
    cin >> mushCnt;
    vector<int> mushes;
    for(int i = 0; i < mushCnt; ++i){
        int currentMush;
        cin >> currentMush;
        mushes.push_back(currentMush);
    }
    int first = firstCompute(mushes);
    int second = secondCompute(mushes);
    return pair<int, int>(first, second);
}

int main(){
	int T;
	cin >> T;

	for(int testCaseNo = 1; testCaseNo <= T; ++testCaseNo){
	    pair<int, int> ret = solve();
	    cout << "Case #" << testCaseNo << ": " <<  ret.first << " " << ret.second << endl;
	}
	return 0;
}

#ifdef CUTE_PLATFORM
#ifdef CUTE_MAIN_RUNNER
CUTE_MAIN(__FILE__, main);
#endif
}
#endif
