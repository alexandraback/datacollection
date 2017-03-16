#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>
#include <utility>
#include <stdlib.h>
#include <stdio.h>


using namespace std;
typedef unsigned long long ull;

int T, B, N;

ull barb[1005];


ull numCut(ull t){
    ull ans = 0;
    for (int i = 0; i < B; i++){
        ans += t/barb[i]+1 ;
    }
    return ans;
}

int main(){
    
    //ifstream ins("B-small-attempt0.in");
    ifstream ins("B-large.in");
    ofstream ofs("B-large-out.txt");
    
    ins >> T;
    
    for (int cse = 1; cse <= T; cse++){
        
        ins >> B >> N;
        
        for (int i = 0; i < B; i++){
            ins >> barb[i];
        }
        
        
        ull start = 0, end = ull(pow(10,16));
        ull mid = 0;
        while (start < end){
            mid = (start+end)/2;
            ull nc = numCut(mid);
            if (nc >= N){
                end = mid;
            }
            else
                start = mid+1;
        }
        
        
        ull inLineAtEnd = N;
        if ( end >= 1){
            inLineAtEnd -= numCut(end-1);
        }
        
        int i = 0;
        for ( i = 0; i < B; i++){
            if ( (end % barb[i]) == 0){
                inLineAtEnd--;
                if (inLineAtEnd == 0)
                    break;
            }
        }
        
        ofs << "Case #" << cse << ": " << i+1 << endl;
    }
    
    return 0;
}


